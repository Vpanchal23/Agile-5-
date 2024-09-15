#ifndef NODETYPE_H
#define NODETYPE_H

#include <iostream>
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"
using namespace std;

struct nodeType
{
	bankAccountType *data;
	nodeType *previous;
	nodeType *next;
};

void InitializeList(nodeType **head, nodeType **tail);

bool EmptyList(nodeType *head);

void PrintList(nodeType *head);

int ListLength(nodeType *head);

void DeleteList(nodeType *head, nodeType *tail);

// RetrieveData function (for first and last node) is unnecessary for now

nodeType * SearchListForItem(nodeType *head, string name,
															int	 accountNumber);

void InsertItemInList(nodeType **head, nodeType **tail, string name,
																		  int		accountNumber,
																		  double balance,
																		  short  acctType,
																		  double intRate = 0,
																		  int maturityMon = 0);

void DeleteNode(nodeType *head, nodeType *tail, nodeType *nodeToDelete);

void CopyEntireList(nodeType *head, nodeType *tail, nodeType **newHead, nodeType **newTail);

nodeType * GetNodeByIndex(nodeType *head, int index);

#endif
