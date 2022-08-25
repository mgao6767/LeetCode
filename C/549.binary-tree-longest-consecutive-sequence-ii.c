/*
 * @lc app=leetcode id=549 lang=c
 *
 * [549] Binary Tree Longest Consecutive Sequence II
 *
 * https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/description/
 *
 * algorithms
 * Medium (48.97%)
 * Likes:    984
 * Dislikes: 76
 * Total Accepted:    46K
 * Total Submissions: 93.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given the root of a binary tree, return the length of the longest
 * consecutive path in the tree.
 *
 * A consecutive path is a path where the values of the consecutive nodes in
 * the path differ by one. This path can be either increasing or
 * decreasing.
 *
 *
 * For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path
 * [1,2,4,3] is not valid.
 *
 *
 * On the other hand, the path can be in the child-Parent-child order, where
 * not necessarily be parent-child order.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3]
 * Output: 2
 * Explanation: The longest consecutive path is [1, 2] or [2, 1].
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,1,3]
 * Output: 3
 * Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 3 * 10^4].
 * -3 * 10^4 <= Node.val <= 3 * 10^4
 *
 *
 */
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// @lc code=start
#include <stdbool.h>

int path(struct TreeNode *root, bool ascend, int *maxlen) {
  if (root == NULL)
    return 0;

  if (root->left == NULL && root->right == NULL)
    return 1;

  int lpa = 0, lpd = 0, rpa = 0, rpd = 0, maxL = 1, maxR = 1;

  if (ascend) {
    // left path ascending
    lpa = path(root->left, true, maxlen);
    // right path ascending
    rpa = path(root->right, true, maxlen);
  } else {
    // left path descending
    lpd = path(root->left, false, maxlen);
    // right path descending
    rpd = path(root->right, false, maxlen);
  }

  // child-parent-child paths
  int plen1 = 0, plen2 = 0;
  if (root->left != NULL && root->right != NULL) {
    // right-root-left
    //     2
    //   3   1
    if ((root->left->val - 1 == root->val &&
         root->val - 1 == root->right->val)) {
      // compute the uncalculated right path descending
      if (ascend)
        rpd = path(root->right, false, maxlen);
      plen1 = 1 + lpa + rpd;
    }
    // left-root-right
    //     3
    //   2   4
    if ((root->left->val + 1 == root->val &&
         root->val + 1 == root->right->val)) {
      // compute the uncalculated right path ascending
      if (!ascend)
        rpa = path(root->right, true, maxlen);
      plen2 = 1 + lpd + rpa;
    }
  }

  // parent-child paths
  if (root->left != NULL) {
    if (ascend && root->left->val == root->val + 1) {
      // ascending and add root
      maxL = 1 + lpa;
    } else if (!ascend && root->left->val == root->val - 1) {
      // descending and add root
      maxL = 1 + lpd;
    }
  }
  if (root->right != NULL) {
    if (ascend && root->right->val == root->val + 1) {
      // ascending and add root
      maxR = 1 + rpa;
    } else if (!ascend && root->right->val == root->val - 1) {
      // descending and add root
      maxR = 1 + rpd;
    }
  }

  // update max length inside the tree
  *maxlen = maxL > *maxlen ? maxL : *maxlen;
  *maxlen = maxR > *maxlen ? maxR : *maxlen;
  *maxlen = plen1 > *maxlen ? plen1 : *maxlen;
  *maxlen = plen2 > *maxlen ? plen2 : *maxlen;

  // return the longest paths from parent-child pattern
  // no need to return plen (child-parent-child) since we use it to update the
  // global max length above
  return maxL > maxR ? maxL : maxR;
}

int longestConsecutive(struct TreeNode *root) {
  int maxlen = 0;
  int a = path(root, true, &maxlen);
  int d = path(root, false, &maxlen);

  maxlen = a > maxlen ? a : maxlen;
  maxlen = d > maxlen ? d : maxlen;
  return maxlen;
}
// @lc code=end
