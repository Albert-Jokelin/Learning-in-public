/*
  Given an array of coins- A and an integer- amount, return the fewest number of coins needed to make up the amount
*/

#include<bits/stdc++.h>

using namespace std;

int myFunction(vector<int> &coins, int w, int n){
  if(n == 0 || w == 0)
    return w == 0? 0 : INT_MAX-1;
  if(coins[n-1] <= w)
    return min(1 + myFunction(coins, w - coins[n-1], n), myFunction(coins, w, n-1));
  return myFunction(coins, w, n - 1);
}

int memoization(vector<vector<int>> &t, vector<int> &coins, int w, int n){
  if(n == 0 || w == 0)
    return w == 0? 0 : INT_MAX-1;
  if(t[n][w] != -1)
    return t[n][w];

  if(coins[n-1] <= w)
    return t[n][w] = min(1 + memoization(t, coins, w - coins[n-1], n), memoization(t, coins, w, n-1));
  return t[n][w] = memoization(t, coins, w, n - 1);
}

int iterative(vector<vector<int>> &t, vector<int> &coins, int w, int n){
  for(auto i = 0; i <= n; i++)
    for(auto j = 0; j <= w; j++)
      if( i == 0 || w == 0)
        t[i][j] = j == 0? 0: INT_MAX-1;

  for(auto i = 1; i <= n; i++)
    for(auto j = 0; j <= w; j++){
      if(coins[i] <= j){
        t[i][j] = min(1 + t[i][j - coins[i]], t[i-1][j]);
      } else {
        t[i][j] = t[i-1][j];
      }
    }
}

int main(){
  int n, w;
  cin>>n>>w;
  vector<int>coins(n, 0);
  for(auto i: coins)
    cin>>i;
  cout<<myFunction(coins, w, n);
  return 0;
}
