# Created by oportunitas at 2026/10/21 09:18
# leetgo: 1.4.18
# https://leetcode.com/problems/count-partitions-with-even-sum-difference/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def countPartitions(self, n: List[int]) -> int:
        return 0 if sum(n)%2 else len(n)-1

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().countPartitions(nums)
    print("\noutput:", serialize(ans, "integer"))
