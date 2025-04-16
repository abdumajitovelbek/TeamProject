//SupportList.cpp

#ifndef SUPPORTLIST_H
#define SUPPORTLIST_H

#include <vector>
using namespace std;

template <typename T>
class SupportList {
private:
    vector<T> supporters;

public:
    SupportList() {}

    void add(T user) {
        supporters.push_back(user);
    }

    bool contains(T user) {
        for (const auto &supporter : supporters) {
            if (supporter == user) {
                return true;
            }
        }
        return false;
    }

    int size() {
        return supporters.size();
    }
};

#endif
