/*
 * @lc app=leetcode id=269 lang=c
 *
 * [269] Alien Dictionary
 *
 * https://leetcode.com/problems/alien-dictionary/description/
 *
 * algorithms
 * Hard (35.12%)
 * Likes:    3808
 * Dislikes: 802
 * Total Accepted:    308.6K
 * Total Submissions: 878.9K
 * Testcase Example:  '["wrt","wrf","er","ett","rftt"]'
 *
 * There is a new alien language that uses the English alphabet. However, the
 * order among the letters is unknown to you.
 *
 * You are given a list of strings words from the alien language's dictionary,
 * where the strings in words are sorted lexicographically by the rules of this
 * new language.
 *
 * Return a string of the unique letters in the new alien language sorted in
 * lexicographically increasing order by the new language's rules. If there is
 * no solution, return "". If there are multiple solutions, return any of
 * them.
 *
 * A string s is lexicographically smaller than a string t if at the first
 * letter where they differ, the letter in s comes before the letter in t in
 * the alien language. If the first min(s.length, t.length) letters are the
 * same, then s is smaller if and only if s.length < t.length.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["wrt","wrf","er","ett","rftt"]
 * Output: "wertf"
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["z","x"]
 * Output: "zx"
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["z","x","z"]
 * Output: ""
 * Explanation: The order is invalid, so return "".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] consists of only lowercase English letters.
 *
 *
 */

// @lc code=start
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *alienOrder(char **words, int wordsSize) {
  // graph[a][b]: "a"->"b" arc?
  bool graph[26][26] = {false};
  bool inAlphabet[26] = {false};
  int inDegree[26] = {0};

  int minlen;
  for (int i = 0; i < wordsSize; i++) {
    char *word1 = words[i];
    for (int t = 0; t < strlen(word1); t++)
      inAlphabet[word1[t] - 'a'] = true;

    for (int j = i + 1; j < wordsSize; j++) {
      char *word2 = words[j];
      for (int t = 0; t < strlen(word2); t++)
        inAlphabet[word2[t] - 'a'] = true;

      // word1, word2
      if (strlen(word1) < strlen(word2)) {
        minlen = strlen(word1);
      } else {
        minlen = strlen(word2);
      }

      // find the first distinct letter
      int k;
      for (k = 0; k < minlen; k++) {
        if (word1[k] == word2[k])
          continue;
        int s = word1[k] - 'a';
        int t = word2[k] - 'a';
        if (graph[t][s])
          return "";

        if (!graph[s][t]) {
          inDegree[t] += 1; // a new arc to t
        }
        graph[s][t] = true; // the arc s->t
        break;
      }

      // all first minlen letters are same
      // word1.length must be no larger than word2.length
      if (k == minlen && strlen(word2) < strlen(word1))
        return "";
    }
  }

  // output one sort
  int queue[26], queueEnd = 0, queueStart = 0;
  // enqueue nodes with zero indegree
  for (int i = 0; i < 26; i++) {
    if (inAlphabet[i] && inDegree[i] == 0)
      queue[queueEnd++] = i;
  }
  // no node with zero indegree
  if (queueEnd == 0)
    return "";

  while (queueEnd - queueStart > 0) {
    int c = queue[queueStart++]; // dequeue
    for (int i = 0; i < 26; i++) {
      if (graph[c][i]) {
        inDegree[i] -= 1;
        if (inDegree[i] == 0) {
          queue[queueEnd++] = i;
        }
      }
    }
  }

  // must be that all chars have been in queue
  int nchar = 0;
  for (int i = 0; i < 26; i++)
    if (inAlphabet[i])
      nchar++;
  if (queueEnd != nchar)
    return "";

  char *result = malloc(sizeof(char) * 27);
  for (int i = 0; i < queueEnd; i++) {
    result[i] = 'a' + queue[i];
  }
  result[queueEnd] = '\0';

  return result;
}
// @lc code=end
