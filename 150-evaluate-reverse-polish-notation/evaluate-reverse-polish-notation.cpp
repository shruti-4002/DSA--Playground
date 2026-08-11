class Solution {
public:
    int evalRPN(vector<string>& arr) {
         stack<int>st;
        
        for(string c:arr){
            if (c == "+" || c == "-"|| c == "*" || c == "/" || c == "^"){
             
               int b=st.top();
               st.pop();
               int a=st.top();
               st.pop();
               int ans;
                
                if(c=="+"){
                    ans=a+b;
                    
                }else if(c=="-"){
                    ans=a-b;
                    
                }else if(c=="*"){
                    ans=a*b;
                }else if(c=="/"){
                  ans= floor(a/b);
                }else{
                   ans=pow(a,b);
                }
                
                st.push(ans);
                
            }else{
                int k=stoi(c);
                st.push(k);
            }
        }
        
       if(st.empty()){
           return -1;
       }else{
           return st.top();
       }
        
    }
    
};