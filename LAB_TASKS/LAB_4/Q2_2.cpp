#include <bits/stdc++.h>                          // Hacker_Rank format.

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 

long merge(long *A,long left,long mid,long right,long* T){
    
    // merges the sorted array A[left,....,mid-1] and A[mid,....,right-1].into the auxillary array T.
    long cnt=0;

    if(right-left<=1){
        cnt=0;
    }
    
    else{                                         // O(nlogn)

        long i2=mid-1;
        long j2=right-1;
        while(i2>=0 && j2>=mid){
        if(A[i2]<=A[j2]){
            j2--;

        }
        else{
            cnt+=(j2-mid+1);
            i2--;            
        }}

    }
    
    long i=left;
    long j=mid;
    long d=0;
    while(i<mid && j<right){                     // O(n).
        if(A[i]>A[j]){
            T[d]=A[j];
            d++;
            j++;
            
        }
        else{
            T[d]=A[i];
            d++;
            i++;

        }
    }
    while(i<mid){
        T[d]=A[i];
        i++;
        d++;
    }
    while(j<right){
        T[d]=A[j];
        j++;
        d++;
    }
    for(long i=left;i<right;i++){           
        A[i]=T[i];
    }
  
    return cnt;

}

long mergesort(long* A,long size,long *T){                   // Recursive.
    
    long mid=(size)/2;  
    if(size==1){
        T[0]=A[0];
        return 0;
    }
    return(mergesort(A,mid,T) + mergesort(&A[mid],size-mid,T)+ merge(A,0,mid,size,T));
}



long countInversions(vector<int> arr) {
    
    
    long T[arr.size()];
    long ar[arr.size()];
    for(int i=0;i<arr.size();i++){
        ar[i]=arr[i];
    }
    return mergesort(ar,arr.size(),T);
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
