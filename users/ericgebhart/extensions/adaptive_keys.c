/*
  Copyright 2018-2022 Eric Gebhart <e.a.gebhart@gmail.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include USERSPACE_H
#include "adaptive_keys.h"
#include <stddef.h>

#ifdef ADAPTIVE_KEYS_ENABLE
typedef struct {
    uint16_t prefix_key;
    uint16_t keycode;
    bool processed;
    const uint16_t *keys;
} ak_t;

uint16_t prior_keycode;

/* bool process_foo(uint16_t keycode, keyrecord_t *record) { */
/*    return true */
/* } */

// Processed is the bool return for process_record_user. true to
// stop further processing, false to let it continue.

#define AK_END 65535
#define BLANK(...)
#define AK_STRUCT {prefix_key, key, processed, &ak_keys##name[0]}

// To create an enum index and find out how many we have.
#define AK_ENUM(name, prefix_key, key, processed, ...) AK_##name,

// Create a bunch of terminated key lists in memory to point at
#define AK_DATA(name, prefix_key, key, processed, ...) \
    const uint16_t PROGMEM ak_keys##name[] = {__VA_ARGS__, AK_END};

// build an array of adaptive key structs that point at their keys.
// use its enum for the index.
#define AK_ENTRY(name, prefix_key, key, processed, ...) \
    [AK_##name] = {prefix_key, key, processed, &ak_keys##name[0]},

// Create Enum from the names
#undef AK
#define AK AK_ENUM
enum aks {
#include "adaptive_keys.def"
    AK_LENGTH
};
// set the length
uint16_t AK_LEN = AK_LENGTH;

/* static const uint16_t PROGMEM foo[] = {0,2,3}; */

// declare arrays with the keys to send.
#undef AK
#define AK AK_DATA
#include "adaptive_keys.def"
#undef AK

// An array of the Adaptive key entry structures
#define AK AK_ENTRY
ak_t adaptive_keys[] = {
#include "adaptive_keys.def"
};
#undef AK

uint16_t adaptive_key_timer = 0;

ak_t* find_adaptive_key(uint16_t keycode, uint16_t prefix_key){
  for (int i = 0; i < AK_LEN; ++i) {
      if (keycode == adaptive_keys[i].keycode &&
          prior_keycode == adaptive_keys[i].prefix_key){
          return (&adaptive_keys[i]);
      }
  }
  return NULL;
}

// send the keys for the adaptive key pair and
// return the requested return code.
bool send_adaptive_keys(ak_t* ak){
  // loop through the keys and send them until we hit AK_END.
  for (const uint16_t *k=ak->keys; *k != AK_END; ++k)
      tap_code16(*k);

  return (ak->processed);  // return true or false.
}

bool process_adaptive_key(uint16_t keycode, keyrecord_t *record) {
    ak_t* ak = NULL;
    uint8_t saved_mods = get_mods();
    bool return_processed = true;

    // Are we in an adaptive context?
    if (timer_elapsed(adaptive_key_timer) > ADAPTIVE_TERM) {
        // outside adaptive threshhold
        prior_keycode = keycode;
        adaptive_key_timer = timer_read();
        return true; // no adaptive conditions, so return.
    }

    if (!is_caps_word_on()) { // turn off shift, (first-words & Proper nouns)
        unregister_mods(MOD_MASK_SHIFT);  //CAPS_WORD/LOCK won't be affected.
    }

    ak = find_adaptive_key(keycode & QK_BASIC_MAX, prior_keycode);

    if (ak != NULL){  // send the keys if we found one.
        return_processed = send_adaptive_keys(ak);
        register_mods(saved_mods);
        prior_keycode = 0;
    } else {
        // no adaptive key matches, maybe next time.
        prior_keycode = keycode;
        adaptive_key_timer = timer_read();
    }
    return return_processed;
}
#endif
