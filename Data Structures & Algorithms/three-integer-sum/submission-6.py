class Solution:
    def twoSum(self, nums: List[int], len: int, target: int) -> List[tuple[int,int]]:
        l = 0
        r = len - 1
        ans = []
        # print(f"len {len}, target {target}")
        # print(nums)
        while l < r:
            s = nums[l] + nums[r]
            if s > target:
                r -= 1
            elif s < target:
                l += 1
            else:
                ans.append([l,r])
                while l+1 < len and nums[l] == nums[l+1]:
                    l += 1
                while r-1 >= 0 and nums[r] == nums[r-1]:
                    r -= 1
                l += 1
                r -= 1
        # print(ans)
        return ans
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort() #O(nlogn)
        answer = []
        k = len(nums)-1

        while k >= 0:
            tps = self.twoSum(nums, k, -nums[k])
            if tps:
                for i,j in tps:
                    answer.append((nums[i],nums[j],nums[k]))
            while k-1 >= 0 and nums[k] == nums[k-1]:
                k -= 1
            k -= 1
        return answer
    