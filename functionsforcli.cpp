#include "functionsforcli.h"
#include <iostream>
std::string sScore (
	const intx5& n5DiceToScore
) {
	std::string sScore;
	diceset* diceset_pToScore = diceset_p_ (n5DiceToScore);
	int nScore = diceset_pToScore->nScore ();
	delete diceset_pToScore;
	diceset_pToScore = nullptr;
	sScore = std::to_string (nScore);
	return sScore;
}
std::string sValues (
	const intx5& n5_
) {
	std::string sValues;
	for (int i = 0; i < 5; i++) {
		sValues += std::to_string (n5_[i]);
		if (i < 4)
			sValues += ',';
	}
	return sValues;
}
void present (
	const intx5& n5DiceToPresent
) {
	std::string sLineToPrint = "   . ";
	std::string sScoreOfDice = sScore (n5DiceToPresent);
	std::string sValuesOfDice = sValues (n5DiceToPresent);
	int nLengthOfScore = sScoreOfDice.length ();
	if (nLengthOfScore <= 3)
		sLineToPrint.replace (3 - nLengthOfScore, nLengthOfScore, sScoreOfDice);
	else
		sLineToPrint.replace (0, 3, sScoreOfDice.substr (nLengthOfScore - 3, 3));
	sLineToPrint += sValuesOfDice;
	std::cout << sLineToPrint << '\n';
}
void presentAllScores (
) {
	intx5 n5Dice;
	//Fives Of A Kind
	for (int nDice = 6; 1 <= nDice; nDice--) {
		n5Dice[0] = nDice;
		n5Dice[1] = nDice;
		n5Dice[2] = nDice;
		n5Dice[3] = nDice;
		n5Dice[4] = nDice;
		present (n5Dice);
	}
	//Fours Of A Kind
	for (int nDice0 = 6; 1 <= nDice0; nDice0--) {
		n5Dice[0] = nDice0;
		n5Dice[1] = nDice0;
		n5Dice[2] = nDice0;
		n5Dice[3] = nDice0;
		for (int nDice1 = 6; 1 <= nDice1; nDice1--) {
			if (nDice1 != nDice0) {
				n5Dice[4] = nDice1;
				present (n5Dice);
			}
		}
	}
	//Full Houses
	for (int nDice0 = 6; 1 <= nDice0; nDice0--) {
		n5Dice[0] = nDice0;
		n5Dice[1] = nDice0;
		n5Dice[2] = nDice0;
		for (int nDice1 = 6; 1 <= nDice1; nDice1--) {
			if (nDice1 != nDice0) {
				n5Dice[3] = nDice1;
				n5Dice[4] = nDice1;
				present (n5Dice);
			}
		}
	}
	//Straights
	for (int nRankStraight = 1; nRankStraight <= 2; nRankStraight++) {
		for (int nIndex = 0; nIndex < 5; nIndex++) {
			n5Dice[nIndex] = 7 - nRankStraight - nIndex;
		}
		present (n5Dice);
	}
	//Threes Of A Kind
	for (int nDice0 = 6; 1 <= nDice0; nDice0--) {
		n5Dice[0] = nDice0;
		n5Dice[1] = nDice0;
		n5Dice[2] = nDice0;
		for (int nDice1 = 6; 1 <= nDice1; nDice1--) {
			if (nDice1 != nDice0) {
				n5Dice[3] = nDice1;
				for (int nDice2 = nDice1 - 1; 1 <= nDice2; nDice2--) {
					if (nDice2 != nDice0) {
						n5Dice[4] = nDice2;
						present (n5Dice);
					}
				}
			}
		}
	}
	//Two Pairs
	for (int nDice0 = 6; 1 <= nDice0; nDice0--) {
		n5Dice[0] = nDice0;
		n5Dice[1] = nDice0;
		for (int nDice1 = nDice0 - 1; 1 <= nDice1; nDice1--) {
			n5Dice[2] = nDice1;
			n5Dice[3] = nDice1;
			for (int nDice2 = 6; 1 <= nDice2; nDice2--) {
				if (nDice2 != nDice0) {
					if (nDice2 != nDice1) {
						n5Dice[4] = nDice2;
						present (n5Dice);
					}
				}
			}
		}
	}
	//One Pairs
	for (int nDice0 = 6; 1 <= nDice0; nDice0--) {
		n5Dice[0] = nDice0;
		n5Dice[1] = nDice0;
		for (int nDice1 = 6; 1 <= nDice1; nDice1--) {
			if (nDice0 != nDice1) {
				n5Dice[2] = nDice1;
				for (int nDice2 = nDice1 - 1; 1 <= nDice2; nDice2--) {
					if (nDice0 != nDice2) {
						n5Dice[3] = nDice2;
						for (int nDice3 = nDice2 - 1; 1 <= nDice3; nDice3--) {
							if (nDice0 != nDice3) {
								n5Dice[4] = nDice3;
								present (n5Dice);
							}
						}
					}
				}
			}
		}
	}
	//High Dice
	n5Dice[0] = 6;
	n5Dice[4] = 1;
	int nDiceToAssign;
	for (int nDiceSkipped = 2; nDiceSkipped <= 5; nDiceSkipped++) {
		for (int i = 1; i <= 4; i++) {
			nDiceToAssign = 6 - i;
			if (nDiceToAssign != nDiceSkipped) {
				if (nDiceSkipped < nDiceToAssign)
					n5Dice[i] = nDiceToAssign;
				else
					n5Dice[i - 1] = nDiceToAssign;
			}
		}
		present (n5Dice);
	}
}
void presentAllDiceSet (
) {
	intx5 n5Dice;
	for (int nDice0 = 1; nDice0 <= 6; nDice0++) {
		n5Dice[0] = nDice0;
		for (int nDice1 = 1; nDice1 <= 6; nDice1++) {
			n5Dice[1] = nDice1;
			for (int nDice2 = 1; nDice2 <= 6; nDice2++) {
				n5Dice[2] = nDice2;
				for (int nDice3 = 1; nDice3 <= 6; nDice3++) {
					n5Dice[3] = nDice3;
					for (int nDice4 = 1; nDice4 <= 6; nDice4++) {
						n5Dice[4] = nDice4;
						present (n5Dice);
					}
				}
			}
		}
	}
}