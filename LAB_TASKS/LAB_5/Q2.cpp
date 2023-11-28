#include<bits/stdc++.h>
using namespace std;
class Node{

    public:

    int data;
    Node* left;
    Node* right;

   Node(int val){
    data=val;
    left=NULL;
    right=NULL;
   } 
};
Node *lca(Node *root, int v1,int v2) {


        vector<Node*>path1;
        vector<Node*>path2;

        Node* tmp=root;
        while(tmp->data!=v1){

            if(tmp->data>v1){
                path1.push_back(tmp);
                tmp=tmp->left;
            }
            else{
                path1.push_back(tmp);
                tmp=tmp->right;
            }


        }
        path1.push_back(tmp);

        Node* tmp2=root;
        while(tmp2->data!=v2){

            if(tmp2->data>v2){
                path2.push_back(tmp2);
                tmp2=tmp2->left;
            }
            else{
                path2.push_back(tmp2);
                tmp2=tmp2->right;
            }


        }

        path2.push_back(tmp2);

        map<Node*,bool>mp;
        int l1=path1.size();
        int l2=path2.size();

        for(int i=0;i<l1;i++){
            mp[path1[i]]=true;
        }
        for(int i=l2-1;i>=0;i--){
            if(mp[path2[i]]){
                return path2[i];
            }
        }

    }



int main(){

    
    Node* root= new Node(4);             //                                 1
    root->left=new Node(2);              //                                / \*
    root->right=new Node(7);              //                              2   3
    root->left->left=new Node(1);        //                              /\*  /\*
     root->left->right=new Node(3);      //                             4  5  6 7
    root->right->left=new Node(6);
  

    cout<<lca(root,1,1)->data<<endl;

    return 0;
}