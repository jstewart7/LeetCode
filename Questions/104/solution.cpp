/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int maxDepth(TreeNode* root) {
    return TraverseTree(root, 0);
  }

  int TraverseTree(TreeNode* node, int depth)
  {
    if (node != NULL)
      {
        int lDepth = TraverseTree(node->left, depth+1);
        int rDepth = TraverseTree(node->right, depth+1);

        return (lDepth > rDepth ? lDepth : rDepth);
      }
    else
      {
        return depth;
      }
  }
};
