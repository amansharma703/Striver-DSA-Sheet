// PROBLEM 
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


/*
    Solution : 
    Time complexity : O(NlongN) 
    Space Complexity : O(N)

    Create a 2D vector & store  push_back({start[i], end[i]})
    Sort with end array element
    Now choose an interval. Mark its end time.
    Choose the next interval only if its start time is higher than previous end time.
    Greedily repeat the process. 

*/


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.

    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int> > v;
        
        for(int i=0;i<n;i++){
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(),[](vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
        });
         
        int endPrev = v[0][1];
        int ans = 1;
        
        for(int i=0;i<n;i++){
            int start = v[i][0];
            if(start> endPrev){
                ans++;
                endPrev = v[i][1];
            }
        }
        return ans;
    }
};