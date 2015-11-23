#ifndef POKERDUEL_H
#define POKERDUEL_H
#include "screenelement.h"
#include "diceset.h"
#include "gamedata.h"
#include "gameaction.h"
#include "pokerduelstage.h"
namespace pokerduel {
	void work (
		int&,
		bool&,
		bool&,
		const sf::Font&,
		sf::RenderWindow&,
		gameaction&,
		pokerduelstage*&,
		gamedata*&,
		gamedata*&,
		intx5*&,
		intx5*&,
		intx5*&,
		intx5*&,
		std::vector <screenelement*>&
	);
	void prepare (
		const int&,
		const sf::Font&,
		const pokerduelstage*&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		std::vector <screenelement*>&
	);
	void handle (
		gameaction&,
		pokerduelstage*&,
		gamedata*&,
		gamedata*&,
		intx5*&,
		intx5*&,
		intx5*&,
		intx5*&,
		const std::vector <screenelement*>&,
		bool&,
		const sf::Event&
	);
	void prepareStage_BetInitial (
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		std::vector <screenelement*>&
	);
	void prepareStage_RollInitial (
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		std::vector <screenelement*>&
	);
	void prepareStage_RollRedo (
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		std::vector <screenelement*>&
	);
	void prepareStage_BetRaise (
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		std::vector <screenelement*>&
	);
	void prepareStage_Conclusion (
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		std::vector <screenelement*>&
	);
	void addLabelsCash (
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		std::vector <screenelement*>&
	);
	enum class screenelement_label_enum {
		HeaderNameEnemy,
		HeaderNamePlayer,
		HeaderPot,
		HeaderCashEnemy,
		HeaderCashPlayer,
		HeaderCashPot,
	};
	typedef screenelement_label::screenelement_label <screenelement_label_enum> screenelement_label;
	class screenelement_label_header_name_enemy : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_name_enemy (
			const sf::Font&,
			const gamedata*&
		);
	};
	class screenelement_label_header_name_player : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_name_player (
			const sf::Font&,
			const gamedata*&
		);
	};
	class screenelement_label_header_pot : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_pot (
			const sf::Font&
		);
	};
	class screenelement_label_header_cash_enemy : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_cash_enemy (
			const sf::Font&,
			const gamedata*&
		);
	};
	class screenelement_label_header_cash_player : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_cash_player (
			const sf::Font&,
			const gamedata*&
		);
	};
	class screenelement_label_header_cash_pot : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_cash_pot (
			const sf::Font&,
			const int&
		);
	};
}
#endif