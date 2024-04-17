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
    void dfs(TreeNode* root, string temp, string &ans)
    {
        if(root == nullptr)
        {
            return;
        }
        temp += 'a' + root -> val;
        if(root ->left == NULL && root -> right == NULL)
        {
            reverse(temp.begin(), temp.end());
            ans = min(ans, temp);
        }
        dfs(root -> left, temp, ans);
        dfs(root -> right, temp, ans);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans (8501, 'z');
        dfs(root, "", ans);
        return ans;
    }
};