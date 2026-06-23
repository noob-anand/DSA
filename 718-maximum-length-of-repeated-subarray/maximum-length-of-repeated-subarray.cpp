class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            fill(cur.begin(), cur.end(), 0);
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    cur[j] = 1 + prev[j - 1];
                    ans = max(ans, cur[j]);
                }
            }
            prev = cur;
        }
        return ans;
    }
};