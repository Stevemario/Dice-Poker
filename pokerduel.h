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
	void prepareStage_AcknowledgeBetAndRollInitial (
		const int&,
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		std::vector <screenelement*>&
	);
	void prepareStage_AcknowledgeRollInitialSelectRerollAndBetSecond (
		const int&,
		const std::string&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		std::vector <screenelement*>&
	);
	void prepareStage_AcknowledgeBetAndRollSecond (
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		std::vector <screenelement*>&
	);
	void prepareStage_Conclusion (
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
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
	enum class screenelement_rectangle_enum {
		DiceSelectedBackground,
	};
	typedef screenelement_rectangle::screenelement_rectangle <screenelement_rectangle_enum> screenelement_rectangle;
	class screenelement_rectangle_dice_selected_background : public screenelement_rectangle {
		public: screenelement_rectangle_enum screenelement_rectangle_enum_ (
		) const;
		public: screenelement_rectangle_dice_selected_background (
			const float&,
			const float&
		);
	};
	enum class screenelement_label_enum {
		HeaderNameEnemy,
		HeaderNamePlayer,
		HeaderPot,
		HeaderCashEnemy,
		HeaderCashPlayer,
		HeaderCashPot,
		HeaderPromptBetInitial,
		HeaderAlertBet,
		HeaderPressingRollWillOKBet,
		HeaderDiceRolled,
		HeaderDiceEnemy,
		HeaderDicePlayer,
		HeaderSelectDiceToReroll,
		HeaderPromptBetSecond,
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
		ChangeBetInitial,
		OKBetAndRollDiceInitial,
		DiceEnemy0,
		DiceEnemy1,
		DiceEnemy2,
		DiceEnemy3,
		DiceEnemy4,
		DicePlayer0,
		DicePlayer1,
		DicePlayer2,
		DicePlayer3,
		DicePlayer4,
		SubmitRerollAndSecondBet,
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
	class screenelement_button_dice : public screenelement_button {
		private: screenelement_button_enum m_screenelement_button_enum;
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_dice (
			const sf::Font&,
			const int&,
			const screenelement_button_enum&
		);
	};
}
#endif