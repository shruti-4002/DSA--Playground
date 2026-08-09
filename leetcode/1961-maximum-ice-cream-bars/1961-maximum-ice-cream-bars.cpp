class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i=0;
        int Sum=0;
        while(Sum<=coins && i<costs.size()){
            if(costs[i]>coins){
                break;
            }

            if(Sum+costs[i]>coins){
                break;
            }
            
            Sum+=costs[i];
            i++;
        }

        return i;
    }
};