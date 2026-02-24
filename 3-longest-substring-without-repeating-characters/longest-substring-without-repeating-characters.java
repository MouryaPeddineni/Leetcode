class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(n == 0) return 0;
        int i=0, j=0, maxi = 1;
        Map<Character, Integer> map = new HashMap<>(); 
        while(j<n) {
            if(map.get(s.charAt(j)) != null) {
                if(map.get(s.charAt(j)) >= i) {
                    i = map.get(s.charAt(j)) + 1;
                }
            }
            map.put(s.charAt(j), j);
            maxi = Math.max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
}