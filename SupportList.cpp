//SupportList.cpp
#include "SupportList.h"

template <typename T>
SupportList<T>::SupportList() {}

template <typename T>
void SupportList<T>::add(T user) {
    supporters.push_back(user);
}

template <typename T>
bool SupportList<T>::contains(T user) {
    for (const auto &supporter : supporters) {
        if (supporter == user) {
            return true;
        }
    }
    return false;
}

template <typename T>
int SupportList<T>::size() {
    return supporters.size();
}
