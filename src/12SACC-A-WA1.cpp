#include <iostream>
#include <vector>
#include <unordered_map>

//这是一个错误的解法

using namespace std;

int getSize (const vector<int>& stack) {
    return (int)stack.size();
}

bool notInStack(const unordered_map<int,bool>& inStack, const int& val) {
    return !(bool)inStack.count(val);
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
        unordered_map<int,bool> inStack;
        inStack.reserve(n);

        for (int opIndex = 0; opIndex < n; opIndex++) {

            int opVal = val[opIndex];

            const bool notHasTargetVal = notInStack(inStack, opVal);

            if (op[opIndex] == '+') {
                if (notHasTargetVal) {
                    stack.push_back(opVal);
                    inStack[opVal] = true;
                    intendedOps.push_back('+');
                }
                else {
                    while (!stack.empty()) {
                        int back = stack.back();
                        inStack.erase(back);
                        stack.pop_back();
                        intendedOps.push_back('-');
                        if (back == opVal) {
                            break;
                        }
                    }
                    stack.push_back(opVal);
                    inStack[opVal] = true;
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
                else {
                    while (!stack.empty()) {
                        int back = stack.back();
                        inStack.erase(back);
                        stack.pop_back();
                        intendedOps.push_back('-');
                        if (back == opVal) {
                            break;
                        }
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