/******************************************************************************************************************************************************************
QUESTION: Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

APPROACH: Tree level wise traversal. We push back values of a level in a queue and if the next level exists we push a NULL. We keep on printing the values of
          queue till NULL reaches for one level and add new values to the queue.
 ********************************************************************************************************************************************************************/       
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> a;
        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if(t != NULL)
            {
                a.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            else if(!q.empty())
            {
                v.push_back(a);
                a.resize(0);
                q.push(NULL);                    // this NULL is inserted if further levels exist
            }
        }
        v.push_back(a);                         //to push back the last level elements as for last level NULL willl not be present at the back of queue
        return v;
    }
};
