class Solution:
    def isPalindrome(self, num: int) -> bool:
        s = bin(num)[2:]
        n = len(s)
        for i in range(0, n//2+1):
            if s[i] != s[n-i-1]:
                return False
        return True
        
    def minOperations(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            isPalin = False
            c = 0
            while not isPalin:
                isPalin = self.isPalindrome(num + c)
                if not isPalin:
                    isPalin = self.isPalindrome(num - c)
                c += 1
            ans.append(c-1)
        return ans