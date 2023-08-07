class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(low<mid && arr[mid]<arr[mid-1])
            {
                return arr[mid];
            }
            if(mid<high && arr[mid+1]<arr[mid])
            {
                return arr[mid+1];
            }
            if(arr[low]<arr[high])return arr[low];
            if(arr[low]<=arr[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return arr[high];
    }
};