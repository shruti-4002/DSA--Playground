class Solution {
public:
int rev(int x){
 long long ans=0;

   
        while(x!=0){
            int c=x%10;
            ans=(ans*10)+c;
        
            x=x/10;
        }

        return ans;
    }

    bool isPalindrome(int x) {
        int reversed=rev(x);
        if(x<0){
            return 0;
        }
        if(reversed==x){
            return true;
        }else{
            return false;
        }
    }
};