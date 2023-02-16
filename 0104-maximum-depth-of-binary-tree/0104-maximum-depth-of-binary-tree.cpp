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
    int ans = INT_MIN;
    void dfs(TreeNode* root, int comp)
    {
        if(root ==NULL)
        {
            return;
        }
        ans = max(ans,comp);
        dfs(root->left,comp+1);
        dfs(root->right,comp+1);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root ==NULL)
        {
            return 0;
        }
        dfs(root,1);
        return ans;
    }
};