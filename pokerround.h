#ifndef POKERROUND_H
#define POKERROUND_H
#include "screenelement.h"
#include "diceset.h"
#include "gamedata.h"
#include "pokerroundstage.h"
#include "pokerroundresult.h"
namespace pokerround {
	class variableset0 {
		public: int m_nBetAgreed;
		public: pokerroundstage m_pokerroundstage;
		public: gamedata* m_gamedata_pEnemy;
		public: gamedata* m_gamedata_pPlayer;
		public: void writeTo (
			std::ofstream&
		) const;
		public: variableset0 (
		);
		public: variableset0 (
			std::ifstream&
		);
		public: ~variableset0 ();
	};
	class variableset1 {
		private: intx5 m_n5DiceEnemyInitial;
		private: intx5 m_n5DiceEnemyReroll;
		private: intx5 m_n5DicePlayerInitial;
		private: intx5 m_n5DicePlayerReroll;
		public: intx5 n5DiceEnemyInitial (
		) const;
		public: intx5 n5DiceEnemyReroll (
		) const;
		public: intx5 n5DicePlayerInitial (
		) const;
		public: intx5 n5DicePlayerReroll (
		) const;
		public: void writeTo (
			std::ofstream&
		) const;
		public: variableset1 (
		);
		public: variableset1 (
			std::ifstream&
		);
		public: void set_nDiceEnemyInitial (
			const int&,
			const int&
		);
		public: void set_nDiceEnemyReroll (
			const int&,
			const int&
		);
		public: void set_nDicePlayerInitial (
			const int&,
			const int&
		);
		public: void set_nDicePlayerReroll (
			const int&,
			const int&
		);
	};
	class variableset2 {
		private: int m_nScoreEnemyInitial;
		private: int m_nScoreEnemyUltimate;
		private: int m_nScorePlayerInitial;
		private: int m_nScorePlayerUltimate;
		private: int m_nCashInPotBefore;
		private: pokerroundresult m_pokerroundresult;
		private: intx5 m_n5DiceEnemyUltimate;
		private: intx5 m_n5DicePlayerUltimate;
		public: int nScoreEnemyInitial (
		) const;
		public: int nScoreEnemyUltimate (
		) const;
		public: int nScorePlayerInitial (
		) const;
		public: int nScorePlayerUltimate (
		) const;
		public: int nCashInPotBefore (
		) const;
		public: pokerroundresult pokerroundresult_ (
		) const;
		public: intx5 n5DiceEnemyUltimate (
		) const;
		public: intx5 n5DicePlayerUltimate (
		) const;
		public: void writeTo (
			std::ofstream&
		) const;
		public: variableset2 (
		);
		public: variableset2 (
			std::ifstream&
		);
		public: void set_nScoreEnemyInitial (
			const int&
		);
		public: void set_nScoreEnemyUltimate (
			const int&
		);
		public: void set_nScorePlayerInitial (
			const int&
		);
		public: void set_nScorePlayerUltimate (
			const int&
		);
		public: void set_nCashInPotBefore (
			const int&
		);
		public: void set_pokerroundresult (
			const pokerroundresult&
		);
		public: void set_nDiceEnemyUltimate (
			const int&,
			const int&
		);
		public: void set_nDicePlayerUltimate (
			const int&,
			const int&
		);
	};
	void prepare (
		const int&,
		const int&,
		const std::string&,
		const sf::Font&,
		const pokerroundstage&,
		const gamedata*&,
		const gamedata*&,
		const variableset1*&,
		const variableset2*&,
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
		const intx5&,
		const intx5&,
		const intx5&,
		screenelements&
	);
	void prepareStage_OKInputSecond (
		const int&,
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		const intx5&,
		const intx5&,
		screenelements&
	);
	void prepareStage_OKResults (
		const int&,
		const sf::Font&,
		const gamedata*&,
		const gamedata*&,
		const intx5&,
		const intx5&,
		const intx5&,
		const intx5&,
		const variableset2*&,
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
			const intx5&,
			const intx5&
		);
	};
	class screenelement_label_header_alert_reroll : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_alert_reroll (
			const sf::Font&,
			const intx5&,
			const int&
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
			const pokerroundresult&,
			const int&,
			const gamedata*&
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
			const screenelement_button_enum&
		);
	};
	class screenelement_button_bet_amount : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_bet_amount (
			const sf::Font&,
			const std::string&
		);
	};
	class screenelement_button_dice : public screenelement_button {
		private: screenelement_button_enum m_screenelement_button_enum;
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_dice (
			const sf::Font&,
			const int&,
			const bool&,
			const int&
		);
	};
}
#endif