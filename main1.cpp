//Proba commita
#include "CPolynomLL.h"

void main()
{
	CPolynomLL* list = new CPolynomLL();
	list->insert(3.3, 7);
	list->insert(2.4, 4);
	list->insert(2.1, 2);
	list->insert(4.1, 5);
	list->display();
	CPolynomLL* list2 = new CPolynomLL();
	list2->insert(3.3, 7);
	list2->insert(2.4, 4);
	list2->insert(2.1, 2);
	list2->insert(4.1, 5);
	list2->display();
	CPolynomLL* list3 = new CPolynomLL();
	CPolynomLL* list5 = new CPolynomLL();
	list5 = list3->Add(list, list2);
	list5->display();
	CPolynomLL* list6 = new CPolynomLL();
	CPolynomLL* list4 = new CPolynomLL();
	list6 = list4->Mul(list, list2);
	list6->display();
	delete list;
	delete list2;
	delete list3;
	delete list4;
}