#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};


bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items, int n) {

    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {

            currentWeight += items[i].weight;
            maxValue += items[i].value;
        } else {

            int remainingWeight = W - currentWeight;
            maxValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break; // Bag is full
        }
    }

    return maxValue;
}

int main() {
    int n, W;
    cout << "Enter the number of items and the capacity of the knapsack: ";
    cin >> n >> W;

    vector<Item> items(n);
    cout << "Enter the values and weights of the items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    double maxValue = fractionalKnapsack(W, items, n);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}

