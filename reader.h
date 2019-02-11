#ifndef reader_h
#define reader_h


#include <stdio.h>
#include <ctype.h>
#include <string.h>


struct read
{
	int fd; // fd = 0 - read from stdin, fd = 1 - read from file.
	FILE * file_in;
} reader;

void make_read();
void reader_openfile(char * file);
char * reader_getword();
char * read_word(char * word);


#endif
