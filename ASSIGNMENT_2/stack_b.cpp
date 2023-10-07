#include<iostream>
#include<stdexcept>
#include "stack_b.h"

using namespace std;

/* PART B */
/* Dynamic Stacks */


    // Constructor
    Stack_B::Stack_B(){

        size=0;
        capacity=1024;
        stk=new int[capacity];

    };

    // Destructor
    Stack_B::~Stack_B(){
        delete stk;
    };

    void Stack_B:: push(int data){
            if(size>=capacity){
                int* stk_new;
                stk_new=new int[2*capacity];
                if(stk_new==nullptr){
                    throw runtime_error("Out of Memory");
                }
                for(int i=0;i<capacity;i++){                     // Doubled the size of array.....
                    stk_new[i]=stk[i];
                }
                delete stk;
                stk=stk_new;                               /// see the delete condition......
                capacity*=2;
           }
                stk[size]=data;
               
                size++;
    };

    int Stack_B:: pop(){
       
            if(size<=0){
                throw runtime_error("Empty Stack");
            }
            
            else{
                int y=size; 
                int res=stk[size-1];
               
                size--;
                if(size<=capacity/4){
                  
                    int* new_stk;
                    new_stk=new int[capacity/4];
                    if(new_stk==nullptr){
                    throw runtime_error("Out of Memory");
                }
                    for(int i=0;i<(capacity/4);i++){                     // Doubled the size of array.....
                    new_stk[i]=stk[i];
                }
                delete stk;
                stk=new_stk;
                capacity=capacity/4;                
               }              
                return res;
            }
    };

    int Stack_B:: get_element_from_top(int idx){               // the user asks as per 0 indexing...
            if(idx>=size){
                throw runtime_error("Index out of range");
            }
            else{
                return stk[size-1-idx];
            }
        };

    int Stack_B::get_element_from_bottom(int idx){
            if(idx>=size){
                throw runtime_error("Index out of range");
            }
            else{
                return stk[idx];
            }
        };

    void Stack_B:: print_stack(bool top){
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
        };

    int Stack_B::add(){
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
            else{
                int x=pop();
                int y=pop();
                push(x+y);
               
                return (x+y);
            }
        };
    int Stack_B::subtract(){
       
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
            else{
                int x=pop();
                int y=pop();
               
                push(y-x);
              
                return (y-x);
            }
        };

    int Stack_B::multiply(){
            if(size<2){
                throw runtime_error("Not Enough Arguments");
            }
            else{
                int x=pop();
                int y=pop();
                push(x*y);
                return (x*y);
            }
        };

    int Stack_B::divide(){
            if(size<2){
                throw runtime_error("Not enough Arguments");
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
        }; 

    int* Stack_B:: get_stack(){      // Get a pointer to the array

            return stk;
        };
    int Stack_B::get_size(){      // Get the size of the stack
            return size;
        };

