#include <iostream>
#include <array>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int,10> appleHeight{};
    int height;

    for (int i=0;i<=9;++i) {
        cin>>appleHeight[i];
    }

    cin>>height;

    int *ptr = &appleHeight[0];
    int index = 0;
    int count = 0;

    while (index<=9) {
        if ((*ptr) <= (height + 30)) {
            count++;
        }
        ptr++;
        index++;
    }

    cout << count;
}