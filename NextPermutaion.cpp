#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string nextPermutation(int n, string s);

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    string s;
    cin >> n >> s;

    cout << nextPermutation(n, s) << endl;
  }
}

string nextPermutation(int n, string s)
{
  int i = n - 1;

  while (i >= 1 && s[i - 1] >= s[i])
    i -= 1;

  if (i == 0)
  {
    reverse(s.begin(), s.end());
    return s;
  }

  int j = n - 1;

  while (s[j] < s[i - 1])
    j -= 1;

  swap(s[i - 1], s[j]);

  j = n;

  reverse(s.begin() + i, s.begin() + j);

  return s;
}