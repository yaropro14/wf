#include <stdio.h>
#include <ctype.h>
#include <string.h>


#include "dictionary.h"
#include "word.h"
#include "reader.h"


void make_word(Reader pr, Dictionary pd, Word pw);


int main(int argc, char * argv[])
{	
	int i = 0;
	
	Reader pr = reader_create();
	
	Dictionary pd = dict_create();
	
	Word pw = word_create();
	
	for(i = 1; i < argc; i ++)
	{
		pr->openfile(pr, argv[i]);
		make_word(pr, pd, pw);
		
	}
	
	if(i == 1)
	{
		make_word(pr, pd, pw);
	}
	
	pd->print_all(pd, pw);
	
	pr->destructor(pr);
	
	return 0;
}


void make_word(Reader pr, Dictionary pd, Word pw)
{
	for( ; ; ) 
	{

		char * word = pr->getword(pr);
		
		if(word == NULL)
			break;
			
		struct word_data * p = pd->search_word(pd, word);
		
		if(p == NULL)
			pd->push(pd, word, pw);
			
		else
			pw->add(p);

	}
}
