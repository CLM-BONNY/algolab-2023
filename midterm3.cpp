#include <iostream>
#define MAX_SIZE 101

using namespace std;

int count_teams(int a[], int n);

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    int a[MAX_SIZE];
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }

    cout << count_teams(a, n) << endl;
  }

  return 0;
}

int count_teams(int a[], int n)
{
  int team_count = 0;
  bool team[MAX_SIZE];
  for (int i = 1; i <= n; i++)
  {
    team[i] = false;
  }

  for (int j = 1; j <= n; j++)
  {
    if (!team[j])
    {
      team_count++;
      team[j] = true;
      int k = a[j];

      while (k != j)
      {
        team[k] = true;
        k = a[k];
      }
    }
  }

  return team_count;
}
