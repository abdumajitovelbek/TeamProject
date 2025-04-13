//SupportList.h

#ifndef SUPPORTLIST_H
#define SUPPORTLIST_H

#include <vector>
using namespace std;

template <typename T>
class SupportList {
private:
    vector<T> supporters;

public:
    SupportList();
    void add(T user);
    bool contains(T user);
    int size();
};

#endif
