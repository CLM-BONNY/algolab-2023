#include <iostream>
#include <cstring>

void reverseString(char *str, int start, int end);
void swap(char *str, int a, int b);

using namespace std;

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    char str[100];
    cin >> str;
    int strLength = strlen(str);

    int start = 0;
    int end = strLength - 1;

    reverseString(str, start, end);

    cout << str << endl;
  }

  return 0;
}

void swap(char *str, int a, int b)
{
  char tmp = str[a];
  str[a] = str[b];
  str[b] = tmp;
}

void reverseString(char *str, int start, int end)
{
  if (start >= end) return;

  swap(str, start, end);

  reverseString(str, start + 1, end - 1);
}
