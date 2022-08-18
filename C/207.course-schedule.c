/*
 * @lc app=leetcode id=207 lang=c
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (45.22%)
 * Likes:    10831
 * Dislikes: 426
 * Total Accepted:    970.4K
 * Total Submissions: 2.1M
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
 * Return true if you can finish all courses. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 *
 *
 */

// @lc code=start
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool hasCycle(int node, int **edges, int numEdges, bool *visited, bool *checked,
              int **edgesOf, int *numEdgesOf) {
  for (int i = 0; i < numEdgesOf[node]; i++) {
    int toNode = edgesOf[node][i];
    if (checked[toNode])
      continue;
    if (visited[toNode])
      return true;
    visited[toNode] = true;
    if (hasCycle(toNode, edges, numEdges, visited, checked, edgesOf,
                 numEdgesOf))
      return true;
    checked[toNode] = true;
    visited[toNode] = false;
  }
  return false;
}

// check if there's any cycle in disjoint graphs
bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize,
               int *prerequisitesColSize) {

  // if a node is visited in each DFS
  bool *visited = calloc(numCourses, sizeof(bool));
  // if a node belongs to a graph already checked
  bool *checked = calloc(numCourses, sizeof(bool));
  // if there is a cycle
  bool existsCycle = false;
  int defaultNumEdges = 15;

  int **edges = malloc(numCourses * sizeof(int *));
  int *nEdges = calloc(numCourses, sizeof(int));
  int *maxNumEdges = calloc(numCourses, sizeof(int));
  for (int i = 0; i < numCourses; i++) {
    edges[i] = malloc(defaultNumEdges * sizeof(int));
    maxNumEdges[i] = defaultNumEdges;
  }
  for (int i = 0; i < prerequisitesSize; i++) {
    int toNode = prerequisites[i][0], fromNode = prerequisites[i][1];

    if (nEdges[fromNode] >= maxNumEdges[fromNode]) {
      maxNumEdges[fromNode] *= 2;
      edges[fromNode] =
          realloc(edges[fromNode], sizeof(int) * maxNumEdges[fromNode]);
    }
    edges[fromNode][nEdges[fromNode]++] = toNode;
  }

  for (int i = 0; i < numCourses; i++) {
    if (checked[i])
      continue;
    visited[i] = true;
    existsCycle = hasCycle(i, prerequisites, prerequisitesSize, visited,
                           checked, edges, nEdges);
    if (existsCycle)
      break;
    checked[i] = true; // i belongs to a graph without cycle
  }

  free(visited);
  free(checked);
  free(nEdges);
  for (int i = 0; i < numCourses; i++)
    free(edges[i]);
  free(maxNumEdges);
  free(edges);

  return !existsCycle;
}
// @lc code=end
