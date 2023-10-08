#include <iostream>
#include <cstring>
#include <cmath>

void swap(char *a, char *b);
void weight(char *c, int &cnt);
void stringPermutation(char *str, int begin, int end, int &cnt);

using namespace std;

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int cnt = 0;
    char s[100];

    cin >> s;

    stringPermutation(s, 0, strlen(s), cnt);
    
    cout << cnt << endl;
  }
  return 0;
}

void swap(char *a, char *b)
{
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void weight(char *c, int &cnt)
{
  int strWeight = 0;

  for (int i = 0; i < strlen(c); i++)
  {
    strWeight += pow((-1), i) * ((int)c[i] - 97);
  }

  if (strWeight > 0)
  {
    cnt++;
  }
}

void stringPermutation(char *str, int begin, int end, int &cnt)
{
  int range = end - begin;

  if (range == 1)
  {
    weight(str, cnt);
  }
  else
  {
    for (int i = 0; i < range; i++)
    {
      swap(&str[begin], &str[begin + i]);
      stringPermutation(str, begin + 1, end, cnt);
      swap(&str[begin], &str[begin + i]);
    }
  }
}
