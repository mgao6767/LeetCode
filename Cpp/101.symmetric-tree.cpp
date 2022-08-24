/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (52.41%)
 * Likes:    10694
 * Dislikes: 249
 * Total Accepted:    1.4M
 * Total Submissions: 2.6M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Could you solve it both recursively and iteratively?
 */

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// @lc code=start
#include <vector>

class Solution {
private:
  bool isMirror(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr && t2 == nullptr)
      return true;
    if (t1 == nullptr || t2 == nullptr)
      return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) &&
           isMirror(t1->left, t2->right);
  }

public:
  bool isSymmetric(TreeNode *root) { return isMirror(root, root); }
};
// @lc code=end
