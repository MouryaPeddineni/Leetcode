class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        a=max(candies)
        res=candies
        for i in range(len(candies)):
            if (candies[i]+extraCandies>=a):
                res[i]=True
            else:
                res[i]=False
        return res            

        