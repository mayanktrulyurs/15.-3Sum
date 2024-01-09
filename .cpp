/* better approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();

        set<vector<int>>st;
        for (int i=0;i<n;i++){
            set<int>hashSet;
            for (int j=i+1;j<n;j++){

                int otherNum=-(nums[i]+nums[j]);

                if (hashSet.find(otherNum)!=hashSet.end()){
                    vector<int>temp={nums[i],nums[j],otherNum};
                    sort(temp.begin(),temp.end());

                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>>ans (st.begin(),st.end());  // or 1) vector<vector<int>> ans;
                                                            ans.insert(ans.end(), st.begin(), st.end());
                                                            2) vector<vector<int>> ans;
                                                            ans.assign(st.begin(), st.end());


        return ans;
    }
};

Complexity Analysis
Time Complexity: O(N2 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set. */


/*

best approach:
Time Complexity: O(NlogN)+O(N2), where N = size of the array.
Reason: The pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N2). 

Space Complexity: O(no. of triplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).

*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<vector<int>>ans;

        for (int i=0;i<n;i++){

            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1, k=n-1;

            while (j<k){

                int target=nums[i]+nums[j]+nums[k];

                if (target==0){
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);

                    j++;
                    k--;

                    while (j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while (j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
                else if (target<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};
