#include <iostream>

using namespace std;

class Node {
  friend ostream &operator<<(ostream &out, const Node &n) {
    return out << n.data << "->";
  }

public:
  int data;
  Node *next;
  explicit Node(int data = 0, Node *next = nullptr) : data{data}, next{next} {}
};

class List {
  friend ostream &operator<<(ostream &out, const List &lst) {
    out << "[";
    Node* last = lst.headPtr->next;
    while (last != nullptr) {
      out << *last;
      last = last->next;
    }
    return out << "]";
  }

public:
  List() : headPtr{new Node()} {};
  List &addToEnd(int num) {
    Node *last = headPtr;
    while (last->next != nullptr)
      last = last->next;
    last->next = new Node(num);
    return *this;
  }
  bool isSorted() const { return true; }

private:
  Node *headPtr = nullptr;
};


int main() {
  List lst;
  lst.addToEnd(3).addToEnd(5).addToEnd(7).addToEnd(9);
  cout << lst << endl;
}