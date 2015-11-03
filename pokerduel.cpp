#include "pokerduel.h"
void pokerduel::work (
	bool& bPrepared_vec_screenelement_p,
	const sf::Font& font_,
	sf::RenderWindow& rw_,
	gameaction& gameaction_,
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
			//DO NOTHING.  Clearing event queue.
		} else {
			handle (
				gameaction_,
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
	const gamedata* gamedata_pEnemy,
	const gamedata* gamedata_pPlayer,
	const intx5& n5Enemy,
	const intx5& n5Player,
	std::vector <screenelement*>& vec_screenelement_p_
) {
}
void pokerduel::handle (
	gameaction& gameaction_,
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