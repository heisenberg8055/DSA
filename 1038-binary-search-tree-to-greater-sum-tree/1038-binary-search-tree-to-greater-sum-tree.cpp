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
int s = 0;
private:
    void help(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        help(root -> left);
        int temp = root -> val;
        root -> val = s;
        s -= temp;
        help(root -> right);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                auto it = q.front();
                q.pop();
                s += it -> val;
                if(it -> left)
                {
                    q.push(it -> left);
                }
                if(it -> right)
                {
                    q.push(it -> right);
                }
            }
        }
        help(root);
        return root;
    }
};