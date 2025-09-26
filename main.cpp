#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Item {
    int weight, value;
};

// Function to solve the knapsack problem using a complete search
void knapsackCompleteSearch(int capacity, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    int maxValue = 0;
    vector<int> bestCombination;

    // Generate all possible subsets of items
    for (int subset = 0; subset < (1 << n); subset++) {
        int currentWeight = 0, currentValue = 0;
        vector<int> currentCombination;

        for (int i = 0; i < n; i++) {
            if (subset & (1 << i)) { // Check if item i is included in the subset
                currentWeight += weights[i];
                currentValue += values[i];
                currentCombination.push_back(i + 1);
            }
        }

        // Update the best solution if valid and better
        if (currentWeight <= capacity && currentValue > maxValue) {
            maxValue = currentValue;
            bestCombination = currentCombination;
        }
    }

    // Output the results
    cout << "Maximum Value: " << maxValue << endl;
    cout << "Selected Items: ";
    for (size_t i = 0; i < bestCombination.size(); i++) {
        cout << bestCombination[i] << (i == bestCombination.size() - 1 ? "" : ", ");
    }
    cout << endl;
}

int main() {
    int capacity;
    vector<int> weights, values;

    cout << "Enter maximum capacity: ";
    cin >> capacity;

    cout << "Enter weights and values (format: weight value), one per line. Enter an empty line to finish:" << endl;
    cin.ignore();
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        int weight, value;
        ss >> weight >> value;
        weights.push_back(weight);
        values.push_back(value);
    }

    knapsackCompleteSearch(capacity, weights, values);

    return 0;
}
