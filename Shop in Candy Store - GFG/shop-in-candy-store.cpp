//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        sort(candies, candies+N);
        int ans1=0;
        int countCandy=0;
        for(int i=0; i<N; i++){
            ans1+=(candies[i]);
            countCandy+=(k+1);
            if(countCandy>=N){
                break;
            }
        }
        
        int ans2=0;
        countCandy=0;
        for(int i=N-1; i>=0; i--){
            ans2+=(candies[i]);
            countCandy+=(k+1);
            if(countCandy>=N){
                break;
            }
        }
        
        vector<int> v;
        v.push_back(ans1);
        v.push_back(ans2);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends