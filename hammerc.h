/*
 * This is stupid C code generator from Hammer-C templates. It is not supposed to have
 * any safety/type checking. If anything goes wrong your compiler will tell you.
 * */

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
#define ff fscanf(glob.fp, "%63s", glob.tmp)
#define cmp(x) strcmp(glob.tmp, Keywords[x][0])

// ddecl
typedef uint8_t u8;
typedef struct hc_Source hc_Source;
typedef struct hc_Globals hc_Globals;

// ddef
enum KEYWORDS {
	CLASS,
	PROPERTIES,
	METHODS,
	OBJECTS,
	THIS,
	STRING,
	DEFINE,
	IMPORT,
	
	END,
	NUM_OF_KEYWORDS
};

struct hc_Source {
	char class_name[MAX_INPUT];
	char *properties[MAX_INPUT][MAX_INPUT];

	u8 properties_count;
};

struct hc_Globals {
	FILE *fp;
	char tmp[MAX_INPUT];
	hc_Source src;
};

// fdecl
HC_DECL u8 hc_Compile(const char *restrict);

HC_DECL u8 hc_ParseClass(void);
HC_DECL u8 hc_ParseProperties(void);

HC_DECL u8 hc_GenerateC(void);

// globs
static hc_Globals glob = {
				.fp = NULL,
				.tmp = ""
						};

char *Keywords[NUM_OF_KEYWORDS][MAX_INPUT] = {
	{ "@class" },
	{ "@properties" },
	{ "@methods" },
	{ "@objects" },
	{ "@this" },
	{ "@string" },
	{ "@define" },
	{ "@import" },
	{ "@end" }
};

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

			if(hc_ParseProperties()) {
				fprintf(stderr, "Properties parsing error. Aborting.\n");
				return 1;
			}
		}
	}

	else {
		fprintf(stderr, "File named '%s' cannot be accessed.\n", path);
		return 1;
	}

	fclose(glob.fp);

	return 0;
}

u8
hc_ParseClass(void) {

	while(ff == 1) {
		if(cmp(CLASS) == 0) {
			ff;
			(void)snprintf(glob.src.class_name, sizeof(glob.src.class_name),
			"%s", glob.tmp);
			return 0;
		}

		else {
			fprintf(stderr, "Beginning of Hammer-C file must start with %s declaration."
			Keywords[CLASS][0] );
			return 1;
		}
	}

	return 0;
}

u8
hc_ParseProperties(void) {

	while(ff == 1) {
		if(cmp(PROPERTIES) == 0) {
			while(ff == 1) {
				//xx
			}
		}

		else {
			fprintf(stderr, "After class declaration properties must be defined. Aborting.\n");
			return 1;
		}
	}

	return 0;
}

u8
hc_GenerateC(void) {
	return 0;
}

#endif // HAMMERC_IMPLEMENTATION
#endif // HAMMERC_C
