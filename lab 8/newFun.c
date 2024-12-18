#include <stdio.h>
#include <stdlib.h>



/*
* Programmer Name:Colden Jeanmnonod
*Lab Name: Group Project 2
* Date: NOV 17 2023
* DUE DATE NOV 27 2023
* Assingment: lab8
* Class and Semester: CIS:1057 section: 004
* Description: This Program will take the already pre made phrase and run it through the function and output the amount of consonants and vowels
*/

int vowel_constants( const char *c);

void main (){

char phrase[24] = "Never eat soggy waffles";


printf("The phrase is %s \n", phrase);
vowel_constants( phrase );


}



int vowel_constants( const char *c){
	/*
	*Function Name: vowel_constants
	*Description: Runs the pre selected phrase through the while loop which will in turn count up the amount of vowels and consonants.
	*preconditions: c
	*postcondition: none
	*Global: None
	*Returns: none
	*/


	int i = 0;
	int space_count = 0;
        int vowel_count = 0;
        int const_count = 0;
	char vowels [] = "aeiouyAEIOUY";

	while( c[i] != '\0'){
		if(c[i] == 'a' || c[i]== 'A' || c[i] == 'e' || c[i] == 'E' || c[i] == 'i' || c[i] == 'I' || c[i] == 'o' || c[i] == 'O' || c[i] == 'u' || c[i] == 'U' || c[i] == 'y' || c[i] == 'Y'){
			vowel_count++;
		}else if (c[i] == ' '){
		space_count ++;

		}else{
		 const_count++;
		
		}
		i++;
	}

		printf("There are %d vowels, and there are %d consonants \n", vowel_count, const_count);
}
