#include <iostream>
#include <cstdlib>

using namespace std;

int randRow();
int randCol();
void printGrid();
bool checkBattleship(int, int);
void placeBattleship(int, int);
bool checkCruiser(int, int);
void placeCruiser(int, int);
bool checkCargo(int, int);
void placeCargo(int, int);
bool checkSub(int, int);
void placeSub(int, int);

char** grid;
int i = 0;
int j = 0;
const int rowCount = 8;
const int colCount = 8;


int main()
{

  int row;
  int col;
  int battleshipChecked;
  int battleshipsPlaced = 0;
  int cruisersPlaced = 0;
  int cargosPlaced = 0;
  int subsPlaced = 0;

  //Making the grid
  grid = new char*[rowCount];
  while(i != rowCount)
  {
    //makes ptrs to arrays of size colCount and points to with ptr called line
    char* line = new char[colCount];
    //in every cell of the grid, makes it point to a line
    grid[i] = line;
    i= i +1;
  }

  //Filling
  for(i=0; i < rowCount; ++i)
  {
    for(int j= 0; j < colCount; ++j)
    {
      grid[i][j] = '~';
    }
  }

  for(i=0; i < 101; i++)
  {
    //Makes sure only 1 is placed
    while(battleshipsPlaced < 1)
    {
      row = randRow();
      col = randCol();
      if(checkBattleship(row,col))
      {
        placeBattleship(row, col);
        battleshipsPlaced++;
      }
    }

    while(cruisersPlaced < 2)
    {
      row = randRow();
      col = randCol();
      if(checkCruiser(row,col))
      {
        placeCruiser(row, col);
        cruisersPlaced++;
      }
    }

    while(cargosPlaced < 5)
    {
      row = randRow();
      col = randCol();
      if(checkCargo(row,col))
      {
        placeCargo(row, col);
        cargosPlaced++;
      }
    }

    while(subsPlaced < 10)
    {
      row = randRow();
      col = randCol();
      if(checkSub(row,col))
      {
        placeSub(row, col);
        subsPlaced++;
      }
    }

    printGrid();
    //Reseting the board
    for(int j=0; j < rowCount; ++j)
    {
      for(int k= 0; k < colCount; ++k)
      {
        grid[j][k] = '~';
      }
    }
    //Reseting the ships
    cruisersPlaced = 0;
    battleshipsPlaced = 0;
    cargosPlaced = 0;
    subsPlaced= 0;
  }

  for(i = 0; i <= rowCount; i++)
  {
    delete grid[i];
  }
  delete[] grid;

  return 0;
}


int randRow()
{
  int row = rand() % 8;
  return row;
}

int randCol()
{
  int col = rand() % 8;
  return col;
}

void printGrid()
{
  cout << endl;
  for(int j=0;j<rowCount; ++j)
  {
    for(int k=0;k<colCount;++k)
    {
      cout << grid[j][k] << " ";
    }
    cout << endl;
  }
}

bool checkBattleship(int row, int col)
{
  //int row = randRow();
  //int col = randCol();
  //Notice indices on piece and checkCount. Could be wrong
  int checkCount = 0;
  for(int piece = 1; piece <= 4; piece++)
  {
    if((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
    {
      if(grid[row][col] == '~')
      {
        checkCount++;
        row++;
      }
      else
      {
        return false;
      }
    }
    else
    {
        return false;
    }
  }

  if(checkCount == 4)
  {
    return true;
  }

}

//Changes the grid. Therefore void type
void placeBattleship(int row, int col)
{
  for(int piece = 1; piece <= 4; piece++)
  {
    grid[row][col] = 'B';
    row++;
  }
}

bool checkCruiser(int row, int col)
{
  //int row = randRow();
  //int col = randCol();
  //Notice indices on piece and checkCount. Could be wrong
  int checkCount = 0;
  for(int piece = 1; piece <= 3; piece++)
  {
    if((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
    {
      if(grid[row][col] == '~')
      {
        checkCount++;
        row++;
      }
      else
      {
        return false;
      }
    }
    else
    {
        return false;
    }
  }

  if(checkCount == 3)
  {
    return true;
  }

}

//Changes the grid. Therefore void type
void placeCruiser(int row, int col)
{
  for(int piece = 1; piece <= 3; piece++)
  {
    grid[row][col] = 'C';
    row++;
  }
}

bool checkCargo(int row, int col)
{
  int checkCount = 0;
  for(int piece = 1; piece <= 2; piece++)
  {
    if((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
    {
      if(grid[row][col] == '~')
      {
        checkCount++;
        row++;
      }
      else
      {
        return false;
      }
    }
    else
    {
        return false;
    }
  }

  if(checkCount == 2)
  {
    return true;
  }

}

//Changes the grid. Therefore void type
void placeCargo(int row, int col)
{
  for(int piece = 1; piece <= 2; piece++)
  {
    grid[row][col] = 'S';
    row++;
  }
}

bool checkSub(int row, int col)
{
  int checkCount = 0;
  for(int piece = 1; piece <= 1; piece++)
  {
    if((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
    {
      if(grid[row][col] == '~')
      {
        checkCount++;
        row++;
      }
      else
      {
        return false;
      }
    }
    else
    {
        return false;
    }
  }

  if(checkCount == 1)
  {
    return true;
  }

}

//Changes the grid. Therefore void type
void placeSub(int row, int col)
{
  for(int piece = 1; piece <= 1; piece++)
  {
    grid[row][col] = 'H';
    row++;
  }
}
