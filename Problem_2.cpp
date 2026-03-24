#include <iostream>
using namespace std;
typedef long long lli;

struct square_matrix {
    static const int sz = 2;
    lli a[sz][sz];

    square_matrix operator + (const square_matrix& other) const {
        square_matrix res;
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                res.a[i][j] = a[i][j] + other.a[i][j];
            }
        }
        return res;
    }

    square_matrix operator * (const lli& scalar) const {
        square_matrix res;
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                res.a[i][j] = a[i][j] * scalar;
            }
        }
        return res;
    }
};

const square_matrix zero = {{{0, 0}, {0, 0}}};
const square_matrix identity = {{{1, 0}, {0, 1}}};

istream& operator >> (istream& in, square_matrix& a) {
    for (int i = 0; i < a.sz; ++i) {
        for (int j = 0; j < a.sz; ++j) {
            in >> a.a[i][j];
        }
    }
    return in;
}

ostream& operator << (ostream& out, const square_matrix& a) {
    for (int i = 0; i < a.sz; ++i) {
        for (int j = 0; j < a.sz; ++j) {
            cout << a.a[i][j] << "\t";
        }
        cout << "\n";
    }
    return out;
}

square_matrix product(const square_matrix& a, square_matrix& b) {
    int n = a.sz;
    square_matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                res.a[i][j] += a.a[i][k] * b.a[k][j];
            }
        }
    }
    return res;
}

int main() {
    square_matrix M, N;
    cout << "Input matrix 2x2 M:\n";
    cin >> M;
    cout << "Input matrix 2x2 N:\n";
    cin >> N;
    cout << "\nM x N =\n" << product(M, N) << "\n";
    cout << "Input non-negative integer n: "; int n; cin >> n;
    square_matrix A = identity, B = zero;
    square_matrix A1 = {{{1, 3}, {2, -1}}};
    square_matrix B1 = {{{2, 1}, {1, 4}}};
    for (int i = 1; i <= n; ++i) {
        square_matrix tmp = product(A, A1) + product(B, B1) * 7;
        B = product(A * (-1), B1) + product(B * (-1), A1);
        A = tmp;
    }
    cout << "\nA" << n <<  " = \n" << A << "\nB" << n << " = \n" << B << "\n";
}
