/*
 * @lc app=leetcode id=210 lang=c
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (47.41%)
 * Likes:    7573
 * Dislikes: 256
 * Total Accepted:    689.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 *
 *
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 *
 *
 * Return the ordering of courses you should take to finish all courses. If
 * there are many valid answers, return any of them. If it is impossible to
 * finish all courses, return an empty array.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished course 0. So the correct course order is [0,1].
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both courses 1 and 2. Both courses 1 and 2 should be
 * taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3].
 *
 *
 * Example 3:
 *
 *
 * Input: numCourses = 1, prerequisites = []
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * ai != bi
 * All the pairs [ai, bi] are distinct.
 *
 *
 */

// @lc code=start
#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findOrder(int numCourses, int **prerequisites, int prerequisitesSize,
               int *prerequisitesColSize, int *returnSize) {
  int *queue = malloc(sizeof(int) * numCourses);
  int queueEnd = 0, queueStart = 0, n = 0, defaultNumEdges = 20;
  int *inDegree = calloc(numCourses, sizeof(int));
  int *nEdges = calloc(numCourses, sizeof(int));
  int *edges = malloc(numCourses * defaultNumEdges * sizeof(int));
  // compute indegee/outdegree for each node
  for (int i = 0; i < prerequisitesSize; i++) {
    int toNode = prerequisites[i][0], fromNode = prerequisites[i][1];
    inDegree[toNode]++;
    edges[fromNode * defaultNumEdges + nEdges[fromNode]++] = toNode;
  }
  // enqueue nodes with zero indegree
  for (int i = 0; i < numCourses; i++) {
    if (inDegree[i] == 0)
      queue[queueEnd++] = i;
  }
  while (queueEnd - queueStart > 0) {
    int node = queue[queueStart++]; // dequeue
    for (int i = 0; i < nEdges[node]; i++) {
      int dst = edges[node * defaultNumEdges + i];
      inDegree[dst]--;
      if (inDegree[dst] == 0) {
        queue[queueEnd++] = dst;
      }
    }
    n++;
  }
  if (n == numCourses)
    *returnSize = numCourses;
  else
    *returnSize = 0;

  free(nEdges);
  free(edges);
  free(inDegree);

  return queue;
}
// @lc code=end
