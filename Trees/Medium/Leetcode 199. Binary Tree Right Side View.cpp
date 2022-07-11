/****************************************************************************************************************************************************************
QUESTION: Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

APPROACH: Using queue data struvture and level order traversal we print or store the last element of queue for a particular level to get thr rightmost node in
          that level.
**************************************************************************************************************************************************************/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root == NULL)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0 ; i< n; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(i == n-1)
                    v.push_back(cur->val) ;
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
            }
            
        }
        return v;
    }
};
