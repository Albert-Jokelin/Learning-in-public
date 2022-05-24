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

int memoizedSubsetSum(vector<vector<bool>> &t, vector<int> &a, int s, int n)
{
  if (s == 0)
    return 1;
  if (n == 0)
    return 0;
  if (t[n][s] != -1)
    return t[n][s];
  if (a[n - 1] <= s)
    return t[n][s] = max(recursiveSubsetSum(a, s - a[n - 1], n - 1), recursiveSubsetSum(a, s, n - 1));

  return t[n][s] = recursiveSubsetSum(a, s, n - 1);
}
int main()
{
  // ...
  return 0;
}
