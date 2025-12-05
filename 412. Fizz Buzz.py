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