class Solution {
private: 
    int re(vector<int>& nums, int target, int l, int r) {
        if (l > r) {
            return l;
        }
        if (l == r) {
            return l;
        }
        int mid = (l+r)/2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            return re(nums, target, l, mid-1);
        }
        return re(nums, target, mid+1, r);
    }
public:
    int search(vector<int>& nums, int target) {
        int k = re(nums, target, 0, nums.size()-1);
        if (nums[k] == target)
            return k;
        return -1;
    }
};
