#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../include/myheader.h"
#include "utils.h"

#define MY_SIZE 50

/*
* Programmer Name:Colden Jeanmnonod
*Lab Name: METADATA2
* Date: NOV 1: 2023
* DUE DATE NOV 8 2023
* Assingment: lab8
* Class and Semester: CIS:1057 section: 004
* Description: This Program will generate summary statistics on the dataset
*/

void summary_statistics(int my_array[], const int n );

int lowest_array_value( const int a[], const int count );
int highest_array_value( const int a[], const int count );
double mean_average_array( const int a[], const int count );
int median_array_value( const int a[], const int count );
int mode_array_value( const int a[], const int count );
int range_array_value( const int a[], const int count );
int generate_frequencies( const int a[], const int count, int freq[], int freq_values[]);
void print_frequencies( const int freq[], const int freq_values[], const int count );
int user_fill_array( int a[], const int max_count );
/*
* Programmer Name:Colden Jeanmnonod
*Lab Name: METADATA 2
* Date: OCT 21: 2023
* DUE DATE NOV 10 2023
* Assingment: lab7
* Class and Semester: CIS:1057 section: 004
*/


void main  ()
{

program_identification(8, "metadata", "This Lab will print out the random values: ");
int size = 0;

printf("Please enter a value between 4 and 100");

scanf("%d", &size);

int main_array[size];


user_fill_array( main_array, size);

summary_statistics(main_array, size);
}

void summary_statistics(int my_array[],const int n){
/*
*Function Name: summary_statistics
*Description: through the given array should print out the mean mode median range lowest highest and frequencies within the array
*preconditions: my_array[], n
*postcondition: none
*Global: None
*Returns: none
*/
	int lowest, highest, median, range, mode;
	int freq[n];
	int freq_values[n];
	double mean;

	mean = mean_average_array(my_array, n);

	printf("The mean is %lf \n", mean);

	highest = highest_array_value(my_array, n);

	lowest = lowest_array_value(my_array, n);

	range = range_array_value(my_array, n);

	median = median_array_value(my_array, n);

	mode = mode_array_value(my_array, n);

	printf("The lowest is %d \n", lowest);
	printf("The highest is %d \n", highest);
	printf("The median is %d \n", median);
  	printf("The range is %d \n", range);
  	printf("The mode is %d \n", mode);
	
	generate_frequencies(my_array, n, freq, freq_values);
	print_frequencies(freq, freq_values, n);
}



double mean_average_array( const int a[], const int count ){
/*
*Function Name: mean_average_array
*Description: returns the value of the mean
*preconditions: a[], count
*postcondition: none
*Global: None
*returns mean
*/

	double mean = (double) sum_array(a, count) / count ;

	return mean;


}



int highest_array_value( const int a[], const int count ){
/*
*Function Name: highest_array_value
*Description: returns the highest value
*preconditions: a[], count
*postcondition: none
*Global: None
*Returns: highest
*/


	int highest;
	sort_array(a, count);

	
	highest = a[count -1];
	return highest;
}

int lowest_array_value( const int a[], const int count ){
/*
*Function Name: lowest_array_value
*Description: returns the lowest value
*preconditions: a[], count
*postcondition: none
*Global: None
*Returns: lowest
*/
	int lowest;
	sort_array(a, count);
	lowest = a[0];
	return lowest;
	printf("The lowest is %d \n", a[0]);

}

int range_array_value( const int a[], const int count ){
/*
*Function Name: range_array_value
*Description: returns the range value
*preconditions: a[], count
*postcondition: none
*Global: None
*Returns: range
*/
	sort_array(a, count);

	int range = a[count - 1] - a[0];
	
	return range;
	printf("The range is %d \n", range);
}


int median_array_value( const int a[], const int count ){
/*
*Function Name: median_array_value
*Description: returns the median value
*preconditions: a[], count
*postcondition: none
*Global: None
*Returns: median
*/
	sort_array(a, count);

	int median = (a[count / 2] + a[ (count / 2) + 1]) / 2;

	return median;
	print_values_tag("Sort for median: ", a, count);
	printf("The Median is: %d \n", median);


}

int mode_array_value( const int a[], const int count ){
/*
*Function Name: mode_array_value
*Description: returns the mode value
*preconditions: a[], count
*postcondition: none
*Global: None
*Returns: mode
*/
	int max_count, mode;
	max_count = 0;
	for(int i = 0; i < count; i++){
		int fun_counter = 0;
		for(int j = 0; j < count; j++){
			if( a[j] == a[i]){
				fun_counter++;
			}
		}
		  if(fun_counter > max_count){
                max_count = fun_counter;
                mode = a[i];
        }else if(fun_counter == max_count){
                mode = max_count;


	}

	}


	
	return mode;
}

int generate_frequencies( const int a[], const int count, int freq[], int freq_values[]){
/*
*Function Name: generate_frequencies
*Description: should assign how frequently certain values appear
*preconditions: a[], count, freq[], freq_values[]
*postcondition: none
*Global: None
*Returns: vald_vals
*/

    	for(int i = 0; i < count; i++){
	   freq[i]=0;
	}

	int vald_vals = 0;
	for(int m = 0; m < count; m++){
	int found = 0;
	
		for(int j = 0;j < vald_vals; j++){
			if(freq_values[j] == a[m]){
			found = 1;
			freq[j]++;	
			break;

			}
		}
		if(!found) {
			freq_values[vald_vals] = a[m];
			freq[vald_vals] = 1;
			vald_vals++;
		}
	}
	return vald_vals;

}


void print_frequencies( const int freq[], const int freq_values[], const int count ){
/*
*Function Name: print_frequencies
*Description: prints out the frequency of the values
*preconditions: freq[], freq_values[], count
*postcondition: none
*Global: None
*Returns: none
*/
	for(int i = 0; i < count; i++){
		printf("The frequency of %d is %d  \n", freq_values[i], freq[i]);
	}

}


int user_fill_array( int a[], const int max_count ){
/*
*Function Name: user_fill_array
*Description:  allows the user to input a number of values based on them amount they chose
*preconditions: a[], max_count
*postcondition: none
*Global: None
*Returns: none
*/
int count = 0;
int amount = 0;
	do{
		printf("Please put in a value for the amount of elements in an array between 4-100");
		scanf("%d", &amount);
	}while(amount<4 && amount > 100);
	do{
		int user_inp = 0;
		printf("Please put in a value for the value at %d",  count+1);
		scanf("%d", &user_inp);
		a[count] = user_inp;
		count++;
	}while(count < amount);

}
