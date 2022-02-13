class Solution {
public:
    double myPow(double x, int n) 
    {
        // to store the power
        long long power = n;
        double ans = 1;
        
        // if power is negative, make if positive
        if(power < 0)
            power = abs(power);
        
        // till power exist
        while(power)
        {
            // power is odd
            if(power & 1)
            {
                ans *= x;
                power--;
            }
            // otherwise , half the power
            else
            {
                x *= x;
                power /= 2;
            }
        }
        
        // if power was negative
        if( n < 0 )
            ans = 1/ans;
        
        return ans;
    }
};
