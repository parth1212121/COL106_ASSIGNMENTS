#include<iostream>
#include<stdexcept>
#include "stack_a.h"
using namespace std;

        Stack_A::Stack_A(){
            size=0;
        }
        void Stack_A:: push(int data){
           
            if(size>=1024){
                throw runtime_error("Stack Full");
            }
            else{
                stk[size]=data;
                size++;
            }
        }
        int Stack_A:: pop(){
           
            if(size<=0){
                throw runtime_error("Empty Stack");
            }
            else{
                // int y=size;
                size--;
                return stk[size];
            }

        }
        int Stack_A:: get_element_from_top(int idx){               // the user asks as per 0 indexing...
            if(idx>=size){
                throw runtime_error("Index out of range");
            }
            else{
                return stk[size-1-idx];
            }
        }
        int Stack_A:: get_element_from_bottom(int idx){
            if(idx>=size){
                throw runtime_error("Index out of range");
            }
            else{
                return stk[idx];
            }
        }

        void Stack_A:: print_stack(bool top){
            if(size==0){
                return;
            }
            else if(top){
                int x=size-1;
                while(x>=0){
                        cout<<stk[x]<<" ";
                        x--;
                }cout<<"\n";
            }
            else if(!top){
                int x=0;
                while(x<size){
                    cout<<stk[x]<<" ";
                    x++;
                }cout<<"\n";
            }
        }

        int Stack_A:: add(){
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
            else{
                int x=pop();
                int y=pop();
                push(x+y);
               
                return (x+y);
            }
        }

        int Stack_A:: subtract(){
       
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
            else{
                int x=pop();
                int y=pop();
               
                push(y-x);
              
                return (y-x);
            }
        }
        int Stack_A:: multiply(){
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
            else{
                int x=pop();
                int y=pop();
                push(x*y);
                return (x*y);
            }
        }
        int Stack_A:: divide(){
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
             else if(get_element_from_top(0)==0){
                 throw runtime_error("Divide by Zero Error");
             }
            else{
                
                int x=pop();
                int y=pop();
                if (x*y>0){
                push(y/x);
                
                return (y/x);}
                else {
                    x = abs(x);
                    y = abs(y);
                    if (y%x == 0) {
                        int z = y/x;
                        push(-1*z);
                        return -1*z;
                    }
                    else{
                        int z = y/x;
                        push(-1*(z) -1);
                        return -1*(z) -1;
                    }
                }
            }
        }
        int* Stack_A:: get_stack(){
            return stk;
        }
        int Stack_A:: get_size(){
            return size;
        }


