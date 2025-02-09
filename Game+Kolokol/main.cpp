#include <iostream>
#include <vector>
using namespace std;
#include "Circular_list.hpp"
int main() {
    setlocale(LC_ALL, "Russian");
    CircularList list;
    vector<string> Names = { "Masha","Dima","KAMAR","ROMA","KATYA","POP"};
    list.Game(Names.size(), 2, Names);
    //Game_2(Names.size(),2,Names);
    //vector<int> a = { 10,3,15,100,2,4,10,11,2 };
    //Tree(a, a.size());
    return 0;
}