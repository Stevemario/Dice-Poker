#include "game.h"
#include "iofunctions.h"
#include <ctime>
#include <cstdlib>
int game::m_nBetAgreed;
int game::m_nCashInPot;
int game::m_nCashInPotBefore;
int game::m_nScoreEnemyInitial;
int game::m_nScoreEnemyUltimate;
int game::m_nScorePlayerInitial;
int game::m_nScorePlayerUltimate;
int game::m_nSEClickedLast;
bool game::m_bStringTakesUpper = false;
bool game::m_bStringTakesLower = false;
bool game::m_bStringTakesDigit = false;
bool game::m_bStringTakesPunctuation = false;
bool game::m_bStringTakesSpace = false;
bool game::m_bClickedAButtonJustNow = false;
bool game::m_bEditAString = false;
bool game::m_bHaveGameData = false;
bool game::m_bPrepared_vec_screenelement_p = false;
bool game::m_bShowMainMenuNewGamePageChoice = true;
std::string game::m_sBetPlayer = "0";
std::string game::m_sNewAdventureName = "TEST";
std::string game::m_sSaveSpot = "default save.txt";
std::string* game::m_s_pToEdit;
sf::Font game::m_font;
sf::RenderWindow game::m_rw;
gameaction game::m_gameaction = gameaction::WorkMainMenu;
gamemode* game::m_gamemode_p;
mainmenupage game::m_mainmenupage = mainmenupage::Splash;
pokerroundresult* game::m_pokerroundresult_p;
pokerroundstage* game::m_pokerroundstage_p;
gamedata* game::m_gamedata_pEnemy;
gamedata* game::m_gamedata_pPlayer;
intx5* game::m_n5_pEnemyUltimate;
intx5* game::m_n5_pEnemyInitial;
intx5* game::m_n5_pEnemyReroll;
intx5* game::m_n5_pPlayerUltimate;
intx5* game::m_n5_pPlayerInitial;
intx5* game::m_n5_pPlayerReroll;
screenelements game::m_ses;
void game::play (
) {
	startUp ();
	while (m_gameaction != gameaction::Exit) {
		m_rw.clear (sf::Color::Green);
		prepareData ();
		prepareScreenElements ();
		draw (m_ses, m_rw);
		m_rw.display ();
		handleEvents ();
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
					m_pokerroundstage_p = new pokerroundstage;
					*m_pokerroundstage_p = pokerroundstage::SubmitInputInitial;
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
				mainmenu::prepare (
					m_bHaveGameData,
					m_bShowMainMenuNewGamePageChoice,
					m_sNewAdventureName,
					m_font,
					m_mainmenupage,
					gamedata_pPlayerConst,
					m_ses
				);
				break;
			}
			case gameaction::Play: {
				switch (*m_gamemode_p) {
					case gamemode::PokerDuel: {
						const pokerroundresult* pokerroundresult_p_Const = m_pokerroundresult_p;
						const pokerroundstage* pokerroundstage_p_Const = m_pokerroundstage_p;
						const gamedata* gamedata_pEnemyConst = m_gamedata_pEnemy;
						const gamedata* gamedata_pPlayerConst = m_gamedata_pPlayer;
						const intx5* n5_pEnemyInitialConst = m_n5_pEnemyInitial;
						const intx5* n5_pEnemyRerollConst = m_n5_pEnemyReroll;
						const intx5* n5_pEnemyUltimateConst = m_n5_pEnemyUltimate;
						const intx5* n5_pPlayerInitialConst = m_n5_pPlayerInitial;
						const intx5* n5_pPlayerRerollConst = m_n5_pPlayerReroll;
						const intx5* n5_pPlayerUltimateConst = m_n5_pPlayerUltimate;
						pokerround::prepare (
							m_nBetAgreed,
							m_nCashInPot,
							m_nCashInPotBefore,
							m_nScoreEnemyInitial,
							m_nScoreEnemyUltimate,
							m_nScorePlayerInitial,
							m_nScorePlayerUltimate,
							m_sBetPlayer,
							m_font,
							pokerroundresult_p_Const,
							pokerroundstage_p_Const,
							gamedata_pEnemyConst,
							gamedata_pPlayerConst,
							n5_pEnemyInitialConst,
							n5_pEnemyRerollConst,
							n5_pEnemyUltimateConst,
							n5_pPlayerInitialConst,
							n5_pPlayerRerollConst,
							n5_pPlayerUltimateConst,
							m_ses
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
) {
	bool bShouldClear_vec_screenelement_p = false;
	sf::Event eventToHandle;
	while (m_rw.pollEvent (eventToHandle)) {
		if (bShouldClear_vec_screenelement_p) {
			//DO NOTHING.  Event is void and event queue must be cleared.
		} else {
			sf::Event::EventType eventtypeToHandle = eventToHandle.type;
			switch (eventtypeToHandle) {
				case sf::Event::Closed: {
					m_gameaction = gameaction::Exit;
					bShouldClear_vec_screenelement_p = true;
					break;
				}
				case sf::Event::MouseButtonPressed: {
					handleMousePress (eventToHandle);
					break;
				}
				case sf::Event::MouseButtonReleased: {
					handleMouseRelease (bShouldClear_vec_screenelement_p, eventToHandle);
					break;
				}
				case sf::Event::TextEntered: {
					handleTextEntered (bShouldClear_vec_screenelement_p, eventToHandle);
					break;
				}
			}
			if (bShouldClear_vec_screenelement_p) {
				clear (m_ses);
				m_bPrepared_vec_screenelement_p = false;
			}
		}
	}
}
void game::shutDown (
) {
	m_rw.close ();
	if (m_bHaveGameData) {
		deleteGameData ();
	}
}
void game::load (
	std::ifstream& ifstream_
) {
	char* ch_p_ = new char;
	ifstream_.read (ch_p_, 1);
	m_gamemode_p = new gamemode;
	*m_gamemode_p = gamemode (*ch_p_);
	switch (*m_gamemode_p) {
		case gamemode::PokerDuel: {
			m_gamedata_pEnemy = new gamedata (ifstream_);
			m_gamedata_pPlayer = new gamedata (ifstream_);
			ifstream_.read (ch_p_, 1);
			m_pokerroundstage_p = new pokerroundstage;
			*m_pokerroundstage_p = pokerroundstage (*ch_p_);
			switch (*m_pokerroundstage_p) {
				case pokerroundstage::SubmitInputSecond:
				case pokerroundstage::OKInputSecond: {
					m_n5_pEnemyInitial = new intx5 (ifstream_);
					m_n5_pEnemyReroll = new intx5 (ifstream_);
					m_n5_pPlayerInitial = new intx5 (ifstream_);
					m_n5_pPlayerReroll = new intx5 (ifstream_);
					break;
				}
				case pokerroundstage::OKResults: {
					m_n5_pEnemyInitial = new intx5 (ifstream_);
					m_n5_pEnemyReroll = new intx5 (ifstream_);
					m_n5_pEnemyUltimate = new intx5 (ifstream_);
					m_n5_pPlayerInitial = new intx5 (ifstream_);
					m_n5_pPlayerReroll = new intx5 (ifstream_);
					m_n5_pPlayerUltimate = new intx5 (ifstream_);
					ifstream_.read (ch_p_, 1);
					m_pokerroundresult_p = new pokerroundresult;
					*m_pokerroundresult_p = pokerroundresult (*ch_p_);
					break;
				}
			}
			break;
		}
		case gamemode::Adventure: {
			break;
		}
	}
	delete ch_p_;
	m_bHaveGameData = true;
}
void game::handleMousePress (
	sf::Event& eventToHandle
) {
	sf::Event::MouseButtonEvent mbe_ = eventToHandle.mouseButton;
	screenelement* se_p_;
	unsigned int nAmountOfElements = m_ses.size ();
	int nElementIndex = nAmountOfElements - 1;
	bool bFoundElementClicked = false;
	bool bShouldLoop = (nAmountOfElements != 0);
	m_bEditAString = false;
	while (bShouldLoop) {
		bShouldLoop = false;
		se_p_ = m_ses[nElementIndex];
		if (se_p_->bClicked (mbe_)) {
			bFoundElementClicked = true;
			m_nSEClickedLast = nElementIndex;
			screenelement_enum se_e_ = se_p_->screenelement_enum_ ();
			switch (se_e_) {
				case screenelement_enum::Button: {
					switch (m_gameaction) {
						case gameaction::WorkMainMenu: {
							mainmenu::screenelement_button* se_btn_p_ = dynamic_cast <mainmenu::screenelement_button*> (se_p_);
							se_btn_p_->set_bIsHeldDown (true);
							m_bClickedAButtonJustNow = true;
							break;
						}
						case gameaction::Play: {
							switch (*m_gamemode_p) {
								case gamemode::PokerDuel: {
									pokerround::screenelement_button* se_btn_p_ = dynamic_cast <pokerround::screenelement_button*> (se_p_);
									se_btn_p_->set_bIsHeldDown (true);
									m_bClickedAButtonJustNow = true;
									break;
								}
							}
							break;
						}
					}
					break;
				}
			}
		}
		if (bFoundElementClicked != true) {
			nElementIndex--;
			if (0 <= nElementIndex)
				bShouldLoop = true;
		}
	}
}
void game::handleMouseRelease (
	bool& bShouldClear_vec_screenelement_p,
	sf::Event& eventToHandle
) {
	if (m_bClickedAButtonJustNow) {
		sf::Event::MouseButtonEvent mbe_ = eventToHandle.mouseButton;
		screenelement* se_p_ = m_ses[m_nSEClickedLast];
		if (se_p_->bClicked (mbe_)) {
			screenelement_enum se_e_ = se_p_->screenelement_enum_ ();
			switch (se_e_) {
				case screenelement_enum::Button: {
					switch (m_gameaction) {
						case gameaction::WorkMainMenu: {
							mainmenu::screenelement_button* se_btn_p_ = dynamic_cast <mainmenu::screenelement_button*> (se_p_);
							mainmenu::screenelement_button_enum se_btn_e_ = se_btn_p_->screenelement_button_enum_ ();
							se_btn_p_->set_bIsHeldDown (false);
							handle (
								bShouldClear_vec_screenelement_p,
								se_btn_e_
							);
							break;
						}
						case gameaction::Play: {
							switch (*m_gamemode_p) {
								case gamemode::PokerDuel: {
									pokerround::screenelement_button* se_btn_p_ = dynamic_cast <pokerround::screenelement_button*> (se_p_);
									pokerround::screenelement_button_enum se_btn_e_ = se_btn_p_->screenelement_button_enum_ ();
									se_btn_p_->set_bIsHeldDown (false);
									handle (
										bShouldClear_vec_screenelement_p,
										se_btn_e_
									);
									break;
								}
							}
							break;
						}
					}
					break;
				}
			}
		}
	}
	m_bClickedAButtonJustNow = false;
}
void game::handleTextEntered (
	bool& bShouldClear_vec_screenelement_p,
	sf::Event& eventToHandle
) {
	if (m_bEditAString) {
		sf::Uint32 nInput = eventToHandle.text.unicode;
		if (nInput < 128) {
			bool bAppendInputToString = false;
			char chInput = nInput;
			if (chInput == 8) { //Backspace
				if (m_s_pToEdit->size () > 0) {
					m_s_pToEdit->pop_back ();
					resetWhatStringTakes ();
					bShouldClear_vec_screenelement_p = true;
				}
			} else if (chInput == 13) { //Enter
				//Maybe use later.
			} else if (isupper (chInput)) {
				if (m_bStringTakesUpper) {
					bAppendInputToString = true;
				}
			} else if (islower (chInput)) {
				if (m_bStringTakesLower) {
					bAppendInputToString = true;
				}
			} else if (isdigit (chInput)) {
				if (m_bStringTakesDigit) {
					bAppendInputToString = true;
				}
			} else if (ispunct (chInput)) {
				if (m_bStringTakesPunctuation) {
					bAppendInputToString = true;
				}
			} else if (isspace (chInput)) {
				if (m_bStringTakesSpace) {
					bAppendInputToString = true;
				}
			}
			if (bAppendInputToString) {
					m_s_pToEdit->operator+= (chInput);
					resetWhatStringTakes ();
					bShouldClear_vec_screenelement_p = true;
			}
		}
	}
}
void game::handle (
	bool& bShouldClear_vec_screenelement_p,
	const mainmenu::screenelement_button_enum& screenelement_button_enumToHandle
) {
	switch (screenelement_button_enumToHandle) {
		case mainmenu::screenelement_button_enum::Exit: {
			m_gameaction = gameaction::Exit;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case mainmenu::screenelement_button_enum::Adjust: {
			if (m_mainmenupage != mainmenupage::Adjust) {
				m_mainmenupage = mainmenupage::Adjust;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Accredit: {
			if (m_mainmenupage != mainmenupage::Accredit) {
				m_mainmenupage = mainmenupage::Accredit;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Play: {
			if (m_bHaveGameData) {
				m_gameaction = gameaction::Play;
			} else {
				if (m_mainmenupage == mainmenupage::NewGame) {
					m_gamemode_p = new gamemode;
					if (m_bShowMainMenuNewGamePageChoice) {
						*m_gamemode_p = gamemode::PokerDuel;
						m_gamedata_pEnemy = new gamedata ("Steve's Bot", 100);
						m_gamedata_pPlayer = new gamedata ("Player", 100);
					} else
						*m_gamemode_p = gamemode::Adventure;
					m_gameaction = gameaction::Play;
				} else {
					m_mainmenupage = mainmenupage::NewGame;
				}
			}
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case mainmenu::screenelement_button_enum::NewGame: {
			if (m_mainmenupage != mainmenupage::NewGame) {
				m_mainmenupage = mainmenupage::NewGame;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Save: {
			if (m_mainmenupage != mainmenupage::Save) {
				m_mainmenupage = mainmenupage::Save;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Load: {
			if (m_mainmenupage != mainmenupage::Load) {
				m_mainmenupage = mainmenupage::Load;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Review: {
			if (m_mainmenupage != mainmenupage::Review) {
				m_mainmenupage = mainmenupage::Review;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::NewQuickGame: {
			if (m_bHaveGameData) {
				deleteGameData ();
			}
			m_gamemode_p = new gamemode;
			*m_gamemode_p = gamemode::PokerDuel;
			m_gamedata_pEnemy = new gamedata ("Steve's Bot", 100);
			m_gamedata_pPlayer = new gamedata ("Player", 100);
			m_gameaction = gameaction::Play;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case mainmenu::screenelement_button_enum::NewAdventure: {
			m_bShowMainMenuNewGamePageChoice = false;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case mainmenu::screenelement_button_enum::NewGameReturn: {
			m_bShowMainMenuNewGamePageChoice = true;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case mainmenu::screenelement_button_enum::NewAdventureName: {
			m_s_pToEdit = &m_sNewAdventureName;
			resetWhatStringTakes ();
			m_bEditAString = true;
			break;
		}
	}
}
void game::handle (
	bool& bShouldClear_vec_screenelement_p,
	const pokerround::screenelement_button_enum& screenelement_button_enumToHandle
) {
	switch (screenelement_button_enumToHandle) {
		case pokerround::screenelement_button_enum::BetAmount: {
			m_s_pToEdit = &m_sBetPlayer;
			resetWhatStringTakes ();
			m_bEditAString = true;
			break;
		}
		case pokerround::screenelement_button_enum::SubmitInputInitial: {
			determineBetAmount (10); //Enemy bet is 10.  Be smarter about it later.
			transactBet (m_nBetAgreed);
			*m_pokerroundstage_p = pokerroundstage::OKInputInitial;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::ChangeInputInitial: {
			transactBet (-1 * m_nBetAgreed);
			*m_pokerroundstage_p = pokerroundstage::SubmitInputInitial;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::OKInputInitial: {
			int nTemp;
			intx5** n5Dice[4] = {
				&m_n5_pEnemyInitial,
				&m_n5_pPlayerInitial,
				&m_n5_pEnemyReroll,
				&m_n5_pPlayerReroll
			};
			for (int i = 0; i < 4; i++) {
				*n5Dice[i] = new intx5;
				for (int j = 0; j < 5; j++) {
					if (i < 2) {
						nTemp = rand ();
						nTemp %= 6;
						nTemp += 1;
					} else {
						nTemp = false;
					}
					(*n5Dice[i])->set_n (j, nTemp);
				}
			}
			*m_pokerroundstage_p = pokerroundstage::SubmitInputSecond;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::DicePlayer0: {
			if (m_n5_pPlayerReroll->n (0) == int (true)) {
				m_n5_pPlayerReroll->set_n (0, int (false));
			} else {
				m_n5_pPlayerReroll->set_n (0, int (true));
			}
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::DicePlayer1: {
			if (m_n5_pPlayerReroll->n (1) == int (true)) {
				m_n5_pPlayerReroll->set_n (1, int (false));
			} else {
				m_n5_pPlayerReroll->set_n (1, int (true));
			}
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::DicePlayer2: {
			if (m_n5_pPlayerReroll->n (2) == int (true)) {
				m_n5_pPlayerReroll->set_n (2, int (false));
			} else {
				m_n5_pPlayerReroll->set_n (2, int (true));
			}
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::DicePlayer3: {
			if (m_n5_pPlayerReroll->n (3) == int (true)) {
				m_n5_pPlayerReroll->set_n (3, int (false));
			} else {
				m_n5_pPlayerReroll->set_n (3, int (true));
			}
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::DicePlayer4: {
			if (m_n5_pPlayerReroll->n (4) == int (true)) {
				m_n5_pPlayerReroll->set_n (4, int (false));
			} else {
				m_n5_pPlayerReroll->set_n (4, int (true));
			}
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::SubmitInputSecond: {
			determineBetAmount (10); //Enemy bet is 10.  Be smarter about it later.
			transactBet (m_nBetAgreed);
			*m_pokerroundstage_p = pokerroundstage::OKInputSecond;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::ChangeInputSecond: {
			transactBet (-1 * m_nBetAgreed);
			*m_pokerroundstage_p = pokerroundstage::SubmitInputSecond;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::OKInputSecond: {
			int nTemp;
			bool bWantToReroll;
			intx5** n5Dice[6] = {
				&m_n5_pEnemyReroll,
				&m_n5_pPlayerReroll,
				&m_n5_pEnemyInitial,
				&m_n5_pPlayerInitial,
				&m_n5_pEnemyUltimate,
				&m_n5_pPlayerUltimate
			};
			diceset* dsEnemyInitial;
			diceset* dsEnemyUltimate;
			diceset* dsPlayerInitial;
			diceset* dsPlayerUltimate;
			for (int i = 0; i < 2; i++) {
				*n5Dice[i+4] = new intx5;
				for (int j = 0; j < 5; j++) {
					bWantToReroll = (*n5Dice[i])->n (j) == int (true);
					if (bWantToReroll) {
						nTemp = rand ();
						nTemp %= 6;
						nTemp += 1;
					} else {
						nTemp = (*n5Dice[i+2])->n (j);
					}
					(*n5Dice[i+4])->set_n (j, nTemp);
				}
			}
			m_nCashInPotBefore = m_nCashInPot;
			dsEnemyInitial = diceset_p_ (*m_n5_pEnemyInitial);
			dsEnemyUltimate = diceset_p_ (*m_n5_pEnemyUltimate);
			dsPlayerInitial = diceset_p_ (*m_n5_pPlayerInitial);
			dsPlayerUltimate = diceset_p_ (*m_n5_pPlayerUltimate);
			m_nScoreEnemyInitial = dsEnemyInitial->nScore ();
			m_nScoreEnemyUltimate = dsEnemyUltimate->nScore ();
			m_nScorePlayerInitial = dsPlayerInitial->nScore ();
			m_nScorePlayerUltimate = dsPlayerUltimate->nScore ();
			delete dsEnemyInitial;
			delete dsEnemyUltimate;
			delete dsPlayerInitial;
			delete dsPlayerUltimate;
			m_pokerroundresult_p = new pokerroundresult;
			if (m_nScorePlayerUltimate < m_nScoreEnemyUltimate) {
				*m_pokerroundresult_p = pokerroundresult::Win;
			} else if (m_nScorePlayerUltimate == m_nScoreEnemyUltimate) {
				*m_pokerroundresult_p = pokerroundresult::Tie;
			} else {
				*m_pokerroundresult_p = pokerroundresult::Loss;
			}
			switch (*m_pokerroundresult_p) {
				case pokerroundresult::Win: {
					int nDollarsCarriedPlayerInitial = m_gamedata_pPlayer->nDollarsCarried ();
					int nDollarsCarriedPlayerResult = nDollarsCarriedPlayerInitial + m_nCashInPot;
					m_gamedata_pPlayer->set_nDollarsCarried (nDollarsCarriedPlayerResult);
					break;
				}
				case pokerroundresult::Tie: {
					int nDollarsCarriedEnemyInitial = m_gamedata_pEnemy->nDollarsCarried ();
					int nDollarsCarriedEnemyResult = nDollarsCarriedEnemyInitial + m_nCashInPot / 2;
					int nDollarsCarriedPlayerInitial = m_gamedata_pPlayer->nDollarsCarried ();
					int nDollarsCarriedPlayerResult = nDollarsCarriedPlayerInitial + m_nCashInPot / 2;
					m_gamedata_pEnemy->set_nDollarsCarried (nDollarsCarriedEnemyResult);
					m_gamedata_pPlayer->set_nDollarsCarried (nDollarsCarriedPlayerResult);
					break;
				}
				case pokerroundresult::Loss: {
					int nDollarsCarriedEnemyInitial = m_gamedata_pEnemy->nDollarsCarried ();
					int nDollarsCarriedEnemyResult = nDollarsCarriedEnemyInitial + m_nCashInPot;
					m_gamedata_pEnemy->set_nDollarsCarried (nDollarsCarriedEnemyResult);
					break;
				}
			}
			m_nCashInPot = 0;
			*m_pokerroundstage_p = pokerroundstage::OKResults;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case pokerround::screenelement_button_enum::OKResult: {
			handlePokerRoundEnd (bShouldClear_vec_screenelement_p);
			break;
		}
	}
}
void game::handlePokerRoundEnd (
	bool& bShouldClear_vec_screenelement_p
) {
	switch (*m_gamemode_p) {
		case gamemode::PokerDuel: {
			int nCashEnemy = m_gamedata_pEnemy->nDollarsCarried ();
			int nCashPlayer = m_gamedata_pPlayer->nDollarsCarried ();
			bool bKeepPlaying = 0 < nCashPlayer && 0 < nCashEnemy;
			if (bKeepPlaying) {
				deletePokerRoundData ();
				m_bHaveGameData = false;
				//Since both m_gameaction and m_gamemode_p are left untouched,
				//this will create a new poker round with the same participants.
			} else {
				//GAME OVER
				deleteGameData ();
				m_bHaveGameData = false;
				m_gameaction = gameaction::WorkMainMenu;
			}
			break;
		}
		case gamemode::Adventure: {
			//WILL DO LATER
			break;
		}
	}
	bShouldClear_vec_screenelement_p = true;
}
void game::deleteGameData (
) {
	switch (*m_gamemode_p) {
		case gamemode::PokerDuel: {
			deletePokerRoundData ();
			delete m_gamedata_pEnemy;
			delete m_gamedata_pPlayer;
			break;
		}
		case gamemode::Adventure: {
			//WILL DO LATER
			break;
		}
	}
	delete m_gamemode_p;
}
void game::deletePokerRoundData (
) {
	switch (*m_pokerroundstage_p) {
		case pokerroundstage::SubmitInputSecond:
		case pokerroundstage::OKInputSecond: {
			delete m_n5_pEnemyInitial;
			delete m_n5_pPlayerInitial;
			delete m_n5_pEnemyReroll;
			delete m_n5_pPlayerReroll;
			break;
		}
		case pokerroundstage::OKResults: {
			delete m_n5_pEnemyInitial;
			delete m_n5_pPlayerInitial;
			delete m_n5_pEnemyReroll;
			delete m_n5_pPlayerReroll;
			delete m_n5_pEnemyUltimate;
			delete m_n5_pPlayerUltimate;
			delete m_pokerroundresult_p;
			break;
		}
	}
	delete m_pokerroundstage_p;
}
void game::makeStringTakeNothing () {
	m_bStringTakesUpper = false;
	m_bStringTakesLower = false;
	m_bStringTakesDigit = false;
	m_bStringTakesPunctuation = false;
	m_bStringTakesSpace = false;
}
void game::resetWhatStringTakes () {
	makeStringTakeNothing ();
	if (m_s_pToEdit == & m_sNewAdventureName) {
		if (m_sNewAdventureName.size () == 0) {
			m_bStringTakesUpper = true;
		} else {
			m_bStringTakesLower = true;
		}
	} else if (m_s_pToEdit == &m_sBetPlayer) {
		m_bStringTakesDigit = true;
	}
}
void game::determineBetAmount (const int& nBetEnemy) {
	int nBetPlayer = std::stoi (m_sBetPlayer);
	nBetPlayer = std::max (0, nBetPlayer); //Player can't bet a negative
	nBetPlayer = std::min (nBetPlayer, m_gamedata_pPlayer->nDollarsCarried ()); //Player can't bet more than he has.
	m_nBetAgreed = std::min (nBetPlayer, nBetEnemy); //Bet is the least of the bids placed.
}
void game::transactBet (const int& nBetAmount) {
	m_gamedata_pEnemy->set_nDollarsCarried (m_gamedata_pEnemy-> nDollarsCarried () - nBetAmount);
	m_gamedata_pPlayer->set_nDollarsCarried (m_gamedata_pPlayer-> nDollarsCarried () - nBetAmount);
	m_nCashInPot += 2 * nBetAmount;
}