class Solution:
    def comb(self, i: int, sub: List[int], ans: List[List[int]], candidates: List[int], t: int) -> None:
        if t == 0:
            ans.append(list(sub))
            return
        if i == len(candidates) or t < candidates[i]:
            return
        for ind in range(i, len(candidates)):
            if ind > i and candidates[ind - 1] == candidates[ind]:
                continue
            sub.append(candidates[ind])
            self.comb(ind + 1, sub, ans, candidates, t - candidates[ind])
            sub.pop()
    
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        sub = []
        candidates.sort()
        self.comb(0, sub, ans, candidates, target)
        return ans