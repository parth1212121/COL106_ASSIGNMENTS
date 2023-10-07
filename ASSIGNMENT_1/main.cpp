#include<iostream>
#include<vector>
using namespace std;
class SET{
    vector<int>v;
    public:
        SET(){
        }
        int belongsto(int x){
            bool ans=false;
            for(int i=0;i<v.size();i++){
                if(v[i]==x){
                    ans=true;
                    break;
                }
            }
            if(ans){
                return 1;
            }
            return 0;
        }

        int Insert(int x){                                      // O(n)
            if(v.size()==0){
                v.push_back(x);
                return v.size();
            }
            if(belongsto(x)==0){                            // uniqeness...
            int pos=v.size();
            for(int i=0;i<v.size();i++){
                if(v[i]>x){
                    pos=(i);
                    break;
                }
            }
            v.insert(v.begin()+pos,x);
            }
            return v.size();            
        }

        int Delete(int x){                                     // O(n)
 
            bool present=false;
            int pos=0;
            for(int i=0;i<v.size();i++){
                if(v[i]==x){
                    present=true;
                    pos=i;
                    break;
                }
            }
            if(!present){
                return v.size(); 
            }
            v.erase(v.begin()+pos);
            return v.size();
        }

        int size(){                                   // O(1)
            return v.size();
        }


        vector<int> print(){                          // O(n)
            vector<int>elements;
            for(int i=0;i<v.size();i++){
                elements.push_back(v[i]);
            }
            return elements;
        }


        int Union(SET z){                            //O(n)
            vector<int>zv=z.print();
            int i=0;
            int j=0;
            vector<int>ans;
            while(i<v.size() && j<zv.size()){
                 if(v[i]==zv[j]){
                    ans.push_back(v[i]);
                    i++;
                    j++;
                }
                else if(v[i]>zv[j]){
                    ans.push_back(zv[j]);
                    j++;
                }
                else if(v[i]<zv[j]){
                    ans.push_back(v[i]);
                    i++;
                }
            }  
            while(i<v.size()){
                ans.push_back(v[i]);
                i++;
            }   
            while(j<zv.size()){
                ans.push_back(zv[j]);
                j++;
            }   
            v.clear();
            for(int i=0;i<ans.size();i++){
                v.push_back(ans[i]);
            }
            return v.size();
        }

        int Intersection(SET z){                               //O(n)
            int i=0;
            int j=0;
            vector<int>ans;
            vector<int>zv=z.print();
            while(i<v.size() && j<zv.size()){
                if(v[i]==zv[j]){
                    ans.push_back(v[i]);
                    i++;
                    j++;
                }
                else if(v[i]>zv[j]){
                    j++;
                }
                else if(v[i]<zv[j]){
                    i++;
                }
            }
            v.clear();
            for(int i=0;i<ans.size();i++){
                v.push_back(ans[i]);
            }
            return v.size();
        }

        int Difference(SET z){                                //O(n)
            vector<int>zv=z.print();
            vector<int>ans;
            int i=0;
            int j=0;
            while(i<v.size() && j<zv.size()){
                if(v[i]==zv[j]){
                    i++;
                    j++;
                }
                else if(v[i]>zv[j]){
                    j++;
                }
                else if(v[i]<zv[j]){
                    ans.push_back(v[i]);
                    i++;
                }            
            }
            while(i<v.size()){
                ans.push_back(v[i]);
                i++;
            }
            v.clear();
            for(int i=0;i<ans.size();i++){
                v.push_back(ans[i]);
            }
            return v.size();
            }



            int Sym_Difference(SET z){                              //O(n)
            vector<int>zv=z.print();
            vector<int>ans;
            int i=0;
            int j=0;
            while(i<v.size() && j<zv.size()){
                if(v[i]==zv[j]){
                    i++;
                    j++;
                }
                else if(v[i]>zv[j]){
                     ans.push_back(zv[j]);
                    j++;
                }
                else if(v[i]<zv[j]){
                    ans.push_back(v[i]);
                    i++;
                }  
            }
            while(i<v.size()){
                ans.push_back(v[i]);
                i++;
            }   
            while(j<zv.size()){
                ans.push_back(zv[j]);
                j++;
            } 
            v.clear();
            for(int i=0;i<ans.size();i++){
                v.push_back(ans[i]);
            }
            return v.size();
    }
};


vector<SET>store;
int main(){
    
    int x;
    
    while(cin>>x){
    

    if(x==1){                                              // INSERT
        int y;
        int z;
        cin>>y;
        cin>>z;
        if((store.size())<(y+1)){
            SET st;
            store.push_back(st); 
        }
        store[y].Insert(z);
        cout<<store[y].size()<<endl;
    }


    if(x==2){                                             // Delete
        int y;
        int z;
        cin>>y>>z;
        if((store.size())<(y+1)){
            cout<<-1<<endl;            
        }
        else{
            cout<<store[y].Delete(z)<<endl;
        }
    }


    if(x==3){                                            // Belongs To
    int y,z;
    cin>>y>>z;
    if((store.size())<(y+1)){       
        cout<<-1<<endl;
    }
    else{
        SET s=store[y];
        cout<<s.belongsto(z)<<endl;
    }
    }


    if(x==4){                                            // Union
    int y;
    int z;
    cin>>y>>z;
    if((store.size())<(y+1)){       
        SET st;
        store.push_back(st);
    }
    if((store.size())<(z+1)){
        SET st;
        store.push_back(st);
    }

    if(y==z){
        cout<<store[y].size()<<endl;
    }
    else{
        cout<<store[y].Union(store[z])<<endl;
    }
    }


    if(x==5){                                            //     Intersection
    int y;
    int z;
    cin>>y>>z;
    if((store.size())<(y+1)){       
        SET st;
        store.push_back(st);
    }
    if((store.size())<(z+1)){
        SET st;
        store.push_back(st);
    }

    if(y==z){
        cout<<store[y].size()<<endl;
    }
    else{
        cout<<store[y].Intersection(store[z])<<endl;
    }
    }


    if(x==6){                                           // size
        int y;
        cin>>y;
        if((store.size())<(y+1)){
            SET st;
            store.push_back(st);
        }
        cout<<store[y].size()<<endl;
    }


    if(x==7){                                          // difference
    int y;
    int z;
    cin>>y>>z;
    if((store.size())<(y+1)){       
        SET st;
        store.push_back(st);
    }
    if((store.size())<(z+1)){
        SET st;
        store.push_back(st);
    }
   cout<<store[y].Difference(store[z])<<endl;
   }


   if(x==8){                                            // Symmetric_difference
    int y;
    int z;
    cin>>y>>z;
    if((store.size())<(y+1)){       
        SET st;
        store.push_back(st);
    }
    if((store.size())<(z+1)){
        SET st;
        store.push_back(st);
    }
   cout<<store[y].Sym_Difference(store[z])<<endl;
  }


  if(x==9){                                           //print all
        int y;
        cin>>y;
        if((store.size())<(y+1)){
            cout<<endl;
        }
        else{
            vector<int>tt=store[y].print();
	    if (!tt.size()){
		cout<<endl;
	    }
	    else{
            for(int i=0;i<tt.size()-1;i++){
                cout<<tt[i]<<",";
            }cout<<tt[tt.size()-1];
            cout<<endl;
	    } }
    }

    }
return 0;
}
