class Solution {           // Leet Code template.
public:
    int hIndex(vector<int>& citations) {

        map<int,int>mp;
        
        for(int i=0;i<1000;i++){
          for(int j=0;j<citations.size();j++){
             if(citations[j]>=i){
                  mp[i]++;
              }
           }
        }
        for(int i=1000;i>=1;i--){
            if(mp[i]>=i){
                return i;
            }
        }
        return  0;
            }
};