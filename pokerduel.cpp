#include "pokerduel.h"
void pokerduel::work (
	bool& bHaveGameData,
	bool& bPrepared_vec_screenelement_p,
	const sf::Font& font_,
	sf::RenderWindow& rw_,
	gameaction& gameaction_,
	pokerduelstage& pokerduelstage_,
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
		gamedata_pEnemy = new gamedata ("Steve's Bot");
		gamedata_pPlayer = new gamedata ("Player");
		bHaveGameData = true;
	}
	if (bPrepared_vec_screenelement_p != true) {
		const gamedata* gamedata_pEnemyConst = gamedata_pEnemy;
		const gamedata* gamedata_pPlayerConst = gamedata_pPlayer;
		const intx5* n5_pEnemyConst = n5_pEnemy;
		const intx5* n5_pEnemyInitialConst = n5_pEnemyInitial;
		const intx5* n5_pPlayerConst = n5_pPlayer;
		const intx5* n5_pPlayerInitialConst = n5_pPlayerInitial;
		prepare (
			font_,
			pokerduelstage_,
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
				pokerduelstage_,
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
	const sf::Font& font_,
	const pokerduelstage& pokerduelstage_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5*& n5_pEnemy,
	const intx5*& n5_pEnemyInitial,
	const intx5*& n5_pPlayer,
	const intx5*& n5_pPlayerInitial,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	switch (pokerduelstage_) {
		case pokerduelstage::BetInitial: {
			prepareStage_BetInitial (
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
	pokerduelstage& pokerduelstage_,
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
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
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