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
	screenelement_label* se_lblHeaderPromptBet = new screenelement_label_header_prompt_bet (font_);
	screenelement_button* se_btnBetAmount = new screenelement_button_bet_amount (sBetPlayer, font_);
	screenelement_button* se_btnBetSubmit = new screenelement_button_submit_bet_initial (font_);
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
	screenelement_label* se_lblHeaderAlertBet = new screenelement_label_header_alert_bet (nBetAgreed, font_);
	screenelement_button* se_btnOKBetInitial = new screenelement_button_ok_bet_initial (font_);
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
	screenelement_label* se_lblHeaderNameEnemy = new screenelement_label_header_name_enemy (font_, gamedata_pEnemy);
	screenelement_label* se_lblHeaderNamePlayer = new screenelement_label_header_name_player (font_, gamedata_pPlayer);
	screenelement_label* se_lblHeaderPot = new screenelement_label_header_pot (font_);
	screenelement_label* se_lblHeaderCashEnemy = new screenelement_label_header_cash_enemy (font_, gamedata_pEnemy);
	screenelement_label* se_lblHeaderCashPlayer = new screenelement_label_header_cash_player (font_, gamedata_pPlayer);
	screenelement_label* se_lblHeaderCashPot = new screenelement_label_header_cash_pot (font_, nCashInPot);
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
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_name_enemy::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderNameEnemy;
}
pokerduel::screenelement_label_header_name_enemy::screenelement_label_header_name_enemy (
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy
) {
	set_bIsHeldDown (false);
	create (gamedata_pEnemy->sPlayerName (), font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_name_player::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderNamePlayer;
}
pokerduel::screenelement_label_header_name_player::screenelement_label_header_name_player (
	const sf::Font& font_,
	const gamedata*& gamedata_pPlayer
) {
	set_bIsHeldDown (false);
	create (gamedata_pPlayer->sPlayerName (), font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_pot::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderPot;
}
pokerduel::screenelement_label_header_pot::screenelement_label_header_pot (
	const sf::Font& font_
) {
	set_bIsHeldDown (false);
	create ("Pot", font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_cash_enemy::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderCashEnemy;
}
pokerduel::screenelement_label_header_cash_enemy::screenelement_label_header_cash_enemy (
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy
) {
	set_bIsHeldDown (false);
	create (std::to_string (gamedata_pEnemy->nDollarsCarried ()), font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_cash_player::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderCashPlayer;
}
pokerduel::screenelement_label_header_cash_player::screenelement_label_header_cash_player (
	const sf::Font& font_,
	const gamedata*& gamedata_pPlayer
) {
	set_bIsHeldDown (false);
	create (std::to_string (gamedata_pPlayer->nDollarsCarried ()), font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_cash_pot::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderCashPot;
}
pokerduel::screenelement_label_header_cash_pot::screenelement_label_header_cash_pot (
	const sf::Font& font_,
	const int& nCashPot
) {
	set_bIsHeldDown (false);
	create (std::to_string (nCashPot), font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_prompt_bet::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderPromptBet;
}
pokerduel::screenelement_label_header_prompt_bet::screenelement_label_header_prompt_bet (
	const sf::Font& font_
) {
	set_bIsHeldDown (false);
	create ("Enter Your Bet:", font_, 60, sf::Color::White);
}
pokerduel::screenelement_label_enum pokerduel::screenelement_label_header_alert_bet::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderAlertBet;
}
pokerduel::screenelement_label_header_alert_bet::screenelement_label_header_alert_bet (
	const int& nBetAgreed,
	const sf::Font& font_
) {
	set_bIsHeldDown (false);
	create ("You've each bet $" + std::to_string (nBetAgreed) + ".", font_, 60, sf::Color::White);
}
pokerduel::screenelement_button_enum pokerduel::screenelement_button_bet_amount::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::BetAmount;
}
pokerduel::screenelement_button_bet_amount::screenelement_button_bet_amount (
	const std::string& sBetPlayer,
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("$" + sBetPlayer, fontToUse, 60, sf::Color::White, sf::Color::Black);
	stretch (360.f, 120.f);
}
pokerduel::screenelement_button_enum pokerduel::screenelement_button_submit_bet_initial::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::SubmitBetInitial;
}
pokerduel::screenelement_button_submit_bet_initial::screenelement_button_submit_bet_initial (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Submit", fontToUse, 60, sf::Color::White, sf::Color::Black);
	stretch (360.f, 120.f);
}
pokerduel::screenelement_button_enum pokerduel::screenelement_button_ok_bet_initial::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::OKBetInitial;
}
pokerduel::screenelement_button_ok_bet_initial::screenelement_button_ok_bet_initial (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("OK", fontToUse, 60, sf::Color::White, sf::Color::Black);
	stretch (360.f, 120.f);
}