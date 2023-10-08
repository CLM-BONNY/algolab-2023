#include <iostream>
#include <cmath>

void hanoiTower(int n, int a, int b, int c, unsigned long long int k);

using namespace std;

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    unsigned long long int k;
    cin >> n >> k;

    hanoiTower(n, 1, 2, 3, k);
  }

  return 0;
}

void hanoiTower(int n, int a, int b, int c, unsigned long long int k)
{
  unsigned long long int middle = pow(2, n - 1);

  if (n == 1)
  {
    cout << a << " " << c << endl;
    return;
  }
  else
  {
    if (k < middle)
    {
      hanoiTower(n - 1, a, c, b, k);
    }
    else if (k > middle)
    {
      hanoiTower(n - 1, b, a, c, k - middle);
    }
    else if (k == middle)
    {
      cout << a << " " << c << endl;
    }
  }
}
