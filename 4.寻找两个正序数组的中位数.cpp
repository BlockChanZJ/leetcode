/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    int findKthElement(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        int idx1 = 0, idx2 = 0;
        while (1) {
            if (idx1 == n) {
                return nums2[idx2 + k - 1];
            } 
            if (idx2 == m) {
                return nums1[idx1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[idx1], nums2[idx2]);
            }
            int nidx1 = min(idx1 + k / 2 - 1, n - 1);
            int nidx2 = min(idx2 + k / 2 - 1, m - 1); 
            int pivot1 = nums1[nidx1];
            int pivot2 = nums2[nidx2];
            //cout << idx1 << " " << idx2 << endl;
            if (pivot1 <= pivot2) {
                k -= nidx1 - idx1 + 1;
                idx1 = nidx1 + 1;
            } else {
                k -= nidx2 - idx2 + 1;
                idx2 = nidx2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        if (sum % 2) {
            return findKthElement(nums1, nums2, sum / 2 + 1);
        } else {
            return (findKthElement(nums1, nums2, sum / 2) + findKthElement(nums1, nums2, sum / 2 + 1)) / 2.0;
        }
    }
};
// @lc code=end

