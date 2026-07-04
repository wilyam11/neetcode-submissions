class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashtable = {}
        freq = [[] for i in range(len(nums)+1)]
        for num in nums:
            hashtable[num] = hashtable.get(num,0) +1
        for n,c in hashtable.items():
            freq[c].append(n)
        ans = []
        for i in range(len(freq)-1,0,-1):
            for j in freq[i]:
                ans.append(j)
                if len(ans) == k:
                    return ans
        return ans