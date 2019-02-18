#ifndef dictionary_h
#define dictionary_h


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "word.h"


typedef struct dictionary_fn * Dictionary;


struct dictionary_fn
{
	struct word_data * (* search_word)(Dictionary pd, char * word);
	void (* push)(Dictionary pd, char * word, Word pw);
	void (* print_all)(Dictionary pd, Word pw);
	void (* destructor)(Dictionary pd);
};


Dictionary dict_create();
struct word_data * dictionary_search_word(Dictionary pd, char * word);
void dictionary_push(Dictionary pd, char * word, Word pw);
void dictionary_print_all(Dictionary pd, Word pw);
void dictionary_destructor (Dictionary p);


#endif
