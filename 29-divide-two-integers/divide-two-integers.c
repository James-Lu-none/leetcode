int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    // 計算正負號
    int negatives = 2;
    if (dividend > 0) { negatives--; dividend = -dividend; }
    if (divisor > 0)  { negatives--; divisor = -divisor; }

    int quotient = 0;

    // 用負數比大小：dividend 越負，絕對值越大
    // dividend <= divisor 代表 |dividend| >= |divisor|
    while (dividend <= divisor) {
        int value = divisor;
        int power_of_two = -1;

        // 避免 value + value 溢位 (value >= -1073741824)
        while (value >= -1073741824 && value + value >= dividend) {
            value += value;
            power_of_two += power_of_two;
        }

        dividend -= value;
        quotient += power_of_two; // quotient 累積負數商
    }

    return (negatives == 1) ? quotient : -quotient;
}