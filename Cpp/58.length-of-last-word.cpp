/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (39.32%)
 * Likes:    1601
 * Dislikes: 112
 * Total Accepted:    839.9K
 * Total Submissions: 2.1M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consisting of words and spaces, return the length of the
 * last word in the string.
 *
 * A word is a maximal substring consisting of non-space characters only.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "Hello World"
 * Output: 5
 * Explanation: The last word is "World" with length 5.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "   fly me   to   the moon  "
 * Output: 4
 * Explanation: The last word is "moon" with length 4.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "luffy is still joyboy"
 * Output: 6
 * Explanation: The last word is "joyboy" with length 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only English letters and spaces ' '.
 * There will be at least one word in s.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  int lengthOfLastWord(string s) {
    int l = 0;
    bool trim = true;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (trim && s[i] == ' ')
        continue;
      trim = false;
      if (s[i] != ' ')
        ++l;
      else
        break;
    }
    return l;
  }
};
// @lc code=end
