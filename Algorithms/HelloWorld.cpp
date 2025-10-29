#include<iostream>
#include <vector>
using namespace std;
int firstMissingPositive(vector<int>& nums) {
        // int max = 0;
        int n = nums.size();
        for(int i =0; i<n;i++){
            if(nums[i]<= 0 || nums[i] > n){
                nums[i] = n+1;
            }
        }
        for(int i =0; i<n;i++){
            cout<<nums[i]<<"  "<<endl;
        }
        for(int i =0; i<n;i++){
            if(nums[i]> 0 && nums[i] <=n){
                nums[nums[i]-1] = nums[i]*(-1);
            }
        }
        for(int i =0; i<n;i++){
            cout<<nums[i]<<"  "<<endl;
        }
        for(int i = 0; i<n;++i){
            if(nums[i] >0) return i+1;
        }
        return n+1;
    }
int main() {
    vector<int> nums = {3,4,-1,1};
    int result = firstMissingPositive(nums);
    cout<<result<<endl;

}