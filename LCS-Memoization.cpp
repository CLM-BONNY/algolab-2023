#include <iostream>
#include <cstring>

#define MAXSIZE 100

using namespace std;

int memo[MAXSIZE][MAXSIZE];
int lengthLCS(string X, string Y, int m, int n);

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    string X, Y;
    cin >> X >> Y;

    int m = X.length();
    int n = Y.length();

    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++)
        memo[i][j] = -1;

    cout << lengthLCS(X, Y, m, n) << endl;
  }
}

int lengthLCS(string X, string Y, int m, int n)
{
  if (m == 0 || n == 0)
    return 0;

  if (memo[m - 1][n - 1] != -1)
    return memo[m - 1][n - 1];

  if (X[m - 1] == Y[n - 1])
  {
    memo[m - 1][n - 1] = 1 + lengthLCS(X, Y, m - 1, n - 1);

    return memo[m - 1][n - 1];
  }

  else
  {
    memo[m - 1][n - 1] = max(lengthLCS(X, Y, m, n - 1), lengthLCS(X, Y, m - 1, n));

    return memo[m - 1][n - 1];
  }
}
