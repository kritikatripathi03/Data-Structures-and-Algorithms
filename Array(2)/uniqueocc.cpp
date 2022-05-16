#include<bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if((nums[i] ^ nums[i + 1]) == 0){
                ans.push_back(nums[i]); 
                i++;
            }
        }
        cout << endl;
        return ans;
}
int main(){
    vector<int> ans = {4,3,2,7,8,2,3,1};
    vector<int> res = findDuplicates(ans);

    for(auto element:res){
        cout<<element<<" ";
    }

}