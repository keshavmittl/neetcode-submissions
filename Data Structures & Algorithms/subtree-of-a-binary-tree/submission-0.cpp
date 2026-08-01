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
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->val == q->val && isSameTree(p->left , q->left) && isSameTree(p->right , q->right) )
        return true;

        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false ;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr= st.top();
            st.pop();

            if(isSameTree(curr ,subRoot))return true;

            if(curr->right)st.push(curr->right);
            if(curr->left)st.push(curr->left);
        }
        return false; 
    }
};
