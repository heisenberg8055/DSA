# Sliding Window

## Problems

- <details>
    <summary><a href="https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/">2799. Count Complete Subarrays in an Array</a></summary>

    ```c++
    class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
            int k = unordered_set<int>(nums.begin(), nums.end()).size();
            int i = 0;
            int ans = 0;
            unordered_map<int, int> count;
            for(int j = 0; j < n; j++) {
                k -= count[nums[j]]++ == 0;
                while(k == 0) {
                    k += --count[nums[i++]] == 0;
                }
                ans += i;
            }
            return ans;
        }
    };
    ```
</details>

- <details>
    <summary><a href="https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/"> 2779. Maximum Beauty of an Array After Applying Operation </a></summary>

    ```c++
    class Solution {
    public:
        int maximumBeauty(vector<int>& nums, int k) {
            int ans = 0;
            int n = nums.size();
            int l = 0, r = 0;
            sort(nums.begin(), nums.end());
            while(r < n) {
                if(nums[r] - nums[l] <= 2 * k) {
                    ans = max(ans, r - l + 1);
                    r++;
                } else {
                    l++;
                }
            }        
            return ans;
        }
    };
    ```
</details>

- <details>
    <summary><a href="https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/description/"> 2730. Find the Longest Semi-Repetitive Substring </a></summary>

    ```c++
    class Solution {
    public:
        int maximumBeauty(vector<int>& nums, int k) {
            int ans = 0;
            int n = nums.size();
            int l = 0, r = 0;
            sort(nums.begin(), nums.end());
            while(r < n) {
                if(nums[r] - nums[l] <= 2 * k) {
                    ans = max(ans, r - l + 1);
                    r++;
                } else {
                    l++;
                }
            }        
            return ans;
        }
    };
    ```
</details>
