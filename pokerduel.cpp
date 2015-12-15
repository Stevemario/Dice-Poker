#include "pokerduel.h"
void pokerduel::prepare (
	const int& nBetAgreed,
	const int& nCashInPot,
	const int& nCashInPotBefore,
	const int& nScoreEnemyInitial,
	const int& nScoreEnemyUltimate,
	const int& nScorePlayerInitial,
	const int& nScorePlayerUltimate,
	const std::string& sBetPlayer,
	const sf::Font& font_,
	const pokerduelresult*& pokerduelresult_p_,
	const pokerduelstage*& pokerduelstage_p_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemyInitial,
	const intx5*& n5_pEnemyReroll,
	const intx5*& n5_pEnemyUltimate,
	const intx5*& n5_pPlayerInitial,
	const intx5*& n5_pPlayerReroll,
	const intx5*& n5_pPlayerUltimate,
	screenelements& ses_
) {
	switch (*pokerduelstage_p_) {
		case pokerduelstage::SubmitInputInitial: {
			prepareStage_SubmitInputInitial (
				nCashInPot,
				sBetPlayer,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				ses_
			);
			break;
		}
		case pokerduelstage::OKInputInitial: {
			prepareStage_OKInputInitial (
				nBetAgreed,
				nCashInPot,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				ses_
			);
			break;
		}
		case pokerduelstage::SubmitInputSecond: {
			prepareStage_SubmitInputSecond (
				nCashInPot,
				sBetPlayer,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				n5_pEnemyInitial,
				n5_pPlayerInitial,
				n5_pPlayerReroll,
				ses_
			);
			break;
		}
		case pokerduelstage::OKInputSecond: {
			prepareStage_OKInputSecond (
				nBetAgreed,
				nCashInPot,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				ses_
			);
			break;
		}
		case pokerduelstage::OKResults: {
			prepareStage_OKResults (
				nCashInPot,
				nCashInPotBefore,
				nScoreEnemyInitial,
				nScoreEnemyUltimate,
				nScorePlayerInitial,
				nScorePlayerUltimate,
				font_,
				pokerduelresult_p_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				n5_pEnemyInitial,
				n5_pEnemyReroll,
				n5_pEnemyUltimate,
				n5_pPlayerInitial,
				n5_pPlayerReroll,
				n5_pPlayerUltimate,
				ses_
			);
			break;
		}
	}
}
void pokerduel::prepareStage_SubmitInputInitial (
	const int& nCashInPot,
	const std::string& sBetPlayer,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	screenelements& ses_
) {
	screenelement_label* lblHeaderPromptBet = new screenelement_label_generic (
		font_,
		"Enter Your Bet:",
		screenelement_label_enum::HeaderPromptBetInitial
	);
	screenelement_button* btnBetAmount = new screenelement_button_generic (
		font_,
		"$" + sBetPlayer,
		screenelement_button_enum::BetAmount
	);
	screenelement_button* btnSubmitInputInitial = new screenelement_button_generic (
		font_,
		"Submit",
		screenelement_button_enum::SubmitInputInitial
	);
	btnBetAmount->stretch (360.f, 0.f);
	btnSubmitInputInitial->stretch (360.f, 0.f);
	float fWidth_lblHeaderPromptBet = lblHeaderPromptBet->frBounds_text ().width;
	float fWidth_btnBetAmount = btnBetAmount->frBounds_rs ().width;
	float fWidth_btnSubmitInputInitial = btnSubmitInputInitial->frBounds_rs ().width;
	float fPosX_lblHeaderPromptBet = .5f * (1350.f - fWidth_lblHeaderPromptBet);
	float fPosX_btnBetAmount = .5f * (1350.f - fWidth_btnBetAmount);
	float fPosX_btnSubmitInputInitial = .5f * (1350.f - fWidth_btnSubmitInputInitial);
	lblHeaderPromptBet->move (fPosX_lblHeaderPromptBet, 180.f);
	btnBetAmount->move (fPosX_btnBetAmount, 240.f);
	btnSubmitInputInitial->move (fPosX_btnSubmitInputInitial, 380.f);
	ses_.push_back (lblHeaderPromptBet);
	ses_.push_back (btnBetAmount);
	ses_.push_back (btnSubmitInputInitial);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		ses_
	);
}
void pokerduel::prepareStage_OKInputInitial (
	const int& nBetAgreed,
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	screenelements& ses_
) {
	screenelement_label* lblHeaderAlertBet = new screenelement_label_generic (
		font_,
		"You've each bet $" + std::to_string (nBetAgreed) + ".",
		screenelement_label_enum::HeaderAlertBet
	);
	screenelement_label* lblHeaderPressingRollWillOKBet = new screenelement_label_generic (
		font_,
		"Pressing OK Bet will roll the dice.",
		screenelement_label_enum::HeaderPressingRollWillOKBet
	);
	screenelement_button* btnChangeInputInitial = new screenelement_button_generic (
		font_,
		"Change Bet",
		screenelement_button_enum::ChangeInputInitial
	);
	screenelement_button* btnOKInputInitial = new screenelement_button_generic (
		font_,
		"OK Bet",
		screenelement_button_enum::OKInputInitial
	);
	float fWidth_lblHeaderAlertBet = lblHeaderAlertBet->frBounds_text ().width;
	float fWidth_lblHeaderPressingRollWillOKBet = lblHeaderPressingRollWillOKBet->frBounds_text ().width;
	float fWidth_btnChangeInputInitial = btnChangeInputInitial->frBounds_rs ().width;
	float fPosX_lblHeaderAlertBet = .5f * (1350.f - fWidth_lblHeaderAlertBet);
	float fPosX_lblHeaderPressingRollWillOKBet = .5f * (1350.f - fWidth_lblHeaderPressingRollWillOKBet);
	float fPosX_btnChangeInputInitial = .5f * 1350.f  - 10.f - fWidth_btnChangeInputInitial;
	float fPosX_btnOKInputInitial = .5f * 1350.f  + 10.f;
	lblHeaderAlertBet->move (fPosX_lblHeaderAlertBet, 180.f);
	lblHeaderPressingRollWillOKBet->move (fPosX_lblHeaderPressingRollWillOKBet, 380.f);
	btnChangeInputInitial->move (fPosX_btnChangeInputInitial, 240.f);
	btnOKInputInitial->move (fPosX_btnOKInputInitial, 240.f);
	ses_.push_back (lblHeaderAlertBet);
	ses_.push_back (lblHeaderPressingRollWillOKBet);
	ses_.push_back (btnChangeInputInitial);
	ses_.push_back (btnOKInputInitial);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		ses_
	);
}
void pokerduel::prepareStage_SubmitInputSecond (
	const int& nCashInPot,
	const std::string& sBetPlayer,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemyInitial,
	const intx5*& n5_pPlayerInitial,
	const intx5*& n5_pPlayerReroll,
	screenelements& ses_
) {
	screenelement_rectangle* rectDiceSelected0;
	screenelement_rectangle* rectDiceSelected1;
	screenelement_rectangle* rectDiceSelected2;
	screenelement_rectangle* rectDiceSelected3;
	screenelement_rectangle* rectDiceSelected4;
	screenelement_label* lblHeaderDiceRolled = new screenelement_label_generic (
		font_,
		"These are the dice rolled:",
		screenelement_label_enum::HeaderDiceRolled
	);
	screenelement_label* lblHeaderDiceEnemy = new screenelement_label_generic (
		font_,
		"Enemy's Dice",
		screenelement_label_enum::HeaderDiceEnemy
	);
	screenelement_label* lblHeaderDicePlayer = new screenelement_label_generic (
		font_,
		"Your Dice",
		screenelement_label_enum::HeaderDicePlayer
	);
	screenelement_label* lblHeaderSelectDiceToReroll = new screenelement_label_generic (
		font_,
		"You may select dice to reroll.",
		screenelement_label_enum::HeaderSelectDiceToReroll
	);
	screenelement_label* lblHeaderPromptBetSecond = new screenelement_label_generic (
		font_,
		"Bet:",
		screenelement_label_enum::HeaderPromptBetSecond
	);
	screenelement_button* btnDiceEnemy0 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (0),
		screenelement_button_enum::DiceEnemy0
	);
	screenelement_button* btnDiceEnemy1 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (1),
		screenelement_button_enum::DiceEnemy1
	);
	screenelement_button* btnDiceEnemy2 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (2),
		screenelement_button_enum::DiceEnemy2
	);
	screenelement_button* btnDiceEnemy3 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (3),
		screenelement_button_enum::DiceEnemy3
	);
	screenelement_button* btnDiceEnemy4 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (4),
		screenelement_button_enum::DiceEnemy4
	);
	screenelement_button* btnDicePlayer0 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (0),
		screenelement_button_enum::DicePlayer0
	);
	screenelement_button* btnDicePlayer1 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (1),
		screenelement_button_enum::DicePlayer1
	);
	screenelement_button* btnDicePlayer2 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (2),
		screenelement_button_enum::DicePlayer2
	);
	screenelement_button* btnDicePlayer3 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (3),
		screenelement_button_enum::DicePlayer3
	);
	screenelement_button* btnDicePlayer4 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (4),
		screenelement_button_enum::DicePlayer4
	);
	screenelement_button* btnBetAmount = new screenelement_button_generic (
		font_,
		"$" + sBetPlayer,
		screenelement_button_enum::BetAmount
	);
	screenelement_button* btnSubmitInputSecond = new screenelement_button_generic (
		font_,
		"Submit",
		screenelement_button_enum::SubmitInputSecond
	);
	sf::FloatRect frBounds_btnDicePlayer0 = btnDicePlayer0->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer1 = btnDicePlayer1->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer2 = btnDicePlayer2->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer3 = btnDicePlayer3->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer4 = btnDicePlayer4->frBounds_rs ();
	float fWidth_lblHeaderDiceRolled = lblHeaderDiceRolled->frBounds_text ().width;
	float fWidth_lblHeaderDiceEnemy = lblHeaderDiceEnemy->frBounds_text ().width;
	float fWidth_lblHeaderDicePlayer = lblHeaderDicePlayer->frBounds_text ().width;
	float fWidth_lblHeaderSelectDiceToReroll = lblHeaderSelectDiceToReroll->frBounds_text ().width;
	float fWidth_lblHeaderPromptBetSecond = lblHeaderPromptBetSecond->frBounds_text ().width;
	float fWidth_btnDiceEnemy0 = btnDiceEnemy0->frBounds_rs ().width;
	float fWidth_btnDiceEnemy1 = btnDiceEnemy1->frBounds_rs ().width;
	float fWidth_btnDiceEnemy2 = btnDiceEnemy2->frBounds_rs ().width;
	float fWidth_btnDiceEnemy3 = btnDiceEnemy3->frBounds_rs ().width;
	float fWidth_btnDiceEnemy4 = btnDiceEnemy4->frBounds_rs ().width;
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
	float fWidth_btnSubmitInputSecond = btnSubmitInputSecond->frBounds_rs ().width;
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
	float fPosX_btnSubmitInputSecond = .5f * (1350.f - fWidth_btnSubmitInputSecond);
	rectDiceSelected0 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer0 + 8.f,
		fHeight_btnDicePlayer0 + 8.f
	);
	rectDiceSelected1 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer1 + 8.f,
		fHeight_btnDicePlayer1 + 8.f
	);
	rectDiceSelected2 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer2 + 8.f,
		fHeight_btnDicePlayer2 + 8.f
	);
	rectDiceSelected3 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer3 + 8.f,
		fHeight_btnDicePlayer3 + 8.f
	);
	rectDiceSelected4 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer4 + 8.f,
		fHeight_btnDicePlayer4 + 8.f
	);
	rectDiceSelected0->move (fPosX_btnDicePlayer0 - 4.f, 236.f);
	rectDiceSelected1->move (fPosX_btnDicePlayer1 - 4.f, 336.f);
	rectDiceSelected2->move (fPosX_btnDicePlayer2 - 4.f, 436.f);
	rectDiceSelected3->move (fPosX_btnDicePlayer3 - 4.f, 536.f);
	rectDiceSelected4->move (fPosX_btnDicePlayer4 - 4.f, 636.f);
	lblHeaderDiceRolled->move (fPosX_lblHeaderDiceRolled, 120.f);
	lblHeaderDiceEnemy->move (fPosX_lblHeaderDiceEnemy, 180.f);
	lblHeaderDicePlayer->move (fPosX_lblHeaderDicePlayer, 180.f);
	lblHeaderSelectDiceToReroll->move (fPosX_lblHeaderSelectDiceToReroll, 740.f);
	lblHeaderPromptBetSecond->move (fPosX_lblHeaderPromptBetSecond, 830.f);
	btnDiceEnemy0->move (fPosX_btnDiceEnemy0, 240.f);
	btnDiceEnemy1->move (fPosX_btnDiceEnemy1, 340.f);
	btnDiceEnemy2->move (fPosX_btnDiceEnemy2, 440.f);
	btnDiceEnemy3->move (fPosX_btnDiceEnemy3, 540.f);
	btnDiceEnemy4->move (fPosX_btnDiceEnemy4, 640.f);
	btnDicePlayer0->move (fPosX_btnDicePlayer0, 240.f);
	btnDicePlayer1->move (fPosX_btnDicePlayer1, 340.f);
	btnDicePlayer2->move (fPosX_btnDicePlayer2, 440.f);
	btnDicePlayer3->move (fPosX_btnDicePlayer3, 540.f);
	btnDicePlayer4->move (fPosX_btnDicePlayer4, 640.f);
	btnBetAmount->move (fPosX_btnBetAmount, 800.f);
	btnSubmitInputSecond->move (fPosX_btnSubmitInputSecond, 940.f);
	ses_.push_back (lblHeaderDiceRolled);
	ses_.push_back (lblHeaderDiceEnemy);
	ses_.push_back (lblHeaderDicePlayer);
	ses_.push_back (lblHeaderSelectDiceToReroll);
	ses_.push_back (lblHeaderPromptBetSecond);
	ses_.push_back (btnSubmitInputSecond);
	ses_.push_back (btnBetAmount);
	ses_.push_back (btnDiceEnemy4);
	if (n5_pPlayerReroll->n (4) == int (true)) {
		ses_.push_back (rectDiceSelected4);
	} else {
		delete rectDiceSelected4;
	}
	ses_.push_back (btnDicePlayer4);
	ses_.push_back (btnDiceEnemy3);
	if (n5_pPlayerReroll->n (3) == int (true)) {
		ses_.push_back (rectDiceSelected3);
	} else {
		delete rectDiceSelected3;
	}
	ses_.push_back (btnDicePlayer3);
	ses_.push_back (btnDiceEnemy2);
	if (n5_pPlayerReroll->n (2) == int (true)) {
		ses_.push_back (rectDiceSelected2);
	} else {
		delete rectDiceSelected2;
	}
	ses_.push_back (btnDicePlayer2);
	ses_.push_back (btnDiceEnemy1);
	if (n5_pPlayerReroll->n (1) == int (true)) {
		ses_.push_back (rectDiceSelected1);
	} else {
		delete rectDiceSelected1;
	}
	ses_.push_back (btnDicePlayer1);
	ses_.push_back (btnDiceEnemy0);
	if (n5_pPlayerReroll->n (0) == int (true)) {
		ses_.push_back (rectDiceSelected0);
	} else {
		delete rectDiceSelected0;
	}
	ses_.push_back (btnDicePlayer0);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		ses_
	);
}
void pokerduel::prepareStage_OKInputSecond (
	const int& nBetAgreed,
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	screenelements& ses_
) {
	screenelement_label* lblHeaderAlertDicePlayerWillKeep = new screenelement_label_generic (
		font_,
		"You decided to keep...", //Finish this later
		screenelement_label_enum::HeaderAlertDicePlayerWillKeep
	);
	screenelement_label* lblHeaderAlertBetMore = new screenelement_label_generic (
		font_,
		"You've each bet $" + std::to_string (nBetAgreed) + " more.",
		screenelement_label_enum::HeaderAlertBetSecond
	);
	screenelement_label* lblHeaderPressingOKInputSecondWillRollSecond = new screenelement_label_generic (
		font_,
		"Pressing OK Input will roll the dice.",
		screenelement_label_enum::HeaderPressingOKInputSecondWillRollSecond
	);
	screenelement_button* btnChangeInputSecond = new screenelement_button_generic (
		font_,
		"Change Input",
		screenelement_button_enum::ChangeInputSecond
	);
	screenelement_button* btnOKInputSecond = new screenelement_button_generic (
		font_,
		"OK Input",
		screenelement_button_enum::OKInputSecond
	);
	float fWidth_lblHeaderAlertDicePlayerWillKeep = lblHeaderAlertDicePlayerWillKeep->frBounds_text ().width;
	float fWidth_lblHeaderAlertBet = lblHeaderAlertBetMore->frBounds_text ().width;
	float fWidth_lblHeaderPressingOKInputSecondWillRollSecond = lblHeaderPressingOKInputSecondWillRollSecond->frBounds_text ().width;
	float fWidth_btnChangeInputSecond = btnChangeInputSecond->frBounds_rs ().width;
	float fPosX_lblHeaderAlertDicePlayerWillKeep = .5f * (1350.f - fWidth_lblHeaderAlertDicePlayerWillKeep);
	float fPosX_lblHeaderAlertBet = .5f * (1350.f - fWidth_lblHeaderAlertBet);
	float fPosX_lblHeaderPressingOKInputSecondWillRollSecond = .5f * (1350.f - fWidth_lblHeaderPressingOKInputSecondWillRollSecond);
	float fPosX_btnChangeInputSecond = .5f * 1350.f  - 10.f - fWidth_btnChangeInputSecond;
	float fPosX_btnOKInputSecond = .5f * 1350.f  + 10.f;
	lblHeaderAlertDicePlayerWillKeep->move (fPosX_lblHeaderAlertDicePlayerWillKeep, 180.f);
	lblHeaderAlertBetMore->move (fPosX_lblHeaderAlertBet, 240.f);
	lblHeaderPressingOKInputSecondWillRollSecond->move (fPosX_lblHeaderPressingOKInputSecondWillRollSecond, 440.f);
	btnChangeInputSecond->move (fPosX_btnChangeInputSecond, 300.f);
	btnOKInputSecond->move (fPosX_btnOKInputSecond, 300.f);
	ses_.push_back (lblHeaderAlertDicePlayerWillKeep);
	ses_.push_back (lblHeaderAlertBetMore);
	ses_.push_back (lblHeaderPressingOKInputSecondWillRollSecond);
	ses_.push_back (btnChangeInputSecond);
	ses_.push_back (btnOKInputSecond);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		ses_
	);
}
void pokerduel::prepareStage_OKResults (
	const int& nCashInPot,
	const int& nCashInPotBefore,
	const int& nScoreEnemyInitial,
	const int& nScoreEnemyUltimate,
	const int& nScorePlayerInitial,
	const int& nScorePlayerUltimate,
	const sf::Font& font_,
	const pokerduelresult*& pokerduelresult_p_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemyInitial,
	const intx5*& n5_pEnemyReroll,
	const intx5*& n5_pEnemyUltimate,
	const intx5*& n5_pPlayerInitial,
	const intx5*& n5_pPlayerReroll,
	const intx5*& n5_pPlayerUltimate,
	screenelements& ses_
) {
	screenelement_label* lblHeaderDiceRolled = new screenelement_label_generic (
		font_,
		"These are the dice rolled:",
		screenelement_label_enum::HeaderDiceRolled
	);
	screenelement_label* lblHeaderDiceEnemy = new screenelement_label_generic (
		font_,
		"Enemy's Dice",
		screenelement_label_enum::HeaderDiceEnemy
	);
	screenelement_label* lblHeaderDicePlayer = new screenelement_label_generic (
		font_,
		"Your Dice",
		screenelement_label_enum::HeaderDicePlayer
	);
	screenelement_label* lblHeaderScoreEnemyInitial = new screenelement_label_generic (
		font_,
		"#" + std::to_string (nScoreEnemyInitial),
		screenelement_label_enum::HeaderScoreEnemyInitial
	);
	screenelement_label* lblHeaderScoreEnemyUltimate = new screenelement_label_generic (
		font_,
		"#" + std::to_string (nScoreEnemyUltimate),
		screenelement_label_enum::HeaderScoreEnemyUltimate
	);
	screenelement_label* lblHeaderScorePlayerInitial = new screenelement_label_generic (
		font_,
		"#" + std::to_string (nScorePlayerInitial),
		screenelement_label_enum::HeaderScorePlayerInitial
	);
	screenelement_label* lblHeaderScorePlayerUltimate = new screenelement_label_generic (
		font_,
		"#" + std::to_string (nScorePlayerUltimate),
		screenelement_label_enum::HeaderScorePlayerUltimate
	);
	screenelement_label* lblHeaderAlertOutcomePlayer = new screenelement_label_header_alert_outcome_player (
		font_,
		pokerduelresult_p_,
		nCashInPotBefore
	);
	screenelement_button* btnDiceEnemyInitial0 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (0),
		screenelement_button_enum::DiceEnemy0
	);
	screenelement_button* btnDiceEnemyInitial1 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (1),
		screenelement_button_enum::DiceEnemy1
	);
	screenelement_button* btnDiceEnemyInitial2 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (2),
		screenelement_button_enum::DiceEnemy2
	);
	screenelement_button* btnDiceEnemyInitial3 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (3),
		screenelement_button_enum::DiceEnemy3
	);
	screenelement_button* btnDiceEnemyInitial4 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (4),
		screenelement_button_enum::DiceEnemy4
	);
	screenelement_button* btnDiceEnemyUltimate0 = new screenelement_button_dice (
		font_,
		n5_pEnemyUltimate->n (0),
		screenelement_button_enum::DiceEnemy0
	);
	screenelement_button* btnDiceEnemyUltimate1 = new screenelement_button_dice (
		font_,
		n5_pEnemyUltimate->n (1),
		screenelement_button_enum::DiceEnemy1
	);
	screenelement_button* btnDiceEnemyUltimate2 = new screenelement_button_dice (
		font_,
		n5_pEnemyUltimate->n (2),
		screenelement_button_enum::DiceEnemy2
	);
	screenelement_button* btnDiceEnemyUltimate3 = new screenelement_button_dice (
		font_,
		n5_pEnemyUltimate->n (3),
		screenelement_button_enum::DiceEnemy3
	);
	screenelement_button* btnDiceEnemyUltimate4 = new screenelement_button_dice (
		font_,
		n5_pEnemyUltimate->n (4),
		screenelement_button_enum::DiceEnemy4
	);
	screenelement_button* btnDicePlayerInitial0 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (0),
		screenelement_button_enum::DicePlayer0
	);
	screenelement_button* btnDicePlayerInitial1 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (1),
		screenelement_button_enum::DicePlayer1
	);
	screenelement_button* btnDicePlayerInitial2 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (2),
		screenelement_button_enum::DicePlayer2
	);
	screenelement_button* btnDicePlayerInitial3 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (3),
		screenelement_button_enum::DicePlayer3
	);
	screenelement_button* btnDicePlayerInitial4 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (4),
		screenelement_button_enum::DicePlayer4
	);
	screenelement_button* btnDicePlayerUltimate0 = new screenelement_button_dice (
		font_,
		n5_pPlayerUltimate->n (0),
		screenelement_button_enum::DicePlayer0
	);
	screenelement_button* btnDicePlayerUltimate1 = new screenelement_button_dice (
		font_,
		n5_pPlayerUltimate->n (1),
		screenelement_button_enum::DicePlayer1
	);
	screenelement_button* btnDicePlayerUltimate2 = new screenelement_button_dice (
		font_,
		n5_pPlayerUltimate->n (2),
		screenelement_button_enum::DicePlayer2
	);
	screenelement_button* btnDicePlayerUltimate3 = new screenelement_button_dice (
		font_,
		n5_pPlayerUltimate->n (3),
		screenelement_button_enum::DicePlayer3
	);
	screenelement_button* btnDicePlayerUltimate4 = new screenelement_button_dice (
		font_,
		n5_pPlayerUltimate->n (4),
		screenelement_button_enum::DicePlayer4
	);
	screenelement_button* btnOKResult = new screenelement_button_generic (
		font_,
		"OK Result",
		screenelement_button_enum::OKResult
	);
	float fWidth_lblHeaderDiceRolled = lblHeaderDiceRolled->frBounds_text ().width;
	float fWidth_lblHeaderDiceEnemy = lblHeaderDiceEnemy->frBounds_text ().width;
	float fWidth_lblHeaderDicePlayer = lblHeaderDicePlayer->frBounds_text ().width;
	float fWidth_lblHeaderScoreEnemyInitial = lblHeaderScoreEnemyInitial->frBounds_text ().width;
	float fWidth_lblHeaderScoreEnemyUltimate = lblHeaderScoreEnemyUltimate->frBounds_text ().width;
	float fWidth_lblHeaderScorePlayerInitial = lblHeaderScorePlayerInitial->frBounds_text ().width;
	float fWidth_lblHeaderScorePlayerUltimate = lblHeaderScorePlayerUltimate->frBounds_text ().width;
	float fWidth_lblHeaderAlertOutcomePlayer = lblHeaderAlertOutcomePlayer->frBounds_text ().width;
	float fWidth_btnDiceEnemyInitial0 = btnDiceEnemyInitial0->frBounds_rs ().width;
	float fWidth_btnDiceEnemyInitial1 = btnDiceEnemyInitial1->frBounds_rs ().width;
	float fWidth_btnDiceEnemyInitial2 = btnDiceEnemyInitial2->frBounds_rs ().width;
	float fWidth_btnDiceEnemyInitial3 = btnDiceEnemyInitial3->frBounds_rs ().width;
	float fWidth_btnDiceEnemyInitial4 = btnDiceEnemyInitial4->frBounds_rs ().width;
	float fWidth_btnDiceEnemyUltimate0 = btnDiceEnemyUltimate0->frBounds_rs ().width;
	float fWidth_btnDiceEnemyUltimate1 = btnDiceEnemyUltimate1->frBounds_rs ().width;
	float fWidth_btnDiceEnemyUltimate2 = btnDiceEnemyUltimate2->frBounds_rs ().width;
	float fWidth_btnDiceEnemyUltimate3 = btnDiceEnemyUltimate3->frBounds_rs ().width;
	float fWidth_btnDiceEnemyUltimate4 = btnDiceEnemyUltimate4->frBounds_rs ().width;
	float fWidth_btnDicePlayerInitial0 = btnDicePlayerInitial0->frBounds_rs ().width;
	float fWidth_btnDicePlayerInitial1 = btnDicePlayerInitial1->frBounds_rs ().width;
	float fWidth_btnDicePlayerInitial2 = btnDicePlayerInitial2->frBounds_rs ().width;
	float fWidth_btnDicePlayerInitial3 = btnDicePlayerInitial3->frBounds_rs ().width;
	float fWidth_btnDicePlayerInitial4 = btnDicePlayerInitial4->frBounds_rs ().width;
	float fWidth_btnDicePlayerUltimate0 = btnDicePlayerUltimate0->frBounds_rs ().width;
	float fWidth_btnDicePlayerUltimate1 = btnDicePlayerUltimate1->frBounds_rs ().width;
	float fWidth_btnDicePlayerUltimate2 = btnDicePlayerUltimate2->frBounds_rs ().width;
	float fWidth_btnDicePlayerUltimate3 = btnDicePlayerUltimate3->frBounds_rs ().width;
	float fWidth_btnDicePlayerUltimate4 = btnDicePlayerUltimate4->frBounds_rs ().width;
	float fWidth_btnOKResult = btnOKResult->frBounds_rs ().width;
	float fPosX_lblHeaderDiceRolled = .5f * (1350.f - fWidth_lblHeaderDiceRolled);
	float fPosX_lblHeaderDiceEnemy = 3.f * 1350.f / 4.f - .5f * fWidth_lblHeaderDiceEnemy;
	float fPosX_lblHeaderDicePlayer = 1350.f / 4.f - .5f * fWidth_lblHeaderDicePlayer;
	float fPosX_lblHeaderScoreEnemyInitial = 4.f * 1350.f / 6.f - .5f * fWidth_lblHeaderScoreEnemyInitial;
	float fPosX_lblHeaderScoreEnemyUltimate = 5.f * 1350.f / 6.f - .5f * fWidth_lblHeaderScoreEnemyUltimate;
	float fPosX_lblHeaderScorePlayerInitial = 1350.f / 6.f - .5f * fWidth_lblHeaderScorePlayerInitial;
	float fPosX_lblHeaderScorePlayerUltimate = 2.f * 1350.f / 6.f - .5f * fWidth_lblHeaderScorePlayerUltimate;
	float fPosX_lblHeaderAlertOutcomePlayer = .5f * (1350.f - fWidth_lblHeaderAlertOutcomePlayer);
	float fPosX_btnDiceEnemyInitial0 = 4.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyInitial0;
	float fPosX_btnDiceEnemyInitial1 = 4.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyInitial1;
	float fPosX_btnDiceEnemyInitial2 = 4.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyInitial2;
	float fPosX_btnDiceEnemyInitial3 = 4.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyInitial3;
	float fPosX_btnDiceEnemyInitial4 = 4.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyInitial4;
	float fPosX_btnDiceEnemyUltimate0 = 5.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyUltimate0;
	float fPosX_btnDiceEnemyUltimate1 = 5.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyUltimate1;
	float fPosX_btnDiceEnemyUltimate2 = 5.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyUltimate2;
	float fPosX_btnDiceEnemyUltimate3 = 5.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyUltimate3;
	float fPosX_btnDiceEnemyUltimate4 = 5.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyUltimate4;
	float fPosX_btnDicePlayerInitial0 = 1350.f / 6.f - .5f * fWidth_btnDicePlayerInitial0;
	float fPosX_btnDicePlayerInitial1 = 1350.f / 6.f - .5f * fWidth_btnDicePlayerInitial1;
	float fPosX_btnDicePlayerInitial2 = 1350.f / 6.f - .5f * fWidth_btnDicePlayerInitial2;
	float fPosX_btnDicePlayerInitial3 = 1350.f / 6.f - .5f * fWidth_btnDicePlayerInitial3;
	float fPosX_btnDicePlayerInitial4 = 1350.f / 6.f - .5f * fWidth_btnDicePlayerInitial4;
	float fPosX_btnDicePlayerUltimate0 = 2.f * 1350.f / 6.f - .5f * fWidth_btnDicePlayerUltimate0;
	float fPosX_btnDicePlayerUltimate1 = 2.f * 1350.f / 6.f - .5f * fWidth_btnDicePlayerUltimate1;
	float fPosX_btnDicePlayerUltimate2 = 2.f * 1350.f / 6.f - .5f * fWidth_btnDicePlayerUltimate2;
	float fPosX_btnDicePlayerUltimate3 = 2.f * 1350.f / 6.f - .5f * fWidth_btnDicePlayerUltimate3;
	float fPosX_btnDicePlayerUltimate4 = 2.f * 1350.f / 6.f - .5f * fWidth_btnDicePlayerUltimate4;
	float fPosX_btnOKResult = .5f * (1350.f - fWidth_btnOKResult);
	lblHeaderDiceRolled->move (fPosX_lblHeaderDiceRolled, 120.f);
	lblHeaderDiceEnemy->move (fPosX_lblHeaderDiceEnemy, 180.f);
	lblHeaderDicePlayer->move (fPosX_lblHeaderDicePlayer, 180.f);
	lblHeaderScoreEnemyInitial->move (fPosX_lblHeaderScoreEnemyInitial, 800.f);
	lblHeaderScoreEnemyUltimate->move (fPosX_lblHeaderScoreEnemyUltimate, 800.f);
	lblHeaderScorePlayerInitial->move (fPosX_lblHeaderScorePlayerInitial, 800.f);
	lblHeaderScorePlayerUltimate->move (fPosX_lblHeaderScorePlayerUltimate, 800.f);
	lblHeaderAlertOutcomePlayer->move (fPosX_lblHeaderAlertOutcomePlayer, 860.f);
	btnDiceEnemyInitial0->move (fPosX_btnDiceEnemyInitial0, 300.f);
	btnDiceEnemyInitial1->move (fPosX_btnDiceEnemyInitial1, 400.f);
	btnDiceEnemyInitial2->move (fPosX_btnDiceEnemyInitial2, 500.f);
	btnDiceEnemyInitial3->move (fPosX_btnDiceEnemyInitial3, 600.f);
	btnDiceEnemyInitial4->move (fPosX_btnDiceEnemyInitial4, 700.f);
	btnDiceEnemyUltimate0->move (fPosX_btnDiceEnemyUltimate0, 300.f);
	btnDiceEnemyUltimate1->move (fPosX_btnDiceEnemyUltimate1, 400.f);
	btnDiceEnemyUltimate2->move (fPosX_btnDiceEnemyUltimate2, 500.f);
	btnDiceEnemyUltimate3->move (fPosX_btnDiceEnemyUltimate3, 600.f);
	btnDiceEnemyUltimate4->move (fPosX_btnDiceEnemyUltimate4, 700.f);
	btnDicePlayerInitial0->move (fPosX_btnDicePlayerInitial0, 300.f);
	btnDicePlayerInitial1->move (fPosX_btnDicePlayerInitial1, 400.f);
	btnDicePlayerInitial2->move (fPosX_btnDicePlayerInitial2, 500.f);
	btnDicePlayerInitial3->move (fPosX_btnDicePlayerInitial3, 600.f);
	btnDicePlayerInitial4->move (fPosX_btnDicePlayerInitial4, 700.f);
	btnDicePlayerUltimate0->move (fPosX_btnDicePlayerUltimate0, 300.f);
	btnDicePlayerUltimate1->move (fPosX_btnDicePlayerUltimate1, 400.f);
	btnDicePlayerUltimate2->move (fPosX_btnDicePlayerUltimate2, 500.f);
	btnDicePlayerUltimate3->move (fPosX_btnDicePlayerUltimate3, 600.f);
	btnDicePlayerUltimate4->move (fPosX_btnDicePlayerUltimate4, 700.f);
	btnOKResult->move (fPosX_btnOKResult, 920.f);
	ses_.push_back (lblHeaderAlertOutcomePlayer);
	ses_.push_back (lblHeaderScoreEnemyUltimate);
	ses_.push_back (lblHeaderScoreEnemyInitial);
	ses_.push_back (lblHeaderScorePlayerUltimate);
	ses_.push_back (lblHeaderScorePlayerInitial);
	ses_.push_back (lblHeaderDiceEnemy);
	ses_.push_back (lblHeaderDicePlayer);
	ses_.push_back (lblHeaderDiceRolled);
	ses_.push_back (btnDiceEnemyUltimate4);
	ses_.push_back (btnDiceEnemyInitial4);
	ses_.push_back (btnDicePlayerUltimate4);
	ses_.push_back (btnDicePlayerInitial4);
	ses_.push_back (btnDiceEnemyUltimate3);
	ses_.push_back (btnDiceEnemyInitial3);
	ses_.push_back (btnDicePlayerUltimate3);
	ses_.push_back (btnDicePlayerInitial3);
	ses_.push_back (btnDiceEnemyUltimate2);
	ses_.push_back (btnDiceEnemyInitial2);
	ses_.push_back (btnDicePlayerUltimate2);
	ses_.push_back (btnDicePlayerInitial2);
	ses_.push_back (btnDiceEnemyUltimate1);
	ses_.push_back (btnDiceEnemyInitial1);
	ses_.push_back (btnDicePlayerUltimate1);
	ses_.push_back (btnDicePlayerInitial1);
	ses_.push_back (btnDiceEnemyUltimate0);
	ses_.push_back (btnDiceEnemyInitial0);
	ses_.push_back (btnDicePlayerUltimate0);
	ses_.push_back (btnDicePlayerInitial0);
	ses_.push_back (btnOKResult);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		ses_
	);
}
void pokerduel::addLabelsCash (
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	screenelements& ses_
) {
	screenelement_label* lblHeaderNameEnemy = new screenelement_label_generic (font_,
		gamedata_pEnemy->sPlayerName (),
		screenelement_label_enum::HeaderNameEnemy
	);
	screenelement_label* lblHeaderNamePlayer = new screenelement_label_generic (font_,
		gamedata_pPlayer->sPlayerName (),
		screenelement_label_enum::HeaderNamePlayer
	);
	screenelement_label* lblHeaderPot = new screenelement_label_generic (font_,
		"Pot",
		screenelement_label_enum::HeaderPot
	);
	screenelement_label* lblHeaderCashEnemy = new screenelement_label_generic (font_,
		std::to_string (gamedata_pEnemy->nDollarsCarried ()),
		screenelement_label_enum::HeaderCashEnemy
	);
	screenelement_label* lblHeaderCashPlayer = new screenelement_label_generic (font_,
		std::to_string (gamedata_pPlayer->nDollarsCarried ()),
		screenelement_label_enum::HeaderCashPlayer
	);
	screenelement_label* lblHeaderCashPot = new screenelement_label_generic (
		font_,
		std::to_string (nCashInPot),
		screenelement_label_enum::HeaderCashPot
	);
	float fWidth_lblHeaderNameEnemy = lblHeaderNameEnemy->frBounds_text ().width;
	float fWidth_lblHeaderNamePlayer = lblHeaderNamePlayer->frBounds_text ().width;
	float fWidth_lblHeaderPot = lblHeaderPot->frBounds_text ().width;
	float fWidth_lblHeaderCashEnemy = lblHeaderCashEnemy->frBounds_text ().width;
	float fWidth_lblHeaderCashPlayer = lblHeaderCashPlayer->frBounds_text ().width;
	float fWidth_lblHeaderCashPot = lblHeaderCashPot->frBounds_text ().width;
	float fPosX_lblHeaderNameEnemy = 1350.f - 25.f - fWidth_lblHeaderNameEnemy;
	float fPosX_lblHeaderNamePlayer = 25.f;
	float fPosX_lblHeaderPot = .5f * (1350.f - fWidth_lblHeaderPot);
	float fPosX_lblHeaderCashEnemy = 1350.f - 25.f - fWidth_lblHeaderCashEnemy;
	float fPosX_lblHeaderCashPlayer = 25.f;
	float fPosX_lblHeaderCashPot = .5f * (1350.f - fWidth_lblHeaderCashPot);
	lblHeaderNameEnemy->move (fPosX_lblHeaderNameEnemy, 0.f);
	lblHeaderNamePlayer->move (fPosX_lblHeaderNamePlayer, 0.f);
	lblHeaderPot->move (fPosX_lblHeaderPot, 0.f);
	lblHeaderCashEnemy->move (fPosX_lblHeaderCashEnemy, 60.f);
	lblHeaderCashPlayer->move (fPosX_lblHeaderCashPlayer, 60.f);
	lblHeaderCashPot->move (fPosX_lblHeaderCashPot, 60.f);
	ses_.push_back (lblHeaderNameEnemy);
	ses_.push_back (lblHeaderNamePlayer);
	ses_.push_back (lblHeaderPot);
	ses_.push_back (lblHeaderCashEnemy);
	ses_.push_back (lblHeaderCashPlayer);
	ses_.push_back (lblHeaderCashPot);
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
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_alert_outcome_player::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderAlertOutcomePlayer;
}
pokerduel::screenelement_label_header_alert_outcome_player::screenelement_label_header_alert_outcome_player (
	const sf::Font& font_,
	const pokerduelresult*& pokerduelresult_p_,
	const int& nCashInPotBefore
) {
	std::string sPlayerOutcome;
	switch (*pokerduelresult_p_) {
		case pokerduelresult::Win: {
			sPlayerOutcome = "won";
			break;
		}
		case pokerduelresult::Tie: {
			sPlayerOutcome = "tied for";
			break;
		}
		case pokerduelresult::Loss: {
			sPlayerOutcome = "lost";
			break;
		}
	}
	set_bIsHeldDown (false);
	create ("You " + sPlayerOutcome + " $" + std::to_string (nCashInPotBefore) + "!", font_, 60, sf::Color::White);
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