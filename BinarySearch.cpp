#include <iostream>

#define MAX_SIZE 100

int binarySearch(int a[], int left, int right, int value);

using namespace std;

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n, k;
    int a[MAX_SIZE];

    cin >> n >> k;
    for (int j = 0; j < n; j++)
      cin >> a[j];

    cout << binarySearch(a, 0, n, k) << endl;
  }
}

int binarySearch(int a[], int left, int right, int value)
{
  int mid;

  if (left > right)
    return -1;
  else
  {
    mid = (left + right) / 2;

    if (a[mid] == value)
      return mid;
    else if (a[mid] > value)
      return binarySearch(a, left, mid - 1, value);
    else
      return binarySearch(a, mid + 1, right, value);
  }
}
