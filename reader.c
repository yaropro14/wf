#include <stdio.h>
#include <ctype.h>
#include <string.h>


#include "dictionary.h"
#include "word.h"
#include "reader.h"


void make_read()
{
	reader.fd = 0;
	reader.file_in = stdin;
}


void reader_openfile(char * file_name)
{
	reader.fd = 1;
	
	reader.file_in = fopen(file_name, "r");
}


char * reader_getword()
{
	char * word = NULL;
	
	word = read_word(word);
		
	return word;
}



char * read_word(char * word)
{
	if(reader.file_in == NULL)
	{
		printf("ERROR\n");
		return NULL;
	}
	
	word = (char *) calloc(1, sizeof(char));
	
	int w = 0;
	int i = 0;
	
	for( ; ; )
	{
		char c = (char) fgetc(reader.file_in);
		
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

