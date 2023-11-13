
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int lengthLCS(string X, string Y, int m, int n);

int main()
{
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; ++i)
  {
    string X, Y;
    cin >> X >> Y;

    int m = X.length();
    int n = Y.length();

    cout << lengthLCS(X, Y, m, n) << endl;
  }
  return 0;
}

int lengthLCS(string X, string Y, int m, int n)
{
  if (m == 0 || n == 0)
    return 0;
  if (X[m - 1] == Y[n - 1])
    return lengthLCS(X, Y, m - 1, n - 1) + 1;
  else
    return max(lengthLCS(X, Y, m, n - 1), lengthLCS(X, Y, m - 1, n));
}
