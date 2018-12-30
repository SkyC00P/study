#include "common.h"
#include <ctype.h>
static void _skip_note(FILE * fp) {
	CheckPtr(fp);
	char ch = fgetc(fp);
	while (ch != EOF && isspace(ch)) {
		ch = fgetc(fp);
	}

	while (ch == '#') {
		while (ch != '\n' && ch != EOF && ch != '\r') {
			ch = fgetc(fp);
		}
		while (ch != EOF && isspace(ch)) {
			ch = fgetc(fp);
		}
	}

	ungetc(ch, fp);
}

static int _read_int(FILE * fp) {
	CheckPtr(fp);
	_skip_note(fp);
	int num;
	if (fscanf(fp, "%d", &num) != 1) {
		Exit_with_msg("read int err");
	}
	return num;
}

static char _read_ve(FILE * fp) {
	CheckPtr(fp);
	_skip_note(fp);
	char ch;
	if (fscanf(fp, "%c,", &ch) != 1) {
		Exit_with_msg("read err");
	}
	return ch;
}

static void _read_edge_g(FILE * fp, char * v1, char * v2) {
	CheckPtr(fp);
	_skip_note(fp);
	if (fscanf(fp, "%c-%c", v1, v2) != 2) {
		Exit_with_msg("read err");
	}
}

static void _read_edge_n(FILE * fp, char * v1, char * v2, int * weight) {
	CheckPtr(fp);
	_skip_note(fp);
	if (fscanf(fp, "%c-%c-%d", v1, v2, weight) != 3) {
		Exit_with_msg("read err");
	}
}