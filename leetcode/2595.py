class Solution:
    def evenOddBit(self, n: int) -> list[int]:
        eo, even, odd = True, 0, 0
        while n:
            x = n % 2
            n //= 2
            if x and eo:
                even += 1
            elif x and not eo:
                odd += 1
            eo = not eo
        return [even, odd]
    
if __name__ == '__main__':
    print(Solution().evenOddBit(17))
