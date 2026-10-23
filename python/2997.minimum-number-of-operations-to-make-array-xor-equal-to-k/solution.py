# Created by oportunitas at 2026/10/23 17:11
# leetgo: 1.4.18
# https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def minOperations(self, n: List[int], k: int) -> int:
        return[k:=k^_ for _ in n]and k.bit_count()

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    k: int = deserialize("int", read_line())
    ans = Solution().minOperations(nums, k)
    print("\noutput:", serialize(ans, "integer"))
