#include <iostream>
#include <vector>
using namespace std;

class Node 
{
public:
    string data;
    Node* next;

    Node(string data) : data(data), next(nullptr) {}
};
class CircularList
{
private:
    Node* head;
    Node* tall;
public:
    CircularList() : head(nullptr),tall(nullptr) {}

    CircularList(const CircularList& other) {
        head = nullptr;
        tall = nullptr;
        Node* current = other.head;
        if (current) {
            do {
                add(current->data);
                current = current->next;
            } while (current != other.head);
        }
    }

    ~CircularList() {
        clear();
    }

    CircularList& operator=(const CircularList& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        Node* current = other.head;
        if (current) {
            do {
                add(current->data);
                current = current->next;
            } while (current != other.head);
        }
        return *this;
    }

    void add(string data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            tall = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            tall = newNode;
            newNode->next = head;
        }
    }
    string remove(string data) 
    {
        Node* current;
        current = head;
        Node* prev = new Node("");
        prev->next = current;
        string element;
        int fl = 0;
        while (fl == 0)
        {
            if (current->data == data && current == head)
            {
                prev->next = current->next;
                head = head->next;
                element = current->data;
                delete current;
                fl = 1;
            }
            else if (current->data == data && current == tall)
            {
                prev->next = current->next;
                tall = prev;
                element = current->data;
                delete current;
                fl = 1;
            }
            else if (current->data == data)
            {
                prev->next = current->next;
                element = current->data;
                delete current;
                fl = 1;
            }
            prev = prev->next;
            current = current->next;
        }
        return element;
    }

    bool find(string data) const {
        Node* temp = head;
        if (temp) {
            do {
                if (temp->data == data) return true;
                temp = temp->next;
            } while (temp != head);
        }
        return false;
    }

    void clear() {
        if (!head) {
            return;
        }
        Node* temp = head;
        while(temp != head)
        {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    string& operator[](int index) {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            if (temp->next == head) {
                cout << "Индекс вне границ" << endl;
                exit(1);
            }
            temp = temp->next;
        }
        return temp->data;
    }

    friend ostream& operator<<(ostream& os, const CircularList& list) {
        Node* temp = list.head;
        if (temp) {
            do {
                os << temp->data << " ";
                temp = temp->next;
            } while (temp != list.head);
        }
        return os;
    }

    friend istream& operator>>(istream& is, CircularList& list) {
        list.clear();
        string data;
        cout << "Введите элементы списка (окончание ввода нажатием Enter): ";

        while (true) {
            if (is.peek() == '\n') {
                break;
            }
            if (is >> data) {
                list.add(data);
            }
            else {
                break;
            }
        }

        is.clear();
        return is;
    }

    // конкатенация списков
    CircularList operator+(const CircularList& other) const {
        CircularList result(*this);
        Node* current = other.head;
        if (current) {
            do {
                result.add(current->data);
                current = current->next;
            } while (current != other.head);
        }
        return result;
    }
    // конкатенация списков
    CircularList& operator+=(const CircularList& other) {
        Node* current = other.head;
        if (current) {
            do {
                add(current->data);
                current = current->next;
            } while (current != other.head);
        }
        return *this;
    }
    void Game(int count_names, int drop, vector<string> Names);
    CircularList Creat_list1(vector<string> array, int size_array)
    {
        CircularList list_;
        for (int i = 0; i < size_array; i++)
        {
            list_.add(array[i]);
        }
        return list_;
    }
};
vector<int> Sort_Bell(vector<int>array, int size_array);
void Bell(vector<int> array, int size_array);
void Game_2(int count_names, int drop, vector<string> Names);
void Print_Bell_2(vector<int> array, int size_array);