#include<iostream>
#include<stack>
using namespace std;

// Leetcode template.....


class MyQueue {
     stack<int>st1;
     stack<int>st2;
public:
    MyQueue() {       
    }
    void push(int x) {
            st1.push(x);
                    }
    
    int pop() {
        if(st1.empty() && st2.empty()){
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            else{
                if(st2.empty()){
                    while(!st1.empty()){
                           st2.push(st1.top());
                            st1.pop();
                   }
                }
                int h=st2.top();              
                st2.pop();
                return h;
            }
        
    }
    
    int peek() {
        if(st1.empty() && st2.empty()){
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            else{

                if(st2.empty()){
                    while(!st1.empty()){
                           st2.push(st1.top());
                            st1.pop();
                   }
                }
                return st2.top();
            }       
    }
    
    bool empty() {
         return (st1.empty() && st2.empty());
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */