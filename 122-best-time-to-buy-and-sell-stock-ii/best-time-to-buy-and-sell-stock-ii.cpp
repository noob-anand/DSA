class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<int> prev(2, 0),cur(2,0);
        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 2; b++) {
                int p;
                if (b) {
                    int nt = prev[1];
                    int t = prev[0] - a[i];
                    p = max(t, nt);
                } else {
                    int s = prev[1] + a[i];
                    int ns = prev[0];
                    p = max(s, ns);
                }
                cur[b] = p;
            }
            prev =cur;
        }
        return cur[1];
    }
};