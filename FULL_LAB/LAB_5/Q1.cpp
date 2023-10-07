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
    int idx=0;
    int search(vector<int> inorder,int start,int end,int current){
    for(int i=start;i<=end;i++){
        if(inorder[i]==current){
            return i;
        }
    }
    return -1;                       
}
    TreeNode* comp(vector<int>& preorder,vector<int>& inorder,int start,int end){

    
    if(start>end){
        return nullptr;
    }

    int curr=preorder[idx];
    idx++;
       
    TreeNode* node=new TreeNode(curr);
    if(start==end){
        return node;
    }

    int pos=search(inorder,start,end,curr);

    node->left=comp(preorder,inorder,start,pos-1);
    node->right=comp(preorder,inorder,pos+1,end);

    return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
           int x=preorder.size();
            return comp(preorder,inorder,0,x-1);      
    }


    };
Console
