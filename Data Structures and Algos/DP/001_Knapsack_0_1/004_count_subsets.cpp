/*
  Given an array and a sum- s, find the number of subsets having their sum equal to s

*/

#include <bits/stdc++.h>

using namespace std;

int readInt()
{
  int x;
  cin >> x;
  return x;
}

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
{
  for (auto i = 0; i <= n; i++)
    t[i][0] = 1;
  for (auto i = 0; i <= s; i++)
    t[0][i] = 0;
  for (auto i = 1; i <= n; i++)
    for (auto j = 1; j <= s; j++)
      if (a[i - 1] <= j)
        t[i][j] = t[i - 1][j - a[i - 1]] + t[i - 1][j];
      else
        t[i][j] = t[i - 1][j];

  return t[n][s];
}
int main()
{
  int n, sum;
  vector<int> wt;

  cout << "\nEnter the size of the array: ";
  cin >> n;
  cout << "\nEnter the weights array: ";
  for (auto i = 0; i < n; i++)
    wt.push_back(readInt());
  cout << "\nEnter the target sum: ";
  sum = readInt();

  vector<vector<int>> t(n + 1, vector<int>(sum + 1, -1));

  cout << "\nRecursive call: " << recursivecountSubsets(wt, sum, n) << "\nMemoized call: " << memoizationEqualSubsets(t, wt, sum, n) << "\nIterative call: " << tabularEqualSubsets(t, wt, sum, n);

  return 0;
}
