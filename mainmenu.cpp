#include "mainmenu.h"
void mainmenu::prepare (
	const bool& bHaveGameData,
	const bool& bShowMainMenuNewGamePageChoice,
	const std::string& sLoadSource,
	const std::string& sNewAdventureName,
	const std::string& sSaveDestination,
	const sf::Font& font_,
	const mainmenupage& mainmenupage_,
	const gamedata*& gamedata_pPlayer,
	screenelements& ses_
) {
	switch (mainmenupage_) {
		case mainmenupage::Splash: {
			addPageSplash (font_, ses_);
			break;
		}
		case mainmenupage::Adjust: {
			addPageAdjust (font_, ses_);
			break;
		}
		case mainmenupage::Accredit: {
			addPageAccredit (font_, ses_);
			break;
		}
		case mainmenupage::NewGame: {
			addPageNewGame (
				bHaveGameData,
				bShowMainMenuNewGamePageChoice,
				sNewAdventureName,
				font_,
				ses_
			);
			break;
		}
		case mainmenupage::Save: {
			addPageSave (
				sSaveDestination,
				font_,
				ses_
			);
			break;
		}
		case mainmenupage::Load: {
			addPageLoad (
				sLoadSource,
				font_,
				ses_
			);
			break;
		}
		case mainmenupage::Review: {
			addPageReview (
				bHaveGameData,
				font_,
				gamedata_pPlayer,
				ses_
			);
			break;
		}
	}
	addButtonsPageSwitching (font_, ses_);
}
void mainmenu::addButtonsPageSwitching (
	const sf::Font& font_,
	screenelements& ses_
) {
	screenelement_rectangle* rectBG = new screenelement_rectangle_bg_buttons_page_switching ();
	screenelement_button* btnTitle = new screenelement_button_title (
		font_
	);
	screenelement_button* btnReview = new screenelement_button_page_switching (
		font_,
		screenelement_button_enum::Review
	);
	screenelement_button* btnLoad = new screenelement_button_page_switching (
		font_,
		screenelement_button_enum::Load
	);
	screenelement_button* btnSave = new screenelement_button_page_switching (
		font_,
		screenelement_button_enum::Save
	);
	screenelement_button* btnNewGame = new screenelement_button_page_switching (
		font_,
		screenelement_button_enum::NewGame
	);
	screenelement_button* btnPlay = new screenelement_button_page_switching (
		font_,
		screenelement_button_enum::Play
	);
	screenelement_button* btnAccredit = new screenelement_button_page_switching (
		font_,
		screenelement_button_enum::Accredit
	);
	screenelement_button* btnAdjust = new screenelement_button_page_switching (
		font_,
		screenelement_button_enum::Adjust
	);
	screenelement_button* btnExit = new screenelement_button_page_switching (
		font_,
		screenelement_button_enum::Exit
	);
	float fWidth_btnLoad = btnLoad->frBounds_rs ().width;
	float fWidth_btnSave = btnSave->frBounds_rs ().width;
	float fWidth_btnNewGame = btnNewGame->frBounds_rs ().width;
	float fWidth_btnPlay = btnPlay->frBounds_rs ().width;
	float fWidth_btnAccredit = btnAccredit->frBounds_rs ().width;
	float fWidth_btnAdjust = btnAdjust->frBounds_rs ().width;
	float fWidth_btnExit = btnExit->frBounds_rs ().width;
	float fPosX_btnTitle = 0.f;
	float fPosX_btnReview;
	float fPosX_btnLoad;
	float fPosX_btnSave;
	float fPosX_btnNewGame;
	float fPosX_btnPlay = 0.f;
	float fPosX_btnAccredit;
	float fPosX_btnAdjust;
	float fPosX_btnExit = 1350.f - fWidth_btnExit;
	fPosX_btnAdjust = fPosX_btnExit - fWidth_btnAdjust;
	fPosX_btnAccredit = fPosX_btnAdjust - fWidth_btnAccredit;
	fPosX_btnNewGame = fPosX_btnPlay + fWidth_btnPlay;
	fPosX_btnSave = fPosX_btnNewGame + fWidth_btnNewGame;
	fPosX_btnLoad = fPosX_btnSave + fWidth_btnSave;
	fPosX_btnReview = fPosX_btnLoad + fWidth_btnLoad;
	btnTitle->move (fPosX_btnTitle, 60.f);
	btnReview->move (fPosX_btnReview, 0.f);
	btnLoad->move (fPosX_btnLoad, 0.f);
	btnSave->move (fPosX_btnSave, 0.f);
	btnNewGame->move (fPosX_btnNewGame, 0.f);
	btnPlay->move (fPosX_btnPlay, 0.f);
	btnAccredit->move (fPosX_btnAccredit, 0.f);
	btnAdjust->move (fPosX_btnAdjust, 0.f);
	btnExit->move (fPosX_btnExit, 0.f);
	ses_.push_back (rectBG);
	ses_.push_back (btnTitle);
	ses_.push_back (btnReview);
	ses_.push_back (btnLoad);
	ses_.push_back (btnSave);
	ses_.push_back (btnNewGame);
	ses_.push_back (btnPlay);
	ses_.push_back (btnAccredit);
	ses_.push_back (btnAdjust);
	ses_.push_back (btnExit);
}
void mainmenu::addPageSplash (
	const sf::Font& font_,
	screenelements& ses_
) {
	screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
	screenelement_label* lblHeaderWelcome = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderWelcome
	);
	float fWidth_lblHeaderWelcome = lblHeaderWelcome->frBounds_text ().width;
	float fPosX_lblHeaderWelcome = .5f * (1350.f - fWidth_lblHeaderWelcome);
	rectBG->move (25.f, 150.f);
	lblHeaderWelcome->move (fPosX_lblHeaderWelcome, 210.f);
	ses_.push_back (rectBG);
	ses_.push_back (lblHeaderWelcome);
}
void mainmenu::addPageAdjust (
	const sf::Font& font_,
	screenelements& ses_
) {
	screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
	screenelement_label* lblHeaderOptions = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderOptions
	);
	float fWidth_lblHeaderOptions = lblHeaderOptions->frBounds_text ().width;
	float fPosX_lblHeaderOptions = .5f * (1350.f - fWidth_lblHeaderOptions);
	rectBG->move (25.f, 150.f);
	lblHeaderOptions->move (fPosX_lblHeaderOptions, 210.f);
	ses_.push_back (rectBG);
	ses_.push_back (lblHeaderOptions);
}
void mainmenu::addPageAccredit (
	const sf::Font& font_,
	screenelements& ses_
) {
	screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
	screenelement_label* lblHeaderCredits = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderCredits
	);
	screenelement_label* lblParagraphCredits = new screenelement_label_generic (
		font_,
		screenelement_label_enum::ParagraphCredits
	);
	float fWidth_lblHeaderCredits = lblHeaderCredits->frBounds_text ().width;
	float fWidth_lblParagraphCredits = lblParagraphCredits->frBounds_text ().width;
	float fPosX_lblHeaderCredits = .5f * (1350.f - fWidth_lblHeaderCredits);
	float fPosX_lblParagraphCredits = .5f * (1350.f - fWidth_lblParagraphCredits);
	rectBG->move (25.f, 150.f);
	lblHeaderCredits->move (fPosX_lblHeaderCredits, 210.f);
	lblParagraphCredits->move (fPosX_lblParagraphCredits, 285.f);
	ses_.push_back (rectBG);
	ses_.push_back (lblHeaderCredits);
	ses_.push_back (lblParagraphCredits);
}
void mainmenu::addPageNewGame (
	const bool& bHaveGameData,
	const bool& bShowMainMenuNewGamePageChoice,
	const std::string& sNewAdventureName,
	const sf::Font& font_,
	screenelements& ses_
) {
	if (bShowMainMenuNewGamePageChoice) {
		screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
		screenelement_label* lblHeaderNewGame = new screenelement_label_generic (
			font_,
			screenelement_label_enum::HeaderNewGame
		);
		screenelement_label* lblHeaderNewQuickGameIfPlayClicked = new screenelement_label_generic (
			font_,
			screenelement_label_enum::HeaderNewQuickGameIfPlayClicked
		);
		screenelement_button* btnNewQuickGame = new screenelement_button_generic (
			font_,
			screenelement_button_enum::NewQuickGame
		);
		screenelement_button* btnNewAdventure = new screenelement_button_generic (
			font_,
			screenelement_button_enum::NewAdventure
		);
		btnNewQuickGame->stretch (500.f, 0.f);
		btnNewAdventure->stretch (500.f, 0.f);
		float fWidth_lblHeaderNewGame = lblHeaderNewGame->frBounds_text ().width;
		float fWidth_lblHeaderNewQuickGameIfPlayClicked = lblHeaderNewQuickGameIfPlayClicked->frBounds_text ().width;
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
		ses_.push_back (rectBG);
		ses_.push_back (lblHeaderNewGame);
		if (bHaveGameData)
			delete lblHeaderNewQuickGameIfPlayClicked;
		else
			ses_.push_back (lblHeaderNewQuickGameIfPlayClicked);
		ses_.push_back (btnNewQuickGame);
		ses_.push_back (btnNewAdventure);
	} else {
		screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
		screenelement_label* lblHeaderNewGame = new screenelement_label_generic (
			font_,
			screenelement_label_enum::HeaderNewGame
		);
		screenelement_label* lblHeaderName = new screenelement_label_generic (
			font_,
			screenelement_label_enum::HeaderName
		);
		screenelement_label* lblHeaderNewAdventureIfPlayClicked = new screenelement_label_generic (
			font_,
			screenelement_label_enum::HeaderNewAdventureIfPlayClicked
		);
		screenelement_button* btnNewGameReturn = new screenelement_button_generic (
			font_,
			screenelement_button_enum::NewGameReturn
		);
		screenelement_button* btnNewGameName = new screenelement_button_generic_textfield (
			font_,
			screenelement_button_enum::NewAdventureName,
			sNewAdventureName
		);
		screenelement_button* btnNewAdventureStart = new screenelement_button_generic (
			font_,
			screenelement_button_enum::NewAdventureStart
		);
		float fWidth_btn = (1350.f - 4.f * 25.f) * 0.3f;
		float fWidth_lblHeaderNewGame = lblHeaderNewGame->frBounds_text ().width;
		float fWidth_lblHeaderNewAdventureIfPlayClicked = lblHeaderNewAdventureIfPlayClicked->frBounds_text ().width;
		float fPosX_lblHeaderNewGame = (1350.f - fWidth_lblHeaderNewGame) / 2.f;
		float fPosX_lblHeaderNewAdventureIfPlayClicked = (1350.f - fWidth_lblHeaderNewAdventureIfPlayClicked) / 2.f;
		float fPosX_lbl_ = (1350.f - 4.f * 25.f) * 0.7f + 2.f * 25.f;
		btnNewGameName->stretch (fWidth_btn, 0.f);
		btnNewAdventureStart->stretch (fWidth_btn, 0.f);
		rectBG->move (25.f, 150.f);
		lblHeaderNewGame->move (fPosX_lblHeaderNewGame, 210.f);
		lblHeaderNewAdventureIfPlayClicked->move (fPosX_lblHeaderNewAdventureIfPlayClicked, 900.f);
		lblHeaderName->move (fPosX_lbl_, 345.f);
		btnNewGameReturn->move (50.f, 175.f);
		btnNewGameName->move (fPosX_lbl_, 405.f);
		btnNewAdventureStart->move (fPosX_lbl_, 545.f);
		ses_.push_back (rectBG);
		ses_.push_back (lblHeaderNewGame);
		ses_.push_back (lblHeaderName);
		if (bHaveGameData)
			delete lblHeaderNewAdventureIfPlayClicked;
		else
			ses_.push_back (lblHeaderNewAdventureIfPlayClicked);
		ses_.push_back (btnNewGameReturn);
		ses_.push_back (btnNewGameName);
		ses_.push_back (btnNewAdventureStart);
	}
}
void mainmenu::addPageSave (
	const std::string& sSaveDestination,
	const sf::Font& font_,
	screenelements& ses_
) {
	screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
	screenelement_label* lblHeaderSave = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderSave
	);
	screenelement_label* lblHeaderSaveDestination = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderSaveDestination
	);
	screenelement_label* lblHeaderSaveIfSaveClicked = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderSaveIfSaveClicked
	);
	screenelement_button* btnSaveDestination = new screenelement_button_generic_textfield (
		font_,
		screenelement_button_enum::SaveDestination,
		sSaveDestination
	);
	float fWidth_lblHeaderSave = lblHeaderSave->frBounds_text ().width;
	float fWidth_lblHeaderSaveIfSaveClicked = lblHeaderSaveIfSaveClicked->frBounds_text ().width;
	float fPosX_lblHeaderSave = .5f * (1350.f - fWidth_lblHeaderSave);
	float fPosX_lblHeaderSaveIfSaveClicked = .5f * (1350.f - fWidth_lblHeaderSaveIfSaveClicked);
	rectBG->move (25.f, 150.f);
	lblHeaderSave->move (fPosX_lblHeaderSave, 210.f);
	lblHeaderSaveDestination->move (50.f, 290.f);
	lblHeaderSaveIfSaveClicked->move (fPosX_lblHeaderSaveIfSaveClicked, 900.f);
	btnSaveDestination->move (50.f, 350.f);
	ses_.push_back (rectBG);
	ses_.push_back (lblHeaderSave);
	ses_.push_back (lblHeaderSaveDestination);
	ses_.push_back (lblHeaderSaveIfSaveClicked);
	ses_.push_back (btnSaveDestination);
}
void mainmenu::addPageLoad (
	const std::string& sLoadSource,
	const sf::Font& font_,
	screenelements& ses_
) {
	screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
	screenelement_label* lblHeaderLoad = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderLoad
	);
	screenelement_label* lblHeaderLoadSource = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderLoadSource
	);
	screenelement_label* lblHeaderLoadIfLoadClicked = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderLoadIfLoadClicked
	);
	screenelement_button* btnLoadSource = new screenelement_button_generic_textfield (
		font_,
		screenelement_button_enum::LoadSource,
		sLoadSource
	);
	float fWidth_lblHeaderLoad = lblHeaderLoad->frBounds_text ().width;
	float fWidth_lblHeaderLoadIfLoadClicked = lblHeaderLoadIfLoadClicked->frBounds_text ().width;
	float fPosX_lblHeaderLoad = .5f * (1350.f - fWidth_lblHeaderLoad);
	float fPosX_lblHeaderLoadIfLoadClicked = .5f * (1350.f - fWidth_lblHeaderLoadIfLoadClicked);
	rectBG->move (25.f, 150.f);
	lblHeaderLoad->move (fPosX_lblHeaderLoad, 210.f);
	lblHeaderLoadSource->move (50.f, 290.f);
	lblHeaderLoadIfLoadClicked->move (fPosX_lblHeaderLoadIfLoadClicked, 900.f);
	btnLoadSource->move (50.f, 350.f);
	ses_.push_back (rectBG);
	ses_.push_back (lblHeaderLoad);
	ses_.push_back (lblHeaderLoadSource);
	ses_.push_back (lblHeaderLoadIfLoadClicked);
	ses_.push_back (btnLoadSource);
}
void mainmenu::addPageReview (
	const bool& bHaveGameData,
	const sf::Font& font_,
	const gamedata*& gamedata_pPlayer,
	screenelements& ses_
) {
	if (bHaveGameData) {
		screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
		screenelement_label* lblHeaderReview = new screenelement_label_generic (
			font_,
			screenelement_label_enum::HeaderReview
		);
		screenelement_label* lblHeaderName = new screenelement_label_generic (
			font_,
			screenelement_label_enum::HeaderName
		);
		screenelement_label* lblHeaderNamePlayer = new screenelement_label_variable (
			font_,
			screenelement_label_enum::HeaderNamePlayer,
			gamedata_pPlayer->sPlayerName ()
		);
		screenelement_label* lblHeaderCash = new screenelement_label_generic (
			font_,
			screenelement_label_enum::HeaderCash
		);
		screenelement_label* lblHeaderCashPlayer = new screenelement_label_variable (
			font_,
			screenelement_label_enum::HeaderCashPlayer,
			std::to_string (gamedata_pPlayer->nDollarsCarried ())
		);
		float fWidth_lblHeaderReview = lblHeaderReview->frBounds_text ().width;
		float fPosX_lblHeaderReview = .5f * (1350.f - fWidth_lblHeaderReview);
		float fPosX_lbl_ = (1350.f - 4.f * 25.f) * 0.7f + 2.f * 25.f;
		rectBG->move (25.f, 150.f);
		lblHeaderReview->move (fPosX_lblHeaderReview, 210.f);
		lblHeaderName->move (fPosX_lbl_, 345.f);
		lblHeaderNamePlayer->move (fPosX_lbl_, 405.f);
		lblHeaderCash->move (fPosX_lbl_, 485.f);
		lblHeaderCashPlayer->move (fPosX_lbl_, 545.f);
		ses_.push_back (rectBG);
		ses_.push_back (lblHeaderReview);
		ses_.push_back (lblHeaderName);
		ses_.push_back (lblHeaderNamePlayer);
		ses_.push_back (lblHeaderCash);
		ses_.push_back (lblHeaderCashPlayer);
	} else {
		screenelement_rectangle* rectBG = new screenelement_rectangle_bg_screen_majority ();
		screenelement_label* lblHeaderReview = new screenelement_label_generic (
			font_,
			screenelement_label_enum::HeaderReview
		);
		screenelement_label* lblHeaderNoDataToReview = new screenelement_label_generic (
			font_,
			screenelement_label_enum::HeaderNoDataToReview
		);
		float fWidth_lblHeaderReview = lblHeaderReview->frBounds_text ().width;
		float fWidth_lblHeaderNoDataToReview = lblHeaderNoDataToReview->frBounds_text ().width;
		float fPosX_lblHeaderReview = .5f * (1350.f - fWidth_lblHeaderReview);
		float fPosX_lblHeaderNoDataToReview = .5f * (1350.f - fWidth_lblHeaderNoDataToReview);
		rectBG->move (25.f, 150.f);
		lblHeaderReview->move (fPosX_lblHeaderReview, 210.f);
		lblHeaderNoDataToReview->move (fPosX_lblHeaderNoDataToReview, 290.f);
		ses_.push_back (rectBG);
		ses_.push_back (lblHeaderReview);
		ses_.push_back (lblHeaderNoDataToReview);
	}
}
mainmenu::screenelement_rectangle_enum mainmenu::screenelement_rectangle_bg_buttons_page_switching::screenelement_rectangle_enum_ (
) const {
	return screenelement_rectangle_enum::BgButtonsPageSwitching;
}
mainmenu::screenelement_rectangle_bg_buttons_page_switching::screenelement_rectangle_bg_buttons_page_switching (
) {
	set_bIsHeldDown (false);
	create (1350.f, 60.f, sf::Color (0, 0, 0, 255));
}
mainmenu::screenelement_rectangle_enum mainmenu::screenelement_rectangle_bg_screen_majority::screenelement_rectangle_enum_ (
) const {
	return screenelement_rectangle_enum::BgScreenMajority;
}
mainmenu::screenelement_rectangle_bg_screen_majority::screenelement_rectangle_bg_screen_majority (
) {
	set_bIsHeldDown (false);
	create (1300.f, 905.f, sf::Color (0, 0, 0, 255));
}
mainmenu::screenelement_label_enum mainmenu::screenelement_label_generic::screenelement_label_enum_ (
) const {
	return m_screenelement_label_enum;
}
mainmenu::screenelement_label_generic::screenelement_label_generic (
	const sf::Font& font_,
	const screenelement_label_enum& screenelement_label_enum_
) {
	std::string s_;
	switch (screenelement_label_enum_) {
		case screenelement_label_enum::HeaderWelcome: { s_ = "Welcome to Dice Poker!"; break; }
		case screenelement_label_enum::HeaderOptions: { s_ = "Options"; break; }
		case screenelement_label_enum::HeaderCredits: { s_ = "Credits"; break; }
		case screenelement_label_enum::ParagraphCredits: { s_ = "Written by Steve Correa.  Copy of Witcher 2 minigame."; break; }
		case screenelement_label_enum::HeaderNewGame: { s_ = "New Game"; break; }
		case screenelement_label_enum::HeaderNewQuickGameIfPlayClicked: { s_ = "Note: New Quick Game starts if Play is Clicked.";
			break; }
		case screenelement_label_enum::HeaderName: { s_ = "Name"; break; }
		case screenelement_label_enum::HeaderNewAdventureIfPlayClicked: { s_ = "Note: New Adventure starts if Play is Clicked.";
			break; }
		case screenelement_label_enum::HeaderSave: { s_ = "Save"; break; }
		case screenelement_label_enum::HeaderSaveDestination: { s_ = "Destination"; break; }
		case screenelement_label_enum::HeaderSaveIfSaveClicked: { s_ = "Note: Game Data saves if Save is Clicked"; break; }
		case screenelement_label_enum::HeaderLoad: { s_ = "Load"; break; }
		case screenelement_label_enum::HeaderLoadSource: { s_ = "Source"; break; }
		case screenelement_label_enum::HeaderLoadIfLoadClicked: { s_ = "Note: Game Data loads if Load is Clicked"; break; }
		case screenelement_label_enum::HeaderReview: { s_ = "Review"; break; }
		case screenelement_label_enum::HeaderCash: { s_ = "Cash"; break; }
		case screenelement_label_enum::HeaderNoDataToReview: { s_ = "No Data To Review"; break; }
		default: { s_ = "UNDEFINED"; break; }
	}
	set_bIsHeldDown (false);
	m_screenelement_label_enum = screenelement_label_enum_;
	create (s_, font_, 60, sf::Color::White);
}
mainmenu::screenelement_label_enum mainmenu::screenelement_label_variable::screenelement_label_enum_ (
) const {
	return m_screenelement_label_enum;
}
mainmenu::screenelement_label_variable::screenelement_label_variable (
	const sf::Font& font_,
	const screenelement_label_enum& screenelement_label_enum_,
	const std::string s_
) {
	set_bIsHeldDown (false);
	m_screenelement_label_enum = screenelement_label_enum_;
	create (s_, font_, 60, sf::Color::White);
}
mainmenu::screenelement_button_enum mainmenu::screenelement_button_page_switching::screenelement_button_enum_ (
) const {
	return m_screenelement_button_enum;
}
mainmenu::screenelement_button_page_switching::screenelement_button_page_switching (
	const sf::Font& font_,
	const screenelement_button_enum& screenelement_button_enum_
) {
	std::string s_;
	switch (screenelement_button_enum_) {
		case screenelement_button_enum::Exit: { s_ = "Exit"; break; }
		case screenelement_button_enum::Adjust: { s_ = "Adjust"; break; }
		case screenelement_button_enum::Accredit: { s_ = "Accredit"; break; }
		case screenelement_button_enum::Play: { s_ = "Play"; break; }
		case screenelement_button_enum::NewGame: { s_ = "New Game"; break; }
		case screenelement_button_enum::Save: { s_ = "Save"; break; }
		case screenelement_button_enum::Load: { s_ = "Load"; break; }
		case screenelement_button_enum::Review: { s_ = "Review"; break; }
		default: { s_ = "UNDEFINED"; }
	}
	set_bIsHeldDown (false);
	m_screenelement_button_enum = screenelement_button_enum_;
	create (s_, font_, 30, sf::Color::White, sf::Color (255, 128, 0, 0));
	stretch (frBounds_rs ().width + 12.f, 60.f);
}
mainmenu::screenelement_button_enum mainmenu::screenelement_button_title::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::Title;
}
mainmenu::screenelement_button_title::screenelement_button_title (
	const sf::Font& font_
) {
	set_bIsHeldDown (false);
	create ("Dice Poker", font_, 60, sf::Color::Blue, sf::Color (255, 128, 0, 0));
	stretch (frBounds_rs ().width + 24.f, 90.f);
}
mainmenu::screenelement_button_enum mainmenu::screenelement_button_generic::screenelement_button_enum_ (
) const {
	return m_screenelement_button_enum;
}
mainmenu::screenelement_button_generic::screenelement_button_generic (
	const sf::Font& font_,
	const screenelement_button_enum& screenelement_button_enum_
) {
	std::string s_;
	switch (screenelement_button_enum_) {
		case screenelement_button_enum::NewQuickGame: { s_ = "Quick Game"; break; }
		case screenelement_button_enum::NewAdventure: { s_ = "Full Adventure"; break; }
		case screenelement_button_enum::NewGameReturn: { s_ = "Back"; break; }
		case screenelement_button_enum::NewAdventureStart: { s_ = "START"; break; }
		default: { s_ = "UNDEFINED"; }
	}
	set_bIsHeldDown (false);
	m_screenelement_button_enum = screenelement_button_enum_;
	create (s_, font_, 60, sf::Color::Black, sf::Color::White);
	stretch (frBounds_rs ().width + 24.f, 120.f);
}
mainmenu::screenelement_button_enum mainmenu::screenelement_button_generic_textfield::screenelement_button_enum_ (
) const {
	return m_screenelement_button_enum;
}
mainmenu::screenelement_button_generic_textfield::screenelement_button_generic_textfield (
	const sf::Font& font_,
	const screenelement_button_enum& screenelement_button_enum_,
	const std::string& s_
) {
	set_bIsHeldDown (false);
	m_screenelement_button_enum = screenelement_button_enum_;
	create (s_, font_, 60, sf::Color::Black, sf::Color::White);
	stretch (frBounds_rs ().width + 24.f, 120.f);
}