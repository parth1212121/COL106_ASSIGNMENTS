 bool my_bool(pair<string,int>k1,pair<string,int>k2){      // LeetCode Template...
        if(k1.second!=k2.second){
            return k1.second<k2.second;
        }
        else{
            return k1.first<k2.first;
        }
    }
class Solution {
public:
   
    string largestWordCount(vector<string>& messages, vector<string>& senders) {

        vector<int>int_message;
        for(int i=0;i<messages.size();i++){

            string s=messages[i];
            int cnt=0;
            for(int j=0;j<s.size();j++){
                if(s[j]==' '){
                    cnt++;
                }
            }
            cnt++;                          // cnt ---> word count of the message.

            int_message.push_back(cnt);
        }
        
        map<string,int>mp;
        for(int i=0;i<senders.size();i++){
                mp[senders[i]]+=int_message[i];
        }
        vector<pair<string,int>>v;
        for(auto i: mp){
            string s=i.first;
            int x=i.second;
            pair<string,int>k;
            k.first=s;
            k.second=x;
            v.push_back(k);
        }

        sort(v.begin(),v.end(),my_bool);

        return v[v.size()-1].first; 
    }
};