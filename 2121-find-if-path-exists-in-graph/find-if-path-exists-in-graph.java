class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        ArrayList<ArrayList<Integer>> l = new ArrayList<>();
        for(int i=0;i<n;i++){
            l.add(new ArrayList<>());
        }
        for(int i=0;i<edges.length;i++){
            if(!l.get(edges[i][0]).contains(edges[i][1]))
                l.get(edges[i][0]).add(edges[i][1]);
             if(!l.get(edges[i][1]).contains(edges[i][0]))
                l.get(edges[i][1]).add(edges[i][0]);
        }
        ArrayDeque<Integer> pq = new ArrayDeque<>();
        boolean [] arr = new boolean [n];
        pq.add(source);
        while(pq.isEmpty()==false){
            int x=pq.poll();
            if(x==destination)
                return true;
            for(Integer val: l.get(x)){
                if(arr[val]==false){
                    pq.add(val);
                    arr[val]=true;
                }
            }
        }
        return false;
        
    }
}