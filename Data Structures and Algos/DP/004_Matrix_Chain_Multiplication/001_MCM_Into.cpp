/*
  Given a string/array anf two indices i and j, choose a value k such that the problem is broken into A[i..k] and A[k+1..j]. Each partition is solved and it's answer returned.

*/
#include<bits/stdc++.h>

using namespace std;

// Format
int solve(vector<int> &a, int i, int j){
  if(i > j)
    return 0;
  int ans;
  for(int k = i+1; k < j; k++){
    // calculate the temporary answer
    int temp = solve(a, i, k) + solve(a, k+1, j);
    ans = func(ans, temp);
  }

  return ans;
}
