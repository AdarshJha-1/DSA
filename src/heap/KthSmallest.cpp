// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    
    int maxIdx(vector<int> &arr) {
        int mxI = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > arr[mxI]) {
                mxI = i;
            }
        }
        return mxI;
    }
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        vector<int> temp(k);
        for(int i = 0; i < k; i++) {
            temp[i] = arr[i];
        }
        
        for(int i = k; i < arr.size(); i++) {
            int mxI = maxIdx(temp);
            if(arr[i] < temp[mxI]) {
                temp[mxI] = arr[i];
            }
        }
        int ansI = maxIdx(temp);
        return temp[ansI];
    }
};
