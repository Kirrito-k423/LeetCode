    #define ZERO 0
    #define ONE 1
    class Solution {
    public:
        int findTheLongestBalancedSubstring(string s) {
            int ans = 0;
            int n = s.size();
            int index = 0;
            //去除初始1
            while(index < n && s[index]=='1'){
                index++;
            }
            int count = 0;
            int count0 = 0;
            int count1 = 0;
            int status=ZERO;
            for(;index<n;index++){
                if(status==ZERO){
                    if(s[index]=='0'){
                        count0++;
                        count++;
                    }else{
                        status=ONE;
                        count1++;
                        count++;
                    }
                }else{
                    //status=ONE;
                    if(s[index]=='0'){
                        status=ZERO;
                        ans = max(ans,2*min(count1,count0));
                        count0 =1;
                        count1=0;
                        count = 1;
                    }else{
                        count1++;
                        count++;
                    }
                }
            }
            if(status==ONE)ans = max(ans,count);
            return ans;
            
        }
    };