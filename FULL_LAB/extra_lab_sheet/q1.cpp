
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>v;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*> q;
        
        q.push(root);
        vector<int>v1;
        
        v1.push_back(root->val);
        v.push_back(v1);
        q.push(NULL);
        v1.clear();
        while(!q.empty()){
            if(q.front()){
                TreeNode* t =q.front();
                
                if(t->left){
                q.push(t->left);
                v1.push_back(t->left->val);
                }
                if(t->right){
                q.push(t->right);
                v1.push_back(t->right->val);
                }    
               
                q.pop();
            }
            else{
                q.pop();
                if(q.empty()){
                    break;
                }
                else{
                    if(v1.size()){           
                    v.push_back(v1);}
                    q.push(NULL);    
                    v1.clear();           
                }
            }
        }

    return v;
    }
};