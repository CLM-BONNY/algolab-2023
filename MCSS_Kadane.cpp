#include <iostream>

#define MAX_SIZE 100
void maxSubsequenceSumKadane(int a[], int n);

using namespace std;

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    int a[MAX_SIZE];

    cin >> n;
    for (int j = 0; j < n; j++)
      cin >> a[j];

    maxSubsequenceSumKadane(a, n);
  }
}

void maxSubsequenceSumKadane(int a[], int n)
{
  int i, j;
  int maxSum = 0, thisSum = 0;

  int start = -1, end = -1;

  for (i = 0, j = 0; j < n; j++)
  {
    thisSum += a[j];

    if (thisSum > maxSum)
    {
      maxSum = thisSum;                                                                                                               
      start = i;
      end = j;

      if (a[i] == 0)
      {
        start += 1;
      }
    }
    else if (thisSum < 0)
    {
      i = j + 1;
      thisSum = 0;
    }
  }
  cout << maxSum << " " << start << " " << end << endl;
}
