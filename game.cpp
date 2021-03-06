#include "game.h"
#include "iofunctions.h"
#include <ctime>
#include <cstdlib>
int game::m_nSEClickedLast;
bool game::m_bStringTakesUpper = false;
bool game::m_bStringTakesLower = false;
bool game::m_bStringTakesDigit = false;
bool game::m_bStringTakesPunctuation = false;
bool game::m_bStringTakesSpace = false;
bool game::m_bClickedAButtonJustNow = false;
bool game::m_bEditAString = false;
bool game::m_bHaveGameData = false;
bool game::m_bPrepared_ses = false;
bool game::m_bShowMainMenuNewGamePageChoice = true;
std::string game::m_sLoadSource = "default save.txt";
std::string game::m_sNewAdventureName = "TEST";
std::string game::m_sSaveDestination = "default save.txt";
std::string* game::m_s_pToEdit;
sf::Font game::m_font;
sf::RenderWindow game::m_rw;
gameaction game::m_gameaction = gameaction::WorkMainMenu;
gamemode game::m_gamemode;
mainmenupage game::m_mainmenupage = mainmenupage::Splash;
pokerround::variableset0* game::m_prvs0_p;
pokerround::variableset1* game::m_prvs1_p;
pokerround::variableset2* game::m_prvs2_p;
adventure::variableset0* game::m_avs0_p;
screenelements game::m_ses;
adventure::variableset0::variableset0 (
	const std::string& sPlayerName
) {
	m_gamedata_pPlayer = new gamedata (sPlayerName, 100);
}
adventure::variableset0::variableset0 (
	std::ifstream& ifstream_
) {
	m_gamedata_pPlayer = new gamedata (ifstream_);
}
adventure::variableset0::~variableset0 (
) {
	delete m_gamedata_pPlayer;
}
void iofunctions::write (
	const adventure::variableset0& avs0_,
	std::ofstream& ofstream_
) {
	write (*avs0_.m_gamedata_pPlayer, ofstream_);
}
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
	ifstream_.open (m_sSaveDestination);
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
			switch (m_gamemode) {
				case gamemode::PokerDuel: {
					m_prvs0_p->set_nCashInPot (0);
					m_prvs0_p->set_pokerroundstage (pokerroundstage::SubmitInputInitial);
					m_bHaveGameData = true;
					break;
				}
				case gamemode::Adventure: {
					//WILL DO LATER
					m_bHaveGameData = true;
					break;
				}
			}
		}
	}
}
void game::prepareScreenElements (
) {
	if (m_bPrepared_ses != true) {
		switch (m_gameaction) {
			case gameaction::WorkMainMenu: {
				mainmenu::prepare (
					m_bHaveGameData,
					m_bShowMainMenuNewGamePageChoice,
					m_sLoadSource,
					m_sNewAdventureName,
					m_sSaveDestination,
					m_font,
					m_mainmenupage,
					m_prvs0_p->gamedata_pPlayer (),
					m_ses
				);
				break;
			}
			case gameaction::Play: {
				switch (m_gamemode) {
					case gamemode::PokerDuel: {
						pokerround::prepare (
							m_font,
							(const pokerround::variableset0*&) (m_prvs0_p),
							(const pokerround::variableset1*&) (m_prvs1_p),
							(const pokerround::variableset2*&) (m_prvs2_p),
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
		m_bPrepared_ses = true;
	}
}
void game::handleEvents (
) {
	bool bShouldClear_ses = false;
	sf::Event eventToHandle;
	while (m_rw.pollEvent (eventToHandle)) {
		if (bShouldClear_ses) {
			//DO NOTHING.  Event is void and event queue must be cleared.
		} else {
			sf::Event::EventType eventtypeToHandle = eventToHandle.type;
			switch (eventtypeToHandle) {
				case sf::Event::Closed: {
					m_gameaction = gameaction::Exit;
					bShouldClear_ses = true;
					break;
				}
				case sf::Event::MouseButtonPressed: {
					handleMousePress (eventToHandle);
					break;
				}
				case sf::Event::MouseButtonReleased: {
					handleMouseRelease (bShouldClear_ses, eventToHandle);
					break;
				}
				case sf::Event::TextEntered: {
					handleTextEntered (bShouldClear_ses, eventToHandle);
					break;
				}
			}
			if (bShouldClear_ses) {
				clear (m_ses);
				m_bPrepared_ses = false;
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
							switch (m_gamemode) {
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
	bool& bShouldClear_ses,
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
								bShouldClear_ses,
								se_btn_e_
							);
							break;
						}
						case gameaction::Play: {
							switch (m_gamemode) {
								case gamemode::PokerDuel: {
									pokerround::screenelement_button* se_btn_p_ = dynamic_cast <pokerround::screenelement_button*> (se_p_);
									pokerround::screenelement_button_enum se_btn_e_ = se_btn_p_->screenelement_button_enum_ ();
									se_btn_p_->set_bIsHeldDown (false);
									handle (
										bShouldClear_ses,
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
	bool& bShouldClear_ses,
	sf::Event& eventToHandle
) {
	if (m_bEditAString) {
		editAString (
			bShouldClear_ses,
			eventToHandle.text.unicode
		);
	} else {
		if (m_gameaction == gameaction::Play) {
			handlePlayBind (
				bShouldClear_ses,
				eventToHandle.text.unicode
			);
		}
	}
}
void game::editAString (
	bool& bShouldClear_vec_screenelement_p,
	const sf::Uint32& nInput
) {
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
void game::handlePlayBind (
	bool& bShouldClear_ses,
	const sf::Uint32& nInput
) {
	if (nInput == 27) { //Escape
		m_gameaction = gameaction::WorkMainMenu;
		bShouldClear_ses = true;
	}
}
void game::handle (
	bool& bShouldClear_ses,
	const mainmenu::screenelement_button_enum& screenelement_button_enumToHandle
) {
	switch (screenelement_button_enumToHandle) {
		case mainmenu::screenelement_button_enum::Exit: {
			m_gameaction = gameaction::Exit;
			bShouldClear_ses = true;
			break;
		}
		case mainmenu::screenelement_button_enum::Adjust: {
			if (m_mainmenupage != mainmenupage::Adjust) {
				m_mainmenupage = mainmenupage::Adjust;
				bShouldClear_ses = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Accredit: {
			if (m_mainmenupage != mainmenupage::Accredit) {
				m_mainmenupage = mainmenupage::Accredit;
				bShouldClear_ses = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Play: {
			if (m_bHaveGameData) {
				m_gameaction = gameaction::Play;
			} else {
				if (m_mainmenupage == mainmenupage::NewGame) {
					if (m_bShowMainMenuNewGamePageChoice) {
						m_gamemode = gamemode::PokerDuel;
						m_prvs0_p = new pokerround::variableset0;
					} else {
						m_gamemode = gamemode::Adventure;
						m_avs0_p = new adventure::variableset0 (m_sNewAdventureName);
					}
					m_gameaction = gameaction::Play;
				} else {
					m_mainmenupage = mainmenupage::NewGame;
				}
			}
			bShouldClear_ses = true;
			break;
		}
		case mainmenu::screenelement_button_enum::NewGame: {
			if (m_mainmenupage != mainmenupage::NewGame) {
				m_mainmenupage = mainmenupage::NewGame;
				bShouldClear_ses = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Save: {
			if (m_mainmenupage != mainmenupage::Save) {
				m_mainmenupage = mainmenupage::Save;
				bShouldClear_ses = true;
			} else {
				if (m_bHaveGameData) {
					std::ofstream ofstream_;
					ofstream_.open (m_sSaveDestination);
					if (ofstream_.is_open ()) {
						save (
							ofstream_
						);
						ofstream_.close ();
					}
				}
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Load: {
			if (m_mainmenupage != mainmenupage::Load) {
				m_mainmenupage = mainmenupage::Load;
				bShouldClear_ses = true;
			} else {
				std::ifstream ifstream_;
				ifstream_.open (m_sLoadSource);
				if (ifstream_.is_open ()) {
					load (
						ifstream_
					);
					ifstream_.close ();
				}
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Review: {
			if (m_mainmenupage != mainmenupage::Review) {
				m_mainmenupage = mainmenupage::Review;
				bShouldClear_ses = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::Title: {
			if (m_mainmenupage != mainmenupage::Splash) {
				m_mainmenupage = mainmenupage::Splash;
				bShouldClear_ses = true;
			}
			break;
		}
		case mainmenu::screenelement_button_enum::NewQuickGame: {
			if (m_bHaveGameData) {
				deleteGameData ();
				m_bHaveGameData = false;
			}
			m_gamemode = gamemode::PokerDuel;
			m_prvs0_p = new pokerround::variableset0;
			m_gameaction = gameaction::Play;
			bShouldClear_ses = true;
			break;
		}
		case mainmenu::screenelement_button_enum::NewAdventure: {
			m_bShowMainMenuNewGamePageChoice = false;
			bShouldClear_ses = true;
			break;
		}
		case mainmenu::screenelement_button_enum::NewGameReturn: {
			m_bShowMainMenuNewGamePageChoice = true;
			bShouldClear_ses = true;
			break;
		}
		case mainmenu::screenelement_button_enum::NewAdventureName: {
			m_s_pToEdit = &m_sNewAdventureName;
			resetWhatStringTakes ();
			m_bEditAString = true;
			break;
		}
		case mainmenu::screenelement_button_enum::NewAdventureStart: {
			if (m_bHaveGameData) {
				deleteGameData ();
				m_bHaveGameData = false;
			}
			m_gamemode = gamemode::Adventure;
			m_avs0_p = new adventure::variableset0 (m_sNewAdventureName);
			m_gameaction = gameaction::Play;
			bShouldClear_ses = true;
			break;
		}
		case mainmenu::screenelement_button_enum::SaveDestination: {
			m_s_pToEdit = &m_sSaveDestination;
			resetWhatStringTakes ();
			m_bEditAString = true;
			break;
		}
		case mainmenu::screenelement_button_enum::LoadSource: {
			m_s_pToEdit = &m_sLoadSource;
			resetWhatStringTakes ();
			m_bEditAString = true;
			break;
		}
	}
}
void game::handle (
	bool& bShouldClear_ses,
	const pokerround::screenelement_button_enum& screenelement_button_enumToHandle
) {
	switch (screenelement_button_enumToHandle) {
		case pokerround::screenelement_button_enum::BetAmount: {
			m_s_pToEdit = m_prvs0_p->sBetPlayer_p ();
			resetWhatStringTakes ();
			m_bEditAString = true;
			break;
		}
		case pokerround::screenelement_button_enum::SubmitInputInitial: {
			determineBetAmount (10); //Enemy bet is 10.  Be smarter about it later.
			transactBet (m_prvs0_p->nBetAgreed ());
			m_prvs0_p->set_pokerroundstage (pokerroundstage::OKInputInitial);
			bShouldClear_ses = true;
			break;
		}
		case pokerround::screenelement_button_enum::ChangeInputInitial: {
			transactBet (-1 * m_prvs0_p->nBetAgreed ());
			m_prvs0_p->set_pokerroundstage (pokerroundstage::SubmitInputInitial);
			bShouldClear_ses = true;
			break;
		}
		case pokerround::screenelement_button_enum::OKInputInitial: {
			m_prvs1_p = new pokerround::variableset1;
			for (int i = 0; i < 5; i++) {
				m_prvs1_p->set_nDiceEnemyInitial (i, nRandomDice ());
				m_prvs1_p->set_nDiceEnemyReroll (i, false);
				m_prvs1_p->set_nDicePlayerInitial (i, nRandomDice ());
				m_prvs1_p->set_nDicePlayerReroll (i, false);
			}
			m_prvs0_p->set_pokerroundstage (pokerroundstage::SubmitInputSecond);
			bShouldClear_ses = true;
			break;
		}
		case pokerround::screenelement_button_enum::DicePlayer0: {
			if (m_prvs0_p->pokerroundstage_ () == pokerroundstage::SubmitInputSecond) {
				if (m_prvs1_p->n5DicePlayerReroll ()[0] == int (true)) {
					m_prvs1_p->set_nDicePlayerReroll (0, false);
				} else {
					m_prvs1_p->set_nDicePlayerReroll (0, true);
				}
				bShouldClear_ses = true;
			}
			break;
		}
		case pokerround::screenelement_button_enum::DicePlayer1: {
			if (m_prvs0_p->pokerroundstage_ () == pokerroundstage::SubmitInputSecond) {
				if (m_prvs1_p->n5DicePlayerReroll ()[1] == int (true)) {
					m_prvs1_p->set_nDicePlayerReroll (1, false);
				} else {
					m_prvs1_p->set_nDicePlayerReroll (1, true);
				}
				bShouldClear_ses = true;
			}
			break;
		}
		case pokerround::screenelement_button_enum::DicePlayer2: {
			if (m_prvs0_p->pokerroundstage_ () == pokerroundstage::SubmitInputSecond) {
				if (m_prvs1_p->n5DicePlayerReroll ()[2] == int (true)) {
					m_prvs1_p->set_nDicePlayerReroll (2, false);
				} else {
					m_prvs1_p->set_nDicePlayerReroll (2, true);
				}
				bShouldClear_ses = true;
			}
			break;
		}
		case pokerround::screenelement_button_enum::DicePlayer3: {
			if (m_prvs0_p->pokerroundstage_ () == pokerroundstage::SubmitInputSecond) {
				if (m_prvs1_p->n5DicePlayerReroll ()[3] == int (true)) {
					m_prvs1_p->set_nDicePlayerReroll (3, false);
				} else {
					m_prvs1_p->set_nDicePlayerReroll (3, true);
				}
				bShouldClear_ses = true;
			}
			break;
		}
		case pokerround::screenelement_button_enum::DicePlayer4: {
			if (m_prvs0_p->pokerroundstage_ () == pokerroundstage::SubmitInputSecond) {
				if (m_prvs1_p->n5DicePlayerReroll ()[4] == int (true)) {
					m_prvs1_p->set_nDicePlayerReroll (4, false);
				} else {
					m_prvs1_p->set_nDicePlayerReroll (4, true);
				}
				bShouldClear_ses = true;
			}
			break;
		}
		case pokerround::screenelement_button_enum::SubmitInputSecond: {
			determineBetAmount (10); //Enemy bet is 10.  Be smarter about it later.
			transactBet (m_prvs0_p->nBetAgreed ());
			m_prvs0_p->set_pokerroundstage (pokerroundstage::OKInputSecond);
			bShouldClear_ses = true;
			break;
		}
		case pokerround::screenelement_button_enum::ChangeInputSecond: {
			transactBet (-1 * m_prvs0_p->nBetAgreed ());
			m_prvs0_p->set_pokerroundstage (pokerroundstage::SubmitInputSecond);
			bShouldClear_ses = true;
			break;
		}
		case pokerround::screenelement_button_enum::OKInputSecond: {
			int nTemp;
			bool bWantToReroll;
			intx5 n5DiceEnemyInitial = m_prvs1_p->n5DiceEnemyInitial ();
			intx5 n5DiceEnemyReroll = m_prvs1_p->n5DiceEnemyReroll ();
			intx5 n5DicePlayerInitial = m_prvs1_p->n5DicePlayerInitial ();
			intx5 n5DicePlayerReroll = m_prvs1_p->n5DicePlayerReroll ();
			diceset* dsEnemyInitial;
			diceset* dsEnemyUltimate;
			diceset* dsPlayerInitial;
			diceset* dsPlayerUltimate;
			m_prvs2_p = new pokerround::variableset2;
			for (int i = 0; i < 5; i++) {
				bWantToReroll = n5DiceEnemyReroll[i] == int (true);
				if (bWantToReroll) {
						nTemp = nRandomDice ();
				} else {
					nTemp = n5DiceEnemyInitial[i];
				}
				m_prvs2_p->set_nDiceEnemyUltimate (i, nTemp);
				bWantToReroll = n5DicePlayerReroll[i] == int (true);
				if (bWantToReroll) {
						nTemp = nRandomDice ();
				} else {
					nTemp = n5DicePlayerInitial[i];
				}
				m_prvs2_p->set_nDicePlayerUltimate (i, nTemp);
			}
			m_prvs2_p->set_nCashInPotBefore (m_prvs0_p->nCashInPot ());
			dsEnemyInitial = diceset_p_ (n5DiceEnemyInitial);
			dsEnemyUltimate = diceset_p_ (m_prvs2_p->n5DiceEnemyUltimate ());
			dsPlayerInitial = diceset_p_ (n5DicePlayerInitial);
			dsPlayerUltimate = diceset_p_ (m_prvs2_p->n5DicePlayerUltimate ());
			m_prvs2_p->set_nScoreEnemyInitial (dsEnemyInitial->nScore ());
			m_prvs2_p->set_nScoreEnemyUltimate (dsEnemyUltimate->nScore ());
			m_prvs2_p->set_nScorePlayerInitial (dsPlayerInitial->nScore ());
			m_prvs2_p->set_nScorePlayerUltimate (dsPlayerUltimate->nScore ());
			delete dsEnemyInitial;
			delete dsEnemyUltimate;
			delete dsPlayerInitial;
			delete dsPlayerUltimate;
			if (m_prvs2_p->nScorePlayerUltimate () < m_prvs2_p->nScoreEnemyUltimate ()) {
				m_prvs2_p->set_pokerroundresult (pokerroundresult::Win);
			} else if (m_prvs2_p->nScorePlayerUltimate () == m_prvs2_p->nScoreEnemyUltimate ()) {
				m_prvs2_p->set_pokerroundresult (pokerroundresult::Tie);
			} else {
				m_prvs2_p->set_pokerroundresult (pokerroundresult::Loss);
			}
			switch (m_prvs2_p->pokerroundresult_ ()) {
				case pokerroundresult::Win: {
					int nDollarsCarriedPlayerInitial = m_prvs0_p->gamedata_pPlayer ()->nDollarsCarried ();
					int nDollarsCarriedPlayerResult = nDollarsCarriedPlayerInitial + m_prvs0_p->nCashInPot ();
					m_prvs0_p->set_nDollarsCarriedPlayer (nDollarsCarriedPlayerResult);
					break;
				}
				case pokerroundresult::Tie: {
					int nDollarsCarriedEnemyInitial = m_prvs0_p->gamedata_pEnemy ()->nDollarsCarried ();
					int nDollarsCarriedEnemyResult = nDollarsCarriedEnemyInitial + m_prvs0_p->nCashInPot () / 2;
					int nDollarsCarriedPlayerInitial = m_prvs0_p->gamedata_pPlayer ()->nDollarsCarried ();
					int nDollarsCarriedPlayerResult = nDollarsCarriedPlayerInitial + m_prvs0_p->nCashInPot () / 2;
					m_prvs0_p->set_nDollarsCarriedEnemy (nDollarsCarriedEnemyResult);
					m_prvs0_p->set_nDollarsCarriedPlayer (nDollarsCarriedPlayerResult);
					break;
				}
				case pokerroundresult::Loss: {
					int nDollarsCarriedEnemyInitial = m_prvs0_p->gamedata_pEnemy ()->nDollarsCarried ();
					int nDollarsCarriedEnemyResult = nDollarsCarriedEnemyInitial + m_prvs0_p->nCashInPot ();
					m_prvs0_p->set_nDollarsCarriedEnemy (nDollarsCarriedEnemyResult);
					break;
				}
			}
			m_prvs0_p->set_nCashInPot (0);
			m_prvs0_p->set_pokerroundstage (pokerroundstage::OKResults);
			bShouldClear_ses = true;
			break;
		}
		case pokerround::screenelement_button_enum::OKResult: {
			handlePokerRoundEnd (bShouldClear_ses);
			break;
		}
	}
}
int game::nRandomDice (
) {
	int nRandomDice = rand ();
	nRandomDice %= 6;
	nRandomDice += 1;
	return nRandomDice;
}
void game::handlePokerRoundEnd (
	bool& bShouldClear_ses
) {
	switch (m_gamemode) {
		case gamemode::PokerDuel: {
			int nCashEnemy = m_prvs0_p->gamedata_pEnemy ()->nDollarsCarried ();
			int nCashPlayer = m_prvs0_p->gamedata_pPlayer ()->nDollarsCarried ();
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
	bShouldClear_ses = true;
}
void game::load (
	std::ifstream& ifstream_
) {
	m_gamemode = gamemode (iofunctions::nReading (ifstream_));
	switch (m_gamemode) {
		case gamemode::PokerDuel: {
			m_prvs0_p = new pokerround::variableset0 (ifstream_);
			switch (m_prvs0_p->pokerroundstage_ ()) {
				case pokerroundstage::SubmitInputSecond:
				case pokerroundstage::OKInputSecond: {
					m_prvs1_p = new pokerround::variableset1 (ifstream_);
					break;
				}
				case pokerroundstage::OKResults: {
					m_prvs1_p = new pokerround::variableset1 (ifstream_);
					m_prvs2_p = new pokerround::variableset2 (ifstream_);
					break;
				}
			}
			break;
		}
		case gamemode::Adventure: {
			m_avs0_p = new adventure::variableset0 (ifstream_);
			//WILL DO LATER
			break;
		}
	}
	m_bHaveGameData = true;
}
void game::save (
	std::ofstream& ofstream_
) {
	iofunctions::write (int (m_gamemode), ofstream_);
	switch (m_gamemode) {
		case gamemode::PokerDuel: {
			iofunctions::write (*m_prvs0_p, ofstream_);
			switch (m_prvs0_p->pokerroundstage_ ()) {
				case pokerroundstage::SubmitInputSecond:
				case pokerroundstage::OKInputSecond: {
					iofunctions::write (*m_prvs1_p, ofstream_);
					break;
				}
				case pokerroundstage::OKResults: {
					iofunctions::write (*m_prvs1_p, ofstream_);
					iofunctions::write (*m_prvs2_p, ofstream_);
					break;
				}
			}
			break;
		}
		case gamemode::Adventure: {
			iofunctions::write (*m_avs0_p, ofstream_);
			//WILL DO LATER
			break;
		}
	}
}
void game::deleteGameData (
) {
	switch (m_gamemode) {
		case gamemode::PokerDuel: {
			deletePokerRoundData ();
			delete m_prvs0_p;
			break;
		}
		case gamemode::Adventure: {
			delete m_avs0_p;
			//WILL DO LATER
			break;
		}
	}
}
void game::deletePokerRoundData (
) {
	switch (m_prvs0_p->pokerroundstage_ ()) {
		case pokerroundstage::SubmitInputSecond:
		case pokerroundstage::OKInputSecond: {
			delete m_prvs1_p;
			break;
		}
		case pokerroundstage::OKResults: {
			delete m_prvs1_p;
			delete m_prvs2_p;
			break;
		}
	}
}
void game::makeStringTakeNothing (
) {
	m_bStringTakesUpper = false;
	m_bStringTakesLower = false;
	m_bStringTakesDigit = false;
	m_bStringTakesPunctuation = false;
	m_bStringTakesSpace = false;
}
void game::resetWhatStringTakes (
) {
	makeStringTakeNothing ();
	if (m_s_pToEdit == m_prvs0_p->sBetPlayer_p ()) {
		m_bStringTakesDigit = true;
	} else if (m_s_pToEdit == & m_sLoadSource) {
		m_bStringTakesDigit = true;
		m_bStringTakesLower = true;
		m_bStringTakesSpace = true;
		m_bStringTakesUpper = true;
	} else if (m_s_pToEdit == & m_sNewAdventureName) {
		if (m_sNewAdventureName.size () == 0) {
			m_bStringTakesUpper = true;
		} else {
			m_bStringTakesLower = true;
		}
	} else if (m_s_pToEdit == &m_sSaveDestination) {
		m_bStringTakesDigit = true;
		m_bStringTakesLower = true;
		m_bStringTakesSpace = true;
		m_bStringTakesUpper = true;
	}
}
void game::determineBetAmount (
	const int& nBetEnemy
) {
	int nBetPlayer = std::stoi (m_prvs0_p->sBetPlayer ());
	nBetPlayer = std::max (0, nBetPlayer); //Player can't bet a negative
	nBetPlayer = std::min (nBetPlayer, m_prvs0_p->gamedata_pPlayer ()->nDollarsCarried ()); //Player can't bet more than he has.
	m_prvs0_p->set_nBetAgreed (std::min (nBetPlayer, nBetEnemy)); //Bet is the least of the bids placed.
}
void game::transactBet (
	const int& nBetAmount
) {
	m_prvs0_p->set_nDollarsCarriedEnemy (m_prvs0_p->gamedata_pEnemy ()-> nDollarsCarried () - nBetAmount);
	m_prvs0_p->set_nDollarsCarriedPlayer (m_prvs0_p->gamedata_pPlayer ()-> nDollarsCarried () - nBetAmount);
	m_prvs0_p->set_nCashInPot (m_prvs0_p->nCashInPot () + 2 * nBetAmount);
}