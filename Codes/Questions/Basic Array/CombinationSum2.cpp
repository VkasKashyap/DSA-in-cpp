#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void function(vector<int>& candidates, int target, vector<vector<int>>& ans, int index, vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
        return;
        }
        for(int i = index ; i<candidates.size() ; i++){
            if(i > index && candidates[i] == candidates[i-1])   continue;
            if(candidates[i] > target)  break;
            ds.push_back(candidates[i]);
            function(candidates,target-candidates[i],ans,i+1,ds);
            ds.pop_back();
        }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    function(candidates,target,ans,0,ds);
    return ans;
}
int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates, target);
    cout<<"{";
    for(int i=0 ; i<ans.size() ; i++){
        cout<<"{";
        for(int j=0 ; j<ans[i].size() ; j++){
            cout<<ans[i][j];
        }
        cout<<"}, ";
    }
    cout<<"}";

    return 0;
}