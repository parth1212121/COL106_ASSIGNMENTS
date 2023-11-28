/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"




//--> *********DO SEE IF THIS IS ALLOWED!!!!******** <----

//--> *********DO SEE IF THIS IS ALLOWED!!!!******** <----

//--> *********DO SEE IF THIS IS ALLOWED!!!!******** <----


//--> *********DO SEE IF THIS IS ALLOWED!!!!******** <----


string mag2(string s){
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

bool great2(string s1,string s2){

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

int log_102(int i){
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

string magnitude_add2(string str1,string str2){

 
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

string magnitude_sub2(string str1,string str2){

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


string magnitude_mul2(string str1,string str2){

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

char small_divide2(string tmp,string str2){

   if(great2(str2,tmp)){
      return '0';
   }
   else{
   int x=0;
   string str2_cpy=str2;
   while(great2(tmp,str2) || tmp==str2){
      str2=magnitude_add2(str2_cpy,str2);
      x++;
   }

   return (x+'0');

   }
}

string small_rem2(string tmp,string str2){
   if(great2(str2,tmp)){
      return tmp;
   }
   else{
      string y="";
      char c=small_divide2(tmp,str2);
     
      y.push_back(c);
 
      string x=magnitude_mul2(str2,y);
  
      string ans=magnitude_sub2(tmp,x);
      return ans;
   } 
}
string rectify2(string s){
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

string magnitude_div2(string str1,string str2){

   int size_1=str1.size();
   int size_2=str2.size();
   
   if(str1=="0"){
      return "0";
   }
   if(great2(str2,str1)){
    return "0";
   }
   string ans="";

   string tmp="";
   int ind=0;
   while(great2(str2,tmp)){
      tmp.push_back(str1[ind]);
      ind++;
   }
  // cout<<tmp<<endl;

   ans.push_back((small_divide2(tmp,str2)));
   


   // Now we have tmp which is bigger than str2.....
   string rem=small_rem2(tmp,str2);
   
   while(ind<size_1){
         rem.push_back(str1[ind]);
         rem=rectify2(rem);
        
         ans.push_back(small_divide2(rem,str2));
         
         rem=small_rem2(rem,str2);
         ind++;
   }
   return ans;
}





/////------>









/////------>


string magnitude_mod(string str1,string str2){

    string a1=magnitude_div2(str1,str2);
    string a2=magnitude_mul2(str2,a1);
    string ans=magnitude_sub2(str1,a2);
    return ans;

}

/////------>

string  gcd_pos(string n,string d){

    if(great2(n,d)){
        if(magnitude_mod(n,d)=="0"){            
            return d;
        }
        else{
            return gcd_pos(magnitude_mod(n,d),d);
        }
    }
    else{
        if(magnitude_mod(d,n)=="0"){            
            return n;
        }
        else{
            return gcd_pos(n,magnitude_mod(d,n));
        }
    }
}

UnlimitedInt* gcd(UnlimitedInt* p,UnlimitedInt* q){     // My gcd will always be positive.....

    string n=mag2(p->to_string());
    string d=mag2(q->to_string());

    string ans=gcd_pos(n,d);

    UnlimitedInt* res=new UnlimitedInt(ans);
    return res;

}

void coprime(UnlimitedInt* &p,UnlimitedInt* &q){

    UnlimitedInt* GCD=gcd(p,q);
    p=p->div(p,GCD);
    q=q->div(q,GCD);
    return;

}


UnlimitedRational:: UnlimitedRational(){        // NO_USE...

}

UnlimitedRational:: UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){
  
        if(den->to_string()=="0"){
            UnlimitedInt* n=new UnlimitedInt("0");
            UnlimitedInt* d=new UnlimitedInt("0");
            p=n;
            q=d;
        }
        else if(num->to_string()=="0"){
            p=num;
            q=den;
        }
        else{
        coprime(num,den);
        p=num;
        q=den;
        }

}

UnlimitedRational::~UnlimitedRational(){

     delete  p;                              // Once check and discuss........
     delete  q;                              // Sometimes this doesnt works.....

}

UnlimitedInt* UnlimitedRational:: get_p(){
    return p;
}

UnlimitedInt* UnlimitedRational:: get_q(){
    return q;
}

string UnlimitedRational::get_p_str(){
    return p->to_string();
}

string UnlimitedRational::get_q_str(){
    return q->to_string();
}

string UnlimitedRational::get_frac_str(){
  
        return (p->to_string()+"/"+q->to_string());
    
} 

UnlimitedRational* UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2){

                if(i2->get_frac_str()=="0/0" || i1->get_frac_str()=="0/0"){

                    UnlimitedInt* n=new UnlimitedInt("0");
                    UnlimitedInt* d=new UnlimitedInt("0");
                    UnlimitedRational* r=new UnlimitedRational(n,d);
                    return r;

                }


                UnlimitedInt* p1=i1->get_p();
                UnlimitedInt* q1=i1->get_q();

                UnlimitedInt* p2=i2->get_p();
                UnlimitedInt* q2=i2->get_q();

                UnlimitedInt *n1=p1->mul(p1,q2);
                UnlimitedInt *n2=p2->mul(p2,q1);
                UnlimitedInt* n=n1->add(n1,n2);

                UnlimitedInt* d= q1->mul(q1,q2);

                UnlimitedRational* ans=new UnlimitedRational(n,d);
                return ans;

}

UnlimitedRational* UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2){

                if(i2->get_frac_str()=="0/0" || i1->get_frac_str()=="0/0"){

                    UnlimitedInt* n=new UnlimitedInt("0");
                    UnlimitedInt* d=new UnlimitedInt("0");
                    UnlimitedRational* r=new UnlimitedRational(n,d);
                    return r;

                }

                UnlimitedInt* p1=i1->get_p();
                UnlimitedInt* q1=i1->get_q();

                UnlimitedInt* p2=i2->get_p();
                UnlimitedInt* q2=i2->get_q();

                UnlimitedInt *n1=p1->mul(p1,q2);
                UnlimitedInt *n2=p2->mul(p2,q1);
                UnlimitedInt* n=n1->sub(n1,n2);

                UnlimitedInt* d= q1->mul(q1,q2);

                UnlimitedRational* ans=new UnlimitedRational(n,d);
                return ans;

}


UnlimitedRational* UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2){

                if(i2->get_frac_str()=="0/0" || i1->get_frac_str()=="0/0"){

                    UnlimitedInt* n=new UnlimitedInt("0");
                    UnlimitedInt* d=new UnlimitedInt("0");
                    UnlimitedRational* r=new UnlimitedRational(n,d);
                    return r;

                }

                UnlimitedInt* p1=i1->get_p();
                UnlimitedInt* q1=i1->get_q();

                UnlimitedInt* p2=i2->get_p();
                UnlimitedInt* q2=i2->get_q();

                UnlimitedInt* n=p1->mul(p1,p2);
                UnlimitedInt* d= q1->mul(q1,q2);

                UnlimitedRational* ans=new UnlimitedRational(n,d);
                return ans;

}

UnlimitedRational* UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){

                if(i2->get_frac_str()=="0/0" || i1->get_frac_str()=="0/0"){

                    UnlimitedInt* n=new UnlimitedInt("0");
                    UnlimitedInt* d=new UnlimitedInt("0");
                    UnlimitedRational* r=new UnlimitedRational(n,d);
                    return r;

                }

                UnlimitedInt* p1=i1->get_p();
                UnlimitedInt* q1=i1->get_q();

                UnlimitedInt* p2=i2->get_p();
                UnlimitedInt* q2=i2->get_q();

                UnlimitedInt* n=p1->mul(p1,q2);
                UnlimitedInt* d= q1->mul(q1,p2);

                UnlimitedRational* ans=new UnlimitedRational(n,d);
                return ans;

}


















