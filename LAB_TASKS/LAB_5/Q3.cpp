class Solution {
public:



    void inorder(vector<TreeNode*> &v,TreeNode* root){
       if(root==NULL){
            return ;
        }
        inorder(v,root->left);
        v.push_back(root);
        inorder(v,root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {

        vector<TreeNode*>ino;
        inorder(ino,root);
        return (ino[k-1]->val);
    
    }
};