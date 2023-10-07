#include "QuadraticProbing.h"

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


void QuadraticProbing::createAccount(std::string id, int count) {

    Account a;
    a.id=id;
    a.balance=count;
    int key=hash(id);
    int tt =key;
    int inc=1;
    while(bankStorage1d[tt].id!="x"){                                                         // Linear Probing......
            tt=(key+((inc*inc)))%200323;
                inc++;
    }
    bankStorage1d[tt]=a;     
    size++;

}



std::vector<int> QuadraticProbing::getTopK(int k) {

        
    std::vector<Account>present_accounts;

    for(int i=0;i<200323;i++){                                   // O(n).
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

int QuadraticProbing::getBalance(std::string id) {

    if(!doesExist(id)){
        return -1;
    }
    else{

        int key=hash(id);
        int inc=1;                      
        int tt=key;
        while(bankStorage1d[tt].id!=id){     

         tt=(key+((inc*inc)))%200323;
                inc++;

    }

        return bankStorage1d[tt].balance;
    }

}


void QuadraticProbing::addTransaction(std::string id, int count) {
  
    if(!doesExist(id)){
        createAccount(id,count);
    }
    else{
        int key=hash(id);
        int inc=1;
        int tt=key;
        while(bankStorage1d[tt].id!=id){     

        tt=(key+((inc*inc)))%200323;
                inc++;
    }

        bankStorage1d[tt].balance+=(count);    

    }

}

bool QuadraticProbing::doesExist(std::string id) {

    int key=hash(id);
    int i=key;
    while(i!=((key-1)%200323)){                                  // O(n).
        if(bankStorage1d[i].id==id){
            return true;                      // To be sure not to go into an infinite loop...
        }
        i=((i+1)%200323);
    }
   return false;

}


bool QuadraticProbing::deleteAccount(std::string id) {

        if(!doesExist(id)){
            return false;
        }
        else{
            
            int key=hash(id);
            int inc=1;
            int tt=key;

            while(bankStorage1d[tt].id!=id){     
                 tt=(key+((inc*inc)))%200323;
                inc++;
             
            }

            bankStorage1d[tt].id="x";
            bankStorage1d[tt].balance=0;

            size--;

            return true;
        }

}

int QuadraticProbing::databaseSize() {

   return size;

}

int QuadraticProbing::hash(std::string id) {

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
        int final= 200323*(fin);
        final=final%200323;
    
        return final;
}




