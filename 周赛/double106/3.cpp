#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        //像模拟题，但是怎么模拟呢？
        int n=nums.size();
        vector<long>arr(n,0);
        long mod=1000000007;
        for(int i=0;i<n;i++){
            if(s[i]=='R')
                 arr[i]=nums[i]+d;
            else arr[i]=nums[i]-d;
        }
        sort(arr.begin(),arr.end());
        int size=n;
        int left=0,right=n-1;
        int ans=0;
        while(left<=right){
            ans = (ans%mod +(arr[right]-arr[left])*(size-1)%mod)%mod;
            left++;
            right--;
            size-=2;
        }
        return ans;
    }
};

// class Solution
// public:
// int sumDistance(vector<int>&nums,string s,int d){
// int n=nums.size();
// vector<long>arr(n,0);
// 1 ong mod=1008000007;
// for(int i=0;i<n;i++){
// if(s[i]=='R')
// arr[i]=nums[i]+d;
// else arr[i]=nums[i]-d;
// sort(arr.begin(),arr.end());
// int size=n;
// int left=0,right=n-1;
// int ans=0;
// while(left<=right){
// ans (ans%mod (arr[right]-arr[left])*(size-1)%mod)%mod;
// left++;
// right--;
// s1ze-=2;
// return ans;