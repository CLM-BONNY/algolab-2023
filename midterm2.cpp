#include <iostream>
#define MAX_SIZE 1000

using namespace std;

int getLongestIncreasingSubsequenceLength(int a[], int k);

int main()
{
  int n;
  cin >> n;

  while (n--)
  {
    int k;
    cin >> k;

    int a[MAX_SIZE];
    for (int i = 0; i < k; i++)
    {
      cin >> a[i];
    }

    cout << getLongestIncreasingSubsequenceLength(a, k) << endl;
  }

  return 0;
}

int getLongestIncreasingSubsequenceLength(int a[], int k)
{
  int curperLen = 1;
  int maxLen = 1;

  for (int j = 1; j < k; j++)
  {
    if (a[j] >= a[j - 1])
    {
      curperLen++;
    }
    else
    {
      maxLen = max(maxLen, curperLen);
      curperLen = 1;
    }
  }

  maxLen = max(maxLen, curperLen);
  return maxLen;
}