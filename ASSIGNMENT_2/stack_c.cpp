#include<iostream>
#include<string>
#include <stdexcept>
#include "stack_c.h"
using namespace std;



/* PART B */
/* Stacks using Linked Lists */

    // Constructor
    Stack_C::Stack_C(){
       stk=new List();        
       if(stk==nullptr){      
          throw runtime_error("Out of Memory");
                 }
       
    };

    // Destructor
    Stack_C::~Stack_C(){
        delete stk;
    };

    void Stack_C:: push(int data){
        //cout<<data<<endl;
        stk->insert(data);
    };

    int Stack_C::pop(){
      //  cout<< (stk->delete_tail())<<endl;
        return (stk->delete_tail());

    };

    int Stack_C::get_element_from_top(int idx){

        int size=stk->get_size();
        Node* curr=stk->get_head();
        if(idx>=size){
            throw runtime_error("Index out of range");
        }
        else{
            for(int i=0;i<(size-idx);i++){
                curr=curr->next;
            }
            return curr->get_value();
        }
    };

    int Stack_C::get_element_from_bottom(int idx){

            int size=stk->get_size();
        Node* curr=stk->get_head();
        if(idx>=size){
            throw runtime_error("Index out of range");
        }
        else{
                for(int i=0;i<idx+1;i++){
                    curr=curr->next;
                }
                return curr->get_value();
        }
    };

    void Stack_C::print_stack(bool top_or_bottom){

            int size=stk->get_size();
             if(size==0){
                return;
            }
            
            if(top_or_bottom==true){

                Node* curr=stk->get_head();
                while(curr->next!=nullptr){
                    curr=curr->next;
                }
                while(curr->prev!=nullptr){
                    cout<<curr->get_value()<<" ";
                    curr=curr->prev;
                }cout<<endl;
            }
            else{
                Node* curr=stk->get_head();
                while(curr->next!=nullptr){
                    cout<<curr->get_value()<<" ";
                    curr=curr->next;
                }cout<<endl;
           }
    };

    int Stack_C::add(){

            int size=stk->get_size();
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
            else{
                int x=stk->delete_tail();
                int y=stk->delete_tail();
                stk->insert(x+y);

                return (x+y);
            }
    };

    int Stack_C::subtract(){

            int size=stk->get_size();
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
            else{
                int x=stk->delete_tail();
                int y=stk->delete_tail();
                stk->insert(y-x);

                return (y-x);
            }
    };;

    int Stack_C::multiply(){

            int size=stk->get_size();
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
            else{
                int x=stk->delete_tail();
                int y=stk->delete_tail();
                stk->insert(x*y);

                return (x*y);
            }
    };;

    int Stack_C::divide(){

            int size=stk->get_size();
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
            else if(get_element_from_top(0)==0){
                 throw runtime_error("Divide by Zero Error");
             }
            else{
                int x=stk->delete_tail();
                int y=stk->delete_tail();
   
                 if (x*y>0){
                stk->insert(y/x);
                
                return (y/x);}
                
                else {
                    x = abs(x);
                    y = abs(y);
                    if (y%x == 0) {
                        int z = y/x;
                        stk->insert(-1*z);
                        return -1*z;
                    }
                    else{
                        int z = y/x;
                        stk->insert(-1*(z) -1);
                        return -1*(z) -1;
                    }
                }
            }
    };

    List* Stack_C::get_stack(){
        return stk;
    }; // Get a pointer to the linked list representing the stack

    int Stack_C::get_size(){
        return stk->get_size();
    }; // Get the size of the stack

