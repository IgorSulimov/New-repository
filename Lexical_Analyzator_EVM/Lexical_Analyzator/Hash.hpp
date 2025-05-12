#pragma once 

#include <iostream> 
#include <iomanip> 
using namespace std;
struct TS_el
{
    int label;
    int index_el;
    int next;
};

class Hash
{
    int n_max;
    int n_os;
    int NTS;

    TS_el* t;

    int hashfunc(int key) { return (key % n_os) + 1; }

public:

    Hash(int n1 = 1000, int os = 100)
    {
        n_max = n1;
        n_os = os;
        NTS = os + 1;

        t = new TS_el[n_max];

        for (int i = 0; i < n_max; i++)
        {
            t[i].label = t[i].index_el = -1;
            t[i].next = 0;
        }
    }

    Hash(const Hash& other)
    {
        n_max = other.n_max;
        n_os = other.n_os;
        NTS = other.NTS;;
        t = new TS_el[n_max];

        for (int i = 0; i < n_max; i++)
        {
            t = other.t;
        }
    }

    Hash(Hash& other)
    {
        n_max = other.n_max;
        n_os = other.n_os;
        NTS = other.NTS;;
        t = new TS_el[n_max];

        for (int i = 0; i < n_max; i++)
        {
            t = other.t;
        }
    }

    ~Hash()
    {
        delete[] t;
    }
    int Get_NTS()
    {
        return NTS;
    }
    int Find(int key)
    {
        int i = hashfunc(key);

        while (t[i].label != key)
        {
            if (t[i].next != 0)
                i = t[i].next;
            else
                return 0;
        }
        return i;
    }

    int TLinf(int i)
    {
        if (i >= n_max)
            return -1;
        return t[i].index_el;
    }

    void el_del(int key)
    {


        int k = hashfunc(key);
        if (t[k].label == key && t[k].next == 0)
        {
            t[k].label = -1;
            t[k].index_el = -1;
            return;
        }


        if (t[k].label == key && t[k].next != 0)
        {
            int p = k;//
            int sv = t[k].next;
            while (t[t[p].next].next != 0)
            {
                p = t[p].next;
            }
            t[k] = t[t[p].next];
            t[k].next = sv;
            t[t[p].next].next = 0;
            t[t[p].next].index_el = -1;
            t[t[p].next].label = -1;
            if (t[0].next == 0)
                t[0].next = t[p].next;
            else
            {
                int cpy = t[0].next;
                t[0].next = t[p].next;
                t[t[p].next].next = cpy;
            }
            t[p].next = 0;

            return;
        }



        while (t[t[k].next].label != key)
            k = t[k].next;

        int cpy = t[k].next;
        t[k].next = t[cpy].next;
        t[cpy].label = -1;
        t[cpy].index_el = -1;
        if (t[0].next == 0)
        {
            t[0].next = cpy;
            t[cpy].next = 0;
        }
        else
        {
            int cpy1 = t[0].next;
            t[0].next = cpy;
            t[cpy].next = cpy1;
        }
        return;
    }

    int el_add(int key, int ind)
    {
        int k = hashfunc(key);
        if (t[k].label == -1)
        {
            t[k].label = key;
            t[k].index_el = ind;
            return k;
        }

        int p = k;
        while (t[p].next != 0)
            p = t[p].next;



        if (t[0].next == 0)
        {
            t[p].next = NTS;
            t[NTS].label = key;
            t[NTS].index_el = ind;
            NTS++;
            return NTS - 1;
        }

        if (t[0].next != 0)
        {
            t[p].next = t[0].next;
            int sv = t[0].next;


            t[0].next = t[sv].next;
            t[sv].label = key;
            t[sv].index_el = ind;
            t[sv].next = 0;
            return sv;
        }

    }

    void print()
    {
        cout <<'\n';
        for (int i = 1; i < n_max; i++)
        {
            if (t[i].label != -1)
                cout << setw(7) << i << "|"
                << setw(10) << t[i].label << "|"
                << setw(10) << t[i].index_el << "|"
                << setw(10) << t[i].next << "|" << endl;
        }
        cout << endl;
    }
};