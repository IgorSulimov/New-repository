#include "Circular_list.hpp"
#include <algorithm>
#include <iomanip>
void CircularList::Game(int count_names, int drop, vector<string> Names)
{
    CircularList list;
    list = Creat_list1(Names,count_names);
    Node* current = list.head;

    Node* prev = new Node("");
    prev->next = current;

    vector<string> delete_names;

    int count = count_names;
    int j = 1;

    while (count != 1)
    {
        if (j == drop)
        {
            j = 1;
            current = current->next;
            delete_names.push_back(list.remove(prev->next->data));
            count--;
        }
        else
        {
            j++;
            prev = prev->next;
            current = current->next;
        }
    }
    cout << "Победитель:" << list.head->data << endl;
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
    int end_vec = count_names - 1;
    while (count != 1)
    {
        if (go < end_vec)
        {
            if (j == drop)
            {
                j = 1;
                delete_names.push_back(Names[go]);
                Names.erase(Names.begin() + go);
                count--;
                end_vec--;
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
                end_vec--;
            }
            else
            {
                j++;
            }
            go = 0;
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
void Print_Bell_2(vector<int> array, int size_array)
{
    if (size_array == 0)
    {
        return;
    }
    int l = size_array + 5;
    int m = 1;
    int middle;
    int r = size_array + 5;
    int i = 0;
    int j = 0;
    if (size_array % 2 == 0)
    {
        i = size_array / 2 - 1;
        j = size_array / 2;
        cout << right << setw(l) << array[i];
        i--;
        cout << " ";
        cout << right << setw(m) << array[j];
        j++;
        cout << endl;
        m += 2;
        r++;
        l -= 2;
    }
    if (size_array % 2 != 0)
    {
        middle = size_array / 2;
        i = middle - 1;
        j = middle + 1;
        cout << right << setw(size_array + 5) << array[middle];
        cout << endl;
        r++;
        l -= 2;
    }
    while (i >= 0 && j <= size_array-1)
    {
        cout << right << setw(l) << array[i];
        i--;
        for (int space = 0; space != m; space++)
            cout << " ";
        cout << right << setw(r - l) << array[j];
        j++;
        cout << endl;
        m++;
        r++;
        l -= 2;
    }
}
vector<int> Sort_Bell(vector<int>array, int size_array)
{
    int i;
    int j;
    int mid;
    int fl;
    int fl2;
    if (size_array % 2 == 0)
    {
        i = size_array / 2 - 1;
        j = size_array / 2;
        fl = 0;
    }
    else
    {
        mid = size_array / 2;
        i = mid - 1;
        j = mid + 1;
        fl = 2;
    }
    int max = 0;
    int p = 0;
    int index;
    while (i != 0 || j != size_array-1 )
    {
        if (fl == 0) //i
        {
            index = i;
            fl2 = 0;
                
        }
        if (fl == 1)//j
        {
            index = j;
            fl2 = 1;
        }
        if (fl == 2)//middle
        {
            index = mid;
            fl2 = 2;
        }
        while (p < size_array)
        {
            if (p == i)
            {
                if (array[p] > max)
                {
                    max = array[p];
                    index = p;
                    p+= j-i;
                }
                else
                {
                    p += j - i;
                }
            }
            else if (array[p] > max)
            {
                max = array[p];
                index = p;
                p++;
            }
            else
            {
                p++;
            }
        }
        if (fl2 == 0)
        {
            int temp = array[i];
            array[i] = max;
            array[index] = temp;
            fl = 1;
            p = 0;
            max = 0;
            i--;
        }
        if (fl2 == 1)
        {
            int temp = array[j];
            array[j] = max;
            array[index] = temp;
            fl = 0;
            p = 0;
            max = 0;
            j++;
        }
        if (fl2 == 2)
        {
            int temp = array[mid];
            array[mid] = max;
            array[index] = temp;
            fl = 0;
            p = 0;
            max = 0;
        }
    }
    return array;
}