// Do NOT add any other includes
#include "dict.h"





Dict::Dict(){
    trie* tt = new trie();
    T = tt; 
}

Dict::~Dict(){
    // Implement your function here    
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here  
    string word = "";
    vector <string> words;
    //. , - : ! " ' ( ) ? [ ] ; @
   
    for (int i=0;i<sentence.length();i++){
        if (sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == ',' || sentence[i] == '-' || sentence[i] == ':' || sentence[i] == '!' || sentence[i] == '\"' || sentence[i] == '\'' || sentence[i] == '(' || sentence[i] == ')' || sentence[i] == '?' || sentence[i] == '[' || sentence[i] == ']' || sentence[i] == ';' || sentence[i] == '@'){
            words.push_back(word);
            word = "";
        }
        else{
            int id = static_cast<int>(sentence[i]);
            if (65<=id && id<=90){
                id = id + 32;
                word = word + char(id);
            }
            else{
                word = word + sentence[i];
            }
        }
    }
    words.push_back(word);
    for (string s:words){
        T->ins(s);
    }
    return;
}

int Dict::get_word_count(string word){
    // Implement your function here  
    int count = T->ser(word);
    return count;
}

void Dict::dump(trie* t, string p,ofstream& MyFile){
    for (int i=0;i<53;i++){
        if (i<26 && i>=0){
            string pp = p + char(97+i);
            if (t->frequency[i] != 0){
                    MyFile<<pp<<", "<<t->frequency[i]<<endl;
                }
            if (t->children[i] != nullptr){
                    dump(t->children[i],pp,MyFile);
                }
        }
    
        else if (i<36 && i>=26){
            string pp = p + char(i-26 + 48);
            if (t->frequency[i] != 0){
                    MyFile<<pp<<", "<<t->frequency[i]<<endl;
                }
            if (t->children[i] != nullptr){
                    dump(t->children[i],pp,MyFile);
                }
        }
    
        else{
            string pp = p;
            switch(i){
                case 36:
                    pp = pp + char(35);
                    break;
                case 37:
                    pp = pp + char(36);
                    break;
                case 38:
                    pp = pp + char(37);
                    break;
                case 39:
                    pp = pp + char(38);
                    break;
                case 40:
                    pp = pp + char(42);
                    break;
                case 41:
                    pp = pp + char(43);
                    break;
                case 42:
                    pp = pp + char(47);
                    break;
                case 43:
                    pp = pp + char(60);
                    break;
                case 44:
                    pp = pp + char(61);
                    break;
                case 45:
                    pp = pp + char(62);
                    break;
                case 46:
                    pp = pp + char(94);
                    break;
                case 47:
                    pp = pp + char(95);
                    break;
                case 48:
                    pp = pp + char(96);
                    break;
                case 49:
                    pp = pp + char(123);
                    break;
                case 50:
                    pp = pp + char(124);
                    break;
                case 51:
                    pp = pp + char(125);
                    break;
                case 52:
                    pp = pp + char(126);
                    break;
                case 53:
                    pp = pp + char(92);
                default:
                    pp = pp + char(61);
                    break;
                }
            if (t->frequency[i] != 0){
                    MyFile<<pp<<", "<<t->frequency[i]<<endl;
                }
            if (t->children[i] != nullptr){
                    dump(t->children[i],pp,MyFile);
                }
        }
    }
}


void Dict::dump_dictionary(string filename){
    ofstream MyFile(filename);
    dump(this->T,"",MyFile);
    MyFile.close();
    return;
}

// int main(){
//     Dict* d = new Dict();
//     d->insert_sentence(1,1,1,1,"abc abc abc");
//     d->dump_dictionary("sss");
// }