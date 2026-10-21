# Created by oportunitas at 2026/10/21 08:46
# leetgo: 1.4.18
# https://leetcode.com/problems/root-equals-sum-of-children/

from typing import *
from leetgo_py import *

# @lc code=begin

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkTree(self, r: TreeNode | None) -> bool:
        return r.val==r.right.val+r.left.val

# @lc code=end

if __name__ == "__main__":
    root: TreeNode = deserialize("TreeNode", read_line())
    ans = Solution().checkTree(root)
    print("\noutput:", serialize(ans, "boolean"))
