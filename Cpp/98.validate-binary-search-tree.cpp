/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (31.43%)
 * Likes:    12213
 * Dislikes: 992
 * Total Accepted:    1.6M
 * Total Submissions: 5.2M
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, determine if it is a valid binary search
 * tree (BST).
 *
 * A valid BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [2,1,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is
 * 4.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 */
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

class Solution {

private:
  int min(TreeNode *root) {
    int ml, mr, m = root->val;
    if (root->left != nullptr) {
      ml = min(root->left);
      m = m < ml ? m : ml;
    }
    if (root->right != nullptr) {
      mr = min(root->right);
      m = m < mr ? m : mr;
    }
    return m;
  }
  int max(TreeNode *root) {
    int ml, mr, m = root->val;
    if (root->left != nullptr) {
      ml = max(root->left);
      m = m > ml ? m : ml;
    }
    if (root->right != nullptr) {
      mr = max(root->right);
      m = m > mr ? m : mr;
    }
    return m;
  }
  bool f(TreeNode *root) {
    if (root == nullptr)
      return true;
    if (root->left == nullptr && root->right == nullptr)
      return true;
    if (root->left != nullptr && max(root->left) >= root->val)
      return false;
    if (root->right != nullptr && min(root->right) <= root->val)
      return false;

    return f(root->left) && f(root->right);
  }

public:
  bool isValidBST(TreeNode *root) { return f(root); }
};
// @lc code=end
