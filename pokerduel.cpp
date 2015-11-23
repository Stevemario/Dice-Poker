#include "pokerduel.h"
void pokerduel::work (
	int& nCashInPot,
	bool& bHaveGameData,
	bool& bPrepared_vec_screenelement_p,
	const sf::Font& font_,
	sf::RenderWindow& rw_,
	gameaction& gameaction_,
	pokerduelstage*& pokerduelstage_p_,
	gamedata*& gamedata_pEnemy,
	gamedata*& gamedata_pPlayer,
	intx5*& n5_pEnemy,
	intx5*& n5_pEnemyInitial,
	intx5*& n5_pPlayer,
	intx5*& n5_pPlayerInitial,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	bool bShouldClear_vec_screenelement_p = false;
	sf::Event event_;
	if (bHaveGameData != true) {
		nCashInPot = 0;
		pokerduelstage_p_ = new pokerduelstage;
		gamedata_pEnemy = new gamedata ("Steve's Bot");
		gamedata_pPlayer = new gamedata ("Player");
		*pokerduelstage_p_ = pokerduelstage::BetInitial;
		bHaveGameData = true;
	}
	if (bPrepared_vec_screenelement_p != true) {
		const pokerduelstage* pokerduelstage_p_Const = pokerduelstage_p_;
		const gamedata* gamedata_pEnemyConst = gamedata_pEnemy;
		const gamedata* gamedata_pPlayerConst = gamedata_pPlayer;
		const intx5* n5_pEnemyConst = n5_pEnemy;
		const intx5* n5_pEnemyInitialConst = n5_pEnemyInitial;
		const intx5* n5_pPlayerConst = n5_pPlayer;
		const intx5* n5_pPlayerInitialConst = n5_pPlayerInitial;
		prepare (
			nCashInPot,
			font_,
			pokerduelstage_p_Const,
			gamedata_pEnemyConst,
			gamedata_pPlayerConst,
			n5_pEnemyConst,
			n5_pEnemyInitialConst,
			n5_pPlayerConst,
			n5_pPlayerInitialConst,
			vec_screenelement_p_
		);
		bPrepared_vec_screenelement_p = true;
	}
	draw (vec_screenelement_p_, rw_);
	rw_.display ();
	while (rw_.pollEvent (event_)) {
		if (bShouldClear_vec_screenelement_p) {
			//DO NOTHING.  Event is void and event queue must be cleared.
		} else {
			handle (
				gameaction_,
				pokerduelstage_p_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				n5_pEnemy,
				n5_pEnemyInitial,
				n5_pPlayer,
				n5_pPlayerInitial,
				vec_screenelement_p_,
				bShouldClear_vec_screenelement_p,
				event_
			);
			if (bShouldClear_vec_screenelement_p) {
				clear (vec_screenelement_p_);
				bPrepared_vec_screenelement_p = false;
			}
		}
	}
}
void pokerduel::prepare (
	const int& nCashInPot,
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
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				vec_screenelement_p_
			);
			break;
		}
		case pokerduelstage::RollInitial: {
			prepareStage_RollInitial (
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				vec_screenelement_p_
			);
			break;
		}
		case pokerduelstage::RollRedo: {
			prepareStage_RollRedo (
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
void pokerduel::handle (
	gameaction& gameaction_,
	pokerduelstage*& pokerduelstage_p_,
	gamedata*& gamedata_pEnemy,
	gamedata*& gamedata_pPlayer,
	intx5*& n5_pEnemy,
	intx5*& n5_pEnemyInitial,
	intx5*& n5_pPlayer,
	intx5*& n5_pPlayerInitial,
	const std::vector <screenelement*>& vec_screenelement_p_,
	bool& bShouldClear_vec_screenelement_p,
	const sf::Event& eventToHandle
) {
	gameaction_ = gameaction::Exit; //TODO
	bShouldClear_vec_screenelement_p = true;
}
void pokerduel::prepareStage_BetInitial (
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
void pokerduel::prepareStage_RollInitial (
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
}
void pokerduel::prepareStage_RollRedo (
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemy,
	const intx5*& n5_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
}
void pokerduel::prepareStage_BetRaise (
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemy,
	const intx5*& n5_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
}
void pokerduel::prepareStage_Conclusion (
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemy,
	const intx5*& n5_pEnemyInitial,
	const intx5*& n5_pPlayer,
	const intx5*& n5_pPlayerInitial,
	std::vector <screenelement*>& vec_screenelement_p_
) {
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