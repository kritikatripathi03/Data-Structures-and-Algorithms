#include<bits/stdc++.h>
using namespace std;

int main(){
      //Write your code here.
      vector<vector<int>> v {{1, 5, 8},{9, 6, 7}, {3, 4, 2}};
      int start = INT_MAX, end = INT_MIN;
      for(int i = 0; i < 3; i++){
            int arr_sum = 0;
            for(int j = 0; j < v.size(); j++){
                  cout << v[i][j] << endl;
                  arr_sum += v[i][j];
            }
            cout << "Sum: " << arr_sum << end;
      }
      return 0;
}