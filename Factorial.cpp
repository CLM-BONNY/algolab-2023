#include <iostream>

int factorial(int n);

using namespace std;

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    cin >> n;
    cout << factorial(n) % 1000 << endl;
  }

  return 0;
}

int factorial(int n)
{
  if (n <= 1) return 1;
  else
  {
    int tmp = n * factorial(n - 1);
    while (tmp % 10 == 0)
    {
      tmp = tmp / 10;
    }
    return tmp % 10000;
  }
}