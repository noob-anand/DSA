class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int ma = 1;
        int c = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] < a[i]) {
                c++;
                ma = max(c, ma);
            } else {
                c = 1;
            }
        }
        return ma;
    }
};