# Created by oportunitas at 2026/10/14 12:14
# leetgo: 1.4.18
# https://leetcode.com/problems/count-good-triplets/

from typing import *
from leetgo_py import *

# @lc code=begin
from itertools import combinations

class Solution:
    ''' idea #0
        we golf. we can use itertools.combinations to iterate through all combinations of pick n
        from v
    '''
    def countGoodTriplets(self, v: List[int], a: int, b: int, c: int) -> int:
        return sum(all([abs(i-j)<=a,abs(j-k)<=b,abs(i-k)<=c])for i,j,k in combinations(v,3))

# @lc code=end

if __name__ == "__main__":
    arr: List[int] = deserialize("List[int]", read_line())
    a: int = deserialize("int", read_line())
    b: int = deserialize("int", read_line())
    c: int = deserialize("int", read_line())
    ans = Solution().countGoodTriplets(arr, a, b, c)
    print("\noutput:", serialize(ans, "integer"))
