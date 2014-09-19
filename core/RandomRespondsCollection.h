#ifndef RANDOM_RESPONDS_COLLECTION
#define RANDOM_RESPONDS_COLLECTION
#include <ctime>
#include <cstdlib>
#include <vector>

	const std::string RespondsForEmptySyntax[] =  {"are you here?","hello! say something","say something?","where are you?"};

	 std::string getRespondsForEmptySyntax()
	{
		srand(time(NULL));
		return RespondsForEmptySyntax[rand()%4];
	}

#endif