/********************************************************
 * Author       : Flavio Sovilla                        *
 * Date         : 08.04.2020                            *
 * Title        : binSearch.cpp                         *
 * Description  : This program will find a number with  *
 *                the binary search method              *
********************************************************/
#include <iostream>

using namespace std;

//The binary research function
bool binarySearch(int nbSearched, int amount, int mat[]);

//The binary research function
bool binarySearch(int nbSearched, int amount, int mat[])
{

    return false;
}

int main()
{    
    //The array where we will search the number (It has to be sorted)
    int mat[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    //Amount of numbers in the array
    int amount = sizeof(mat) / sizeof(mat[0]);

    //The nummber searched
    int nbSearched = 38;

    if(binarySearch(nbSearched, amount, mat))
    {
        cout << "The number has been found !";
    }
    else
    {
        cout << "The number is not in the array.";
    }
    
}