#include <stdio.h>
#include <ctype.h>
#include <string.h>


#include "dictionary.h"
#include "word.h"
#include "reader.h"


void make_word(int number_of_files, int open_files);


int main(int argc, char * argv[])
{	
	int number_of_files = argc - 1;
	int open_files = 0;
	
	make_read();
	
	dictionary();
	
	while(open_files < number_of_files)
	{
		reader_openfile(argv[open_files + 1]);
		open_files ++;
		
		make_word(number_of_files, open_files);
		
	}
	
	if(open_files == 0)
	{
		make_word(number_of_files, open_files);
	}
	
	dictionary_print();
	
	
	return 0;
}


void make_word(int number_of_files, int open_files)
{
	for( ; ; ) 
	{

		char * word = reader_getword();
		
		if(word == NULL)
			break;
			
		struct word * place_in_dictionary = search_in_dictionary(word);
		
		if(place_in_dictionary == NULL)
			dictionary_push(word);
			
		else
			word_add(place_in_dictionary);

	}
}
