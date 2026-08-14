class Solution {
public:
    int findMin(vector<int> &nums) { 
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] < nums[n-1]) return nums[0];

        int l = 0, r = n-1;
        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] > nums[m+1]) {
                return nums[m+1];
            }
            if (nums[m] < nums[m-1]) {
                return nums[m];
            }
            if (nums[m] > nums[l]) {
                l = m+1;
            } else if (nums[m] < nums[r]) {
                r = m-1;
            }
        }
        return -1001;
    }
};
