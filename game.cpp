#include "mainmenu.h"
#include "pokerduel.h"
#include "game.h"
#include <ctime>
#include <cstdlib>
int game::m_nSEClickedLast;
bool game::m_bClickedAButtonJustNow = false;
bool game::m_bEdit_sNewAdventureName = false;
bool game::m_bInitialized_gamedata_pEnemy = false;
bool game::m_bInitialized_gamedata_pPlayer = false;
bool game::m_bPrepared_vec_screenelement_p = false;
bool game::m_bShowMainMenuNewGamePageChoice = true;
std::string game::m_sNewAdventureName = "TEST";
std::string game::m_sSaveSpot = "default save.txt";
sf::Font game::m_font;
sf::RenderWindow game::m_rw;
gameaction game::m_gameaction = gameaction::MenuMainWork;
gamemode game::m_gamemode;
mainmenupage game::m_mainmenupage = mainmenupage::Splash;
gamedata* game::m_gamedata_pEnemy;
gamedata* game::m_gamedata_pPlayer;
intx5 game::m_n5Enemy;
intx5 game::m_n5Player;
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
			char* ch_p_ = new char;
			ifstream_.read (ch_p_, 1);
			m_gamemode = gamemode (*ch_p_);
			delete ch_p_;
			switch (m_gamemode) {
				case gamemode::PokerDuel: {
					m_gamedata_pEnemy = new gamedata (ifstream_);
					m_bInitialized_gamedata_pEnemy = true;
					m_gamedata_pPlayer = new gamedata (ifstream_);
					m_bInitialized_gamedata_pPlayer = true;
					break;
				}
				case gamemode::Adventure: {
					m_gamedata_pPlayer = new gamedata (ifstream_);
					m_bInitialized_gamedata_pPlayer = true;
					break;
				}
			}
			ifstream_.close ();
		}
	}
	while (m_gameaction != gameaction::Exit) {
		m_rw.clear (sf::Color::Green);
		switch (m_gameaction) {
			case gameaction::MenuMainWork: {
				menu_main::work (
					m_nSEClickedLast,
					m_bClickedAButtonJustNow,
					m_bEdit_sNewAdventureName,
					m_bInitialized_gamedata_pEnemy,
					m_bInitialized_gamedata_pPlayer,
					m_bPrepared_vec_screenelement_p,
					m_bShowMainMenuNewGamePageChoice,
					m_sNewAdventureName,
					m_font,
					m_rw,
					m_gameaction,
					m_gamemode,
					m_mainmenupage,
					m_gamedata_pEnemy,
					m_gamedata_pPlayer,
					m_vec_screenelement_p
				);
				break;
			}
			case gameaction::Play: {
				switch (m_gamemode) {
					case gamemode::PokerDuel: {
						pokerduel::work (
							m_bPrepared_vec_screenelement_p,
							m_font,
							m_rw,
							m_gameaction,
							m_gamedata_pEnemy,
							m_gamedata_pPlayer,
							m_n5Enemy,
							m_n5Player,
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
	if (m_bInitialized_gamedata_pEnemy)
		delete m_gamedata_pEnemy;
	if (m_bInitialized_gamedata_pPlayer)
		delete m_gamedata_pPlayer;
}