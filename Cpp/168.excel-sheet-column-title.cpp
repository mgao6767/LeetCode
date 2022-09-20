/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (33.83%)
 * Likes:    3186
 * Dislikes: 466
 * Total Accepted:    338.9K
 * Total Submissions: 980.6K
 * Testcase Example:  '1'
 *
 * Given an integer columnNumber, return its corresponding column title as it
 * appears in an Excel sheet.
 *
 * For example:
 *
 *
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 * ...
 *
 *
 *
 * Example 1:
 *
 *
 * Input: columnNumber = 1
 * Output: "A"
 *
 *
 * Example 2:
 *
 *
 * Input: columnNumber = 28
 * Output: "AB"
 *
 *
 * Example 3:
 *
 *
 * Input: columnNumber = 701
 * Output: "ZY"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= columnNumber <= 2^31 - 1
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string convertToTitle(int columnNumber) {

    string result = "";
    while (columnNumber > 0) {
      int i = (columnNumber - 1) % 26;
      result = char('A' + i) + result;
      columnNumber -= i;
      columnNumber /= 26;
    }
    return result;
  }
};
// @lc code=end
