# Created by oportunitas at 2026/10/14 11:27
# leetgo: 1.4.18
# https://leetcode.com/problems/number-of-arithmetic-triplets/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0
        we golf
    '''
    def arithmeticTriplets(self, n: list[int], d: int) -> int:
        return sum(i-d in n and i-2*d in n for i in n)

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    diff: int = deserialize("int", read_line())
    ans = Solution().arithmeticTriplets(nums, diff)
    print("\noutput:", serialize(ans, "integer"))
