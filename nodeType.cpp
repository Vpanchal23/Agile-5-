#include "nodeType.h"

void InitializeList(nodeType **head, nodeType **tail)
{
	(*head) = nullptr;
	(*tail) = nullptr;

	return;
}

bool EmptyList(nodeType *head)
{

	return (head == nullptr);
}

void PrintList(nodeType *head)
{
	nodeType *body;

	body = head;
	body->data->print();
	body = body->next;

	while (body != nullptr)
	{
		cout << ' ';
		body->data->print();
		body = body->next;
	}

	return;
}

int ListLength(nodeType *head)
{
	nodeType *body;
	int counter;

	counter = 0;
	body = head;

	while (body != nullptr)
	{
		counter++;
		body = body->next;
	}

	return counter;
}

void DeleteList(nodeType *head, nodeType *tail)
{
	nodeType *body;

	body = tail;

	while (body != nullptr)
	{
		tail = tail->previous;

		delete body->data;
		delete body;

		body = tail;
	}

	return;
}

nodeType * SearchListForItem(nodeType *head, string name = "*****",
															int 	 accountNumber = -1)
{
	nodeType *body;

	body = head;

	while (body->data->getName() != name && body->data->getAccountNumber() != accountNumber)
	{
		body = body->next;
	}

	return body;
}

void InsertItemInList(nodeType **head, nodeType **tail, string name,
																		  int		accountNumber,
																		  double	balance,
																		  short	acctType,
																		  double intRate,
																		  int    maturityMon)
{
	nodeType *newNode;

	newNode = new nodeType;

	switch(acctType)
	{
		case 1:
				newNode->data = new savingsAccountType(name,
											  						accountNumber,
											  						balance);
				break;
		case 2:
				newNode->data = new highInterestSavingsType(name,
											  							  accountNumber,
											  							  balance);
				break;
		case 3:
				newNode->data = new certificateOfDepositType(name,
											  								accountNumber,
											  								balance,
																			intRate,
																			maturityMon);
				break;
		case 4:
				newNode->data = new serviceChargeCheckingType(name,
											  						  		 accountNumber,
											  						  		 balance);
				break;
		case 5:
				newNode->data = new noServiceChargeCheckingType(name,
											  								   accountNumber,
											  									balance);
				break;
		case 6:
				newNode->data = new highInterestCheckingType(name,
											  								accountNumber,
											  								balance);
				break;
		default:
				break;


	}

	newNode->next = nullptr;
	newNode->previous = nullptr;

	if ((*head) != nullptr)
	{
		(*tail)->next = newNode;
		newNode->previous = (*tail);
		(*tail) = newNode;
	}
	else
	{
		(*head) = newNode;
		(*tail) = newNode;
	}

	return;
}

void DeleteNode(nodeType *head, nodeType *tail, nodeType *nodeToDelete)
{
	nodeType *pre;
	nodeType *post;

	pre = nodeToDelete->previous;
	post = nodeToDelete->next;

	if (pre != nullptr && post != nullptr)
	{
		pre->next = post;
		post->previous = pre;
	}
	else if (post == nullptr && pre != nullptr)
	{
		pre->next = nullptr;
		tail = pre;
	}
	else if (post != nullptr && pre == nullptr)
	{
		post->previous = nullptr;
		head = post;
	}
	delete nodeToDelete->data;

	delete nodeToDelete;

	return;
}

void CopyEntireList(nodeType *head, nodeType *tail, nodeType **cpHead, nodeType **cpTail)
{
	nodeType *body;

	body = head;

	while (body != nullptr)
	{
		InsertItemInList(cpHead, cpTail, body->data->getName(),
													body->data->getAccountNumber(),
													body->data->getBalance(),
													1); //change this

		body = body->next;
	}

	return;
}

nodeType * GetNodeByIndex(nodeType *head, int index)
{
	short iter;
	nodeType *body;

	body = head;
	iter = 0;

	while(iter != index)
	{
		body = body->next;
		iter++;
	}

	return body;
}

