#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
#define print(a) cout << a <<" "
#define printn(a) cout << a << endl
void printa(vector<int> &a,string fl="") { for(int w:a) print(w); printn(fl);}
void printa2(vector<vector<int>> &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } printn("");}
string itoa2(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */


/*

<!-- @lc app=leetcode.cn id=2917 lang=cpp -->

[2917] 找出数组中的 K-or 值

https://leetcode.cn/problems/find-the-k-or-of-an-array/description/

algorithms
Easy (70.73%)
Likes:    5
Dislikes: 0
Total Accepted:    5.5K
Total Submissions: 7.8K
Testcase Example:  '[7,12,9,8,9,15]\n4'

给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

nums 中的 K-or 是一个满足以下条件的非负整数：


只有在 nums 中，至少存在 k 个元素的第 i 位值为 1 ，那么 K-or 中的第 i 位的值才是 1 。


返回 nums 的 K-or 值。

注意 ：对于整数 x ，如果 (2^i AND x) == 2^i ，则 x 中的第 i 位值为 1 ，其中 AND 为按位与运算符。



示例 1：


输入：nums = [7,12,9,8,9,15], k = 4
输出：9
解释：nums[0]、nums[2]、nums[4] 和 nums[5] 的第 0 位的值为 1 。
nums[0] 和 nums[5] 的第 1 位的值为 1 。
nums[0]、nums[1] 和 nums[5] 的第 2 位的值为 1 。
nums[1]、nums[2]、nums[3]、nums[4] 和 nums[5] 的第 3 位的值为 1 。
只有第 0 位和第 3 位满足数组中至少存在 k 个元素在对应位上的值为 1 。因此，答案为 2^0 + 2^3 = 9 。


示例 2：


输入：nums = [2,12,1,11,4,5], k = 6
输出：0
解释：因为 k == 6 == nums.length ，所以数组的 6-or 等于其中所有元素按位与运算的结果。因此，答案为 2 AND 12 AND
1 AND 11 AND 4 AND 5 = 0 。


示例 3：


输入：nums = [10,8,5,9,11,6,8], k = 1
输出：15
解释：因为 k == 1 ，数组的 1-or 等于其中所有元素按位或运算的结果。因此，答案为 10 OR 8 OR 5 OR 9 OR 11 OR 6
OR 8 = 15 。



提示：


1 <= nums.length <= 50
0 <= nums[i] < 2^31
1 <= k <= nums.length




 */

// @lc code=start
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        
        vector<int> cnt(33,0);
        int n = nums.size();
        for (int i=0;i<n;i++) {
            int x = nums[i];
            int j=0;
            while (j<=31) {
                if((x>>j)&1) cnt[j]++;
                j++;
            }
        }
        int mask=0;
        for (int i=0;i<31;i++) {
            if (cnt[i] >=k) {
                mask |= (1<<i);
            }
        }
        #ifdef debug
        printa(nums);
        printa(cnt);
        printn(itoa2(mask));
        #endif
        return mask;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2917] 找出数组中的 K-or 值" << endl;
    #endif

    Solution k;
    vector<int> x = {7,12,9,8,9,15};
    cout << k.findKOr(x,4)<<endl;
    return 0;
}
