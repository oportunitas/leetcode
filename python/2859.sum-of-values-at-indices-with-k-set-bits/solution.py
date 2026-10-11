# Created by oportunitas at 2026/10/11 12:45
# leetgo: 1.4.18
# https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 19.4MB/34th%)
        same idea with c++ implementation
    '''
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        return sum(n for i, n in enumerate(nums) if i.bit_count() == k)

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    k: int = deserialize("int", read_line())
    ans = Solution().sumIndicesWithKSetBits(nums, k)
    print("\noutput:", serialize(ans, "integer"))
