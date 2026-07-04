class Solution:
    def isAnagram(self, s: str, t: str) -> bool:        
        def count(st: str) -> list:
            cnt_list = [0]*26
            for char in st:
                index = ord(char)-ord('a')
                cnt_list[index] += 1
            return cnt_list
        a = count(s)
        b = count(t)
        for i in range(26):
            if a[i] != b[i]:
                return False
        return True
            