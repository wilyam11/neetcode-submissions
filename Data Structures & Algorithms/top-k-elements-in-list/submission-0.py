class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashtable = {}
        for num in nums:
            hashtable[num] = hashtable.get(num,0) +1
        #print(hashtable)
        sort_t = dict(sorted(hashtable.items(), key = lambda item: item[1], reverse = True))
        #print(sort_t)
        ans = list(sort_t.keys())[:k]
        return ans