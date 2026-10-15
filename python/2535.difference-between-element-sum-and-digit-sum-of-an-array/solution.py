# Created by oportunitas at 2026/10/15 10:22
# leetgo: 1.4.18
# https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def differenceOfSum(self, n: list[int]) -> int:
        # print(sum(map(int,''.join(map(str,n)))))
        return abs(sum(map(int,''.join(map(str,n))))-sum(n))

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().differenceOfSum(nums)
    print("\noutput:", serialize(ans, "integer"))
