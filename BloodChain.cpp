#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

struct Donor {
    string name, bloodGroup, phone;
};

vector<Donor> donors;
stack<Donor> st;
queue<string> rq;
unordered_map<string, vector<Donor>> mp;

void rebuildMap() {
    mp.clear();
    for (auto &d : donors) {
        mp[d.bloodGroup].push_back(d);
    }
}

void addDonor() {
    Donor d;
    cin >> d.name >> d.bloodGroup >> d.phone;

    donors.push_back(d);
    mp[d.bloodGroup].push_back(d);

    cout << "Added\n";
}

void viewDonors() {
    if (donors.empty()) {
        cout << "Empty\n";
        return;
    }

    for (auto &d : donors) {
        cout << d.name << " " << d.bloodGroup << " " << d.phone << "\n";
    }
}

void searchDonor() {
    string bg;
    cin >> bg;

    if (mp[bg].empty()) {
        cout << "Not found\n";
        return;
    }

    for (auto &d : mp[bg]) {
        cout << d.name << " " << d.phone << "\n";
    }
}

void removeDonor() {
    viewDonors();

    if (donors.empty()) {
        cout << "No donors\n";
        return;
    }

    int x;
    cin >> x;

    if (x < 1 || x > donors.size()) {
        cout << "Invalid\n";
        return;
    }

    Donor removed = donors[x - 1];
    st.push(removed);

    donors.erase(donors.begin() + x - 1);

    rebuildMap();

    cout << "Removed\n";
}

void undo() {
    if (st.empty()) {
        cout << "Nothing\n";
        return;
    }

    Donor d = st.top();
    st.pop();

    donors.push_back(d);
    mp[d.bloodGroup].push_back(d);

    cout << "Undo\n";
}

void addReq() {
    string x;
    cin >> x;

    rq.push(x);
    cout << "Req added\n";
}

void processReq() {
    if (rq.empty()) {
        cout << "No req\n";
        return;
    }

    cout << rq.front() << "\n";
    rq.pop();
}

int main() {
    int c;

    while (true) {
        cout << "\n1 Add 2 View 3 Search 4 Remove 5 Undo 6 Req 7 Process 8 Exit\n";
        cin >> c;

        if (c == 1) addDonor();
        else if (c == 2) viewDonors();
        else if (c == 3) searchDonor();
        else if (c == 4) removeDonor();
        else if (c == 5) undo();
        else if (c == 6) addReq();
        else if (c == 7) processReq();
        else break;
    }

    return 0;
}