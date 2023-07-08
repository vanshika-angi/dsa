//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;


// } Driver Code Ends
//User function Template for Java

class Solution
{
    //Function to swap odd and even bits.
    public static int swapBits(int n) 
    {
	   // int even= n&0xAAAAAAAA;
	   // int odd=n&0x55555555;
	    int even=1;
	    for(int i=1;i<32;i++)
	    {
	        if(i%2==0)
	        {
	            even=even<<1;
	            even=even+1;
	        }
	        else
	        {
	            even=even<<1;
	        }
	    }
	    int odd=0;
	    for(int i=1;i<32;i++)
	    {
	        if(i%2==0)
	        {
	            odd=odd<<1;
	            
	        }
	        else
	        {
	            odd=odd<<1;
	            odd=odd+1;
	        }
	    }
	    
	    
	    int even_val=n&even;
	    int odd_val=n&odd;
	    even_val=even_val>>1;
	    odd_val=odd_val<<1;
	    return even_val|odd_val;
	}
    
}

//{ Driver Code Starts.

class BitWise{

	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();//testcases
		while(t-->0){
		    int n = sc.nextInt();//taking n
		    
		    Solution obj = new Solution();
		    
		    //calling swapBits() method of class
		    //Swap
		    System.out.println(obj.swapBits(n));
		}
	}
}
// } Driver Code Ends