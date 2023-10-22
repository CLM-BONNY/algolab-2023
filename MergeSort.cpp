#include <iostream>
#define MAX_SIZE 100

using namespace std;

void merge(int a[], int low, int mid, int high);
void mergeSort(int v[], int low, int high);

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

    mergeSort(a, 0, n - 1);
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

void mergeSort(int v[], int low, int high)
{
  int mid;

  if (low == high)
    return;

  mid = (low + high) / 2;

  mergeSort(v, low, mid);
  mergeSort(v, mid + 1, high);
  merge(v, low, mid, high);
}