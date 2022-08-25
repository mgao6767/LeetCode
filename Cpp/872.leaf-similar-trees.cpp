/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (65.10%)
 * Likes:    1833
 * Dislikes: 55
 * Total Accepted:    176.2K
 * Total Submissions: 270.6K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n' +
  '[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree, from left to right order, the
 * values of those leaves form a leaf value sequence.
 *
 *
 *
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 *
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 *
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 *
 *
 * Example 1:
 *
 *
 * Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 =
 * [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root1 = [1,2,3], root2 = [1,3,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each tree will be in the range [1, 200].
 * Both of the given trees will have values in the range [0, 200].
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
#include <vector>

class Solution {
private:
  void f(TreeNode *root, std::vector<int> &vec) {
    if (root == nullptr)
      return;
    f(root->left, vec);
    if (root->left == nullptr && root->right == nullptr) {
      vec.push_back(root->val);
    }
    f(root->right, vec);
  }

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    std::vector<int> valsLeft, valsRight;
    f(root1, valsLeft);
    f(root2, valsRight);
    if (valsLeft.size() != valsRight.size()) {
      return false;
    }
    for (std::size_t i = 0; i < valsLeft.size(); i++) {
      if (valsLeft[i] != valsRight[i]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
