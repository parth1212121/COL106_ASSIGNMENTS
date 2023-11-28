#include<iostream>
#include<unordered_map>
using namespace std;
                                                                                // DLL and unordered_maps.....
class Node{
       public:
       int val;
       int key;
       Node* next;
       Node* prev;
        Node(int value,int ke,Node*n=NULL){
            val=value;
            key=ke;
            next=NULL;
            prev=NULL;
}
};

unordered_map<int,Node*>mp;


//  Doubly Linked List...       [ because we need to access the end element in O(1).]


void insertAthead(int key,int value,Node* &head, Node* &tail){          // O(1).

    Node* n=new Node(value,key);
    head->next->prev=n;
    n->next=head->next;
    head->next=n; 
    n->prev=head;
    mp[key]=n;
   

}




void deleteAtend(Node* &head, Node* &tail){             
    if(head->next==tail){
        return;
    }

    Node* todelete=tail->prev;              // O(1).
    tail->prev=tail->prev->prev;
    tail->prev->next=tail;
    delete todelete;  

}


void deletion(Node* n){                   // given that x is present in the linked list..

    Node* todelete=n;                       //O(1).
    n->next->prev=n->prev;
    n->prev->next=n->next;
    delete todelete;
}

int end_value(Node* head, Node* tail){           // O(1).
    if(head->next==tail){
        return -1;

    }
    return tail->prev->key;
}


// LRUCache..



class LRUCache {
        int size;
        int cap;
        
        unordered_map<int,bool>present;                                          // MARK X in HASH TABLE........
        
        Node* head=new Node(-1,-1);
        Node* tail=new Node(-1,-2);
       

    public:
        LRUCache(int capacity) {
        size=0;
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        }

        int get(int key) {
            if(!present[key]){
                return -1;
            }
            else{                           // Bring it to the top of the Cache.
                int r=mp[key]->val;
                deletion(mp[key]);                  // O(1)
                insertAthead(key,r,head,tail);      // O(1)
                return r;
            }       
        }
    
        void put(int key, int value) {
            if(present[key]){               // Bring it to the top of the Cache.
                deletion(mp[key]);                  // O(1)
                insertAthead(key,value,head,tail);                
                return;
            }
            if(size==cap){
                present[end_value(head,tail)]=false;              // Free cahche space.......                                          
                deleteAtend(head,tail);                          // o(1)
                size--;
            }            
        
            insertAthead(key,value,head,tail);          
            present[key]=true;
            size++;
            return;
        }      
};

