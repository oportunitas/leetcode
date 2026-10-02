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
""" idea #0 (31ms/56th% | 23.9MB/97th%)
    we can use the cpp solution, but zen-ified to python's syntax
"""
class Solution:
    def __init__(self):
        self.node_list = []
        self.is_added = set()
        self.node_count = 0

    def _build_node_list(self, cur_node):
        if cur_node.left is not None:
            self._build_node_list(cur_node.left)
        self.node_list.append(cur_node)
        self.node_count += 1
        if cur_node.right is not None:
            self._build_node_list(cur_node.right)

    def _build_final_tree(self, cur_node, begin, middle, end):
        left = max(((middle - begin) // 2) + begin, begin)
        right = min(((end - middle) // 2) + (middle + 1), end)

        # print(f"[{begin} {left} {middle} {right} {end}]")

        if left not in self.is_added:
            cur_node.left = self.node_list[left]
            self.is_added.add(left)
            self._build_final_tree(cur_node.left, begin, left, middle - 1)
        else:
            cur_node.left = None

        if right not in self.is_added:
            cur_node.right = self.node_list[right]
            self.is_added.add(right)
            self._build_final_tree(cur_node.right, middle + 1, right, end)
        else:
            cur_node.right = None

    def balanceBST(self, root: TreeNode | None) -> TreeNode | None:
        self._build_node_list(root)
        print([node.val for node in self.node_list])
        res_root = self.node_list[self.node_count // 2]
        self._build_final_tree(res_root, 0, (self.node_count // 2), (self.node_count - 1))
        return res_root



# @lc code=end

if __name__ == "__main__":
    root: TreeNode = deserialize("TreeNode", read_line())
    ans = Solution().balanceBST(root)
    print("\noutput:", serialize(ans, "TreeNode"))
