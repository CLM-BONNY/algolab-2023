#include <iostream>
#define MAX_SIZE 100

using namespace std;

void merge(int a[], int low, int mid, int high);
void mergeSortIterative(int v[], int n);

int countCmpOps = 0;

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

    mergeSortIterative(a, n);
    cout << countCmpOps << endl;
    countCmpOps = 0;
  }

  return 0;
}

void merge(int a[], int low, int mid, int high)
{
  int i, j, k;
  int tmp[MAX_SIZE];

  for (i = low; i <= high; i++)
    tmp[i] = a[i];

  i = k = low;
  j = mid + 1;

  while (i <= mid && j <= high)
  {
    countCmpOps++;

    if (tmp[i] <= tmp[j])
      a[k++] = tmp[i++];
    else
      a[k++] = tmp[j++];
  }

  while (i <= mid)
    a[k++] = tmp[i++];
  while (j <= high)
    a[k++] = tmp[j++];
}

void mergeSortIterative(int v[], int n)
{
  int size = 1;

  while (size < n)
  {
    for (int i = 0; i < n; i += 2 * size)
    {
      int low = i;
      int mid = low + size - 1;
      int high = min(i + 2 * size - 1, n - 1);

      if (mid >= n - 1)
      {
        break;
      }

      merge(v, low, mid, high);
    }
    size *= 2;
  }
}