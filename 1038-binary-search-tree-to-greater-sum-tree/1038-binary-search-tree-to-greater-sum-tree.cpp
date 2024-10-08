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
int ans = 0;
private:
    void help(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        help(root -> right);
        int temp = root -> val;
        root -> val += ans;
        ans += temp;
        help(root -> left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        help(root);
        return root;
    }
};