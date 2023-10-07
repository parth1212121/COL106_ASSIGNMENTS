#include<bits/stdc++.h>
using namespace std;                 // Better see the Complete_AVL.cpp


typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; 


unordered_map<node*,node*>parent;
int height(node* n){
    
    if(n==NULL){
        return -1;
    }
 
    return (max(height(n->left),height(n->right))+1);
    

}

bool is_balanced(node* n){
    if(n==NULL){
        return true;
    }
    else{
        if(abs(height(n->left)-height(n->right))<=1){
            return true;
        }
        return false;
    }
}


void insert_raw(node* &root,node* &v){                   
    
                                                  // Worst Case -->O(n).
                                                  // Average case--> O(log n)
    // Inserts node v into the BST.
    //Assumes that v->left and v->right are null
    // Assumes that v->key is not present in TREE.
    if(root==NULL){
        return ;
    }
    if(v->val<root->val){
        // Insert on the left side of the root.
        if(root->left==0){
            // We have found the right place to insert.
            root->left=v;
            parent[v]=root;
        }
        else{
            insert_raw(root->left,v);
        }
  }
  else{
     // Insert on the right side of the root.
        if(root->right==0){
            // We have found the right place to insert.
            root->right=v;
            parent[v]=root;
        }
        else{
            insert_raw(root->right,v);
        }
  }
}

void balance(node* &root, node* &n){


    node* tmp=n;
    while(is_balanced(parent[tmp])){
        tmp=parent[tmp];
        if(tmp==root){
            return;
        }
    }

    // Case_1

    if((parent[tmp]->left==tmp) && (n->val<tmp->val)){
        
        node* a=tmp;
        node* b=parent[tmp];
                                              // All connections.....
    // cout<<b->val<<endl;
    //  cout<<a->val<<endl;
     if(b==root){
        parent[a]=NULL;
     }
     else{
        parent[a]=parent[parent[a]];}
    //  //   cout<<(b==root)<<endl;
         
    //     if(b!=root){
            
    //     if(parent[b]->left==b){
    //     parent[b]->left=a;}
    //     else if(parent[b]->right==b){
    //         parent[b]->right=a;
    //     }
    //     }
          if(b==root){
    //         //cout<<"hi"<<endl;
            root=a;
         }
       // cout<<root->val<<endl;
       // node* t2=a->right;
        

        ///a->right=b;   
        //cout<<root->right->val<<endl;     
       // cout<<root->left->val<<endl;    
        //parent[b]=a;
        
       
        
       // b->left=t2; 
        // if(t2!=NULL){                         // Important!!!!
        // parent[t2]=b;}
        
       
    }

    // Case_2

    if(parent[tmp]->right==tmp && (n->val)>(tmp->val)){


            node* a=tmp;
            node* b=parent[tmp];

            parent[a]=parent[parent[a]];
            if(b!=root){
            if(parent[b]->left==b){
            parent[b]->left=a;}
            else if(parent[b]->right==b){
                parent[b]->right=a;
            }}

            node* t1=a->left;

            a->left=b;
            parent[b]=a;

            b->right=t1;
            if(t1!=NULL){
                parent[t1]=b;
            }
    }


    // Case_3

    if(parent[tmp]->left==tmp && n->val>tmp->val){
            
            node* a=tmp;
            node* b= parent[tmp];
            node* d=tmp->right;
       

            parent[d]=parent[b];
            
            if(b!=root){
            if(parent[b]->left==b){
                parent[d]->left=d;
            }
            else if(parent[b]->right==b){
                parent[d]->right=d;
            }}

            parent[a]=d;

            node* t2a=d->left;
            node* t2b=d->right;

            d->left=a;

            a->right=t2a;

            if(t2a!=NULL){
            parent[t2a]=a;}
            
            parent[b]=d;
            d->right=b;
            b->left=t2b;

            if(t2b!=NULL){
            parent[t2b]=b;}
    
    }

    // Case_4

    if(parent[tmp]->right==tmp && n->val<tmp->val){
            
            node* a=tmp;
            node* b= parent[tmp];
            node* d=tmp->left;
       
            parent[d]=parent[b];
            if(b!=root){
            if(parent[b]->left==b){
                parent[d]->left=d;
            }
            else if(parent[b]->right==b){

                parent[d]->right=d;
            }}

            parent[a]=d;

            node* t2a=d->left;
            node* t2b=d->right;

            d->left=b;

            b->right=t2a;

            if(t2a!=NULL){
            parent[t2a]=b;}
            
            parent[b]=d;
            d->right=a;
            a->left=t2b;

            if(t2b!=NULL){
            parent[t2b]=a;}    
    }
}


node * insert(node * &root,int val)
{
 
    node *n=new node;
    n->val=val;
    n->left=NULL;
    n->right=NULL;
    insert_raw(root,n);
    balance(root,n);  
    return root;

}


int main(){

    node* root=new node;
   
    root->val=4;
   
    root->left=NULL;
    root->right=NULL;
  
    insert(root,3);


    insert(root,2);
    // insert(root,5);
    // insert(root,6);
    cout<<root->val<<endl;
   // cout<<root->right->val<<endl;
    //  cout<<root->right->val<<endl;
    // cout<<root->left->left->val<<endl;
    // // cout<<root->right->left->val<<endl;
    //  cout<<root->right->right->val<<endl;

}