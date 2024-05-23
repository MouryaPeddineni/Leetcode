/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    const ans = [];
    const sub = [];
    
    candidates.sort((a, b) => a - b);
    
    const comb = function(i, sub, ans, candidates, t) {
        if (t === 0) {
            ans.push([...sub]);
            return;
        }
        if (i === candidates.length || t < candidates[i]) return;
        for (let ind = i; ind < candidates.length; ind++) {
            if (ind > i && candidates[ind - 1] === candidates[ind]) continue;
            sub.push(candidates[ind]);
            comb(ind + 1, sub, ans, candidates, t - candidates[ind]);
            sub.pop();
        }
    }
    
    comb(0, sub, ans, candidates, target);
    return ans;
};