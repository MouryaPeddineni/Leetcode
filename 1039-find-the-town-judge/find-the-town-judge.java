class Solution {
    public int findJudge(int n, int[][] trust) {
        int m = trust.length;
        if(n==1 && m==0) return 1; 
        Map<Integer, Integer> mpp = new HashMap<>();
        for(int i=0;i<m;i++) {
            mpp.put(trust[i][1], 1 + mpp.getOrDefault(trust[i][1], 0));
            mpp.put(trust[i][0], mpp.getOrDefault(trust[i][0], 0) - 1);
        }
        Iterator hmIterator = mpp.entrySet().iterator();
        while(hmIterator.hasNext()) {
            Map.Entry mapElement
                = (Map.Entry)hmIterator.next();
            int mem = (int)mapElement.getValue();
            if(mem == n-1) return (int)mapElement.getKey();
        }
        return -1;
    }
}