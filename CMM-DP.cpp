#include <iostream>
#define MAX_SIZE 100

using namespace std;

int P[MAX_SIZE][MAX_SIZE];
int M[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE];

void order(int i, int j);
void minmult(int n);

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    cin >> n;

    for (int i = 0; i < n + 1; i++)
    {
      cin >> d[i];
    }

    minmult(n + 1);
  }
  return 0;
}

void order(int i, int j)
{
  if (i == j)
    cout << "M" << i;
  else
  {
    int k = P[i][j];
    cout << "(";
    order(i, k);
    order(k + 1, j);
    cout << ")";
  }
}

void minmult(int n)
{
  for (int i = 1; i <= n; i++)
    M[i][i] = 0;

  for (int diagonal = 1; diagonal <= n - 1; diagonal++)
  {
    for (int i = 1; i <= n - diagonal; i++)
    {
      int j = i + diagonal;
      M[i][j] = __INT_MAX__;

      for (int k = i; k <= j - 1; k++)
      {
        int tmp = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];

        if (tmp < M[i][j])
        {
          M[i][j] = tmp;
          P[i][j] = k;
        }
      }
    }
  }

  order(1, n - 1);
  cout << endl;
  cout << M[1][n - 1] << endl;
}