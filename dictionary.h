#ifndef dictionary_h
#define dictionary_h


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


struct dictionary
{
	struct word * words;
	int num_of_word;
} dict;


void dictionary();
struct word * search_in_dictionary(char * word);
struct word * search_in_dictionary(char * word);
void dictionary_push(char * word);
void dictionary_print();


#endif
