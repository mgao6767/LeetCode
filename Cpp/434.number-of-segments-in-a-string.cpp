/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (37.89%)
 * Likes:    508
 * Dislikes: 1052
 * Total Accepted:    124.8K
 * Total Submissions: 330.3K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Given a string s, return the number of segments in the string.
 *
 * A segment is defined to be a contiguous sequence of non-space characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "Hello, my name is John"
 * Output: 5
 * Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
 *
 *
 * Example 2:
 *
 *
 * Input: s = "Hello"
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 300
 * s consists of lowercase and uppercase English letters, digits, or one of the
 * following characters "!@#$%^&*()_+-=',.:".
 * The only space character in s is ' '.
 *
 *
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  int countSegments(string s) {
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
      if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
        n++;
      }
    }
    return n;
  }
};
// @lc code=end
