class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> cnt(n, 1);

        int bestLen = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i]) {
                    if (len[prev] + 1 == len[i])
                        cnt[i] += cnt[prev];

                    if (len[prev] + 1 > len[i]) {
                        len[i] = len[prev] + 1;
                        cnt[i] = cnt[prev];
                    }
                }
            }
            bestLen = max(bestLen, len[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (bestLen == len[i])
                ans += cnt[i];
        return ans;
    }
};