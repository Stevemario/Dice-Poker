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
				n5_pPlayerInitial,
				n5_pPlayerReroll,
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
		screenelement_label_enum::HeaderPromptBetInitial
	);
	screenelement_button* btnBetAmount = new screenelement_button_bet_amount (
		font_,
		sBetPlayer
	);
	screenelement_button* btnSubmitInputInitial = new screenelement_button_generic (
		font_,
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
	screenelement_label* lblHeaderAlertBet = new screenelement_label_header_alert_bet (
		font_,
		nBetAgreed,
		true
	);
	screenelement_label* lblHeaderPressingRollWillOKBet = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderPressingRollWillOKBet
	);
	screenelement_button* btnChangeInputInitial = new screenelement_button_generic (
		font_,
		screenelement_button_enum::ChangeInputInitial
	);
	screenelement_button* btnOKInputInitial = new screenelement_button_generic (
		font_,
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
		screenelement_label_enum::HeaderDiceRolled
	);
	screenelement_label* lblHeaderDiceEnemy = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceEnemy
	);
	screenelement_label* lblHeaderDicePlayer = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDicePlayer
	);
	screenelement_label* lblHeaderSelectDiceToReroll = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderSelectDiceToReroll
	);
	screenelement_label* lblHeaderPromptBetSecond = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderPromptBetSecond
	);
	screenelement_button* btnDiceEnemy0 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (0),
		true,
		0
	);
	screenelement_button* btnDiceEnemy1 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (1),
		true,
		1
	);
	screenelement_button* btnDiceEnemy2 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (2),
		true,
		2
	);
	screenelement_button* btnDiceEnemy3 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (3),
		true,
		3
	);
	screenelement_button* btnDiceEnemy4 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (4),
		true,
		4
	);
	screenelement_button* btnDicePlayer0 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (0),
		false,
		0
	);
	screenelement_button* btnDicePlayer1 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (1),
		false,
		1
	);
	screenelement_button* btnDicePlayer2 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (2),
		false,
		2
	);
	screenelement_button* btnDicePlayer3 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (3),
		false,
		3
	);
	screenelement_button* btnDicePlayer4 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (4),
		false,
		4
	);
	screenelement_button* btnBetAmount = new screenelement_button_bet_amount (
		font_,
		sBetPlayer
	);
	screenelement_button* btnSubmitInputSecond = new screenelement_button_generic (
		font_,
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
	const intx5*& n5_pPlayerInitial,
	const intx5*& n5_pPlayerReroll,
	screenelements& ses_
) {
	screenelement_label* lblHeaderAlertDicePlayerWillKeep = new screenelement_label_header_alert_dice_player_will_keep (
		font_,
		n5_pPlayerInitial,
		n5_pPlayerReroll
	);
	screenelement_label* lblHeaderAlertBetMore = new screenelement_label_header_alert_bet (
		font_,
		nBetAgreed,
		false
	);
	screenelement_label* lblHeaderPressingOKInputSecondWillRollSecond = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderPressingOKInputSecondWillRollSecond
	);
	screenelement_button* btnChangeInputSecond = new screenelement_button_generic (
		font_,
		screenelement_button_enum::ChangeInputSecond
	);
	screenelement_button* btnOKInputSecond = new screenelement_button_generic (
		font_,
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
		screenelement_label_enum::HeaderDiceRolled
	);
	screenelement_label* lblHeaderDiceEnemy = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceEnemy
	);
	screenelement_label* lblHeaderDicePlayer = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDicePlayer
	);
	screenelement_label* lblHeaderDiceInitialEnemy = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceInitial
	);
	screenelement_label* lblHeaderDiceInitialPlayer = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceInitial
	);
	screenelement_label* lblHeaderDiceUltimateEnemy = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceUltimate
	);
	screenelement_label* lblHeaderDiceUltimatePlayer = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceUltimate
	);
	screenelement_label* lblHeaderAlertRerollEnemy0 = new screenelement_label_header_alert_reroll (
		font_,
		n5_pEnemyReroll,
		0
	);
	screenelement_label* lblHeaderAlertRerollEnemy1 = new screenelement_label_header_alert_reroll (
		font_,
		n5_pEnemyReroll,
		1
	);
	screenelement_label* lblHeaderAlertRerollEnemy2 = new screenelement_label_header_alert_reroll (
		font_,
		n5_pEnemyReroll,
		2
	);
	screenelement_label* lblHeaderAlertRerollEnemy3 = new screenelement_label_header_alert_reroll (
		font_,
		n5_pEnemyReroll,
		3
	);
	screenelement_label* lblHeaderAlertRerollEnemy4 = new screenelement_label_header_alert_reroll (
		font_,
		n5_pEnemyReroll,
		4
	);
	screenelement_label* lblHeaderAlertRerollPlayer0 = new screenelement_label_header_alert_reroll (
		font_,
		n5_pPlayerReroll,
		0
	);
	screenelement_label* lblHeaderAlertRerollPlayer1 = new screenelement_label_header_alert_reroll (
		font_,
		n5_pPlayerReroll,
		1
	);
	screenelement_label* lblHeaderAlertRerollPlayer2 = new screenelement_label_header_alert_reroll (
		font_,
		n5_pPlayerReroll,
		2
	);
	screenelement_label* lblHeaderAlertRerollPlayer3 = new screenelement_label_header_alert_reroll (
		font_,
		n5_pPlayerReroll,
		3
	);
	screenelement_label* lblHeaderAlertRerollPlayer4 = new screenelement_label_header_alert_reroll (
		font_,
		n5_pPlayerReroll,
		4
	);
	screenelement_label* lblHeaderScoreEnemyInitial = new screenelement_label_header_score (
		font_,
		nScoreEnemyInitial,
		true,
		true
	);
	screenelement_label* lblHeaderScoreEnemyUltimate = new screenelement_label_header_score (
		font_,
		nScoreEnemyUltimate,
		true,
		false
	);
	screenelement_label* lblHeaderScorePlayerInitial = new screenelement_label_header_score (
		font_,
		nScorePlayerInitial,
		false,
		true
	);
	screenelement_label* lblHeaderScorePlayerUltimate = new screenelement_label_header_score (
		font_,
		nScorePlayerUltimate,
		false,
		false
	);
	screenelement_label* lblHeaderAlertOutcomePlayer = new screenelement_label_header_alert_outcome_player (
		font_,
		pokerduelresult_p_,
		nCashInPotBefore
	);
	screenelement_button* btnDiceEnemyInitial0 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (0),
		true,
		0
	);
	screenelement_button* btnDiceEnemyInitial1 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (1),
		true,
		1
	);
	screenelement_button* btnDiceEnemyInitial2 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (2),
		true,
		2
	);
	screenelement_button* btnDiceEnemyInitial3 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (3),
		true,
		3
	);
	screenelement_button* btnDiceEnemyInitial4 = new screenelement_button_dice (
		font_,
		n5_pEnemyInitial->n (4),
		true,
		4
	);
	screenelement_button* btnDiceEnemyUltimate0 = new screenelement_button_dice (
		font_,
		n5_pEnemyUltimate->n (0),
		true,
		0
	);
	screenelement_button* btnDiceEnemyUltimate1 = new screenelement_button_dice (
		font_,
		n5_pEnemyUltimate->n (1),
		true,
		1
	);
	screenelement_button* btnDiceEnemyUltimate2 = new screenelement_button_dice (
		font_,
		n5_pEnemyUltimate->n (2),
		true,
		2
	);
	screenelement_button* btnDiceEnemyUltimate3 = new screenelement_button_dice (
		font_,
		n5_pEnemyUltimate->n (3),
		true,
		3
	);
	screenelement_button* btnDiceEnemyUltimate4 = new screenelement_button_dice (
		font_,
		n5_pEnemyUltimate->n (4),
		true,
		4
	);
	screenelement_button* btnDicePlayerInitial0 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (0),
		false,
		0
	);
	screenelement_button* btnDicePlayerInitial1 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (1),
		false,
		1
	);
	screenelement_button* btnDicePlayerInitial2 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (2),
		false,
		2
	);
	screenelement_button* btnDicePlayerInitial3 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (3),
		false,
		3
	);
	screenelement_button* btnDicePlayerInitial4 = new screenelement_button_dice (
		font_,
		n5_pPlayerInitial->n (4),
		false,
		4
	);
	screenelement_button* btnDicePlayerUltimate0 = new screenelement_button_dice (
		font_,
		n5_pPlayerUltimate->n (0),
		false,
		1
	);
	screenelement_button* btnDicePlayerUltimate1 = new screenelement_button_dice (
		font_,
		n5_pPlayerUltimate->n (1),
		false,
		1
	);
	screenelement_button* btnDicePlayerUltimate2 = new screenelement_button_dice (
		font_,
		n5_pPlayerUltimate->n (2),
		false,
		2
	);
	screenelement_button* btnDicePlayerUltimate3 = new screenelement_button_dice (
		font_,
		n5_pPlayerUltimate->n (3),
		false,
		3
	);
	screenelement_button* btnDicePlayerUltimate4 = new screenelement_button_dice (
		font_,
		n5_pPlayerUltimate->n (4),
		false,
		4
	);
	screenelement_button* btnOKResult = new screenelement_button_generic (
		font_,
		screenelement_button_enum::OKResult
	);
	float fWidth_lblHeaderDiceRolled = lblHeaderDiceRolled->frBounds_text ().width;
	float fWidth_lblHeaderDiceEnemy = lblHeaderDiceEnemy->frBounds_text ().width;
	float fWidth_lblHeaderDicePlayer = lblHeaderDicePlayer->frBounds_text ().width;
	float fWidth_lblHeaderDiceInitialEnemy = lblHeaderDiceInitialEnemy->frBounds_text ().width;
	float fWidth_lblHeaderDiceInitialPlayer = lblHeaderDiceInitialPlayer->frBounds_text ().width;
	float fWidth_lblHeaderDiceUltimateEnemy = lblHeaderDiceUltimateEnemy->frBounds_text ().width;
	float fWidth_lblHeaderDiceUltimatePlayer = lblHeaderDiceUltimatePlayer->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollEnemy0 = lblHeaderAlertRerollEnemy0->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollEnemy1 = lblHeaderAlertRerollEnemy1->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollEnemy2 = lblHeaderAlertRerollEnemy2->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollEnemy3 = lblHeaderAlertRerollEnemy3->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollEnemy4 = lblHeaderAlertRerollEnemy4->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollPlayer0 = lblHeaderAlertRerollPlayer0->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollPlayer1 = lblHeaderAlertRerollPlayer1->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollPlayer2 = lblHeaderAlertRerollPlayer2->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollPlayer3 = lblHeaderAlertRerollPlayer3->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollPlayer4 = lblHeaderAlertRerollPlayer4->frBounds_text ().width;
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
	float fPosX_lblHeaderDiceInitialEnemy = 4.f * 1350.f / 6.f - .5f * fWidth_lblHeaderDiceInitialEnemy;
	float fPosX_lblHeaderDiceInitialPlayer = 1350.f / 6.f - .5f * fWidth_lblHeaderDiceInitialPlayer;
	float fPosX_lblHeaderDiceUltimateEnemy = 5.f * 1350.f / 6.f - .5f * fWidth_lblHeaderDiceUltimateEnemy;
	float fPosX_lblHeaderDiceUltimatePlayer = 2.f * 1350.f / 6.f - .5f * fWidth_lblHeaderDiceUltimatePlayer;
	float fPosX_lblHeaderAlertRerollEnemy0 = 9.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollEnemy0;
	float fPosX_lblHeaderAlertRerollEnemy1 = 9.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollEnemy1;
	float fPosX_lblHeaderAlertRerollEnemy2 = 9.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollEnemy2;
	float fPosX_lblHeaderAlertRerollEnemy3 = 9.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollEnemy3;
	float fPosX_lblHeaderAlertRerollEnemy4 = 9.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollEnemy4;
	float fPosX_lblHeaderAlertRerollPlayer0 = 3.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollPlayer0;
	float fPosX_lblHeaderAlertRerollPlayer1 = 3.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollPlayer1;
	float fPosX_lblHeaderAlertRerollPlayer2 = 3.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollPlayer2;
	float fPosX_lblHeaderAlertRerollPlayer3 = 3.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollPlayer3;
	float fPosX_lblHeaderAlertRerollPlayer4 = 3.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollPlayer4;
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
	lblHeaderDiceInitialEnemy->move (fPosX_lblHeaderDiceInitialEnemy, 240.f);
	lblHeaderDiceInitialPlayer->move (fPosX_lblHeaderDiceInitialPlayer, 240.f);
	lblHeaderDiceUltimateEnemy->move (fPosX_lblHeaderDiceUltimateEnemy, 240.f);
	lblHeaderDiceUltimatePlayer->move (fPosX_lblHeaderDiceUltimatePlayer, 240.f);
	lblHeaderAlertRerollEnemy0->move (fPosX_lblHeaderAlertRerollEnemy0, 320.f);
	lblHeaderAlertRerollEnemy1->move (fPosX_lblHeaderAlertRerollEnemy1, 420.f);
	lblHeaderAlertRerollEnemy2->move (fPosX_lblHeaderAlertRerollEnemy2, 520.f);
	lblHeaderAlertRerollEnemy3->move (fPosX_lblHeaderAlertRerollEnemy3, 620.f);
	lblHeaderAlertRerollEnemy4->move (fPosX_lblHeaderAlertRerollEnemy4, 720.f);
	lblHeaderAlertRerollPlayer0->move (fPosX_lblHeaderAlertRerollPlayer0, 320.f);
	lblHeaderAlertRerollPlayer1->move (fPosX_lblHeaderAlertRerollPlayer1, 420.f);
	lblHeaderAlertRerollPlayer2->move (fPosX_lblHeaderAlertRerollPlayer2, 520.f);
	lblHeaderAlertRerollPlayer3->move (fPosX_lblHeaderAlertRerollPlayer3, 620.f);
	lblHeaderAlertRerollPlayer4->move (fPosX_lblHeaderAlertRerollPlayer4, 720.f);
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
	ses_.push_back (lblHeaderAlertRerollEnemy4);
	ses_.push_back (lblHeaderAlertRerollPlayer4);
	ses_.push_back (lblHeaderAlertRerollEnemy3);
	ses_.push_back (lblHeaderAlertRerollPlayer3);
	ses_.push_back (lblHeaderAlertRerollEnemy2);
	ses_.push_back (lblHeaderAlertRerollPlayer2);
	ses_.push_back (lblHeaderAlertRerollEnemy1);
	ses_.push_back (lblHeaderAlertRerollPlayer1);
	ses_.push_back (lblHeaderAlertRerollEnemy0);
	ses_.push_back (lblHeaderAlertRerollPlayer0);
	ses_.push_back (lblHeaderDiceUltimateEnemy);
	ses_.push_back (lblHeaderDiceInitialEnemy);
	ses_.push_back (lblHeaderDiceUltimatePlayer);
	ses_.push_back (lblHeaderDiceInitialPlayer);
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
	screenelement_label* lblHeaderNameEnemy = new screenelement_label_header_name (
		font_,
		gamedata_pEnemy,
		true
	);
	screenelement_label* lblHeaderNamePlayer = new screenelement_label_header_name (
		font_,
		gamedata_pPlayer,
		false
	);
	screenelement_label* lblHeaderPot = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderPot
	);
	screenelement_label* lblHeaderCashEnemy = new screenelement_label_header_cash (
		font_,
		gamedata_pEnemy,
		true
	);
	screenelement_label* lblHeaderCashPlayer = new screenelement_label_header_cash (
		font_,
		gamedata_pPlayer,
		false
	);
	screenelement_label* lblHeaderCashPot = new screenelement_label_header_cash_pot (
		font_,
		nCashInPot
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
	const screenelement_label_enum& screenelement_label_enum_
) {
	std::string s_;
	switch (screenelement_label_enum_) {
		case screenelement_label_enum::HeaderPot: { s_ = "Pot"; break; }
		case screenelement_label_enum::HeaderPromptBetInitial: { s_ = "Enter Your Bet:"; break; }
		case screenelement_label_enum::HeaderPressingRollWillOKBet: { s_ = "Pressing OK Bet will roll the dice."; break; }
		case screenelement_label_enum::HeaderDiceRolled: { s_ = "These are the dice rolled:"; break; }
		case screenelement_label_enum::HeaderDiceEnemy: { s_ = "Enemy's Dice"; break; }
		case screenelement_label_enum::HeaderDicePlayer: { s_ = "Your Dice"; break; }
		case screenelement_label_enum::HeaderSelectDiceToReroll: { s_ = "You may select dice to reroll."; break; }
		case screenelement_label_enum::HeaderPromptBetSecond: { s_ = "Bet:"; break; }
		case screenelement_label_enum::HeaderPressingOKInputSecondWillRollSecond: { s_ = "Pressing OK Input will roll the dice.";
			break; }
		case screenelement_label_enum::HeaderDiceInitial: { s_ = "#1"; break; }
		case screenelement_label_enum::HeaderDiceUltimate: { s_ = "#2"; break; }
		default: { s_ = "UNDEFINED"; break; }
	}
	set_bIsHeldDown (false);
	m_screenelement_label_enum = screenelement_label_enum_;
	create (s_, font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_name::screenelement_label_enum_ (
) const {
	return m_screenelement_label_enum;
}
pokerduel::screenelement_label_header_name::screenelement_label_header_name (
	const sf::Font& font_,
	const gamedata*& gamedata_p_,
	const bool& bNameEnemy
) {
	std::string s_ = gamedata_p_->sPlayerName ();
	set_bIsHeldDown (false);
	if (bNameEnemy)
		m_screenelement_label_enum = screenelement_label_enum::HeaderNameEnemy;
	else
		m_screenelement_label_enum = screenelement_label_enum::HeaderNamePlayer;
	create (s_, font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_cash::screenelement_label_enum_ (
) const {
	return m_screenelement_label_enum;
}
pokerduel::screenelement_label_header_cash::screenelement_label_header_cash (
	const sf::Font& font_,
	const gamedata*& gamedata_p_,
	const bool& bCashEnemy
) {
	std::string s_ = "$" + std::to_string (gamedata_p_->nDollarsCarried ());
	set_bIsHeldDown (false);
	if (bCashEnemy)
		m_screenelement_label_enum = screenelement_label_enum::HeaderCashEnemy;
	else
		m_screenelement_label_enum = screenelement_label_enum::HeaderCashPlayer;
	create (s_, font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_cash_pot::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderCashPot;
}
pokerduel::screenelement_label_header_cash_pot::screenelement_label_header_cash_pot (
	const sf::Font& font_,
	const int& nCashInPot
) {
	std::string s_ = "$" + std::to_string (nCashInPot);
	set_bIsHeldDown (false);
	create (s_, font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_alert_bet::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderAlertBet;
}
pokerduel::screenelement_label_header_alert_bet::screenelement_label_header_alert_bet (
	const sf::Font& font_,
	const int& nBetAgreed,
	const bool& bBetInitial
) {
	std::string s_ = "You've each bet $" + std::to_string (nBetAgreed) + (bBetInitial ? "." : " more.");
	set_bIsHeldDown (false);
	create (s_, font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_alert_dice_player_will_keep::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderAlertDicePlayerWillKeep;
}
pokerduel::screenelement_label_header_alert_dice_player_will_keep::screenelement_label_header_alert_dice_player_will_keep (
	const sf::Font& font_,
	const intx5*& n5_pDicePlayerInitial,
	const intx5*& n5_pDicePlayerReroll
) {
	int nDiceKept;
	std::string s_ = "You decided to keep ";
	std::vector<int> vec_nDiceKept;
	for (int i = 0; i < 5; i++) {
		if (n5_pDicePlayerReroll-> n(i) != int (true))
			vec_nDiceKept.push_back (n5_pDicePlayerInitial-> n(i));
	}
	nDiceKept = vec_nDiceKept.size ();
	if (nDiceKept == 0) {
		s_ += "none of your dice.";
	} else if (nDiceKept == 1) {
		s_ += "a dice showing " +
			std::to_string (vec_nDiceKept[0]) + ".";
	} else if (nDiceKept == 2) {
		s_ += "dice showing " +
			std::to_string (vec_nDiceKept[0]) + " and " +
			std::to_string (vec_nDiceKept[1]) + ".";
	} else if (nDiceKept == 3) {
		s_ += "dice showing " +
			std::to_string (vec_nDiceKept[0]) + ", " +
			std::to_string (vec_nDiceKept[1]) + " and " +
			std::to_string (vec_nDiceKept[2]) + ".";
	} else if (nDiceKept == 4) {
		s_ += "dice showing " +
			std::to_string (vec_nDiceKept[0]) + ", " +
			std::to_string (vec_nDiceKept[1]) + ", " +
			std::to_string (vec_nDiceKept[2]) + " and " +
			std::to_string (vec_nDiceKept[3]) + ".";
	} else {
		s_ += "all of your dice.";
	}
	set_bIsHeldDown (false);
	create (s_, font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_alert_reroll::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderAlertReroll;
}
pokerduel::screenelement_label_header_alert_reroll::screenelement_label_header_alert_reroll (
	const sf::Font& font_,
	const intx5*& n5Reroll,
	const int& nDiceIndex
) {
	bool bRerolled = n5Reroll->n (nDiceIndex) == int (true);
	set_bIsHeldDown (false);
	create (bRerolled ? "ROLL" : "->", font_, 40, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_score::screenelement_label_enum_ (
) const {
	return m_screenelement_label_enum;
}
pokerduel::screenelement_label_header_score::screenelement_label_header_score (
	const sf::Font& font_,
	const int& nScore,
	const bool& bScoreEnemy,
	const bool& bScoreInitial
) {
	std::string s_ = "#" + std::to_string (nScore);
	if (bScoreEnemy) {
		if (bScoreInitial)
			m_screenelement_label_enum = screenelement_label_enum::HeaderScoreEnemyInitial;
		else
			m_screenelement_label_enum = screenelement_label_enum::HeaderScoreEnemyUltimate;
	} else {
		if (bScoreInitial)
			m_screenelement_label_enum = screenelement_label_enum::HeaderScorePlayerInitial;
		else
			m_screenelement_label_enum = screenelement_label_enum::HeaderScorePlayerUltimate;
	}
	set_bIsHeldDown (false);
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
	const screenelement_button_enum& screenelement_button_enum_
) {
	std::string s_;
	switch (screenelement_button_enum_) {
		case screenelement_button_enum::SubmitInputInitial: { s_ = "Submit"; break; };
		case screenelement_button_enum::ChangeInputInitial: { s_ = "Change Bet"; break; };
		case screenelement_button_enum::OKInputInitial: { s_ = "OK Bet"; break; };
		case screenelement_button_enum::SubmitInputSecond: { s_ = "Submit Input"; break; };
		case screenelement_button_enum::ChangeInputSecond: { s_ = "Change Input"; break; };
		case screenelement_button_enum::OKInputSecond: { s_ = "OK Input"; break; };
		case screenelement_button_enum::OKResult: { s_ = "OK Result"; break; };
		default: { s_ = "UNDEFINED"; };
	}
	set_bIsHeldDown (false);
	m_screenelement_button_enum = screenelement_button_enum_;
	create (s_, font_, 60, sf::Color::White, sf::Color::Black);
	stretch (frBounds_rs ().width + 24.f, 120.f);
}
pokerduel::screenelement_button_enum pokerduel::screenelement_button_bet_amount::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::BetAmount;
}
pokerduel::screenelement_button_bet_amount::screenelement_button_bet_amount (
	const sf::Font& font_,
	const std::string& sBetPlayer
) {
	std::string s_ = "$" + sBetPlayer;
	set_bIsHeldDown (false);
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
	const bool& bEnemy,
	const int& nDiceIndex
) {
	set_bIsHeldDown (false);
	if (bEnemy) {
		switch (nDiceIndex) {
			case 0: { m_screenelement_button_enum = screenelement_button_enum::DiceEnemy0; break; }
			case 1: { m_screenelement_button_enum = screenelement_button_enum::DiceEnemy1; break; }
			case 2: { m_screenelement_button_enum = screenelement_button_enum::DiceEnemy2; break; }
			case 3: { m_screenelement_button_enum = screenelement_button_enum::DiceEnemy3; break; }
			case 4: { m_screenelement_button_enum = screenelement_button_enum::DiceEnemy4; break; }
		}
	} else {
		switch (nDiceIndex) {
			case 0: { m_screenelement_button_enum = screenelement_button_enum::DicePlayer0; break; }
			case 1: { m_screenelement_button_enum = screenelement_button_enum::DicePlayer1; break; }
			case 2: { m_screenelement_button_enum = screenelement_button_enum::DicePlayer2; break; }
			case 3: { m_screenelement_button_enum = screenelement_button_enum::DicePlayer3; break; }
			case 4: { m_screenelement_button_enum = screenelement_button_enum::DicePlayer4; break; }
		}
	}
	create (std::to_string (n_), font_, 40, sf::Color::White, sf::Color::Black);
	stretch (frBounds_rs ().width + 16.f, 80.f);
}