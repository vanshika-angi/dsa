class Solution {
public:
    int climbStairs(int n) {

        if(n==0 || n==1)return 1;
       int n1=1;
       int n2=1;
        int steps=0;
       for(int i=2;i<=n;i++)
       {
            steps=n1+n2;
            
            n2=n1;
            n1=steps;
            

       } 
       return steps;
    }
};