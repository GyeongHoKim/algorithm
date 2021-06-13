#include <iostream>
using namespace std;

bool eratos[1001];
int quest[100];

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> quest[i];
    
    fill_n(eratos, 1001, true);
    eratos[0] = false;
    eratos[1] = false;
    for (int i = 2; i < 1001; ++i) {
        for (int j = 2; i * j < 1001; ++j) {
            if (eratos[i * j])
                eratos[i * j] = false;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (eratos[quest[i]])
            ++cnt;
    }

    cout << cnt;
    return 0;
}