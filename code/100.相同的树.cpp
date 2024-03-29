/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
    bool flag_ = false;
    bool dfs(TreeNode *p,TreeNode *q) {
        if(p&&q) {
            if(p ->val == q->val) {
                return dfs(p->left,q->left) && dfs(p->right,q->right);
            }
            return false;
        }
        if(p==NULL && q==NULL) return true;
        return false;
    }
};
// @lc code=end

