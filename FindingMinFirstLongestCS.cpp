#include <iostream>

#define MAX_SIZE 1000

using namespace std;

int findingMinFirstLongestCS(int a[], int n);

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

    cout << findingMinFirstLongestCS(a, n) << endl;
  }
}

int findingMinFirstLongestCS(int a[], int n)
{
  int minValue = a[0];
  int Slength = 0;
  int answer = 1;

  for (int i = 0; i < n; i++)
  {
    Slength += 1;

    if (a[i] < minValue)
    {
      if (answer < Slength - 1)
        answer = Slength - 1;

      minValue = a[i];
      Slength = 1;
    }

    if (i == n - 1)
      if (answer < Slength)
        answer = Slength;
  }

  return answer;
}