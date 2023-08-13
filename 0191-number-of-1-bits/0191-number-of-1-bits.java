public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int a=n;
        int cnt=0;
        for(int i=0;i<32;i++)
        {
            int temp=a&1;
            if(temp==1)cnt++;
            a = a>>1;
        }
       return cnt; 
    }
}