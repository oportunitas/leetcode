# Created by oportunitas at 2026/10/10 07:06
# leetgo: 1.4.18
# https://leetcode.com/problems/decode-the-message/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (3ms/55th% | 19.4MB/31th%)
        we go golf

        the cpp implementation uses arrays, in python we can use a dictionary instead.
        we first set the dictionary to map space to space (32->32 in ascii)

        then we use setdefault to map the current character to 96 (a - 1) + len(map)(which 
        starts at 1 since we already have 32->32)

        then we use translate(). very nice indeed.
    '''
    def decodeMessage(self, k: str, m: str) -> str:
        d={32:32};[d.setdefault(ord(c),96+len(d))for c in k];return m.translate(d)

# @lc code=end

if __name__ == "__main__":
    key: str = deserialize("str", read_line())
    message: str = deserialize("str", read_line())
    ans = Solution().decodeMessage(key, message)
    print("\noutput:", serialize(ans, "string"))
