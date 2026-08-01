class Solution {
public:
    int partition(vector<int>&nums ,int left , int right){
        int i = left; 
        int j = right ; 
        int pivot = nums[left];
        while(i< j){
            while(i<=right && nums[i] <= pivot){
                i++;
            }
            while(j>= left && nums[j] > pivot){
                j--;
            }
            if(i < j )swap(nums[i] ,nums[j]);
        }
        swap(nums[j] ,nums[left]);
        return j ; 
    }
    void quicksort(vector<int>&nums, int low , int high){
        if(low < high){
            int pindex = partition(nums , low , high );
            quicksort(nums , low , pindex- 1 );
            quicksort(nums , pindex +1  , high );
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        //lets sort it using quick sort
        quicksort(nums , 0 , nums.size() -1 );
        return nums; 
    }
};