int divide(int dividend, int divisor) {
    // if(!divisor) return -1; // divisor != 0 in constraints
    bool q_is_negative = (dividend < 0) ^ (divisor < 0);
    long long result = 0;

    // long long (64 bits) is required otherwise it will overflow
    // if value is INT_MIN (-2147483648)
    long long abs_dividend = dividend;
    long long abs_divisor = divisor;
    abs_dividend = (abs_dividend ^ abs_dividend>>63) - (abs_dividend>>63);
    abs_divisor = (abs_divisor ^ abs_divisor>>63) - (abs_divisor>>63);

    for (int i=63; i>=0; i--) {
        if (abs_dividend>>i >= abs_divisor){
            abs_dividend -= abs_divisor<<i;
            result |= (long long)1<<i;
        }
    }
    
    if(q_is_negative) return -result;
    else if(result > INT_MAX) return INT_MAX;
    else return result;
}