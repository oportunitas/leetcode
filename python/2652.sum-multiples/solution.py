# Created by oportunitas at 2026/10/04 17:54
# leetgo: 1.4.18
# https://leetcode.com/problems/sum-multiples/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (140ms/5th% | 19.1MB/85th%)
        similar to the cpp implementation, but using sum()
    '''
    def sumOfMultiples(self, n: int) -> int:
        return sum(i for i in range(0, n + 1) if any(i % d == 0 for d in [3, 5, 7]))

# @lc code=end

if __name__ == "__main__":
    n: int = deserialize("int", read_line())
    ans = Solution().sumOfMultiples(n)
    print("\noutput:", serialize(ans, "integer"))
