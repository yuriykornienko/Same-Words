#include<string>
#include "list.h"

list::Node::Node(std::string value) : count(1), value(value), next(nullptr) {}

bool list::_findSameWord(const std::string& value) 
{
    Node* current = head;

    while (current != nullptr) {
        if (current->value == value) {
            current->count++;
            return true;
        }
        current = current->next;
    }

    return false;
}

void list::sort() {

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    bool isSorted = false;

    while (!isSorted) {
        isSorted = true;
        Node* current = head;

        while (current->next != nullptr) {

            if (current->count < current->next->count ||
                (current->count == current->next->count &&
                    current->value > current->next->value)) {

                std::swap(current->count, current->next->count);
                std::swap(current->value, current->next->value);
                isSorted = false;
            }
            current = current->next;
        }
    }
}


list::list() : head(nullptr) {}

list::~list()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void list::pushBack(const std::string value)
{
    if (_findSameWord(value)) { return; }

    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* current = head;

        while (current->next != nullptr)
            current = current->next;

        current->next = newNode;
    }
}

list::Node* list::getHead() { return head; }
