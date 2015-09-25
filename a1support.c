// //////////////////////////////////////////////////////////////////////////////
//
//  File          : a1support.c
//  Description   : This is a set of general-purpose utility functions we use
//                  for the 311 homework assignments.
//
//  Author   : Raquel Alvarez
//  Created  : 9/1/2015

// Include Files
#include <stdio.h>
#include <math.h>

// Functional Prototypes:

// ------------- Print Array Float -------------
// Input: array of floats to print
// Output: prints floats in array, then return
// Prints out the values in an array of floats
void print_array_float(float arry[], int size)
{
	int i = 0;
	// Print out the list of float values
	for (i = 0; i < size; i++)
	{
		printf("float[%d] = %.3f\n", i, arry[i]);
	}
	
	return;
}
//----------------------------------------------


// ------------ Print Array Integer ------------
// Input: array of ints
// Output: print the ints in array and return
// Prints out the values in an array of integers
void print_array_integer(int arry[], int size)
{
	int i = 0;
	// Print out the list of integer values
	for (i = 0; i < size; i++)
	{
		printf("integer[%d] = %d \n", i, arry[i]);
	}

	return;
}
// --------------------------------------------


// ------------ Sum Array Float ---------------
// Input: array of floats
// Output: return sum of values in the array
// Computes the sum of an array of floats and returns the result
float sum_array_float(float arry[], int size)
{	
	int i = 0;
	float sum = 0;
	// Compute the sum of the float values
	for (i = 0; i < size; i++)
	{
		sum = sum + arry[i];
	}

	return sum;
}
// --------------------------------------------


// ------------ Sum Array Integer -------------
// Input: array of ints
// Output: return sum of ints
// Computes the sum of an array of integers and returns the result
int sum_array_integer(int arry[], int size)
{
	int sum = 0;
	int i = 0;
	// Compute the sum of the integer values
	for (i = 0; i < size; i++)
	{
		sum = sum + arry[i];	
	}

	return sum;
}
// --------------------------------------------


// ----------- Euclidean Algorithms -----------
// Input: two integers to take the gratest common denominator from
// Output: the gratest common denominator
int euclids_algorithm(int a, int b)
{
	int gcd = 0;
	int not_found = 1;
	int r = 0;
	int temp = 0;

	

	// Euclid's algorithm to calculate the greatest common divisor
	while (not_found == 1)
	{
		// swap a and b if a < b, we want to devide larger/smaller numbers
		if (a < b)
		{
			// swap
			temp = a;
			a = b;
			b = temp;
		}
		
		r = a % b;	// calculate remainder

		//printf("DEBUG r = 29? %d \n", r);		
		
		// we want to keep calculating until the remainder is 0 
		if (r > 0)
		{
			// the algorithms says that while the remainder is not 0,
			// the remainder can be used to calculate the GCD, so we want to swap values
			// to calculate the GCD with the smallest numbers possible
			a = b;
			b = r;
			//r = 0;
			not_found = 1;
		}
		// when we reached remainder 0, we found the GCD
		else if(r == 0)
		{
			gcd = b;
			not_found = 0;
		}
		// a negative remainder should be an error
		else
		{
			printf("Error calculating GCD, negative remainder \n");
			not_found = 0;
		}
	}
	return gcd;
}
// --------------------------------------------


// -------------- Selection Sort --------------
// Input: float array and size
// Output: sorted array
// NOTE: more comments on the next functions (same code, different data types)
void selection_sort_float(float arry[], int size)
{
	int min_index = 0;
	float temp = 0;
	int i = 0;
	int j = 0;

	// Sort the list of float values
	for (i = 0; i < size-1; i++)
	{
		min_index = i;
		
		for (j = i+1; j < size; j++)
		{
			if (arry[min_index] > arry[j])
			{
				min_index = j;
			}
		}
		
		// if a[i] was not the smallest value, then swap a[i] with the current smallest value
		if (min_index != i)
		{
			temp = arry[i];
			arry[i] = arry[min_index];
			arry[min_index] = temp;
		}
	}

	return;
}
// --------------------------------------------


// ------------ Selection Sort Int ------------
// Input: integer array and size
// Output: sorted array
void selection_sort_integer(int arry[], int size)
{
	int min_index = 0;
	int temp = 0;
	int i = 0;
	int j = 0;

	// Sort the list of integer values
	for (i = 0; i < size-1; i++)
	{
		min_index = i;	// store the index of the min value
		
		// now, loop through the rest of the numbers ahead of a[i] (we assume 0 through i-1 are sorted)
		for (j = i+1; j < size; j++)
		{
			// if the current value is smaller than the stored min, then update the index of min
			if (arry[min_index] > arry[j])
			{
				min_index = j;
			}
		}
		
		// after finding the min, swap it with the first value if the first value is not the min itself
		// if a[i] was not the smallest value, then swap a[i] with the current smallest value
		if (min_index != i)
		{
			temp = arry[i];
			arry[i] = arry[min_index];
			arry[min_index] = temp;
		}
	}

	return;
}
// --------------------------------------------


// ---------------- Graph Sin -----------------
// Input: mult, in y = sin(mult * x)
// Output: graph of sin
// Description: This function prints the graph of sine(x), 
// 		where x is multiplied by the function parameter 
void graph_sin(float mult)
{	
	// Graph the sin(x*multiplier) function
	float x_axis[71] = {0};		// array of x axis values, range from -3.5 to 3.5
	float y[71] = {0};		// array of y values, corresponding to y[i] = sin (mult * x[i])
	char grid[71][31] = {{'0'}};	// grid that represents both axis together, will store '*' for each (x,y) pair
					// x -> -3.5 to 3.5, 71 values ----- y -> -1.5 to 1.5, 31 values
	float x_bound = -3.5;		// variable used as a counter that will range from -3.5 to 3.5
	float y_bound = 0;		// variable used as a counter to print the graph (from 1.5 to -1.5)
	int grid_x = 0;			// these variables are used to map the actual axis values
	int grid_y = 0;			// to the corresponding array values (ex. for y axis: -1.4 = 29)
	
	int i = 0;			// for loop variable
	int yy = 0;			// for loop variable to loop through y values (for printing)
	int xx = 0;			// for loop variable to loop through x values (for printing)

	// 1. fill up x_axis with values from -3.5 to 3.5
	for (i = 0; i < 71; i++)
	{
		x_axis[i] = x_bound;
		x_bound += 0.1;		// increase x_bound by 0.1
	}
	
	// debug
	//printf("x_bound should be 3.6, is it?	%f \n", x_bound);

	// 2. fill up y by calculating the value of y[i], doing sin(mult*x[i])
	for (i = 0; i < 71; i++)
	{
		y[i] = sin(mult*x_axis[i]);	// sin(radians)
	}

	// 3. fill up grid with * for every (x,y) pair -> grid[x[i]][y[i]] = '*'
	for (i = 0; i < 71; i++)
	{
		// map x_axis[] and y[] to grid values:
		grid_x = 35 + 10*x_axis[i];	// map values -3.5,3.5 on the x axis to corresponding 0,70 on array
		grid_y = round(15 + 10*y[i]);		// map values -1.5,1.5 on the y axis to corresponding 0,30 on array
		grid[grid_x][grid_y] = '*';
		//printf("grid[%d][%d] = %c -- x=%f  y=%f \n", grid_x, grid_y, grid[grid_x][grid_y], x_axis[i], y[i]);
	}	

	y_bound = 1.5;

	// 4. print graph using printf
	// start printing from y = 1.5 , for all x values (-3.5 to 3.5)
	for (yy = 30; yy >= 0; yy--)
	{
		printf("\n");
		// print y axis value (only signed when negative) and |, then print spaces or *
		printf("%4.1f |", y_bound);

		for (xx = 0; xx < 71; xx++)
		{
			if (grid[xx][yy] == '*')
			{
				//print star
				printf("*");
			}
			else
			{
				//print space
				printf(" ");
			}		
		}
		y_bound -= 0.1;
	}

	printf("\n");

	// the x axis dashes start 6 spaces after the new line
	printf("      ");
	
	// print the x-axis line
	for (i = 0; i < 71; i++)
	{
		printf("_");
	}
	printf("\n");
	
	// the x_axis values start 6 spaces after the new line, and -3 starts 6 spaces after the start of the grid
	printf("%12d", -3);

	// print the rest of the values for the x axis (-2 to 3)
	for (i = -2; i < 4; i++)
	{
		// each value is 10 spaces apart, so print 9 spaces and the value (or 8 spaces plus the sign and value, if < 0)
		printf("%10d", i);
	}
	
	printf("\n\n\n");
	
	return;
}
// --------------------------------------------
