#include <queue>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  std::vector<int> rightSideView(TreeNode *root) {
    // Approach: BFS level-order traversal
    // For each level, add the rightmost node to result

    std::vector<int> result;

    if (!root)
      return result;

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      int levelSize = queue.size();

      for (int i = 0; i < levelSize; i++) {
        TreeNode *node = queue.front();
        queue.pop();

        // If this is the last (rightmost) node in the level, add to result
        if (i == levelSize - 1) {
          result.push_back(node->val);
        }

        // Add children to queue (left first, then right)
        if (node->left)
          queue.push(node->left);
        if (node->right)
          queue.push(node->right);
      }
    }

    return result;
  }
};

// Time Complexity: O(n) - We visit each node exactly once
// Space Complexity: O(w) - Where w is the maximum width of the tree (queue
// size)
//                  Worst case O(n) for a complete binary tree
