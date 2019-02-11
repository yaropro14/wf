#include <stdio.h>
#include <ctype.h>
#include <string.h>


#include "dictionary.h"
#include "word.h"
#include "reader.h"


void word_add(struct word * word)
{
	word->frequency ++;
};


void word_print(struct word place_in_dictionary)
{
	printf("%s - %d\n", place_in_dictionary.word, place_in_dictionary.frequency);
}


struct word word_create(char * word)
{
	struct word * new_word = (struct word *) calloc(1, sizeof(struct word));
	new_word->word = strdup(word);
	new_word->frequency ++;
	return * new_word;
}
