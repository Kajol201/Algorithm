#include <iostream>
#include <vector>
using namespace std;

void genMagicSquare(int n) {
    if (n % 2 != 0 || n % 4 == 0) {
        cout << "Order must be singly even (e.g., 6, 10).\n";
        return;
    }

    int h = n / 2, s = h * h;
    vector<vector<int>> m(n, vector<int>(n, 0));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            int b = i * h + j + 1;
            m[i][j] = b;
            m[i + h][j + h] = b + s;
            m[i][j + h] = b + 2 * s;
            m[i + h][j] = b + 3 * s;
        }
    }

    int k = h / 2;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < k; j++) {
            swap(m[i][j], m[i + h][j]);
        }
        for (int j = n - k + 1; j < n; j++) {
            swap(m[i][j], m[i + h][j]);
        }
    }

    for (int i = 0; i < h; i++) {
        swap(m[i][k], m[i + h][k]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the order of the magic square: ";
    cin >> n;
    genMagicSquare(n);
    return 0;
}
