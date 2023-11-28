/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"


string mag(string s){
   string ans="";
   if(s[0]=='-'){
      for(int i=1;i<s.size();i++){
         ans.push_back(s[i]);
      }
      return ans;
   }  
   else{
    for(int i=0;i<s.size();i++){
         ans.push_back(s[i]);
      }
      return ans;
   }
      
}

bool great(string s1,string s2){

   if(s1.size()>s2.size()){
      return true;
   }
   else if(s1.size()==s2.size()){
      if(s1>s2){
         return true;
      }
   }
   return false;

}

int log_10(int i){
   if(i==0){
        return 1;
    }
   int x=10;
   int cnt=0;
   while(i!=0){
      i=i/x;
      cnt++;
   }
   return cnt;  
}

string magnitude_add(string str1,string str2){

 
int size_1=str1.size();
int size_2=str2.size();

string result="";
string ans="";                             // The magnitiute sum.....

if(size_1>size_2){                         // Swapping.....
   string tmp=str1;
   str1=str2;
   str2=tmp;
}

size_1=str1.size();
size_2=str2.size();

   int dif=size_2-size_1;
   int car=0;
   for(int i=size_1-1;i>=0;i--){

      int sum_p=(str1[i]-'0')+(str2[i+dif]-'0')+car;
      result.push_back((sum_p%10)+'0');
      car=sum_p/10;

   }

   //extra digits of str2....

   for(int i=dif-1;i>=0;i--){

      int sum_p=((str2[i]-'0')+car);
      result.push_back((sum_p%10)+'0');
      car=sum_p/10;

   }

   if(car!=0) result.push_back(car+'0');
                                                              
   for(int i=result.size()-1;i>=0;i--){                      // Reversing..
      ans.push_back(result[i]);  
   }

// Now -->"ans"<-- stores the sum of the magnitutes of the string numbers....

return ans;

}

string magnitude_sub(string str1,string str2){

if(str1==str2){
   return "0";
}
 
int size_1=str1.size();
int size_2=str2.size();

//Magnitude subtraction.....

string result="";
string ans="";  

// need to ensure thet str2>str1....

bool change=false;
if(size_1>size_2){
    change=true;
}
else if(size_1==size_2){
  if(str1>str2){                        // lexicographic comparing....
    change=true;
  }
}

if(change){                             // Swapping.....
                        
   string tmp=str1;
   str1=str2;
   str2=tmp;

size_1=str1.size();
size_2=str2.size();}                      //[size_2>size_1]


int dif=size_2-size_1;
int bor=0;

for(int i=size_1-1;i>=0;i--){

   int differ=((str2[dif+i]-'0')-(str1[i]-'0')-bor);
   if(differ<0){
      differ+=10;
      bor=1;
   }
   else{
      bor=0;
   }
   result.push_back(differ+'0'); 

}

//extra digits of str2...

for(int i=dif-1;i>=0;i--){

      int differ=((str2[i]-'0')-bor);
      if(differ<0){
      differ+=10;
      bor=1;
      }
      else{
      bor=0;
      }
      result.push_back(differ+'0'); 

}

   for(int i=result.size()-1;i>=0;i--){                      // Reversing..
      ans.push_back(result[i]);  
   }

    string final_ans="";
    int cnt=0;
    while(ans[cnt]=='0'){
        cnt++;
    }
    for(int i=cnt;i<ans.size();i++){
        final_ans.push_back(ans[i]);
    }

   // Now final_ans stores the magnitude subraction of the two numbers..

   return final_ans;
}


string magnitude_mul(string str1,string str2){

    if(str1=="0" || str2=="0"){
        return "0";
    }

   int size_1=str1.size();
   int size_2=str2.size();
   string res="";
   string ans="";
   for(int i=0;i<(size_1+size_2);i++){
      res.push_back('0');                    // res is ready to store the computation results....
   }                                   
   int n1=0;
   int n2=0;
   for(int i=size_1-1;i>=0;i--){
         int num1=str1[i]-'0';   // present no in the str1...        
         int car=0;
         n2=0;
         int sum_t=0;
         for(int j=size_2-1;j>=0;j--){
               int num2=str2[j]-'0';
               sum_t=(res[n1+n2]-'0')+(num1*num2)+(car);
               res[n1+n2]=(sum_t%10+'0');
               car=sum_t/10;
               n2++;
         }
         if(car>0){                                      // Extra remaining carry for each digit in num_1.
            int sum_t=(res[n1+n2]-'0')+car;
            res[n1+n2]=(sum_t+'0');
         }
         n1++;
   }
   for(int i=res.size()-1;i>=0;i--){                      // Reversing..
      ans.push_back(res[i]);  
   }
   string final_ans="";
   int cnt=0;
   while(ans[cnt]=='0'){
    cnt++;
   }
   for(int i=cnt;i<ans.size();i++){                       // Removing zeros.....
    final_ans.push_back(ans[i]);
   }
   return final_ans;   
}

char small_divide(string tmp,string str2){

   if(great(str2,tmp)){
      return '0';
   }
   else{
   int x=0;
   string str2_cpy=str2;
   while(great(tmp,str2) || tmp==str2){
      str2=magnitude_add(str2_cpy,str2);
      x++;
   }

   return (x+'0');

   }
}

string small_rem(string tmp,string str2){
   if(great(str2,tmp)){
      return tmp;
   }
   else{
      string y="";
      char c=small_divide(tmp,str2);
     
      y.push_back(c);
 
      string x=magnitude_mul(str2,y);
  
      string ans=magnitude_sub(tmp,x);
      return ans;
   } 
}
string rectify(string s){
    string ans="";
    int cnt=0;
    while(s[cnt]=='0'){
        cnt++;
    }
    for(int i=cnt;i<s.size();i++){
        ans.push_back(s[i]);
    }
    if(ans==""){
        return "0";
    }
    else{
        return ans;
    }

}

string magnitude_div(string str1,string str2){

   int size_1=str1.size();
   int size_2=str2.size();
   
   if(str1=="0"){
      return "0";
   }
   if(great(str2,str1)){
    return "0";
   }
   string ans="";

   string tmp="";
   int ind=0;
   while(great(str2,tmp)){
      tmp.push_back(str1[ind]);
      ind++;
   }
  // cout<<tmp<<endl;

   ans.push_back((small_divide(tmp,str2)));
   


   // Now we have tmp which is bigger than str2.....
   string rem=small_rem(tmp,str2);
   
   while(ind<size_1){
         rem.push_back(str1[ind]);
         rem=rectify(rem);
        
         ans.push_back(small_divide(rem,str2));
         
         rem=small_rem(rem,str2);
         ind++;
   }
   return ans;
}


UnlimitedInt::  UnlimitedInt(){               // Time_pass...

     size=0;
     sign=1;                           
     capacity=1;
     unlimited_int=new int[capacity];

}

UnlimitedInt::  UnlimitedInt(string s){

     capacity=2*s.size();
     unlimited_int=new int[capacity];
     
     if(s[0]=='-'){          // Sign
        size=s.size()-1;
        sign=-1;
        for(int i=0;i<s.size()-1;i++){
        unlimited_int[i]=(s[i+1]-'0');
        }
     }
     else if(s[0]=='0'){
        size=1;
        sign=0;
        unlimited_int[0]=0;
     }
     else{
        size=s.size();
        sign=1;
        for(int i=0;i<s.size();i++){
        unlimited_int[i]=(s[i]-'0');    
        }
    }  

}

UnlimitedInt::  UnlimitedInt(int i){                // For now assuming it to be only positive....

     size=log_10(i);                                // Majorly would not be used....

     capacity=2*size;

     unlimited_int=new int[capacity];
     int i_copy=i;
     int x=10;

     for(int j=0;j<size;j++){
      unlimited_int[size-j-1]=(i_copy)%10;
      i_copy=i_copy/10;
     }

     if(i==0) sign=0;    
     else sign=1;

}

UnlimitedInt:: UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz){
 
    unlimited_int=ulimited_int;
    capacity=cap;
    sign=sgn;
    size=sz;

}

UnlimitedInt:: ~UnlimitedInt(){

   delete [] unlimited_int;

}

// Return the size of the unlimited int
int UnlimitedInt:: get_size(){
   return size;
}

// Return the unlimited_int array
int* UnlimitedInt:: get_array(){
   return unlimited_int;
}

// Get sign
int UnlimitedInt::get_sign(){
   return sign;
}

// Get capacity
int UnlimitedInt::get_capacity(){
   return capacity;
}

string UnlimitedInt::to_string(){
   string s="";
   for(int i=0;i<size;i++){
      s.push_back(unlimited_int[i]+'0');
   }
   if(sign==-1){
      s="-"+s;
   }
   return s;
}

// Implement these integer operations as they are defined for integers in mathematics
// (Since there are no size restrictions)

UnlimitedInt* UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2){

int sign1=i1->get_sign();
int sign2=i2->get_sign();

if((sign1==1|| sign1==0) && (sign2==1|| sign2==0)){         //CASE_add_1     
   string str1=mag(i1->to_string());
   string str2=mag(i2->to_string());

   string ans=magnitude_add(str1,str2);       
   UnlimitedInt* p=new UnlimitedInt(ans);
   return p;
}

if(sign1==-1 && (sign2==1||sign2==0)){                      //CASE_add_2

   string s1=mag(i1->to_string());
   string s2=mag(i2->to_string());
   string diff=magnitude_sub(s1,s2);
   if(great(s2,s1)){
      UnlimitedInt* p=new UnlimitedInt(diff);
      return p;
   }
   else{
      diff="-"+diff;
      UnlimitedInt* p=new UnlimitedInt(diff);
      return p;
   }
      }

if((sign1==1||sign1==0) && sign2==-1){                      // CASE_add_3

   string s1=mag(i1->to_string());
   string s2=mag(i2->to_string());
   string diff=magnitude_sub(s1,s2);
   if(great(s1,s2)){
      UnlimitedInt* p=new UnlimitedInt(diff);
      return p;
   }
   else{
      diff="-"+diff;
      UnlimitedInt* p=new UnlimitedInt(diff);
      return p;
   }
} 

if((sign1==-1) && (sign2==-1)){                             // CASE_add_4

   string str1=mag(i1->to_string());
   string str2=mag(i2->to_string());

   string ans=magnitude_add(str1,str2);     
   ans="-"+ans;  
   UnlimitedInt* p=new UnlimitedInt(ans);
   return p;

}
}

UnlimitedInt* UnlimitedInt::sub(UnlimitedInt* i1, UnlimitedInt* i2){

   int sign1=i1->get_sign();
   int sign2=i2->get_sign();

   if((sign1==1|| sign1==0) && (sign2==1||sign2==0)){  // CASE_sub_1

            string s1=mag(i1->to_string());
            string s2=mag(i2->to_string());

            string ans=magnitude_sub(s1,s2);
            if(great(s1,s2)){
               UnlimitedInt* p=new UnlimitedInt(ans);
               return p;
            }
            else{
               ans="-"+ans;
               UnlimitedInt* p=new UnlimitedInt(ans);
               return p;
            }
          
   }
   if(sign1==-1 && sign2!=-1){                        //CASE_sub_2

            string str1=mag(i1->to_string());
            string str2=mag(i2->to_string());

            string ans=magnitude_add(str1,str2);     
            ans="-"+ans;  
            UnlimitedInt* p=new UnlimitedInt(ans);
            return p;

   }
   if(sign1!=-1 && sign2==-1){                         //CASE_sub_3
            string str1=mag(i1->to_string());
            string str2=mag(i2->to_string());

            string ans=magnitude_add(str1,str2);       
            UnlimitedInt* p=new UnlimitedInt(ans);
            return p;
   }

   if(sign1==-1 && sign2==-1){                        //CASE_sub_4

            string s1=mag(i1->to_string());
            string s2=mag(i2->to_string());

            string ans=magnitude_sub(s1,s2);
            if(great(s2,s1)){
               UnlimitedInt* p=new UnlimitedInt(ans);
               return p;
            }
            else{
               ans="-"+ans;
               UnlimitedInt* p=new UnlimitedInt(ans);
               return p;
            }
   }
}


UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2){


   int sign1=i1->get_sign();
   int sign2=i2->get_sign();

   if(sign1*sign2==0){                       // CASE_1_MUL
            string str1=mag(i1->to_string());
            string str2=mag(i2->to_string());

            string ans=magnitude_mul(str1,str2);       
            UnlimitedInt* p=new UnlimitedInt(ans);
            return p;
   }
   if(sign1*sign2==1){                        // CASE_2_MUL

            string str1=mag(i1->to_string());
            string str2=mag(i2->to_string());

            string ans=magnitude_mul(str1,str2);       
            UnlimitedInt* p=new UnlimitedInt(ans);
            return p;
   }
   if((sign1*sign2)==-1){                      // CASE_3_MUL

            string str1=mag(i1->to_string());
            string str2=mag(i2->to_string());

            string ans=magnitude_mul(str1,str2);   
            ans="-"+ans;    
            UnlimitedInt* p=new UnlimitedInt(ans);
            return p;
   }
}

UnlimitedInt* UnlimitedInt::div(UnlimitedInt* i1, UnlimitedInt* i2){

   int sign1=i1->get_sign();
   int sign2=i2->get_sign();

   if(sign1==0){                                  // CASE_1_div
            string str1=mag(i1->to_string());
            string str2=mag(i2->to_string());

            string ans=magnitude_div(str1,str2);       
            UnlimitedInt* p=new UnlimitedInt(ans);
            return p;
   }
   if(sign1*sign2==1){                             // CASE_2_div

            string str1=mag(i1->to_string());
            string str2=mag(i2->to_string());

            string ans=magnitude_div(str1,str2);       
            UnlimitedInt* p=new UnlimitedInt(ans);
            return p;

   }
   if((sign1*sign2)==-1){                          // CASE_3_div

            string str1=mag(i1->to_string());
            string str2=mag(i2->to_string());

            string ans=magnitude_div(str1,str2);   
            ans="-"+ans;    
            UnlimitedInt* p=new UnlimitedInt(ans);
            return p;
   }
}

 UnlimitedInt* UnlimitedInt::mod(UnlimitedInt* i1, UnlimitedInt* i2){     
         return sub(i1,mul(i2,div(i1,i2)));
}
