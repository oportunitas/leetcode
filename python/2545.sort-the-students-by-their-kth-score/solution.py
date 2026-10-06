# Created by oportunitas at 2026/10/06 10:59
# leetgo: 1.4.18
# https://leetcode.com/problems/sort-the-students-by-their-kth-score/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 24.7MB/95th%)
        this is trivial in python, we just call .sort()
    '''
    def sortTheStudents(self, score: list[list[int]], k: int) -> list[list[int]]:
        score.sort(key = (lambda row: row[k]), reverse = True)
        return score

# @lc code=end

if __name__ == "__main__":
    score: List[List[int]] = deserialize("List[List[int]]", read_line())
    k: int = deserialize("int", read_line())
    ans = Solution().sortTheStudents(score, k)
    print("\noutput:", serialize(ans, "integer[][]"))
