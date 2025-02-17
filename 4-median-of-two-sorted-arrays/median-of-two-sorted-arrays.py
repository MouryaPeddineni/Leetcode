class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        m, n = len(nums1), len(nums2)
        low, high = 0, m
        total = m + n
        half = (total + 1) // 2

        while low <= high:
            i = (low + high) // 2
            j = half - i

            left_max1 = nums1[i-1] if i > 0 else float('-inf')
            left_max2 = nums2[j-1] if j > 0 else float('-inf')
            right_min1 = nums1[i] if i < m else float('inf')
            right_min2 = nums2[j] if j < n else float('inf')

            if left_max1 <= right_min2 and left_max2 <= right_min1:
                if total % 2 == 1:
                    return max(left_max1, left_max2)
                else:
                    return (max(left_max1, left_max2) + min(right_min1, right_min2)) / 2.0
            elif left_max1 > right_min2:
                high = i - 1
            else:
                low = i + 1
        return 0.0  # This return is theoretically unreachable given the problem constraints
