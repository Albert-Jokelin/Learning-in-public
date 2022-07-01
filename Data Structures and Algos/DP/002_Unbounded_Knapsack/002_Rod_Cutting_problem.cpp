/*
  Given a rod of length n an integer array len that contains the lengths at which the rod must be cut and an integer array price that tells us the price needed to cut each rod. Maximize the value of price.

  The code for this problem is same as the one we use in unbounded knapsack.

*/
#include <bits/stdc++.h>
using namespace std;

int readInt()
{
  int x;
  cin >> x;
  return x;
}

int rodCuttingProblem(vector<vector<int>> &t, vector<int> &len, vector<int> &price, int n, int N)
{
  if (n == 0 || N == 0)
    return 0;

  if (t[n][N] != -1)
    return t[n][N];
  if (len[n - 1] <= N)
    return t[n][N] = max(price[n - 1] + rodCuttingProblem(t, len, price, n - 1, N - price[n - 1]), rodCuttingProblem(t, len, price, n - 1, N));

  return t[n][N] = rodCuttingProblem(t, len, price, n - 1, N);
}

int main()
{
  int n = readInt(), N = readInt();
  vector<vector<int>> t(n+1, vector<int>(N+1, 0));
  vector<int> len(n, 0), price(n, 0);

  for(auto i = 0; i < n; i++){
    cin>>len[i]>>price[i];
  }

  cout<<rodCuttingProblem(t, len, price, n, N);
  return 0;
}
