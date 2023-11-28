/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"

ExprTreeNode :: ExprTreeNode(){

    UnlimitedInt* p=new UnlimitedInt("0");
    UnlimitedInt* q=new UnlimitedInt("0");
    UnlimitedRational* r=new UnlimitedRational(p,q);
    val=r;
    evaluated_value=r;
    type=" ";
    left=NULL;
    right=NULL;

    
}

ExprTreeNode :: ExprTreeNode(string t, UnlimitedInt* v){

    UnlimitedInt* p=new UnlimitedInt("1");
    UnlimitedRational* r=new UnlimitedRational(v,p);
    val=r;
    evaluated_value=r;
    type=t;
    left=NULL;
    right=NULL;


}

ExprTreeNode :: ExprTreeNode(string t, UnlimitedRational* v){

type=t;
val=v;
evaluated_value=v;
    left=NULL;
    right=NULL;


}

ExprTreeNode :: ~ExprTreeNode(){

    delete evaluated_value;
}