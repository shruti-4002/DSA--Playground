class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;

        for(int x:stones){
            q.push(x);
        }


        while(!q.empty()){
            if(q.size()==1){
                return q.top();
            }
        int p1=q.top();
        q.pop();
        int p2=q.top();
        q.pop();

        q.push(p1-p2);
    

        }

        return 0;
    }
};