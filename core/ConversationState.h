#ifndef CONVERSATION_STATE_H
#define CONVERSATION_STATE_H

#include <cstdlib> //for srand() and rand()
#include <ctime> // for time()
class ConversationState
{
private:
	int GuestSpeakTimes = 0;
	int HostSpeakTimes = 0;
	int TotalSpeakTimes = 0;
	short SaluationRepeated = 0;
	short Satisfaction = 5;      // 1->5->10
	bool ConversationStarted = false;

	enum class EXEPCTIONS 
	{ 	
		SATISFACTION_LOW,
		SATISFACTION_HIGH,
		SALUATION_REPEATED 	
	};

public:
	void incrementGuestSpeakTimes();
	void incrementHostSpeakTimes();
	void incrementSaluationRepeated();
	void incrementSatisfaction();
	void decrementSatisfaction();

	int getGuestSpeakTimes();
	int getHostSpeakTimes();
	int getTotalSpeakTimes();
	short getSatisfaction();
	short getSaluationRepeated();
};

void ConversationState::incrementGuestSpeakTimes() { ++GuestSpeakTimes; }
void ConversationState::incrementHostSpeakTimes(){ ++HostSpeakTimes; }

void ConversationState::incrementSaluationRepeated() {
	srand(time(NULL));
 	if(SaluationRepeated == ((rand() % 3) + 3)) 
 		/*
 			for unexpected behaviour from the software, 
 			this will randomly choose the highest 
 			SaluationRepeated value (from range [3:6] times) 
 			before throwing the exeption
 		*/
	{
 		EXEPCTIONS EX = EXEPCTIONS::SALUATION_REPEATED;
		throw EX;
	}
	else
		++SaluationRepeated;
}

void ConversationState::incrementSatisfaction(){ 
	if(Satisfaction == 10)
	{
		EXEPCTIONS EX = EXEPCTIONS::SATISFACTION_HIGH;
		throw EX;
	}
	else
		++Satisfaction; 
}
void ConversationState::decrementSatisfaction(){

	if(Satisfaction == 0)
	{
		EXEPCTIONS EX = EXEPCTIONS::SATISFACTION_LOW;
		throw EX;
	}
	else
 		--Satisfaction; 
}

int ConversationState::getGuestSpeakTimes(){ return GuestSpeakTimes; }
int ConversationState::getHostSpeakTimes(){ return HostSpeakTimes; }
int ConversationState::getTotalSpeakTimes(){ return GuestSpeakTimes + HostSpeakTimes; }
short ConversationState::getSatisfaction() { return Satisfaction ;}
short ConversationState::getSaluationRepeated() { return SaluationRepeated; }


#endif