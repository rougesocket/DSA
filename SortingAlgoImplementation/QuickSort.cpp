class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high)return;
        int mi = partition(arr,low,high);
        quickSort(arr,low,mi-1);
        quickSort(arr,mi+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot= arr[high];
       int i=low,j=low;
       while(i<=high){
           if(arr[i]<=pivot){
               swap(arr[i],arr[j]);
                j++;
           }
           i++;
       }
       return j-1;
    }
};
