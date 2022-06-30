/*
  Given an array and a difference, find the number of ways the array can be partitioed such that the difference
  of the sum of the partitions is equal to the given difference.

  We use the
*/

#include <bits/stdc++.h>
#include "002_subset_sum.cpp"

using namespace std;

int main()
{
  vector<vector<int>> t;
  vector<int> a;
  int n, s, diff;

  for (auto &i : a)
    s += i;

  tabulatedSubsetSum(t, a, n, (diff + s) / 2);

  // ...
  return 0;
}
