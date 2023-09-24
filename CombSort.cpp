#include <iostream>
#include <cmath>

#define MAX_SIZE 1000
void combSort(int a[], int n);

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
    combSort(a, num);

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

/* comb sort 함수 */
void combSort(int a[], int n)
{
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0;  // swap 함수 실행 횟수

  // comb sort 알고리즘 구현
  int gap = n;
  float shrink = 1.3;
  bool sorted = false;

  while (!sorted)
  {
    gap = floor(gap / shrink);
    if (gap <= 1)
    {
      gap = 1;
      sorted = true;
    }

    int i = 0;
    for (int i = 0; i + gap < n; i++)
    {
      countCmpOps++;
      if (a[i] > a[i + gap])
      {
        swap(a[i], a[i + gap]);
        countSwaps++;
        sorted = false;
      }
    }
  }

  cout << countCmpOps << " " << countSwaps;
}