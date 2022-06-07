/*
  In this type of problem, we are given two strings x and y. We need to return the length of the longest common subsequence.

  Base Condition:
  To properly find the base condition find the smallest valid input (preferable method) or the largest invalid input. In this case, the smallest invalid input is:
  if(n == 0 || m == 0)
    return 0;

  Choice diagram:
  Given one element in each substring represented by x[i] and y[j], we can have to possible scenarios:

  Case-1: x[i] == y[j]
  In this case, we return the value (1+lcs(x, y, m-1, n-1));

  Case-2: x[i] != y[j]
  In this case we are presented with two options: The longest substring can be found if we decrement m or if we decrement n. For eg: we have two strings "reat" and "great". Here, we will have to move y's pointer to the next element to find the LCS.

  Since we don't know and can't predict what lies ahead, we use the max function.

  return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));

*/

#include <bits/stdc++.h>

using namespace std;

int recursive(string x, string y, int m, int n)
{
  if (!n || !m)
    return 0;

  if (x[m] == y[n])
    return 1 + recursive(x, y, m - 1, n - 1);

  return max(recursive(x, y, m - 1, n), recursive(x, y, m, n - 1));
}

int memoized(vector<vector<int>> &t, string x, string y, int m, int n)
{
  if (!n || !m)
    return 0;

  if (t[m][n] != -1)
    return t[m][n];
  if (x[m] == y[n])
    return t[m][n] = 1 + recursive(x, y, m - 1, n - 1);

  return t[m][n] = max(recursive(x, y, m - 1, n), recursive(x, y, m, n - 1));
}

int iterative(vector<vector<int>> &t, string x, string y, int m, int n)
{
  for (auto i = 0; i <= m; i++)
    for (auto j = 0; j <= n; j++)
      if (!i || !j)
        t[i][j] = 0;
  for (auto i = 1; i <= m; i++)
    for (auto j = 1; j <= n; j++)
      if (x[i] == y[j])
        t[i][j] = 1 + t[i - 1][j - 1];
      else
        t[i][j] = max(t[i - 1][j], t[i][j - 1]);

  return t[m][n];
}

int main()
{
  return 0;
}
