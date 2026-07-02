class Solution {
public:
    int f(int i, int j, vector<int>& a,vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        int ma = 0;
        for (int k = i; k <= j; k++) {
            int c = a[i - 1] * a[k] * a[j + 1] 
            + f(i, k - 1, a,dp) 
            + f(k + 1, j, a,dp);
            ma = max(ma, c);
        }
        return dp[i][j]= ma;
    }
    int maxCoins(vector<int>& a) {
        int n = a.size();
        a.push_back(1);
        a.insert(a.begin(), 1);
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        return f(1, n, a,dp);
    }
};