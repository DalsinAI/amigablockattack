/* A Shell gives 4 KB of stack; libnix's startup sets this much up instead.
 * The AmiCradle Team. GPL 2 or later, like Block Attack. */
unsigned long __stack = 512 * 1024;
static const char version[] __attribute__((used)) = "$VER: Block Attack 2.9.1 Amiga (06.11.2026)";
