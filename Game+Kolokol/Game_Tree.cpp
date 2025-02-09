#include "Circular_list.hpp"
#include <algorithm>
#include <iomanip>
void CircularList::Game(int count_names, int drop, vector<string> Names)
{
    CircularList list;
    for (int i = 0; i < count_names; i++) {
        list.add(Names[i]);
    }
    Node* current = list.head;
    Node* prev = new Node("");
    prev->next = current;
    vector<string> delete_names;
    int go = 0;
    int count = count_names;
    int j = 1;
    int tt = count_names - 1;
    while (count != 1)
    {
        if (go < tt)
        {
            if (j == drop)
            {
                j = 1;
                prev->next = current->next;
                if (current == list.head)
                {
                    Node* temp = list.head;
                    list.head = list.head->next;
                    delete_names.push_back(temp->data);
                    delete temp;
                    list.size--;
                    current = list.head;
                }
                else if (go == tt)
                {
                    Node* temp = current;
                    current = current->next;
                    prev->next = current;
                    delete_names.push_back(temp->data);
                    delete temp;
                    list.size--;
                }
                else
                {
                    Node* temp = current;
                    current = current->next;
                    prev->next = current;
                    delete_names.push_back(temp->data);
                    delete temp;
                    list.size--;
                }
                Names.erase(Names.begin() + go);
                count--;
                tt--;
            }
            else
            {
                j++;
                go++;
                prev = prev->next;
                current = current->next;
            }
        }
        else
        {
            if (j == drop)
            {
                j = 1;
                prev->next = current->next;
                if (current == list.head)
                {
                    Node* temp = list.head;
                    list.head = list.head->next;
                    delete_names.push_back(temp->data);
                    delete temp;
                    list.size--;
                    current = list.head;
                }
                else if (go == tt)
                {
                    Node* temp = current;
                    current = current->next;
                    prev->next = current;
                    delete_names.push_back(temp->data);
                    delete temp;
                    list.size--;
                }
                else
                {
                    Node* temp = current;
                    current = current->next;
                    prev->next = current;
                    delete_names.push_back(temp->data);
                    delete temp;
                    list.size--;
                }
                count--;
                tt--;
            }
            else
            {
                go = 0;
                j++;
                prev = prev->next;
                current = current->next;
            }
        }
    }
    cout << "Победитель:" << Names.back() << endl;
    cout << "Проигравшие:";
    for (int j = 0; j < delete_names.size(); j++)
    {
        cout << delete_names[j] << " ";
    }
    cout << endl;
}
void Game_2(int count_names, int drop, vector<string> Names)
{
    vector<string> delete_names;
    int go = 0;
    int count = count_names;
    int j = 1;
    int tt = count_names - 1;
    while (count != 1)
    {
        if (go < tt)
        {
            if (j == drop)
            {
                j = 1;
                delete_names.push_back(Names[go]);
                Names.erase(Names.begin() + go);
                count--;
                tt--;
            }
            else
            {
                j++;
                go++;
            }
        }
        else
        {
            if (j == drop)
            {
                j = 1;
                delete_names.push_back(Names[go]);
                Names.erase(Names.begin() + go);
                cout << endl;
                count--;
                tt--;
            }
            else
            {
                go = 0;
                j++;
            }
        }
    }
    cout << "Победитель:" << Names.back() << endl;
    cout << "Проигравшие:";
    for (int j = 0; j < delete_names.size(); j++)
    {
        cout << delete_names[j] << " ";
    }
    cout << endl;
}

void Tree(vector<int> array, int size_array)
{
    if (size_array == 0)
    {
        return;
    }
    sort(array.begin(), array.end());
    int l = size_array+5;
    int m = 1;
    int r = size_array+5;
    int i = size_array;
    while(i >0)
    {
        if (i == size_array && size_array % 2 == 0)
        {
            cout << right << setw(l) << array.back();
            array.pop_back();
            cout << " ";
            cout << right << setw(m) << array.back();
            array.pop_back();
            cout << endl;
            m+=2;
            r++;
            l-=2;
            i-=2;
        }
        if(i == size_array && size_array % 2 != 0)
        {
            cout << right << setw(size_array+5) << array.back();
            array.pop_back();
            cout << endl;
            r++;
            l-=2;
            i--;
        }
        if ((i - 2) >= 0)
        {
            cout << right << setw(l) << array.back();
            array.pop_back();
            for(int j = 0; j != m ;j++)
                cout << " ";
            cout << right << setw(r-l) << array.back();
            array.pop_back();
            cout << endl;
            m++;
            r++;
            l-=2;
            i-=2;
        }
        else
        {
            cout << right << setw(l) << array.back();
            array.pop_back();
            cout << endl;
            r++;
            l-=2;
            i--;
        }
    }
}