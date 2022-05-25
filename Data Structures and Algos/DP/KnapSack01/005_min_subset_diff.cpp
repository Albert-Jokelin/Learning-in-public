/*
  Given an array, partition the array in such a way that the difference of the sum of both the partitions is minimum.

  Approach :  Same as subset sum but given sum is replaced by total_sum/2.
*/

#include <bits/stdc++.h>

using namespace std;

int recursiveMinSubset(vector<int> &a, int s, int n)
{
  if (n == 0 || s == 0)
    return s;
  if (a[n - 1] <= s)
    return min(recursiveMinSubset(a, s - a[n - 1], n - 1), recursiveMinSubset(a, s, n - 1));

  return recursiveMinSubset(a, s, n - 1);
}

int memoizedMinSubset(vector<vector<int>> &t, vector<int> &a, int s, int n)
{
  if (n == 0 || s == 0)
    return s;
  if (t[n][s] != -1)
    return t[n][s];
  if (a[n - 1] <= s)
    return min(memoizedMinSubset(t, a, s - a[n - 1], n - 1), memoizedMinSubset(t, a, s, n - 1));

  return memoizedMinSubset(t, a, s, n - 1);
}

int tabulatedMinSubset(vector<vector<int>> &t, vector<int> &a, int s, int n)
{
  for (auto i = 0; i <= n; i++)
    t[i][0] = 1;
  for (auto i = 1; i <= s; i++)
    t[0][i] = 0;

  for (auto i = 1; i <= n; i++)
    for (auto j = 1; j <= s; j++)
      if (a[i - 1] <= j)
        t[i][j] = min(t[i - 1][j - a[i - 1]], t[i - 1][j]);
      else
        t[i][j] = t[i - 1][j];
  return t[n][s];
}

int main()
{
  vector<int> a;
  int s, n;

  for (auto &e : a)
    s += e;
  recursiveMinSubset(a, s / 2, n);
  // ...
  return 0;
}
