run-test: main.cpp nodeType.o
	g++ -std=c++20 -Wall -Werror -o run-test main.cpp nodeType.o bankAccountType.o certificateOfDepositType.o savingsAccountType.o checkingAccountType.o highInterestSavingsType.o serviceChargeCheckingType.o noServiceChargeCheckingType.o highInterestCheckingType.o

nodeType.o: bankAccountType.o certificateOfDepositType.o savingsAccountType.o checkingAccountType.o highInterestSavingsType.o serviceChargeCheckingType.o noServiceChargeCheckingType.o highInterestCheckingType.o
	g++ -std=c++20 -Wall -Werror -c nodeType.cpp bankAccountType.o certificateOfDepositType.o savingsAccountType.o checkingAccountType.o highInterestSavingsType.o serviceChargeCheckingType.o noServiceChargeCheckingType.o highInterestCheckingType.o

bankAccountType.o: bankAccountType.cpp
	g++ -std=c++20 -Wall -Werror -c bankAccountType.cpp

certificateOfDepositType.o: certificateOfDepositType.cpp bankAccountType.o
	g++ -std=c++20 -Wall -Werror -c certificateOfDepositType.cpp bankAccountType.o

savingsAccountType.o: savingsAccountType.cpp bankAccountType.o
	g++ -std=c++20 -Wall -Werror -c savingsAccountType.cpp bankAccountType.o

checkingAccountType.o: checkingAccountType.cpp bankAccountType.o
	g++ -std=c++20 -Wall -Werror -c checkingAccountType.cpp bankAccountType.o

highInterestSavingsType.o: highInterestSavingsType.cpp savingsAccountType.o
	g++ -std=c++20 -Wall -Werror -c highInterestSavingsType.cpp savingsAccountType.o

noServiceChargeCheckingType.o: noServiceChargeCheckingType.cpp checkingAccountType.o
	g++ -std=c++20 -Wall -Werror -c noServiceChargeCheckingType.cpp checkingAccountType.o

serviceChargeCheckingType.o: serviceChargeCheckingType.cpp checkingAccountType.o
	g++ -std=c++20 -Wall -Werror -c serviceChargeCheckingType.cpp checkingAccountType.o

highInterestCheckingType.o: highInterestCheckingType.cpp noServiceChargeCheckingType.o
	g++ -std=c++20 -Wall -Werror -c highInterestCheckingType.cpp noServiceChargeCheckingType.o

clean:
	-rm *.o run-test
