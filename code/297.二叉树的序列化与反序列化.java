/*
 * @lc app=leetcode.cn id=297 lang=java
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (41.87%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 21.3K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * 
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 
 * 示例: 
 * 
 * 你可以将以下二叉树：
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * 序列化为 "[1,2,3,null,null,4,5]"
 * 
 * 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 
 * 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList();
        queue.add(root);
        StringBuilder sb = new StringBuilder("[");
        while(!queue.isEmpty())
        {
            TreeNode m = queue.poll();
            sb.append(m==null? "null":m.val);
            

            if(m.left!=null)
            {
                queue.add(m.left);
            }
            if(m.right!=null)
            {
                queue.add(m.right);
            }
            if(!queue.isEmpty())
            {
                sb.append(",");
            }
        }
        sb.append("]");

        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        data = data.replace("[|]", "");
        String[] vals = data.split(",");
        if(vals.length<=0) return null;
        int val = Integer.parseInt(vals[0]);
        TreeNode ans = new TreeNode(val);
        ans.left = dfs(vals,1);
        ans.right = dfs(vals,2);
        return ans;

    }

    public TreeNode dfs(String[] arr,int i)
    {
        if(i>=arr.length) return null;
        TreeNode ans = null;
        if(!arr[i].equals("null"))
        {
            int val = Integer.parseInt(arr[i]);
            ans = new TreeNode(val);
            i = i<<1;
            ans.left = dfs(arr,i+1);
            ans.right = dfs(arr,i+2);
        }
        return ans;

    }

    
    
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
// @lc code=end

