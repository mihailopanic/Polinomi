#pragma once
#include "Node.h"

class CPolynomLL {
private:
    Node* head;

public:
    CPolynomLL() {
        head = nullptr;
    }

    ~CPolynomLL() {
        Node* curr = head;
        while (curr != nullptr) 
        {
            Node* temp = curr;
            curr = curr->getNext();
            delete temp;
        }
    }

    void insert(double coef, int exp) {
        if (head == nullptr || exp > head->getExp()) {
            head = new Node(coef, exp, head);
        }
        else 
        {
            Node* curr = head;
            while (curr->getNext() != nullptr && curr->getNext()->getExp() >= exp) 
            {
                curr = curr->getNext();
            }
            Node* temp = curr->getNext();
            curr->setNext(new Node(coef, exp, temp));
            curr->getNext()->setNext(temp);
        }
    }

    void display() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->getCoef() << "x^" << curr->getExp() << " ";
            curr = curr->getNext();
        }
        cout << endl;
    }

    CPolynomLL* Add(CPolynomLL* poly1, CPolynomLL* poly2) {
        CPolynomLL* result = new CPolynomLL();
        Node* curr1 = poly1->head;
        Node* curr2 = poly2->head;

        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->getExp() > curr2->getExp()) {
                result->insert(curr1->getCoef(), curr1->getExp());
                curr1 = curr1->getNext();
            }
            else if (curr1->getExp() < curr2->getExp()) {
                result->insert(curr2->getCoef(), curr2->getExp());
                curr2 = curr2->getNext();
            }
            else {
                result->insert(curr1->getCoef() + curr2->getCoef(), curr1->getExp());
                curr1 = curr1->getNext();
                curr2 = curr2->getNext();
            }
        }
        
        while (curr1 != nullptr) {
            result->insert(curr1->getCoef(), curr1->getExp());
            curr1 = curr1->getNext();
        }

        while (curr2 != nullptr) {
            result->insert(curr2->getCoef(), curr2->getExp());
            curr2 = curr2->getNext();
        }

        return result;
    }

    CPolynomLL* Mul(CPolynomLL* poly1, CPolynomLL* poly2) {
        CPolynomLL* result = new CPolynomLL();
        Node* curr1 = poly1->head;
        Node* curr2 = poly2->head;

        while (curr1 != nullptr) {
            curr2 = poly2->head;

            while (curr2 != nullptr) {
                double coef = curr1->getCoef() * curr2->getCoef();
                int exp = curr1->getExp() + curr2->getExp();
                result->insert(coef, exp);
                curr2 = curr2->getNext();
            }

            curr1 = curr1->getNext();
        }

        return result;
    }
};
    
