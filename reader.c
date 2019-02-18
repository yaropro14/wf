#include <stdio.h>
#include <ctype.h>
#include <string.h>


#include "dictionary.h"
#include "word.h"
#include "reader.h"


#define MAKE_R(p)												\
	struct reader_data * r = (Reader) (p + 1);


struct reader_data
{
	int fd; // fd = 0 - read from stdin, fd = 1 - read from file.
	FILE * file_in;
};


Reader reader_create()
{
	void * pr = calloc(1, sizeof(struct reader_fn) + sizeof(struct reader_data));
	
	Reader p = (Reader) pr;
	MAKE_R(p);
	
	p->openfile = reader_openfile;
	p->getword = reader_getword;
	p->destructor = reader_destructor;
	
	r->fd = 0;
	r->file_in = stdin;
	
	return p;
}


void reader_openfile(Reader p, char * file_name)
{
	MAKE_R(p);
	
	if(r->file_in)
		fclose(r->file_in);
	
	r->fd = 1;
	
	r->file_in = fopen(file_name, "r");
}


char * reader_getword(Reader p)
{
	char * word = NULL;
	
	word = reader_makeword(p, word);
		
	return word;
}



char * reader_makeword(Reader p, char * word)
{
	MAKE_R(p);
	
	if(r->file_in == NULL)
	{
		printf("ERROR\n");
		return NULL;
	}
	
	word = (char *) calloc(1, sizeof(char));
	
	int w = 0;
	int i = 0;
	
	for( ; ; )
	{
		char c = (char) fgetc(r->file_in);
		
		if(c == EOF)
		{
			if(i == 0)
				free(word);
				
			return NULL;
		}
		
		if(isalpha(c))
		{
			i ++;
			word = (char *) realloc(word, i * sizeof(char));
			w = 1;
			word[i - 1] = (char)c;
		}
		else if(w == 1)
		{
			return word;
		}
			
	}
	
	
}


void reader_destructor (Reader p)
{
	MAKE_R(p);
	
	free(p);
	free(r);
	
}

