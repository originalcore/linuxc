#include <stdio.h>

/* Code from LinuxProgramingByExample book */

/* TECHINQUE 1 SUCK don't care */

#ifdef TECHNIQUE2

/* TECHNIQUE 2, most portable, recommended */
/* In application header file: */
#ifdef MYAPPDEBUG
#define DPRINT(stuff) fprintf stuff
#else
#define DPRINT(stuff)
#endif

#else

/* TECHNIQUE 3, cleanest, but C99 only */
/* In application header file: */
#ifdef MYAPPDEBUG
#define DPRINT(mesg, ...) fprintf(stderr, mesg, __VA_ARGS__)
#else
#define DPRINT(mesg, ...)
#endif

#endif

/*
 * Compile:
 * gcc -DTECHNIQUE2 -DMYAPPDEBUG
 * gcc -DMYAPPDEBUG
 */
int main(int argc, char *argv[])
{
#ifdef TECHNIQUE2
	DPRINT((stderr, "Technique 2 var = %d\n", 911));
#else
	DPRINT("Technique 3 var = %d\n", 110);
#endif
	return 0;
}
