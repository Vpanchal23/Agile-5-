#ifndef NOSERVICECHARGECHECKINGTYPE_H
#define NOSERVICECHARGECHECKINGTYPE_H

#include <string>
#include "checkingAccountType.h"

using namespace std;

class noServiceChargeCheckingType: public checkingAccountType
{
	public:
		noServiceChargeCheckingType(string n, int acctNumber, double bal);
		noServiceChargeCheckingType(string n, int acctNumber, double bal, double minBalance, double inRate);
		double getMinimumBalance();
		void setMinimumBalance(double minBalance);
		bool verifyMinimumBalance(double amount);
		void writeCheck(double amount);
		void withdraw(double amount);
		virtual void createMonthlyStatement();
		virtual void print();

	protected:
		double minimumBalance;
		double interestRate;

	private:
		static const double MIN_BALANCE; // = 100.00;
		static const double INTEREST_RATE; // = 0.02;
};

#endif