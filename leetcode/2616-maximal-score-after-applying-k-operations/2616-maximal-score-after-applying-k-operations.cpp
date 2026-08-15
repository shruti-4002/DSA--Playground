class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int count=0;
        long long sum=0;
        for(int x:nums){
            pq.push(x);
        
        }
        while(!pq.empty()){
            
          
            int a=pq.top();

            sum+=a;
            
            pq.pop();
            pq.push((a+2)/3);
             count++;
             if(count==k){
                break;
             }

        }

        return sum;
    }
};