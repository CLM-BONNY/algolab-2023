#include <iostream>

#define MAX_SIZE 100

using namespace std;

int maxSubsequenceSumDNC(int a[], int left, int right);

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

    cout << maxSubsequenceSumDNC(a, 0, n - 1) << endl;
  }
}

int maxSubsequenceSumDNC(int a[], int left, int right)
{
  int maxSum = 0, leftThisSum = 0, leftMaxSum = 0, rightThisSum = 0, rightMaxSum = 0;

  if (left == right)
    return a[left];
  else
  {
    int mid = (left + right) / 2;

    for (int i = mid; i >= left; i--)
    {
      leftThisSum += a[i];

      if (leftThisSum > leftMaxSum)
        leftMaxSum = leftThisSum;
    }

    for (int j = mid + 1; j <= right; j++)
    {
      rightThisSum += a[j];

      if (rightThisSum > rightMaxSum)
        rightMaxSum = rightThisSum;
    }

    int midContain = leftMaxSum + rightMaxSum;

    maxSum = max(max(maxSubsequenceSumDNC(a, left, mid), maxSubsequenceSumDNC(a, mid + 1, right)), midContain);

    return maxSum;
  }
}