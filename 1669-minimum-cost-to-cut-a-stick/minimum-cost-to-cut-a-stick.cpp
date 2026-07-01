class Solution {
public:
    int f(int i, int j, vector<int>& a, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        int mi = 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        for (int k = i; k <= j; k++) {
            int st =
                (a[j + 1] - a[i - 1]) + f(i, k - 1, a, dp) + f(k + 1, j, a, dp);
            mi = min(st, mi);
        }
        return dp[i][j] = mi;
    }
    int minCost(int n, vector<int>& a) {
        sort(a.begin(), a.end());
        int m = a.size();
        a.push_back(n);
        a.insert(a.begin(), 0);
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, -1));
        return f(1, m, a, dp);
    }
};