#### Approach #1 Brute Force [Accepted]

**Intuition**

Compare the bits in each number one by one. If they are different at that index, increment the count.

**Algorithm**

Suppose we loop through each bit. If they are both the same, then the count will not increment. The count will increment if both bits in x and y are different at the same index.

The approach below uses 2^i because in binary, each bit is a power of 2. The largest bit is 2^31, and the smallest bit is 2^0. The for loop simply checks if the bit is set at that power of 2.

**How bits in binary map out to powers of 2**  
2^0 = bit 0  
2^1 = bit 1  
...  
2^30 = bit 30  
2^31 = bit 31  

**Python**

```python
def hammingDistance(self, x, y):
    ans = 0
    for i in range(32):
        if 2**i & x != 2**i & y:
          ans += 1
    return ans
```

**Complexity Analysis**

* Time complexity : $$O(n)$$.

To verify if bits within index range $$[0, 31]$$ are different,
we need to scan all of them.

---
#### Approach #2 Look Up Tables and Using XOR [Accepted]

**Intuition**
Let's kick it up a notch. How about we compare 3 bits at a time? A look up table can also be used to get the right hamming distance for those three bits, so we can add it to the final result.

**Algorithm**

Rather than look up each bit, creating a lookup table for 3 bits will shorten bit manipulation. The concepts below (shifting bits, XOR) are needed to implement a more efficient solution.

**Shifting Bits**

In the previous solution, it was explained that each bit is a power of 2. Using that knowledge, bit-wise shifting can also be incorporated.  

Shifting a number to the right by one bit is the same as dividing by two. This will shift all bits to the right. The new bit coming in from the leftmost position will be a 0.   

Using the example below, 6 in binary is 110. The 'b' in front just means it is meant to be read as 1s and 0s.  

If 6 is shifted to the right by 1 bit, it pushes everything over by one bit. This will remove the 0 and fill in the empty space on the left with another 0. Shifting 3 to the right one bit will remove one 1, and the space on the left will be filled in with a 0 again. It is important to note that you can shift multiple bits at once, and it will produce the same value as shifting one bit at a time.

6 = b110 # starting here  
3 = b011 # shift 6 right 1  OR (6 >> 1)  
1 = b001 # shift 3 right 1  OR (6 >> 1) OR (3 >> 1)  

**XOR**

XOR is an exclusive or. This bit-wise operator will return 0 (False) if all bits are the same. Below are examples to explain in more detail.

* Single Bit Example:  
0 XOR 0 = 0  
0 XOR 1 = 1  
1 XOR 0 = 1  
1 XOR 1 = 0  

* Multiple Bit Example:  
When using XOR for larger numbers, the same principle applies to the single bit at the index of each number.  
5 XOR 1 = 4  
Binary representation is easier to show how it works.  
b101 XOR b001 = b100  
The only bit that differs is at index 2. Therefore, the answer 4 shows that the bits are different at that index only.


**Python**

```python
def hammingDistance(self, x, y):
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

```

**Complexity Analysis**

* Time complexity : $$O(n/3) = O(n)$$. In the worst case each 3 bits will be scanned until all 32 bits have been read. This is quicker than the previous implementation when the values of x and y only have 32 bits.

---
#### Approach #3 Using Built In Functions [Accepted]

**Algorithm**

Using the same initial approach as in Approach #2, XOR x and y to get the location of the different bits. Then find how many changed bits there are with the language's standard library if available.

**Python**

```python
def hammingDistance(self, x, y):
    return bin(x ^ y).count('1')
```
