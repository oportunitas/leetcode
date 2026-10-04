# Created by oportunitas at 2026/10/04 11:35
# leetgo: 1.4.18
# https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

from typing import *
from leetgo_py import *
from collections import Counter
# @lc code=begin

class Solution:
    ''' idea #0 (2ms/62th% | 19.3MB/43th%)
        this is a listified solution of the cpp implementation. we first create a dictionary 
        storing the occurences of each number.

        then we create the arrays, by looping for each num in occurences with occurence > i,
        for i from 0 to the maximum occurence count
    '''
    def findMatrix(self, nums: list[int]) -> list[list[int]]:
        occurences = Counter(nums)
        return [[num for num, occurence in occurences.items() if occurence > i]
                for i in range(max(occurences.values()))]

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().findMatrix(nums)
    print("\noutput:", serialize(ans, "integer[][]"))
