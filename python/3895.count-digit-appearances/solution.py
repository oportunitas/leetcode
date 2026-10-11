# Created by oportunitas at 2026/10/11 12:21
# leetgo: 1.4.18
# https://leetcode.com/problems/count-digit-appearances/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (54ms/8th% | 19.4MB/57th%)
        we go golf
    '''
    def countDigitOccurrences(self, nums: list[int], digit: int) -> int:
        return sum(c == str(digit) for c in "".join([str(n) for n in nums]))

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    digit: int = deserialize("int", read_line())
    ans = Solution().countDigitOccurrences(nums, digit)
    print("\noutput:", serialize(ans, "integer"))
