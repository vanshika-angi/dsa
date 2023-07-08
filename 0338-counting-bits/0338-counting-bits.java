class Solution {
    public int[] countBits(int n) {
        int[] ans= new int[n+1];
        ans[0]=0;
        if(n<1)return ans;
        ans[1]=1;
        if(n<2)return ans;
        int j=0;
        for(int i=2;i+j<n+1;i*=2)
        {
            for(j=0;j<i && i+j<n+1;j++)
            {
                System.out.println(i);
                System.out.println(j);
                ans[i+j]=ans[j]+1;
                
            }
            j=0;
        }
        
        return ans;
    }
}