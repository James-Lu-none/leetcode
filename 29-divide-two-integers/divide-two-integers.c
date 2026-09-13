int divide(int dividend, int divisor) {
    // 唯一會超出 32-bit signed int 範圍的情況
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;

    bool is_negative = (dividend < 0) ^ (divisor < 0);

    // 安全轉成 unsigned int 取絕對值
    unsigned int a = (dividend < 0) ? -(unsigned int)dividend : (unsigned int)dividend;
    unsigned int b = (divisor < 0)  ? -(unsigned int)divisor  : (unsigned int)divisor;

    unsigned int quotient = 0;

    // 32 位元無符號數，最多右移 31 位
    for (int i = 31; i >= 0; i--) {
        if ((a >> i) >= b) {
            quotient += (1U << i);
            a -= (b << i);
        }
    }

    // return value must reside in [−2^31, 2^31 − 1]
    // so we have to handle edge case where 
    // if (is_negative && quotient > INT_MAX) return INT_MIN;

    return is_negative ? -(int)quotient : (int)quotient;
}