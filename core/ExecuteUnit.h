#ifndef EXECUTE_UNIT_H
#define EXECUTE_UNIT_H
#include "SyntaxParser.h"
#include "SyntaxMetadata.h"
#include "RespondGenerator.h"
class ExecuteUnit
{
private:
	std::string syntax;
	std::string respond;
	SyntaxParser* SyntaxeParserInstace;
	SyntaxMetadata* SyntaxMetadataInstance;
	RespondGenerator* RespondGeneratorInstance;
public:
	ExecuteUnit();
	~ExecuteUnit();
	void execute();
	void operator()(const std::string& syntax);
	std::string getFinalRespond();
};

ExecuteUnit::ExecuteUnit()
{
	SyntaxeParserInstace = new SyntaxParser;
	SyntaxMetadataInstance = new SyntaxMetadata;
	RespondGeneratorInstance = new RespondGenerator;
	syntax = "";
	respond = "";

}

ExecuteUnit::~ExecuteUnit()
{
	delete SyntaxeParserInstace;
	delete SyntaxMetadataInstance;
	delete RespondGeneratorInstance;
}

void ExecuteUnit::operator()(const std::string& syntax)
{
	this->syntax = syntax;
}

void ExecuteUnit::execute()
{
	SyntaxeParserInstace->typeHandler(syntax,*SyntaxMetadataInstance);
	RespondGeneratorInstance->generate(*SyntaxMetadataInstance);
	this->respond = RespondGeneratorInstance->getRespond();
}

std::string ExecuteUnit::getFinalRespond()
{
	return this->respond;
}
#endif