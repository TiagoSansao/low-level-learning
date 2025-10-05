#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

struct Square
{
  unsigned row;
  unsigned col;
  Square(unsigned r, unsigned c)
  {
    row = r;
    col = c;
  }
};
class ChessBoard
{
private:
  int board[8][8] = {
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0};
  unsigned int _sz = 8;

public:
  unsigned int size() const
  {
    return _sz;
  }
  int *operator[](unsigned i)
  {
    /* Enables the use of [] operator for ChessBoard objects */
    return board[i];
  }
  void fill(int value)
  {
    /* Fills all the board with a specific value */
    for (unsigned i = 0; i < size(); ++i)
    {
      for (unsigned j = 0; j < size(); ++j)
      {
        board[i][j] = value;
      }
    }
  }
};

std::ostream &operator<<(std ::ostream &out, ChessBoard &board)
{
  /* Enables the use of std :: cout << board
   * to print the board . May be used for debugging .
   */
  for (auto i = 0u; i < board.size(); ++i)
  {
    for (auto j = 0u; j < board.size(); ++j)
    {
      out << board[i][j] << ' ';
    }
    out << '\n';
  }
  return out;
}

bool square_valid(const Square &s, const ChessBoard &board)
{
  unsigned n = board.size();
  return s.row < n and s.col < n;
  // Since we are using unsigned for the squares , there is no need to check
  // whether values are >= 0.
}

unsigned get_knight_path_length(const Square &origin, const Square &dest)
{
  ChessBoard board;
  board.fill(0);

  std::pair<int, int> knightMovesArray[8] = {{1, -2}, {2, -1}, {1, 2}, {2, 1}, {-2, 1}, {-1, +2}, {-2, -1}, {-1, -2}};

  std::queue<Square> queue;
  queue.push(origin);

  while (!queue.empty())
  {
    Square curSquare = queue.front();
    queue.pop();

    for (std::pair<int, int> knightMoves : knightMovesArray)
    {
      auto [row, col] = knightMoves;
      Square newSquare = Square(curSquare.row + row, curSquare.col + col);
      if (not square_valid(newSquare, board) || board[newSquare.row][newSquare.col] != 0)
        continue;

      board[newSquare.row][newSquare.col] = board[curSquare.row][curSquare.col] + 1;

      if (newSquare.row == dest.row && newSquare.col == dest.col)
        return board[newSquare.row][newSquare.col];

      queue.push(newSquare);
    }
  }

  return -1;
}

int main(void)
{
  // Used to map the squares as char to indices of the board
  std::unordered_map<char, unsigned> table = {
      {'a', 0},
      {'b', 1},
      {'c', 2},
      {'d', 3},
      {'e', 4},
      {'f', 5},
      {'g', 6},
      {'h', 7}};
  char icol, ocol;
  unsigned irow, orow;
  std ::cin >> icol >> irow;
  std ::cin.ignore(1); // Skip the '\n' char at the input ;
  std ::cin >> ocol >> orow;
  Square origin(irow - 1, table[icol]);
  Square dest(orow - 1, table[ocol]);
  unsigned nmoves = get_knight_path_length(origin, dest);
  std ::cout << "Movimentos: " << nmoves << '\n';
  return 0;
}