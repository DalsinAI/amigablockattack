Block Attack - Rise of the Blocks 2.9.1 for AmigaOS 3.x
=======================================================

Block Attack - Rise of the Blocks (Poul Sander and others,
https://blockattack.net), the puzzle game in the style of Tetris Attack:
swap blocks side by side to line up three of a colour while the stack
rises. For AmigaOS 3.x on a 68040 or 68060 with an FPU and an RTG screen,
on OpenGPU's SDL 2.

Base: tag v2.9.1 (commit 0fba975828a1). Branch team2/blockattack-amiga.

Status: plays in the lab (Instance-45, 6 November 2026, SDL2.module from
gfopenrtg 29d32bf): the menus (mouse and cursor keys), a single-player
endless game (the stack rising, the cursor moving, the clock and the
score), the exit sign back to the menus, and Exit back to the Shell;
the settings, statistics and replay drawers made in user/.

9 November 2026: PhysicsFS is no longer compiled in. The game opens
LIBS:physfs.library (gfopenphysfs 1.1), one copy of PhysicsFS for every
program, and is 73 KB smaller. Tested in a lab of Instance-40 (the Team's
OpenROM): the menus and a single-player game from the drawer's data/
through the library, user/ made and written through it, Ctrl-C back to
the Shell, and PhysFSTest passing beside the running game.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- OpenGPU 0.6 or later: opengpu.library and LIBS:OpenGPU/SDL2.module,
  SDL2_image.module, SDL2_mixer.module and SDL2_ttf.module (installed by
  OpenUp).
- physfs.library 1 or later in LIBS: (GFOpenUp's GFOpenGPU part installs
  it). Without it the game stops at once with "This program needs
  physfs.library 1 or newer in LIBS:".


How to play
-----------

Open the BlockAttack icon, or run BlockAttack from a Shell (options:
--nosound, --software-renderer, --no-auto-scale, --always-sixteen-nine,
--verbose-basic, --version). The game reads its data from the drawer's
data/ and keeps its settings, high scores and replays in user/ there.



Standard keys
-------------

Every AmiCradle game has the same keys on Right Amiga (GFOpenUp's
SDL2.module, after 0.8.26):

- Right Amiga + F: window or full screen, remembered for next time
- Right Amiga + P: pause (Right Amiga + P again goes on)
- Right Amiga + Q: quit
- Right Amiga + M: free the mouse pointer, or let the game take it again
- Right Amiga + S: a screenshot in the drawer's Screenshots
- Help: this game's keys (the drawer's Controls file)
- Right Amiga + F1, F2: F11, F12; Right Amiga + cursor keys: Page Up,
  Page Down, Home, End

The FULLSCREEN tooltype on the game's icon (take the brackets off) starts
it full screen.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers, the OpenGPU kit
and physfs.library's SDK files: physfs.h and libphysfs_auto.a, from the
GFOpenGPU kit, the Open SDK (PHYSFS_INC=$(SDK)/Include
PHYSFS_LIB=$(SDK)/Lib/build/m68k-amigaos) or gfopenphysfs's own build
(PHYSFSKIT=build/os3/sdk); see the Makefile's head. The drawer is dist/BlockAttack (and
dist/BlockAttack.info).


What was changed
----------------

- source/code/main.cpp: main() first moves into the drawer
  (amiga/amiga_start.c) and closes at exit the screens SDL2.module 0.6 can
  leave (amiga/amiga_screens.c); the data is the drawer's data/ (unpacked,
  not upstream's blockattack.data zip); the options are read by a few
  lines of the game's own (upstream: Boost.Program_options).
  amiga/stack.c: 512 KB of stack.
- source/code/os.cpp: settings in PROGDIR:user (upstream: the platform's
  save-game folder, through PlatformFolders), drawers made with mkdir()
  (upstream: a mkdir -p command).
- amiga/include: libintl.h (no gettext: English), platform_folders.h (the
  two calls main.cpp and gamecontroller.cpp make, answering the drawer's
  user/) and boost/algorithm/string.hpp (ends_with, replace_all, split).
- amiga/amiga_prelude.hpp (included before every file): std::strtoll,
  stoll and the other C99 calls the GCC 16 stove's libstdc++ for the 68040
  leaves out, and <algorithm>, which upstream had through Boost.
- PhysicsFS 3.2.0 is LIBS:physfs.library (DalsinAI/gfopenphysfs), linked
  with -lphysfs_auto, which opens it before main(). Until 9 November it
  was compiled in from amiga/physfs.
- The drawer's 8-bit RGB PNGs are stored as RGBA (amiga/tools/png_rgba.py:
  SDL2_image.module 0.6 damages the host's heap decoding some of them).


Licences
--------

Block Attack: GPL 2 or later (COPYING); its data (fonts, pictures, sounds,
music: GPL 2, CC-BY 3.0, CC0 and others) file by file in AUTH.txt
(upstream's source/AUTH). {fmt}: MIT. The Amiga files (amiga/): GPL 2
or later, the AmiCradle Team. PhysicsFS (zlib) is not in the program: it
is physfs.library, which carries its own licence.
