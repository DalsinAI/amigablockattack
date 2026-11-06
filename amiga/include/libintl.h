/* No gettext on the Amiga here: Block Attack in English, its own words.
 * The AmiCradle Team. GPL 2 or later, like Block Attack. */
#ifndef AMIGA_LIBINTL_H
#define AMIGA_LIBINTL_H
#define gettext(s) (s)
#define bindtextdomain(d, dir) ((const char *)(dir))
#define bind_textdomain_codeset(d, c) ((const char *)(c))
#define textdomain(d) ((const char *)(d))
#endif
