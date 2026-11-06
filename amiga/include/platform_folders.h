/* PlatformFolders' calls that Block Attack makes outside os.cpp, for the
 * Amiga: everything the game writes goes in its drawer's user/.
 * The AmiCradle Team. GPL 2 or later, like Block Attack. */
#ifndef AMIGA_PLATFORM_FOLDERS_H
#define AMIGA_PLATFORM_FOLDERS_H
#include <string>

namespace sago {
inline std::string getConfigHome() { return "PROGDIR:user"; }
inline std::string getPicturesFolder() { return "PROGDIR:user"; }
}
#endif
