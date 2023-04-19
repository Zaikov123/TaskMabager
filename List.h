#pragma once
#include <iostream>
#include <fstream>
#include <string>

struct Node
{
    std::string data;
    Node* next;
};

class List
{
private:
    Node* head;
public:
    List()
    {
        head = NULL;
    }

    void addNode(std::string d)
    {
        Node* nd = new Node;
        nd->data = d;
        nd->next = NULL;

        if (head == NULL)
            head = nd;

        else
        {
            Node* current = head;

            while (current->next != NULL)
                current = current->next;
            current->next = nd;
        }
    }

    void deleteNode(unsigned int el) {
        if (head == NULL)
            return;

        Node* current = head;
        if (el == 0) {
            head = current->next;
            delete current;
            return;
        }

        for (unsigned int i = 0; current != NULL && i < el - 1; i++)
            current = current->next;

        if (current == NULL || current->next == NULL)
            return;

        Node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
    }
    void printToTxt()
    {
        std::ofstream outfile("data.txt");
        Node* current = head;
        while (current != NULL)
        {
            outfile << current->data << std::endl;
            current = current->next;
        }
        outfile.close();
    }

    void printList()
    {
        Node* current = head;
        while (current != NULL)
        {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
};