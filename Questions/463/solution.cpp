/*
  You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

  [[0,1,0,0],
  [1,1,1,0],
  [0,1,0,0],
  [1,1,0,0]]

  Answer: 16
  Explanation: The perimeter is the 16 yellow stripes in the image below:
*/

class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int xSize = grid.size();
    int ySize = grid[xSize-1].size();

    int result = 0;
    int surroundingTiles = 4;
    int top = 0; int bot = 0; int left = 0; int right = 0;
    for(int x=0; x<xSize; x++)
      {
        for(int y=0; y<ySize; y++)
          {
            if(grid[x][y] == 1)
              {
                if(y<ySize-1)
                  top = grid[x][y+1];
                if(y>0)
                  bot = grid[x][y-1];
                if(x>0)
                  left = grid[x-1][y];
                if(x<xSize-1)
                   right = grid[x+1][y];

                result += (surroundingTiles - top - bot - left - right);
              }
            top = 0; bot = 0; left = 0; right = 0;
          }
      }
    return result;
  }
};
