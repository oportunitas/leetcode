# Created by oportunitas at 2026/10/21 08:39
# leetgo: 1.4.18
# https://leetcode.com/problems/rename-columns/

# @lc code=begin

import pandas as pd

def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    return students.rename(columns={
        'id'    : 'student_id', 
        'first' : 'first_name', 
        'last'  : 'last_name', 
        'age'   : 'age_in_years'})

# @lc code=end
