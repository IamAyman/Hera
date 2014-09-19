#include <iostream>

#include "core/ExecuteUnit.h"
using namespace std;

int main(int argc, char const *argv[])
{
	string test;
	ExecuteUnit ExecuteUnitInstance;
	cout << "type 'EXIT' to end the conversation" << endl;

	while(true)
	{
		cout << "[ready]:[type now] -> ";
		getline(cin,test);
		if(test == "EXIT" || test =="exit")
		{
			cout << "Goodby dear :-)" << endl;
			break;
		}
		ExecuteUnitInstance(test);
		ExecuteUnitInstance.execute();
		cout << "[ANSWER]           -> " << ExecuteUnitInstance.getFinalRespond() << endl;
	}


	return 0;
}