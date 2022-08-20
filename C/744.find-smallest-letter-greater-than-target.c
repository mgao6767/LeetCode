/*
 * @lc app=leetcode id=744 lang=c
 *
 * [744] Find Smallest Letter Greater Than Target
 *
 * https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
 *
 * algorithms
 * Easy (44.67%)
 * Likes:    2036
 * Dislikes: 1799
 * Total Accepted:    229.1K
 * Total Submissions: 513K
 * Testcase Example:  '["c","f","j"]\n"a"'
 *
 * Given a characters array letters that is sorted in non-decreasing order and
 * a character target, return the smallest character in the array that is
 * larger than target.
 *
 * Note that the letters wrap around.
 *
 *
 * For example, if target == 'z' and letters == ['a', 'b'], the answer is
 * 'a'.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: letters = ["c","f","j"], target = "a"
 * Output: "c"
 *
 *
 * Example 2:
 *
 *
 * Input: letters = ["c","f","j"], target = "c"
 * Output: "f"
 *
 *
 * Example 3:
 *
 *
 * Input: letters = ["c","f","j"], target = "d"
 * Output: "f"
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= letters.length <= 10^4
 * letters[i] is a lowercase English letter.
 * letters is sorted in non-decreasing order.
 * letters contains at least two different characters.
 * target is a lowercase English letter.
 *
 *
 */

// @lc code=start
// [smaller or equal to] target [greater or equal to]
char bs(char *letters, int lo, int hi, char target) {
  int mid = lo + (hi - lo) / 2;
  if (hi == lo) {
    if (letters[lo] <= target)
      return letters[0];
    else
      return letters[lo];

  } else if (letters[mid] <= target) {
    return bs(letters, mid + 1, hi, target);
  } else {
    return bs(letters, lo, mid, target);
  }
}

char nextGreatestLetter(char *letters, int lettersSize, char target) {
  return bs(letters, 0, lettersSize - 1, target);
}
// @lc code=end
