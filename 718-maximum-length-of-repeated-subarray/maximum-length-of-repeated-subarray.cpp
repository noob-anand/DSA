class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int ans = 0;

        for (int d = -(m - 1); d <= n - 1; d++) {
            int i = max(0, d);
            int j = max(0, -d);

            int cur = 0;

            while (i < n && j < m) {
                if (a[i] == b[j]) {
                    cur++;
                    ans = max(ans, cur);
                } else {
                    cur = 0;
                }
                i++;
                j++;
            }
        }

        return ans;
    }
};