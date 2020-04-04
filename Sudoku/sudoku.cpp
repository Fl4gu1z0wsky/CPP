#include <iostream>

bool solving(int grid[9][9]);

bool rowColBox(int posX, int posY, int grid[9][9]);

bool solving(int grid[9][9])
{
    int posX = 0;
    int posY = 0;
    bool isEmpty = false;
    for (int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            //Check if there is an empty case
            if (grid[i][j] == 0)
            {
                posX = i;
                posY = j;
                isEmpty = true;
                break;
            }  
        }
        if (isEmpty)
        {
            std::cout << posX << " : " << posY << "\n";
            break;
        }
    }
}

bool rowColBox(int posX, int posY, int grid[9][9])
{
    int number = 1;
    int isUsed = false;
    //Check if the number is assigned

    //Row
    for (int i = 0; i < 9; i++)
    {
        if(grid[posX][i] == number)
        {
            isUsed = true;
        }
        if(isUsed)
        {
            break;
        }
    }

    //Column
    for (int i = 0; i < 9; i++)
    {
        if(grid[i][posY] == number)
        {
            isUsed = true;
        }
        if(isUsed)
        {
            break;
        }
    }

    //Box
    
}

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

    solving(mat);
}
