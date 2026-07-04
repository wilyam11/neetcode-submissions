class Solution:
    bracket_pairs: dict[str, str] = {
        ']': '[',
        ')': '(',
        '}': '{'
    }
    
    closing = {')', '}', ']'}

    def is_closing(self, c: str) -> bool:
        return c in self.closing
    
    def isValid(self, s: str) -> bool:
        if self.is_closing(s[0]):
            return False
        stack = []
        for c in s:
            if self.is_closing(c):
                if not stack:
                    return False
                last = stack.pop()
                if self.bracket_pairs.get(c) != last:
                    return False
            else:
                stack.append(c)
        if not stack:
            return True
        return False
                

