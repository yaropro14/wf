#ifndef reader_h
#define reader_h


#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct reader_fn * Reader;

struct reader_fn
{
	void (* openfile)(Reader p, char * file_name);
	char * (* getword)(Reader p);
	void (* destructor)(Reader p);
};


Reader reader_create();
void reader_openfile(Reader p, char * file_name);
char * reader_getword(Reader p);
char * reader_makeword(Reader p, char * word);
void reader_destructor (Reader p);

#endif
