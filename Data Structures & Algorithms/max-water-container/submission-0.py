class Solution:
    def volume(self, len, h1,h2) -> int:
        return len*min(h1,h2)
    def maxArea(self, heights: List[int]) -> int:
        l = 0
        r = len(heights)-1
        maxA = (r-l) * min(heights[l], heights[r])
        while l < r:
            cur = (r-l)*min(heights[l], heights[r])
            maxA = max(cur, maxA)
            if min(heights[l], heights[r]) == heights[l]:
                l += 1
            else:
                r -= 1
        return maxA