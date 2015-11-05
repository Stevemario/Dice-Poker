#include "pokerduel.h"
void pokerduel::work (
	bool& bPrepared_vec_screenelement_p,
	const sf::Font& font_,
	sf::RenderWindow& rw_,
	gameaction& gameaction_,
	pokerduelstage& pokerduelstage_,
	gamedata* gamedata_pEnemy,
	gamedata* gamedata_pPlayer,
	intx5& n5Enemy,
	intx5& n5Player,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	bool bShouldClear_vec_screenelement_p = false;
	sf::Event event_;
	if (bPrepared_vec_screenelement_p != true) {
		prepare (
			font_,
			pokerduelstage_,
			gamedata_pEnemy,
			gamedata_pPlayer,
			n5Enemy,
			n5Player,
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
				n5Enemy,
				n5Player,
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
	const gamedata* gamedata_pEnemy,
	const gamedata* gamedata_pPlayer,
	const intx5& n5Enemy,
	const intx5& n5Player,
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
				n5Enemy,
				n5Player,
				vec_screenelement_p_
			);
			break;
		}
		case pokerduelstage::BetRaise: {
			prepareStage_BetRaise (
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				n5Enemy,
				n5Player,
				vec_screenelement_p_
			);
			break;
		}
		case pokerduelstage::Conclusion: {
			prepareStage_Conclusion (
				font_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				n5Enemy,
				n5Player,
				vec_screenelement_p_
			);
			break;
		}
	}
}
void pokerduel::handle (
	gameaction& gameaction_,
	pokerduelstage& pokerduelstage_,
	gamedata* gamedata_pEnemy,
	gamedata* gamedata_pPlayer,
	intx5& n5Enemy,
	intx5& n5Player,
	const std::vector <screenelement*>& vec_screenelement_p_,
	bool& bShouldClear_vec_screenelement_p,
	const sf::Event& eventToHandle
) {
	gameaction_ = gameaction::Exit; //TODO
	bShouldClear_vec_screenelement_p = true;
}
void pokerduel::prepareStage_BetInitial (
	const sf::Font& font_,
	const gamedata* gamedata_pEnemy,
	const gamedata* gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
}
void pokerduel::prepareStage_RollInitial (
	const sf::Font& font_,
	const gamedata* gamedata_pEnemy,
	const gamedata* gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
}
void pokerduel::prepareStage_RollRedo (
	const sf::Font& font_,
	const gamedata* gamedata_pEnemy,
	const gamedata* gamedata_pPlayer,
	const intx5& n5Enemy,
	const intx5& n5Player,
	std::vector <screenelement*>& vec_screenelement_p_
) {
}
void pokerduel::prepareStage_BetRaise (
	const sf::Font& font_,
	const gamedata* gamedata_pEnemy,
	const gamedata* gamedata_pPlayer,
	const intx5& n5Enemy,
	const intx5& n5Player,
	std::vector <screenelement*>& vec_screenelement_p_
) {
}
void pokerduel::prepareStage_Conclusion (
	const sf::Font& font_,
	const gamedata* gamedata_pEnemy,
	const gamedata* gamedata_pPlayer,
	const intx5& n5Enemy,
	const intx5& n5Player,
	std::vector <screenelement*>& vec_screenelement_p_
) {
}