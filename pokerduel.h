#ifndef POKERDUEL_H
#define POKERDUEL_H
#include "screenelement.h"
#include "diceset.h"
#include "gamedata.h"
#include "gameaction.h"
#include "pokerduelstage.h"
namespace pokerduel {
	void work (
		bool&,
		bool&,
		const sf::Font&,
		sf::RenderWindow&,
		gameaction&,
		pokerduelstage&,
		gamedata*,
		gamedata*,
		intx5*,
		intx5*,
		intx5*,
		intx5*,
		std::vector <screenelement*>&
	);
	void prepare (
		const sf::Font&,
		const pokerduelstage&,
		const gamedata*,
		const gamedata*,
		const intx5*,
		const intx5*,
		const intx5*,
		const intx5*,
		std::vector <screenelement*>&
	);
	void handle (
		gameaction&,
		pokerduelstage&,
		gamedata*,
		gamedata*,
		intx5*,
		intx5*,
		intx5*,
		intx5*,
		const std::vector <screenelement*>&,
		bool&,
		const sf::Event&
	);
	void prepareStage_BetInitial (
		const sf::Font&,
		const gamedata*,
		const gamedata*,
		std::vector <screenelement*>&
	);
	void prepareStage_RollInitial (
		const sf::Font&,
		const gamedata*,
		const gamedata*,
		std::vector <screenelement*>&
	);
	void prepareStage_RollRedo (
		const sf::Font&,
		const gamedata*,
		const gamedata*,
		const intx5*,
		const intx5*,
		std::vector <screenelement*>&
	);
	void prepareStage_BetRaise (
		const sf::Font&,
		const gamedata*,
		const gamedata*,
		const intx5*,
		const intx5*,
		std::vector <screenelement*>&
	);
	void prepareStage_Conclusion (
		const sf::Font&,
		const gamedata*,
		const gamedata*,
		const intx5*,
		const intx5*,
		const intx5*,
		const intx5*,
		std::vector <screenelement*>&
	);
}
#endif