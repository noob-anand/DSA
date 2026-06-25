class Solution {
public:
    long long f(int i, int j, string &s, string &t,
                vector<vector<long long>>& dp) {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long nt = f(i - 1, j, s, t, dp);
        long long ta = 0;

        if (s[i] == t[j])
            ta = f(i - 1, j - 1, s, t, dp);

        return dp[i][j] = ta + nt;
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};