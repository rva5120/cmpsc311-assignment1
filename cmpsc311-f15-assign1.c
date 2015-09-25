// //////////////////////////////////////////////////////////////////////////////
//
//  File           : cmpsc311-f15-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMPSC311 at Penn State University.  See the related
//                   assignment page for details.
//
//   Author        : Raquel Alvarez
//   Last Modified : 9/1/2015
//

// Include Files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Project Includes
//#include </home/raquelalvarez/cmpsc311/assign1/a1support.h>
#include <a1support.h>

// Functions

// //////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CRUD simulator
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure

int main(int argc, char *argv[]) {

	// Local variables
	// NOTE: this is where you will want to add some new variables
	float f_array[20];
	int i_array[20];
    	float mult[] = {1.0, 1.5, 2.0, 3.0};
	int i = 0;
	float sum_float = 0;
	int sum_int = 0;
	int temp = 0;

	//printf("Starting Program");

	// First, lets read in the float numbers to process
	for (i=0; i<20; i++) {
		scanf("%f", &f_array[i]);
	}

    	// 2. for each value in the float array convert:
	//	a. If number >= 10, then multiply by M_PI
	//	b. Otherwise, multiply by 42.4
	for (i = 0; i < 20; i++) 
	{
		if (f_array[i] >= 10) 
		{
			f_array[i] = f_array[i]*M_PI;
		}
		else
		{
			f_array[i] = f_array[i]*42.4;
		}
	}

	// ------------ debug --------------
	//printf("number = %f \n", -31.730);
	//int temp = -31.730;
	//printf("round -32 = %d \n", temp);
	//int temp2 = abs(temp);
	//printf("abs 32 = %d \n", temp2);
	

	// 3. Fill second array of integers, 
	//    where i_array[i] = abs(f_array[i]) rounded
	for (i = 0; i < 20; i++)
	{	
		temp = round(f_array[i]);
		temp = abs(temp);
		i_array[i] = temp;	
	}

	// 4. Print both arrays
	printf("Array of float values: ");
	print_array_float(f_array, 20);
	printf("\n");
	
	printf("Array of integer values: ");
	print_array_integer(i_array, 20);
	printf("\n");

	// 7. Print the sum of both arrays
	sum_float = sum_array_float(f_array, 20);
	printf("The sum of float array is: %.3f \n", sum_float);
	sum_int = sum_array_integer(i_array, 20);
	printf("The sum of integer array is: %d \n", sum_int);

	// 5 and 6. Euclid's Algorithm Loop
	//cout << "GCD List:" << endl;
	for (i = 0; i < 19; i++)
	{
		printf("The GCD(%d,%d) = %d \n", i_array[i], i_array[i+1], euclids_algorithm(i_array[i], i_array[i+1]));
	}

	// 8. Sort both arrays
	selection_sort_float(f_array, 20);
	selection_sort_integer(i_array, 20);
	// And print both sorted arrays
	printf("Array of sorted float values:");
	print_array_float(f_array, 20);
	printf("\n");
	
	printf("Array of sorted integer values:");
	print_array_integer(i_array, 20);
	printf("\n");

	// 9. Graph y = sin(x*mult), where mult = [1.0, 1.5, 2.0, 3.0]
	for (i = 0; i < 4; i++)
	{
		printf("\t\t\tGraph of y=sin(x*%.2f) \n", mult[i]);
		graph_sin(mult[i]);
	} 

	// Return successfully
	return(0);
}
