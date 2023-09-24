#include <iostream>

#define MAX_SIZE 1000
void insertionSort(int a[], int n);

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

    insertionSort(a, num);

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

/* Insertion Sort 함수 */
void insertionSort(int a[], int n)
{
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0;  // swap 함수 실행 횟수
  // insertion sort 알고리즘 구현
  for (int i = 1; i < n; i++)
  {
    countCmpOps++;
    for (int j = i; j > 0 && a[j - 1] > a[j];)
    {
      countCmpOps++;
      swap(a[j - 1], a[j]);
      countSwaps++;
      j--;
      if (j <= 0)
        countCmpOps--;
    }
  }
  cout << countCmpOps << " " << countSwaps;
}