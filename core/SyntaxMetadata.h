#ifndef SYNTAX_METADATA_H
#define SYNTAX_METADATA_H

#include "ConversationState.h"

class SyntaxMetadata
{
public:
	enum class SYNTAX_TYPE {QUESTION,ANSWER,SALUATION,VOID};
	enum class QUESTION_TYPE {LOGICAL,WHAT,WHO,WHY,WHENE,WHERE,HOW,VOID};
	enum class SALUATION_TYPE {HI,HELLO,VOID};
	enum class ERROR {NO_ERROR,UNKNOWN_SAYNTAX,EMPTY_SYNTAX};

	void setSyntaxErrors(SyntaxMetadata::ERROR SyntaxError);
	void setSyntaxType(SyntaxMetadata::SYNTAX_TYPE SaluationType);
	void setQuestionType(SyntaxMetadata::QUESTION_TYPE QuestionType);
	void setSaluationType(SyntaxMetadata::SALUATION_TYPE SaluationType);

	ERROR getSyntaxErrors() const;
	SYNTAX_TYPE getSyntaxType() const;
	QUESTION_TYPE getQuestionType() const;
	SALUATION_TYPE getSaluationType() const;

private:
	ERROR SyntaxErrors;
	SYNTAX_TYPE SyntaxType;
	QUESTION_TYPE QuestionType;
	SALUATION_TYPE SaluationType;
	ConversationState ConversationStateInstance;
};


void SyntaxMetadata::setSyntaxErrors(SyntaxMetadata::ERROR SyntaxError) 
{ 
	this->SyntaxErrors = SyntaxError; 
}

void SyntaxMetadata::setSyntaxType(SyntaxMetadata::SYNTAX_TYPE SyntaxType)
{
	this->SyntaxType = SyntaxType;
}
void SyntaxMetadata::setQuestionType(SyntaxMetadata::QUESTION_TYPE QuestionType)
{
	this->QuestionType = QuestionType;
}
void SyntaxMetadata::setSaluationType(SyntaxMetadata::SALUATION_TYPE SaluationType)
{
	this->SaluationType = SaluationType;
}

SyntaxMetadata::ERROR SyntaxMetadata::getSyntaxErrors() const
{
	return this->SyntaxErrors;
}

SyntaxMetadata::SYNTAX_TYPE SyntaxMetadata::getSyntaxType() const
{
	return this->SyntaxType;
}

SyntaxMetadata::QUESTION_TYPE SyntaxMetadata::getQuestionType() const
{
	return this->QuestionType;
}
	
SyntaxMetadata::SALUATION_TYPE SyntaxMetadata::getSaluationType() const
{
	return this->SaluationType;
}


#endif