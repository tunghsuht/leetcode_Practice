class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        a = {}
        for i in nums:
            if i in a:
                a[i] = a[i] + 1
                if a[i] == 2:
                    return True
                    break
            else:
                a[i] = 1
        return False
            