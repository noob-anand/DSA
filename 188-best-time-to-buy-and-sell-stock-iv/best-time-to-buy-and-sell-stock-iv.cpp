class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int m = a.size();
        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for (int i = m - 1; i >= 0; i--) {
            for (int b = 0; b <= 1; b++) {
                for (int n = 1; n <= k; n++) {
                    if (b) {
                        int buy = dp[i + 1][0][n] - a[i];
                        int skip = dp[i + 1][1][n];
                        dp[i][b][n] = max(buy, skip);
                    } else {
                        int sell = dp[i + 1][1][n - 1] + a[i];
                        int skip = dp[i + 1][0][n];
                        dp[i][b][n] = max(sell, skip);
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};