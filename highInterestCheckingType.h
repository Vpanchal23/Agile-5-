#ifndef HIGHINTERESTCHECKINGTYPE_H
#define HIGHINTERESTCHECKINGTYPE_H

#include <string>
#include "noServiceChargeCheckingType.h"
using namespace std;

class highInterestCheckingType: public noServiceChargeCheckingType
{
	public:
		highInterestCheckingType(string n, int acctNumber, double bal);
		highInterestCheckingType(string n, int acctNumber, double bal, double minBal, double intRate);

		double getInterestRate();
		void setInterestRate(double intRate);
		void postInterest();
		virtual void createMonthlyStatement();
		virtual void print();

	private:
		static const double INTEREST_RATE; // = 0.05;
		static const double MIN_BALANCE; // = 5000.00;
};

#endif
