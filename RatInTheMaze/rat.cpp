/********************************************************
 * Author       : Flavio Sovilla                        *
 * Date         : 06.04.2020                            *
 * Title        : Rat.cpp                               *
 * Description  : This program will help the rat going  *
 *                through the labyrinth                 *
********************************************************/
#include <iostream>
#include <vector>

using namespace std;

//******INITIAL INPUT*********

//The start and end position
int posX = 0, posY = 4;
int endX = 4, endY = 4;

//Matrice N*N
const int matricN = 5;

//Initial matrice
int mat[matricN][matricN] = { {1, 0, 1, 1, 1 },
                              {1, 1, 1, 0, 0 },
                              {0, 0, 1, 0, 0 },
                              {0, 0, 1, 0, 0 },
                              {1, 1, 1, 1, 1 }};

//****************************

//We stock the path here
vector<char> path;

//Function to guide the rat
bool whereToGo(int posX, int posY, int grid[matricN][matricN]);

//Function to guide the rat
bool whereToGo(int posX, int posY, int grid[matricN][matricN])
{
    char where;
    grid[posX][posY] = 2;

    //We check if it's the final case
    if(posX == endX && posY == endY)
    {
        return true;
    }

    //We move right
    if(grid[posX][posY + 1] == 1)
    {
        if(whereToGo(posX, posY + 1, grid))
        {    
            path.push_back('R');
            return true;
        }
    }
    //We move down
    if(grid[posX + 1][posY] == 1)
    {
        if(whereToGo(posX + 1, posY, grid))
        {      
            path.push_back('D');
            return true;
        }
    }
    //We move left
    if(grid[posX][posY - 1] == 1)
    {
        if(whereToGo(posX, posY - 1, grid))
        {      
            path.push_back('L');
            return true;
        }
    }
    //We move up
    if(grid[posX - 1][posY] == 1)
    {
        if(whereToGo(posX - 1, posY, grid))
        {      
            path.push_back('U');
            return true;
        }
    }
    grid[posX][posY] = 1;
    return false;
}

//The main function
int main()
{   
    //If it exists a path, the rat can eat a cheese, otherwise ...
    if(whereToGo(posX, posY, mat))
    {
        for(int i = (path.size() - 1); i >= 0; i--)
        {
            cout << path[i] <<" ";
        }
        cout << "\nSucceed ! The rat can eat the cheese";
    }
    else
    {
        cout << "\nThe rat died inside ...";
    }   

}