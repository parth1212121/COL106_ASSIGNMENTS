#include "LinearProbing.h"

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



// Code start--->


void LinearProbing::createAccount(std::string id, int count) {

    Account a;
    a.id=id;                                                            //O(n).
    a.balance=count;
    int key=hash(id);
    int tt =key;
    while(bankStorage1d[tt].id!="x"){                                                                  // Linear Probing......
             tt=(tt+1)%(100043);
    }
    bankStorage1d[tt]=a;     
    size++;                                             
           
}



std::vector<int> LinearProbing::getTopK(int k) {     // O(nlogn).

        
    std::vector<Account>present_accounts;

    for(int i=0;i<100043;i++){                                   // O(n).
        if(bankStorage1d[i].id!="x"){
            present_accounts.push_back(bankStorage1d[i]);          
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

int LinearProbing::getBalance(std::string id) {         // O(n).

    if(!doesExist(id)){
        return -1;
    }
    else{

        int key=hash(id);
        while(bankStorage1d[key].id!=id){
                key=(key+1)%100043;
        }
        return bankStorage1d[key].balance;
    }

}


void LinearProbing::addTransaction(std::string id, int count) {             // O(n).
  
    if(!doesExist(id)){
        createAccount(id,count);
    }
    else{
        int key=hash(id);
        while(bankStorage1d[key].id!=id){
                key=(key+1)%100043;
        }
        bankStorage1d[key].balance+=(count);    
    }

}

bool LinearProbing::doesExist(std::string id) {

    int key=hash(id);
    int i=key;
    while(i!=((key-1)%100043)){                                  // O(n).
        if(bankStorage1d[i].id==id){
            return true;
        }
        i=((i+1)%100043);
    }
   return false;

}

bool LinearProbing::deleteAccount(std::string id) {                 // O(n).

        if(!doesExist(id)){
            return false;
        }
        else{
            
            int key=hash(id);
            while(bankStorage1d[key].id!=id){
                key=(key+1)%100043;
            }
            bankStorage1d[key].id="x";
            bankStorage1d[key].balance=0;

            size--;

            return true;
        }
}

int LinearProbing::databaseSize() {

   return size;                              // O(1).

}

int LinearProbing::hash(std::string id) {
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

