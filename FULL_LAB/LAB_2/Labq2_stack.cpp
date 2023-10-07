#include<bits/stdc++.h>
using namespace std;                                                       // Next greatest element.....
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<int>st;
    int mp[n];
    for(int i=0;i<n;i++){
        mp[i]=-1;
    }
    st.push(0);
    for(int i=1;i<n;i++){                                                  // O(n)
        if(a[i]>a[st.top()]){
            if(!st.empty()){
            while(a[i]>a[st.top()] ){
            mp[st.top()]=a[i];
            st.pop();
            if(st.empty()){
                break;
            }
            }
            }
            st.push(i);
        }
        else{
            st.push(i);
        }
    }
    for(int i=0;i<n;i++){
        cout<<mp[i]<<" ";
    }cout<<endl;
return 0;
}