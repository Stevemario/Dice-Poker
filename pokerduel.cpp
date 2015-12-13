#include "pokerduel.h"
void pokerduel::prepare (
	const int& nBetAgreed,
	const int& nCashInPot,
	const std::string& sBetPlayer,
	const sf::Font& font_,
	const pokerduelstage*& pokerduelstage_p_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemy,
	const intx5*& n5_pEnemyInitial,
	const intx5*& n5_pEnemyReroll,
	const intx5*& n5_pPlayer,
	const intx5*& n5_pPlayerInitial,
	const intx5*& n5_pPlayerReroll,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	switch (*pokerduelstage_p_) {
		case pokerduelstage::BetInitial: {
			prepareStage_BetInitial (
				nCashInPot,
				sBetPlayer,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				vec_screenelement_p_
			);
			break;
		}
		case pokerduelstage::AcknowledgeBetAndRollInitial: {
			prepareStage_AcknowledgeBetAndRollInitial (
				nBetAgreed,
				nCashInPot,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				vec_screenelement_p_
			);
			break;
		}
		case pokerduelstage::AcknowledgeRollInitialSelectRerollAndBetSecond: {
			prepareStage_AcknowledgeRollInitialSelectRerollAndBetSecond (
				nCashInPot,
				sBetPlayer,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				n5_pEnemyInitial,
				n5_pPlayerInitial,
				n5_pPlayerReroll,
				vec_screenelement_p_
			);
			break;
		}
		case pokerduelstage::AcknowledgeBetAndRollSecond: {
			prepareStage_AcknowledgeBetAndRollSecond (
				nCashInPot,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				vec_screenelement_p_
			);
			break;
		}
		case pokerduelstage::Conclusion: {
			prepareStage_Conclusion (
				nCashInPot,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				n5_pEnemy,
				n5_pPlayer,
				vec_screenelement_p_
			);
			break;
		}
	}
}
void pokerduel::prepareStage_BetInitial (
	const int& nCashInPot,
	const std::string& sBetPlayer,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	screenelement_label* se_lblHeaderPromptBet = new screenelement_label_generic (
		font_,
		"Enter Your Bet:",
		screenelement_label_enum::HeaderPromptBetInitial
	);
	screenelement_button* se_btnBetAmount = new screenelement_button_generic (
		font_,
		"$" + sBetPlayer,
		screenelement_button_enum::BetAmount
	);
	screenelement_button* se_btnBetSubmit = new screenelement_button_generic (
		font_,
		"Submit",
		screenelement_button_enum::SubmitBetInitial
	);
	se_btnBetAmount->stretch (360.f, 0.f);
	se_btnBetSubmit->stretch (360.f, 0.f);
	float fWidth_lblHeaderPromptBet = se_lblHeaderPromptBet->frBounds_text ().width;
	float fWidth_btnBetAmount = se_btnBetAmount->frBounds_rs ().width;
	float fWidth_btnBetSubmit = se_btnBetSubmit->frBounds_rs ().width;
	float fPosX_lblHeaderPromptBet = .5f * (1350.f - fWidth_lblHeaderPromptBet);
	float fPosX_btnBetAmount = .5f * (1350.f - fWidth_btnBetAmount);
	float fPosX_btnBetSubmit = .5f * (1350.f - fWidth_btnBetSubmit);
	se_lblHeaderPromptBet->move (fPosX_lblHeaderPromptBet, 300.f);
	se_btnBetAmount->move (fPosX_btnBetAmount, 360.f);
	se_btnBetSubmit->move (fPosX_btnBetSubmit, 500.f);
	vec_screenelement_p_.push_back (se_lblHeaderPromptBet);
	vec_screenelement_p_.push_back (se_btnBetAmount);
	vec_screenelement_p_.push_back (se_btnBetSubmit);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		vec_screenelement_p_
	);
}
void pokerduel::prepareStage_AcknowledgeBetAndRollInitial (
	const int& nBetAgreed,
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	screenelement_label* se_lblHeaderAlertBet = new screenelement_label_generic (
		font_,
		"You've each bet $" + std::to_string (nBetAgreed) + ".",
		screenelement_label_enum::HeaderAlertBet
	);
	screenelement_label* se_lblHeaderPressingRollWillOKBet = new screenelement_label_generic (
		font_,
		"Pressing Roll will OK Bet.",
		screenelement_label_enum::HeaderPressingRollWillOKBet
	);
	screenelement_button* se_btnChangeBetInitial = new screenelement_button_generic (
		font_,
		"Change Bet",
		screenelement_button_enum::ChangeBetInitial
	);
	screenelement_button* se_btnOKBetAndRollDiceInitial = new screenelement_button_generic (
		font_,
		"Roll",
		screenelement_button_enum::OKBetAndRollDiceInitial
	);
	float fWidth_lblHeaderAlertBet = se_lblHeaderAlertBet->frBounds_text ().width;
	float fWidth_lblHeaderPressingRollWillOKBet = se_lblHeaderPressingRollWillOKBet->frBounds_text ().width;
	float fWidth_btnChangeBetInitial = se_btnChangeBetInitial->frBounds_rs ().width;
	float fPosX_lblHeaderAlertBet = .5f * (1350.f - fWidth_lblHeaderAlertBet);
	float fPosX_lblHeaderPressingRollWillOKBet = .5f * (1350.f - fWidth_lblHeaderPressingRollWillOKBet);
	float fPosX_btnChangeBetInitial = .5f * 1350.f  - 10.f - fWidth_btnChangeBetInitial;
	float fPosX_btnOKBetAndRollDiceInitial = .5f * 1350.f  + 10.f;
	se_lblHeaderAlertBet->move (fPosX_lblHeaderAlertBet, 300.f);
	se_lblHeaderPressingRollWillOKBet->move (fPosX_lblHeaderPressingRollWillOKBet, 360.f);
	se_btnChangeBetInitial->move (fPosX_btnChangeBetInitial, 420.f);
	se_btnOKBetAndRollDiceInitial->move (fPosX_btnOKBetAndRollDiceInitial, 420.f);
	vec_screenelement_p_.push_back (se_lblHeaderAlertBet);
	vec_screenelement_p_.push_back (se_lblHeaderPressingRollWillOKBet);
	vec_screenelement_p_.push_back (se_btnChangeBetInitial);
	vec_screenelement_p_.push_back (se_btnOKBetAndRollDiceInitial);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		vec_screenelement_p_
	);
}
void pokerduel::prepareStage_AcknowledgeRollInitialSelectRerollAndBetSecond (
	const int& nCashInPot,
	const std::string& sBetPlayer,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemyInitial,
	const intx5*& n5_pPlayerInitial,
	const intx5*& n5_pPlayerReroll,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	screenelement_rectangle* se_rectDiceSelected0;
	screenelement_rectangle* se_rectDiceSelected1;
	screenelement_rectangle* se_rectDiceSelected2;
	screenelement_rectangle* se_rectDiceSelected3;
	screenelement_rectangle* se_rectDiceSelected4;
	screenelement_label* se_lblHeaderDiceRolled = new screenelement_label_generic (
		font_,
		"These are the dice rolled:",
		screenelement_label_enum::HeaderDiceRolled
	);
	screenelement_label* se_lblHeaderDiceEnemy = new screenelement_label_generic (
		font_,
		"Enemy's Dice",
		screenelement_label_enum::HeaderDiceEnemy
	);
	screenelement_label* se_lblHeaderDicePlayer = new screenelement_label_generic (
		font_,
		"Your Dice",
		screenelement_label_enum::HeaderDicePlayer
	);
	screenelement_label* se_lblHeaderSelectDiceToReroll = new screenelement_label_generic (
		font_,
		"You may select dice to reroll.",
		screenelement_label_enum::HeaderSelectDiceToReroll
	);
	screenelement_label* se_lblHeaderPromptBetSecond = new screenelement_label_generic (
		font_,
		"Bet:",
		screenelement_label_enum::HeaderPromptBetSecond
	);
	screenelement_button* se_btnDiceEnemy0 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (0),
		screenelement_button_enum::DiceEnemy0
	);
	screenelement_button* se_btnDiceEnemy1 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (1),
		screenelement_button_enum::DiceEnemy1
	);
	screenelement_button* se_btnDiceEnemy2 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (2),
		screenelement_button_enum::DiceEnemy2
	);
	screenelement_button* se_btnDiceEnemy3 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (3),
		screenelement_button_enum::DiceEnemy3
	);
	screenelement_button* se_btnDiceEnemy4 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (4),
		screenelement_button_enum::DiceEnemy4
	);
	screenelement_button* se_btnDicePlayer0 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (0),
		screenelement_button_enum::DicePlayer0
	);
	screenelement_button* se_btnDicePlayer1 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (1),
		screenelement_button_enum::DicePlayer1
	);
	screenelement_button* se_btnDicePlayer2 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (2),
		screenelement_button_enum::DicePlayer2
	);
	screenelement_button* se_btnDicePlayer3 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (3),
		screenelement_button_enum::DicePlayer3
	);
	screenelement_button* se_btnDicePlayer4 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (4),
		screenelement_button_enum::DicePlayer4
	);
	screenelement_button* se_btnBetAmount = new screenelement_button_generic (
		font_,
		"$" + sBetPlayer,
		screenelement_button_enum::BetAmount
	);
	screenelement_button* se_btnSubmitRerollAndSecondBet = new screenelement_button_generic (
		font_,
		"Submit",
		screenelement_button_enum::SubmitRerollAndSecondBet
	);
	sf::FloatRect frBounds_btnDicePlayer0 = se_btnDicePlayer0->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer1 = se_btnDicePlayer1->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer2 = se_btnDicePlayer2->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer3 = se_btnDicePlayer3->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer4 = se_btnDicePlayer4->frBounds_rs ();
	float fWidth_lblHeaderDiceRolled = se_lblHeaderDiceRolled->frBounds_text ().width;
	float fWidth_lblHeaderDiceEnemy = se_lblHeaderDiceEnemy->frBounds_text ().width;
	float fWidth_lblHeaderDicePlayer = se_lblHeaderDicePlayer->frBounds_text ().width;
	float fWidth_lblHeaderSelectDiceToReroll = se_lblHeaderSelectDiceToReroll->frBounds_text ().width;
	float fWidth_lblHeaderPromptBetSecond = se_lblHeaderPromptBetSecond->frBounds_text ().width;
	float fWidth_btnDiceEnemy0 = se_btnDiceEnemy0->frBounds_rs ().width;
	float fWidth_btnDiceEnemy1 = se_btnDiceEnemy1->frBounds_rs ().width;
	float fWidth_btnDiceEnemy2 = se_btnDiceEnemy2->frBounds_rs ().width;
	float fWidth_btnDiceEnemy3 = se_btnDiceEnemy3->frBounds_rs ().width;
	float fWidth_btnDiceEnemy4 = se_btnDiceEnemy4->frBounds_rs ().width;
	float fWidth_btnDicePlayer0 = frBounds_btnDicePlayer0.width;
	float fWidth_btnDicePlayer1 = frBounds_btnDicePlayer1.width;
	float fWidth_btnDicePlayer2 = frBounds_btnDicePlayer2.width;
	float fWidth_btnDicePlayer3 = frBounds_btnDicePlayer3.width;
	float fWidth_btnDicePlayer4 = frBounds_btnDicePlayer4.width;
	float fHeight_btnDicePlayer0 = frBounds_btnDicePlayer0.height;
	float fHeight_btnDicePlayer1 = frBounds_btnDicePlayer1.height;
	float fHeight_btnDicePlayer2 = frBounds_btnDicePlayer2.height;
	float fHeight_btnDicePlayer3 = frBounds_btnDicePlayer3.height;
	float fHeight_btnDicePlayer4 = frBounds_btnDicePlayer4.height;
	float fWidth_btnSubmitRerollAndSecondBet = se_btnSubmitRerollAndSecondBet->frBounds_rs ().width;
	float fPosX_lblHeaderDiceRolled = .5f * (1350.f - fWidth_lblHeaderDiceRolled);
	float fPosX_lblHeaderDiceEnemy = 2.f * 1350.f / 3.f - .5f * fWidth_lblHeaderDiceEnemy;
	float fPosX_lblHeaderDicePlayer = 1350.f / 3.f - .5f * fWidth_lblHeaderDicePlayer;
	float fPosX_lblHeaderSelectDiceToReroll = .5f * (1350.f - fWidth_lblHeaderSelectDiceToReroll);
	float fPosX_lblHeaderPromptBetSecond = .5f * 1350.f - 10.f - fWidth_lblHeaderPromptBetSecond;
	float fPosX_btnDiceEnemy0 = 2.f * 1350.f / 3.f - .5f * fWidth_btnDiceEnemy0;
	float fPosX_btnDiceEnemy1 = 2.f * 1350.f / 3.f - .5f * fWidth_btnDiceEnemy1;
	float fPosX_btnDiceEnemy2 = 2.f * 1350.f / 3.f - .5f * fWidth_btnDiceEnemy2;
	float fPosX_btnDiceEnemy3 = 2.f * 1350.f / 3.f - .5f * fWidth_btnDiceEnemy3;
	float fPosX_btnDiceEnemy4 = 2.f * 1350.f / 3.f - .5f * fWidth_btnDiceEnemy4;
	float fPosX_btnDicePlayer0 = 1350.f / 3.f - .5f * fWidth_btnDicePlayer0;
	float fPosX_btnDicePlayer1 = 1350.f / 3.f - .5f * fWidth_btnDicePlayer1;
	float fPosX_btnDicePlayer2 = 1350.f / 3.f - .5f * fWidth_btnDicePlayer2;
	float fPosX_btnDicePlayer3 = 1350.f / 3.f - .5f * fWidth_btnDicePlayer3;
	float fPosX_btnDicePlayer4 = 1350.f / 3.f - .5f * fWidth_btnDicePlayer4;
	float fPosX_btnBetAmount = .5f * 1350.f + 10.f;
	float fPosX_btnSubmitRerollAndSecondBet = .5f * (1350.f - fWidth_btnSubmitRerollAndSecondBet);
	se_rectDiceSelected0 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer0 + 8.f,
		fHeight_btnDicePlayer0 + 8.f
	);
	se_rectDiceSelected1 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer1 + 8.f,
		fHeight_btnDicePlayer1 + 8.f
	);
	se_rectDiceSelected2 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer2 + 8.f,
		fHeight_btnDicePlayer2 + 8.f
	);
	se_rectDiceSelected3 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer3 + 8.f,
		fHeight_btnDicePlayer3 + 8.f
	);
	se_rectDiceSelected4 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer4 + 8.f,
		fHeight_btnDicePlayer4 + 8.f
	);
	se_rectDiceSelected0->move (fPosX_btnDicePlayer0 - 4.f, 236.f);
	se_rectDiceSelected1->move (fPosX_btnDicePlayer1 - 4.f, 336.f);
	se_rectDiceSelected2->move (fPosX_btnDicePlayer2 - 4.f, 436.f);
	se_rectDiceSelected3->move (fPosX_btnDicePlayer3 - 4.f, 536.f);
	se_rectDiceSelected4->move (fPosX_btnDicePlayer4 - 4.f, 636.f);
	se_lblHeaderDiceRolled->move (fPosX_lblHeaderDiceRolled, 120.f);
	se_lblHeaderDiceEnemy->move (fPosX_lblHeaderDiceEnemy, 180.f);
	se_lblHeaderDicePlayer->move (fPosX_lblHeaderDicePlayer, 180.f);
	se_lblHeaderSelectDiceToReroll->move (fPosX_lblHeaderSelectDiceToReroll, 740.f);
	se_lblHeaderPromptBetSecond->move (fPosX_lblHeaderPromptBetSecond, 830.f);
	se_btnDiceEnemy0->move (fPosX_btnDiceEnemy0, 240.f);
	se_btnDiceEnemy1->move (fPosX_btnDiceEnemy1, 340.f);
	se_btnDiceEnemy2->move (fPosX_btnDiceEnemy2, 440.f);
	se_btnDiceEnemy3->move (fPosX_btnDiceEnemy3, 540.f);
	se_btnDiceEnemy4->move (fPosX_btnDiceEnemy4, 640.f);
	se_btnDicePlayer0->move (fPosX_btnDicePlayer0, 240.f);
	se_btnDicePlayer1->move (fPosX_btnDicePlayer1, 340.f);
	se_btnDicePlayer2->move (fPosX_btnDicePlayer2, 440.f);
	se_btnDicePlayer3->move (fPosX_btnDicePlayer3, 540.f);
	se_btnDicePlayer4->move (fPosX_btnDicePlayer4, 640.f);
	se_btnBetAmount->move (fPosX_btnBetAmount, 800.f);
	se_btnSubmitRerollAndSecondBet->move (fPosX_btnSubmitRerollAndSecondBet, 940.f);
	vec_screenelement_p_.push_back (se_lblHeaderDiceRolled);
	vec_screenelement_p_.push_back (se_lblHeaderDiceEnemy);
	vec_screenelement_p_.push_back (se_lblHeaderDicePlayer);
	vec_screenelement_p_.push_back (se_lblHeaderSelectDiceToReroll);
	vec_screenelement_p_.push_back (se_lblHeaderPromptBetSecond);
	vec_screenelement_p_.push_back (se_btnSubmitRerollAndSecondBet);
	vec_screenelement_p_.push_back (se_btnBetAmount);
	vec_screenelement_p_.push_back (se_btnDiceEnemy4);
	if (n5_pPlayerReroll->n (4) == int (true)) {
		vec_screenelement_p_.push_back (se_rectDiceSelected4);
	} else {
		delete se_rectDiceSelected4;
	}
	vec_screenelement_p_.push_back (se_btnDicePlayer4);
	vec_screenelement_p_.push_back (se_btnDiceEnemy3);
	if (n5_pPlayerReroll->n (3) == int (true)) {
		vec_screenelement_p_.push_back (se_rectDiceSelected3);
	} else {
		delete se_rectDiceSelected3;
	}
	vec_screenelement_p_.push_back (se_btnDicePlayer3);
	vec_screenelement_p_.push_back (se_btnDiceEnemy2);
	if (n5_pPlayerReroll->n (2) == int (true)) {
		vec_screenelement_p_.push_back (se_rectDiceSelected2);
	} else {
		delete se_rectDiceSelected2;
	}
	vec_screenelement_p_.push_back (se_btnDicePlayer2);
	vec_screenelement_p_.push_back (se_btnDiceEnemy1);
	if (n5_pPlayerReroll->n (1) == int (true)) {
		vec_screenelement_p_.push_back (se_rectDiceSelected1);
	} else {
		delete se_rectDiceSelected1;
	}
	vec_screenelement_p_.push_back (se_btnDicePlayer1);
	vec_screenelement_p_.push_back (se_btnDiceEnemy0);
	if (n5_pPlayerReroll->n (0) == int (true)) {
		vec_screenelement_p_.push_back (se_rectDiceSelected0);
	} else {
		delete se_rectDiceSelected0;
	}
	vec_screenelement_p_.push_back (se_btnDicePlayer0);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		vec_screenelement_p_
	);
}
void pokerduel::prepareStage_AcknowledgeBetAndRollSecond (
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		vec_screenelement_p_
	);
}
void pokerduel::prepareStage_Conclusion (
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemy,
	const intx5*& n5_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		vec_screenelement_p_
	);
}
void pokerduel::addLabelsCash (
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	screenelement_label* se_lblHeaderNameEnemy = new screenelement_label_generic (font_,
		gamedata_pEnemy->sPlayerName (),
		screenelement_label_enum::HeaderNameEnemy
	);
	screenelement_label* se_lblHeaderNamePlayer = new screenelement_label_generic (font_,
		gamedata_pPlayer->sPlayerName (),
		screenelement_label_enum::HeaderNamePlayer
	);
	screenelement_label* se_lblHeaderPot = new screenelement_label_generic (font_,
		"Pot",
		screenelement_label_enum::HeaderPot
	);
	screenelement_label* se_lblHeaderCashEnemy = new screenelement_label_generic (font_,
		std::to_string (gamedata_pEnemy->nDollarsCarried ()),
		screenelement_label_enum::HeaderCashEnemy
	);
	screenelement_label* se_lblHeaderCashPlayer = new screenelement_label_generic (font_,
		std::to_string (gamedata_pPlayer->nDollarsCarried ()),
		screenelement_label_enum::HeaderCashPlayer
	);
	screenelement_label* se_lblHeaderCashPot = new screenelement_label_generic (
		font_,
		std::to_string (nCashInPot),
		screenelement_label_enum::HeaderCashPot
	);
	float fWidth_lblHeaderNameEnemy = se_lblHeaderNameEnemy->frBounds_text ().width;
	float fWidth_lblHeaderNamePlayer = se_lblHeaderNamePlayer->frBounds_text ().width;
	float fWidth_lblHeaderPot = se_lblHeaderPot->frBounds_text ().width;
	float fWidth_lblHeaderCashEnemy = se_lblHeaderCashEnemy->frBounds_text ().width;
	float fWidth_lblHeaderCashPlayer = se_lblHeaderCashPlayer->frBounds_text ().width;
	float fWidth_lblHeaderCashPot = se_lblHeaderCashPot->frBounds_text ().width;
	float fPosX_lblHeaderNameEnemy = 1350.f - 25.f - fWidth_lblHeaderNameEnemy;
	float fPosX_lblHeaderNamePlayer = 25.f;
	float fPosX_lblHeaderPot = .5f * (1350.f - fWidth_lblHeaderPot);
	float fPosX_lblHeaderCashEnemy = 1350.f - 25.f - fWidth_lblHeaderCashEnemy;
	float fPosX_lblHeaderCashPlayer = 25.f;
	float fPosX_lblHeaderCashPot = .5f * (1350.f - fWidth_lblHeaderCashPot);
	se_lblHeaderNameEnemy->move (fPosX_lblHeaderNameEnemy, 0.f);
	se_lblHeaderNamePlayer->move (fPosX_lblHeaderNamePlayer, 0.f);
	se_lblHeaderPot->move (fPosX_lblHeaderPot, 0.f);
	se_lblHeaderCashEnemy->move (fPosX_lblHeaderCashEnemy, 60.f);
	se_lblHeaderCashPlayer->move (fPosX_lblHeaderCashPlayer, 60.f);
	se_lblHeaderCashPot->move (fPosX_lblHeaderCashPot, 60.f);
	vec_screenelement_p_.push_back (se_lblHeaderNameEnemy);
	vec_screenelement_p_.push_back (se_lblHeaderNamePlayer);
	vec_screenelement_p_.push_back (se_lblHeaderPot);
	vec_screenelement_p_.push_back (se_lblHeaderCashEnemy);
	vec_screenelement_p_.push_back (se_lblHeaderCashPlayer);
	vec_screenelement_p_.push_back (se_lblHeaderCashPot);
}
pokerduel::screenelement_rectangle_enum pokerduel::screenelement_rectangle_dice_selected_background::screenelement_rectangle_enum_ (
) const {
	return screenelement_rectangle_enum::DiceSelectedBackground;
}
pokerduel::screenelement_rectangle_dice_selected_background::screenelement_rectangle_dice_selected_background (
	const float& fWidth,
	const float& fHeight
) {
	set_bIsHeldDown (false);
	create (fWidth, fHeight, sf::Color (255, 255, 255, 255));
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_generic::screenelement_label_enum_ (
) const {
	return m_screenelement_label_enum;
}
pokerduel::screenelement_label_generic::screenelement_label_generic (
	const sf::Font& font_,
	const std::string& s_,
	const screenelement_label_enum& screenelement_label_enum_
) {
	set_bIsHeldDown (false);
	m_screenelement_label_enum = screenelement_label_enum_;
	create (s_, font_, 60, sf::Color::White);
}
pokerduel::screenelement_button_enum pokerduel::screenelement_button_generic::screenelement_button_enum_ (
) const {
	return m_screenelement_button_enum;
}
pokerduel::screenelement_button_generic::screenelement_button_generic (
	const sf::Font& font_,
	const std::string& s_,
	const screenelement_button_enum& screenelement_button_enum_
) {
	set_bIsHeldDown (false);
	m_screenelement_button_enum = screenelement_button_enum_;
	create (s_, font_, 60, sf::Color::White, sf::Color::Black);
	stretch (frBounds_rs ().width + 24.f, 120.f);
}
pokerduel::screenelement_button_enum pokerduel::screenelement_button_dice::screenelement_button_enum_ (
) const {
	return m_screenelement_button_enum;
}
pokerduel::screenelement_button_dice::screenelement_button_dice (
	const sf::Font& font_,
	const int& n_,
	const screenelement_button_enum& screenelement_button_enum_
) {
	set_bIsHeldDown (false);
	m_screenelement_button_enum = screenelement_button_enum_;
	create (std::to_string (n_), font_, 40, sf::Color::White, sf::Color::Black);
	stretch (frBounds_rs ().width + 16.f, 80.f);
}