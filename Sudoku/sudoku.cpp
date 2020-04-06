/********************************************************
 * Author       : Flavio Sovilla                        *
 * Date         : 06.04.2020                            *
 * Title        : sudoku.cpp                            *
 * Description  : This program will help soving a       *
 *                sudoku with backtracking              *
********************************************************/

#include <iostream>

//Function to solve the sudoku
bool solveEverything(int grid[9][9]);

//Function to find a free case
bool emptyCase(int& posX, int& posY, int grid[9][9]);

//Function to see if everything is free
bool isItCorrect(int posX, int posY, int grid[9][9], int number);

//Function to see if a row is free
bool isRowFree(int posX, int grid[9][9], int number);

//Function to see if a column is free
bool isColFree(int posY, int grid[9][9], int number);

//Function to see if a box is free
bool isBoxFree(int posX, int posY, int grid[9][9], int number);

//Function to solve the sudoku
bool solveEverything(int grid[9][9])
{
    int posX, posY;

    //We check if a case is empty (= 0)
    if(!emptyCase(posX, posY, grid))
    {
        //If not it's solved
        return true;
    }

    //We check for every number possible (1 - 9)
    for(int number = 1; number < 10; number++)
    {
        //Check the row, the column and the box
        if(isItCorrect(posX, posY, grid, number))
        {
            //If it's free, we add the number
            grid[posX][posY] = number;
            //And we use again the function to check the other cases
            if(solveEverything(grid))
            {
                return true;
            }
            //We put again the number if it doesn't match
            grid[posX][posY] = 0;
        }
    }
    return false;
}

//Function to find a free case
bool emptyCase(int &posX, int &posY, int grid[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            //Check if there is an empty case (= 0)
            if(grid[i][j] == 0)
            {
                posX = i;
                posY = j;
                return true;
            }
        }
    }
    return false;
}

//Function to see if everything is free
bool isItCorrect(int posX, int posY, int grid[9][9], int number)
{
    if(isRowFree(posX, grid, number) && isColFree(posY, grid, number) &&
    isBoxFree(posX, posY, grid, number))
    {
        return true;
    }
    return false;
}

//Function to see if a row is free
bool isRowFree(int posX, int grid[9][9], int number)
{
    for(int i = 0; i < 9; i++)
    {
        if(grid[posX][i] == number)
        {
            return false;
        }
    }
    return true;
}

//Function to see if a column is free
bool isColFree(int posY, int grid[9][9], int number)
{
    for(int i = 0; i < 9; i++)
    {
        if(grid[i][posY] == number)
        {
            return false;
        }
    }
    return true;
}

//Function to see if a box is free
bool isBoxFree(int posX, int posY, int grid[9][9], int number)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            //We use modulo to find the start of the box and we check the 9 cases
            if(grid[(posX - (posX % 3)) + i][(posY - (posY % 3)) + j] == number)
            {
                return false;
            }
        }
    }
    return true;
}

//Main function
int main() {

    //Initial matrice
    int mat[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                      { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                      { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                      { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                      { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                      { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                      { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                      { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                      { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    //If we have a solution
    if(solveEverything(mat))
    {
        //We print the grid
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                std::cout << mat[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    else
    {
        //There is no solution
        std::cout << "There is no solution !\n";
    }
}
