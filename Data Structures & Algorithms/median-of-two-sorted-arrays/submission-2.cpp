class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        if (l1 > l2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int mid = (l1+l2+1)/2;
        int l = 0, r = l1;

        while (l <= r) {
            int i = (l+r)/2;
            int j = mid - i;

            int aleft = (i > 0)? nums1[i-1]: INT_MIN;
            int aright = (i < l1)? nums1[i]: INT_MAX;
            int bleft = (j > 0)? nums2[j-1]: INT_MIN;
            int bright = (j < l2)? nums2[j]: INT_MAX;

            if (aleft <= bright && bleft <= aright) {
                if ((l1+l2)%2) {    // odd
                    return max(aleft, bleft);
                } else {    // even
                    return (double)
                        (min(bright, aright) + max(aleft, bleft))/2;
                }
            } else if (aleft > bright) {
                r = i-1;
            } else {
                l = i+1;
            }
        }
        return -1;
    }
};
