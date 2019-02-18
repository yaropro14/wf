#include <stdio.h>
#include <ctype.h>
#include <string.h>


#include "dictionary.h"
#include "word.h"
#include "reader.h"


void make_word(Reader pr);


int main(int argc, char * argv[])
{	
	int i = 0;
	
	Reader pr = reader_create();
	
	dict_create();
	
	for(i = 1; i < argc; i ++)
	{
		pr->openfile(pr, argv[i]);
		make_word(pr);
		
	}
	
	if(i == 1)
	{
		make_word(pr);
	}
	
	dictionary_print();
	
	//pr->destructor(pr);
	
	return 0;
}


void make_word(Reader pr)
{
	for( ; ; ) 
	{

		char * word = pr->getword(pr);
		
		if(word == NULL)
			break;
			
		struct word * p = search_in_dictionary(word);
		
		if(p == NULL)
			dictionary_push(word);
			
		else
			word_add(p);

	}
}
