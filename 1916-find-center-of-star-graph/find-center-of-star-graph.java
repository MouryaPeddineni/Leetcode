class Solution {
    public int findCenter(int[][] edges) {
        int n = edges.length;
        int cntHighest = 0, node = 0;
        Map<Integer, Integer> mpp = new HashMap<>();
        for(int i=0;i<n;i++) {    
            mpp.put(edges[i][0], 1 + mpp.getOrDefault(edges[i][0], 0));
            mpp.put(edges[i][1], 1 + mpp.getOrDefault(edges[i][1], 0));
            if(mpp.get(edges[i][0]) > cntHighest) {
                node = edges[i][0];
                cntHighest = mpp.get(edges[i][0]);
            }
            if(mpp.get(edges[i][1]) > cntHighest) {
                node = edges[i][1];
                cntHighest = mpp.get(edges[i][0]);
            }
        }
        return node;
    }
}