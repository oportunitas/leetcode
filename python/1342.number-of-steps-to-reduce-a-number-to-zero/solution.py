# Created by oportunitas at 2026/10/11 12:34
# leetgo: 1.4.18
# https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 19.3MB/26th%)
        same idea as cpp implementation
    '''
    def numberOfSteps(self, num: int) -> int:
        return num.bit_length() + max(num.bit_count() - 1, 0)

# @lc code=end

if __name__ == "__main__":
    num: int = deserialize("int", read_line())
    ans = Solution().numberOfSteps(num)
    print("\noutput:", serialize(ans, "integer"))
