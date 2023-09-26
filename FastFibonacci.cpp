#include <iostream>

int fastFibonacci(int n);
void multiply(int a[2][2], int b[2][2]);
void calculation(int a[2][2], int n);

using namespace std;

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    cin >> n;
    cout << fastFibonacci(n) << endl;
  }

  return 0;
}

void multiply(int a[2][2], int b[2][2])
{
  int w = a[0][0] * b[0][0] + a[0][1] * b[1][0];
  int x = a[0][0] * b[0][1] + a[0][1] * b[1][1];
  int y = a[1][0] * b[0][0] + a[1][1] * b[1][0];
  int z = a[1][0] * b[0][1] + a[1][1] * b[1][1];

  a[0][0] = w % 1000;
  a[0][1] = x % 1000;
  a[1][0] = y % 1000;
  a[1][1] = z % 1000;
}

void calculation(int a[2][2], int n)
{
  if (n <= 1) return;

  int b[2][2] = {{1, 1}, {1, 0}};

  calculation(a, n / 2);
  multiply(a, a);

  if (n % 2 != 0) multiply(a, b);
}

int fastFibonacci(int n)
{
  if (n == 0) return 0;
  else
  {
    int a[2][2] = {{1, 1}, {1, 0}};
    calculation(a, n - 1);

    return a[0][0];
  }
}