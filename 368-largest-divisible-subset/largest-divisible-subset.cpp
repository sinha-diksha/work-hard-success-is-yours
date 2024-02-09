class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int> > v(n);
    
        for(int i=n-1; i>=0; i--){
            
            cout<<i<<endl;
            int j=-1;
            int including=-1;
            for(j=i+1; j<n; j++){
                if(nums[j]%nums[i]==0){
                    if(including==-1){
                        including=j;
                    }else{
                        if(v[j].size()>v[including].size()){
                            including=j;
                        }
                    }
                    
                }
            }
            
            if(including!=-1){
                cout<<"including"<<endl;
                vector<int> v1=v[including];
                v1.push_back(nums[i]);
                v[i]=v1;
            }
            else{
                v[i]={nums[i]};
            }
            cout<<v[i].size()<<endl;
        }
        cout<<"fshgjkdasg"<<endl;
        int maxSize=1;
        int index=0;
        for(int i=0; i<n; i++){
            cout<<i<<endl;
            cout<<v[i].size()<<endl;
        }
        int i;
        
        for(i=0; i<n; i++){
            if(v[i].size()>maxSize){
                maxSize=v[i].size();
                index=i;
            }
        }

        return v[index];
    }
};