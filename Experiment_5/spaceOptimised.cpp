// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int main() {
    // Write C++ code here
    int n = 4;
    int sum = 5;
    int arr[n] = {2, 3, 5, 6};
    
   vector<int> dp(sum+1);
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
    for(int j = sum;j>=1;j--){
        if(arr[i-1]<=j){
            dp[j] = dp[j] + dp[j-arr[i-1]];
    }
    }
    }
    cout<<dp[sum];
    

    return 0;
}