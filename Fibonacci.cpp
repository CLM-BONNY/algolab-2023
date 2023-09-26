#include <iostream>

int fibonacci(int num);

using namespace std;

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
  }

  return 0;
}

int fibonacci(int n)
{
  if (n <= 1) return n;
  else return fibonacci(n-1) + fibonacci(n-2);
}