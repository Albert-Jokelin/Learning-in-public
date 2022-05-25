/*
  Given an array, partition it in such a way that both the partions have an equal sum.
*/

#include <bits/stdc++.h>

using namespace std;

bool recursiveEqualSum(vector<int> &a, int s, int n)
{
  if (s == 0)
    return true;
  if (n == 0)
    return false;
  if (a[n - 1] <= s)
    return recursiveEqualSum(a, s - a[n - 1], n - 1) || recursiveEqualSum(a, s, n - 1);
  return recursiveEqualSum(a, s, n - 1);
}

int memoizationEqualSum(vector<vector<int>> &t, vector<int> &a, int s, int n)
{
  if (s == 0)
    return 1;
  if (n == 0)
    return 0;
  if (t[n][s] != -1)
    return t[n][s];
  if (a[n - 1] <= s)
    return t[n][s] = max(memoizationEqualSum(t, a, s - a[n - 1], n - 1), memoizationEqualSum(t, a, s, n - 1));
  return t[n][s] = memoizationEqualSum(t, a, s, n - 1);
}

int tabulationEqualSum(vector<vector<int>> &t, vector<int> &a, int s, int n)
{
  for (auto i = 0; i <= n; i++)
    t[i][0] = 1;

  for (auto i = 1; i <= s; i++)
    t[0][i] = 0;

  for (auto i = 1; i <= n; i++)
    for (auto j = 1; j <= s; j++)
      if (a[i - 1] <= j)
      {
        t[i][j] = max(t[i - 1][j - a[i - 1]], t[i - 1][j]);
      }
      else
      t[i][j] = t[i - 1][j];

  return t[n][s];
}
int main()
{
  int sum = 0;
  vector<int> arr;

  for (auto i = 0; i < arr.size(); i++)
    sum += arr[i];

  if (!(sum % 2))
  {
    cout << false;
    return 0;
  }

  sum /= 2;
  // ...

  return 0;
}
