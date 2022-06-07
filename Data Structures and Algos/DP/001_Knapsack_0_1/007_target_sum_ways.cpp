/*
  Given an integer array a and an integer target.

  You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

  For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
  Return the number of different expressions that you can build, which evaluates to target.

  Approach:
  - Divide the array into two parts such that the difference of the sums of partitions is equal to target.

  In essence, if the array a is divided into A1 & A2 then, sum(A1) - sum(A2) == target. We return the number of such instances found while iterating over a.

*/
#include <bits/stdc++.h>

using namespace std;

int readInt()
{
  int x;
  cin>>x;
  return x;
}

int findAns(vector<int> &a, int W, int n)
{
  if (n == 0)
    return 0;
  if (W == 0)
    return 1;

  int p1, p2;

  if (a[n - 1] <= W)
    p1 = findAns(a, W - a[n - 1], n - 1);
  p2 = findAns(a, W, n - 1);

  return p1 + p2;
}
int findTargetSumWays(vector<int> &nums, int target)
{
  int W, sum = 0;

  for (auto &num : nums)
    sum += num;

  W = (sum + target) / 2;

  return findAns(nums, W, nums.size());
}

int main()
{
  vector<int> a;
  int n, W;

  cin>>n>>W;

  for(auto i = 0; i < n; i++)
    a.push_back(readInt());
  cout<<"\nAns: "<<findTargetSumWays(a, W);

  return 0;
}
