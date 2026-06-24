class Solution {
public:
    int minInsertions(string s1) {
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        int n = s1.size(),m=n;

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    cur[j] = 1 + prev[j - 1];
                else
                    cur[j] = max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }

        return (n-prev[m]);
    }
};