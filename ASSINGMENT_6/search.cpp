// Do NOT add any other includes
#include "search.h"

    SearchEngine::SearchEngine(){
        // Implement your function here  
    }

    SearchEngine::~SearchEngine(){
        // Implement your function here  
    }

    void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){

        // Pre-processing...

        small(sentence);

        book_no.push_back(book_code);
        page_no.push_back(page);
        para_no.push_back(paragraph);
        sent_no.push_back(sentence_no);
        sentence_text.push_back(sentence);

        // Implement your function here  
        return;
    }

    Node* SearchEngine::search(string pattern, int& n_matches){

        small(pattern);
        
        Node* head=nullptr;
        Node* tail=nullptr;

        for(int i=0;i<book_no.size();i++){
                
            vector<int>res;
            The_KMP(sentence_text[i],pattern,res);

            for(int j=0;j<res.size();j++){

                    Node* n=new Node(book_no[i],page_no[i],para_no[i],sent_no[i],res[j]); 
                    n->right=nullptr;
                    n->left=nullptr;
                    if(head==nullptr){            
                        head=n;
                        tail=n;
                        n_matches++;
                    }
                    else{
                    tail->right=n;
                    n->left=tail;
                    tail=n;
                    n_matches++;
                    }
            }
    
        }
        // Implement your function here  
        return head;
    }


