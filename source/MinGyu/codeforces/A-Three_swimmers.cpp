#include <iostream>
#include <climits>

using namespace std;

long long swim_time[3];
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    long long p,min_time;
    cin >> T;
    while(T--){
        min_time = LLONG_MAX;
        cin >> p >> swim_time[0] >> swim_time[1] >> swim_time[2];


        for(int i=0;i<3;++i){
            if(p > swim_time[i]){
                min_time = min(min_time, swim_time[i] - (p % swim_time[i]));
            }
            else{
                min_time = min(min_time,swim_time[i] - p );
            }
        }

        cout << min_time << '\n';
    }

    return 0;
}