class Solution:
    def alphanumcheck(self, c):
        return ((ord('A') <= ord(c) <= ord('Z')) or
        (ord('a') <= ord(c) <= ord('z')) or
        (ord('0') <= ord(c) <= ord('9'))
        )
    def isPalindrome(self, s: str) -> bool:
        #print(s)
        slen = len(s)
        l = 0
        r = slen-1
        while l < r:
            while(l < r and self.alphanumcheck(s[l]) == False):
                l+=1
            while(l < r and self.alphanumcheck(s[r]) == False):
                r-=1
            if(s[l].lower() != s[r].lower()):
                return False
            l+=1
            r-=1
        return True