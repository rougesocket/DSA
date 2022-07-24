#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

void countsort(vector<int>& arr, int max, int min) {
  vector<int> freq(max-min+1);
  for(int i=0;i<arr.size();i++)freq[arr[i]-min]++;
  for(int i=1;i<freq.size();i++)freq[i]+=freq[i-1];
  
  vector<int> ans(arr.size());
  for(int i=arr.size()-1;i>=0;i--){
      ans[freq[arr[i]-min]-1]=arr[i];
      freq[arr[i]-min]--;
  }
  arr=ans;
}

void Display(vector<int>& arr) {
  for (int ele : arr) {
    cout << ele << endl;
  }
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int maxi = (int) -1e9;
  int mini = (int)1e9;

  for (int i = 0; i < n; i++) {
    mini = min(mini, arr[i]);
    maxi = max(maxi, arr[i]);
  }

  countsort(arr, maxi, mini);
  Display(arr);

}
