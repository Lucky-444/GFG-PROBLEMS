class Solution {
  public:
   string compress(string &s) {
       // code here
       int n=s.size();

       int j=n;
       string ans="";
       while(true){
           j=j/2;
           ans="";
           while(j>0){
               int len=j;
               string t1=s.substr(0,j);
               string t2=s.substr(j,j);

               // cout<<t1<<" "<<t2<<endl;

               if(t1==t2){
                   ans+=t1;
                   ans+="*";
                   string rem=s.substr(2*j);
                   ans+=rem;
                   // cout<<ans<<endl;
                   s=ans;
                   break;
               }
               else{
                   j--;
               }

           }
           if(j<=0)break;
       }

       return s;
   }
};
