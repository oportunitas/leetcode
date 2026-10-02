# Created by oportunitas at 2026/10/02 09:36
# leetgo: 1.4.18
# https://leetcode.com/problems/balance-a-binary-search-tree/

from typing import *
from leetgo_py import *

# @lc code=begin

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
""" idea #0 (26ms/82nd% | 23.9MB/97th%)
    we can use the cpp solution, but zen-ified to python's syntax
"""
class Solution:
    def __init__(self):
        self.node_list = []
        self.is_added = set()

    def build(self, left, right):
        if left > right:
            return None

        middle = (left + right) // 2
        parent = self.node_list[middle]
        parent.left = self.build(left, middle - 1)
        parent.right = self.build(middle + 1, right)

        return parent

    def balanceBST(self, root: TreeNode | None) -> TreeNode | None:
        # inorder traversal to find sorted version of tree
        self.node_list = (f := lambda n: f(n.left) + [n] + f(n.right) if n else []) (root)
        
        print([node.val for node in self.node_list])
        return self.build(0, len(self.node_list) - 1)



# @lc code=end

if __name__ == "__main__":
    root: TreeNode = deserialize("TreeNode", read_line())
    ans = Solution().balanceBST(root)
    print("\noutput:", serialize(ans, "TreeNode"))
