#include "pokerduel.h"
void pokerduel::work (
	bool& bPrepared_vec_screenelement_p,
	const sf::Font& font_,
	sf::RenderWindow& rw_,
	gameaction& gameaction_,
	gamedata* gamedata_p_,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	bool bShouldClear_vec_screenelement_p = false;
	sf::Event event_;
	if (bPrepared_vec_screenelement_p != true) {
		prepare (
			font_,
			gamedata_p_,
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
				gamedata_p_,
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
	gamedata* gamedata_p_,
	std::vector <screenelement*>& vec_screenelement_p_
) {
}
void pokerduel::handle (
	gameaction& gameaction_,
	gamedata* gamedata_p_,
	const std::vector <screenelement*>& vec_screenelement_p_,
	bool& bShouldClear_vec_screenelement_p,
	const sf::Event& eventToHandle
) {
	gameaction_ = gameaction::Exit; //TODO
	bShouldClear_vec_screenelement_p = true;
}