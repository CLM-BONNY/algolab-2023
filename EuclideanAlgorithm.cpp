#include <iostream>

using namespace std;

int gcd(int a, int b);

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
  }

  return 0;
}

int gcd(int a, int b)
{
  if (b == 0) return a;
  else return gcd(b, a % b);
}