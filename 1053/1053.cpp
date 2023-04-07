class Solution {
public:
    int find(vector<int>& arr, int targetIndex){
        int value = arr[targetIndex-1];
        int low = targetIndex, high = arr.size() - 1;
        if(value > arr[high]){return high;}
        while(low + 1 < high){
            int mid = low + (high - low) / 2;
            if(arr[mid] >= value){
                high = mid-1;
            }
            else{
                low = mid;
            }
        }
        return low;
    }
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int index = n - 1;
        while(index > 0 && arr[index] >= arr[index - 1]) {
            index--;
        }
        if(index == 0) { return arr; }
        //
        int changeI = find(arr, index);
        while(changeI>0 && arr[changeI-1] == arr[changeI]) {
            changeI--;
        }
        //change
        int tmp = arr[changeI];
        arr[changeI] = arr[index-1];
        arr[index-1] = tmp;
        return arr;
    }
};