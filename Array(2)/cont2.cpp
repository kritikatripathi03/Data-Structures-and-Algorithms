#include<bits/stdc++.h>
using namespace std;

char diamond(int i, int j, int s){
      bool backslash = true;
      if(i >= s/2){
            i = s - i - 1;
            backslash = !backslash;
      }

      if(j < s/2){
            j = s - j - 1;
            backslash = !backslash;
      }

      j -= s / 2;
      if(i == j){
            if (backslash){
                  return '\\';
            }
            else{
                  return '/';
            }
      }
      else if(i > j){
            return 'o';
      }
      else{
            return 'e';
      }

}

int main(){
      int s, r, c;
      cin >> s >> r >> c;
      for(int i = 0; i < r; i++){
            for(int j = 0 ; j < c; j++){
                  cout << diamond(i % s, j % s, s);
            }
            cout << endl;
      }
}