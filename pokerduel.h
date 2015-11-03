#ifndef POKERDUEL_H
#define POKERDUEL_H
#include "screenelement.h"
#include "diceset.h"
#include "gamedata.h"
#include "gameaction.h"
namespace pokerduel {
	void work (
		bool&,
		const sf::Font&,
		sf::RenderWindow&,
		gameaction&,
		gamedata*,
		gamedata*,
		intx5&,
		intx5&,
		std::vector <screenelement*>&
	);
	void prepare (
		const sf::Font&,
		const gamedata*,
		const gamedata*,
		const intx5&,
		const intx5&,
		std::vector <screenelement*>&
	);
	void handle (
		gameaction&,
		gamedata*,
		gamedata*,
		intx5&,
		intx5&,
		const std::vector <screenelement*>&,
		bool&,
		const sf::Event&
	);
}
#endif