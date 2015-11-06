#ifndef GAME_H
#define GAME_H
#include "screenelement.h"
#include "diceset.h"
#include "gamedata.h"
#include "gameaction.h"
#include "gamemode.h"
#include "mainmenupage.h"
#include "pokerduelstage.h"
namespace game {
	extern int m_nSEClickedLast;
	extern bool m_bClickedAButtonJustNow;
	extern bool m_bEdit_sNewAdventureName;
	extern bool m_bHaveGameData;
	extern bool m_bPrepared_vec_screenelement_p;
	extern bool m_bShowMainMenuNewGamePageChoice;
	extern std::string m_sNewAdventureName;
	extern std::string m_sSaveSpot;
	extern sf::Font m_font;
	extern sf::RenderWindow m_rw;
	extern gameaction m_gameaction;
	extern gamemode* m_gamemode_p;
	extern mainmenupage m_mainmenupage;
	extern pokerduelstage* m_pokerduelstage_p;
	extern gamedata* m_gamedata_pEnemy;
	extern gamedata* m_gamedata_pPlayer;
	extern intx5* m_n5_pEnemy;
	extern intx5* m_n5_pEnemyInitial;
	extern intx5* m_n5_pPlayer;
	extern intx5* m_n5_pPlayerInitial;
	extern std::vector <screenelement*> m_vec_screenelement_p;
	void play (
	);
	void load (
		bool&,
		gamemode*,
		gamedata*,
		gamedata*,
		std::ifstream&
	);
}
#endif