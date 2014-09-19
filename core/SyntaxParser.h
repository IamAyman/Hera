#ifndef SYNTAX_PARSER_H
#define SYNTAX_PARSER_H

#include <regex> //for regex_search()
#include "SyntaxMetadata.h"
#include "RespondGenerator.h"
#include "ConversationState.h"


class SyntaxParser
{
public:
	RespondGenerator RespondGeneratorInstance;
	void typeHandler(const std::string& syntax, SyntaxMetadata& object);

};


void SyntaxParser::typeHandler(const std::string& syntax, SyntaxMetadata& object)
{
	object.setSyntaxErrors(SyntaxMetadata::ERROR::NO_ERROR);

	if(syntax.length() == 0)
	{
		object.setSyntaxErrors(SyntaxMetadata::ERROR::EMPTY_SYNTAX);
	}

	if (std::regex_search(syntax, std::regex("hello")))
	{
		object.setSyntaxType(SyntaxMetadata::SYNTAX_TYPE::SALUATION);
		object.setSaluationType(SyntaxMetadata::SALUATION_TYPE::HELLO);
	}

	else if (std::regex_search(syntax, std::regex("hi")))
	{
		object.setSyntaxType(SyntaxMetadata::SYNTAX_TYPE::SALUATION);
		object.setSaluationType(SyntaxMetadata::SALUATION_TYPE::HI);
	}


	else if (std::regex_search(syntax, std::regex("what")))
	{
		object.setSyntaxType(SyntaxMetadata::SYNTAX_TYPE::QUESTION);
		object.setQuestionType(SyntaxMetadata::QUESTION_TYPE::WHAT);
	}

	else if (std::regex_search(syntax, std::regex("who")))
	{
		object.setSyntaxType(SyntaxMetadata::SYNTAX_TYPE::QUESTION);
		object.setQuestionType(SyntaxMetadata::QUESTION_TYPE::WHO);
	}

	else if (std::regex_search(syntax, std::regex("why")))
	{
		object.setSyntaxType(SyntaxMetadata::SYNTAX_TYPE::QUESTION);
		object.setQuestionType(SyntaxMetadata::QUESTION_TYPE::WHY);
	}

	else if (std::regex_search(syntax, std::regex("when")))
	{
		object.setSyntaxType(SyntaxMetadata::SYNTAX_TYPE::QUESTION);
		object.setQuestionType(SyntaxMetadata::QUESTION_TYPE::WHENE);
	}

	else if (std::regex_search(syntax, std::regex("where")))
	{
		object.setSyntaxType(SyntaxMetadata::SYNTAX_TYPE::QUESTION);
		object.setQuestionType(SyntaxMetadata::QUESTION_TYPE::WHERE);
	}

		else if (std::regex_search(syntax, std::regex("how")))
	{
		object.setSyntaxType(SyntaxMetadata::SYNTAX_TYPE::QUESTION);
		object.setQuestionType(SyntaxMetadata::QUESTION_TYPE::HOW);
	}

}

#endif