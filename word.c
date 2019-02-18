#include <stdio.h>
#include <ctype.h>
#include <string.h>


#include "dictionary.h"
#include "word.h"
#include "reader.h"


Word word_create()
{
	void * pw = calloc(1, sizeof(struct word_fn));
	
	Word p = (Word) pw;
	
	p->add = word_add;
	p->print = word_print;
	p->new_word = word_new_word;
	p->destructor = word_destructor;
	
	return p;
}


void word_add(struct word_data * word)
{
	word->frequency ++;
};


void word_print(struct word_data place_in_dictionary)
{
	printf("%s - %d\n", place_in_dictionary.word, place_in_dictionary.frequency);
}


struct word_data word_new_word(char * word)
{
	struct word_data * new_word = (struct word_data *) calloc(1, sizeof(struct word_data));
	
	new_word->word = strdup(word);
	new_word->frequency ++;
	
	return * new_word;
}

void word_destructor(Word p)
{
	free(p);
}
