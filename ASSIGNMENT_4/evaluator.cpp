/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "evaluator.h"

bool isval(string s){
    bool ans=true;
    for(int i=0;i<s.size();i++){
        if(!(s[i]>='0' && s[i]<='9')){
            ans=false;
            break;
        }
    }
return ans;
}

UnlimitedRational* Compute(ExprTreeNode* &r,SymbolTable* &S){

        if(r->type=="VAL"){         
            return r->val;
        }
        else if(r->type=="VAR"){          
            return (S->search(r->id));
        }  
        else if(r->type=="ADD"){        
        UnlimitedRational* ans= Compute(r->left,S)->add(Compute(r->left,S),Compute(r->right,S));
        r->evaluated_value=ans;
        return ans;
        }
        else if(r->type=="SUB"){
        UnlimitedRational* ans= Compute(r->left,S)->sub(Compute(r->left,S),Compute(r->right,S));
        r->evaluated_value=ans;
        return ans;
        }
        else if(r->type=="MUL"){
            
        UnlimitedRational* ans= Compute(r->left,S)->mul(Compute(r->left,S),Compute(r->right,S));
        r->evaluated_value=ans;
        return ans;
        }
        else if(r->type=="DIV"){
        UnlimitedRational* ans= Compute(r->left,S)->div(Compute(r->left,S),Compute(r->right,S));
        r->evaluated_value=ans;
        return ans;
        }
    
}

Evaluator:: Evaluator(){
      symtable=new SymbolTable();
}

Evaluator:: ~Evaluator(){
    delete symtable;                        // Check for the memory management......  
}

void Evaluator::parse(vector<string> code){                         // PARSING.....

    ExprTreeNode* root=new ExprTreeNode();
    ExprTreeNode* curr=root;
    vector<ExprTreeNode*>parents;
   
    code.push_back(")");                                   // Completing the parenthesis......
    code.insert(code.begin(),"(");

    for(int i=0;i<code.size();i++){ 

        if(code[i]=="("){

            ExprTreeNode* left_child =new ExprTreeNode();
            curr->left=left_child;
            parents.push_back(curr);
            curr=curr->left;

        }

        else if(code[i]=="+" || code[i]=="-" || code[i]=="/" || code[i]=="*" || code[i]==":="){
        // “ADD,” “SUB,” “MUL,” “DIV,” “VAL,” or “VAR” 
            if(code[i]=="+"){
                curr->type="ADD";
            }
            if(code[i]=="-"){
                curr->type="SUB";
            }
            if(code[i]=="*"){
                curr->type="MUL";
            }
            if(code[i]=="/"){
                curr->type="DIV";
            }
            if(code[i]==":="){
                curr->type="ADD";
            }

            ExprTreeNode* right_child =new ExprTreeNode();
            curr->right=right_child;
            parents.push_back(curr);
            curr=curr->right;
        }

        else if(code[i]==")"){

            curr=parents[parents.size()-1];
            parents.pop_back();

        }

        else{

            if(isval(code[i])){

                curr->type="VAL";
                UnlimitedInt* d=new UnlimitedInt("1");
                UnlimitedInt* n=new UnlimitedInt(code[i]);
                UnlimitedRational* r=new UnlimitedRational(n,d);
                curr->val=r;
                curr->evaluated_value=r;            // can also be used... ideally defined only for operators....                
           
            }
            else{
            //     if(i==0){   // new variable...(not in sym_table..)  
            //         curr->type="VAR";    
            //         curr->id=code[i];
            //    }
            //    else{            // variable present in symtable..
            //         curr->type="VAR";
            //         curr->id=code[i];
            //    }
                
                    curr->type="VAR";              // Just a Parse Tree...
                    curr->id=code[i];

                    //curr->evaluated_value=NULL;

           }
            curr=parents[parents.size()-1];
            parents.pop_back();
        }
    }

    expr_trees.push_back(root);

}

void Evaluator::eval(){

    ExprTreeNode* to_eval=expr_trees[expr_trees.size()-1];
      
    UnlimitedRational* ans=Compute(to_eval->right,symtable);     // Be careful about "this"....!!!!
   
    to_eval->left->evaluated_value=ans;

    //Populating the symbol Table......
    
    symtable->insert(to_eval->left->id,to_eval->left->evaluated_value);

}

// int main(){
// Evaluator* E=new Evaluator();


// vector<string>code={"x",":=","(","3","+","(","4","/","5",")"};
// E->parse(code);
// E->eval();

// vector<string>code2={"y",":=","(","3","+","(","4","*","x",")"};
// E->parse(code2);
// E->eval();

// vector<string>code3={"z",":=","(","x","+","y",")"};
// E->parse(code3);
// E->eval();

// cout<<E->symtable->search("z")->get_frac_str()<<endl;



// //ExprTreeNode* root= E->expr_trees[(E->expr_trees).size()-1];
// //cout<<root->left->id<<endl;
// // cout<<root->type<<endl;
// // cout<<root->left->id<<endl;
// // cout<<root->right->type<<endl;
// // cout<<root->right->left->val->get_frac_str()<<endl;
// // cout<<root->right->right->type<<endl;
// // cout<<root->right->right->left->val->get_frac_str()<<endl;
// // cout<<root->right->right->right->val->get_frac_str()<<endl;


// //cout<<E->symtable->get_size()<<endl;



// return 0;
// }



