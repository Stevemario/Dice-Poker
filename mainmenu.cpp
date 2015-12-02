#include "mainmenu.h"
void menu_main::work (
	int& nSEClickedLast,
	bool& bClickedAButtonJustNow,
	bool& bEditAString,
	bool& bHaveGameData,
	bool& bPrepared_vec_screenelement_p,
	bool& bShowMainMenuNewGamePageChoice,
	std::string& sNewAdventureName,
	std::string*& s_pToEdit,
	const sf::Font& font_,
	sf::RenderWindow& rw_,
	gameaction& gameaction_,
	gamemode*& gamemode_p_,
	mainmenupage& mainmenupage_,
	gamedata*& gamedata_pEnemy,
	gamedata*& gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_p_
) {
	bool bShouldClear_vec_screenelement_p = false;
	sf::Event event_;
	if (bPrepared_vec_screenelement_p != true) {
		const gamedata* gamedata_pPlayerConst = gamedata_pPlayer;
		prepare (
			bHaveGameData,
			bShowMainMenuNewGamePageChoice,
			sNewAdventureName,
			font_,
			mainmenupage_,
			gamedata_pPlayerConst,
			vec_screenelement_p_
		);
		bPrepared_vec_screenelement_p = true;
	}
	draw (vec_screenelement_p_, rw_);
	rw_.display ();
	while (rw_.pollEvent (event_)) {
		if (bShouldClear_vec_screenelement_p) {
			//DO NOTHING.  Event is void and event queue must be cleared.
		} else {
			handle (
				nSEClickedLast,
				bClickedAButtonJustNow,
				bEditAString,
				bHaveGameData,
				bShowMainMenuNewGamePageChoice,
				sNewAdventureName,
				s_pToEdit,
				gameaction_,
				gamemode_p_,
				mainmenupage_,
				gamedata_pEnemy,
				gamedata_pPlayer,
				vec_screenelement_p_,
				bShouldClear_vec_screenelement_p,
				event_
			);
			if (bShouldClear_vec_screenelement_p) {
				clear (vec_screenelement_p_);
				bPrepared_vec_screenelement_p = false;
			}
		}
	}
}
void menu_main::prepare (
	const bool& bHaveGameData,
	const bool& bShowMainMenuNewGamePageChoice,
	const std::string& sNewAdventureName,
	const sf::Font& fontToUse,
	const mainmenupage& mainmenupage_,
	const gamedata*& gamedata_pPlayer,
	std::vector <screenelement*>& vec_screenelement_pToPrepare
) {
	switch (mainmenupage_) {
		case mainmenupage::Splash: {
			addPageSplash (fontToUse, vec_screenelement_pToPrepare);
			break;
		}
		case mainmenupage::Adjust: {
			addPageAdjust (fontToUse, vec_screenelement_pToPrepare);
			break;
		}
		case mainmenupage::Accredit: {
			addPageAccredit (fontToUse, vec_screenelement_pToPrepare);
			break;
		}
		case mainmenupage::NewGame: {
			addPageNewGame (
				bHaveGameData,
				bShowMainMenuNewGamePageChoice,
				sNewAdventureName,
				fontToUse,
				vec_screenelement_pToPrepare
			);
			break;
		}
	}
	addButtonsPageSwitching (fontToUse, vec_screenelement_pToPrepare);
}
void menu_main::handle (
	int& nSEClickedLast,
	bool& bClickedAButtonJustNow,
	bool& bEditAString,
	bool& bHaveGameData,
	bool& bShowMainMenuNewGamePageChoice,
	std::string& sNewAdventureName,
	std::string*& s_pToEdit,
	gameaction& gameaction_,
	gamemode*& gamemode_p_,
	mainmenupage& mainmenupage_,
	gamedata*& gamedata_pEnemy,
	gamedata*& gamedata_pPlayer,
	const std::vector <screenelement*>& vec_screenelement_p_,
	bool& bShouldClear_vec_screenelement_p,
	const sf::Event& eventToHandle
) {
	sf::Event::EventType eventtypeToHandle = eventToHandle.type;
	switch (eventtypeToHandle) {
		case sf::Event::Closed: {
			gameaction_ = gameaction::Exit;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case sf::Event::MouseButtonPressed: {
			sf::Event::MouseButtonEvent mbe_ = eventToHandle.mouseButton;
			screenelement* se_p_;
			unsigned int nAmountOfElements = vec_screenelement_p_.size ();
			int nElementIndex = nAmountOfElements - 1;
			bool bFoundElementClicked = false;
			bool bShouldLoop = (nAmountOfElements != 0);
			bEditAString = false;
			while (bShouldLoop) {
				bShouldLoop = false;
				se_p_ = vec_screenelement_p_[nElementIndex];
				if (se_p_->bClicked (mbe_)) {
					bFoundElementClicked = true;
					nSEClickedLast = nElementIndex;
					screenelement_enum se_e_ = se_p_->screenelement_enum_ ();
					switch (se_e_) {
						case screenelement_enum::Button: {
							screenelement_button* se_btn_p_ = dynamic_cast <screenelement_button*> (se_p_);
							se_btn_p_->set_bIsHeldDown (true);
							bClickedAButtonJustNow = true;
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
			break;
		}
		case sf::Event::MouseButtonReleased: {
			if (bClickedAButtonJustNow) {
				sf::Event::MouseButtonEvent mbe_ = eventToHandle.mouseButton;
				screenelement* se_p_ = vec_screenelement_p_[nSEClickedLast];
				if (se_p_->bClicked (mbe_)) {
					screenelement_enum se_e_ = se_p_->screenelement_enum_ ();
					switch (se_e_) {
						case screenelement_enum::Button: {
							screenelement_button* se_btn_p_ = dynamic_cast <screenelement_button*> (se_p_);
							screenelement_button_enum se_btn_e_ = se_btn_p_->screenelement_button_enum_ ();
							se_btn_p_->set_bIsHeldDown (false);
							handle (
								bEditAString,
								bHaveGameData,
								bShowMainMenuNewGamePageChoice,
								sNewAdventureName,
								s_pToEdit,
								gameaction_,
								gamemode_p_,
								mainmenupage_,
								gamedata_pEnemy,
								gamedata_pPlayer,
								bShouldClear_vec_screenelement_p,
								se_btn_e_
							);
							break;
						}
					}
				}
			}
			bClickedAButtonJustNow = false;
			break;
		}
		case sf::Event::TextEntered: {
			if (bEditAString) {
				char chInput = eventToHandle.text.unicode;
				if (chInput < 128) {
					if (chInput == 8) { //Backspace
						if(s_pToEdit->size () > 0) {
							s_pToEdit->pop_back ();
							bShouldClear_vec_screenelement_p = true;
						}
					} else if (chInput == 13) { //Enter
						//Maybe use later.
					} else if (isalpha (chInput)) {
						s_pToEdit->operator+= (chInput);
						bShouldClear_vec_screenelement_p = true;
					}
				}
			}
			break;
		}
	}
}
void menu_main::addButtonsPageSwitching (
	const sf::Font& fontToUse,
	std::vector <screenelement*>& vec_screenelement_pToPrepare
) {
	screenelement_rectangle* rectBG = new screenelement_rectangle_bg_buttons_page_switching ();
	screenelement_label* lblTitleShadow = new screenelement_label_title_shadow (fontToUse);
	screenelement_label* lblTitle = new screenelement_label_title (fontToUse);
	screenelement_button* btnReview = new screenelement_button_review (fontToUse);
	screenelement_button* btnLoad = new screenelement_button_load (fontToUse);
	screenelement_button* btnSave = new screenelement_button_save (fontToUse);
	screenelement_button* btnNewGame = new screenelement_button_new_game (fontToUse);
	screenelement_button* btnPlay = new screenelement_button_play (fontToUse);
	screenelement_button* btnAccredit = new screenelement_button_accredit (fontToUse);
	screenelement_button* btnAdjust = new screenelement_button_adjust (fontToUse);
	screenelement_button* btnExit = new screenelement_button_exit (fontToUse);
	float fWidth_btnLoad = btnLoad->rs_ ().getGlobalBounds ().width;
	float fWidth_btnSave = btnSave->rs_ ().getGlobalBounds ().width;
	float fWidth_btnNewGame = btnNewGame->rs_ ().getGlobalBounds ().width;
	float fWidth_btnPlay = btnPlay->rs_ ().getGlobalBounds ().width;
	float fWidth_btnAccredit = btnAccredit->rs_ ().getGlobalBounds ().width;
	float fWidth_btnAdjust = btnAdjust->rs_ ().getGlobalBounds ().width;
	float fWidth_btnExit = btnExit->rs_ ().getGlobalBounds ().width;
	float fPosX_lblTitleShadow;
	float fPosX_lblTitle = 15.f;
	float fPosX_btnReview;
	float fPosX_btnLoad;
	float fPosX_btnSave;
	float fPosX_btnNewGame;
	float fPosX_btnPlay = 0.f;
	float fPosX_btnAccredit;
	float fPosX_btnAdjust;
	float fPosX_btnExit = 1350.f - fWidth_btnExit;
	fPosX_lblTitleShadow = fPosX_lblTitle + 1.f;
	fPosX_btnAdjust = fPosX_btnExit - fWidth_btnAdjust;
	fPosX_btnAccredit = fPosX_btnAdjust - fWidth_btnAccredit;
	fPosX_btnNewGame = fPosX_btnPlay + fWidth_btnPlay;
	fPosX_btnSave = fPosX_btnNewGame + fWidth_btnNewGame;
	fPosX_btnLoad = fPosX_btnSave + fWidth_btnSave;
	fPosX_btnReview = fPosX_btnLoad + fWidth_btnLoad;
	lblTitleShadow->move (fPosX_lblTitleShadow, 76.f);
	lblTitle->move (fPosX_lblTitle, 75.f);
	btnReview->move (fPosX_btnReview, 0.f);
	btnLoad->move (fPosX_btnLoad, 0.f);
	btnSave->move (fPosX_btnSave, 0.f);
	btnNewGame->move (fPosX_btnNewGame, 0.f);
	btnPlay->move (fPosX_btnPlay, 0.f);
	btnAccredit->move (fPosX_btnAccredit, 0.f);
	btnAdjust->move (fPosX_btnAdjust, 0.f);
	btnExit->move (fPosX_btnExit, 0.f);
	vec_screenelement_pToPrepare.push_back (rectBG);
	vec_screenelement_pToPrepare.push_back (lblTitleShadow);
	vec_screenelement_pToPrepare.push_back (lblTitle);
	vec_screenelement_pToPrepare.push_back (btnReview);
	vec_screenelement_pToPrepare.push_back (btnLoad);
	vec_screenelement_pToPrepare.push_back (btnSave);
	vec_screenelement_pToPrepare.push_back (btnNewGame);
	vec_screenelement_pToPrepare.push_back (btnPlay);
	vec_screenelement_pToPrepare.push_back (btnAccredit);
	vec_screenelement_pToPrepare.push_back (btnAdjust);
	vec_screenelement_pToPrepare.push_back (btnExit);
}
void menu_main::addPageSplash (
	const sf::Font& fontToUse,
	std::vector <screenelement*>& vec_screenelement_pToPrepare
) {
	screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
	screenelement_label* lblHeaderWelcome = new screenelement_label_header_welcome (fontToUse);
	float fWidth_lblHeaderWelcome = lblHeaderWelcome->text_ ().getGlobalBounds ().width;
	float fPosX_lblHeaderWelcome = .5f * (1350.f - fWidth_lblHeaderWelcome);
	rectBG->move (25.f, 150.f);
	lblHeaderWelcome->move (fPosX_lblHeaderWelcome, 210.f);
	vec_screenelement_pToPrepare.push_back (rectBG);
	vec_screenelement_pToPrepare.push_back (lblHeaderWelcome);
}
void menu_main::addPageAdjust (
	const sf::Font& fontToUse,
	std::vector <screenelement*>& vec_screenelement_pToPrepare
) {
	screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
	screenelement_label* lblHeaderOptions = new screenelement_label_header_options (fontToUse);
	float fWidth_lblHeaderOptions = lblHeaderOptions->text_ ().getGlobalBounds ().width;
	float fPosX_lblHeaderOptions = .5f * (1350.f - fWidth_lblHeaderOptions);
	rectBG->move (25.f, 150.f);
	lblHeaderOptions->move (fPosX_lblHeaderOptions, 210.f);
	vec_screenelement_pToPrepare.push_back (rectBG);
	vec_screenelement_pToPrepare.push_back (lblHeaderOptions);
}
void menu_main::addPageAccredit (
	const sf::Font& fontToUse,
	std::vector <screenelement*>& vec_screenelement_pToPrepare
) {
	screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
	screenelement_label* lblHeaderCredits = new screenelement_label_header_credits (fontToUse);
	screenelement_label* lblParagraphCredits = new screenelement_label_paragraph_credits (fontToUse);
	float fWidth_lblHeaderCredits = lblHeaderCredits->text_ ().getGlobalBounds ().width;
	float fWidth_lblCredits = lblParagraphCredits->text_ ().getGlobalBounds ().width;
	float fPosX_lblHeaderCredits = .5f * (1350.f - fWidth_lblHeaderCredits);
	float fPosX_lblCredits = .5f * (1350.f - fWidth_lblCredits);
	rectBG->move (25.f, 150.f);
	lblHeaderCredits->move (fPosX_lblHeaderCredits, 210.f);
	lblParagraphCredits->move (fPosX_lblCredits, 285.f);
	vec_screenelement_pToPrepare.push_back (rectBG);
	vec_screenelement_pToPrepare.push_back (lblHeaderCredits);
	vec_screenelement_pToPrepare.push_back (lblParagraphCredits);
}
void menu_main::addPageNewGame (
	const bool& bHaveGameData,
	const bool& bShowMainMenuNewGamePageChoice,
	const std::string& sNewAdventureName,
	const sf::Font& fontToUse,
	std::vector <screenelement*>& vec_screenelement_pToPrepare
) {
	if (bShowMainMenuNewGamePageChoice) {
		screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
		screenelement_label* lblHeaderNewGame = new screenelement_label_header_new_game (fontToUse);
		screenelement_label* lblHeaderNewQuickGameIfPlayClicked =
			new screenelement_label_header_new_quick_game_if_play_clicked (fontToUse);
		screenelement_button* btnNewQuickGame = new screenelement_button_new_quick_game (fontToUse);
		screenelement_button* btnNewAdventure = new screenelement_button_new_adventure (fontToUse);
		btnNewQuickGame->stretch (500.f, 0.f);
		btnNewAdventure->stretch (500.f, 0.f);
		float fWidth_lblHeaderNewGame = lblHeaderNewGame->text_ ().getGlobalBounds ().width;
		float fWidth_lblHeaderNewQuickGameIfPlayClicked = lblHeaderNewQuickGameIfPlayClicked->text_ ().getGlobalBounds ().width;
		float fPosX_lblHeaderNewGame = (1350.f - fWidth_lblHeaderNewGame) / 2.f;
		float fPosX_lblHeaderNewQuickGameIfPlayClicked = (1350.f - fWidth_lblHeaderNewQuickGameIfPlayClicked) / 2.f;
		float fLeftoverX = (1350.f - 2.f * 25.f - 2.f * 500.f) / 3.f;
		float fPosX_btnNewQuickGame = 25.f + fLeftoverX;
		float fPosX_btnNewAdventure = 25.f + 2.f * fLeftoverX + 500.f;
		rectBG->move (25.f, 150.f);
		lblHeaderNewGame->move (fPosX_lblHeaderNewGame, 210.f);
		lblHeaderNewQuickGameIfPlayClicked->move (fPosX_lblHeaderNewQuickGameIfPlayClicked, 900.f);
		btnNewQuickGame->move (fPosX_btnNewQuickGame, 345.f);
		btnNewAdventure->move (fPosX_btnNewAdventure, 345.f);
		vec_screenelement_pToPrepare.push_back (rectBG);
		vec_screenelement_pToPrepare.push_back (lblHeaderNewGame);
		if (bHaveGameData)
			delete lblHeaderNewQuickGameIfPlayClicked;
		else
			vec_screenelement_pToPrepare.push_back (lblHeaderNewQuickGameIfPlayClicked);
		vec_screenelement_pToPrepare.push_back (btnNewQuickGame);
		vec_screenelement_pToPrepare.push_back (btnNewAdventure);
	} else {
		screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
		screenelement_label* lblHeaderNewGame = new screenelement_label_header_new_game (fontToUse);
		screenelement_label* lblHeaderName = new screenelement_label_header_name (fontToUse);
		screenelement_label* lblHeaderNewAdventureIfPlayClicked =
			new screenelement_label_header_new_adventure_if_play_clicked (fontToUse);
		screenelement_button* btnNewGameReturn = new screenelement_button_new_game_return (fontToUse);
		screenelement_button* btnNewGameName = new screenelement_button_new_adventure_name (sNewAdventureName, fontToUse);
		float fWidth_lblHeaderNewGame = lblHeaderNewGame->text_ ().getGlobalBounds ().width;
		float fWidth_lblHeaderNewAdventureIfPlayClicked = lblHeaderNewAdventureIfPlayClicked->text_ ().getGlobalBounds ().width;
		float fPosX_lblHeaderNewGame = (1350.f - fWidth_lblHeaderNewGame) / 2.f;
		float fPosX_lblHeaderNewAdventureIfPlayClicked = (1350.f - fWidth_lblHeaderNewAdventureIfPlayClicked) / 2.f;
		float fPosX_lbl_ = (1350.f - 4.f * 25.f) * 0.7f + 2.f * 25.f;
		rectBG->move (25.f, 150.f);
		lblHeaderNewGame->move (fPosX_lblHeaderNewGame, 210.f);
		lblHeaderNewAdventureIfPlayClicked->move (fPosX_lblHeaderNewAdventureIfPlayClicked, 900.f);
		lblHeaderName->move (fPosX_lbl_, 345.f);
		btnNewGameReturn->move (50.f, 175.f);
		btnNewGameName->move (fPosX_lbl_, 405.f);
		vec_screenelement_pToPrepare.push_back (rectBG);
		vec_screenelement_pToPrepare.push_back (lblHeaderNewGame);
		vec_screenelement_pToPrepare.push_back (lblHeaderName);
		if (bHaveGameData)
			delete lblHeaderNewAdventureIfPlayClicked;
		else
			vec_screenelement_pToPrepare.push_back (lblHeaderNewAdventureIfPlayClicked);
		vec_screenelement_pToPrepare.push_back (btnNewGameReturn);
		vec_screenelement_pToPrepare.push_back (btnNewGameName);
	}
}
void menu_main::handle (
	bool& bEditAString,
	bool& bHaveGameData,
	bool& bShowMainMenuNewGamePageChoice,
	std::string& sNewAdventureName,
	std::string*& s_pToEdit,
	gameaction& gameaction_,
	gamemode*& gamemode_p_,
	mainmenupage& mainmenupage_,
	gamedata*& gamedata_pEnemy,
	gamedata*& gamedata_pPlayer,
	bool& bShouldClear_vec_screenelement_p,
	screenelement_button_enum screenelement_button_enumToHandle
) {
	switch (screenelement_button_enumToHandle) {
		case screenelement_button_enum::Exit: {
			gameaction_ = gameaction::Exit;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case screenelement_button_enum::Adjust: {
			if (mainmenupage_ != mainmenupage::Adjust) {
				mainmenupage_ = mainmenupage::Adjust;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case screenelement_button_enum::Accredit: {
			if (mainmenupage_ != mainmenupage::Accredit) {
				mainmenupage_ = mainmenupage::Accredit;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case screenelement_button_enum::Play: {
			if (bHaveGameData) {
				gameaction_ = gameaction::Play;
			} else {
				if (mainmenupage_ == mainmenupage::NewGame) {
					gamemode_p_ = new gamemode;
					if (bShowMainMenuNewGamePageChoice)
						*gamemode_p_ = gamemode::PokerDuel;
					else
						*gamemode_p_ = gamemode::Adventure;
					gameaction_ = gameaction::Play;
				} else {
					mainmenupage_ = mainmenupage::NewGame;
				}
			}
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case screenelement_button_enum::NewGame: {
			if (mainmenupage_ != mainmenupage::NewGame) {
				mainmenupage_ = mainmenupage::NewGame;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case screenelement_button_enum::Save: {
			if (mainmenupage_ != mainmenupage::Save) {
				mainmenupage_ = mainmenupage::Save;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case screenelement_button_enum::Load: {
			if (mainmenupage_ != mainmenupage::Load) {
				mainmenupage_ = mainmenupage::Load;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case screenelement_button_enum::Review: {
			if (mainmenupage_ != mainmenupage::Review) {
				mainmenupage_ = mainmenupage::Review;
				bShouldClear_vec_screenelement_p = true;
			}
			break;
		}
		case screenelement_button_enum::NewQuickGame: {
			if (bHaveGameData) {
				switch (*gamemode_p_) {
					case gamemode::PokerDuel: {
						delete gamedata_pEnemy;
						delete gamedata_pPlayer;
						break;
					}
					case gamemode::Adventure: {
						break;
					}
				}
				bHaveGameData = false;
			} else {
				gamemode_p_ = new gamemode;
			}
			*gamemode_p_ = gamemode::PokerDuel;
			gameaction_ = gameaction::Play;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case screenelement_button_enum::NewAdventure: {
			bShowMainMenuNewGamePageChoice = false;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case screenelement_button_enum::NewGameReturn: {
			bShowMainMenuNewGamePageChoice = true;
			bShouldClear_vec_screenelement_p = true;
			break;
		}
		case screenelement_button_enum::NewAdventureName: {
			s_pToEdit = &sNewAdventureName;
			bEditAString = true;
			break;
		}
	}
}
menu_main::screenelement_rectangle_enum menu_main::screenelement_rectangle_bg_buttons_page_switching::screenelement_rectangle_enum_ (
) const {
	return screenelement_rectangle_enum::BgButtonsPageSwitching;
}
menu_main::screenelement_rectangle_bg_buttons_page_switching::screenelement_rectangle_bg_buttons_page_switching (
) {
	set_bIsHeldDown (false);
	create (1350.f, 60.f, sf::Color (0, 0, 0, 255));
}
menu_main::screenelement_rectangle_enum menu_main::screenelement_rectangle_bg_screen_majority::screenelement_rectangle_enum_ (
) const {
	return screenelement_rectangle_enum::BgScreenMajority;
}
menu_main::screenelement_rectangle_bg_screen_majority::screenelement_rectangle_bg_screen_majority (
) {
	set_bIsHeldDown (false);
	create (1300.f, 905.f, sf::Color (0, 0, 0, 255));
}
menu_main::screenelement_label_enum menu_main::screenelement_label_title::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::Title;
}
menu_main::screenelement_label_title::screenelement_label_title (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Dice Poker", fontToUse, 60, sf::Color::White);
}
menu_main::screenelement_label_enum menu_main::screenelement_label_title_shadow::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::TitleShadow;
}
menu_main::screenelement_label_title_shadow::screenelement_label_title_shadow (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Dice Poker", fontToUse, 60, sf::Color::Black);
}
menu_main::screenelement_label_enum menu_main::screenelement_label_header_welcome::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderWelcome;
}
menu_main::screenelement_label_header_welcome::screenelement_label_header_welcome (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Welcome to Dice Poker!", fontToUse, 60, sf::Color::White);
}
menu_main::screenelement_label_enum menu_main::screenelement_label_header_options::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderOptions;
}
menu_main::screenelement_label_header_options::screenelement_label_header_options (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Options", fontToUse, 60, sf::Color::White);
}
menu_main::screenelement_label_enum menu_main::screenelement_label_header_credits::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderCredits;
}
menu_main::screenelement_label_header_credits::screenelement_label_header_credits (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Credits", fontToUse, 60, sf::Color::White);
}
menu_main::screenelement_label_enum menu_main::screenelement_label_paragraph_credits::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::ParagraphCredits;
}
menu_main::screenelement_label_paragraph_credits::screenelement_label_paragraph_credits (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Written by Steve Correa.  Copy of Witcher 2 minigame.", fontToUse, 45, sf::Color::White);
}
menu_main::screenelement_label_enum menu_main::screenelement_label_header_new_game::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderNewGame;
}
menu_main::screenelement_label_header_new_game::screenelement_label_header_new_game (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("New Game", fontToUse, 60, sf::Color::White);
}
menu_main::screenelement_label_enum menu_main::screenelement_label_header_new_quick_game_if_play_clicked::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderNewQuickGameIfPlayClicked;
}
menu_main::screenelement_label_header_new_quick_game_if_play_clicked::screenelement_label_header_new_quick_game_if_play_clicked (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Note: New Quick Game starts if Play is Clicked.", fontToUse, 60, sf::Color::White);
}
menu_main::screenelement_label_enum menu_main::screenelement_label_header_name::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderName;
}
menu_main::screenelement_label_header_name::screenelement_label_header_name (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Name", fontToUse, 60, sf::Color::White);
}
menu_main::screenelement_label_enum menu_main::screenelement_label_header_new_adventure_if_play_clicked::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderNewAdventureIfPlayClicked;
}
menu_main::screenelement_label_header_new_adventure_if_play_clicked::screenelement_label_header_new_adventure_if_play_clicked (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Note: New Adventure starts if Play is Clicked.", fontToUse, 60, sf::Color::White);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_exit::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::Exit;
}
menu_main::screenelement_button_exit::screenelement_button_exit (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Exit", fontToUse, 30, sf::Color::White, sf::Color (255, 128, 0, 0));
	stretch (rs_ ().getGlobalBounds ().width + 12.f, 60.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_adjust::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::Adjust;
}
menu_main::screenelement_button_adjust::screenelement_button_adjust (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Adjust", fontToUse, 30, sf::Color::White, sf::Color (255, 128, 0, 0));
	stretch (rs_ ().getGlobalBounds ().width + 12.f, 60.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_accredit::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::Accredit;
}
menu_main::screenelement_button_accredit::screenelement_button_accredit (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Accredit", fontToUse, 30, sf::Color::White, sf::Color (255, 128, 0, 0));
	stretch (rs_ ().getGlobalBounds ().width + 12.f, 60.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_play::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::Play;
}
menu_main::screenelement_button_play::screenelement_button_play (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Play", fontToUse, 30, sf::Color::White, sf::Color (255, 128, 0, 0));
	stretch (rs_ ().getGlobalBounds ().width + 12.f, 60.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_new_game::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::NewGame;
}
menu_main::screenelement_button_new_game::screenelement_button_new_game (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("New Game", fontToUse, 30, sf::Color::White, sf::Color (255, 128, 0, 0));
	stretch (rs_ ().getGlobalBounds ().width + 12.f, 60.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_save::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::Save;
}
menu_main::screenelement_button_save::screenelement_button_save (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Save", fontToUse, 30, sf::Color::White, sf::Color (255, 128, 0, 0));
	stretch (rs_ ().getGlobalBounds ().width + 12.f, 60.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_load::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::Load;
}
menu_main::screenelement_button_load::screenelement_button_load (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Load", fontToUse, 30, sf::Color::White, sf::Color (255, 128, 0, 0));
	stretch (rs_ ().getGlobalBounds ().width + 12.f, 60.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_review::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::Review;
}
menu_main::screenelement_button_review::screenelement_button_review (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Review", fontToUse, 30, sf::Color::White, sf::Color (255, 128, 0, 0));
	stretch (rs_ ().getGlobalBounds ().width + 12.f, 60.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_new_quick_game::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::NewQuickGame;
}
menu_main::screenelement_button_new_quick_game::screenelement_button_new_quick_game (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Quick Game", fontToUse, 60, sf::Color::Black, sf::Color::White);
	stretch (rs_ ().getGlobalBounds ().width + 24.f, 120.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_new_adventure::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::NewAdventure;
}
menu_main::screenelement_button_new_adventure::screenelement_button_new_adventure (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Full Adventure", fontToUse, 60, sf::Color::Black, sf::Color::White);
	stretch (rs_ ().getGlobalBounds ().width + 24.f, 120.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_new_game_return::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::NewGameReturn;
}
menu_main::screenelement_button_new_game_return::screenelement_button_new_game_return (
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create ("Back", fontToUse, 60, sf::Color::Black, sf::Color::White);
	stretch (rs_ ().getGlobalBounds ().width + 24.f, 120.f);
}
menu_main::screenelement_button_enum menu_main::screenelement_button_new_adventure_name::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::NewAdventureName;
}
menu_main::screenelement_button_new_adventure_name::screenelement_button_new_adventure_name (
	const std::string& sName,
	const sf::Font& fontToUse
) {
	set_bIsHeldDown (false);
	create (sName, fontToUse, 60, sf::Color::Black, sf::Color::White);
	stretch ((1350.f - 4.f * 25.f) * 0.3f, 120.f);
}