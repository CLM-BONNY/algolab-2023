#include <iostream>

int fastPower(int a, int n);

using namespace std;

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int x, n;
    cin >> x >> n;
    cout << fastPower(x, n) << endl;
  }

  return 0;
}

int fastPower(int a, int n)
{
  int b;

  if (n == 0) return 1;
  else if (n % 2 == 1)
  {
    b = fastPower(a, (n - 1) / 2);
    int tmp = a * b * b;
    return tmp % 1000;
  }
  else
  {
    b = fastPower(a, n / 2);
    int tmp = b * b;
    return tmp % 1000;
  }
}