/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void trav(TreeNode* root, vector<int>& arr) {
        if(root == nullptr) {
            return;
        }
        trav(root -> left, arr);
        arr.push_back(root -> val);
        trav(root -> right, arr);
    }
    TreeNode* construct(vector<int>& arr, int l, int r, int n) {
        printf("%d %d\n", l, r);
        int mid = l + ((r - l) / 2);
        if(l == r) {
            return new TreeNode(arr[mid]);
        }
        if(l < 0 || r >= n || l > r) {
            return nullptr;
        }
        return new TreeNode(arr[mid], construct(arr, l, mid - 1, n), construct(arr, mid + 1, r, n));
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>val;
        trav(root, val);
        int n = val.size();
        TreeNode* ans = construct(val, 0, n - 1, n);
        return ans;
    }
};