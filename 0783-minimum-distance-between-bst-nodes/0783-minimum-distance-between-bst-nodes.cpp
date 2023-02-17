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
    int prev = INT_MIN;
private:
    void pre(TreeNode* root, int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        pre(root->left, ans);
        if(prev == INT_MIN)
        {
            
        }
        else{
            ans = min(ans, root->val - prev);
        }
        prev = root->val;
        pre(root->right, ans);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        pre(root, ans);
        return ans;
    }
};