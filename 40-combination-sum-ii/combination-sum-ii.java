class Solution {
    public void comb(int i, List<Integer> sub, List<List<Integer>> ans, int[] candidates, int t) {
        if (t == 0) {
            ans.add(new ArrayList<>(sub));
            return;
        }
        if (i == candidates.length) return;
        if (t < candidates[i]) return;
        for (int ind = i; ind < candidates.length; ind++) {
            if (ind > i && candidates[ind - 1] == candidates[ind]) continue;
            sub.add(candidates[ind]);
            comb(ind + 1, sub, ans, candidates, t - candidates[ind]);
            sub.remove(sub.size() - 1);
        }
        return;
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> sub = new ArrayList<>();
        Arrays.sort(candidates);
        comb(0, sub, ans, candidates, target);
        return ans;
    }
}