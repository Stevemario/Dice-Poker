#ifndef GAME_H
#define GAME_H
#include "gamedata.h"
#include "screenelement.h"
#include "gameaction.h"
#include "mainmenupage.h"
namespace game {
	extern int m_nSEClickedLast;
	extern bool m_bClickedAButtonJustNow;
	extern bool m_bEdit_sNewAdventureName;
	extern bool m_bInitialized_gamedata_p;
	extern bool m_bPrepared_vec_screenelement_p;
	extern bool m_bShowMainMenuNewGamePageChoice;
	extern std::string m_sNewAdventureName;
	extern std::string m_sSaveSpot;
	extern sf::Font m_font;
	extern sf::RenderWindow m_rw;
	extern gameaction m_gameaction;
	extern mainmenupage m_mainmenupage;
	extern gamedata* m_gamedata_p;
	extern std::vector <screenelement*> m_vec_screenelement_p;
	void play (
	);
}
#endif