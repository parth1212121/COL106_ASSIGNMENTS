#include "Comp.h"


void merge(Account *A,int left,int mid,int right,Account* T){               // O(nlogn)
    // merges the sorted array A[left,....,mid-1] and A[mid,....,right-1].into the auxillary array T.
    int i=left;
    int j=mid;
    int d=0;
    while(i<mid && j<right){                     // O(n).
        if(A[i].balance>A[j].balance || (A[i].balance==A[j].balance && A[i].id<A[j].id)){
            T[d]=A[j];
            d++;
            j++;
        }        
        else{
            T[d]=A[i];
            d++;
            i++;
        }
    }                             
    while(i<mid){
        T[d]=A[i];
        i++;
        d++;
    }
    while(j<right){
        T[d]=A[j];
        j++;
        d++;
    }
    for(int i=left;i<right;i++){           
        A[i]=T[i];
    }
}

void mergesort(Account* A,int size,Account *T){                   // Recursive.
    int mid=(size)/2;  
    if(size==1){
        T[0]=A[0];
        return;
    }
    mergesort(A,mid,T);
    mergesort(&A[mid],size-mid,T);    
    merge(A,0,mid,size,T);   
}


void Comp::createAccount(std::string id, int count) {       // Added to the database....
 
    Account A;                                                    
    A.id=id;
    A.balance=count;    
    int key=hash(id);    
    if(bankStorage2d[key][0].id=="x"){
        bankStorage2d[key][0]=A;
    }                                              // O(1).
    else{
        bankStorage2d[key].push_back(A);
    }
  
    size++;                                      
   
}

std::vector<int> Comp::getTopK(int k) {                      // O(nlogn).

 
    std::vector<Account>present_accounts;

    for(int i=0;i<100043;i++){                                   // O(n).
        if(bankStorage2d[i][0].id!="x"){
            for(int j=0;j<bankStorage2d[i].size();j++){
                    present_accounts.push_back(bankStorage2d[i][j]);
            }
        }
    }

    // Merge_Sort present_account with respect to balance....

    int n=present_accounts.size();
    Account present_accounts_array[n];
    for(int i=0;i<n;i++){
        present_accounts_array[i]=present_accounts[i];
    }

    Account present_accounts_sorted_array[n];

    mergesort(present_accounts_array,n,present_accounts_sorted_array);  // O(nlogn).

    std::vector<int>top_k;

    if(k>n){
        for(int i=n-1;i>=0;i--){
            top_k.push_back(present_accounts_sorted_array[i].balance);
        }
        return top_k;
    }
    else{
        for(int i=n-1;i>(n-(k+1));i--){
            top_k.push_back(present_accounts_sorted_array[i].balance);
        }
        return top_k;
    }

}

int Comp::getBalance(std::string id) {

    if(bankStorage2d[hash(id)][0].id=="x"){
        return -1;
    }
    else{                                                               // O(1+a).
        for(int j=0;j<bankStorage2d[hash(id)].size();j++){
            if(bankStorage2d[hash(id)][j].id==id){
                return bankStorage2d[hash(id)][j].balance;
                }
            }
            return -1;
    }
    
}

void Comp::addTransaction(std::string id, int count) {

    if(doesExist(id)){
        int key=hash(id);
        int i=0;
        for(;i<bankStorage2d[key].size();i++){
            if(bankStorage2d[key][i].id==id){                           // O(1+a).
                bankStorage2d[key][i].balance+=count;                
                break;
            }
            }                   
            } 
    else{
        createAccount(id,count);
        }
    
}

bool Comp::doesExist(std::string id) {


    if(bankStorage2d[hash(id)][0].id=="x"){
        return false;
    }                                                                   // O(1+a).
    else{
            for(int j=0;j<bankStorage2d[hash(id)].size();j++){
                if(bankStorage2d[hash(id)][j].id==id){
                    return true;
                }
            }
            return false;
    }

}

bool Comp::deleteAccount(std::string id) {

        if(!doesExist(id)){
            return false;
        }
        else{

            int key=hash(id);
            if(bankStorage2d[key].size()==1){
                
                bankStorage2d[key][0].id="x";
                bankStorage2d[key][0].balance=0;
            }

            else{                                                        
            for(int j=0;j<bankStorage2d[key].size();j++){                 // O(1+a).
                if(bankStorage2d[key][j].id==id){
                    bankStorage2d[key][j].id="x";
                    bankStorage2d[key][j].balance=0;

                   bankStorage2d[key].erase(bankStorage2d[key].begin()+j);

                    break;
                }
            }
            }  
            size--;
            return true;
            }
}


int Comp::databaseSize() {
    
    return size;                                      // O(1).

}

int Comp::hash(std::string id) {                                     
  
    int ans=0;
    
    for(int i=0;i<id.size();i++){
        int r=(id[i]);
        ans+=r;
    }
    ans=ans%7;
  
     int cnt=0;
     int res=0;
     while(cnt<22){
      int val=id[cnt];
         res+=(prime[ans]*(val));
         ans=((ans+1)%100);
          cnt++;
     }

        float fin=float(res-39995)/float(41036);
        int final= 100043*(fin);
        final=final%100043;
    
        return final;

}











