# Created by oportunitas at 2026/10/03 13:23
# leetgo: 1.4.18
# https://leetcode.com/problems/find-the-number-of-good-pairs-i/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (3ms/86th% | 19.1MB/93rd%)
        we can do a one-liner here
    '''
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        return sum(1 for n2 in nums2 for n1 in nums1 if n1 % (n2 * k) == 0)

# @lc code=end

if __name__ == "__main__":
    nums1: List[int] = deserialize("List[int]", read_line())
    nums2: List[int] = deserialize("List[int]", read_line())
    k: int = deserialize("int", read_line())
    ans = Solution().numberOfPairs(nums1, nums2, k)
    print("\noutput:", serialize(ans, "integer"))
