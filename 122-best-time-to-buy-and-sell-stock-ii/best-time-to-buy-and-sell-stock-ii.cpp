class Solution {
public:
    int f(int i, int b, vector<int>& a, vector<vector<int>>& dp) {
        if (i == a.size())
            return 0;
        if (dp[i][b] != -1)
            return dp[i][b];
        int p;
        if (b) {
            int nt = f(i + 1, 1, a, dp);
            int t = f(i + 1, 0, a, dp) - a[i];
            p = max(t, nt);
        } else {
            int s = f(i + 1, 1, a, dp) + a[i];
            int ns = f(i + 1, 0, a, dp);
            p = max(s, ns);
        }
        return dp[i][b] = p;
    }

    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 2; b++) {
                int p;
                if (b) {
                    int nt = dp[i + 1][1];
                    int t = dp[i + 1][0] - a[i];
                    p = max(t, nt);
                } else {
                    int s = dp[i + 1][1] + a[i];
                    int ns = dp[i + 1][0];
                    p = max(s, ns);
                }
                dp[i][b] = p;
            }
        }
        return dp[0][1];
    }
};