class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int b = 0;
        int res = 0;

        for(int s=0; s<n; s++){
            if(prices[s] > prices[b]){
                res += prices[s] - prices[b];
            }
            b=s;
        }
        return res;
    }
};