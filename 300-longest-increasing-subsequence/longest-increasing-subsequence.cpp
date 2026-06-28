class Solution {
public:
    int f(int i, int p, vector<int>& a, vector<vector<int>>& dp) {
        if (i == a.size())
            return 0;
        if (dp[i][p+1] != -1)
            return dp[i][p+1];
        int nt = f(i + 1, p, a, dp);
        int t = 0;
        if (p == -1 || a[i] > a[p])
            t = 1 + f(i + 1, i, a, dp);
        return dp[i][p+1] = max(nt, t);
    }
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n , vector<int>(n+1, -1));
        return f(0, -1, a, dp);
    }
};