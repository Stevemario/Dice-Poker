#ifndef POKERDUELSTAGE_H
#define POKERDUELSTAGE_H
enum class pokerduelstage {
	BetInitial,
	AcknowledgeBetAndRollInitial,
	AcknowledgeRollInitialSelectRerollAndBetSecond,
	AcknowledgeBetAndRollSecond,
	Conclusion,
};
#endif