#include <iostream>
using namespace std;

// function prototyping
int replaceElements(double array[], double value, double newValue);
void replaceNegativeValues(double array[4][4]);
void replaceZeroPoint5Values(double array[4][4]);
void displayArray(double array[4][4]);

int main() {
	
	// test (replaceElements function)
	double array[] = {2, 34, 9, 10, 2, 12, 3, 0, 2, 22, 33, 2};
	cout << "Question 1 \n";
	cout << "Number of Replaced Elements: " << replaceElements(array, 2, -1) << endl << endl;
	
	// test (replaceNegativeValues function )
	double matrixA[4][4] = {
						{1,  9,  0, -3},
						{2,  8, -2,  6},
						{-1, 4,  9,  5},
						{6, -9,  0,  1}
	                 };
	cout << "Question 2 \n";
	replaceNegativeValues(matrixA);
	
	// test (replaceZeroPoint5Values function )
	double matrixB[4][4] = {
						{0.5, 9,  0,  -3},
						{2,   8,  0.5, 6},
						{0.5, 4,  9,   5},
						{6,  -9,  0.5, 1}
	                 };
	cout << "Question 3 \n";
	replaceZeroPoint5Values(matrixB);
	
	return 0;
}

/**
 *
 * Question 1
 * This function replaces all the elements that equals a given value with the given new value
 * and returns the number of replaced elements
 *
*/
int replaceElements(double array[], double value, double newValue)
{
	int numberOfReplacedElements = 0;
	
	for(int i = 0; i < 12; i++)
	{
		if(array[i] == value)
		{
			array[i] = newValue;
			numberOfReplacedElements ++;
		}
	}
	return numberOfReplacedElements;
}


/**
 *
 * Question 2
 * This function replaces all the negative element values with the 
 * sum of the squares of each element in that row
 *
*/
void replaceNegativeValues(double array[4][4])
{	
	int n = 4;
	double sum = 0.0;
	
	for(int i = 0; i < n; i++)
	{
		sum = 0.0; // reset sum to be zero for next row
		
		for(int j = 0; j < n; j++)
		{
			sum += array[i][j] * array[i][j]; // find sum of squares of each element in a row
		}
		
		for(int j = 0; j < n; j++)
		{
			array[i][j] = array[i][j] < 0 ? sum : array[i][j]; // replace negative values
		}
		
	}
	
	// display new array
	displayArray(array);
}

/**
 *
 * Question 3
 * This function replaces all the element's values equal to 0.5 with the 
 * sum of the cubic of each element in that row
 *
*/
void replaceZeroPoint5Values(double array[4][4])
{	
	int n = 4;
	double sum = 0.0;
	
	for(int i = 0; i < n; i++)
	{
		sum = 0.0; // reset sum to be zero for next row
		
		for(int j = 0; j < n; j++)
		{
			sum += array[i][j] * array[i][j]  * array[i][j]; // find sum of cubic of each element in a row
		}
		
		for(int j = 0; j < n; j++)
		{
			array[i][j] = array[i][j] == 0.5 ? sum : array[i][j]; // replace values equal to 0.5
		}
		
	}
	
	// display new array
	displayArray(array);
}

/**
 *
 * Displays all the values in the given 2D array
 *
*/
void displayArray(double array[4][4])
{
	int n = 4;
	
	for(int i = 0; i < n; i++)
	{ 	cout << "[";
		for(int j = 0; j < n; j++)
		{
			cout << array[i][j] << " ";	
		}	
		cout << "] \n";	
	}
	cout << endl;
}















