#ifndef POKERDUEL_H
#define POKERDUEL_H
#include "screenelement.h"
#include "diceset.h"
#include "gamedata.h"
#include "pokerduelstage.h"
#include "pokerduelresult.h"
namespace pokerduel {
	void prepare (
		const int&,
		const int&,
		const int&,
		const int&,
		const int&,
		const int&,
		const int&,
		const std::string&,
		const sf::Font&,
		const pokerduelresult*&,
		const pokerduelstage*&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		screenelements&
	);
	void prepareStage_SubmitInputInitial (
		const int&,
		const std::string&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		screenelements&
	);
	void prepareStage_OKInputInitial (
		const int&,
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		screenelements&
	);
	void prepareStage_SubmitInputSecond (
		const int&,
		const std::string&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		screenelements&
	);
	void prepareStage_OKInputSecond (
		const int&,
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		screenelements&
	);
	void prepareStage_OKResults (
		const int&,
		const int&,
		const int&,
		const int&,
		const int&,
		const int&,
		const sf::Font&,
		const pokerduelresult*&,
		const gamedata*&,
		const gamedata*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		const intx5*&,
		screenelements&
	);
	void addLabelsCash (
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		screenelements&
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
		HeaderAlertDicePlayerWillKeep,
		HeaderAlertBetSecond,
		HeaderPressingOKInputSecondWillRollSecond,
		HeaderDiceInitial,
		HeaderDiceUltimate,
		HeaderAlertReroll,
		HeaderScoreEnemyInitial,
		HeaderScoreEnemyUltimate,
		HeaderScorePlayerInitial,
		HeaderScorePlayerUltimate,
		HeaderAlertOutcomePlayer,
	};
	typedef screenelement_label::screenelement_label <screenelement_label_enum> screenelement_label;
	class screenelement_label_generic : public screenelement_label {
		private: screenelement_label_enum m_screenelement_label_enum;
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_generic (
			const sf::Font&,
			const screenelement_label_enum&
		);
	};
	class screenelement_label_header_name : public screenelement_label {
		private: screenelement_label_enum m_screenelement_label_enum;
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_name (
			const sf::Font&,
			const gamedata*&,
			const bool&
		);
	};
	class screenelement_label_header_cash : public screenelement_label {
		private: screenelement_label_enum m_screenelement_label_enum;
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_cash (
			const sf::Font&,
			const gamedata*&,
			const bool&
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
	class screenelement_label_header_alert_bet : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_alert_bet (
			const sf::Font&,
			const int&,
			const bool&
		);
	};
	class screenelement_label_header_alert_dice_player_will_keep : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_alert_dice_player_will_keep (
			const sf::Font&,
			const intx5*&,
			const intx5*&
		);
	};
	class screenelement_label_header_score : public screenelement_label {
		private: screenelement_label_enum m_screenelement_label_enum;
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_score (
			const sf::Font&,
			const int&,
			const bool&,
			const bool&
		);
	};
	class screenelement_label_header_alert_outcome_player : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_alert_outcome_player (
			const sf::Font&,
			const pokerduelresult*&,
			const int&
		);
	};
	class screenelement_label_header_alert_reroll : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_alert_reroll (
			const sf::Font&,
			const intx5*&,
			const int&
		);
	};
	enum class screenelement_button_enum {
		BetAmount,
		SubmitInputInitial,
		ChangeInputInitial,
		OKInputInitial,
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
		SubmitInputSecond,
		ChangeInputSecond,
		OKInputSecond,
		OKResult,
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