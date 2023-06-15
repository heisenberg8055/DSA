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
    int maxLevelSum(TreeNode* root) {
        int ans = -1;
        int lvl = 1;
        int comp = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty() == false)
        {
            int sum = 0;
            int n = q.size();
            for(int i =0;i<n;i++)
            {
                auto it = q.front();
                q.pop();
                sum += it->val;
                if(it->left)
                {
                    q.push(it->left);
                }
                if(it->right)
                {
                    q.push(it->right);
                }
            }
            if(sum > comp)
            {
                comp = sum;
                ans = lvl;
            }
            lvl++;
        }
        return ans;
    }
};