class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # return sorted(s) == sorted(t)
        if len(s) != len(t):
            return False
        dictionary_s = {}
        dictionary_t = {}
        for i in s:
            if i in dictionary_s:
                dictionary_s[i] = dictionary_s[i] + 1
            else:
                dictionary_s[i] = 1
        for i in t:
            if i in dictionary_t:
                dictionary_t[i] = dictionary_t[i] + 1
            else:
                dictionary_t[i] = 1
        if dictionary_s == dictionary_t:
            return True
        else:
            return False