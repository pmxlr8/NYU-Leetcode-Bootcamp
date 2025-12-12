#include <queue>
#include <vector>

class Solution {
public:
  int orangesRotting(std::vector<std::vector<int>> &grid) {
    // Approach: Multi-source BFS starting from all rotten oranges
    // Track time (minutes) for rotting to spread

    int m = grid.size();
    int n = grid[0].size();

    std::queue<std::pair<int, int>> queue;
    int freshCount = 0;

    // Step 1: Find all rotten oranges and count fresh oranges
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          queue.push({i, j});
        } else if (grid[i][j] == 1) {
          freshCount++;
        }
      }
    }

    // If no fresh oranges, return 0
    if (freshCount == 0)
      return 0;

    // Step 2: BFS to spread rotting
    int minutes = 0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!queue.empty()) {
      int size = queue.size();
      bool rotted = false;

      for (int i = 0; i < size; i++) {
        auto [row, col] = queue.front();
        queue.pop();

        for (auto &dir : directions) {
          int newRow = row + dir[0];
          int newCol = col + dir[1];

          // Check bounds and if it's a fresh orange
          if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
              grid[newRow][newCol] == 1) {

            grid[newRow][newCol] = 2; // Mark as rotten
            queue.push({newRow, newCol});
            freshCount--;
            rotted = true;
          }
        }
      }

      if (rotted)
        minutes++;
    }

    // If there are still fresh oranges, return -1
    return freshCount == 0 ? minutes : -1;
  }
};

// Time Complexity: O(m * n) - Each cell is visited at most once
// Space Complexity: O(m * n) - Queue can contain all cells in worst case
