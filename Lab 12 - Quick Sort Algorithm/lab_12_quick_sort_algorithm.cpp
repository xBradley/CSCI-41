/*
Bradley Gallardo
CS41
Quicksort Algorithm
Sorts an array from least to greatest
*/

// This program demonstrates the QuickSort Algorithm.
#include <iostream>
using namespace std;

// Function prototypes
void quickSort(int [], int, int);
int partition(int [], int, int);
void swap(int &, int &);

int main()
{
   const int SIZE = 10;  // Array size
   int count;            // Loop counter
   int array[SIZE] = {19, 7, 73, 41, 5, 11, 9, 13, 3};

   cout << "Orginal Array" << endl;
   // Display the array contents.
   for (count = 0; count < SIZE; count++)
      cout << array[count] << " ";
   cout << endl << endl;
   
   cout << "Table of value" << endl;
   // Sort the array.
   quickSort(array, 0, SIZE - 1);
   cout << endl;

   cout << "Sorted Array" << endl;
   // Display the array contents.
   for (count = 0; count < SIZE; count++)
      cout << array[count] << " ";
   cout << endl;


   system("pause");
   return 0;
}

//************************************************
// quickSort uses the quicksort algorithm to     *
// sort set, from set[start] through set[end].   *
//************************************************

void quickSort(int set[], int start, int end)
{
   int pivotPoint;

   if (start < end)
   {
      // Get the pivot point.
      pivotPoint = partition(set, start, end);
      // Sort the first sub list.
      quickSort(set, start, pivotPoint - 1);
      // Sort the second sub list.
      quickSort(set, pivotPoint + 1, end);
   }

   for (int count = 0; count < 10; count++)
	   cout << set[count] << " ";
   cout << endl;
}

//**********************************************************
// partition selects the value in the middle of the        *
// array set as the pivot. The list is rearranged so       *
// all the values less than the pivot are on its left      *
// and all the values greater than pivot are on its right. *
//**********************************************************

int partition(int set[], int start, int end)
{
   int pivotValue, pivotIndex, mid;

   mid = (start + end) / 2;
   swap(set[start], set[mid]);
   pivotIndex = start;
   pivotValue = set[start];
   for (int scan = start + 1; scan <= end; scan++)
   {
      if (set[scan] < pivotValue)
      {
         pivotIndex++;
         swap(set[pivotIndex], set[scan]);
      }
   }
   swap(set[start], set[pivotIndex]);
   return pivotIndex;
}

//**********************************************
// swap simply exchanges the contents of       *
// value1 and value2.                          *
//**********************************************

void swap(int &value1, int &value2)
{
   int temp = value1;

   value1 = value2;
   value2 = temp;
}

/*
Orginal Array
7 3 9 2 0 1 8 4 6 5

Table of value
0 3 9 2 7 1 8 4 6 5
0 1 9 2 7 3 8 4 6 5
0 1 2 3 7 9 8 4 6 5
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9

Sorted Array
0 1 2 3 4 5 6 7 8 9
Press any key to continue . . .



----------Even Numbers-------------

Orginal Array
20 8 4 42 6 12 10 14 24 2

Table of value
2 4 6 42 20 12 10 14 24 8
2 4 6 42 20 12 10 14 24 8
2 4 6 42 20 12 10 14 24 8
2 4 6 8 10 12 42 14 24 20
2 4 6 8 10 12 14 42 24 20
2 4 6 8 10 12 14 20 24 42
2 4 6 8 10 12 14 20 24 42
2 4 6 8 10 12 14 20 24 42
2 4 6 8 10 12 14 20 24 42
2 4 6 8 10 12 14 20 24 42
2 4 6 8 10 12 14 20 24 42

Sorted Array
2 4 6 8 10 12 14 20 24 42
Press any key to continue . . .



------------Odd Numbers------------

Orginal Array
19 7 73 41 5 11 9 13 3 0

Table of value
0 3 5 41 19 11 9 13 7 73
0 3 5 41 19 11 9 13 7 73
0 3 5 41 19 11 9 13 7 73
0 3 5 7 9 11 41 13 19 73
0 3 5 7 9 11 13 41 19 73
0 3 5 7 9 11 13 19 41 73
0 3 5 7 9 11 13 19 41 73
0 3 5 7 9 11 13 19 41 73
0 3 5 7 9 11 13 19 41 73
0 3 5 7 9 11 13 19 41 73
0 3 5 7 9 11 13 19 41 73
0 3 5 7 9 11 13 19 41 73
0 3 5 7 9 11 13 19 41 73

Sorted Array
0 3 5 7 9 11 13 19 41 73
Press any key to continue . . .
*/