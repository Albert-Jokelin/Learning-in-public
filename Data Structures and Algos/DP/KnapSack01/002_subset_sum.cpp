/*
  Given an array and a sum s, we need to find whether there exists a subset whose sum of all it's elements is equal to s.

  This function returns a boolean output.

*/
#include <bits/stdc++.h>

using namespace std;

int recursiveSubsetSum(vector<int> &a, int s, int n)
{
  if (s == 0)
    return 1;
  if (n == 0)
    return 0;
  if (a[n - 1] <= s)
    return max(recursiveSubsetSum(a, s - a[n - 1], n - 1), recursiveSubsetSum(a, s, n - 1));

  return recursiveSubsetSum(a, s, n - 1);
}

int memoizedSubsetSum(vector<vector<int>> &t, vector<int> &a, int s, int n)
{
  if (s == 0)
    return 1;
  if (n == 0)
    return 0;
  if (t[n][s] != -1)
    return t[n][s];
  if (a[n - 1] <= s)
    return t[n][s] = max(memoizedSubsetSum(t, a, s - a[n - 1], n - 1), memoizedSubsetSum(t, a, s, n - 1));

  return t[n][s] = memoizedSubsetSum(t, a, s, n - 1);
}

int tabulatedSubsetSum(vector<vector<bool>> &t, vector<int> &a, int s, int n)
{
  for (auto i = 0; i <= n; i++)
    t[i][0] = 1;
  for (auto i = 1; i <= s; i++)
    t[0][i] = 0;

  for (auto i = 1; i <= n; i++)
    for (auto j = 1; j <= s; j++)
    {
      if (a[n - 1] <= j)
        t[i][j] = max(t[i - 1][j - a[i - 1]], t[i - 1][j]);
      else
        t[i][j] = t[i - 1][j];
    }

  return t[n][s];
}

int main()
{
  // ...
  return 0;
}
