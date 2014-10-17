#ifndef RESPOND_GENERATOR_H
#define RESPOND_GENERATOR_H

#include "RandomRespondsCollection.h"

class RespondGenerator
{
private:
	std::string respond; //all of this crap just to generate this respond :-)

public:
	void resetRespond();
	void generate(const SyntaxMetadata &object);
	std::string getRespond();
};

void RespondGenerator::resetRespond(){ this->respond = ""; }

void RespondGenerator::generate(const SyntaxMetadata &object)
{
	this->resetRespond();

	if(object.getSyntaxErrors() == SyntaxMetadata::ERROR::EMPTY_SYNTAX)
	{
		this->respond = getRespondsForEmptySyntax();
		return;
	}

	if(object.getSyntaxErrors() == SyntaxMetadata::ERROR::UNKNOWN_SAYNTAX)
		this->respond = "sorry!! but i cant understand this.";

	if(object.getSaluationType() == SyntaxMetadata::SALUATION_TYPE::HELLO)
		this->respond = "Hi!";

	else if(object.getSaluationType() == SyntaxMetadata::SALUATION_TYPE::HI)
		this->respond = "Hello!";

}

std::string RespondGenerator::getRespond(){ return this->respond; }

#endif

