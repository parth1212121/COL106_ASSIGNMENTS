#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* nxt;
    Node(int v){
        val=v;
        nxt=nullptr;        
    }
};



///*****IMPORTANT********

Node* reverse(Node* head){             // reverse of linked list......[in place]

   if(head->nxt==NULL){
        return head;
    }

    Node* p=NULL;
    Node* curr=head;
    Node* n=NULL;

    while(curr!=NULL){

        n=curr->nxt;


        curr->nxt=p;


        p=curr;
        curr=n;
        if(n){
        n=n->nxt;}

    }

    return p;


}





///*****IMPORTANT********




void display(Node* head){

    Node* t=head;
    while(t!=nullptr){
        cout<<t->val<<" ";
        t=t->nxt;
    }
    cout<<"\n";

}

int main(){

    Node* n1=new Node(1);
    Node* n2=new Node(2);
    Node* n3=new Node(3);
    Node* n4=new Node(4);
    Node* n5=new Node(5);
    Node* n6=new Node(6);

    n1->nxt=n2;
    n2->nxt=n3;
    n3->nxt=n4;
    n4->nxt=n5;
    n5->nxt=n6;
   // cout<<n1->val<<endl;
    Node* head=reverse(n1);
    cout<<head->val<<endl;
    display(head);

}