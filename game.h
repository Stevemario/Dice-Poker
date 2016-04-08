#ifndef GAME_H
#define GAME_H
#include "pokerround.h"
#include "mainmenu.h"
namespace game {
	extern int m_nBetAgreed;
	extern int m_nCashInPot;
	extern int m_nCashInPotBefore;
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
	extern std::string m_sLoadSource;
	extern std::string m_sNewAdventureName;
	extern std::string m_sSaveDestination;
	extern std::string* m_s_pToEdit;
	extern sf::Font m_font;
	extern sf::RenderWindow m_rw;
	extern gameaction m_gameaction;
	extern gamemode* m_gamemode_p;
	extern mainmenupage m_mainmenupage;
	extern pokerroundstage* m_pokerroundstage_p;
	extern gamedata* m_gamedata_pEnemy;
	extern gamedata* m_gamedata_pPlayer;
	extern pokerround::variableset1* m_prvs1_p;
	extern pokerround::variableset2* m_prvs2_p;
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
	void editAString (
		bool&,
		const sf::Uint32&
	);
	void handlePlayBind (
		bool&,
		const sf::Uint32&
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
	void load (
		std::ifstream&
	);
	void save (
		std::ofstream&
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