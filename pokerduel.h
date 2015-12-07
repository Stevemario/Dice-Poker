#ifndef POKERDUEL_H
#define POKERDUEL_H
#include "screenelement.h"
#include "diceset.h"
#include "gamedata.h"
#include "gameaction.h"
#include "pokerduelstage.h"
namespace pokerduel {
	void prepare (
		const int&,
		const int&,
		const std::string&,
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
	void prepareStage_BetInitial (
		const int&,
		const std::string&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		std::vector <screenelement*>&
	);
	void prepareStage_AlertBetInitial (
		const int&,
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		std::vector <screenelement*>&
	);
	void prepareStage_RollInitial (
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		std::vector <screenelement*>&
	);
	void prepareStage_RollRedo (
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		std::vector <screenelement*>&
	);
	void prepareStage_BetRaise (
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		std::vector <screenelement*>&
	);
	void prepareStage_Conclusion (
		const int&,
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
		HeaderPromptBet,
		HeaderAlertBet,
		HeaderDiceRolled,
		HeaderDiceEnemy,
		HeaderDicePlayer,
		HeaderSelectDiceToReroll,
	};
	typedef screenelement_label::screenelement_label <screenelement_label_enum> screenelement_label;
	class screenelement_label_generic : public screenelement_label {
		private: screenelement_label_enum m_screenelement_label_enum;
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_generic (
			const sf::Font&,
			const std::string&,
			const screenelement_label_enum&
		);
	};
	enum class screenelement_button_enum {
		BetAmount,
		SubmitBetInitial,
		OKBetInitial,
	};
	typedef screenelement_button::screenelement_button <screenelement_button_enum> screenelement_button;
	class screenelement_button_generic : public screenelement_button {
		private: screenelement_button_enum m_screenelement_button_enum;
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_generic (
			const sf::Font&,
			const std::string&,
			const screenelement_button_enum&
		);
	};
}
#endif