#include "Circular_list.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    CircularList list2;
    vector<string> Names = { "Masha","Dima","KAMAR","ROMA","KATYA","POP"};
    list2.Game(Names.size(), 2, Names);
    //Game_2(Names.size(),2,Names);
    //vector<int> a = { 1,2,3,4,5,6};
    //vector<int> b =Sort_Bell(a, a.size());
    //for (int i = 0; i < a.size(); i++)
    //{
    //    cout << b[i] << "|";
    //}
    //cout << endl;
    //Print_Bell_2(b, a.size());
    return 0;
}