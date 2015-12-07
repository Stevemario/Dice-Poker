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
	const intx5*& n5_pPlayer,
	const intx5*& n5_pPlayerInitial,
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
		case pokerduelstage::AlertBetInitial: {
			prepareStage_AlertBetInitial (
				nBetAgreed,
				nCashInPot,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				vec_screenelement_p_
			);
			break;
		}
		case pokerduelstage::RollInitial: {
			prepareStage_RollInitial (
				nCashInPot,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				vec_screenelement_p_
			);
			break;
		}
		case pokerduelstage::RollRedo: {
			prepareStage_RollRedo (
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
		case pokerduelstage::BetRaise: {
			prepareStage_BetRaise (
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
		case pokerduelstage::Conclusion: {
			prepareStage_Conclusion (
				nCashInPot,
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				n5_pEnemy,
				n5_pEnemyInitial,
				n5_pPlayer,
				n5_pPlayerInitial,
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
		screenelement_label_enum::HeaderPromptBet
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
	float fWidth_lblHeaderPromptBet = se_lblHeaderPromptBet->text_ ().getGlobalBounds ().width;
	float fWidth_btnBetAmount = se_btnBetAmount->rs_ ().getGlobalBounds ().width;
	float fWidth_btnBetSubmit = se_btnBetSubmit->rs_ ().getGlobalBounds ().width;
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
void pokerduel::prepareStage_AlertBetInitial (
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
	screenelement_button* se_btnOKBetInitial = new screenelement_button_generic (
		font_,
		"OK",
		screenelement_button_enum::OKBetInitial
	);
	float fWidth_lblHeaderAlertBet = se_lblHeaderAlertBet->text_ ().getGlobalBounds ().width;
	float fWidth_btnOKBetInitial = se_btnOKBetInitial->rs_ ().getGlobalBounds ().width;
	float fPosX_lblHeaderAlertBet = .5f * (1350.f - fWidth_lblHeaderAlertBet);
	float fPosX_btnOKBetInitial = .5f * (1350.f - fWidth_btnOKBetInitial);
	se_lblHeaderAlertBet->move (fPosX_lblHeaderAlertBet, 300.f);
	se_btnOKBetInitial->move (fPosX_btnOKBetInitial, 360.f);
	vec_screenelement_p_.push_back (se_lblHeaderAlertBet);
	vec_screenelement_p_.push_back (se_btnOKBetInitial);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		vec_screenelement_p_
	);
}
void pokerduel::prepareStage_RollInitial (
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
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
	float fWidth_lblHeaderDiceRolled = se_lblHeaderDiceRolled->text_ ().getGlobalBounds ().width;
	float fWidth_lblHeaderDiceEnemy = se_lblHeaderDiceEnemy->text_ ().getGlobalBounds ().width;
	float fWidth_lblHeaderDicePlayer = se_lblHeaderDicePlayer->text_ ().getGlobalBounds ().width;
	float fWidth_lblHeaderSelectDiceToReroll = se_lblHeaderSelectDiceToReroll->text_ ().getGlobalBounds ().width;
	float fPosX_lblHeaderDiceRolled = .5f * (1350.f - fWidth_lblHeaderDiceRolled);
	float fPosX_lblHeaderDiceEnemy = 2.f * 1350.f / 3.f - .5f * fWidth_lblHeaderDiceEnemy;
	float fPosX_lblHeaderDicePlayer = 1350.f / 3.f - .5f * fWidth_lblHeaderDicePlayer;
	float fPosX_lblHeaderSelectDiceToReroll = .5f * (1350.f - fWidth_lblHeaderSelectDiceToReroll);
	se_lblHeaderDiceRolled->move (fPosX_lblHeaderDiceRolled, 180.f);
	se_lblHeaderDiceEnemy->move (fPosX_lblHeaderDiceEnemy, 240.f);
	se_lblHeaderDicePlayer->move (fPosX_lblHeaderDicePlayer, 240.f);
	se_lblHeaderSelectDiceToReroll->move (fPosX_lblHeaderSelectDiceToReroll, 1000.f);
	vec_screenelement_p_.push_back (se_lblHeaderDiceRolled);
	vec_screenelement_p_.push_back (se_lblHeaderDiceEnemy);
	vec_screenelement_p_.push_back (se_lblHeaderDicePlayer);
	vec_screenelement_p_.push_back (se_lblHeaderSelectDiceToReroll);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		vec_screenelement_p_
	);
}
void pokerduel::prepareStage_RollRedo (
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
void pokerduel::prepareStage_BetRaise (
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
void pokerduel::prepareStage_Conclusion (
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemy,
	const intx5*& n5_pEnemyInitial,
	const intx5*& n5_pPlayer,
	const intx5*& n5_pPlayerInitial,
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
	float fWidth_lblHeaderNameEnemy = se_lblHeaderNameEnemy->text_ ().getGlobalBounds ().width;
	float fWidth_lblHeaderNamePlayer = se_lblHeaderNamePlayer->text_ ().getGlobalBounds ().width;
	float fWidth_lblHeaderPot = se_lblHeaderPot->text_ ().getGlobalBounds ().width;
	float fWidth_lblHeaderCashEnemy = se_lblHeaderCashEnemy->text_ ().getGlobalBounds ().width;
	float fWidth_lblHeaderCashPlayer = se_lblHeaderCashPlayer->text_ ().getGlobalBounds ().width;
	float fWidth_lblHeaderCashPot = se_lblHeaderCashPot->text_ ().getGlobalBounds ().width;
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
	stretch (rs_ ().getGlobalBounds ().width + 24.f, 120.f);
}