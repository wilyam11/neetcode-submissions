class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zero = 0
        pd = 1
        arr = [0]*len(nums)
        for i in range(len(nums)):
            if nums[i] == 0:
                zero += 1
            else:
                pd *= nums[i]
        if zero > 1:
            return arr
        elif zero == 1:
            for i in range(len(nums)):
                if nums[i] == 0:
                    arr[i] = pd
        else:
            for i in range(len(nums)):
                arr[i] = int(pd/nums[i])
        return arr