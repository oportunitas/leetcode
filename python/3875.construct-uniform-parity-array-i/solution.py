# Created by oportunitas at 2026/10/13 08:53
# leetgo: 1.4.18
# https://leetcode.com/problems/construct-uniform-parity-array-i/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        return True

# @lc code=end

if __name__ == "__main__":
    nums1: List[int] = deserialize("List[int]", read_line())
    ans = Solution().uniformArray(nums1)
    print("\noutput:", serialize(ans, "boolean"))
