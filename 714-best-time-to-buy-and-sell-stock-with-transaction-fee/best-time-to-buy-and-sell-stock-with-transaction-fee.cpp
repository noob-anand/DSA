class Solution {
public:
    int f(int i, int b, vector<int>& a, int fee, vector<vector<int>>& dp) {
        if (i == a.size())
            return 0;

        if (dp[i][b] != -1)
            return dp[i][b];

        int p;
        if (b) {
            int nt = f(i + 1, 1, a, fee, dp);
            int t = f(i + 1, 0, a, fee, dp) - a[i];
            p = max(t, nt);
        } else {
            int s = f(i + 1, 1, a, fee, dp) + a[i] - fee;
            int ns = f(i + 1, 0, a, fee, dp);
            p = max(s, ns);
        }

        return dp[i][b] = p;
    }

    int maxProfit(vector<int>& a, int fee) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, a, fee, dp);
    }
};