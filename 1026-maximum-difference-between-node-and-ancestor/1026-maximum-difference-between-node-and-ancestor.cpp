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
class Solution{
private:
    void trav(TreeNode* root, int &ans, int mini, int maxi)
    {
        if(root == NULL)
        {
            return;
        }
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        if(mini!= 5002 && maxi)
        {
            ans = max(ans, abs(maxi - mini));
        }
        trav(root->left,ans,mini,maxi);
        trav(root->right,ans,mini,maxi);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        trav(root,ans,5002,0);
        return ans;
    }
};