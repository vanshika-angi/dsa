//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            int n = sc.nextInt();
            int d = sc.nextInt();
            
            Solution ob = new Solution();
            
            ArrayList<Integer> res = ob.rotate (n, d);
            System.out.println(res.get(0));
            System.out.println(res.get(1));
            
           
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    
    ArrayList<Integer> rotate(int N, int D)
    {
       ArrayList<Integer> ans=new ArrayList<Integer>();
    //   int left_mask=N>>(16-D);
    //   int right_mask=N<<(16-D);
    //   System.out.println(right_mask);
       
    //   int left_val=N<<D;
    //   int right_val=N>>D;
    //   System.out.println(right_val);
    //   left_val=left_val|left_mask;
    //   right_val=right_val|right_mask;
       
    //   ans.add(left_val);
    //   ans.add(right_val);
            D=D%16;

            int n1=N<<D|N>>(16-D);

            int n2=N>>D|N<<(16-D);
            ans.add(n1&65535);
            ans.add(n2&65535);
            

            // return {n1&65535,n2&65535};
       
      return ans;
       
    }
}