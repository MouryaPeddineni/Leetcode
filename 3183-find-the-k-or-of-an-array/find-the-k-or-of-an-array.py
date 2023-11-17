class Solution:
    def findKOr(self, nums: List[int], k: int) -> int:
        bit = [0]*32
        for i in nums:
            for j in range(32):
                if (i>>j)&1:
                    bit[j]+=1
        res=0
        for i in range(32):
            if bit[i]>=k:
                res |= (1<<i)
        return res