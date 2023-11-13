#include <iostream>
#define MAX_SIZE 100

using namespace std;

int memo[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE];

int minmult(int *m, int i, int j);
int chainedMatrix(int *m, int n);

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    cin >> n;

    for (int j = 0; j < n + 1; j++)
      cin >> d[j];

    for (int k = 0; k < MAX_SIZE; k++)
      for (int l = 0; l < MAX_SIZE; l++)
        memo[k][l] = -1;

    cout << chainedMatrix(d, n + 1) << endl;
  }
}

int minmult(int *m, int i, int j)
{
  if (i == j)
    return 0;

  if (memo[i][j] != -1)
    return memo[i][j];

  memo[i][j] = __INT_MAX__;

  for (int k = i; k < j; k++)
    memo[i][j] = min(memo[i][j], minmult(m, i, k) + minmult(m, k + 1, j) + m[i - 1] * m[k] * m[j]);

  return memo[i][j];
}

int chainedMatrix(int *m, int n)
{
  int i = 1;
  int j = n - 1;

  return minmult(m, i, j);
}