# Created by oportunitas at 2026/10/15 09:40
# leetgo: 1.4.18
# https://leetcode.com/problems/minimum-number-game/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def numberGame(self, n: List[int]) -> List[int]:
        return[sorted(n)[i^1]for i in range(len(n))]

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().numberGame(nums)
    print("\noutput:", serialize(ans, "integer[]"))
