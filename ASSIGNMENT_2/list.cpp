#include<iostream>
#include "list.h"
#include<stdexcept>
using namespace std;


/* PART B */
/* Stacks using Linked Lists */

/* 
Linked Lists with Sentinels 
[X]<->[7]<->[3]<->[2]<->[X]
The head and tails are dummy elements ([X]) that do not have valid values.
These are called sentinel elements.
*/


    List::List(){
        size=0;
        sentinel_head=new Node(true);
        sentinel_tail=new Node(true);
        if(sentinel_head==nullptr){
                  throw runtime_error("Out of Memory");
                  }
        if(sentinel_tail==nullptr){
                  throw runtime_error("Out of Memory");
                  }
       // sentinel_head->next=sentinel_tail;
        //sentinel_tail->prev=sentinel_head;
    };

    List::~List(){         
        Node* curr=sentinel_head;
        while(curr!=sentinel_tail){
            Node* todelete=curr;
            curr=curr->next;
            delete todelete;
        }
        delete sentinel_tail;
    }

    // Insert an element at the tail of the linked list 
    void List::insert(int v){
        Node* n=new Node(v,sentinel_tail,nullptr);
        if(n==nullptr){          
                  throw runtime_error("Out of Memory");            
        }
        if(size==0){
            sentinel_head->next=n;
            sentinel_tail->prev=n;
            n->next=sentinel_tail;
            n->prev=sentinel_head;
            size++;
        }
        else{
        sentinel_tail->prev->next=n;
        n->prev=sentinel_tail->prev;
        sentinel_tail->prev=n;
        size++;}
    };

    // Delete the tail of the linked list and return the value
    // You need to delete the valid tail element, not the sentinel
    int List::delete_tail(){
            if(!size){
                throw runtime_error("Empty Stack");
            }

            else{
                Node* todelete= sentinel_tail->prev;
                sentinel_tail->prev->prev->next=sentinel_tail;
                sentinel_tail->prev=sentinel_tail->prev->prev;
                int x= todelete->get_value();
                delete todelete;
                size--;
                return x;
            }
   };

    // Return the size of the linked list 
    // Do not count the sentinel elements
    int List::get_size(){
        return size;
    }; 

    // Return a pointer to the sentinel head of the linked list 
    Node* List::get_head(){
        return sentinel_head;
    };



