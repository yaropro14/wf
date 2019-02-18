#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


#include "dictionary.h"
#include "word.h"
#include "reader.h"


#define MAKE_D(p)												\
	struct dictionary_data * d = (struct dictionary_data *) (p + 1);



struct dictionary_data
{
	struct word_data * words;
	int num_of_word;
};




Dictionary dict_create()
{
	void * pd = calloc(1, sizeof(struct dictionary_fn) + sizeof(struct dictionary_data));
	
	Dictionary p = (Dictionary) pd;
	MAKE_D(p);
	
	p->search_word = dictionary_search_word;
	p->push = dictionary_push;
	p->print_all = dictionary_print_all;
	p->destructor = dictionary_destructor;
	
	d->words = (struct word_data *) calloc (1, sizeof(struct word_data));
	d->num_of_word = 0;
	
	return p;
};


struct word_data * dictionary_search_word(Dictionary pd, char * word)
{
	MAKE_D(pd);
	
	if(d->num_of_word == 0)
		return NULL;
	
	int i = 0;
	
	if(d->num_of_word == 0)
		return NULL;
		
	for(i = 0; i < d->num_of_word; i ++)
	{
		if(strcmp(d->words[i].word, word) == 0)
			return &d->words[i];
	}
	
	return NULL;
}


void dictionary_push(Dictionary pd, char * word, Word pw)
{
	MAKE_D(pd);
	
	d->num_of_word ++;
	d->words = (struct word_data *) realloc (d->words, d->num_of_word * sizeof(struct word_data));
	d->words[d->num_of_word - 1] = pw->new_word(word);
}


void dictionary_print_all(Dictionary pd, Word pw)
{
	MAKE_D(pd);
	
	for(int i = 0; i < d->num_of_word; i ++)
	{
		pw->print(d->words[i]);
	}
}


void dictionary_destructor (Dictionary p)
{
	free(p);
}
