#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

//这是一个对的的解法
//哦不我踏马提交了怎么还是错的
//孩子们这并不好笑
//我做了这题目整整三天

using namespace std;

//i wish for:
//              00                 0000000000
//            00  00            000          000
//           00    00         00                00
//          00      00       00                  00
//          00      00       00
//          0000000000       00
//          00      00       00                  00
//          00      00        00                00
//          00      00          000          000
//          00      00             0000000000
//手打求过，球球了

int getSize (const vector<int>& stack) {
    return static_cast<int>(stack.size());
}

bool notInStack(const unordered_map<int,bool>& inStack, const int& val) {
    return !static_cast<bool>(inStack.count(val));
}

int nextPosAfter(const vector<int>& positions, int index) {
    auto it = ranges::upper_bound(positions, index);
    if (it == positions.end()) return -1;
    return *it;
}

bool isDead (const int& val,
    const int currentIndex,
    unordered_map<int,vector<int>> & appearPositions,
    unordered_map<int,vector<int>> & queryPositions,
    const char op[])
{
    const int nextEventPos = nextPosAfter(appearPositions[val], currentIndex);
    if (nextEventPos == -1) {
        return true;
    }
    const char nextOp = op[nextEventPos];
    if (nextOp == 'T') {
        return false;
    }
    if (nextOp == 'F') {
        return true;
    }
    int nextQueryPos = nextPosAfter(queryPositions[val], currentIndex);
    if (nextQueryPos != -1 && nextQueryPos < nextEventPos) {
        return false;
    }
    return true;
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

        unordered_map<int,vector<int>> appearPositions;
        unordered_map<int,vector<int>> queryPositions;

        for (int i = 0; i < n; ++i) {
            cin >> op[i] >> val[i];
            appearPositions[val[i]].push_back(i);
            if (op[i] == 'T' || op[i] == 'F') {
                queryPositions[val[i]].push_back(i);//只有查询才记
            }
        }

        vector<int>stack;
        vector<char>intendedOps;

        unordered_map<int,bool> inStack;

        inStack.reserve(n);

        for (int opIndex = 0; opIndex < n; opIndex++) {

            int opVal = val[opIndex];

            const bool notHasTargetVal = notInStack(inStack, opVal);

            if (op[opIndex] == '+') {
                while (!stack.empty() && isDead(stack.back(), opIndex, appearPositions, queryPositions, op)) {
                    int back = stack.back();
                    stack.pop_back();
                    inStack.erase(back);
                    intendedOps.push_back('-');
                }
                if (!notHasTargetVal) {
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
                else {//x不在栈->直接压入
                    stack.push_back(opVal);
                    inStack[opVal] = true;
                    intendedOps.push_back('+');
                }
            }
            else if (op[opIndex] == 'T') {
                while (!stack.empty() && stack.back() != opVal && isDead(stack.back(), opIndex, appearPositions, queryPositions, op)) {
                    int back = stack.back();
                    inStack.erase(back);
                    stack.pop_back();
                    intendedOps.push_back('-');
                }
                intendedOps.push_back('?');
            }
            else if (op[opIndex] == 'F') {
                while (!stack.empty() && isDead(stack.back(), opIndex, appearPositions, queryPositions, op)) {
                    int back = stack.back();
                    inStack.erase(back);
                    stack.pop_back();
                    intendedOps.push_back('-');
                }
                if (!notHasTargetVal) {
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
                }//补else
                else {
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