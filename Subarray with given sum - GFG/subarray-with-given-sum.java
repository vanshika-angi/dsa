//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class Main{
	static BufferedReader br;
    static PrintWriter ot;
    public static void main(String[] args) throws IOException{
        
        br = new BufferedReader(new InputStreamReader(System.in));
        ot = new PrintWriter(System.out);

        int t = Integer.parseInt(br.readLine());

        while(t-->0){
            
            String s[] = br.readLine().trim().split(" ");
            
            int n = Integer.parseInt(s[0]);
            int k = Integer.parseInt(s[1]);
            int a[] = new int[n];
            s = br.readLine().trim().split(" ");
            for(int i = 0; i < n; i++)
                a[i] = Integer.parseInt(s[i]);
            Solution obj = new Solution();
            ArrayList<Integer> res = obj.subarraySum(a, n, k);
            for(int ii = 0;ii<res.size();ii++)
                ot.print(res.get(ii) + " ");
            ot.println();
        }
        ot.close();
    }

}
// } Driver Code Ends


class Solution
{
    //Function to find a continuous sub-array which adds up to a given number.
    static boolean isValid(int sum,int s, int l, int r, ArrayList<Integer> ans)
    {
       
       if(sum==s)
       {
          ans.add(l+1);
          ans.add(r+1);
          return true;
       } 
       return false;
    }
    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) 
    {
        ArrayList<Integer> ans=new ArrayList<Integer>();
        if(s==0){
            ans.add(-1);
            return ans;
        }
       int l=0,r=0;
       int sum=0;
       
       
       for( r=0;r<n;r++)
       {
           sum=sum+arr[r];
           
           if(isValid(sum,s,l,r,ans))
           {
              return ans;
           }
           
           while(sum>s)
           {
               sum=sum-arr[l];
               l++;
               if(isValid(sum,s,l,r,ans))
               {
                  return ans;
               }
           }
           
           
       }
       if(ans.size()==0)ans.add(-1);
       return ans;
    }
}