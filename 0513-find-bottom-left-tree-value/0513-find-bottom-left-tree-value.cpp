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
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false)
        {
            int n = q.size();
            ans = q.front()->val;
            while(n--)
            {
                auto it = q.front();
                q.pop();
                if(it->left != nullptr)
                {
                    q.push(it->left);
                }
                if(it->right != nullptr)
                {
                    q.push(it->right);
                }
            }
        }
        return ans;
    }
};