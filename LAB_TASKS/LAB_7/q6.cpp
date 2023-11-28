#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Merge sort from scratch.......

    int merge( int* A, int* T,int start,int mid,int end){

    // Arrays A[start],.....,A[mid-1] and A[mid],.........,A[end-1] are sorted arrays and have to be  merged..

    int cnt1=0;

    int i1=start;
    int j1=mid;
    int ans=0;
    int res=0;

    while(i1<mid && j1<end){
        if(A[i1]>2*(long long)A[j1]){
            j1++;
            cnt1++;
        }
        else{
            i1++;
            ans+=cnt1;
            res+=ans;
            cnt1=0;
        }
    }
    while(i1<mid){
            i1++;
            ans+=cnt1;
            res+=ans;
            cnt1=0;
    }

    int i=start;
    int j=mid;
    int cnt=start;
    
    while(i<mid && j<end){
        if(A[i]<A[j]){           
            T[cnt]=A[i];
            i++;
            cnt++;
        }
        else{
            T[cnt]=A[j];
            j++;
            cnt++;
        }
    }
    while(i<mid){
        T[cnt]=A[i];
        i++;
        cnt++;
    }
    while(j<end){
        T[cnt]=A[j];
        j++;
        cnt++;
    }
    
    
    for(int i=start;i<end;i++){
        A[i]=T[i];
    }

    return res;

   }
      int x=0;
        

    int mergesort(int* A, int* T,int start,int end,int size){
        
     

        if(end-start<=1){
            return 0;
        }

        int mid=(start+end)/2;

        mergesort(A,T,start,mid,size);
        mergesort(A,T,mid,end,size);
        x+=merge(A,T,start,mid,end);

        return x;
        
    }

    int reversePairs(vector<int>& nums) {
  
        int A[nums.size()];
        for(int i=0;i<nums.size();i++){
            A[i]=nums[i];
        }
        int T[nums.size()];

        return mergesort(A,T,0,nums.size(),nums.size());

    }
};