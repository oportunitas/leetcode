# Created by oportunitas at 2026/10/13 09:02
# leetgo: 1.4.18
# https://leetcode.com/problems/separate-the-digits-in-an-array/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 19.5MB/50th%)
        we go golf
    '''
    def separateDigits(self, n: list[int]) -> list[int]:
        return[int(d)for d in"".join(map(str,n))]

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().separateDigits(nums)
    print("\noutput:", serialize(ans, "integer[]"))
