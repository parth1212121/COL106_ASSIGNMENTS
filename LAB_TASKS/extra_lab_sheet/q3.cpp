
 /// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include<bits/stdc++.h>
using namespace std;
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