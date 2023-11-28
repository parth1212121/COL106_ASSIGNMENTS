#include<bits/stdc++.h>
using namespace std;
class ListNode{                           // O(1)-->Memory...
                                      // O(n)-->Time.....      
public:
    int val;
    ListNode* next;
    ListNode(int v){
        val=v;
        next=nullptr;        
    }
};

ListNode* reverse(ListNode* &head){             // reverse of linked list......[in place]


   if(head->next==NULL){
        return head;
    }

    ListNode* p=NULL;
    ListNode* curr=head;
    ListNode* n=NULL;

    while(curr!=NULL){

        n=curr->next;


        curr->next=p;


        p=curr;
        curr=n;
        if(n){
        n=n->next;}

    }

    return p;
}

int size(ListNode* head){
    ListNode* tmp=head;
    int cnt=0;
    while(tmp!=nullptr){
        tmp=tmp->next;
        cnt++;
    }
    return cnt;  
}

bool isPalindrome(ListNode* head){

int n=size(head);
bool ans=true;

    ListNode* tmp=head;
    int cnt=0;
    while(cnt!=(n/2-1)){
        tmp=tmp->next;
        cnt++;
    }
    ListNode* kk=reverse(tmp->next);
    while(kk!=nullptr){
        if(head->val!=kk->val){
            ans=false;
            break;
        }
        head=head->next;
        kk=kk->next;
    }
return ans;
}

int main(){


    ListNode* n1=new ListNode(1);
    ListNode* n2=new ListNode(2);
    ListNode* n3=new ListNode(3);
    
    ListNode* n5=new ListNode(2);
    ListNode* n6=new ListNode(7);

    n1->next=n2;
    n2->next=n3;
    n3->next=n5;
    
    n5->next=n6;

    cout<<isPalindrome(n1)<<endl;

}