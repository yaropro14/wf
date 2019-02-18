#ifndef word_h
#define word_h


#include <stdio.h>
#include <ctype.h>
#include <string.h>


typedef struct word_fn * Word;


struct word_data
{
	char * word;
	int frequency;
};


struct word_fn
{
	void (* add)(struct word_data * place_in_dictionary);
	void (* print)(struct word_data place_in_dictionary);
	struct word_data (* new_word)(char * word);
	void (* destructor)(Word p);
};


void word_add(struct word_data * place_in_dictionary);
void word_print(struct word_data place_in_dictionary);
struct word_data word_new_word(char * word);
Word word_create();
void word_destructor(Word p);



#endif
