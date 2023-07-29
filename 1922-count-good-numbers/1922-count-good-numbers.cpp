class Solution {
public:
    int mod=1000000000+7;
    long long mypow(long long x,long long n)
    {
        if(n==0)return 1;
        if(n==1)return x;
        long long ans = mypow(x,n/2)%mod;
        ans = (ans*ans)%mod;
        
        if(n%2==1)ans = (x*ans)%mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long  even = n/2 + n%2;
        
        
        return (mypow(4,odd)*mypow(5,even))%mod;
    }
};