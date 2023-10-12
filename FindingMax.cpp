#include <iostream>

#define MAX_SIZE 100

int findingMax(int a[], int left, int right);

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

    cout << findingMax(a, 0, n - 1) << endl;
  }
}

int findingMax(int a[], int left, int right)
{
  int half;

  if (left == right)
    return a[left];
  else
  {
    half = (left + right) / 2;
    return max(findingMax(a, left, half), findingMax(a, half + 1, right));
  }
}
