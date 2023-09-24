#include <iostream>

#define MAX_SIZE 1000
void ShellSort(int a[], int n);

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

    ShellSort(a, num);

    cout << endl;
  }

  return 0;
}

/* Shell Sort 함수 */
void ShellSort(int a[], int n)
{
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0;  // swap 함수 실행 횟수

  // Shell sort 알고리즘 구현
  int shrinkRatio = 2;
  int gap = n / shrinkRatio;

  while (gap > 0)
  {
    int tmp, j;
    for (int i = gap; i < n; i++)
    {
      tmp = a[i];
      countCmpOps++;
      for (j = i; (j >= gap) && (a[j - gap] > tmp);)
      {
        countCmpOps++;
        a[j] = a[j - gap];
        countSwaps++;
        j -= gap;
        if (j < gap)
          countCmpOps--;
      }
      a[j] = tmp;
    }
    gap /= shrinkRatio;
  }
  cout << countCmpOps << " " << countSwaps;
}
