#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N,S,count=0;
  int arr[20];
  cin >> N >> S;

  for(int i=0;i<N;i++)
    cin >> arr[i];

  for(int i=1;i<(1<<N);i++) {
    int sum =0;
    for(int j=0;j<N;j++)
    {
      if(i&(1<<j)) sum += arr[j];
    }
    if(sum==S) count +=1;
  }
  cout << count;
}
