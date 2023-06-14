* Eric.a's QMK user space.

*This is just a sparse qmk_firmware with only my keyboard maps and my user space.*


I have begun using Emacs Org to manage this code.
As such, the readme found in users/ericgebhart is still valid, but dated.  
It does provide more
information which may be useful.
But current code and explanation is in the org files. Which are easy to read.
I've put all the org files here at the top.

I've been an emacs and org user for years, and I finally have decided
to try literate programming with org and qmk. I like the organization
and all the org features make it easy to manage things. In Emacs I  fold
all the topics in the file down to their headings, and then navigate that way.

I realize that it might make it more difficult for people who dont have
emacs and org. But the org files do create all the original source code
files which was well organized to begin with. So its perfectly reasonable
to ignore the org files if desired.

The configuration is now kept in [config.org](users/ericgebhart/config.org) along with a fair amount
of explanation. config.org tangles its contents into config.h and
rules.mk. 

The rest of the project is divided among various org files which tangle
into the original code files.  Only the keymap, =layer_names= and the oled
stuff is not contained in org files.

My goals with org, are to make a checkbox config, and automatic boilerplate
code for when a new layer is created. On verra.

The org file name matches the folder name that it tangles its code to.

The original readme converted to org.
  - [readme.org](file:users/ericgebhart/readme.org)

The org files which contain this code.

  - [introduction.org](file://users/ericgebhart/introduction.org)
   Some explanation of the parts and where you turn everything on and off.

  - [config.org](file://users/ericgebhart/config.org)
   The configuration of the firmware is here.

  - [lang.org](file://users/ericgebhart/lang.org)
This has some internals about keycodes and language, 
the structure of the layout wrappers and various other things that didn't belong here.

  - [base_layers.org](file://users/ericgebhart/base_layers.org)
This is where all the base layers live.  Dvorak, Beakl, Qwerty, Hands Down, Colemak,...

  - [layers.org](file://users/ericgebhart/layers.org)
Layer definitions like keypads, symbols, navigation, accents, etc.

  - [extensions.org](file://users/ericgebhart/extensions.org)
Code and definitions for extensions, key over-rides, combos, tap hold, smart locks, keycodes, etc.

  - [keyboards.org](file://users/ericgebhart/keyboards.org) 
  The layout matrices and keyboard mappings.

  - [mod_layers.org](file://users/ericgebhart/mod_layers.org)
Mod layer definitions to apply to the keymap given.

  -  [perimeter](file://users/ericgebhart/perimeter.org)
Edge keys, thumb keys, number rows. Middle keys.  Not really in the org yet.
The code lives in *perimeter/*.

 * The code not found in org.
Not everything is in org. One of the motivations of using org is to automate some of these.
  - oled/
  - layer_names/
  - perimeter/
