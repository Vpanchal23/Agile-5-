#include "nodeType.h"

void createAnAccount(nodeType **head, nodeType **tail)
{

	short userChoice;
	string name;
	int acctNumber;
	double balance;
	double intRate;
	bool invalid;
	double minBal;
	double sevChargAmount;
	double sevChargChecks;
	int matuMonth;

	do
	{
		cout << "\033[H\033[2J" << endl;

		cout << "\t ************************************************************************ \n"
		     << "\t *                            OPEN AN ACCOUNT                           * \n"
		     << "\t ************************************************************************ \n"
		     << "\t *\n"
		     << "\t *\n"
		     << "\t *  Would you like to open a savings or checking account?\n"
			  << "\t *\n"
	        << "\t *  1. Savings.\n"
	        << "\t *  2. Checking.\n"
			  << "\t *  3. Certificate of deposit.\n"
	        << "\t *  4. EXIT.\n"
			  << "\t *\n"
			  << "\t ************************************************************************ \n"
	        << "\t  <Choice>: ";

		if (!(cin >> userChoice))
		{
			cin.clear();
			choice = -1;
		}
		cin.ignore(1000, '\n');

		switch (userChoice)
		{
			case 1:
					do
					{
						cout << "\033[H\033[2J" << endl;

						cout << "\t ************************************************************************ \n"
						     << "\t *                       OPEN A SAVINGS ACCOUNT                         * \n"
						     << "\t ************************************************************************ \n"
						     << "\t *\n"
						     << "\t *\n"
						     << "\t *  What savings account would you like to open?\n"
							  << "\t *\n"
					        << "\t *  1. Savings account.\n"
					        << "\t *  2. High interest savings account.\n"
					        << "\t *  3. EXIT.\n"
							  << "\t *\n"
							  << "\t ************************************************************************ \n"
					        << "\t  <Choice>: ";

						if (!(cin >> userChoice))
						{
							cin.clear();
							choice = -1;
						}
						cin.ignore(1000, '\n');

						switch (userChoice)
						{
							case 1:

									do
									{
										invalid = true;
										cout << "\033[H\033[2J" << endl;

										cout << "\t ************************************************************************ \n"
										     << "\t *                           SAVINGS ACCOUNT                            * \n"
										     << "\t ************************************************************************ \n"
										     << "\t *\n"
											  << "\t *\n"
									        << "\t *  1. Enter Owner's Name       --> " << name       << endl
									        << "\t *  2. Enter Account Number     --> " << acctNumber << endl
									        << "\t *  3. Enter Account Balance    --> " << balance    << endl
											  << "\t *  4. Enter Interest Rate      --> " << intRate    << endl
											  << "\t *  5. Create Account.\n"
											  << "\t *  6. Exit.\n"
											  << "\t *\n"
											  << "\t ************************************************************************ \n"
									        << "\t  <Choice>: ";

										if (!(cin >> userChoice))
										{
											cin.clear();
											choice = -1;
										}
										cin.ignore(1000, '\n');

										switch (userChoice)
										{
											case 1:
													cout << "\n\t Enter Owner's Name: ";
													getline(cin, name);
													break;
											case 2:
													do
													{
														cout << "\n\t Account Number: ";
														if (!(cin  >> acctNumber))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (acctNumber < 0)
														{
															cout << "\n\t Invalid input - Please try again\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 3:
													do
													{
														cout << "\n\t Account Balance: ";
														if (!(cin  >> balance))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (balance < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 4:
													do
													{
														cout << "\n\t Account Interest Rate: ";
														if (!(cin  >> intRate))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (intRate < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 5:
													InsertNodeInList(head, tail, new savingsAccountType(name,
																														 acctNumber,
																														 balance,
																														 intRate));
													break;
											case 6:
													break;
											default:
													cout << "\n\t Please enter a number between 1 - 6\n"
														  << "\n\t Press enter to try again";
													cin.ignore(1000, '\n');
										}

									}white (userChoice != 5 &&
											  userChoice != 6);
									break;
							case 2:
									do
									{
										invalid = true;
										cout << "\033[H\033[2J" << endl;

										cout << "\t ************************************************************************ \n"
										     << "\t *                    HIGH INTEREST SAVINGS ACCOUNT                     * \n"
										     << "\t ************************************************************************ \n"
										     << "\t *\n"
											  << "\t *\n"
									        << "\t *  1. Enter Owner's Name       --> " << name       << endl
									        << "\t *  2. Enter Account Number     --> " << acctNumber << endl
									        << "\t *  3. Enter Account Balance    --> " << balance    << endl
											  << "\t *  4. Enter Interest Rate      --> " << intRate    << endl
											  << "\t *  5. Enter Minimum Balance    --> " << minBal     << endl
											  << "\t *  6. Create Account.\n"
											  << "\t *  7. Exit.\n"
											  << "\t *\n"
											  << "\t ************************************************************************ \n"
									        << "\t  <Choice>: ";

										if (!(cin >> userChoice))
										{
											cin.clear();
											choice = -1;
										}
										cin.ignore(1000, '\n');

										switch (userChoice)
										{
											case 1:
													cout << "\n\t Enter Owner's Name: ";
													getline(cin, name);
													break;
											case 2:
													do
													{
														cout << "\n\t Account Number: ";
														if (!(cin  >> acctNumber))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (acctNumber < 0)
														{
															cout << "\n\t Invalid input - Please try again\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 3:
													do
													{
														cout << "\n\t Account Balance: ";
														if (!(cin  >> balance))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (balance < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 4:
													do
													{
														cout << "\n\t Account Interest Rate: ";
														if (!(cin  >> intRate))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (intRate < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 5:
													do
													{
														cout << "\n\t Account Minimum Balance: ";
														if (!(cin  >> minBal))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (minBal < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 6:
													InsertNodeInList(head, tail, new highInterestSavingsType(name,
																														 		acctNumber,
																														 		balance,
																														 		intRate,
																																minBal));
													break;
											case 7:
													break;
											default:
													cout << "\n\t Please enter a number between 1 - 7\n"
														  << "\n\t Press enter to try again";
													cin.ignore(1000, '\n');
										}

									}white (userChoice != 6 &&
											  userChoice != 7);
									break;
						}
					break;
			case 2:
					do
					{
						cout << "\033[H\033[2J" << endl;

						cout << "\t ************************************************************************ \n"
						     << "\t *                       OPEN A CHECKING ACCOUNT                        * \n"
						     << "\t ************************************************************************ \n"
						     << "\t *\n"
						     << "\t *\n"
						     << "\t *  What checking account would you like to open?\n"
							  << "\t *\n"
					        << "\t *  1. Service charge checking account.\n"
					        << "\t *  2. No service charge checking account.\n"
							  << "\t *  3. High interest checking account.\n"
					        << "\t *  4. EXIT.\n"
							  << "\t *\n"
							  << "\t ************************************************************************ \n"
					        << "\t  <Choice>: ";

						if (!(cin >> userChoice))
						{
							cin.clear();
							choice = -1;
						}
						cin.ignore(1000, '\n');

						switch (userChoice)
						{
							case 1:
									do
									{
										invalid = true;
										cout << "\033[H\033[2J" << endl;

										cout << "\t ************************************************************************ \n"
										     << "\t *                  SERVICE CHARGE CHECKING ACCOUNT                     * \n"
										     << "\t ************************************************************************ \n"
										     << "\t *\n"
											  << "\t *\n"
									        << "\t *  1. Enter Owner's Name           --> " << name           << endl
									        << "\t *  2. Enter Account Number         --> " << acctNumber     << endl
									        << "\t *  3. Enter Account Balance        --> " << balance        << endl
											  << "\t *  4. Enter Service Charge Amount  --> " << sevChargAmount << endl
											  << "\t *  5. Enter Service Charge Checks  --> " << sevChargChecks << endl
											  << "\t *  6. Create Account.\n"
											  << "\t *  7. Exit.\n"
											  << "\t *\n"
											  << "\t ************************************************************************ \n"
									        << "\t  <Choice>: ";

										if (!(cin >> userChoice))
										{
											cin.clear();
											choice = -1;
										}
										cin.ignore(1000, '\n');

										switch (userChoice)
										{
											case 1:
													cout << "\n\t Enter Owner's Name: ";
													getline(cin, name);
													break;
											case 2:
													do
													{
														cout << "\n\t Account Number: ";
														if (!(cin  >> acctNumber))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (acctNumber < 0)
														{
															cout << "\n\t Invalid input - Please try again\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 3:
													do
													{
														cout << "\n\t Account Balance: ";
														if (!(cin  >> balance))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (balance < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 4:
													do
													{
														cout << "\n\t Service Charge Amount: ";
														if (!(cin  >> sevChargAmount))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (sevChargAmount < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 5:
													do
													{
														cout << "\n\t Service Charge Checks: ";
														if (!(cin  >> sevChargChecks))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (sevChargChecks < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 6:
													InsertNodeInList(head, tail, new serviceChargeCheckingType(name,
																														 		  acctNumber,
																														 		  balance,
																														 		  sevChargAmount,
																																  sevChargChecks));
													break;
											case 7:
													break;
											default:
													cout << "\n\t Please enter a number between 1 - 7\n"
														  << "\n\t Press enter to try again";
													cin.ignore(1000, '\n');
										}

									}white (userChoice != 6 &&
											  userChoice != 7);
									break;
							case 2:
									do
									{
										invalid = true;
										cout << "\033[H\033[2J" << endl;

										cout << "\t ************************************************************************ \n"
										     << "\t *                 NO SERVICE CHARGE CHECKING ACCOUNT                   * \n"
										     << "\t ************************************************************************ \n"
										     << "\t *\n"
											  << "\t *\n"
									        << "\t *  1. Enter Owner's Name       --> " << name       << endl
									        << "\t *  2. Enter Account Number     --> " << acctNumber << endl
									        << "\t *  3. Enter Account Balance    --> " << balance    << endl
											  << "\t *  4. Enter Interest Rate      --> " << intRate    << endl
											  << "\t *  5. Enter Minimum Balance    --> " << minBal     << endl
											  << "\t *  6. Create Account.\n"
											  << "\t *  7. Exit.\n"
											  << "\t *\n"
											  << "\t ************************************************************************ \n"
									        << "\t  <Choice>: ";

										if (!(cin >> userChoice))
										{
											cin.clear();
											choice = -1;
										}
										cin.ignore(1000, '\n');

										switch (userChoice)
										{
											case 1:
													cout << "\n\t Enter Owner's Name: ";
													getline(cin, name);
													break;
											case 2:
													do
													{
														cout << "\n\t Account Number: ";
														if (!(cin  >> acctNumber))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (acctNumber < 0)
														{
															cout << "\n\t Invalid input - Please try again\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 3:
													do
													{
														cout << "\n\t Account Balance: ";
														if (!(cin  >> balance))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (balance < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 4:
													do
													{
														cout << "\n\t Account Interest Rate: ";
														if (!(cin  >> intRate))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (intRate < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 5:
													do
													{
														cout << "\n\t Account Minimum Balance: ";
														if (!(cin  >> minBal))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (minBal < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 6:
													InsertNodeInList(head, tail, new noServiceChargeCheckingType(name,
																														 			 acctNumber,
																														 			 balance,
																																 	 minBal,
																																	 intRate));
													break;
											case 7:
													break;
											default:
													cout << "\n\t Please enter a number between 1 - 7\n"
														  << "\n\t Press enter to try again";
													cin.ignore(1000, '\n');
										}

									}white (userChoice != 6 &&
											  userChoice != 7);
									break;
							case 3:
									do
									{
										invalid = true;
										cout << "\033[H\033[2J" << endl;

										cout << "\t ************************************************************************ \n"
										     << "\t *                   HIGH INTEREST CHECKING ACCOUNT                     * \n"
										     << "\t ************************************************************************ \n"
										     << "\t *\n"
											  << "\t *\n"
									        << "\t *  1. Enter Owner's Name       --> " << name       << endl
									        << "\t *  2. Enter Account Number     --> " << acctNumber << endl
									        << "\t *  3. Enter Account Balance    --> " << balance    << endl
											  << "\t *  4. Enter Interest Rate      --> " << intRate    << endl
											  << "\t *  5. Enter Minimum Balance    --> " << minBal     << endl
											  << "\t *  6. Create Account.\n"
											  << "\t *  7. Exit.\n"
											  << "\t *\n"
											  << "\t ************************************************************************ \n"
									        << "\t  <Choice>: ";

										if (!(cin >> userChoice))
										{
											cin.clear();
											choice = -1;
										}
										cin.ignore(1000, '\n');

										switch (userChoice)
										{
											case 1:
													cout << "\n\t Enter Owner's Name: ";
													getline(cin, name);
													break;
											case 2:
													do
													{
														cout << "\n\t Account Number: ";
														if (!(cin  >> acctNumber))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (acctNumber < 0)
														{
															cout << "\n\t Invalid input - Please try again\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 3:
													do
													{
														cout << "\n\t Account Balance: ";
														if (!(cin  >> balance))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (balance < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 4:
													do
													{
														cout << "\n\t Account Interest Rate: ";
														if (!(cin  >> intRate))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (intRate < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 5:
													do
													{
														cout << "\n\t Account Minimum Balance: ";
														if (!(cin  >> minBal))
														{
															cin.clear();
															cout << "\n\t Invalid input - Please enter a number\n";
														}
														else if (minBal < 0)
														{
															cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
														}
														else
														{
															invalid = false;
														}
														cin.ignore(1000, '\n');
													}while (invalid);
													break;
											case 6:
													InsertNodeInList(head, tail, new highInterestCheckingType(name,
																														 		 acctNumber,
																														 		 balance,
																																 minBal,
																																 intRate));
													break;
											case 7:
													break;
											default:
													cout << "\n\t Please enter a number between 1 - 7\n"
														  << "\n\t Press enter to try again";
													cin.ignore(1000, '\n');
										}

									}white (userChoice != 6 &&
											  userChoice != 7);
									break;
							case 4:
									break;
							default:
									cout << "\n\t Please enter a number between 1 - 4\n"
										  << "\n\t Press enter to try again";
									cin.ignore(1000, '\n');
						}
					}while (userChoice != 4)

					break;
			case 3:
					do
					{
						invalid = true;
						cout << "\033[H\033[2J" << endl;

						cout << "\t ************************************************************************ \n"
						     << "\t *                   CERTIFICATE OF DEPOSIT ACCOUNT                     * \n"
						     << "\t ************************************************************************ \n"
						     << "\t *\n"
							  << "\t *\n"
					        << "\t *  1. Enter Owner's Name       --> " << name       << endl
					        << "\t *  2. Enter Account Number     --> " << acctNumber << endl
					        << "\t *  3. Enter Account Balance    --> " << balance    << endl
							  << "\t *  4. Enter Interest Rate      --> " << intRate    << endl
							  << "\t *  5. Enter Maturity Month     --> " << matuMonth  << endl
							  << "\t *  6. Create Account.\n"
							  << "\t *  7. Exit.\n"
							  << "\t *\n"
							  << "\t ************************************************************************ \n"
					        << "\t  <Choice>: ";

						if (!(cin >> userChoice))
						{
							cin.clear();
							choice = -1;
						}
						cin.ignore(1000, '\n');

						switch (userChoice)
						{
							case 1:
									cout << "\n\t Enter Owner's Name: ";
									getline(cin, name);
									break;
							case 2:
									do
									{
										cout << "\n\t Account Number: ";
										if (!(cin  >> acctNumber))
										{
											cin.clear();
											cout << "\n\t Invalid input - Please enter a number\n";
										}
										else if (acctNumber < 0)
										{
											cout << "\n\t Invalid input - Please try again\n";
										}
										else
										{
											invalid = false;
										}
										cin.ignore(1000, '\n');
									}while (invalid);
									break;
							case 3:
									do
									{
										cout << "\n\t Account Balance: ";
										if (!(cin  >> balance))
										{
											cin.clear();
											cout << "\n\t Invalid input - Please enter a number\n";
										}
										else if (balance < 0)
										{
											cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
										}
										else
										{
											invalid = false;
										}
										cin.ignore(1000, '\n');
									}while (invalid);
									break;
							case 4:
									do
									{
										cout << "\n\t Account Interest Rate: ";
										if (!(cin  >> intRate))
										{
											cin.clear();
											cout << "\n\t Invalid input - Please enter a number\n";
										}
										else if (intRate < 0)
										{
											cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
										}
										else
										{
											invalid = false;
										}
										cin.ignore(1000, '\n');
									}while (invalid);
									break;
							case 5:
									do
									{
										cout << "\n\t Account Maturity Month(#): ";
										if (!(cin  >> matuMonth))
										{
											cin.clear();
											cout << "\n\t Invalid input - Please enter a number\n";
										}
										else if (matuMonth < 0)
										{
											cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
										}
										else
										{
											invalid = false;
										}
										cin.ignore(1000, '\n');
									}while (invalid);
									break;
							case 6:
									InsertNodeInList(head, tail, new certificateOfDepositType(name,
																										 		 acctNumber,
																										 		 balance,
																												 intRate,
																												 matuMonth));
									break;
							case 7:
									break;
							default:
									cout << "\n\t Please enter a number between 1 - 7\n"
										  << "\n\t Press enter to try again";
									cin.ignore(1000, '\n');
						}

					}white (userChoice != 6 &&
							  userChoice != 7);
					break;
			case 4:
					break;
			default:
					cout << endl
						  << "\t Please enter a number between 1 - 4\n\n"
						  << "\t Press ENTER to try again";
					cin.ignore(1000, '\n');
		}

	}while (userChoice != 4)

	return;
}
