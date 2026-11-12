#include <iostream>
#include <vector>

using namespace std;

int main(){

    int width;
    int length;

    cin >> length >> width;

    int enumLength = 1;
    int enumWidth = 1;

    long long totalCountRectangle = 0;
    long long totalCountSquare = 0;

    while (enumLength <= length) {
        while (enumWidth <= width) {
            long long count = 1LL * (length - enumLength + 1)
                                   * (width - enumWidth + 1);
            totalCountRectangle += count;
            enumWidth++;
        }
        enumWidth = 1;
        enumLength++;
    }

    enumLength = 1;
    enumWidth = 1;

    while (enumWidth <= width && enumLength <= length) {
        long long count = 1LL * (length - enumLength + 1)
                               * (width - enumWidth + 1);
        totalCountSquare += count;
        enumWidth++;
        enumLength++;
    }

    totalCountRectangle -= totalCountSquare;

    cout << totalCountSquare << ' ' << totalCountRectangle << endl;

    return 0;
}
