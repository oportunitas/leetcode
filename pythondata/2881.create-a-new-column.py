# Created by oportunitas at 2026/09/19 06:39
# leetgo: 1.4.18
# https://leetcode.com/problems/create-a-new-column/

# @lc code=begin

import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees["bonus"] = employees["salary"] * 2
    return employees

# @lc code=end
