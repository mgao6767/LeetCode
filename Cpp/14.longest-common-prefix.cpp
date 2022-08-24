/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (40.28%)
 * Likes:    9799
 * Dislikes: 3303
 * Total Accepted:    1.8M
 * Total Submissions: 4.5M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 *
 * Example 1:
 *
 *
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters.
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {

    size_t minlen = SIZE_MAX;
    string str;
    for (auto &&s : strs) {
      if (s.length() < minlen) {
        minlen = s.length();
        str = s;
      }
    }
    if (minlen == 0) {
      return "";
    }

    size_t i, matches = 0;
    for (i = 1; i <= minlen; i++) {
      for (auto &&s : strs) {
        if (str.compare(0, i, s, 0, i) != 0) {
          return str.substr(0, i - 1);
        }
      }
      matches++;
    }
    if (i == minlen && matches) {
      return str;
    } else {
      return str.substr(0, i - 1);
    }
  }
};
// @lc code=end
