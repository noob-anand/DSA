class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0,c=0;
        int m =prices[0];
        for(int i =1;i<prices.size();i++){
            c=prices[i]-m;
            p=max(p,c);
            m=min(m,prices[i]);
        }
        return p;
    }
};