#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


#include "dictionary.h"
#include "word.h"
#include "reader.h"


void dictionary()
{
	dict.words = (struct word *) calloc (1, sizeof(struct word));
}


struct word * search_in_dictionary(char * word)
{
	
	if(dict.num_of_word == 0)
		return NULL;
	
	int i = 0;
	
	if(dict.num_of_word == 0)
		return NULL;
		
	for(i = 0; i < dict.num_of_word; i ++)
	{
		if(strcmp(dict.words[i].word, word) == 0)
			return &dict.words[i];
	}
	
	return NULL;
}


void dictionary_push(char * word)
{
	dict.num_of_word ++;
	dict.words = (struct word *) realloc (dict.words, dict.num_of_word * sizeof(struct word));
	dict.words[dict.num_of_word - 1] = word_create(word);
}


void dictionary_print()
{
	for(int i = 0; i < dict.num_of_word; i ++)
	{
		word_print(dict.words[i]);
	}
}
