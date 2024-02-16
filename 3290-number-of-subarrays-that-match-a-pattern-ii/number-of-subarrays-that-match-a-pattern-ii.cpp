class Solution {

    vector<int> LPS(vector<int>& pattern){
        int n=pattern.size();
        vector<int> lps(n,0);
        int pre=0;
        int suf=1;
        while(suf<n){
            if(pattern[pre]==pattern[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }else{
                if(pre==0){
                    suf++;
                }else{
                    pre=lps[pre-1];
                }
            }
        }
   
        return lps;
    }

    int KMP(vector<int>& nums2, vector<int>& pattern){
        vector<int> lps=LPS(pattern);
        int n=nums2.size();
        int m=pattern.size();
        int i=0;
        int j=0;
        int ans=0;
        while(i<n){
      
            if(nums2[i]==pattern[j]){
                i++;
                j++;
                if(j==m){
                    ans++;
                    j=lps[j-1];
                }
            }else if(nums2[i]!=pattern[j]){
                if(j==0){
                    i++;
                }else{
                    j=lps[j-1];
                }
            }
            
        }
       
        return ans;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size();
        vector<int> nums2;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]>nums[i]){
                nums2.push_back(1);
            }else if(nums[i+1]==nums[i]){
                nums2.push_back(0);
            }else{
                nums2.push_back(-1);
            }
        }
     
        int ans=KMP(nums2, pattern);
        
        return ans;

    }
};