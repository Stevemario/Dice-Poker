#include "mainmenu.h"
#include "pokerduel.h"
#include "game.h"
#include <ctime>
#include <cstdlib>
int game::m_nSEClickedLast;
bool game::m_bClickedAButtonJustNow = false;
bool game::m_bEdit_sNewAdventureName = false;
bool game::m_bInitialized_gamedata_p = false;
bool game::m_bPrepared_vec_screenelement_p = false;
bool game::m_bShowMainMenuNewGamePageChoice = true;
std::string game::m_sNewAdventureName = "TEST";
std::string game::m_sSaveSpot = "default save.txt";
sf::Font game::m_font;
sf::RenderWindow game::m_rw;
gameaction game::m_gameaction = gameaction::MenuMainWork;
mainmenupage game::m_mainmenupage = mainmenupage::Splash;
gamedata* game::m_gamedata_p;
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
			m_gamedata_p = new gamedata (ifstream_);
			ifstream_.close ();
			m_bInitialized_gamedata_p = true;
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
					m_bInitialized_gamedata_p,
					m_bPrepared_vec_screenelement_p,
					m_bShowMainMenuNewGamePageChoice,
					m_sNewAdventureName,
					m_font,
					m_rw,
					m_gameaction,
					m_mainmenupage,
					m_gamedata_p,
					m_vec_screenelement_p
				);
				break;
			}
			case gameaction::Play: {
				pokerduel::work (
					m_bPrepared_vec_screenelement_p,
					m_font,
					m_rw,
					m_gameaction,
					m_gamedata_p,
					m_vec_screenelement_p
				);
				break;
			}
		}
	}
	m_rw.close ();
	if (m_bInitialized_gamedata_p)
		delete m_gamedata_p;
}