/*
  Given an array of coins and a sum, find the maximum number of ways a the coins can be used to make the sum.

*/

#include <bits/stdc++.h>

using namespace std;

int function(vector<vector<int>> &t, vector<int> &a, int n, int amt)
{
  if (amt == 0)
    return 1;
  if (n == 0)
    return 0;
  if (t[n][amt] != -1)
    return t[n][amt];

  if (a[n - 1] <= amt)
    return t[n][amt] = function(t, a, n, amt - a[n - 1]) + function(t, a, n - 1, amt);

  return t[n][amt] = function(t, a, n - 1, amt);
}

int change(int amount, vector<int> &coins)
{
  vector<vector<int>> t(coins.size() + 1, vector<int>(amount + 1, -1));

  return function(t, coins, coins.size(), amount);
}

int main()
{
  return 0;
}
