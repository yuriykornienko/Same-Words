#pragma once
#include"logger.h"

class list {
public:
    struct Node
    {
        std::string value;
        int count;
        Node* next;
        Node(std::string value);
    };

private:
    bool _findSameWord(const std::string& value);
    Node* head;
public:
    list();
    ~list();
    void pushBack(const std::string value);
    void sort();
    Node* getHead();
};