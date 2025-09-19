#include <algorithm> // std::max

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0; // base case
        int leftDepth  = maxDepth(root->left);   // 递归求左子树深度
        int rightDepth = maxDepth(root->right);  // 递归求右子树深度
        return 1 + std::max(leftDepth, rightDepth); // 合并
    }
};
/*
        1
      /   \
     2     3
    / \     \
   4   5     6
      /
     7

maxDepth(1)
  maxDepth(2)
    maxDepth(4)
      maxDepth(nullptr) -> 0
      maxDepth(nullptr) -> 0
    <- return 1 + max(0,0) = 1
    maxDepth(5)
      maxDepth(7)
        maxDepth(nullptr) -> 0
        maxDepth(nullptr) -> 0
      <- return 1 + max(0,0) = 1
      maxDepth(nullptr) -> 0
    <- return 1 + max(1,0) = 2
  <- return 1 + max(1,2) = 3
  maxDepth(3)
    maxDepth(nullptr) -> 0
    maxDepth(6)
      maxDepth(nullptr) -> 0
      maxDepth(nullptr) -> 0
    <- return 1 + max(0,0) = 1
  <- return 1 + max(0,1) = 2
<- return 1 + max(3,2) = 4
*/