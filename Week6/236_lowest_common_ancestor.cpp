// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // Base case: if root is null or root is one of the nodes, return root
    if (root == nullptr || root == p || root == q) {
      return root;
    }

    // Recursively search in left and right subtrees
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    // If both left and right are non-null, root is the LCA
    if (left != nullptr && right != nullptr) {
      return root;
    }

    // If one is non-null, that subtree contains both p and q
    // Return the non-null one
    return left != nullptr ? left : right;
  }
};

// Time Complexity: O(n) - We may visit all nodes in the worst case
// Space Complexity: O(h) - Recursion stack, where h is the height of the tree
//                   O(n) in the worst case for a skewed tree
