#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        vector<int>ans;
        stack<int>st;
        ans.push_back(0);
        st.push(heights[heights.size()-1]);

        for(int i=heights.size()-2;i>=0;i--){

            if(!st.empty()){

                    int ele=st.top();
                    if(ele>heights[i]){
                        st.push(heights[i]);
                        ans.push_back(1);
                    }
                    else{
                        int cnt=1;

                        while(st.top()<heights[i]){
                            cnt++;
                            st.pop();
                            if(st.empty()){
                                cnt--;
                                break;
                            }
                        }

                        st.push(heights[i]);
                        ans.push_back(cnt);
                    }
            }
            else{
                st.push(heights[i]);
                ans.push_back(1);
            }
            }
            vector<int>res;
            for(int i=ans.size()-1;i>=0;i--){
            res.push_back(ans[i]);

            }
            return res;       
    }
};