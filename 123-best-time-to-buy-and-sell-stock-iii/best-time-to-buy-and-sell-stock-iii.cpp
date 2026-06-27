class Solution {
public:
    int maxProfit(vector<int>& a) {
        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));
        for (int i = a.size() - 1; i >= 0; i--) {
            for (int b = 0; b <= 1; b++) {
                for (int n = 1; n <= 2; n++) {
                    if (b) {
                        int buy = prev[0][n] - a[i];
                        int skip = prev[1][n];
                        cur[b][n] = max(buy, skip);
                    } else {
                        int sell = prev[1][n - 1] + a[i];
                        int skip = prev[0][n];
                        cur[b][n] = max(sell, skip);
                    }
                }
            }
            prev = cur;
        }
        return prev[1][2];
    }
};