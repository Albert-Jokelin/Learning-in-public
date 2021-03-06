/*
  Given two integer-based arrays- val and wt and two integers- n and w where,
  val denotes the value of the items present
  wt denotes the weight of the items present
  n denotes the number odf items present
  w denotes the capacity of the knapsack

  Find the maximum number of elements that can be stored in the knapsack.
*/

#include <bits/stdc++.h>

using namespace std;

int readInt()
{
  int x;
  cin >> x;
  return x;
}

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
    return t[n][w] = max(val[n - 1] + memoizedKnapsack(t, wt, val, n - 1, w - val[n - 1]), memoizedKnapsack(t, wt, val, n - 1, w));

  return t[n][w] = memoizedKnapsack(t, wt, val, n - 1, w);
}

int iterativeKnapsack(vector<vector<int>> &t, vector<int> &wt, vector<int> &val, int n, int w)
{
  for (auto i = 0; i <= n; i++)
    t[i][0] = 1;
  for (auto i = 1; i <= w; i++)
    t[0][i] = 0;

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
  int n, w;
  vector<int> wt, val;

  cout << "\nEnter the size of the array: ";
  cin >> n;
  cout << "\nEnter the value array: ";
  for (auto i = 0; i < n; i++)
    val.push_back(readInt());
  cout << "\nEnter the weights array: ";
  for (auto i = 0; i < n; i++)
    wt.push_back(readInt());
  cout << "\nEnter the capacity of the knapsack: ";
  w = readInt();

  vector<vector<int>> t(n, vector<int>(w, -1));

  cout << "\nRecursive call: " << recursiveKnapsack(wt, val, n, w) << "\nMemoized call: " << memoizedKnapsack(t, wt, val, n, w) << "\nIterative call: " << iterativeKnapsack(t, wt, val, n, w);

  return 0;
}
