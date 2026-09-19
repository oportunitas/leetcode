# Created by oportunitas at 2026/09/19 06:51
# leetgo: 1.4.18
# https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/

# @lc code=begin

import pandas as pd

def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    # group subject_id by teacher_id and find unique counts, then reset index, then rename
    # subject_id to cnt
    result = teacher.groupby("teacher_id")["subject_id"].nunique() \
        .reset_index() \
        .rename(columns={"subject_id": "cnt"})
    return result

# @lc code=end
