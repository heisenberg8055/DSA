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

- <details>
    <summary><a href="https://leetcode.com/problems/longest-palindromic-substring/">5. Longest Palindromic Substring</a></summary>

    - <details>
        <summary>Brute Force</summary>

        ```cpp
        class Solution {
        public:
            string longestPalindrome(string s) {
                for (int length = s.size(); length > 0; length--) {
                    for (int start = 0; start <= s.size() - length; start++) {
                        if (check(s, start, start + length)) {
                            return s.substr(start, length);
                        }
                    }
                }

                return "";
            }

        private:
            bool check(string s, int i, int j) {
                int left = i;
                int right = j - 1;

                while (left < right) {
                    if (s[left] != s[right]) {
                        return false;
                    }

                    left++;
                    right--;
                }

                return true;
            }
        };
        ```
        </details>
    
    - <details>
        <summary>Tabulation</summary>

        ```cpp
        class Solution {
        public:
            string longestPalindrome(string s) {
                int n = s.size();
                array<int, 2> ans = {0, 0};
                vector<vector<bool>> dp(n, vector<bool>(n));
                for(int i = 0; i < n; i++) {
                    dp[i][i] = true;
                }
                for(int i = 0; i < n - 1; i++) {
                    if (s[i] == s[i + 1]) {
                        dp[i][i + 1] = true;
                        ans = {i, i + 1};
                    }
                }
                for(int diff = 2; diff < n; diff++) {
                    for(int i = 0; i < n - diff; i++) {
                        int j = i + diff;
                        if(s[i] == s[j] && dp[i + 1][j - 1]) {
                            dp[i][j] = true;
                            ans = {i, j};
                        }
                    }
                }
                int i = ans[0];
                int j = ans[1];
                return s.substr(i, j - i + 1);
            }
        };
        ```
        </details>

    - <details>
        <summary>Tabulation(space optimization)</summary>

        ```cpp
        class Solution {
        private:
            string expand(int i, int j, string s) {
                int left = i, right = j;
                while(left >= 0 && right < s.size() && s[left] == s[right]) {
                    left--;
                    right++;
                }
                return s.substr(left + 1, right - left - 1);
            }
        public:
            string longestPalindrome(string s) {
                string ans = "";
                int n = s.size();
                for(int i = 0; i < n; i++) {
                    string odd = expand(i, i, s);
                    if(odd.size() > ans.size()) {
                        ans = odd;
                    }
                    string even = expand(i, i + 1, s);
                    if(even.size() > ans.size()) {
                        ans = even;
                    }
                }
                return ans;
            }
        };
        ```
    </details>

</details>

- <details>
    <summary><a href="https://leetcode.com/problems/maximum-number-of-points-with-cost/">1937. Maximum Number of Points with Cost</a></summary>
    
    - <details>
        <summary>Tabulation</summary>

        ```cpp
        class Solution {
        public:
            long long maxPoints(vector<vector<int>>& points) {
                int rows = points.size(), cols = points[0].size();
                vector<long long> previousRow(cols);

                // Initialize the first row
                for (int col = 0; col < cols; ++col) {
                    previousRow[col] = points[0][col];
                }

                // Process each row
                for (int row = 0; row < rows - 1; ++row) {
                    vector<long long> leftMax(cols);
                    vector<long long> rightMax(cols);
                    vector<long long> currentRow(cols);

                    // Calculate left-to-right maximum
                    leftMax[0] = previousRow[0];
                    for (int col = 1; col < cols; ++col) {
                        leftMax[col] = max(leftMax[col - 1] - 1, previousRow[col]);
                    }

                    // Calculate right-to-left maximum
                    rightMax[cols - 1] = previousRow[cols - 1];
                    for (int col = cols - 2; col >= 0; --col) {
                        rightMax[col] = max(rightMax[col + 1] - 1, previousRow[col]);
                    }

                    // Calculate the current row's maximum points
                    for (int col = 0; col < cols; ++col) {
                        currentRow[col] =
                            points[row + 1][col] + max(leftMax[col], rightMax[col]);
                    }

                    // Update previousRow for the next iteration
                    previousRow = currentRow;
                }

                // Find the maximum value in the last processed row
                long long maxPoints = 0;
                for (int col = 0; col < cols; ++col) {
                    maxPoints = max(maxPoints, previousRow[col]);
                }

                return maxPoints;
            }
        };
        ```
        </details>

    - <details>
        <summary>Tabulation(space optimization)</summary>

        ```cpp
        class Solution {
        public:
            long long maxPoints(vector<vector<int>>& points) {
                int cols = points[0].size();
                vector<long long> previousRow(cols);

                for (auto& row : points) {
                    // runningMax holds the maximum value generated in the previous
                    // iteration of each loop
                    long long runningMax = 0;

                    // Left to right pass
                    for (int col = 0; col < cols; ++col) {
                        runningMax = max(runningMax - 1, previousRow[col]);
                        previousRow[col] = runningMax;
                    }

                    runningMax = 0;
                    // Right to left pass
                    for (int col = cols - 1; col >= 0; --col) {
                        runningMax = max(runningMax - 1, previousRow[col]);
                        previousRow[col] = max(previousRow[col], runningMax) + row[col];
                    }
                }

                // Find maximum points in the last row
                long long maxPoints = 0;
                for (int col = 0; col < cols; ++col) {
                    maxPoints = max(maxPoints, previousRow[col]);
                }

                return maxPoints;
            }
        };
        ```
    </details>

</details>

- <details>
    <summary><a href="https://leetcode.com/problems/minimum-falling-path-sum/description/">931. Minimum Falling Path Sum</a></summary>
    
    - <details>
        <summary>Tabulation</summary>

        ```cpp
        class Solution {
        public:
            int minFallingPathSum(vector<vector<int>>& matrix) {
                int n = matrix.size();
                vector<int>prev = matrix[0];
                for(int i = 1; i < n; i++) {
                    vector<int>curr(n);
                    for(int j = 0; j < n; j++) {
                        int cl, cr, t;
                        cl = cr = t = INT_MAX;
                        if(j > 0) {
                            cl = prev[j - 1];
                        }
                        if(j < n - 1) {
                            cr = prev[j + 1];
                        }
                        t = prev[j];
                        curr[j] = min(cl, min(cr, t)) + matrix[i][j];
                    }
                    prev = curr;
                }
                int ans = INT_MAX;
                for(auto it: prev) {
                    ans = min(ans, it);
                }
                return ans;
            }
        };
        ```
        </details>

</details>

- <details>
    <summary><a href="https://leetcode.com/problems/minimum-path-sum/description/">64. Minimum Path Sum</a></summary>
    
    - <details>
        <summary>Brute force</summary>

        ```cpp
        class Solution {
        private:
            int help(int ans, int x, int y, int m, int n, vector<vector<int>>& grid) {
                if (x == m - 1 && y == n - 1) {
                    return ans + grid[x][y];
                }
                int s = INT_MAX, ne = INT_MAX;
                if (x + 1 < m) {
                    s = help(ans + grid[x][y], x + 1, y, m, n, grid);
                }
                if (y + 1 < n) {
                    ne = help(ans + grid[x][y], x, y + 1, m, n, grid);
                }
                return s == INT_MAX && ne == INT_MAX ? 0 : min(s, ne);
            }
        public:
            int minPathSum(vector<vector<int>>& grid) {
                int ans = 0;
                int m = grid.size();
                int n = grid[0].size();
                return help(0, 0, 0, m, n, grid);
            }
        };
        ```
        </details>

    - <details>
        <summary>Tabulation</summary>

        ```cpp
        class Solution {
        public:
            int minPathSum(vector<vector<int>>& grid) {
                int m = grid.size();
                int n = grid[0].size();
                vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
                dp[0][0] = grid[0][0];
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        if (i - 1 >= 0) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                        }
                        if (j - 1 >= 0) {
                            dp[i][j] = min(dp[i][j], dp[i][j- 1] + grid[i][j]);
                        }
                    }
                }
                return dp[m - 1][n - 1];
            }
        };
        ```
        </details>

</details>

- <details>
    <summary><a href="https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/">1981. Minimize the Difference Between Target and Chosen Elements</a></summary>
    
    - <details>
        <summary>Brute force</summary>

        ```cpp
        class Solution {
        int ans = INT_MAX;
        private:
            void help(int curr, int i, vector<vector<int>>& mat, int target) {
                if(i == mat.size()) {
                    ans = min(ans, abs(curr - target));
                    return;
                }
                for(int j = 0; j < mat[i].size(); j++) {
                    help(curr + mat[i][j], i + 1, mat, target);
                }
            }
        public:
            int minimizeTheDifference(vector<vector<int>>& mat, int target) {
                int m = mat.size();
                int n = mat[0].size();
                help(0, 0, mat, target);
                return ans;
            }
        };
        ```
        </details>

    - <details>
        <summary>Tabulation</summary>

        ```cpp
        class Solution {
        public:
            int minPathSum(vector<vector<int>>& grid) {
                int m = grid.size();
                int n = grid[0].size();
                vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
                dp[0][0] = grid[0][0];
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        if (i - 1 >= 0) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                        }
                        if (j - 1 >= 0) {
                            dp[i][j] = min(dp[i][j], dp[i][j- 1] + grid[i][j]);
                        }
                    }
                }
                return dp[m - 1][n - 1];
            }
        };
        ```
        </details>

</details>

- <details>
    <summary><a href="https://leetcode.com/problems/generate-parentheses">22. Genenrate Parentheses</a></summary>
    
    - <details>
        <summary>Brute force</summary>

        ```cpp
            class Solution {
            private:
                void help(vector<string>& ans, int l, int r, int n, string curr) {
                    if(l + r == 2 * n) {
                        ans.push_back(curr);
                        return;
                    }
                    if (l < n) {
                        help(ans, l + 1, r, n, curr + "(");
                    }
                    if (r < l) {
                        help(ans, l, r + 1, n, curr + ")");
                    }
                }
            public:
                vector<string> generateParenthesis(int n) {
                    vector<string>ans;
                    help(ans, 0, 0, n, "");
                    return ans;
                }
            };
        ```
        </details>

</details>

- <details>
    <summary><a href="https://leetcode.com/problems/maximum-compatibility-score-sum/">1947. Maximum Compatibility Score Sum</a></summary>
    
    - <details>
        <summary>Backtrack</summary>

        ```cpp
            class Solution {
            int maxi = 0;
            private:
                void help(vector<bool>& vis, vector<vector<int>>& s, vector<vector<int>>& m, int pos, int score) {
                    if (pos >= s.size()) {
                        maxi = max(maxi, score);
                        return;
                    }
                    for(int i = 0; i < m.size(); i++) {
                        if (!vis[i]) {
                            vis[i] = true;
                            help(vis, s, m, pos + 1, score + scor(s[pos], m[i]));
                            vis[i] = false;
                        }
                    }
                }
                int scor(vector<int>& a,vector<int>& b) {
                    int ans = 0;
                    for(int i = 0; i < a.size(); i++) {
                        if (a[i] == b[i]) {
                            ans++;
                        }
                    }
                    return ans;
                }
            public:
                int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
                    int m = students.size();
                    int n = students[0].size();
                    vector<bool>vis(m, false);
                    help(vis, students, mentors, 0, 0);
                    return maxi;
                }
            };
        ```
        
        </details>

    - <details>
        <summary>Brute Force(Permutation)</summary>

        ```cpp
            class Solution {
            public:
                int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
                    int ans = 0;
                    int m = students.size();
                    int n = students[0].size();
                    vector<int>pos;
                    for(int i = 0; i < m; i++) {
                        pos.push_back(i);
                    }
                    do {
                        int cnt = 0;
                        for(int i = 0; i < m; i++) {
                            for(int j = 0; j < n; j++) {
                                if (students[pos[i]][j] == mentors[i][j]) {
                                    cnt++;
                                }
                            }
                        }
                        ans = max(ans, cnt);
                    }while (next_permutation(pos.begin(), pos.end()));
                    return ans;
                }
            };
        ```
        
        </details>

</details>