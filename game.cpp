#include "mainmenu.h"
#include "pokerduel.h"
#include "game.h"
#include <ctime>
#include <cstdlib>
int game::m_nCashInPot;
int game::m_nSEClickedLast;
bool game::m_bClickedAButtonJustNow = false;
bool game::bEditAString = false;
bool game::m_bHaveGameData = false;
bool game::m_bPrepared_vec_screenelement_p = false;
bool game::m_bShowMainMenuNewGamePageChoice = true;
std::string game::m_sNewAdventureName = "TEST";
std::string game::m_sSaveSpot = "default save.txt";
std::string* game::m_s_pToEdit;
sf::Font game::m_font;
sf::RenderWindow game::m_rw;
gameaction game::m_gameaction = gameaction::WorkMainMenu;
gamemode* game::m_gamemode_p;
mainmenupage game::m_mainmenupage = mainmenupage::Splash;
pokerduelstage* game::m_pokerduelstage_p;
gamedata* game::m_gamedata_pEnemy;
gamedata* game::m_gamedata_pPlayer;
intx5* game::m_n5_pEnemy;
intx5* game::m_n5_pEnemyInitial;
intx5* game::m_n5_pPlayer;
intx5* game::m_n5_pPlayerInitial;
std::vector <screenelement*> game::m_vec_screenelement_p;
void game::play (
) {
	srand (unsigned int (time (NULL)));
	m_rw.create (sf::VideoMode (1350, 1080), "Dice Poker");
	m_rw.setFramerateLimit (60); //Stops my video card from making noise.  don't really want this.
	m_font.loadFromFile ("C:/Windows/Fonts/arial.ttf");
	{
		std::ifstream ifstream_;
		ifstream_.open (m_sSaveSpot);
		if (ifstream_.is_open ()) {
			load (
				m_bHaveGameData,
				m_gamemode_p,
				m_pokerduelstage_p,
				m_gamedata_pEnemy,
				m_gamedata_pPlayer,
				ifstream_
			);
			ifstream_.close ();
		}
	}
	while (m_gameaction != gameaction::Exit) {
		m_rw.clear (sf::Color::Green);
		switch (m_gameaction) {
			case gameaction::WorkMainMenu: {
				menu_main::work (
					m_nSEClickedLast,
					m_bClickedAButtonJustNow,
					bEditAString,
					m_bHaveGameData,
					m_bPrepared_vec_screenelement_p,
					m_bShowMainMenuNewGamePageChoice,
					m_sNewAdventureName,
					m_s_pToEdit,
					m_font,
					m_rw,
					m_gameaction,
					m_gamemode_p,
					m_mainmenupage,
					m_gamedata_pEnemy,
					m_gamedata_pPlayer,
					m_vec_screenelement_p
				);
				break;
			}
			case gameaction::Play: {
				switch (*m_gamemode_p) {
					case gamemode::PokerDuel: {
						pokerduel::work (
							m_nCashInPot,
							m_bHaveGameData,
							m_bPrepared_vec_screenelement_p,
							m_font,
							m_rw,
							m_gameaction,
							m_pokerduelstage_p,
							m_gamedata_pEnemy,
							m_gamedata_pPlayer,
							m_n5_pEnemy,
							m_n5_pEnemyInitial,
							m_n5_pPlayer,
							m_n5_pPlayerInitial,
							m_vec_screenelement_p
						);
						break;
					}
					case gamemode::Adventure: {
						m_gameaction = gameaction::Exit; //WILL DO LATER
						break;
					}
				}
				break;
			}
		}
	}
	m_rw.close ();
	if (m_bHaveGameData) {
		switch (*m_gamemode_p) {
			case gamemode::PokerDuel: {
				delete m_pokerduelstage_p;
				delete m_gamedata_pEnemy;
				delete m_gamedata_pPlayer;
				break;
			}
			case gamemode::Adventure: {
				break;
			}
		}
		delete m_gamemode_p;
	}
}
void game::load (
	bool& bHaveGameData,
	gamemode*& gamemode_p_,
	pokerduelstage*& pokerduelstage_p_,
	gamedata*& gamedata_pEnemy,
	gamedata*& gamedata_pPlayer,
	std::ifstream& ifstream_
) {
	char* ch_p_ = new char;
	ifstream_.read (ch_p_, 1);
	gamemode_p_ = new gamemode;
	*gamemode_p_ = gamemode (*ch_p_);
	switch (*gamemode_p_) {
		case gamemode::PokerDuel: {
			pokerduelstage_p_ = new pokerduelstage;
			ifstream_.read (ch_p_, 1);
			*pokerduelstage_p_ = pokerduelstage (*ch_p_);
			gamedata_pEnemy = new gamedata (ifstream_);
			gamedata_pPlayer = new gamedata (ifstream_);
			break;
		}
		case gamemode::Adventure: {
			break;
		}
	}
	delete ch_p_;
	bHaveGameData = true;
}