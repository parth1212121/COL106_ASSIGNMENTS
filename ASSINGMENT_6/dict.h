// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Dict {
private:
    // You can add attributes/helper functions here

    class trie{
    public:
        vector <trie*> children;
        vector <int> frequency;
        
        trie(){
            vector<int> vect(54, 0);
            frequency = vect;
            vector <trie*> vv(54,nullptr);
            children = vv;
        }

        void insert(trie* T, string word, int &i){
            if (word == ""){
                return;
            }
            int index = static_cast<int>(word[i])-static_cast<int>('a');
            if (0<=index && index<26){
                if (i != word.length()-1){
                    if (T->children[index] != nullptr){
                        i++;
                        insert(T->children[index],word,i);
                    }

                    else{
                        trie* t = new trie();
                        T->children[index] = t;
                        i++;
                        insert(T->children[index],word,i);
                    }
                }
                else{
                    T->frequency[index] += 1;
                }

            }
            else{
                int id = static_cast<int>(word[i]);
                if (48<=id && id<=57){
                    index = id -48 + 26;
                    if (i != word.length()-1){
                        if (T->children[index] != nullptr){
                            i++;
                            insert(T->children[index],word,i);
                        }

                        else{
                            trie* t = new trie();
                            T->children[index] = t;
                            i++;
                            insert(T->children[index],word,i);
                        }
                    }
                    else{
                        T->frequency[index] += 1;
                    }
                }
                else{
                    // # $ % & * + / \ < = > ^ _ ` { } | ~
                    switch (id){
                        case 35:
                            index = 36;
                            break;
                        case 36:
                            index = 37;
                            break;
                        case 37:
                            index = 38;
                            break;

                        case 38:
                            index = 39;
                            break;

                        case 42:
                            index = 40;
                            break;

                        case 43:
                            index = 41;
                            break;

                        case 47:
                            index = 42;
                            break;

                        case 60:
                            index = 43;
                            break;

                        case 61:
                            index = 44;
                            break;

                        case 62:
                            index = 45;
                            break;
                        case 92:
                            index = 53;
                            break;
                        case 94:
                            index = 46;
                            break;

                        case 95:
                            index = 47;
                            break;

                        case 96:
                            index = 48;
                            break;

                        case 123:
                            index = 49;
                            break;

                        case 124:
                            index = 50;
                            break;

                        case 125:
                            index = 51;
                            break;

                        case 126:
                            index = 52;
                            break;

                        default:
                            index = 52;
                            break;

                    }
                    if (i != word.length()-1){
                        if (T->children[index] != nullptr){

                            i++;
                            insert(T->children[index],word,i);
                        }

                        else{
                            trie* t = new trie();
                            T->children[index] = t;
                            i++;
                            insert(T->children[index],word,i);
                        }
                    }
                    else{

                        T->frequency[index] += 1;
                    }
                }
            }

    }
        
        void ins(string s){
            int i=0;
            insert(this,s,i);
        }

        int search(trie* T,string word, int& i){
            if (word == ""){
                return 0;
            }
            int index = static_cast<int>(word[i])-static_cast<int>('a');
            if (0<=index && index<26){
                if (i != word.length()-1){
                    if (T->children[index] != nullptr){
                        i++;
                        return search(T->children[index],word,i);
                    }

                    else{
                        return 0;
                    }
                }
                else{
                    return T->frequency[index];
                }
            }
            else{
                int id = static_cast<int>(word[i]);
                if (48<=id && id<=57){
                    index = id -48 + 26;
                    if (i != word.length()-1){
                        if (T->children[index] != nullptr){
                            i++;
                            return search(T->children[index],word,i);
                        }

                        else{
                            return 0;
                        }
                    }
                    else{
                        return T->frequency[index];
                    }
                }
                else{
                    // # $ % & * + / < = > ^ _ ` { } | ~
                    switch (id){
                        case 35:
                            index = 36;
                            break;
                        case 36:
                            index = 37;
                            break;

                        case 37:
                            index = 38;
                            break;

                        case 38:
                            index = 39;
                            break;

                        case 42:
                            index = 40;
                            break;

                        case 43:
                            index = 41;
                            break;

                        case 47:
                            index = 42;
                            break;

                        case 60:
                            index = 43;
                            break;

                        case 61:
                            index = 44;
                            break;

                        case 62:
                            index = 45;
                            break;
                        case 92:
                            index = 53;
                            break;

                        case 94:
                            index = 46;
                            break;

                        case 95:
                            index = 47;
                            break;

                        case 96:
                            index = 48;
                            break;

                        case 123:
                            index = 49;
                            break;

                        case 124:
                            index = 50;
                            break;

                        case 125:
                            index = 51;
                            break;

                        case 126:
                            index = 52;
                            break;

                        
                    }
                    if (i != word.length()-1){
                        if (T->children[index] != nullptr){
                            i++;
                            return search(T->children[index],word,i);
                        }

                        else{
                            return 0;
                        }
                    }
                    else{
                        
                        return T->frequency[index];
                    }
                }
            }
        }

        int ser(string s){
            int i=0;
            return search(this,s,i);
        }

};
    
public: 

    void dump(trie* t,string p,ofstream& MyFile);
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/

    trie* T;
    




};