/*
  Given a string a, find the largest palindromic subsequence.

*/

#include <bits/stdc++.h>
#include "001_LCS.cpp"

using namespace std;

int main(){
  string a;
  cin>>a;
  string b = a;
  reverse(b.begin(), b.end());
  vector<vector<int>> t(a.size() + 1, vector<int>(b.size() + 1, -1));
  cout<<"Ans: "<<iterative(t, a, b, a.size(), b.size());

  return 0;
}
