# Created by oportunitas at 2026/10/14 10:41
# leetgo: 1.4.18
# https://leetcode.com/problems/maximize-sum-of-squares-of-digits/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (1ms/80th% | 21.3MB/59th%)
        we golf

        add 9 (sum/9) times, then add remain, then add 0
        num,  num-(sum/9)  , num-(sum/9)-1  , 0

        [9 for n in range(sum/9)] + [remain] + [0 for n in range(remain_sum)]

        golf:
        add 9 (sum//9) times, then add remain (sum%9), then add num 0s, then truncate.
    '''
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        return ""if 9*num<sum else("9"*(sum//9)+str(sum%9)+"0"*num)[:num]

# @lc code=end

if __name__ == "__main__":
    num: int = deserialize("int", read_line())
    sum: int = deserialize("int", read_line())
    ans = Solution().maxSumOfSquares(num, sum)
    print("\noutput:", serialize(ans, "string"))
