#ifndef word_h
#define word_h


#include <stdio.h>
#include <ctype.h>
#include <string.h>


struct word
{
	char * word;
	int frequency;
};


void word_add(struct word * place_in_dictionary);
void word_print(struct word place_in_dictionary);
struct word word_create(char * word);


#endif
