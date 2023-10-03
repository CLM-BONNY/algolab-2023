#include <iostream>

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0
typedef struct Point
{
  int x, y;
} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];
int knightTour(int m, int n, point pos, int counter);

using namespace std;
int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int m, n, s, t;
    int counter = 1;
    point start;

    cin >> m >> n >> s >> t;
    start.y = s;
    start.x = t;

    for (int j = 1; j <= m; j++)
      for (int k = 1; k <= n; k++)
        board[j][k] = UNMARK;

    board[start.y][start.x] = MARK;
    path[start.y][start.x] = 1;

    if (knightTour(m, n, start, counter))
    {
      cout << 1 << '\n';
      for (int a = 1; a <= m; a++)
      {
        for (int b = 1; b <= n; b++)
        {
          cout << path[a][b] << " ";
        }
        cout << '\n';
      }
    }
    else
    {
      cout << 0 << '\n';
    }
  }

  return 0;
}

int knightTour(int m, int n, point pos, int counter)
{
  point next;

  if (counter == m * n)
    return 1;

  for (int i = 0; i < 8; i++)
  {
    next.x = pos.x + direction[i].x;
    next.y = pos.y + direction[i].y;

    if (next.x > 0 && next.x <= n &&
        next.y > 0 && next.y <= m &&
        board[next.y][next.x] != MARK)
    {
      board[next.y][next.x] = MARK;
      path[next.y][next.x] = counter + 1;
      if (knightTour(m, n, next, counter + 1))
        return 1;
      board[next.y][next.x] = UNMARK;
    }
  }

  return 0;
}
