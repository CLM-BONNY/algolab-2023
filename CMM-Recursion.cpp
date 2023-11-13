#include <iostream>
#define MAX_SIZE 101

using namespace std;

int minmult(int m[], int i, int j);

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    cin >> n;

    int a[MAX_SIZE];
    for (int j = 0; j < n + 1; ++j)
      cin >> a[j];

    cout << minmult(a, 1, n) << endl;
  }
}

int minmult(int m[], int i, int j)
{
  if (i == j)
    return 0;

  int minValue = __INT_MAX__;

  for (int k = i; k < j; k++)
  {
    int tmp = minmult(m, i, k) + minmult(m, k + 1, j) + m[i - 1] * m[k] * m[j];
    if (tmp < minValue)
      minValue = tmp;
  }

  return minValue;
}