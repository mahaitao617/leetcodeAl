/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Helper(TreeNode* root,vector<vector<int>>&res,int h)
    {
        if(!root)return ;
        if(res.size()<h+1)
        {
            vector<int>tmp;
            tmp.push_back(root->val);
            res.push_back(tmp);
        }
        else
        {
            res[h].push_back(root->val);
        }
        Helper(root->left,res,h+1);
        Helper(root->right,res,h+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)return result;
        Helper(root,result,0);
        return result;
        
    }
};
