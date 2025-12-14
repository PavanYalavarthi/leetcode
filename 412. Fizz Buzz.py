"""
problem credits: https://leetcode.com/problems/fizz-buzz/

Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
 
Solution: Self explanatory
"""
class Solution:
    def fun(self, i):
        if i % 3 and i % 5:
            return str(i)
        elif i % 3 :
            return "Buzz"
        elif i % 5:
            return "Fizz"
        else:
            return "FizzBuzz"

    def fizzBuzz(self, n: int) -> List[str]:
        return list(map(self.fun, range(1,n+1)))