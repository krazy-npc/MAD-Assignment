#include <iostream>
#include <vector>
using namespace std;
typedef long long lli;
const string a = "abc";

bool valid(string s) {
    for (const char& c : s) {
        if (c - 'a' > 2 || c - 'a' < 0) {
            return false;
        }
    }
    return true;
}

string next(string s) {
    vector<int> idx; idx.push_back(-1);
    for (int i = 0; i < s.length(); ++i) {
        idx.push_back(s[i] - 'a');
    }
    idx[s.length()] += 1;
    int r = idx.back(), i = s.length();
    while (r % 3 == 0) {
        idx[i--] %= 3;
        idx[i] += 1;
        r = idx[i];
    }
    string res = "";
    for (const int& i : idx) {
        if (i != -1) {
            res += a[i];
        }
    }
    return res;
}

string previous(string s) {
    if (s == "a") {
        return "Null";
    }
    vector<int> idx;
    for (int i = 0; i < s.length(); ++i) {
        idx.push_back(s[i] - 'a');
    }
    idx[s.length() - 1] -= 1;
    int r = idx.back(), i = s.length() - 1;
    while (i && r == -1) {
        idx[--i] -= 1;
        r = idx[i];
    }
    string res = "";
    if (idx[0] == -1) {
        for (int i = 1; i < idx.size(); ++i) {
            res += a[(idx[i] + 3) % 3];
        }
    } else {
        for (const int& i : idx) {
            res += a[(idx[i] + 3) % 3];
        }
    }
    return res;
}

lli count1(string s) {
    lli res = 0, p3 = 1;
    for (const char& c : s) {
        res *= 3; p3 *= 3;
        res += c - 'a';
    }
    return p3 - res - 1;
}

int main() {
    cout << "Input string s containing only a, b and c: ";
    string s; cin >> s;
    if (!valid(s)) {
        cout << "Invalid input\n";
        return 1;
    }
    cout << "Next(" << s << ") = " << next(s) << "\n";
    cout << "Previous(" << s << ") = " << previous(s) << "\n";
    lli cnt1 = count1(s);
    if (cnt1 < 2) {
        cout << "There is " << cnt1 << " string which has the same length as " << s << " and stands behind " << s << "\n";    
    } else {
        cout << "There are " << cnt1 << " strings which have the same length as " << s << " and stand behind " << s << "\n";
    }
    cout << "Input length n: "; int n; cin >> n;
    if (n < 0) {
        cout << "Invalid length\n";
    }
}