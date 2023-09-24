#include <iostream>

#define MAX_SIZE 1000
void selectionSort(int a[], int n);

using namespace std;

int main()
{
  int numTestCases;

  cin >> numTestCases;
  for (int i = 0; i < numTestCases; ++i)
  {
    int num;
    int a[MAX_SIZE];

    cin >> num;
    for (int j = 0; j < num; j++)
      cin >> a[j];

    selectionSort(a, num);

    cout << endl;
  }
  return 0;
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/* Selection Sort 함수 */
void selectionSort(int a[], int n)
{
  int sMin;
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0;  // swap 함수 실행 횟수

  // selection sort 알고리즘 구현
  for (int i = 0; i < n - 1; i++)
  {
    sMin = i;

    for (int j = i + 1; j < n; j++)
    {
      countCmpOps++;
      if (a[j] < a[sMin])
        sMin = j;
    }

    if (sMin != i)
    {
      swap(a[sMin], a[i]);
      countSwaps++;
    }
  }

  cout << countCmpOps << " " << countSwaps;
}