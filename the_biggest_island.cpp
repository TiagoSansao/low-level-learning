#include <vector>
#include <string>
#include <iostream>
#include <stack>

void read_input(std::vector<std::vector<char>> &matrix)
{
  std::string line;
  while (std::cin >> line)
  {
    std::vector<char> aux(line.cbegin(), line.cend());
    matrix.push_back(aux);
  }
}

int main()
{
  std::vector<std::vector<char>> matrix;
  read_input(matrix);

  unsigned int biggestIslandSize = 0;
  std::pair<int, int> adjacentSquares[4] = {{0, 1},
                                            {0, -1},
                                            {1, 0},
                                            {-1, 0}};

  for (int i = 0; i < matrix.size(); i += 1)
  {
    for (int j = 0; j < matrix[i].size(); j += 1)
    {
      if (matrix[i][j] == '0')
        continue;

      unsigned int currentIslandSize = 0;
      std::stack<std::pair<int, int>> stack;
      stack.push({i, j});

      while (!stack.empty())
      {
        std::pair<int, int> currentSquare = stack.top();
        stack.pop();

        if (matrix[currentSquare.first][currentSquare.second] == '0')
          continue;

        currentIslandSize++;
        matrix[currentSquare.first][currentSquare.second] = '0';

        for (std::pair<int, int> adjacentSquare : adjacentSquares)
        {
          auto [rowDelta, colDelta] = adjacentSquare;
          std::pair<int, int> newSquare = {currentSquare.first + rowDelta,
                                           currentSquare.second + colDelta};

          if (newSquare.first > matrix.size() - 1 || newSquare.second > matrix[0].size() - 1 || newSquare.first < 0 || newSquare.second < 0)
            continue;

          if (matrix[newSquare.first][newSquare.second] == '0')
            continue;

          stack.push({newSquare.first, newSquare.second});
        }
      }

      if (currentIslandSize > biggestIslandSize)
        biggestIslandSize = currentIslandSize;
    }
  }

  std::cout << biggestIslandSize << '\n';
  return 0;
}
