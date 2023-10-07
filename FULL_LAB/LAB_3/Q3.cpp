#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int h[n];

    for(int i=0;i<n;i++){
        cin>>h[i];  
    }
    int h2[n];
    for(int i=0;i<n;i++){
        h2[i]=h[n-1-i];
    }
    vector<int>v;
    stack<pair<int,int>>st;
    st.push(make_pair(0,0));
    st.push(make_pair(h[0],1));
     
    for(int i=1;i<n;i++){ 
    if(h[i]>=st.top().first){
            st.push(make_pair(h[i],i+1));
        }
        else{

            while(st.top().first>h[i] && !st.empty()){
               int x= (st.top().first)*(i+1-st.top().second);
               v.push_back(x);
                st.pop();
              //cout<<x<<endl;
                if(st.empty()){
                    break;
                }        
            }
              st.push(make_pair(h[i],i+1));

        }
        }
    if(!st.empty()){
     while( !st.empty()){
               int x= (st.top().first)*(n+1-st.top().second);         
               v.push_back(x);
                st.pop();
                if(st.empty()){
                    break;
                }
       }
    }
    
int maxi=0;
for(int i=0;i<v.size();i++){
    if(v[i]>maxi){
        maxi=v[i];
    }
}
//cout<<maxi<<endl;


// Reverse..


    vector<int>v2;
    stack<pair<int,int>>st2;
  
    st2.push(make_pair(h2[0],1));
    // cout<<h2[0]<<endl;
    for(int i=1;i<n;i++){ 
    if(h2[i]>=st2.top().first){
            st.push(make_pair(h2[i],i+1));
        }
        else{

            while(st2.top().first>h2[i] && !st2.empty()){
               int x= (st2.top().first)*(i+1-st2.top().second);
               v2.push_back(x);
                st2.pop();
              //cout<<x<<endl;
                if(st2.empty()){
                    break;
                }        
            }
              st2.push(make_pair(h2[i],i+1));

        }
        }
    if(!st2.empty()){
     while( !st2.empty()){
               int x= (st2.top().first)*(n+1-st2.top().second);    
            
               v2.push_back(x);
                st2.pop();
                if(st2.empty()){
                    break;
                }
       }
    }
    
int maxi2=0;
for(int i=0;i<v2.size();i++){
    if(v2[i]>maxi2){
        maxi2=v2[i];
    }
}
cout<<max(maxi,maxi2)<<endl;
  
return 0;
}