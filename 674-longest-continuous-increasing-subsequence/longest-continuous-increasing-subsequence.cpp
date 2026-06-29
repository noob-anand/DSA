class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = 1, maxi = len;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                maxi = max(maxi, ++len);
            else
                len = 1;
        }
        return maxi;
    }
};