#include <iostream>
#define MAX_SIZE 1001

using namespace std;

void swap(int *a, int *b);
int partitionHoare(int a[], int low, int high);
int partitionRomuto(int a[], int low, int high);
void quickSortHoare(int a[], int low, int high);
void quickSortRomuto(int a[], int low, int high);

int countSwapsHoare = 0;
int countCmpOpsHoare = 0;
int countSwapsRomuto = 0;
int countCmpOpsRomuto = 0;

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    int a[MAX_SIZE];
    int b[MAX_SIZE];

    countSwapsHoare = 0;
    countCmpOpsHoare = 0;
    countSwapsRomuto = 0;
    countCmpOpsRomuto = 0;

    cin >> n;
    for (int j = 0; j < n; j++)
    {
      int k;
      cin >> k;

      a[j] = k;
      b[j] = k;
    }

    quickSortHoare(a, 0, n - 1);
    quickSortRomuto(b, 0, n - 1);

    cout << countSwapsHoare << " " << countSwapsRomuto << " " << countCmpOpsHoare << " " << countCmpOpsRomuto << endl;
  }

  return 0;
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partitionHoare(int a[], int low, int high)
{
  int i, j;
  int pivot;

  pivot = a[low];

  i = low - 1;
  j = high + 1;

  while (true)
  {
    do
    {
      i++;
      countCmpOpsHoare++;
    } while (a[i] < pivot);

    do
    {
      j--;
      countCmpOpsHoare++;
    } while (a[j] > pivot);

    if (i < j)
    {
      swap(a[i], a[j]);
      countSwapsHoare++;
    }
    else
      return j;
  }
}

int partitionRomuto(int a[], int low, int high)
{
  int i, j;
  int pivot, pivotPos;

  pivot = a[low];
  j = low;

  for (i = low + 1; i <= high; i++)
  {
    countCmpOpsRomuto++;
    if (a[i] < pivot)
    {
      j++;
      swap(a[i], a[j]);
      countSwapsRomuto++;
    }
  }

  pivotPos = j;
  swap(a[low], a[pivotPos]);
  countSwapsRomuto++;

  return pivotPos;
}

void quickSortHoare(int a[], int low, int high)
{
  if (low >= high)
    return;

  int p = partitionHoare(a, low, high);
  quickSortHoare(a, low, p);
  quickSortHoare(a, p + 1, high);
}

void quickSortRomuto(int a[], int low, int high)
{
  if (low >= high)
    return;

  int p = partitionRomuto(a, low, high);
  quickSortRomuto(a, low, p - 1);
  quickSortRomuto(a, p + 1, high);
}
