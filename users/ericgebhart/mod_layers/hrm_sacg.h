#pragma once
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
#include "mod_layer_parms.h"

// LEFT.
#define ROW0L_5_hrm_sacg(K01, K02, K03, K04, K05)       \
  K01, K02, K03, K04, K05

// Take and put an extra column in front.
// Mod K01 how you want it.
#define ROW0L_6_hrm_sacg(K01, K02, K03, K04, K05, K06) \
  K01    \
  , ROW0L_5_hrm_sacg(K02, K03, K04, K05, K06)

// 5 into 6, derivitive of the first two.
#define ROW0L_5_6_hrm_sacg(K01, K02, K03, K04, K05) \
  ROW0L_6_hrm_sacg(LEFT_0, K01, K02, K03, K04, K05)

// RIGHT.
#define ROW0R_5_hrm_sacg(K01, K02, K03, K04, K05)       \
  K01, K02, K03, K04, K05

// Take and put an extra column in front.
// Mod K01 how you want it.
#define ROW0R_6_hrm_sacg(K01, K02, K03, K04, K05, K06) \
  ROW0R_5_hrm_sacg(K01, K02, K03, K04, K05),\
  K06

// 5 into 6, derivitive of the first two.
#define ROW0R_5_6_hrm_sacg(K01, K02, K03, K04, K05) \
  ROW0R_6_hrm_sacg(K01, K02, K03, K04, K05, RIGHT_0)

// ROW1
// LEFT.
#define ROW1L_5_hrm_sacg(K01, K02, K03, K04, K05)       \
  K01, K02, K03, LT(_NAV, K04), K05

// Take and put an extra column in front.
// Mod K01 how you want it.
#define ROW1L_6_hrm_sacg(K01, K02, K03, K04, K05, K06)  \
  K01    \
  , ROW1L_5_hrm_sacg(K02, K03, K04, K05, K06)

// 5 into 6, derivitive of the first two.
#define ROW1L_5_6_hrm_sacg(K01, K02, K03, K04, K05) \
  ROW1L_6_hrm_sacg(LEFT_1, K01, K02, K03, K04, K05)

// RIGHT.
#define ROW1R_5_hrm_sacg(K01, K02, K03, K04, K05)                       \
  K01, K02, K03, K04, LT(_LAYERS, K05)                                  \

// Take and put an extra column in front.
// Mod K06 how you want it.
#define ROW1R_6_hrm_sacg(K01, K02, K03, K04, K05, K06) \
  ROW1R_5_hrm_sacg(K01, K02, K03, K04, K05),\
  K06

// 5 into 6, derivitive of the first two.
#define ROW1R_5_6_hrm_sacg(K01, K02, K03, K04, K05) \
  ROW1R_6_hrm_sacg(K01, K02, K03, K04, K05, RIGHT_1)

// LEFT.
#define ROW2L_5_hrm_sacg(K01, K02, K03, K04, K05)                       \
  MT(MOD_LSFT, K01), MT(MOD_LALT, K02), MT(MOD_LCTL, K03), MT(MOD_LGUI, K04), K05

// Take and put an extra column in front.
// Mod K01 how you want it.
#define ROW2L_6_hrm_sacg(K01, K02, K03, K04, K05, K06)   \
   K01    \
   , ROW2L_5_hrm_sacg(K02, K03, K04, K05, K06)

// 5 into 6, derivitive of the first two.
#define ROW2L_5_6_hrm_sacg(K01, K02, K03, K04, K05) \
  ROW2L_6_hrm_sacg(LEFT_2, K01, K02, K03, K04, K05)

// RIGHT.
#define ROW2R_5_hrm_sacg(K01, K02, K03, K04, K05)                       \
  K01, MT(MOD_RGUI, K02),  MT(MOD_RCTL, K03), MT(MOD_RALT, K04), MT(MOD_RSFT, K05)

// Take and put an extra column in front.
// Mod K06 how you want it.
#define ROW2R_6_hrm_sacg(K01, K02, K03, K04, K05, K06) \
  ROW2R_5_hrm_sacg(K01, K02, K03, K04, K05),\
  K06

// 5 into 6, derivitive of the first two.
#define ROW2R_5_6_hrm_sacg(K01, K02, K03, K04, K05) \
  ROW2R_6_hrm_sacg(K01, K02, K03, K04, K05, RIGHT_2)

// ROW 3
// LEFT.
#define ROW3L_5_hrm_sacg(K01, K02, K03, K04, K05)       \
  K01, K02, K03, K04, K05

// Take and put an extra column in front.
// Mod K01 how you want it.
#define ROW3L_6_hrm_sacg(K01, K02, K03, K04, K05, K06)  \
  K01    \
  ,  ROW3L_5_hrm_sacg(K02, K03, K04, K05, K06)

// 5 into 6, derivitive of the first two.
#define ROW3L_5_6_hrm_sacg(K01, K02, K03, K04, K05) \
  ROW3L_6_hrm_sacg(LEFT_3,  K01, K02, K03, K04, K05)

// RIGHT.
#define ROW3R_5_hrm_sacg(K01, K02, K03, K04, K05)       \
  K01, LT(_NAV, K02), K03, LT(LANG_N(_SYMB), K04), K05

// Take and put an extra column in front.
#define ROW3R_6_hrm_sacg(K01, K02, K03, K04, K05, K06) \
  ROW3R_5_hrm_sacg(K01, K02, K03, K04, K05),\
  K06

// 5 into 6, derivitive of the first two.
#define ROW3R_5_6_hrm_sacg(K01, K02, K03, K04, K05) \
  ROW3R_6_hrm_sacg(K01, K02, K03, K04, K05, RIGHT_3)
