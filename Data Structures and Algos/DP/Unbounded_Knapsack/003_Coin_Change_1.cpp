/*

  You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

  Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

  You may assume that you have an infinite number of each kind of coin.

*/

#include <bits/stdc++.h>

using namespace std;
int recursive(vector<int> &coins, int n, int w)
{
  if (!n || !w)
    return w == 0 ? 0 : INT_MAX;
  if (coins[n - 1] < w)
    return min(recursive(coins, n, w - coins[n - 1]) + 1, recursive(coins, n - 1, w));

  return recursive(coins, n - 1, w);
}

int memoized(vector<vector<int>> &t, vector<int> &coins, int n, int w)
{
  if (!n || !w)
    return w == 0 ? 0 : INT_MAX;

  if (t[n][w] != -1)
    return t[n][w];

  if (coins[n - 1] < w)
    return t[n][w] = min(recursive(coins, n, w - coins[n - 1]) + 1, recursive(coins, n - 1, w));

  return t[n][w] = recursive(coins, n - 1, w);
}

int iterative(vector<vector<int>> &t, vector<int> &coins, int n, int w)
{
  for (auto i = 0; i <= n; i++)
    for (auto j = 0; j <= w; j++)
      t[i][j] = j == 0 ? 1 : INT_MAX;
  for (auto i = 1; i <= n; i++)
    for (auto j = 1; j <= w; j++)
    {
      if (coins[i - 1] <= j)
        t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
      else
        t[i][j] = t[i - 1][j];
    }
  return t[n][w];
}
