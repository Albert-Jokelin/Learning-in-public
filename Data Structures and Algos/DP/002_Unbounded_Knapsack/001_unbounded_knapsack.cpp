/*
  The difference between 0/1 knapsack and unbounded knapsack lies in the fact that unbounded knapsack allows you to have multiple occurences of a single element. This can be used in scenarios like finding the minimum number of denominations that can represent a value in particlar currency.

  The approach we follow in unbounded knapsack is, if an element has been chosen we consider it not to be processed. A real world analogy can be ice creams. If you like eating ice creams, you would certainly go for as many of them you are offered. However, if you aren't fond of them, you won't really have as much.

  ## The changes that have to be made:
  If we consider the iterative knapsack function:
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

  We can observe that, to allow multiple occurences we must change the recursive call. The recursive call will be changed as follows:
      if (wt[n - 1] <= w)
        return t[n][w] = max(val[n - 1] + memoizedKnapsack(wt, val, n, w - val[n - 1]), memoizedKnapsack(wt, val, n - 1, w));

      return t[n][w] = memoizedKnapsack(wt, val, n - 1, w);
*/
