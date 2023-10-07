  struct Node {
      int data;
      Node *left;
     Node *right;
     Node() : data(0), left(nullptr), right(nullptr) {}
      Node(int x) : data(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
  };
 




#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int sum_subt(Node* root){

    if(root==NULL){
        return 0;
    }
    
    return (sum_subt(root->left)+ root->data + sum_subt(root->right));
    }

    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root)
    {
        
        if(root==NULL){
            return 0;
        }
        else if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        else if(root->left==NULL){
            return max(findLargestSubtreeSum(root->right),sum_subt(root));
        }
        else if(root->right==NULL){
            return max(findLargestSubtreeSum(root->left),sum_subt(root));
        }
        else{
            return max(max(findLargestSubtreeSum(root->left),findLargestSubtreeSum(root->right)),sum_subt(root));
        }
    }
};