class Solution {
public:

 int maxPoints(vector<vector<int>>& points) {
     
            float n=points.size();
            if(n==1){
                return 1;
            }
            vector<vector<float>>v;
            float vert=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
               // cout<<"HELLO"<<endl;
                    float x_i=points[i][0];
                    //cout<<x_i<<endl;
                    float x_j=points[j][0];
                   // cout<<x_j<<endl;
                    float y_i=points[i][1];
                    float y_j=points[j][1];
                    if((x_j-x_i)!=0){
                    //cout<<"HELLO"<<endl;
                    float m= float((y_j-y_i))/float((x_j-x_i));
                    float c= (float((((y_i)*(x_j))-((y_j)*(x_i))))/float((x_j-x_i)));

                    vector<float>line;
                    line.push_back(m);
                    line.push_back(c);
                    v.push_back(line);}
                    
                }
            }
           vector<float>see;
            for(int i=0;i<n;i++){
                int c=0;
                for(int j=i+1;j<n;j++){
                if(points[i][0]==points[j][0]){
                    c++;
                }}
                c++;
                see.push_back(c);
            }
             vert=0;
            for(int i=0;i<see.size();i++){
                if(see[i]>vert){
                    vert=see[i];
                }
            }
           // vert++;
            map<vector<float>,bool>mp;
            vector<vector<float>>v2;
            for(int i=0;i<v.size();i++){
            if(!mp[v[i]]){
            v2.push_back(v[i]);
            mp[v[i]]=true;
            }
            
			}   
			         
            vector<float>ans;
            for(int i=0;i<v2.size();i++){
            float cnt=0;
                for(int j=0;j<n;j++){
                    if((points[j][1]==(points[j][0]*v2[i][0]+v2[i][1]))){
                   	
                        cnt++;
                    }
                }
               
                //cout<<v2[i][0]<<" "<<v2[i][1]<<endl;
                //cout<<cnt<<endl;
                ans.push_back(cnt);
            }

            float maxi=0;
            for(int i=0;i<ans.size();i++){
                if(ans[i]>maxi){
                    maxi=ans[i];
                }
            }
          //  cout<<vert<<endl;
            maxi=max(vert,maxi);
        return maxi;
    }


};