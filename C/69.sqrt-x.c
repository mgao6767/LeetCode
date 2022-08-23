/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (36.83%)
 * Likes:    4610
 * Dislikes: 3480
 * Total Accepted:    1.2M
 * Total Submissions: 3.2M
 * Testcase Example:  '4'
 *
 * Given a non-negative integer x, compute and return the square root of x.
 *
 * Since the return type is an integer, the decimal digits are truncated, and
 * only the integer part of the result is returned.
 *
 * Note: You are not allowed to use any built-in exponent function or operator,
 * such as pow(x, 0.5) or x ** 0.5.
 *
 *
 * Example 1:
 *
 *
 * Input: x = 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since the decimal part
 * is truncated, 2 is returned.
 *
 *
 * Constraints:
 *
 *
 * 0 <= x <= 2^31 - 1
 *
 *
 */

// @lc code=start

int mySqrt(int x) {
  if (x <= 1)
    return x;
  int root = 2;

  while (x / root > root) {
    root = root << 1;
  }
  while (x / root < root) {
    root *= 0.9;
  }
  while (x / root > root) {
    ++root;
  }
  while (x / root < root) {
    --root;
  }
  return root;
}

// @lc code=end
