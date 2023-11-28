#include<bits/stdc++.h>

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>record;
        int n=operations.size();
        for(int i=0;i<n;i++){
                if(operations[i]=="+"){
                    int prev1=record[record.size()-1];
                    int prev2=record[record.size()-2];
                    record.push_back(prev1+prev2);
                }
                else if(operations[i]=="D"){
                    int prev1=record[record.size()-1];
                    record.push_back(2*prev1);
                }
                else if(operations[i]=="C"){
                    record.pop_back();
                }
                else{
                    record.push_back(stoi(operations[i]));
                }
        }
        int ans=0;
        for(int i=0;i<record.size();i++){
            ans+=record[i];
        }
        return ans;
    }    
};