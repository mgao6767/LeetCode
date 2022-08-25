/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 *
 * https://leetcode.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (61.26%)
 * Likes:    1567
 * Dislikes: 53
 * Total Accepted:    141.9K
 * Total Submissions: 231.5K
 * Testcase Example:  '"ab-cd"'
 *
 * Given a string s, reverse the string according to the following rules:
 *
 *
 * All the characters that are not English letters remain in the same
 * position.
 * All the English letters (lowercase or uppercase) should be reversed.
 *
 *
 * Return s after reversing it.
 *
 *
 * Example 1:
 * Input: s = "ab-cd"
 * Output: "dc-ba"
 * Example 2:
 * Input: s = "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * Example 3:
 * Input: s = "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s consists of characters with ASCII values in the range [33, 122].
 * s does not contain '\"' or '\\'.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
private:
  bool isEnglishLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      return true;
    }
    return false;
  }

public:
  string reverseOnlyLetters(string s) {
    string ans = "";
    int l = s.size();
    int j = l - 1;
    for (size_t i = 0; i < l; i++) {
      // char to be add
      char c = s[i];
      if (!isEnglishLetter(c)) {
        ans += c;
      } else {
        char cc = s[j--];
        while (!isEnglishLetter(cc)) {
          cc = s[j--];
        }
        ans += cc;
      }
    }
    return ans;
  }
};
// @lc code=end
