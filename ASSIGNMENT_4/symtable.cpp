/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"



SymEntry* find(SymEntry* root,string k){

    SymEntry* tmp=root;
    while(tmp!=nullptr){
        if(tmp->key==k){
            return tmp;
        }
        else if(tmp->key<k){
            tmp=tmp->right;
        }
        else{
            tmp=tmp->left;      
    }
}
}

// deletion....

SymEntry* Suc(SymEntry* n){

    SymEntry* tmp=n->right;
    while(tmp->left!=NULL){
        tmp=tmp->left;
    }
    return tmp;

}

SymEntry* Pre(SymEntry* n){

    SymEntry* tmp=n->left;
    while(tmp->right!=NULL){
        tmp=tmp->right;
    }
    return tmp;

}

SymEntry* remove_leaf(SymEntry* &root,SymEntry* &n){                 // neat_deleting.......

    if(root->key==n->key){
        return NULL;            
    }
    else if(root->key>n->key){
        root->left=remove_leaf(root->left,n);
        return root;
    }
    else{
        root->right=remove_leaf(root->right,n);
        return root;
    }

}

SymEntry*  delete_it(SymEntry* &root,SymEntry* &n){
  
    if(n->left==NULL && n->right==NULL){
       
        return  remove_leaf(root,n);            
    }     
    else if(n->right==NULL){

        SymEntry* to_del=Pre(n);
        string cpy_str=to_del->key;
        UnlimitedRational* cpy_rational=to_del->val;
        delete_it(n,to_del);
        n->key=cpy_str;
        n->val=cpy_rational;           
        return root;        
    
    }

    else{

        SymEntry* to_del=Suc(n);       
        string cpy_str=to_del->key;
        UnlimitedRational* cpy_rational=to_del->val;
        delete_it(n,to_del);
        n->key=cpy_str;
        n->val=cpy_rational;           
        return root;     

    }
}

SymEntry* deletion(SymEntry* root, string key) {
   
    SymEntry* to_rem=find(root,key);    
    return delete_it(root,to_rem);
   
}

SymbolTable:: SymbolTable(){

    size=0;
    root=NULL;
}

SymbolTable:: ~SymbolTable(){           // Check tis once............
    delete root;
}

SymEntry* SymbolTable:: get_root(){
    return root;
}

int SymbolTable:: get_size(){
    return size;
}

//Insertion....

void insert_help(SymEntry* &root,SymEntry* &v){                   
                                                     // Worst Case -->O(n).
                                                  // Average case--> O(log n)

    // Inserts SymEntry v into the BST.
    //Assumes that v->left and v->right are null
    // Assumes that v->key is not present in TREE.

    if(root==NULL){     
     
        root=v;
        return ;
    }
    if(v->key<root->key){
        
        // Insert on the left side of the root.
        if(root->left==0){
            // We have found the right place to insert.
            root->left=v;           
        }
        else{
            insert_help(root->left,v);
        }
  }
  else{

     // Insert on the right side of the root.
        if(root->right==0){
            // We have found the right place to insert.
            root->right=v;
            
        }
        else{
            insert_help(root->right,v);
        }
  }

}

void SymbolTable::insert(string k, UnlimitedRational* v){
    
    SymEntry* n=new SymEntry(k,v);
    insert_help(root,n);
    size++;
    return;
}

UnlimitedRational* SymbolTable::search(string k){

    SymEntry* tmp=root;
    while(tmp!=nullptr){
        if(tmp->key==k){
            return tmp->val;
        }
        else if(tmp->key>k){
            tmp=tmp->left;
        }
        else 
        {
            tmp=tmp->right;
        }
    }

    return nullptr;         // Error condtions..(Not of use in assignment..)

}

void SymbolTable::remove(string k){
    size--;
    deletion(root,k);
}

// int main()
// {
//     UnlimitedInt* p1=new UnlimitedInt("-2");
//     UnlimitedInt* q1=new UnlimitedInt("5");
//     UnlimitedRational* r1=new UnlimitedRational(p1,q1);

//     UnlimitedInt* p2=new UnlimitedInt("-1");
//     UnlimitedInt* q2=new UnlimitedInt("10");
//     UnlimitedRational* r2=new UnlimitedRational(p2,q2);

//     UnlimitedInt* p3=new UnlimitedInt("1");
//     UnlimitedInt* q3=new UnlimitedInt("10");
//     UnlimitedRational* r3=new UnlimitedRational(p3,q3);

//     UnlimitedInt* p4=new UnlimitedInt("8");
//     UnlimitedInt* q4=new UnlimitedInt("9");
//     UnlimitedRational* r4=new UnlimitedRational(p4,q4);

//     UnlimitedInt* p8=new UnlimitedInt("9");
//     UnlimitedInt* q8=new UnlimitedInt("11");
//     UnlimitedRational* r8=new UnlimitedRational(p8,q8);

//     SymbolTable* T = new SymbolTable();
   
//     T->insert("m",r1);
//    // cout<<T->get_root()->val->get_frac_str()<<endl;
//     T->insert("e",r2);
//     T->insert("q",r3);
//     T->insert("a",r4);
//     T->insert("p",r4);
//     T->insert("t",r4);
//     T->insert("s",r4);
//     T->insert("u",r4);

//     cout<<T->get_root()->left->key<<endl;
//     cout<<T->get_root()->left->left->key<<endl;
//     cout<<T->get_root()->right->key<<endl;
//     cout<<T->get_root()->right->left->key<<endl;
//     cout<<T->get_root()->right->right->key<<endl;
//     cout<<T->get_root()->right->right->left->key<<endl;
//     cout<<T->get_root()->right->right->right->key<<endl;

//     T->remove("m");


//     cout<<"-----after removal"<<endl;


//     cout<<T->get_root()->key<<endl;
//     cout<<T->get_root()->left->key<<endl;
//     cout<<T->get_root()->left->left->key<<endl;
//     cout<<T->get_root()->right->key<<endl;
//     cout<<T->get_root()->right->left->key<<endl;
//     cout<<T->get_root()->right->right->key<<endl;
//     //cout<<T->get_root()->right->right->left->key<<endl;
//     cout<<T->get_root()->right->right->right->key<<endl;

// }



















