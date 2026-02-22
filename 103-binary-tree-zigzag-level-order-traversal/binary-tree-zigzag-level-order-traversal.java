/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null)
            return ans;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        int cnt = 0;
        while (!queue.isEmpty()) {
            int sz = queue.size();
            List<Integer> sub = new ArrayList<>();
            cnt++;
            for (int i = 0; i < sz; i++) {
                TreeNode node = queue.peek();
                sub.add(node.val);
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
                queue.poll();
            }
            if(cnt % 2 == 0) {
                Collections.reverse(sub);
            }
            ans.add(sub);
        }
        return ans;
    }
}