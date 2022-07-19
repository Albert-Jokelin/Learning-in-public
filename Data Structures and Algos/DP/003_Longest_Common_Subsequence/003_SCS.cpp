/*
  Given two strings a & b, merge them to form a super-sequence. Return the length of the shortest such merger.
  Eg: a = "geek", b = "eke"; c = "geeke", size = 5

  Steps:
    1) Find the length of a, b and the SCS(a, b)
    2) return a + b - lcs
*/

#include <bits/stdc++.h>
#include "002_LCSubstring.cpp"

using namespace std;

int main(){
  string x, y;
  cin>>x>>y;

  vector<vector<int>> t(x.size()+1, vector<int>(y.size()+1, -1));
  cout<<"Ans: "<<x.size() + y.size() - iterative(t, x, y, x.size(), y.size());
  return 0;
}
