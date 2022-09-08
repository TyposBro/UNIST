unsigned floatAbsVal(unsigned uf)
{
    /*
     * Lorem ipsum dolor sit amet consectetur adipisicing elit.Dolorum est
     * commodi ducimus repellendus eos sint beatae praesentium libero
     * deserunt, architecto incidunt.Earum alias dolorem non quibusdam modi
     * perferendis repellendus.Totam.
     */
    unsigned expo = (uf >> 23) & 0xFF;
    unsigned fracc = uf << 9;
    if (expo == 0xFF && fracc != 0x00)
        return uf;

    return uf & ~(1 << 31);
}

unsigned floatNegate(unsigned uf)
{
    /*
     * Since it's two's complement we can negate
     * with the help of leading 1
     * which is uf^10000000000000000000000000000000 (32)
     */
    unsigned e = 0xFF & (uf >> 23);
    unsigned f = uf << 9;
    if (e == 0xFF && f != 0x00)
        return uf;

    return (1 << 31) ^ uf;
}

unsigned floatPower2(int x)
{
    /*
     * The maximum range that a floating point number can represent is
     * <2 * 2 ^ (254 - 127)-><2 ^* 128, so X> 127, directly overflowing the minimum range represented
     * by a floating point number X >= 2 ^ (1 - 127) * 2 ^ (-23)is
     * equivalent to X >= 2 ^ -149, so X<-149 directly becomes 0
     * Considering the 2 cases of EXP> 0 and = 0. When EXP> 0, the answer
     * is EXP << 23. Because FRAC is all 0, it represents the range of 1 -
     * 2 ^ 127 EXP = 0, the range of X is[-127, -149], 149, just move 1U to
     * the left by the displacement of FRAC.to the power of 2 ^ -(23 - FRAC)
     */

    int frac = x + 149;
    if (x > 127)
        return 0x7f800000u;
    if (x < -149)
        return 0u;
    if (x >= -126)
    {
        unsigned exp = x + 127;
        return exp << 23;
    }
    return 1u << frac;
}

int isPower2(int x)
{
    /*
     * If we subtract 1 from the power of 2 what we get is 1s at all the
     * places from the end of the binary number till we will not get 1 set
     * bit. And, if we apply Bitwise AND operator we should only get zeros.
     */
    int a = x & (x - 1);

    //! Honestly I don't know why this works
    //! x <= 0? 0:!(x & (x - 1)); would be much simpler version
    //! if we were allowed to use if statements
    int b = ((!(x >> 31)) & (~(!x)));
    return (!a) & b;
}

int logicalNeg(int x)
{
    /*
     * In most implementations, a right shift on a signed integer is
     * usually an arithmetical shift(e.g.the sign bit is copied over).As a
     * result, right shift x and its negation by 31. One of those two will
     * be a negative value, resulting in 0xFFFFFFFFFF when right shifted by
     * 31(of course, if x = 0, the right shift will result in 0x0, which is
     * what we want).Because we don't know whether x or its negation is
     * a negative integer, we simply OR them together to achieve what we
     * want. Then we can add 1.
     */

    return ((x >> 31) | ((~x + 1) >> 31)) + 1;
}

int logicalShift(int x, int n)
{
    /*
     *   First we need to convert it to unsigned int to make sure that
     *   the left most interger is 0 since it's two's complement.
     *   After that we can safely shift it by n and type case again
     */
    int m = ~(-1 << n) << (32 - n);
    return ~m & ((x >> n) | m);
}

int replaceByte(int x, int n, int c)
{
    /*
     * Mask out current byte value and OR in replacement
     */
    //* Store whole byte n in a by shifting by 3
    int byte = n << 3;

    //* Mask of 1's that shifts by a byte
    int mask = 0xFF << byte;

    //* Shift bytes
    int shift = c << byte;

    //* replace with the byte c that you wanted to add by using mask and OR
    return shift | (~mask & x);
}

int rotateRight(int x, int n)
{
/*
 * n % 32: prevent from right shifting more than int width
 * >>: right shift by n bits
 * (32-n) % 32: prevent from left shifting more than int width
 * <<: shift the bits to rotate all the way to the left
 * |: combine left and right shifted results
 */
#include <limits.h>

    unsigned unsigned_x = x;
    unsigned unsigned_n = n;
    unsigned_n %= (sizeof(int) * CHAR_BIT);
    unsigned y = unsigned_x >> unsigned_n;
    if (unsigned_n > 0)
        y |= unsigned_x << ((sizeof(int) * CHAR_BIT) - unsigned_n);

    return y;
}

int satMul2(int x)
{
    //! I give up on this one.
    return 0;
}

int sign(int x)
{
    /*
     * The signed shift n>>31 converts every negative number into -1 and
     * every other into 0.
     * When we do a -n>>31, if it is a positive number then it will return * -1 as we are doing -n>>31 and the vice versa when we do for a
     * negative number.
     * But when we do for 0 then n>>31 and -n>>31 both returns 0
     */
    return (x >> 31) - (-x >> 31);
}

int thirdBits(void)
{
    //! Didn't get a thing why we're doing it
    int temp1 = 0x49;          //* 0000 0000 0000 0000 0000 0000 0100 1001
    int shift = temp1 << 9;    //* 0000 0000 0000 0000 1001 0010 0000 0000
    int temp2 = shift | temp1; //* 0000 0000 0000 0000 1001 0010 0100 1001
    //! shift by (4*3+6)
    int shift2 = temp2 << 18; //* 0100 1001 0010 0100 0000 0000 0000 0000

    return temp2 | shift2; //* 0100 1001 0010 0100 1001 0010 0100 1001
}

int upperBits(int n)
{
    /*
     * If there is a leading one, push one over to the most essential bit, * because it's arythmetic >>, it'll be full with ones. n&1 - unless
     * in the case of 0. (first number determined)
     */
    return ((!!n & 1) << 31) >> (n + ~0);
}
