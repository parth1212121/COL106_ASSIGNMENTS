// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class SearchEngine {
private:

    vector<int>book_no;
    vector<int>page_no;
    vector<int>para_no;
    vector<int>sent_no;
    vector<string>sentence_text;

    void small(string &s){

        for(int i=0;i<s.size();i++){
            s[i]=tolower(s[i]);
        }
    }

    void develop_pi_table(string pattern,vector<int>&pi){          // pi is an empty vector.
    int ans=0;                                                 // used to form pi table.
    pi.push_back(0);
    int i=1;
    int m=pattern.size();
    for(;i<m;i++){
        if(pattern[i]==pattern[ans]){
            ans++;
            pi.push_back(ans);
        }
        else{
                if(!ans){
                    pi.push_back(0);
                }
                else{
                    ans=pi[ans-1];
                    i--;
                }             
        }
    }
    }

    // preprocess pi before...

    void KMP(string text,string pattern,vector<int>pi,vector<int>&results){

        int j=0;
        int i=0;
        int n=text.size();
        int m=pattern.size();
        for(;i<n;i++){

            if(j==m){
                results.push_back(i-m);
                j=pi[j-1];
                i--;
            }
            else if(i<n && pattern[j]!=text[i]){
                if(j){
                    j=pi[j-1];
                    i--;
                }
            }
            else if(pattern[j]==text[i]){
                j++;
            }
        }
        if(j==m){
            results.push_back(i-m);
        }

    }

    void The_KMP(string text,string pattern,vector<int>& results){

        vector<int>pi;
        develop_pi_table(pattern,pi);
        KMP(text,pattern,pi,results);

        return;
    }


    // You can add attributes/helper functions here

public:
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
};