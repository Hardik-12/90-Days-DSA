#include <bits/stdc++.h>
using namespace std;

// Find repeating and missing from an array consisting of numbers from 1 to n
int *findTwoElement(int *arr, int n) {
    // code here
    
    long long sum_arr = 0;
    long long sum_arr_sq = 0;
    for(int i=0;i<n;i++){
        sum_arr+= arr[i];
        sum_arr_sq+= (long long)arr[i]*arr[i];
    }
    long long org_sum = ((long long)n*(n+1))/2;
    long long org_sum_sq = ((long long)n*(n+1)*(2*n + 1))/6;
    long long res = sum_arr - org_sum;
    long long res2 = sum_arr_sq - org_sum_sq;
    long long inter = res2/res;
    long long repeating = (res + inter)/2;
    long long missing = repeating - res;
    int *ans = new int[2];
    ans[0] = repeating;
    ans[1] = missing;
    return ans;
}