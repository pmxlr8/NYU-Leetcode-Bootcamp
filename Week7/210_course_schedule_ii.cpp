#include <queue>
#include <vector>

class Solution {
public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>> &prerequisites) {
    // Approach: Topological Sort using Kahn's Algorithm (BFS)
    // Returns valid ordering if exists, empty array if cycle detected

    // Step 1: Build adjacency list and calculate in-degrees
    std::vector<std::vector<int>> graph(numCourses);
    std::vector<int> inDegree(numCourses, 0);

    for (auto &prereq : prerequisites) {
      int course = prereq[0];
      int prereqCourse = prereq[1];
      graph[prereqCourse].push_back(course); // prereq -> course
      inDegree[course]++;
    }

    // Step 2: Initialize queue with courses having no prerequisites (in-degree
    // 0)
    std::queue<int> queue;
    for (int i = 0; i < numCourses; i++) {
      if (inDegree[i] == 0) {
        queue.push(i);
      }
    }

    // Step 3: Process courses in topological order
    std::vector<int> result;

    while (!queue.empty()) {
      int course = queue.front();
      queue.pop();
      result.push_back(course);

      // Reduce in-degree for all dependent courses
      for (int nextCourse : graph[course]) {
        inDegree[nextCourse]--;
        if (inDegree[nextCourse] == 0) {
          queue.push(nextCourse);
        }
      }
    }

    // Step 4: Check if all courses can be completed (no cycle)
    if (result.size() == numCourses) {
      return result;
    }

    // Cycle detected - impossible to complete all courses
    return {};
  }
};

// Time Complexity: O(V + E) - Where V = numCourses, E = number of prerequisites
// Space Complexity: O(V + E) - Adjacency list and queue
