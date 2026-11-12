#include <iostream>
#include <vector>

using namespace std;

constexpr int TOTAL_SPICE_COUNT = 10;
constexpr int MAX_SPICE_WEIGHT = 30;

int gramLimit;

vector<int> currentSolution(TOTAL_SPICE_COUNT);

vector<vector<int>> solutions = {};

int main() {

    cin >> gramLimit;

    if (gramLimit > MAX_SPICE_WEIGHT || gramLimit < TOTAL_SPICE_COUNT) {
        cout << 0;
        return 0;
    }

    for (int gram1 = 1; gram1 <= 3;++gram1) {
        for (int gram2 = 1; gram2 <= 3; ++gram2) {
            for (int gram3 = 1; gram3 <= 3; ++gram3) {
                for (int gram4 = 1; gram4 <= 3; ++gram4) {
                    for (int gram5 = 1; gram5 <= 3; ++gram5) {
                        for (int gram6 = 1; gram6 <= 3; ++gram6) {
                            for (int gram7 = 1; gram7 <= 3; ++gram7) {
                                for (int gram8 = 1; gram8 <= 3; ++gram8) {
                                    for (int gram9 = 1; gram9 <= 3; ++gram9) {
                                        int sum = gram1 + gram2 + gram3 + gram4 + gram5 + gram6 + gram7 + gram8 + gram9;
                                        int gram10 = gramLimit - sum;
                                        if (gram10 < 1 || gram10 > 3) {
                                            continue;
                                        }
                                        else {
                                            currentSolution[0] = gram1;
                                            currentSolution[1] = gram2;
                                            currentSolution[2] = gram3;
                                            currentSolution[3] = gram4;
                                            currentSolution[4] = gram5;
                                            currentSolution[5] = gram6;
                                            currentSolution[6] = gram7;
                                            currentSolution[7] = gram8;
                                            currentSolution[8] = gram9;
                                            currentSolution[9] = gram10;
                                            solutions.push_back(currentSolution);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << solutions.size() << endl;

    for (const auto& s : solutions) {
        for (int j = 0;j < TOTAL_SPICE_COUNT; ++j) {
            cout << s[j] << " ";
        }
        cout << endl;
    }
}
// void DFS(int position,int sumGrams) {
//     if (position == TOTAL_SPICE_COUNT) {
//         if (sumGrams == gramLimit) {
//             solutions.push_back(currentSolution);
//         }
//         return;
//     }
//     for (int gram = 1; gram <= 3; gram++) {
//            currentSolution[position] = gram;
//            DFS(position+1,sumGrams + gram);
//     }
// }
//
// int main () {
//
//     cin >> gramLimit;
//
//     if (gramLimit > MAX_SPICE_WEIGHT || gramLimit < TOTAL_SPICE_COUNT) {
//         cout << 0 << endl;
//         return 0;
//     }
//
//     DFS(0,0);
//
//     cout << solutions.size() << endl;
//
//     for (auto& solution : solutions) {
//         for (auto& gram : solution) {
//             cout << gram << " ";
//         }
//         cout << endl;
//     }
//
//     return 0;
// }
