class Solution {
public:
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