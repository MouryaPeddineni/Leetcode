class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        HashMap<Integer, Integer> hm = new HashMap<>();
        int []ans = new int[n];
        int []greater = new int[m];
        for(int i=0;i<m;i++) {
            hm.put(nums2[i], i);
        }
        Stack<Integer> st = new Stack<>();
        for(int i=m-1;i>=0;i--) {
            while(!st.isEmpty() && st.peek() <= nums2[i]) {
                st.pop();
            }
            if(st.isEmpty()) greater[i] = -1;
            else greater[i] = st.peek();
            st.push(nums2[i]);
        }
        for(int i=0;i<n;i++) {
            ans[i] = greater[hm.get(nums1[i])];
        }
        return ans;
    }
}