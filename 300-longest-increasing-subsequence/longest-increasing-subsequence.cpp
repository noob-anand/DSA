class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> prev(n + 1, 0), cur(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int p = i - 1; p >= -1; p--) {
                int nt = prev[p + 1];
                int t = 0;
                if (p == -1 || a[i] > a[p])
                    t = 1 + prev[i + 1];
                cur[p + 1] = max(nt, t);
            }
            prev=cur;
        }
        return cur[0];
    }
};