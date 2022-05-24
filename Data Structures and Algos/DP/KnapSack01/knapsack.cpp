#include <bits/stdc++.h>

using namespace std;

int recursiveKnapsack(vector<int> &wt, vector<int> &val, int n, int w)
{
  if (n == 0 || w == 0)
    return 0;
  if (wt[n - 1] <= w)
    return max(val[n - 1] + recursiveKnapsack(wt, val, n - 1, w - val[n - 1]), recursiveKnapsack(wt, val, n - 1, w));

  return recursiveKnapsack(wt, val, n - 1, w);
}

int memoizedKnapsack(vector<vector<int>> &t, vector<int> &wt, vector<int> &val, int n, int w)
{
  if (n == 0 || w == 0)
    return 0;

  if (t[n][w] != -1)
    return t[n][w];
  if (wt[n - 1] <= w)
    return t[n][w] = max(val[n - 1] + recursiveKnapsack(wt, val, n - 1, w - val[n - 1]), recursiveKnapsack(wt, val, n - 1, w));

  return t[n][w] = recursiveKnapsack(wt, val, n - 1, w);
}

int iterativeKnapsack(vector<vector<int>> &t, vector<int> &wt, vector<int> &val, int n, int w)
{
  for (auto i = 0; i <= n; i++)
    t[i][0] = 0;
  for (auto i = 0; i <= w; i++)
    t[0][i] = 0;

  t[0][0] = 1;

  for (auto i = 1; i <= n; i++)
    for (auto j = 1; j <= w; j++)
    {
      if (wt[i - 1] <= j)
        t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
      else
        t[i][j] = t[i - 1][j];
    }

  return t[n][w];
}

int main()
{
  // ...

  return 0;
}
