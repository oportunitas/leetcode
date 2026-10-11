# Created by oportunitas at 2026/10/11 13:48
# leetgo: 1.4.18
# https://leetcode.com/problems/maximum-binary-tree/

from typing import *
from leetgo_py import *

# @lc code=begin

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

''' idea #0 (27ms/61th% | 19.5MB/94th%)
    we zen (not really golfable because the function name is verbose), and
    try to golf as far as possible
'''
class Solution:
    def constructMaximumBinaryTree(self, nums: list[int]) -> TreeNode | None:
        return TreeNode(
            nums[i:=nums.index(max(nums))], #value
            self.constructMaximumBinaryTree(nums[:i]), #left
            self.constructMaximumBinaryTree(nums[i+1:]) #right
        ) if nums else None

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().constructMaximumBinaryTree(nums)
    print("\noutput:", serialize(ans, "TreeNode"))
