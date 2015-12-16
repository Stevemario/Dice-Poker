#ifndef GAME_H
#define GAME_H
#include "pokerround.h"
#include "mainmenu.h"
namespace game {
	extern int m_nBetAgreed;
	extern int m_nCashInPot;
	extern int m_nCashInPotBefore;
	extern int m_nScoreEnemyInitial;
	extern int m_nScoreEnemyUltimate;
	extern int m_nScorePlayerInitial;
	extern int m_nScorePlayerUltimate;
	extern int m_nSEClickedLast;
	extern bool m_bStringTakesUpper;
	extern bool m_bStringTakesLower;
	extern bool m_bStringTakesDigit;
	extern bool m_bStringTakesPunctuation;
	extern bool m_bStringTakesSpace;
	extern bool m_bClickedAButtonJustNow;
	extern bool m_bEditAString;
	extern bool m_bHaveGameData;
	extern bool m_bPrepared_vec_screenelement_p;
	extern bool m_bShowMainMenuNewGamePageChoice;
	extern std::string m_sBetPlayer;
	extern std::string m_sNewAdventureName;
	extern std::string m_sSaveSpot;
	extern std::string* m_s_pToEdit;
	extern sf::Font m_font;
	extern sf::RenderWindow m_rw;
	extern gameaction m_gameaction;
	extern gamemode* m_gamemode_p;
	extern mainmenupage m_mainmenupage;
	extern pokerroundresult* m_pokerroundresult_p;
	extern pokerroundstage* m_pokerroundstage_p;
	extern gamedata* m_gamedata_pEnemy;
	extern gamedata* m_gamedata_pPlayer;
	extern intx5* m_n5_pEnemyUltimate;
	extern intx5* m_n5_pEnemyInitial;
	extern intx5* m_n5_pEnemyReroll;
	extern intx5* m_n5_pPlayerUltimate;
	extern intx5* m_n5_pPlayerInitial;
	extern intx5* m_n5_pPlayerReroll;
	extern screenelements m_ses;
	void play (
	);
	void startUp (
	);
	void prepareData (
	);
	void prepareScreenElements (
	);
	void handleEvents (
	);
	void shutDown (
	);
	void load (
		bool&,
		gamemode*&,
		pokerroundstage*&,
		gamedata*&,
		gamedata*&,
		std::ifstream&
	);
	void handleMousePress (
		sf::Event&
	);
	void handleMouseRelease (
		bool&,
		sf::Event&
	);
	void handleTextEntered (
		bool&,
		sf::Event&
	);
	void handle (
		bool&,
		const mainmenu::screenelement_button_enum&
	);
	void handle (
		bool&,
		const pokerround::screenelement_button_enum&
	);
	void handlePokerRoundEnd (
		bool&
	);
	void deleteGameData (
	);
	void deletePokerRoundData (
	);
	void makeStringTakeNothing (
	);
	void resetWhatStringTakes (
	);
	void determineBetAmount (
		const int&
	);
	void transactBet (
		const int&
	);
}
#endif