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
#define MAX_INPUT 63
#define MAX_SOURCE 65500
#define ff fscanf(fp, "%63s", tmp);

// ddecl
typedef uint8_t u8;
typedef struct hc_Source hc_Source;
typedef struct hc_Globals hc_Globals;

struct hc_Source {
	int x; // todo
};

struct hc_Globals {
	FILE *fp;
	char tmp[MAX_INPUT];
	hc_Source src;
};

// fdecl
HC_DECL u8 hc_Compile(const char *restrict);
HC_DECL u8 hc_ParseClass(void);

// globals
static hc_Globals glob = {
				.fp = NULL,
				.tmp = ""
						};

// ddef

// fdef
u8
hc_Compile(const char *restrict path) {

	glob.fp = NULL;
	
	if(access(path, F_OK) == 0) {
		if( (glob.fp = fopen(path, "r")) == NULL) {
			fprintf(stderr, "File named '%s' cannot be opened.\n", path);
			return 1;
		}

		else {
			if(hc_ParseClass()) {
				fprintf(stderr, "Class parsing error. Aborting.\n");
				return 1;
			}
			
			fclose(glob.fp);
		}
	}

	else {
		fprintf(stderr, "File named '%s' cannot be accessed.\n", path);
		return 1;
	}

	return 0;
}

u8
hc_ParseClass(void) {
	return 0;
}

#endif // HAMMERC_IMPLEMENTATION
#endif // HAMMERC_C
