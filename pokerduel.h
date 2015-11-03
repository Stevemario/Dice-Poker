#ifndef POKERDUEL_H
#define POKERDUEL_H
#include "gamedata.h"
#include "screenelement.h"
#include "gameaction.h"
namespace pokerduel {
	void work (
		bool&,
		const sf::Font&,
		sf::RenderWindow&,
		gameaction&,
		gamedata*,
		std::vector <screenelement*>&
	);
	void prepare (
		const sf::Font&,
		gamedata*,
		std::vector <screenelement*>&
	);
	void handle (
		gameaction&,
		gamedata*,
		const std::vector <screenelement*>&,
		bool&,
		const sf::Event&
	);
}
#endif