class Solution:
    def hammingDistance(self, x, y):
        ans = 0
        for i in range(32):
            if 2**i & x != 2**i & y:
              ans += 1
        return ans

    def hammingDistance2(self, x, y):
        # create the look up table
        # dict {value: hamming distance}
        bitmap = {
            0: 0, # b000
            1: 1, # b001
            2: 1, # b010
            3: 2, # b011
            4: 1, # b100
            5: 2, # b101
            6: 2, # b110
            7: 3, # b111
        }
        ans = 0

        # show the different bits
        check = x ^ y

        while check:
            # gets the hamming distance of the smallest 3 bits
            ans += bitmap[check & 7]

            # shifts all bits over by 3
            check >>= 3
        return ans

    def hammingDistance3(self, x, y):
        return bin(x ^ y).count('1')
