#include <iostream>
#define MAX_LENGTH 101
using namespace std;

int L[MAX_LENGTH][MAX_LENGTH], S[MAX_LENGTH][MAX_LENGTH];

int lengthLCS(char s[], char t[], int m, int n);
void printLCS(char s[], char t[], int m, int n);

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

    char a[m], b[n];

    for (int j = 0; j < m; j++)
      a[j] = X[j];

    for (int k = 0; k < n; k++)
      b[k] = Y[k];

    cout << lengthLCS(a, b, m, n) << " ";
    printLCS(a, b, m, n);
    cout << endl;
  }
}

int lengthLCS(char s[], char t[], int m, int n)
{
  int i, j;

  for (i = 0; i <= m; i++)
    L[i][0] = 0;

  for (i = 0; i <= n; i++)
    L[0][i] = 0;

  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
    {
      if (s[i - 1] == t[j - 1])
      {
        L[i][j] = L[i - 1][j - 1] + 1;
        S[i][j] = 0;
      }
      else
      {
        L[i][j] = max(L[i][j - 1], L[i - 1][j]);
        if (L[i][j] == L[i][j - 1])
          S[i][j] = 1;
        else
          S[i][j] = 2;
      }
    }
  return L[m][n];
}

void printLCS(char s[], char t[], int m, int n)
{
  if (m == 0 || n == 0)
    return;

  if (S[m][n] == 0)
  {
    printLCS(s, t, m - 1, n - 1);
    cout << s[m - 1];
  }
  else if (S[m][n] == 1)
    printLCS(s, t, m, n - 1);
  else if (S[m][n] == 2)
    printLCS(s, t, m - 1, n);
}