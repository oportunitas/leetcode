# Created by oportunitas at 2026/10/03 13:32
# leetgo: 1.4.18
# https://leetcode.com/problems/count-the-digits-that-divide-a-number/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 19.2MB/60th%)
        same idea as the c++ solution
    '''
    def countDigits(self, num: int) -> int:
        return sum(1 for c in str(num) if num % int(c) == 0)

# @lc code=end

if __name__ == "__main__":
    num: int = deserialize("int", read_line())
    ans = Solution().countDigits(num)
    print("\noutput:", serialize(ans, "integer"))
