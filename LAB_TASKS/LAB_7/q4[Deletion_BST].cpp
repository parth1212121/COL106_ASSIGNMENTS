#include<bits/stdc++.h>
using namespace std;

 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 



    bool is_there(TreeNode* root, int key){

        if(root==NULL){
            return false;
        }

        if(root->val==key){
            return true;
        }
        else if(root->val<key){
            return is_there(root->right,key);
        }
        else{
            return is_there(root->left,key);
        }

    }

    TreeNode* find(TreeNode* root, int key){        // Sure that the key is there....
    
     
        if(root->val==key){
            return root;
        }
        else if(root->val<key){
            return find(root->right,key);
        }
        else{
            return find(root->left,key);
        }

    }

    TreeNode* Suc(TreeNode* n){

        TreeNode* tmp=n->right;
        while(tmp->left!=NULL){
            tmp=tmp->left;
        }
        return tmp;

    }

    TreeNode* Pre(TreeNode* n){

        TreeNode* tmp=n->left;
        while(tmp->right!=NULL){
            tmp=tmp->right;
        }
        return tmp;

    }

    TreeNode* remove_leaf(TreeNode* &root,TreeNode* &n){                 // neat_deleting.......

        if(root->val==n->val){
            return NULL;            
        }
        else if(root->val>n->val){
            root->left=remove_leaf(root->left,n);
            return root;
        }
        else{
            root->right=remove_leaf(root->right,n);
            return root;
        }

    }

    TreeNode*  deletion(TreeNode* &root,TreeNode* &n){

       if(n->left==NULL && n->right==NULL){
          return  remove_leaf(root,n);            
       }     
       else if(n->right==NULL){

           TreeNode* to_del=(n->left);
           int cpy=to_del->val;
           deletion(n,to_del)->val=cpy;           
           return root;        
        
       }

       else{

           TreeNode* to_del=Suc(n);
           int cpy=to_del->val;
           deletion(n,to_del)->val=cpy;
           return root;

       }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(is_there(root,key)){
        TreeNode* to_rem=find(root,key);
        return deletion(root,to_rem);
        }
        else{
        return root;
        }      
    }



int main(){


    TreeNode* n1=new TreeNode(9);
    TreeNode* n2=new TreeNode(34);
    TreeNode* n3=new TreeNode(8);
    TreeNode* n4=new TreeNode(7);
    TreeNode* n5=new TreeNode(6);
    TreeNode* n6=new TreeNode(5);
    TreeNode* n7=new TreeNode(4);

    n1->right=n2;
    n1->left=n3;
    n3->left=n4;
    n4->left=n5;
    n5->left=n6;
    n6->left=n7;

    deleteNode(n1,6);

    cout<<n1->left->left->left->val<<endl;







        

















}