#include<bits/stdc++.h>
using namespace std;

int Parent(int i){
    return (i-1)/2;
}
int leftchild(int i){
    return (2*i+1);
}
int rightchild(int i){
    return (2*i+2);
}

void heapifyUp(int index,vector<int>& heap){             //O(logn)

    if(index==0){
        return;   
    }
    else{
        int parent_index=Parent(index);
        if(heap[parent_index]>heap[index]){
            swap(heap[parent_index],heap[index]);
            heapifyUp(parent_index,heap);
        }
        return;
    }
}

void HeapifyDown(int index,vector<int>& heap){          //O(logn)

    int left=leftchild(index);
    int right=rightchild(index);
    int minindex=index;
    if(left>=heap.size()){
        return;
    }    
    if(left<heap.size() && heap[left]<heap[minindex]){
        minindex=left;
    }
    if(right<heap.size() && heap[right]<heap[minindex]) {
        minindex=right;
    }
    if(index!=minindex){
        swap(heap[minindex],heap[index]);
        HeapifyDown(minindex,heap);
    }
}

void insertion1(int val,vector<int>& heap){       //O(logn)
    heap.push_back(val);
    heapifyUp(heap.size()-1,heap);
return;
}

void Deletemin(vector<int>& heap){                 //O(nlogn)

    heap[0]=heap[heap.size()-1];
    heap.pop_back();
    HeapifyDown(0,heap);
}


void BuildHeap(vector<int>& arr){                   // O(n)

    int n=arr.size();
    for
(int i=(n/2-1);i>=0;i--){
        HeapifyDown(i,arr);
    }
}

void HeapifyDown_2(int index,vector<int>& heap,int i){          //O(logn)

    int left=leftchild(index);
    int right=rightchild(index);
    int minindex=index;
    if(left>=i){
        return;
    }    
    if(left<i && heap[left]<heap[minindex]){
        minindex=left;
    }
    if(right<i && heap[right]<heap[minindex]) {
        minindex=right;
    }
    if(index!=minindex){
        swap(heap[minindex],heap[index]);
        HeapifyDown_2(minindex,heap,i);
    }

}

vector<int> HeapSort(vector<int>& arr){           // O(nlogn)                // MEMORY---> O(1)

    vector<int>sorted;

    for(int i=0;i<arr.size();i++){
        sorted.push_back(arr[i]);
    }

    BuildHeap(sorted);

    for(int i=sorted.size()-1;i>0;i--){
        swap(sorted[0],sorted[i]);
        HeapifyDown_2(0,sorted,i);
    }
    return sorted;
}

    vector<string> findRelativeRanks(vector<int>& score) {

        vector<int>sortit;
        sortit=HeapSort(score);
        for(int i=0;i<score.size();i++){
            cout<<sortit[i]<<" ";
        }cout<<endl;

        map<int,string>mp;
        mp[sortit[0]]="Gold Medal";
        mp[sortit[1]]="Silver Medal";
        mp[sortit[2]]="Bronze Medal";
        for(int i=3;i<sortit.size();i++){
            mp[sortit[i]]=to_string(i+1);
        }
        vector<string>ans;
        for(int i=0;i<score.size();i++){
            ans.push_back(mp[score[i]]);
        }      
     return ans;
      
    }
int main(){


    vector<int>v={5,4,3,2,1};

    vector<string>ans=findRelativeRanks(v);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;


}