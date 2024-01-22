class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        a=max(candies)
        res=[]
        for i in candies:
            if (i+extraCandies>=a):
                res.append(True)
            else:
                res.append(False)
        return res            

        