#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string data) : data(data), next(nullptr) {}
};
void Tree(vector<int> array, int size_array);
class CircularList {
private:
    Node* head;
    int size;
public:
    CircularList() : head(nullptr),size(0) {}

    CircularList(const CircularList& other) {
        head = nullptr;
        size = 0;
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
            newNode->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        size++;
    }
    void remove(string data) 
    {
        if (!head) {
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->data == data) {
                if (temp == head) {
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                    delete temp;
                    size--;
                    return;
                }
                else {
                    prev->next = temp->next;
                    delete temp;
                    size--;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
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
        while(size)
        {
            Node* next = temp->next;
            delete temp;
            temp = next;
            size--;
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
    void delete_el(CircularList list, Node* current, vector<string> del_el);
    void Game(int count_names, int drop, vector<string> Names);
};

void Game_2(int count_names, int drop, vector<string> Names);