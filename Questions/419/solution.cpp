/*
Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
 */

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
      int count = 0;
      vector<int> shipsX;
      vector<int> shipsY;
      for(int x=0; x<board.size(); x++)
        {
          for(int y=0; y<board[x].size(); y++)
            {
              //found a part of a ship
              if(board[x][y] == 'X')
                {
                  //Find topmost leftmost point of the ship
                  int xx = x-1;
                  int yy = y-1;

                  bool foundPoint = true;
                  do {
                    foundPoint = true;

                    if(xx >= 0)
                      {
                        if(board[xx][y] == 'X')//x direction
                          {
                            xx--;
                            foundPoint = false;
                          }
                      }
                    if(yy >= 0)
                      {
                        if(board[x][yy] == 'X' && foundPoint)//y direction
                          {
                            yy--;
                            foundPoint = false;
                          }
                      }

                  } while (!foundPoint);

                  //make sure we haven't found this ship already
                  bool contains = false;
                  for(int i=0; i<shipsX.size(); i++)
                    {
                      if(shipsX[i] == xx && shipsY[i] == yy)
                        {
                          contains = true;
                        }
                    }
                  if(!contains)
                    {
                      cout << xx << yy;
                      shipsX.push_back(xx);
                      shipsY.push_back(yy);
                      count++;
                    }
                }
            }
        }
      return count;
    }
};
