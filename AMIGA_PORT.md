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


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- OpenGPU 0.6 or later: opengpu.library and LIBS:OpenGPU/SDL2.module,
  SDL2_image.module, SDL2_mixer.module and SDL2_ttf.module (installed by
  OpenUp).


How to play
-----------

Open the BlockAttack icon, or run BlockAttack from a Shell (options:
--nosound, --software-renderer, --no-auto-scale, --always-sixteen-nine,
--verbose-basic, --version). The game reads its data from the drawer's
data/ and keeps its settings, high scores and replays in user/ there.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers and the OpenGPU kit
(see the Makefile's head). The drawer is dist/BlockAttack (and
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
- amiga/physfs: PhysicsFS 3.2.0 with its AmigaOS platform file (as in the
  Team's DXX-Rebirth port), compiled in.
- The drawer's 8-bit RGB PNGs are stored as RGBA (amiga/tools/png_rgba.py:
  SDL2_image.module 0.6 damages the host's heap decoding some of them).


Licences
--------

Block Attack: GPL 2 or later (COPYING); its data (fonts, pictures, sounds,
music: GPL 2, CC-BY 3.0, CC0 and others) file by file in AUTH.txt
(upstream's source/AUTH). {fmt}: MIT. PhysicsFS: zlib (PhysicsFS-LICENSE.txt). The
Amiga files (amiga/): GPL 2 or later, the AmiCradle Team (amiga/physfs:
zlib, like PhysicsFS).
