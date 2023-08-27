class Solution:
    def minimumPossibleSum(self, n: int, target: int) -> int:
        l=set()
        i=1
        s=0
        while len(l)<n:
            if target-i not in l:
                l.add(i)
                s+=i
            i+=1
        print(l)
        return s