# Bitwise Operations

- Virtually any programming language will provide some way of operating on individual bits
- Depending on your application, bitwise operators can be essential for reaching peak performance of keeping your data footpring small
- C provides the following bitwise operators. All but the NOT operator are binary
- __C does not allow bitwise operations for `float` and `double`__ 

| __Symbol__ | __Description__ |
| ---------- | --------------- |
| `&`        | bitwise AND     |
| `\|`       | bitwise OR      |
| `^`        | bitwise XOR     |
| `<<`       | left shift      |
| `>>`       | right shift     |
| `~`        | bitwise NOT     |

## Bitwise AND

| __a__ | __b__ | __a & b__ |
| ----- | ----- | --------- |
| 0     | 0     | 0         |
| 0     | 1     | 0         |
| 1     | 0     | 0         |
| 1     | 1     | 1         |

- True if _both_ inputs are true

## Bitwise OR 

| __a__ | __b__ | __a \|\| b__ |
| ----- | ----- | ------------ |
| 0     | 0     | 0            |
| 0     | 1     | 1            |
| 1     | 0     | 1            |
| 1     | 1     | 1            |

- True if _either_ input is true

## Bitwise XOR

| __a__ | __b__ | __a ^ b__ |
| ----- | ----- | --------- |
| 0     | 0     | 0         |
| 0     | 1     | 1         |
| 1     | 0     | 1         |
| 1     | 1     | 0         |

- True if one of the inputs are true, but not both

## Bitwise Shift

- A left shift (moving every bit to the left once) will double the previous value for each number of shifts.
  - so, 10 << 2 = 10 * 2 * 2 = 40
  - Bits will not loop around, so once you shift the most significant bit to the left, that bit is lost
- A right shift will half the number, trunkating any decimal that would otherwise have existed.
  - 10 >> 1 = 10 / 2 = 5
  - 10 >> 2 = (10 / 2) / 2 = 2.5 => 2

## Bitwise NOT

- Applying the `~` to a value negates the bits
- That is, the 1's are flipped to 0 and vice versa

### Twos Complement

- Two's complement is a mathematical operation used for signed number representation
- __Definition__: The two's complement of an _n_-bit number is defined as its complement with respect to 2<sup>_n_</sup>. The sum of a number and it's two's complement is 2<sup>_n_</sup>.
- For example, the two's complement of the 4 bit number 1010 is 0110.

    1010 + 0110 = 10000 = 16<sub>10</sub> = 2<sup>4</sup>

- An easier way to calculate the two's complement is by inverting th ebits and adding 1

    ~(00001010) --> 11110101

    11110101 + 1 --> 11110110 = -10<sub>10</sub>

- This became negative because of how signed numbers are represented in binary

## Bitmasks

- Used to isolate a certain value or range of values of a group or bits
- Usually applied with the AND operator
  - `11001010 & 00001111 = 00001010`
  - By applying the mask `00001111`, you can isolate the last four bits of the first binary value