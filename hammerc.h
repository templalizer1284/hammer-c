#ifndef HAMMERC_C
#define HAMMERC_C

#ifdef HAMMERC_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <unistd.h>

// macros
#define HC_DECL static inline

// ddecl
typedef uint8_t u8;

// fdecl
HC_DECL u8 hc_Compile(const char *restrict);

// globals

// ddef

// fdef
u8 hc_Compile(const char *restrict path) {

	FILE *fp = NULL;
	
	if(access(path, F_OK) == 0) {
		if( (fp = fopen(path, "r")) == NULL) {
			// proceed
		}

		else {
			fprintf(stderr, "File named '%s' cannot be opened.\n", path);
			return 1;
		}
	}

	else {
		fprintf(stderr, "File named '%s' cannot be accessed.\n", path);
		return 1;
	}

	return 0;
}

#endif // HAMMERC_IMPLEMENTATION
#endif // HAMMERC_C
