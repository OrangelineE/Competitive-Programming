class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        endpoints = {}
        for i, c in enumerate(s):
            endpoints[c] = i

        maxEndpoint = 0
        ans = []
        start = -1
        maxEndpoint = endpoints[s[0]]
        for i, c in enumerate(s):
            if endpoints[c] > maxEndpoint and i < maxEndpoint:
                maxEndpoint = endpoints[c]
            elif i >= maxEndpoint:
                ans.append(maxEndpoint - start)
                start = maxEndpoint
                if i < len(s) - 1:
                    maxEndpoint = endpoints[s[i + 1]]

        return ans
