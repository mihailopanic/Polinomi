#pragma once
#include <iostream>
using namespace std;

class Node {
	Node* next;
	double coef;
	int exp;

public:
	Node(double coef, int exp, Node* next = nullptr) {
		this->next = next;
		this->coef = coef;
		this->exp = exp;
	}

	Node* getNext() const {
		return next;
	}

	double getCoef() const {
		return coef;
	}

	int getExp() const {
		return exp;
	}

	void setCoef(int coef) { this->coef = coef; }
	void setExp(int exp) { this->exp = exp; }
	void setNext(Node* next) { this->next = next; }
};