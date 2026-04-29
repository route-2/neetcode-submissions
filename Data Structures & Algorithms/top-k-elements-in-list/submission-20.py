class Solution:
    def topKFrequent(self, nums, k):
        freq = {}

        # count frequency (like unordered_map++)
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1

        # buckets = vector<vector<int>>(n+1)
        buckets = [[] for _ in range(len(nums) + 1)]

        # fill buckets
        for num in freq:
            count = freq[num]
            buckets[count].append(num)

        res = []

        # traverse from back
        for i in range(len(nums), 0, -1):
            for num in buckets[i]:
                res.append(num)
                if len(res) == k:
                    return res