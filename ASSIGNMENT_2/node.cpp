#include<iostream>
#include "node.h"
using namespace std;

/* PART B */
/* Stacks using Linked Lists */


    // Use to construct a sentinel node (see list.h)
     Node::Node(bool sentinel){
         is_sentinel=true;
         next=nullptr;
         prev=nullptr;
     };

    // Use to construct a regular node
     Node::Node(int v, Node* nxt, Node* prv){
        value=v;
        is_sentinel=false;
        next=nullptr;
        prev=nullptr;
    };

    // Return whether a node is a sentinel node 
    // Use it to check if we are at the ends of a list
    bool  Node::is_sentinel_node(){
        return is_sentinel;
    };

    // Return the value of a node
    int  Node::get_value(){
        return value;
    };

