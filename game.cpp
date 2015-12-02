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
	startUp ();
	while (m_gameaction != gameaction::Exit) {
		m_rw.clear (sf::Color::Green);
		bool bShouldClear_vec_screenelement_p = false;
		sf::Event event_;
		prepareData ();
		prepareScreenElements ();
		draw (m_vec_screenelement_p, m_rw);
		m_rw.display ();
		handleEvents (bShouldClear_vec_screenelement_p, event_);
	}
	shutDown ();
}
void game::startUp (
) {
	srand (unsigned int (time (NULL)));
	m_rw.create (sf::VideoMode (1350, 1080), "Dice Poker");
	m_rw.setFramerateLimit (60); //Stops my video card from making noise.  don't really want this.
	m_font.loadFromFile ("C:/Windows/Fonts/arial.ttf");
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
void game::prepareData (
) {
	if (m_gameaction == gameaction::Play) {
		if (m_bHaveGameData != true) {
			switch (*m_gamemode_p) {
				case gamemode::PokerDuel: {
					m_nCashInPot = 0;
					m_pokerduelstage_p = new pokerduelstage;
					m_gamedata_pEnemy = new gamedata ("Steve's Bot");
					m_gamedata_pPlayer = new gamedata ("Player");
					*m_pokerduelstage_p = pokerduelstage::BetInitial;
					m_bHaveGameData = true;
					break;
				}
				case gamemode::Adventure: {
					//WILL DO LATER
					break;
				}
			}
		}
	}
}
void game::prepareScreenElements (
) {
	if (m_bPrepared_vec_screenelement_p != true) {
		switch (m_gameaction) {
			case gameaction::WorkMainMenu: {
				const gamedata* gamedata_pPlayerConst = m_gamedata_pPlayer;
				menu_main::prepare (
					m_bHaveGameData,
					m_bShowMainMenuNewGamePageChoice,
					m_sNewAdventureName,
					m_font,
					m_mainmenupage,
					gamedata_pPlayerConst,
					m_vec_screenelement_p
				);
				break;
			}
			case gameaction::Play: {
				switch (*m_gamemode_p) {
					case gamemode::PokerDuel: {
						const pokerduelstage* pokerduelstage_p_Const = m_pokerduelstage_p;
						const gamedata* gamedata_pEnemyConst = m_gamedata_pEnemy;
						const gamedata* gamedata_pPlayerConst = m_gamedata_pPlayer;
						const intx5* n5_pEnemyConst = m_n5_pEnemy;
						const intx5* n5_pEnemyInitialConst = m_n5_pEnemyInitial;
						const intx5* n5_pPlayerConst = m_n5_pPlayer;
						const intx5* n5_pPlayerInitialConst = m_n5_pPlayerInitial;
						pokerduel::prepare (
							m_nCashInPot,
							m_font,
							pokerduelstage_p_Const,
							gamedata_pEnemyConst,
							gamedata_pPlayerConst,
							n5_pEnemyConst,
							n5_pEnemyInitialConst,
							n5_pPlayerConst,
							n5_pPlayerInitialConst,
							m_vec_screenelement_p
						);
						break;
					}
					case gamemode::Adventure: {
						//WILL DO LATER
						break;
					}
				}
				break;
			}
		}
		m_bPrepared_vec_screenelement_p = true;
	}
}
void game::handleEvents (
	bool& bShouldClear_vec_screenelement_p,
	sf::Event& event_
) {
	while (m_rw.pollEvent (event_)) {
		if (bShouldClear_vec_screenelement_p) {
			//DO NOTHING.  Event is void and event queue must be cleared.
		} else {
			switch (m_gameaction) {
				case gameaction::WorkMainMenu: {
					menu_main::handle (
						m_nSEClickedLast,
						m_bClickedAButtonJustNow,
						bEditAString,
						m_bHaveGameData,
						m_bShowMainMenuNewGamePageChoice,
						m_sNewAdventureName,
						m_s_pToEdit,
						m_gameaction,
						m_gamemode_p,
						m_mainmenupage,
						m_gamedata_pEnemy,
						m_gamedata_pPlayer,
						m_vec_screenelement_p,
						bShouldClear_vec_screenelement_p,
						event_
					);
					break;
				}
				case gameaction::Play: {
					switch (*m_gamemode_p) {
						case gamemode::PokerDuel: {
							pokerduel::handle (
								m_gameaction,
								m_pokerduelstage_p,
								m_gamedata_pEnemy,
								m_gamedata_pPlayer,
								m_n5_pEnemy,
								m_n5_pEnemyInitial,
								m_n5_pPlayer,
								m_n5_pPlayerInitial,
								m_vec_screenelement_p,
								bShouldClear_vec_screenelement_p,
								event_
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
			if (bShouldClear_vec_screenelement_p) {
				clear (m_vec_screenelement_p);
				m_bPrepared_vec_screenelement_p = false;
			}
		}
	}
}
void game::shutDown (
) {
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