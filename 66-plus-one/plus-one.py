class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        res = []
        num0 = 0
        for order in range(len(digits)):
            num0 += digits[-order-1] * 10**(order)
            print(num0)
        num = num0 + 1
        while num > 0:
            res.append(num % 10)
            num = num // 10
        return res[::-1]