/*
  Given an array and a sum- s, find the number of subsets having their sum equal to s

*/

#include <bits/stdc++.h>

using namespace std;

int recursivecountSubsets(vector<int> &a, int s, int n)
{
  if (!n)
    return 0;
  if (!s)
    return 1;

  if (a[n - 1] <= s)
    return recursivecountSubsets(a, s - a[n - 1], n - 1) + recursivecountSubsets(a, s, n - 1);
  return recursivecountSubsets(a, s, n - 1);
}

int memoizationEqualSubsets(vector<vector<int>> &t, vector<int> &a, int s, int n)
{
  if (!n)
    return 0;
  if (!s)
    return 1;
  if (t[n][s] != -1)
    return t[n][s];

  if (a[n - 1] <= s)
    return t[n][s] = recursivecountSubsets(a, s - a[n - 1], n - 1) + recursivecountSubsets(a, s, n - 1);
  return t[n][s] = recursivecountSubsets(a, s, n - 1);
}

int tabularEqualSubsets(vector<vector<int>> &t, vector<int> &a, int s, int n)
int main()
{
  // ...

  return 0;
}
