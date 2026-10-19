# Created by oportunitas at 2026/10/19 08:23
# leetgo: 1.4.18
# https://leetcode.com/problems/find-target-indices-after-sorting-array/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def targetIndices(self, n: list[int], t: int) -> list[int]:
        return [i for i,_ in enumerate(sorted(n))if _==t]

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    target: int = deserialize("int", read_line())
    ans = Solution().targetIndices(nums, target)
    print("\noutput:", serialize(ans, "integer[]"))
