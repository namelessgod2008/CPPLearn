#include <iostream>
#include <vector>

using namespace std;

int getSize (const vector<int>& stack) {
    return (int)stack.size();
}

vector<int> searchTgtVal(const vector<int>& stack, const int& tgt) {

    int index = 0;

    if (stack.empty()) {
        return {};
    }
    const int *ptr = &stack[0];
    vector<int> tgtValIndex;

    while ( index < getSize(stack)) {
        if (const int currentVal = *ptr; currentVal == tgt) {
            tgtValIndex.push_back(index);
        }
        ptr++;
        index++;
    }
    return tgtValIndex;
}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        char op[n];
        int val[n];

        for (int i = 0; i < n; ++i) {
            cin >> op[i] >> val[i];
        }

        vector<int>stack;
        vector<char>intendedOps;

        for (int opIndex = 0; opIndex < n; opIndex++) {

            const bool notHasTargetVal = searchTgtVal(stack, val[opIndex]).empty();

            if (op[opIndex] == '+') {
                if (notHasTargetVal) {
                    stack.push_back(val[opIndex]);
                    intendedOps.push_back('+');
                }
                else {
                    int tgtIndex = searchTgtVal(stack, val[opIndex])[0];
                    while ((int)stack.size() > tgtIndex) {
                        stack.pop_back();
                        intendedOps.push_back('-');
                    }
                    stack.push_back(val[opIndex]);
                    intendedOps.push_back('+');
                }
            }
            else if (op[opIndex] == 'T') {
                intendedOps.push_back('?');
            }
            else if (op[opIndex] == 'F') {
                if (notHasTargetVal) {
                    intendedOps.push_back('?');
                }
                else {                       // x 在栈中
                    int tgtIndex = searchTgtVal(stack, val[opIndex])[0];
                    while ((int)stack.size() > tgtIndex) {   // 弹出 [tgtIndex..末),含 x 自己
                        stack.pop_back();
                        intendedOps.push_back('-');
                    }
                    intendedOps.push_back('?');
                }
            }
        }

        for (const char& intendedOperation : intendedOps) {
            cout << intendedOperation;
        }

        for (int leftVals = getSize(stack);leftVals > 0;leftVals--) {
            cout << '-';
        }

        cout << std::endl;

    }

    return 0;
}