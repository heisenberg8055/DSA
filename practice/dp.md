# Dp Problems

Dynamic Programming is a commonly used algorithmic technique used to optimize recursive solutions when same subproblems are called again.

- The core idea behind DP is to store solutions to subproblems so that each is solved only once.
- To solve DP problems, we first write a recursive solution in a way that there are overlapping subproblems in the recursion tree (the recursive function is called with the same parameters multiple times)
- To make sure that a recursive value is computed only once (to improve time taken by algorithm), we store results of the recursive calls.
- There are two ways to store the results, one is top down (or memoization) and other is bottom up (or tabulation).


### Approaches

1. Top-Down Approach (Memoization):
    - In the top-down approach, also known as memoization, we keep the solution recursive and add a             memoization table to avoid repeated calls of same subproblems.

    - Before making any recursive call, we first check if the memoization table already has solution for it.
    - After the recursive call is over, we store the solution in the memoization table.

2. Bottom-Up Approach (Tabulation):
    - In the bottom-up approach, also known as tabulation, we start with the smallest subproblems and gradually build up to the final solution.

    - We write an iterative solution (avoid recursion overhead) and build the solution in bottom-up manner.
    - We use a dp table where we first fill the solution for base cases and then fill the remaining entries of the table using recursive formula.
    - We only use recursive formula on table entries and do not make recursive calls.

## Problems
- <details>
    <summary><a href="https://leetcode.com/problems/climbing-stairs/description/">70. Climbing Stairs</a></summary>


    - <details>
            <summary>Recursion</summary>

        ```cpp
        class Solution {
        private:
            void trav(int s, int n, int &ans) {
                if (s > n) {
                    return;
                }
                if (s == n) {
                    ans++;
                    return;
                }
                trav(s + 1, n, ans);
                trav(s + 2, n, ans);
            }
        public:
            int climbStairs(int n) {
                int ans = 0;
                trav(0, n, ans);
                return ans;
            }
        };
        ```
        </details>

    - <details>
            <summary>Top down (Memoization)</summary>

        ```cpp
        class Solution {
        private:
            int trav(int n, vector<int> &dp) {
                if (n == 0 || n == 1) {
                    return 1;
                }
                if (dp[n] != -1) {
                    return dp[n];
                }
                return dp[n] = trav(n - 1, dp) + trav(n - 2, dp);
            }
        public:
            int climbStairs(int n) {
                vector<int>dp(n + 1, -1);
                return trav(n, dp);
            }
        };
        ```
        </details>

    - <details>
            <summary>Bottom up (Tabulation)</summary>
            
            
        ```cpp
        class Solution {
        public:
            int climbStairs(int n) {
                vector<int>dp(n + 1, 0);
                dp[1] = 1, dp[0] = 1;
                for(int i = 2; i < n + 1; i++) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
                return dp[n];
            }
        };
        ```

        </details>
    - <details>
            <summary>Space Optimization</summary>

        ```cpp
        class Solution {
        public:
            int climbStairs(int n) {
                if(n == 0 || n == 1) {
                    return 1;
                }
                int prev = 1, curr = 1;
                for(int i = 2; i <= n; i++) {
                    int temp = curr;
                    curr = prev + curr;
                    prev = temp;
                }
                return curr;
            }
        };
        ```

        </details>
</details>

- <details>
    <summary><a href="https://leetcode.com/problems/pascals-triangle/description/">118. Pascal's Triangle (Combinatorial Formula)</a></summary>

    \
    Combinatorial formula C(n, k) = C(n-1, k-1) + C(n-1, k)
    ```cpp
    class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>>ans;
            for(int i = 1; i <= numRows; i++) {
                vector<int>temp(i, 1);
                if (i != 1 && i != 2) {
                    for(int j = 1; j < i - 1; j++)
                    {
                        temp[j] = ans[i - 2][j - 1] + ans[i - 2][j];
                    }
                }
                ans.push_back(temp);
            }
            return ans;
        }
    };
    ```
</details>

- <details>
    <summary><a href="https://leetcode.com/problems/pascals-triangle-ii/description/">119. Pascal's Triangle II(Combinatorial Formula)</a></summary>

    \
    Combinatorial formula C(n, k) = C(n-1, k-1) + C(n-1, k)
    ```cpp
    class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int>ans(1, 1);
            if (rowIndex == 0) {
                return ans;
            }
            for(int i = 1; i <= rowIndex; i++) {
                vector<int>reff(i + 1, 1);
                for(int j = 1; j < i; j++) {
                    reff[j] = ans[j - 1] + ans[j];
                }
                ans = reff;
            }
            return ans;
        }
    };
    ```
</details>

- <details>
    <summary><a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock/">121. Best time to buy and sell stocks</a></summary>

    \
    ```cpp
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int ans = 0;
            int maxi = prices[n - 1];
            for(int i = n - 2; i >= 0; i--) {
                ans = max(ans, maxi - prices[i]);
                maxi = max(prices[i], maxi);
            }
            return ans;
        }
    };
    ```
</details>
