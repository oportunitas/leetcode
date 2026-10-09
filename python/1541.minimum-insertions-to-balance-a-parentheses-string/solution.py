# Created by oportunitas at 2026/10/09 09:57
# leetgo: 1.4.18
# https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #1 
        now we golf

        this implementation forces the cpp implementation i made earlier into a list comprehension
        trick. you may refer to my cpp implementation to compare and see how a more spread-out
        version of this code essentially does

        t: toadd, b: balance

        here's my best attempt at explaining the logic with human language as closely to the
        syntax:
            if c is (, we add balance by 2, but if we need ) beforehand, we add it as well, and
            change the balance accordingly

            else (if c is )) we add 1 open parenthesis if none are left, and as such, the balance
            is either gonna be balance - 1 or (balance - 1) + 2 (add 1 open parenthesis) if b is 0
            equating to abs(b-1)
    '''
    def minInsertions(self, s: str) -> int:
        t,b=0,0;[(t:=t+b%2,b:=b+2-b%2)if c=='('else(t:=t+(b==0),b:=abs(b-1))for c in s]
        return t+b

    # ''' idea #0 (22ms/100th% | 19.8MB/89th%)
    #     in python, its always better to see problems at a birds eye view perspective rather
    #     than sequence/dp-focused perspective imo. in this solution, we convert the string into
    #     a normal parentheses string using an intermediary swapping ))->}->)

    #     then we can just do a default while loop to eliminate cases of () from the bottom up
    #     (again, birds eye view, not sequential perspective)

    #     then we're going to be only left with either all open brackets or all close brackets
    #     if the remaining are all open brackets, we remember to add twice the amount of 
    #     close brackets
    # '''
    # def minInsertions(self, s: str) -> int:
    #     s = s.replace('))', '}')
    #     # print(f"s is now {s}")
    #     toadd = s.count(')') # add 1 more close bracket for each of these lone closes

    #     s = s.replace('}', ')') # now we're back to the default easier () question
    #     while '()' in s:
    #         s = s.replace('()', '')

    #     # now we're either left with only close brackets or open brackets. 
    #     toadd += len(s)
    #     # dont forget that for each remaining open brackets, we need to add another close bracket
    #     toadd += s.count('(')

    #     return toadd

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().minInsertions(s)
    print("\noutput:", serialize(ans, "integer"))
