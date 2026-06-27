class Solution {
public:
    int f(int i, int b, int n, vector<int>& a,
          vector<vector<vector<int>>>& dp) {
        if (n == 0)
            return 0;
        if (i == a.size())
            return 0;
        if (dp[i][b][n] != -1)
            return dp[i][b][n];
        int p;
        if (b) {
            int nt = f(i + 1, 1, n, a,dp);
            int t = f(i + 1, 0, n, a,dp) - a[i];
            p = max(t, nt);
        } else {
            int s = f(i + 1, 1, n - 1, a,dp) + a[i];
            int ns = f(i + 1, 0, n, a,dp);
            p = max(s, ns);
        }
        return dp[i][b][n] = p;
    }
    int maxProfit(vector<int>& a) {
        vector<vector<vector<int>>> dp(
            a.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, a, dp);
    }
};