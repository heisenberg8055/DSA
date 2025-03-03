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

- <details>
    <summary><a href="https://leetcode.com/problems/counting-bits/">338. Counting Bits</a></summary>

    ```cpp
    class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int>ans(n + 1, 0);
            for(int i = 1; i <= n; i++) {
                ans[i] = ans[i >> 1] + (i & 1);
            }
            return ans;
        }
    };
    ```
</details>

- <details>
    <summary><a href="https://leetcode.com/problems/is-subsequence/description/">392. Is Subsequence</a></summary>

    - <details>
        <summary>Two Pointer</summary>

        ```cpp
        class Solution {
        public:
            bool isSubsequence(string s, string t) {
                int n = s.size(), m = t.size();
                if(n > m) {
                    return false;
                }
                int i = 0, j = 0;
                while(i < n && j < m) {
                    while(j < m && t[j] != s[i]) {
                        j++;
                    }
                    if(t[j] == s[i]){

                    
                    i++;
                    j++;
                    } else{
                        break;
                    }
                }
                return i == n;
            }
        };
        ```
        </details>

    - <details>
        <summary>Memoization</summary>

        ```cpp
        class Solution {
            private:
                int isLCS(string s, string t, int i, int j, vector<vector<int>> &dp) {
                    if (i == 0 || j == 0) {
                        return 0;
                    }
                    if (dp[i][j] != -1) {
                        return dp[i][j];
                    }
                    if (s[i - 1] == t[j - 1]) {
                        return dp[i][j] = 1 + isLCS(s, t, i - 1, j - 1, dp);
                    }
                    return dp[i][j] = isLCS(s, t, i, j - 1, dp);
                }
            public:
                bool isSubsequence(string s, string t) {
                    int n = s.size();
                    int m = t.size();
                    if (n > m) {
                        return false;
                    }
                    vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
                    return isLCS(s, t, n, m, dp) == n;
                }
            };
        ```
        </details>

</details>

- <details>
    <summary><a href="https://leetcode.com/problems/min-cost-climbing-stairs/">746. Min Cost Climbing Stairs</a></summary>

    - <details>
        <summary>Recursion</summary>

        ```cpp
        class Solution {
        private:
            int help(int i, int n, vector<int>& cost) {
                if (i > n - 1) {
                    return 0;
                }
                return cost[i] + min(help(i + 1, n, cost), help(i + 2, n, cost));
            }
        public:
            int minCostClimbingStairs(vector<int>& cost) {
                int n = cost.size();
                return min(help(0, n, cost), help(1, n, cost));
            }
        };
        ```
        </details>

    - <details>
        <summary>Memoization</summary>

        ```cpp
        class Solution {
        private:
            int help(int i, int n, vector<int>& cost, vector<int>& dp) {
                if (i > n - 1) {
                    return 0;
                }
                if (dp[i] != -1) {
                    return dp[i];
                }
                return dp[i] = cost[i] + min(help(i + 1, n, cost, dp), help(i + 2, n, cost, dp));
            }
        public:
            int minCostClimbingStairs(vector<int>& cost) {
                int n = cost.size();
                vector<int>dp(n, -1);
                return min(help(0, n, cost, dp), help(1, n, cost, dp));
            }
        };
        ```
        </details>

    - <details>
        <summary>Tabulation</summary>

        ```cpp
        class Solution {
        public:
            int minCostClimbingStairs(vector<int>& cost) {
                int n = cost.size();
                vector<int>dp(n + 2, 0);
                for(int i = n - 1; i >= 0; i--) {
                    dp[i] = cost[i] + min(dp[i + 1], dp[i +2]);
                }
                return min(dp[0], dp[1]);
            }
        };
        ```
        </details>

    - <details>
        <summary>Space Optimization</summary>

        ```cpp
        class Solution {
        public:
            int minCostClimbingStairs(vector<int>& cost) {
                int n = cost.size();
                int first = cost[0];
                int second = cost[1];
                if (n <= 2) {
                    return min(first, second);
                }
                for(int i = 2; i < n; i++) {
                    int curr = cost[i] + min(first, second);
                    first = second;
                    second = curr;
                }
                return min(first, second);
            }
        };
        ```
        </details>

</details>

- <details>
    <summary><a href="https://leetcode.com/problems/fibonacci-number/description/">509. Fibonacci Number</a></summary>

    - <details>
        <summary>Recursion</summary>

        ```cpp
        class Solution {
        public:
            int fib(int n) {
                if (n < 2) {
                    return n;
                }
                return fib(n - 1) + fib(n - 2);
            }
        };
        ```
        </details>

    - <details>
        <summary>Memoization</summary>

        ```cpp
        class Solution {
            vector<int>dp;
        private:
            int help(int n) {
                if (n < 2) {
                    return n;
                }
                if (dp[n] != -1) {
                    return dp[n];
                }
                return dp[n] = fib(n - 1) + fib(n - 2);
            }
        public:
            int fib(int n) {
                dp.resize(n + 1, -1);
                return help(n);
            }
        };
        ```
        </details>

    - <details>
        <summary>Tabulation</summary>

        ```cpp
        class Solution {
        public:
            int fib(int n) {
                if (n < 2) {
                    return n;
                }
                vector<int>dp(n + 1, -1);
                dp[0] = 0;
                dp[1] = 1;
                for(int i = 2; i <= n; i++) {
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
            int fib(int n) {
                if (n < 2) {
                    return n;
                }
                int ne = 1, nn = 0, ans = 0;
                for(int i = 2; i <= n; i++) {
                    ans = ne + nn;
                    nn = ne;
                    ne = ans;
                }
                return ans;
            }
        };
        ```
        </details>

</details>


- <details>
    <summary><a href="https://leetcode.com/problems/divisor-game">1025. Divisor Game</a></summary>

    ```c++
        class Solution {
        public:
            bool divisorGame(int n) {
                return !(n & 1);
            }
        };
    ```
</details>

- <details>
    <summary><a href="https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/">2900. Longest Unequal Adjacent Groups Subsequence I</a></summary>

    ```cpp
        class Solution {
        public:
            vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
                int n = words.size();
                vector<string>ans;
                int comp = !groups[0];
                for(int i = 0; i < n; i++) {
                    if(comp != groups[i]) {
                        ans.push_back(words[i]);
                        comp = !comp;
                    }
                }
                return ans;
            }
        };
    ```
</details>

- <details>
    <summary><a href="https://leetcode.com/problems/n-th-tribonacci-number">1137. N-th Tribonacci Number</a></summary>

    ```c++
        class Solution {
        private:
            int help(int n, vector<int>& dp) {
                if (n < 2) {
                    return n;
                } else if (n == 2) {
                    return 1;
                } else if (dp[n] != -1) {
                    return dp[n];
                }
                return dp[n] = help(n - 1, dp) + help(n - 2, dp) + help(n - 3, dp);
            }
        public:
            int tribonacci(int n) {
                vector<int>dp(n + 1, -1);
                return help(n, dp);
            }
        };
    ```
</details>

- <details>
    <summary><a href="https://leetcode.com/problems/maximum-repeating-substring">1668. Maximum Repeating Substring</a></summary>

    - <details>
        <summary>Brute Force</summary>

        ```cpp
        class Solution {
        private:
            bool chk(int i, string word, string s) {
                string temp = "";
                while(i--) {
                    temp += word;
                }
                if(temp.size() > s.size()) {
                    return false;
                }
                for(int i = 0; i < s.size() - temp.length() + 1; i++) {
                    if(temp == s.substr(i, temp.length())) {
                        return true;
                    }
                }
                return false;
            }
        public:
            int maxRepeating(string s, string word) {
                int ans  = 0;
                int m = s.size(), n = word.size();
                if (n > m) {
                    return ans;
                }
                while(chk(ans + 1, word, s)) {
                    ans++;
                }
                return ans;
            }
        };
        ```
    </details>
</details>