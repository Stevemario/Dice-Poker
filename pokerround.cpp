#include "pokerround.h"
#include "diceset.h"
int pokerround::variableset0::nBetAgreed (
) const {
	return m_nBetAgreed;
}
int pokerround::variableset0::nCashInPot (
) const {
	return m_nCashInPot;
}
std::string pokerround::variableset0::sBetPlayer (
) const {
	return m_sBetPlayer;
}
pokerroundstage pokerround::variableset0::pokerroundstage_ (
) const {
	return m_pokerroundstage;
}
const gamedata*& pokerround::variableset0::gamedata_pEnemy (
) const {
	return (const gamedata*&) (m_gamedata_pEnemy);
}
const gamedata*& pokerround::variableset0::gamedata_pPlayer (
) const {
	return (const gamedata*&) (m_gamedata_pPlayer);
}
std::string* pokerround::variableset0::sBetPlayer_p (
) {
	return &m_sBetPlayer;
}
pokerround::variableset0::variableset0 (
) {
	m_sBetPlayer = "0";
	m_gamedata_pEnemy = new gamedata ("Steve's Bot", 100);
	m_gamedata_pPlayer = new gamedata ("Player", 100);
}
pokerround::variableset0::variableset0 (
	std::ifstream& ifstream_
) {
	m_nBetAgreed = iofunctions::nReading (ifstream_);
	m_nCashInPot = iofunctions::nReading (ifstream_);
	m_sBetPlayer = iofunctions::sReading (ifstream_);
	m_pokerroundstage = pokerroundstage (iofunctions::nReading (ifstream_));
	m_gamedata_pEnemy = new gamedata (ifstream_);
	m_gamedata_pPlayer = new gamedata (ifstream_);
}
pokerround::variableset0::~variableset0 (
) {
	delete m_gamedata_pEnemy;
	delete m_gamedata_pPlayer;
}
void pokerround::variableset0::set_nBetAgreed (
	const int& nBetAgreed
) {
	m_nBetAgreed = nBetAgreed;
}
void pokerround::variableset0::set_nCashInPot (
	const int& nCashInPot
) {
	m_nCashInPot = nCashInPot;
}
void pokerround::variableset0::set_pokerroundstage (
	const pokerroundstage& pokerroundstage_
) {
	m_pokerroundstage = pokerroundstage_;
}
void pokerround::variableset0::set_nDollarsCarriedEnemy (
	const int& nDollarsCarried
) {
	m_gamedata_pEnemy->set_nDollarsCarried (nDollarsCarried);
}
void pokerround::variableset0::set_nDollarsCarriedPlayer (
	const int& nDollarsCarried
) {
	m_gamedata_pPlayer->set_nDollarsCarried (nDollarsCarried);
}
intx5 pokerround::variableset1::n5DiceEnemyInitial (
) const {
	return m_n5DiceEnemyInitial;
}
intx5 pokerround::variableset1::n5DiceEnemyReroll (
) const {
	return m_n5DiceEnemyReroll;
}
intx5 pokerround::variableset1::n5DicePlayerInitial (
) const {
	return m_n5DicePlayerInitial;
}
intx5 pokerround::variableset1::n5DicePlayerReroll (
) const {
	return m_n5DicePlayerReroll;
}
pokerround::variableset1::variableset1 (
) {
}
pokerround::variableset1::variableset1 (
	std::ifstream& ifstream_
) {
	m_n5DiceEnemyInitial = n5Reading (ifstream_);
	m_n5DiceEnemyReroll = n5Reading (ifstream_);
	m_n5DicePlayerInitial = n5Reading (ifstream_);
	m_n5DicePlayerReroll = n5Reading (ifstream_);
}
void pokerround::variableset1::set_nDiceEnemyInitial (
	const int& nIndex,
	const int& nDice
) {
	m_n5DiceEnemyInitial[nIndex] = nDice;
}
void pokerround::variableset1::set_nDiceEnemyReroll (
	const int& nIndex,
	const int& nDice
) {
	m_n5DiceEnemyReroll[nIndex] = nDice;
}
void pokerround::variableset1::set_nDicePlayerInitial (
	const int& nIndex,
	const int& nDice
) {
	m_n5DicePlayerInitial[nIndex] = nDice;
}
void pokerround::variableset1::set_nDicePlayerReroll (
	const int& nIndex,
	const int& nDice
) {
	m_n5DicePlayerReroll[nIndex] = nDice;
}
int pokerround::variableset2::nScoreEnemyInitial (
) const {
	return m_nScoreEnemyInitial;
}
int pokerround::variableset2::nScoreEnemyUltimate (
) const {
	return m_nScoreEnemyUltimate;
}
int pokerround::variableset2::nScorePlayerInitial (
) const {
	return m_nScorePlayerInitial;
}
int pokerround::variableset2::nScorePlayerUltimate (
) const {
	return m_nScorePlayerUltimate;
}
int pokerround::variableset2::nCashInPotBefore (
) const {
	return m_nCashInPotBefore;
}
pokerroundresult pokerround::variableset2::pokerroundresult_ (
) const {
	return m_pokerroundresult;
}
intx5 pokerround::variableset2::n5DiceEnemyUltimate (
) const {
	return m_n5DiceEnemyUltimate;
}
intx5 pokerround::variableset2::n5DicePlayerUltimate (
) const {
	return m_n5DicePlayerUltimate;
}
pokerround::variableset2::variableset2 (
) {
}
pokerround::variableset2::variableset2 (
	std::ifstream& ifstream_
) {
	set_nScoreEnemyInitial (iofunctions::nReading (ifstream_));
	set_nScoreEnemyUltimate (iofunctions::nReading (ifstream_));
	set_nScorePlayerInitial (iofunctions::nReading (ifstream_));
	set_nScorePlayerUltimate (iofunctions::nReading (ifstream_));
	set_nCashInPotBefore (iofunctions::nReading (ifstream_));
	set_pokerroundresult (pokerroundresult (iofunctions::nReading (ifstream_)));
	m_n5DiceEnemyUltimate = n5Reading (ifstream_);
	m_n5DicePlayerUltimate = n5Reading (ifstream_);
}
void pokerround::variableset2::set_nScoreEnemyInitial (
	const int& n_
) {
	m_nScoreEnemyInitial = n_;
}
void pokerround::variableset2::set_nScoreEnemyUltimate (
	const int& n_
) {
	m_nScoreEnemyUltimate = n_;
}
void pokerround::variableset2::set_nScorePlayerInitial (
	const int& n_
) {
	m_nScorePlayerInitial = n_;
}
void pokerround::variableset2::set_nScorePlayerUltimate (
	const int& n_
) {
	m_nScorePlayerUltimate = n_;
}
void pokerround::variableset2::set_nCashInPotBefore (
	const int& n_
) {
	m_nCashInPotBefore = n_;
}
void pokerround::variableset2::set_pokerroundresult (
	const pokerroundresult& pokerroundresult_
) {
	m_pokerroundresult = pokerroundresult_;
}
void pokerround::variableset2::set_nDiceEnemyUltimate (
	const int& nIndex,
	const int& nDice
) {
	m_n5DiceEnemyUltimate[nIndex] = nDice;
}
void pokerround::variableset2::set_nDicePlayerUltimate (
	const int& nIndex,
	const int& nDice
) {
	m_n5DicePlayerUltimate[nIndex] = nDice;
}
void pokerround::prepare (
	const sf::Font& font_,
	const variableset0*& prvs0_p_,
	const variableset1*& prvs1_p_,
	const variableset2*& prvs2_p_,
	screenelements& ses_
) {
	switch (prvs0_p_->pokerroundstage_ ()) {
		case pokerroundstage::SubmitInputInitial: {
			prepareStage_SubmitInputInitial (
				prvs0_p_->nCashInPot (),
				prvs0_p_->sBetPlayer (),
				font_,
				prvs0_p_->gamedata_pEnemy (),
				prvs0_p_->gamedata_pPlayer (),
				ses_
			);
			break;
		}
		case pokerroundstage::OKInputInitial: {
			prepareStage_OKInputInitial (
				prvs0_p_->nBetAgreed (),
				prvs0_p_->nCashInPot (),
				font_,
				prvs0_p_->gamedata_pEnemy (),
				prvs0_p_->gamedata_pPlayer (),
				ses_
			);
			break;
		}
		case pokerroundstage::SubmitInputSecond: {
			prepareStage_SubmitInputSecond (
				prvs0_p_->nCashInPot (),
				prvs0_p_->sBetPlayer (),
				font_,
				prvs0_p_->gamedata_pEnemy (),
				prvs0_p_->gamedata_pPlayer (),
				prvs1_p_->n5DiceEnemyInitial (),
				prvs1_p_->n5DicePlayerInitial (),
				prvs1_p_->n5DicePlayerReroll (),
				ses_
			);
			break;
		}
		case pokerroundstage::OKInputSecond: {
			prepareStage_OKInputSecond (
				prvs0_p_->nBetAgreed (),
				prvs0_p_->nCashInPot (),
				font_,
				prvs0_p_->gamedata_pEnemy (),
				prvs0_p_->gamedata_pPlayer (),
				prvs1_p_->n5DicePlayerInitial (),
				prvs1_p_->n5DicePlayerReroll (),
				ses_
			);
			break;
		}
		case pokerroundstage::OKResults: {
			prepareStage_OKResults (
				prvs0_p_->nCashInPot (),
				font_,
				prvs0_p_->gamedata_pEnemy (),
				prvs0_p_->gamedata_pPlayer (),
				prvs1_p_->n5DiceEnemyInitial (),
				prvs1_p_->n5DiceEnemyReroll (),
				prvs1_p_->n5DicePlayerInitial (),
				prvs1_p_->n5DicePlayerReroll (),
				prvs2_p_,
				ses_
			);
			break;
		}
	}
}
void pokerround::prepareStage_SubmitInputInitial (
	const int& nCashInPot,
	const std::string& sBetPlayer,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	screenelements& ses_
) {
	screenelement_label* lblHeaderPromptBet = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderPromptBetInitial
	);
	screenelement_button* btnBetAmount = new screenelement_button_bet_amount (
		font_,
		sBetPlayer
	);
	screenelement_button* btnSubmitInputInitial = new screenelement_button_generic (
		font_,
		screenelement_button_enum::SubmitInputInitial
	);
	btnBetAmount->stretch (360.f, 0.f);
	btnSubmitInputInitial->stretch (360.f, 0.f);
	float fWidth_lblHeaderPromptBet = lblHeaderPromptBet->frBounds_text ().width;
	float fWidth_btnBetAmount = btnBetAmount->frBounds_rs ().width;
	float fWidth_btnSubmitInputInitial = btnSubmitInputInitial->frBounds_rs ().width;
	float fPosX_lblHeaderPromptBet = .5f * (1350.f - fWidth_lblHeaderPromptBet);
	float fPosX_btnBetAmount = .5f * (1350.f - fWidth_btnBetAmount);
	float fPosX_btnSubmitInputInitial = .5f * (1350.f - fWidth_btnSubmitInputInitial);
	lblHeaderPromptBet->move (fPosX_lblHeaderPromptBet, 180.f);
	btnBetAmount->move (fPosX_btnBetAmount, 240.f);
	btnSubmitInputInitial->move (fPosX_btnSubmitInputInitial, 380.f);
	ses_.push_back (lblHeaderPromptBet);
	ses_.push_back (btnBetAmount);
	ses_.push_back (btnSubmitInputInitial);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		ses_
	);
}
void pokerround::prepareStage_OKInputInitial (
	const int& nBetAgreed,
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	screenelements& ses_
) {
	screenelement_label* lblHeaderAlertBet = new screenelement_label_header_alert_bet (
		font_,
		nBetAgreed,
		true
	);
	screenelement_label* lblHeaderPressingRollWillOKBet = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderPressingRollWillOKBet
	);
	screenelement_button* btnChangeInputInitial = new screenelement_button_generic (
		font_,
		screenelement_button_enum::ChangeInputInitial
	);
	screenelement_button* btnOKInputInitial = new screenelement_button_generic (
		font_,
		screenelement_button_enum::OKInputInitial
	);
	float fWidth_lblHeaderAlertBet = lblHeaderAlertBet->frBounds_text ().width;
	float fWidth_lblHeaderPressingRollWillOKBet = lblHeaderPressingRollWillOKBet->frBounds_text ().width;
	float fWidth_btnChangeInputInitial = btnChangeInputInitial->frBounds_rs ().width;
	float fPosX_lblHeaderAlertBet = .5f * (1350.f - fWidth_lblHeaderAlertBet);
	float fPosX_lblHeaderPressingRollWillOKBet = .5f * (1350.f - fWidth_lblHeaderPressingRollWillOKBet);
	float fPosX_btnChangeInputInitial = .5f * 1350.f  - 10.f - fWidth_btnChangeInputInitial;
	float fPosX_btnOKInputInitial = .5f * 1350.f  + 10.f;
	lblHeaderAlertBet->move (fPosX_lblHeaderAlertBet, 180.f);
	lblHeaderPressingRollWillOKBet->move (fPosX_lblHeaderPressingRollWillOKBet, 380.f);
	btnChangeInputInitial->move (fPosX_btnChangeInputInitial, 240.f);
	btnOKInputInitial->move (fPosX_btnOKInputInitial, 240.f);
	ses_.push_back (lblHeaderAlertBet);
	ses_.push_back (lblHeaderPressingRollWillOKBet);
	ses_.push_back (btnChangeInputInitial);
	ses_.push_back (btnOKInputInitial);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		ses_
	);
}
void pokerround::prepareStage_SubmitInputSecond (
	const int& nCashInPot,
	const std::string& sBetPlayer,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5& n5EnemyInitial,
	const intx5& n5PlayerInitial,
	const intx5& n5PlayerReroll,
	screenelements& ses_
) {
	screenelement_rectangle* rectDiceSelected0;
	screenelement_rectangle* rectDiceSelected1;
	screenelement_rectangle* rectDiceSelected2;
	screenelement_rectangle* rectDiceSelected3;
	screenelement_rectangle* rectDiceSelected4;
	screenelement_label* lblHeaderDiceRolled = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceRolled
	);
	screenelement_label* lblHeaderDiceEnemy = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceEnemy
	);
	screenelement_label* lblHeaderDicePlayer = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDicePlayer
	);
	screenelement_label* lblHeaderSelectDiceToReroll = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderSelectDiceToReroll
	);
	screenelement_label* lblHeaderPromptBetSecond = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderPromptBetSecond
	);
	screenelement_button* btnDiceEnemy0 = new screenelement_button_dice (
		font_,
		n5EnemyInitial[0],
		true,
		0
	);
	screenelement_button* btnDiceEnemy1 = new screenelement_button_dice (
		font_,
		n5EnemyInitial[1],
		true,
		1
	);
	screenelement_button* btnDiceEnemy2 = new screenelement_button_dice (
		font_,
		n5EnemyInitial[2],
		true,
		2
	);
	screenelement_button* btnDiceEnemy3 = new screenelement_button_dice (
		font_,
		n5EnemyInitial[3],
		true,
		3
	);
	screenelement_button* btnDiceEnemy4 = new screenelement_button_dice (
		font_,
		n5EnemyInitial[4],
		true,
		4
	);
	screenelement_button* btnDicePlayer0 = new screenelement_button_dice (
		font_,
		n5PlayerInitial[0],
		false,
		0
	);
	screenelement_button* btnDicePlayer1 = new screenelement_button_dice (
		font_,
		n5PlayerInitial[1],
		false,
		1
	);
	screenelement_button* btnDicePlayer2 = new screenelement_button_dice (
		font_,
		n5PlayerInitial[2],
		false,
		2
	);
	screenelement_button* btnDicePlayer3 = new screenelement_button_dice (
		font_,
		n5PlayerInitial[3],
		false,
		3
	);
	screenelement_button* btnDicePlayer4 = new screenelement_button_dice (
		font_,
		n5PlayerInitial[4],
		false,
		4
	);
	screenelement_button* btnBetAmount = new screenelement_button_bet_amount (
		font_,
		sBetPlayer
	);
	screenelement_button* btnSubmitInputSecond = new screenelement_button_generic (
		font_,
		screenelement_button_enum::SubmitInputSecond
	);
	sf::FloatRect frBounds_btnDicePlayer0 = btnDicePlayer0->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer1 = btnDicePlayer1->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer2 = btnDicePlayer2->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer3 = btnDicePlayer3->frBounds_rs ();
	sf::FloatRect frBounds_btnDicePlayer4 = btnDicePlayer4->frBounds_rs ();
	float fWidth_lblHeaderDiceRolled = lblHeaderDiceRolled->frBounds_text ().width;
	float fWidth_lblHeaderDiceEnemy = lblHeaderDiceEnemy->frBounds_text ().width;
	float fWidth_lblHeaderDicePlayer = lblHeaderDicePlayer->frBounds_text ().width;
	float fWidth_lblHeaderSelectDiceToReroll = lblHeaderSelectDiceToReroll->frBounds_text ().width;
	float fWidth_lblHeaderPromptBetSecond = lblHeaderPromptBetSecond->frBounds_text ().width;
	float fWidth_btnDiceEnemy0 = btnDiceEnemy0->frBounds_rs ().width;
	float fWidth_btnDiceEnemy1 = btnDiceEnemy1->frBounds_rs ().width;
	float fWidth_btnDiceEnemy2 = btnDiceEnemy2->frBounds_rs ().width;
	float fWidth_btnDiceEnemy3 = btnDiceEnemy3->frBounds_rs ().width;
	float fWidth_btnDiceEnemy4 = btnDiceEnemy4->frBounds_rs ().width;
	float fWidth_btnDicePlayer0 = frBounds_btnDicePlayer0.width;
	float fWidth_btnDicePlayer1 = frBounds_btnDicePlayer1.width;
	float fWidth_btnDicePlayer2 = frBounds_btnDicePlayer2.width;
	float fWidth_btnDicePlayer3 = frBounds_btnDicePlayer3.width;
	float fWidth_btnDicePlayer4 = frBounds_btnDicePlayer4.width;
	float fHeight_btnDicePlayer0 = frBounds_btnDicePlayer0.height;
	float fHeight_btnDicePlayer1 = frBounds_btnDicePlayer1.height;
	float fHeight_btnDicePlayer2 = frBounds_btnDicePlayer2.height;
	float fHeight_btnDicePlayer3 = frBounds_btnDicePlayer3.height;
	float fHeight_btnDicePlayer4 = frBounds_btnDicePlayer4.height;
	float fWidth_btnSubmitInputSecond = btnSubmitInputSecond->frBounds_rs ().width;
	float fPosX_lblHeaderDiceRolled = .5f * (1350.f - fWidth_lblHeaderDiceRolled);
	float fPosX_lblHeaderDiceEnemy = 2.f * 1350.f / 3.f - .5f * fWidth_lblHeaderDiceEnemy;
	float fPosX_lblHeaderDicePlayer = 1350.f / 3.f - .5f * fWidth_lblHeaderDicePlayer;
	float fPosX_lblHeaderSelectDiceToReroll = .5f * (1350.f - fWidth_lblHeaderSelectDiceToReroll);
	float fPosX_lblHeaderPromptBetSecond = .5f * 1350.f - 10.f - fWidth_lblHeaderPromptBetSecond;
	float fPosX_btnDiceEnemy0 = 2.f * 1350.f / 3.f - .5f * fWidth_btnDiceEnemy0;
	float fPosX_btnDiceEnemy1 = 2.f * 1350.f / 3.f - .5f * fWidth_btnDiceEnemy1;
	float fPosX_btnDiceEnemy2 = 2.f * 1350.f / 3.f - .5f * fWidth_btnDiceEnemy2;
	float fPosX_btnDiceEnemy3 = 2.f * 1350.f / 3.f - .5f * fWidth_btnDiceEnemy3;
	float fPosX_btnDiceEnemy4 = 2.f * 1350.f / 3.f - .5f * fWidth_btnDiceEnemy4;
	float fPosX_btnDicePlayer0 = 1350.f / 3.f - .5f * fWidth_btnDicePlayer0;
	float fPosX_btnDicePlayer1 = 1350.f / 3.f - .5f * fWidth_btnDicePlayer1;
	float fPosX_btnDicePlayer2 = 1350.f / 3.f - .5f * fWidth_btnDicePlayer2;
	float fPosX_btnDicePlayer3 = 1350.f / 3.f - .5f * fWidth_btnDicePlayer3;
	float fPosX_btnDicePlayer4 = 1350.f / 3.f - .5f * fWidth_btnDicePlayer4;
	float fPosX_btnBetAmount = .5f * 1350.f + 10.f;
	float fPosX_btnSubmitInputSecond = .5f * (1350.f - fWidth_btnSubmitInputSecond);
	rectDiceSelected0 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer0 + 8.f,
		fHeight_btnDicePlayer0 + 8.f
	);
	rectDiceSelected1 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer1 + 8.f,
		fHeight_btnDicePlayer1 + 8.f
	);
	rectDiceSelected2 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer2 + 8.f,
		fHeight_btnDicePlayer2 + 8.f
	);
	rectDiceSelected3 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer3 + 8.f,
		fHeight_btnDicePlayer3 + 8.f
	);
	rectDiceSelected4 = new screenelement_rectangle_dice_selected_background (
		fWidth_btnDicePlayer4 + 8.f,
		fHeight_btnDicePlayer4 + 8.f
	);
	rectDiceSelected0->move (fPosX_btnDicePlayer0 - 4.f, 236.f);
	rectDiceSelected1->move (fPosX_btnDicePlayer1 - 4.f, 336.f);
	rectDiceSelected2->move (fPosX_btnDicePlayer2 - 4.f, 436.f);
	rectDiceSelected3->move (fPosX_btnDicePlayer3 - 4.f, 536.f);
	rectDiceSelected4->move (fPosX_btnDicePlayer4 - 4.f, 636.f);
	lblHeaderDiceRolled->move (fPosX_lblHeaderDiceRolled, 120.f);
	lblHeaderDiceEnemy->move (fPosX_lblHeaderDiceEnemy, 180.f);
	lblHeaderDicePlayer->move (fPosX_lblHeaderDicePlayer, 180.f);
	lblHeaderSelectDiceToReroll->move (fPosX_lblHeaderSelectDiceToReroll, 740.f);
	lblHeaderPromptBetSecond->move (fPosX_lblHeaderPromptBetSecond, 830.f);
	btnDiceEnemy0->move (fPosX_btnDiceEnemy0, 240.f);
	btnDiceEnemy1->move (fPosX_btnDiceEnemy1, 340.f);
	btnDiceEnemy2->move (fPosX_btnDiceEnemy2, 440.f);
	btnDiceEnemy3->move (fPosX_btnDiceEnemy3, 540.f);
	btnDiceEnemy4->move (fPosX_btnDiceEnemy4, 640.f);
	btnDicePlayer0->move (fPosX_btnDicePlayer0, 240.f);
	btnDicePlayer1->move (fPosX_btnDicePlayer1, 340.f);
	btnDicePlayer2->move (fPosX_btnDicePlayer2, 440.f);
	btnDicePlayer3->move (fPosX_btnDicePlayer3, 540.f);
	btnDicePlayer4->move (fPosX_btnDicePlayer4, 640.f);
	btnBetAmount->move (fPosX_btnBetAmount, 800.f);
	btnSubmitInputSecond->move (fPosX_btnSubmitInputSecond, 940.f);
	ses_.push_back (lblHeaderDiceRolled);
	ses_.push_back (lblHeaderDiceEnemy);
	ses_.push_back (lblHeaderDicePlayer);
	ses_.push_back (lblHeaderSelectDiceToReroll);
	ses_.push_back (lblHeaderPromptBetSecond);
	ses_.push_back (btnSubmitInputSecond);
	ses_.push_back (btnBetAmount);
	ses_.push_back (btnDiceEnemy4);
	if (n5PlayerReroll[4] == int (true)) {
		ses_.push_back (rectDiceSelected4);
	} else {
		delete rectDiceSelected4;
	}
	ses_.push_back (btnDicePlayer4);
	ses_.push_back (btnDiceEnemy3);
	if (n5PlayerReroll[3] == int (true)) {
		ses_.push_back (rectDiceSelected3);
	} else {
		delete rectDiceSelected3;
	}
	ses_.push_back (btnDicePlayer3);
	ses_.push_back (btnDiceEnemy2);
	if (n5PlayerReroll[2] == int (true)) {
		ses_.push_back (rectDiceSelected2);
	} else {
		delete rectDiceSelected2;
	}
	ses_.push_back (btnDicePlayer2);
	ses_.push_back (btnDiceEnemy1);
	if (n5PlayerReroll[1] == int (true)) {
		ses_.push_back (rectDiceSelected1);
	} else {
		delete rectDiceSelected1;
	}
	ses_.push_back (btnDicePlayer1);
	ses_.push_back (btnDiceEnemy0);
	if (n5PlayerReroll[0] == int (true)) {
		ses_.push_back (rectDiceSelected0);
	} else {
		delete rectDiceSelected0;
	}
	ses_.push_back (btnDicePlayer0);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		ses_
	);
}
void pokerround::prepareStage_OKInputSecond (
	const int& nBetAgreed,
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5& n5PlayerInitial,
	const intx5& n5PlayerReroll,
	screenelements& ses_
) {
	screenelement_label* lblHeaderAlertDicePlayerWillKeep = new screenelement_label_header_alert_dice_player_will_keep (
		font_,
		n5PlayerInitial,
		n5PlayerReroll
	);
	screenelement_label* lblHeaderAlertBetMore = new screenelement_label_header_alert_bet (
		font_,
		nBetAgreed,
		false
	);
	screenelement_label* lblHeaderPressingOKInputSecondWillRollSecond = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderPressingOKInputSecondWillRollSecond
	);
	screenelement_button* btnChangeInputSecond = new screenelement_button_generic (
		font_,
		screenelement_button_enum::ChangeInputSecond
	);
	screenelement_button* btnOKInputSecond = new screenelement_button_generic (
		font_,
		screenelement_button_enum::OKInputSecond
	);
	float fWidth_lblHeaderAlertDicePlayerWillKeep = lblHeaderAlertDicePlayerWillKeep->frBounds_text ().width;
	float fWidth_lblHeaderAlertBet = lblHeaderAlertBetMore->frBounds_text ().width;
	float fWidth_lblHeaderPressingOKInputSecondWillRollSecond = lblHeaderPressingOKInputSecondWillRollSecond->frBounds_text ().width;
	float fWidth_btnChangeInputSecond = btnChangeInputSecond->frBounds_rs ().width;
	float fPosX_lblHeaderAlertDicePlayerWillKeep = .5f * (1350.f - fWidth_lblHeaderAlertDicePlayerWillKeep);
	float fPosX_lblHeaderAlertBet = .5f * (1350.f - fWidth_lblHeaderAlertBet);
	float fPosX_lblHeaderPressingOKInputSecondWillRollSecond = .5f * (1350.f - fWidth_lblHeaderPressingOKInputSecondWillRollSecond);
	float fPosX_btnChangeInputSecond = .5f * 1350.f  - 10.f - fWidth_btnChangeInputSecond;
	float fPosX_btnOKInputSecond = .5f * 1350.f  + 10.f;
	lblHeaderAlertDicePlayerWillKeep->move (fPosX_lblHeaderAlertDicePlayerWillKeep, 180.f);
	lblHeaderAlertBetMore->move (fPosX_lblHeaderAlertBet, 240.f);
	lblHeaderPressingOKInputSecondWillRollSecond->move (fPosX_lblHeaderPressingOKInputSecondWillRollSecond, 440.f);
	btnChangeInputSecond->move (fPosX_btnChangeInputSecond, 300.f);
	btnOKInputSecond->move (fPosX_btnOKInputSecond, 300.f);
	ses_.push_back (lblHeaderAlertDicePlayerWillKeep);
	ses_.push_back (lblHeaderAlertBetMore);
	ses_.push_back (lblHeaderPressingOKInputSecondWillRollSecond);
	ses_.push_back (btnChangeInputSecond);
	ses_.push_back (btnOKInputSecond);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		ses_
	);
}
void pokerround::prepareStage_OKResults (
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	const intx5& n5EnemyInitial,
	const intx5& n5EnemyReroll,
	const intx5& n5PlayerInitial,
	const intx5& n5PlayerReroll,
	const variableset2*& prvs2_p_,
	screenelements& ses_
) {
	screenelement_label* lblHeaderDiceRolled = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceRolled
	);
	screenelement_label* lblHeaderDiceEnemy = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceEnemy
	);
	screenelement_label* lblHeaderDicePlayer = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDicePlayer
	);
	screenelement_label* lblHeaderDiceInitialEnemy = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceInitial
	);
	screenelement_label* lblHeaderDiceInitialPlayer = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceInitial
	);
	screenelement_label* lblHeaderDiceUltimateEnemy = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceUltimate
	);
	screenelement_label* lblHeaderDiceUltimatePlayer = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderDiceUltimate
	);
	screenelement_label* lblHeaderAlertRerollEnemy0 = new screenelement_label_header_alert_reroll (
		font_,
		n5EnemyReroll,
		0
	);
	screenelement_label* lblHeaderAlertRerollEnemy1 = new screenelement_label_header_alert_reroll (
		font_,
		n5EnemyReroll,
		1
	);
	screenelement_label* lblHeaderAlertRerollEnemy2 = new screenelement_label_header_alert_reroll (
		font_,
		n5EnemyReroll,
		2
	);
	screenelement_label* lblHeaderAlertRerollEnemy3 = new screenelement_label_header_alert_reroll (
		font_,
		n5EnemyReroll,
		3
	);
	screenelement_label* lblHeaderAlertRerollEnemy4 = new screenelement_label_header_alert_reroll (
		font_,
		n5EnemyReroll,
		4
	);
	screenelement_label* lblHeaderAlertRerollPlayer0 = new screenelement_label_header_alert_reroll (
		font_,
		n5PlayerReroll,
		0
	);
	screenelement_label* lblHeaderAlertRerollPlayer1 = new screenelement_label_header_alert_reroll (
		font_,
		n5PlayerReroll,
		1
	);
	screenelement_label* lblHeaderAlertRerollPlayer2 = new screenelement_label_header_alert_reroll (
		font_,
		n5PlayerReroll,
		2
	);
	screenelement_label* lblHeaderAlertRerollPlayer3 = new screenelement_label_header_alert_reroll (
		font_,
		n5PlayerReroll,
		3
	);
	screenelement_label* lblHeaderAlertRerollPlayer4 = new screenelement_label_header_alert_reroll (
		font_,
		n5PlayerReroll,
		4
	);
	screenelement_label* lblHeaderScoreEnemyInitial = new screenelement_label_header_score (
		font_,
		prvs2_p_->nScoreEnemyInitial (),
		true,
		true
	);
	screenelement_label* lblHeaderScoreEnemyUltimate = new screenelement_label_header_score (
		font_,
		prvs2_p_->nScoreEnemyUltimate (),
		true,
		false
	);
	screenelement_label* lblHeaderScorePlayerInitial = new screenelement_label_header_score (
		font_,
		prvs2_p_->nScorePlayerInitial (),
		false,
		true
	);
	screenelement_label* lblHeaderScorePlayerUltimate = new screenelement_label_header_score (
		font_,
		prvs2_p_->nScorePlayerUltimate (),
		false,
		false
	);
	screenelement_label* lblHeaderAlertOutcomePlayer = new screenelement_label_header_alert_outcome_player (
		font_,
		(const pokerroundresult) (prvs2_p_->pokerroundresult_ ()),
		prvs2_p_->nCashInPotBefore (),
		gamedata_pEnemy
	);
	screenelement_button* btnDiceEnemyInitial0 = new screenelement_button_dice (
		font_,
		n5EnemyInitial[0],
		true,
		0
	);
	screenelement_button* btnDiceEnemyInitial1 = new screenelement_button_dice (
		font_,
		n5EnemyInitial[1],
		true,
		1
	);
	screenelement_button* btnDiceEnemyInitial2 = new screenelement_button_dice (
		font_,
		n5EnemyInitial[2],
		true,
		2
	);
	screenelement_button* btnDiceEnemyInitial3 = new screenelement_button_dice (
		font_,
		n5EnemyInitial[3],
		true,
		3
	);
	screenelement_button* btnDiceEnemyInitial4 = new screenelement_button_dice (
		font_,
		n5EnemyInitial[4],
		true,
		4
	);
	screenelement_button* btnDiceEnemyUltimate0 = new screenelement_button_dice (
		font_,
		prvs2_p_->n5DiceEnemyUltimate ()[0],
		true,
		0
	);
	screenelement_button* btnDiceEnemyUltimate1 = new screenelement_button_dice (
		font_,
		prvs2_p_->n5DiceEnemyUltimate ()[1],
		true,
		1
	);
	screenelement_button* btnDiceEnemyUltimate2 = new screenelement_button_dice (
		font_,
		prvs2_p_->n5DiceEnemyUltimate ()[2],
		true,
		2
	);
	screenelement_button* btnDiceEnemyUltimate3 = new screenelement_button_dice (
		font_,
		prvs2_p_->n5DiceEnemyUltimate ()[3],
		true,
		3
	);
	screenelement_button* btnDiceEnemyUltimate4 = new screenelement_button_dice (
		font_,
		prvs2_p_->n5DiceEnemyUltimate ()[4],
		true,
		4
	);
	screenelement_button* btnDicePlayerInitial0 = new screenelement_button_dice (
		font_,
		n5PlayerInitial[0],
		false,
		0
	);
	screenelement_button* btnDicePlayerInitial1 = new screenelement_button_dice (
		font_,
		n5PlayerInitial[1],
		false,
		1
	);
	screenelement_button* btnDicePlayerInitial2 = new screenelement_button_dice (
		font_,
		n5PlayerInitial[2],
		false,
		2
	);
	screenelement_button* btnDicePlayerInitial3 = new screenelement_button_dice (
		font_,
		n5PlayerInitial[3],
		false,
		3
	);
	screenelement_button* btnDicePlayerInitial4 = new screenelement_button_dice (
		font_,
		n5PlayerInitial[4],
		false,
		4
	);
	screenelement_button* btnDicePlayerUltimate0 = new screenelement_button_dice (
		font_,
		prvs2_p_->n5DicePlayerUltimate ()[0],
		false,
		1
	);
	screenelement_button* btnDicePlayerUltimate1 = new screenelement_button_dice (
		font_,
		prvs2_p_->n5DicePlayerUltimate ()[1],
		false,
		1
	);
	screenelement_button* btnDicePlayerUltimate2 = new screenelement_button_dice (
		font_,
		prvs2_p_->n5DicePlayerUltimate ()[2],
		false,
		2
	);
	screenelement_button* btnDicePlayerUltimate3 = new screenelement_button_dice (
		font_,
		prvs2_p_->n5DicePlayerUltimate ()[3],
		false,
		3
	);
	screenelement_button* btnDicePlayerUltimate4 = new screenelement_button_dice (
		font_,
		prvs2_p_->n5DicePlayerUltimate ()[4],
		false,
		4
	);
	screenelement_button* btnOKResult = new screenelement_button_generic (
		font_,
		screenelement_button_enum::OKResult
	);
	float fWidth_lblHeaderDiceRolled = lblHeaderDiceRolled->frBounds_text ().width;
	float fWidth_lblHeaderDiceEnemy = lblHeaderDiceEnemy->frBounds_text ().width;
	float fWidth_lblHeaderDicePlayer = lblHeaderDicePlayer->frBounds_text ().width;
	float fWidth_lblHeaderDiceInitialEnemy = lblHeaderDiceInitialEnemy->frBounds_text ().width;
	float fWidth_lblHeaderDiceInitialPlayer = lblHeaderDiceInitialPlayer->frBounds_text ().width;
	float fWidth_lblHeaderDiceUltimateEnemy = lblHeaderDiceUltimateEnemy->frBounds_text ().width;
	float fWidth_lblHeaderDiceUltimatePlayer = lblHeaderDiceUltimatePlayer->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollEnemy0 = lblHeaderAlertRerollEnemy0->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollEnemy1 = lblHeaderAlertRerollEnemy1->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollEnemy2 = lblHeaderAlertRerollEnemy2->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollEnemy3 = lblHeaderAlertRerollEnemy3->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollEnemy4 = lblHeaderAlertRerollEnemy4->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollPlayer0 = lblHeaderAlertRerollPlayer0->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollPlayer1 = lblHeaderAlertRerollPlayer1->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollPlayer2 = lblHeaderAlertRerollPlayer2->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollPlayer3 = lblHeaderAlertRerollPlayer3->frBounds_text ().width;
	float fWidth_lblHeaderAlertRerollPlayer4 = lblHeaderAlertRerollPlayer4->frBounds_text ().width;
	float fWidth_lblHeaderScoreEnemyInitial = lblHeaderScoreEnemyInitial->frBounds_text ().width;
	float fWidth_lblHeaderScoreEnemyUltimate = lblHeaderScoreEnemyUltimate->frBounds_text ().width;
	float fWidth_lblHeaderScorePlayerInitial = lblHeaderScorePlayerInitial->frBounds_text ().width;
	float fWidth_lblHeaderScorePlayerUltimate = lblHeaderScorePlayerUltimate->frBounds_text ().width;
	float fWidth_lblHeaderAlertOutcomePlayer = lblHeaderAlertOutcomePlayer->frBounds_text ().width;
	float fWidth_btnDiceEnemyInitial0 = btnDiceEnemyInitial0->frBounds_rs ().width;
	float fWidth_btnDiceEnemyInitial1 = btnDiceEnemyInitial1->frBounds_rs ().width;
	float fWidth_btnDiceEnemyInitial2 = btnDiceEnemyInitial2->frBounds_rs ().width;
	float fWidth_btnDiceEnemyInitial3 = btnDiceEnemyInitial3->frBounds_rs ().width;
	float fWidth_btnDiceEnemyInitial4 = btnDiceEnemyInitial4->frBounds_rs ().width;
	float fWidth_btnDiceEnemyUltimate0 = btnDiceEnemyUltimate0->frBounds_rs ().width;
	float fWidth_btnDiceEnemyUltimate1 = btnDiceEnemyUltimate1->frBounds_rs ().width;
	float fWidth_btnDiceEnemyUltimate2 = btnDiceEnemyUltimate2->frBounds_rs ().width;
	float fWidth_btnDiceEnemyUltimate3 = btnDiceEnemyUltimate3->frBounds_rs ().width;
	float fWidth_btnDiceEnemyUltimate4 = btnDiceEnemyUltimate4->frBounds_rs ().width;
	float fWidth_btnDicePlayerInitial0 = btnDicePlayerInitial0->frBounds_rs ().width;
	float fWidth_btnDicePlayerInitial1 = btnDicePlayerInitial1->frBounds_rs ().width;
	float fWidth_btnDicePlayerInitial2 = btnDicePlayerInitial2->frBounds_rs ().width;
	float fWidth_btnDicePlayerInitial3 = btnDicePlayerInitial3->frBounds_rs ().width;
	float fWidth_btnDicePlayerInitial4 = btnDicePlayerInitial4->frBounds_rs ().width;
	float fWidth_btnDicePlayerUltimate0 = btnDicePlayerUltimate0->frBounds_rs ().width;
	float fWidth_btnDicePlayerUltimate1 = btnDicePlayerUltimate1->frBounds_rs ().width;
	float fWidth_btnDicePlayerUltimate2 = btnDicePlayerUltimate2->frBounds_rs ().width;
	float fWidth_btnDicePlayerUltimate3 = btnDicePlayerUltimate3->frBounds_rs ().width;
	float fWidth_btnDicePlayerUltimate4 = btnDicePlayerUltimate4->frBounds_rs ().width;
	float fWidth_btnOKResult = btnOKResult->frBounds_rs ().width;
	float fPosX_lblHeaderDiceRolled = .5f * (1350.f - fWidth_lblHeaderDiceRolled);
	float fPosX_lblHeaderDiceEnemy = 3.f * 1350.f / 4.f - .5f * fWidth_lblHeaderDiceEnemy;
	float fPosX_lblHeaderDicePlayer = 1350.f / 4.f - .5f * fWidth_lblHeaderDicePlayer;
	float fPosX_lblHeaderDiceInitialEnemy = 4.f * 1350.f / 6.f - .5f * fWidth_lblHeaderDiceInitialEnemy;
	float fPosX_lblHeaderDiceInitialPlayer = 1350.f / 6.f - .5f * fWidth_lblHeaderDiceInitialPlayer;
	float fPosX_lblHeaderDiceUltimateEnemy = 5.f * 1350.f / 6.f - .5f * fWidth_lblHeaderDiceUltimateEnemy;
	float fPosX_lblHeaderDiceUltimatePlayer = 2.f * 1350.f / 6.f - .5f * fWidth_lblHeaderDiceUltimatePlayer;
	float fPosX_lblHeaderAlertRerollEnemy0 = 9.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollEnemy0;
	float fPosX_lblHeaderAlertRerollEnemy1 = 9.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollEnemy1;
	float fPosX_lblHeaderAlertRerollEnemy2 = 9.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollEnemy2;
	float fPosX_lblHeaderAlertRerollEnemy3 = 9.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollEnemy3;
	float fPosX_lblHeaderAlertRerollEnemy4 = 9.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollEnemy4;
	float fPosX_lblHeaderAlertRerollPlayer0 = 3.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollPlayer0;
	float fPosX_lblHeaderAlertRerollPlayer1 = 3.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollPlayer1;
	float fPosX_lblHeaderAlertRerollPlayer2 = 3.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollPlayer2;
	float fPosX_lblHeaderAlertRerollPlayer3 = 3.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollPlayer3;
	float fPosX_lblHeaderAlertRerollPlayer4 = 3.f * 1350.f / 12.f - .5f * fWidth_lblHeaderAlertRerollPlayer4;
	float fPosX_lblHeaderScoreEnemyInitial = 4.f * 1350.f / 6.f - .5f * fWidth_lblHeaderScoreEnemyInitial;
	float fPosX_lblHeaderScoreEnemyUltimate = 5.f * 1350.f / 6.f - .5f * fWidth_lblHeaderScoreEnemyUltimate;
	float fPosX_lblHeaderScorePlayerInitial = 1350.f / 6.f - .5f * fWidth_lblHeaderScorePlayerInitial;
	float fPosX_lblHeaderScorePlayerUltimate = 2.f * 1350.f / 6.f - .5f * fWidth_lblHeaderScorePlayerUltimate;
	float fPosX_lblHeaderAlertOutcomePlayer = .5f * (1350.f - fWidth_lblHeaderAlertOutcomePlayer);
	float fPosX_btnDiceEnemyInitial0 = 4.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyInitial0;
	float fPosX_btnDiceEnemyInitial1 = 4.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyInitial1;
	float fPosX_btnDiceEnemyInitial2 = 4.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyInitial2;
	float fPosX_btnDiceEnemyInitial3 = 4.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyInitial3;
	float fPosX_btnDiceEnemyInitial4 = 4.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyInitial4;
	float fPosX_btnDiceEnemyUltimate0 = 5.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyUltimate0;
	float fPosX_btnDiceEnemyUltimate1 = 5.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyUltimate1;
	float fPosX_btnDiceEnemyUltimate2 = 5.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyUltimate2;
	float fPosX_btnDiceEnemyUltimate3 = 5.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyUltimate3;
	float fPosX_btnDiceEnemyUltimate4 = 5.f * 1350.f / 6.f - .5f * fWidth_btnDiceEnemyUltimate4;
	float fPosX_btnDicePlayerInitial0 = 1350.f / 6.f - .5f * fWidth_btnDicePlayerInitial0;
	float fPosX_btnDicePlayerInitial1 = 1350.f / 6.f - .5f * fWidth_btnDicePlayerInitial1;
	float fPosX_btnDicePlayerInitial2 = 1350.f / 6.f - .5f * fWidth_btnDicePlayerInitial2;
	float fPosX_btnDicePlayerInitial3 = 1350.f / 6.f - .5f * fWidth_btnDicePlayerInitial3;
	float fPosX_btnDicePlayerInitial4 = 1350.f / 6.f - .5f * fWidth_btnDicePlayerInitial4;
	float fPosX_btnDicePlayerUltimate0 = 2.f * 1350.f / 6.f - .5f * fWidth_btnDicePlayerUltimate0;
	float fPosX_btnDicePlayerUltimate1 = 2.f * 1350.f / 6.f - .5f * fWidth_btnDicePlayerUltimate1;
	float fPosX_btnDicePlayerUltimate2 = 2.f * 1350.f / 6.f - .5f * fWidth_btnDicePlayerUltimate2;
	float fPosX_btnDicePlayerUltimate3 = 2.f * 1350.f / 6.f - .5f * fWidth_btnDicePlayerUltimate3;
	float fPosX_btnDicePlayerUltimate4 = 2.f * 1350.f / 6.f - .5f * fWidth_btnDicePlayerUltimate4;
	float fPosX_btnOKResult = .5f * (1350.f - fWidth_btnOKResult);
	lblHeaderDiceRolled->move (fPosX_lblHeaderDiceRolled, 120.f);
	lblHeaderDiceEnemy->move (fPosX_lblHeaderDiceEnemy, 180.f);
	lblHeaderDicePlayer->move (fPosX_lblHeaderDicePlayer, 180.f);
	lblHeaderDiceInitialEnemy->move (fPosX_lblHeaderDiceInitialEnemy, 240.f);
	lblHeaderDiceInitialPlayer->move (fPosX_lblHeaderDiceInitialPlayer, 240.f);
	lblHeaderDiceUltimateEnemy->move (fPosX_lblHeaderDiceUltimateEnemy, 240.f);
	lblHeaderDiceUltimatePlayer->move (fPosX_lblHeaderDiceUltimatePlayer, 240.f);
	lblHeaderAlertRerollEnemy0->move (fPosX_lblHeaderAlertRerollEnemy0, 320.f);
	lblHeaderAlertRerollEnemy1->move (fPosX_lblHeaderAlertRerollEnemy1, 420.f);
	lblHeaderAlertRerollEnemy2->move (fPosX_lblHeaderAlertRerollEnemy2, 520.f);
	lblHeaderAlertRerollEnemy3->move (fPosX_lblHeaderAlertRerollEnemy3, 620.f);
	lblHeaderAlertRerollEnemy4->move (fPosX_lblHeaderAlertRerollEnemy4, 720.f);
	lblHeaderAlertRerollPlayer0->move (fPosX_lblHeaderAlertRerollPlayer0, 320.f);
	lblHeaderAlertRerollPlayer1->move (fPosX_lblHeaderAlertRerollPlayer1, 420.f);
	lblHeaderAlertRerollPlayer2->move (fPosX_lblHeaderAlertRerollPlayer2, 520.f);
	lblHeaderAlertRerollPlayer3->move (fPosX_lblHeaderAlertRerollPlayer3, 620.f);
	lblHeaderAlertRerollPlayer4->move (fPosX_lblHeaderAlertRerollPlayer4, 720.f);
	lblHeaderScoreEnemyInitial->move (fPosX_lblHeaderScoreEnemyInitial, 800.f);
	lblHeaderScoreEnemyUltimate->move (fPosX_lblHeaderScoreEnemyUltimate, 800.f);
	lblHeaderScorePlayerInitial->move (fPosX_lblHeaderScorePlayerInitial, 800.f);
	lblHeaderScorePlayerUltimate->move (fPosX_lblHeaderScorePlayerUltimate, 800.f);
	lblHeaderAlertOutcomePlayer->move (fPosX_lblHeaderAlertOutcomePlayer, 860.f);
	btnDiceEnemyInitial0->move (fPosX_btnDiceEnemyInitial0, 300.f);
	btnDiceEnemyInitial1->move (fPosX_btnDiceEnemyInitial1, 400.f);
	btnDiceEnemyInitial2->move (fPosX_btnDiceEnemyInitial2, 500.f);
	btnDiceEnemyInitial3->move (fPosX_btnDiceEnemyInitial3, 600.f);
	btnDiceEnemyInitial4->move (fPosX_btnDiceEnemyInitial4, 700.f);
	btnDiceEnemyUltimate0->move (fPosX_btnDiceEnemyUltimate0, 300.f);
	btnDiceEnemyUltimate1->move (fPosX_btnDiceEnemyUltimate1, 400.f);
	btnDiceEnemyUltimate2->move (fPosX_btnDiceEnemyUltimate2, 500.f);
	btnDiceEnemyUltimate3->move (fPosX_btnDiceEnemyUltimate3, 600.f);
	btnDiceEnemyUltimate4->move (fPosX_btnDiceEnemyUltimate4, 700.f);
	btnDicePlayerInitial0->move (fPosX_btnDicePlayerInitial0, 300.f);
	btnDicePlayerInitial1->move (fPosX_btnDicePlayerInitial1, 400.f);
	btnDicePlayerInitial2->move (fPosX_btnDicePlayerInitial2, 500.f);
	btnDicePlayerInitial3->move (fPosX_btnDicePlayerInitial3, 600.f);
	btnDicePlayerInitial4->move (fPosX_btnDicePlayerInitial4, 700.f);
	btnDicePlayerUltimate0->move (fPosX_btnDicePlayerUltimate0, 300.f);
	btnDicePlayerUltimate1->move (fPosX_btnDicePlayerUltimate1, 400.f);
	btnDicePlayerUltimate2->move (fPosX_btnDicePlayerUltimate2, 500.f);
	btnDicePlayerUltimate3->move (fPosX_btnDicePlayerUltimate3, 600.f);
	btnDicePlayerUltimate4->move (fPosX_btnDicePlayerUltimate4, 700.f);
	btnOKResult->move (fPosX_btnOKResult, 920.f);
	ses_.push_back (lblHeaderAlertOutcomePlayer);
	ses_.push_back (lblHeaderScoreEnemyUltimate);
	ses_.push_back (lblHeaderScoreEnemyInitial);
	ses_.push_back (lblHeaderScorePlayerUltimate);
	ses_.push_back (lblHeaderScorePlayerInitial);
	ses_.push_back (lblHeaderAlertRerollEnemy4);
	ses_.push_back (lblHeaderAlertRerollPlayer4);
	ses_.push_back (lblHeaderAlertRerollEnemy3);
	ses_.push_back (lblHeaderAlertRerollPlayer3);
	ses_.push_back (lblHeaderAlertRerollEnemy2);
	ses_.push_back (lblHeaderAlertRerollPlayer2);
	ses_.push_back (lblHeaderAlertRerollEnemy1);
	ses_.push_back (lblHeaderAlertRerollPlayer1);
	ses_.push_back (lblHeaderAlertRerollEnemy0);
	ses_.push_back (lblHeaderAlertRerollPlayer0);
	ses_.push_back (lblHeaderDiceUltimateEnemy);
	ses_.push_back (lblHeaderDiceInitialEnemy);
	ses_.push_back (lblHeaderDiceUltimatePlayer);
	ses_.push_back (lblHeaderDiceInitialPlayer);
	ses_.push_back (lblHeaderDiceEnemy);
	ses_.push_back (lblHeaderDicePlayer);
	ses_.push_back (lblHeaderDiceRolled);
	ses_.push_back (btnDiceEnemyUltimate4);
	ses_.push_back (btnDiceEnemyInitial4);
	ses_.push_back (btnDicePlayerUltimate4);
	ses_.push_back (btnDicePlayerInitial4);
	ses_.push_back (btnDiceEnemyUltimate3);
	ses_.push_back (btnDiceEnemyInitial3);
	ses_.push_back (btnDicePlayerUltimate3);
	ses_.push_back (btnDicePlayerInitial3);
	ses_.push_back (btnDiceEnemyUltimate2);
	ses_.push_back (btnDiceEnemyInitial2);
	ses_.push_back (btnDicePlayerUltimate2);
	ses_.push_back (btnDicePlayerInitial2);
	ses_.push_back (btnDiceEnemyUltimate1);
	ses_.push_back (btnDiceEnemyInitial1);
	ses_.push_back (btnDicePlayerUltimate1);
	ses_.push_back (btnDicePlayerInitial1);
	ses_.push_back (btnDiceEnemyUltimate0);
	ses_.push_back (btnDiceEnemyInitial0);
	ses_.push_back (btnDicePlayerUltimate0);
	ses_.push_back (btnDicePlayerInitial0);
	ses_.push_back (btnOKResult);
	addLabelsCash (
		nCashInPot,
		font_,
		gamedata_pEnemy,
		gamedata_pPlayer,
		ses_
	);
}
void pokerround::addLabelsCash (
	const int& nCashInPot,
	const sf::Font& font_,
	const gamedata*& gamedata_pEnemy,
	const gamedata*& gamedata_pPlayer,
	screenelements& ses_
) {
	screenelement_label* lblHeaderNameEnemy = new screenelement_label_header_name (
		font_,
		gamedata_pEnemy,
		true
	);
	screenelement_label* lblHeaderNamePlayer = new screenelement_label_header_name (
		font_,
		gamedata_pPlayer,
		false
	);
	screenelement_label* lblHeaderPot = new screenelement_label_generic (
		font_,
		screenelement_label_enum::HeaderPot
	);
	screenelement_label* lblHeaderCashEnemy = new screenelement_label_header_cash (
		font_,
		gamedata_pEnemy,
		true
	);
	screenelement_label* lblHeaderCashPlayer = new screenelement_label_header_cash (
		font_,
		gamedata_pPlayer,
		false
	);
	screenelement_label* lblHeaderCashPot = new screenelement_label_header_cash_pot (
		font_,
		nCashInPot
	);
	float fWidth_lblHeaderNameEnemy = lblHeaderNameEnemy->frBounds_text ().width;
	float fWidth_lblHeaderNamePlayer = lblHeaderNamePlayer->frBounds_text ().width;
	float fWidth_lblHeaderPot = lblHeaderPot->frBounds_text ().width;
	float fWidth_lblHeaderCashEnemy = lblHeaderCashEnemy->frBounds_text ().width;
	float fWidth_lblHeaderCashPlayer = lblHeaderCashPlayer->frBounds_text ().width;
	float fWidth_lblHeaderCashPot = lblHeaderCashPot->frBounds_text ().width;
	float fPosX_lblHeaderNameEnemy = 1350.f - 25.f - fWidth_lblHeaderNameEnemy;
	float fPosX_lblHeaderNamePlayer = 25.f;
	float fPosX_lblHeaderPot = .5f * (1350.f - fWidth_lblHeaderPot);
	float fPosX_lblHeaderCashEnemy = 1350.f - 25.f - fWidth_lblHeaderCashEnemy;
	float fPosX_lblHeaderCashPlayer = 25.f;
	float fPosX_lblHeaderCashPot = .5f * (1350.f - fWidth_lblHeaderCashPot);
	lblHeaderNameEnemy->move (fPosX_lblHeaderNameEnemy, 0.f);
	lblHeaderNamePlayer->move (fPosX_lblHeaderNamePlayer, 0.f);
	lblHeaderPot->move (fPosX_lblHeaderPot, 0.f);
	lblHeaderCashEnemy->move (fPosX_lblHeaderCashEnemy, 60.f);
	lblHeaderCashPlayer->move (fPosX_lblHeaderCashPlayer, 60.f);
	lblHeaderCashPot->move (fPosX_lblHeaderCashPot, 60.f);
	ses_.push_back (lblHeaderNameEnemy);
	ses_.push_back (lblHeaderNamePlayer);
	ses_.push_back (lblHeaderPot);
	ses_.push_back (lblHeaderCashEnemy);
	ses_.push_back (lblHeaderCashPlayer);
	ses_.push_back (lblHeaderCashPot);
}
pokerround::screenelement_rectangle_enum pokerround::screenelement_rectangle_dice_selected_background::screenelement_rectangle_enum_ (
) const {
	return screenelement_rectangle_enum::DiceSelectedBackground;
}
pokerround::screenelement_rectangle_dice_selected_background::screenelement_rectangle_dice_selected_background (
	const float& fWidth,
	const float& fHeight
) {
	set_bIsHeldDown (false);
	create (fWidth, fHeight, sf::Color (255, 255, 255, 255));
}
pokerround::screenelement_label_enum pokerround::screenelement_label_generic::screenelement_label_enum_ (
) const {
	return m_screenelement_label_enum;
}
pokerround::screenelement_label_generic::screenelement_label_generic (
	const sf::Font& font_,
	const screenelement_label_enum& screenelement_label_enum_
) {
	std::string s_;
	switch (screenelement_label_enum_) {
		case screenelement_label_enum::HeaderPot: { s_ = "Pot"; break; }
		case screenelement_label_enum::HeaderPromptBetInitial: { s_ = "Enter Your Bet:"; break; }
		case screenelement_label_enum::HeaderPressingRollWillOKBet: { s_ = "Pressing OK Bet will roll the dice."; break; }
		case screenelement_label_enum::HeaderDiceRolled: { s_ = "These are the dice rolled:"; break; }
		case screenelement_label_enum::HeaderDiceEnemy: { s_ = "Enemy's Dice"; break; }
		case screenelement_label_enum::HeaderDicePlayer: { s_ = "Your Dice"; break; }
		case screenelement_label_enum::HeaderSelectDiceToReroll: { s_ = "You may select dice to reroll."; break; }
		case screenelement_label_enum::HeaderPromptBetSecond: { s_ = "Bet:"; break; }
		case screenelement_label_enum::HeaderPressingOKInputSecondWillRollSecond: { s_ = "Pressing OK Input will roll the dice.";
			break; }
		case screenelement_label_enum::HeaderDiceInitial: { s_ = "#1"; break; }
		case screenelement_label_enum::HeaderDiceUltimate: { s_ = "#2"; break; }
		default: { s_ = "UNDEFINED"; break; }
	}
	set_bIsHeldDown (false);
	m_screenelement_label_enum = screenelement_label_enum_;
	create (s_, font_, 60, sf::Color::White);
}
pokerround::screenelement_label_enum pokerround::screenelement_label_header_name::screenelement_label_enum_ (
) const {
	return m_screenelement_label_enum;
}
pokerround::screenelement_label_header_name::screenelement_label_header_name (
	const sf::Font& font_,
	const gamedata*& gamedata_p_,
	const bool& bNameEnemy
) {
	std::string s_ = gamedata_p_->sPlayerName ();
	set_bIsHeldDown (false);
	if (bNameEnemy)
		m_screenelement_label_enum = screenelement_label_enum::HeaderNameEnemy;
	else
		m_screenelement_label_enum = screenelement_label_enum::HeaderNamePlayer;
	create (s_, font_, 60, sf::Color::White);
}
pokerround::screenelement_label_enum pokerround::screenelement_label_header_cash::screenelement_label_enum_ (
) const {
	return m_screenelement_label_enum;
}
pokerround::screenelement_label_header_cash::screenelement_label_header_cash (
	const sf::Font& font_,
	const gamedata*& gamedata_p_,
	const bool& bCashEnemy
) {
	std::string s_ = "$" + std::to_string (gamedata_p_->nDollarsCarried ());
	set_bIsHeldDown (false);
	if (bCashEnemy)
		m_screenelement_label_enum = screenelement_label_enum::HeaderCashEnemy;
	else
		m_screenelement_label_enum = screenelement_label_enum::HeaderCashPlayer;
	create (s_, font_, 60, sf::Color::White);
}
pokerround::screenelement_label_enum pokerround::screenelement_label_header_cash_pot::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderCashPot;
}
pokerround::screenelement_label_header_cash_pot::screenelement_label_header_cash_pot (
	const sf::Font& font_,
	const int& nCashInPot
) {
	std::string s_ = "$" + std::to_string (nCashInPot);
	set_bIsHeldDown (false);
	create (s_, font_, 60, sf::Color::White);
}
pokerround::screenelement_label_enum pokerround::screenelement_label_header_alert_bet::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderAlertBet;
}
pokerround::screenelement_label_header_alert_bet::screenelement_label_header_alert_bet (
	const sf::Font& font_,
	const int& nBetAgreed,
	const bool& bBetInitial
) {
	std::string s_ = "You've each bet $" + std::to_string (nBetAgreed) + (bBetInitial ? "." : " more.");
	set_bIsHeldDown (false);
	create (s_, font_, 60, sf::Color::White);
}
pokerround::screenelement_label_enum pokerround::screenelement_label_header_alert_dice_player_will_keep::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderAlertDicePlayerWillKeep;
}
pokerround::screenelement_label_header_alert_dice_player_will_keep::screenelement_label_header_alert_dice_player_will_keep (
	const sf::Font& font_,
	const intx5& n5DicePlayerInitial,
	const intx5& n5DicePlayerReroll
) {
	int nDiceKept;
	std::string s_ = "You decided to keep ";
	std::vector<int> vec_nDiceKept;
	for (int i = 0; i < 5; i++) {
		if (n5DicePlayerReroll[i] != int (true))
			vec_nDiceKept.push_back (n5DicePlayerInitial[i]);
	}
	nDiceKept = vec_nDiceKept.size ();
	if (nDiceKept == 0) {
		s_ += "none of your dice.";
	} else if (nDiceKept == 1) {
		s_ += "a dice showing " +
			std::to_string (vec_nDiceKept[0]) + ".";
	} else if (nDiceKept == 2) {
		s_ += "dice showing " +
			std::to_string (vec_nDiceKept[0]) + " and " +
			std::to_string (vec_nDiceKept[1]) + ".";
	} else if (nDiceKept == 3) {
		s_ += "dice showing " +
			std::to_string (vec_nDiceKept[0]) + ", " +
			std::to_string (vec_nDiceKept[1]) + " and " +
			std::to_string (vec_nDiceKept[2]) + ".";
	} else if (nDiceKept == 4) {
		s_ += "dice showing " +
			std::to_string (vec_nDiceKept[0]) + ", " +
			std::to_string (vec_nDiceKept[1]) + ", " +
			std::to_string (vec_nDiceKept[2]) + " and " +
			std::to_string (vec_nDiceKept[3]) + ".";
	} else {
		s_ += "all of your dice.";
	}
	set_bIsHeldDown (false);
	create (s_, font_, 60, sf::Color::White);
}
pokerround::screenelement_label_enum pokerround::screenelement_label_header_alert_reroll::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderAlertReroll;
}
pokerround::screenelement_label_header_alert_reroll::screenelement_label_header_alert_reroll (
	const sf::Font& font_,
	const intx5& n5Reroll,
	const int& nDiceIndex
) {
	bool bRerolled = n5Reroll[nDiceIndex] == int (true);
	set_bIsHeldDown (false);
	create (bRerolled ? "ROLL" : "->", font_, 40, sf::Color::White);
}
pokerround::screenelement_label_enum pokerround::screenelement_label_header_score::screenelement_label_enum_ (
) const {
	return m_screenelement_label_enum;
}
pokerround::screenelement_label_header_score::screenelement_label_header_score (
	const sf::Font& font_,
	const int& nScore,
	const bool& bScoreEnemy,
	const bool& bScoreInitial
) {
	std::string s_ = "#" + std::to_string (nScore);
	if (bScoreEnemy) {
		if (bScoreInitial)
			m_screenelement_label_enum = screenelement_label_enum::HeaderScoreEnemyInitial;
		else
			m_screenelement_label_enum = screenelement_label_enum::HeaderScoreEnemyUltimate;
	} else {
		if (bScoreInitial)
			m_screenelement_label_enum = screenelement_label_enum::HeaderScorePlayerInitial;
		else
			m_screenelement_label_enum = screenelement_label_enum::HeaderScorePlayerUltimate;
	}
	set_bIsHeldDown (false);
	create (s_, font_, 60, sf::Color::White);
}
pokerround::screenelement_label_enum pokerround::screenelement_label_header_alert_outcome_player::screenelement_label_enum_ (
) const {
	return screenelement_label_enum::HeaderAlertOutcomePlayer;
}
pokerround::screenelement_label_header_alert_outcome_player::screenelement_label_header_alert_outcome_player (
	const sf::Font& font_,
	const pokerroundresult& pokerroundresult_,
	const int& nCashInPotBefore,
	const gamedata*& gamedata_pEnemy
) {
	int nGains = nCashInPotBefore;
	std::string sWinners;
	switch (pokerroundresult_) {
		case pokerroundresult::Win: {
			sWinners = "You";
			break;
		}
		case pokerroundresult::Tie: {
			sWinners = "You both";
			nGains /= 2;
			break;
		}
		case pokerroundresult::Loss: {
			sWinners = gamedata_pEnemy->sPlayerName ();
			break;
		}
	}
	set_bIsHeldDown (false);
	create (sWinners + " won $" + std::to_string (nGains) + "!", font_, 60, sf::Color::White);
}
pokerround::screenelement_button_enum pokerround::screenelement_button_generic::screenelement_button_enum_ (
) const {
	return m_screenelement_button_enum;
}
pokerround::screenelement_button_generic::screenelement_button_generic (
	const sf::Font& font_,
	const screenelement_button_enum& screenelement_button_enum_
) {
	std::string s_;
	switch (screenelement_button_enum_) {
		case screenelement_button_enum::SubmitInputInitial: { s_ = "Submit"; break; };
		case screenelement_button_enum::ChangeInputInitial: { s_ = "Change Bet"; break; };
		case screenelement_button_enum::OKInputInitial: { s_ = "OK Bet"; break; };
		case screenelement_button_enum::SubmitInputSecond: { s_ = "Submit Input"; break; };
		case screenelement_button_enum::ChangeInputSecond: { s_ = "Change Input"; break; };
		case screenelement_button_enum::OKInputSecond: { s_ = "OK Input"; break; };
		case screenelement_button_enum::OKResult: { s_ = "OK Result"; break; };
		default: { s_ = "UNDEFINED"; };
	}
	set_bIsHeldDown (false);
	m_screenelement_button_enum = screenelement_button_enum_;
	create (s_, font_, 60, sf::Color::White, sf::Color::Black);
	stretch (frBounds_rs ().width + 24.f, 120.f);
}
pokerround::screenelement_button_enum pokerround::screenelement_button_bet_amount::screenelement_button_enum_ (
) const {
	return screenelement_button_enum::BetAmount;
}
pokerround::screenelement_button_bet_amount::screenelement_button_bet_amount (
	const sf::Font& font_,
	const std::string& sBetPlayer
) {
	std::string s_ = "$" + sBetPlayer;
	set_bIsHeldDown (false);
	create (s_, font_, 60, sf::Color::White, sf::Color::Black);
	stretch (frBounds_rs ().width + 24.f, 120.f);
}
pokerround::screenelement_button_enum pokerround::screenelement_button_dice::screenelement_button_enum_ (
) const {
	return m_screenelement_button_enum;
}
pokerround::screenelement_button_dice::screenelement_button_dice (
	const sf::Font& font_,
	const int& n_,
	const bool& bEnemy,
	const int& nDiceIndex
) {
	set_bIsHeldDown (false);
	if (bEnemy) {
		switch (nDiceIndex) {
			case 0: { m_screenelement_button_enum = screenelement_button_enum::DiceEnemy0; break; }
			case 1: { m_screenelement_button_enum = screenelement_button_enum::DiceEnemy1; break; }
			case 2: { m_screenelement_button_enum = screenelement_button_enum::DiceEnemy2; break; }
			case 3: { m_screenelement_button_enum = screenelement_button_enum::DiceEnemy3; break; }
			case 4: { m_screenelement_button_enum = screenelement_button_enum::DiceEnemy4; break; }
		}
	} else {
		switch (nDiceIndex) {
			case 0: { m_screenelement_button_enum = screenelement_button_enum::DicePlayer0; break; }
			case 1: { m_screenelement_button_enum = screenelement_button_enum::DicePlayer1; break; }
			case 2: { m_screenelement_button_enum = screenelement_button_enum::DicePlayer2; break; }
			case 3: { m_screenelement_button_enum = screenelement_button_enum::DicePlayer3; break; }
			case 4: { m_screenelement_button_enum = screenelement_button_enum::DicePlayer4; break; }
		}
	}
	create (std::to_string (n_), font_, 40, sf::Color::White, sf::Color::Black);
	stretch (frBounds_rs ().width + 16.f, 80.f);
}
void iofunctions::write (
	const pokerround::variableset0& vs0_,
	std::ofstream& ofstream_
) {
	iofunctions::write (vs0_.nBetAgreed (), ofstream_);
	iofunctions::write (vs0_.nCashInPot (), ofstream_);
	iofunctions::write (vs0_.sBetPlayer (), ofstream_);
	iofunctions::write (int (vs0_.pokerroundstage_ ()), ofstream_);
	write (*vs0_.gamedata_pEnemy (), ofstream_);
	write (*vs0_.gamedata_pPlayer (), ofstream_);
}
void iofunctions::write (
	const pokerround::variableset1& vs1_,
	std::ofstream& ofstream_
) {
	iofunctions::write (vs1_.n5DiceEnemyInitial (), ofstream_);
	iofunctions::write (vs1_.n5DiceEnemyReroll (), ofstream_);
	iofunctions::write (vs1_.n5DicePlayerInitial (), ofstream_);
	iofunctions::write (vs1_.n5DicePlayerReroll (), ofstream_);
}
void iofunctions::write (
	const pokerround::variableset2& vs2_,
	std::ofstream& ofstream_
) {
	iofunctions::write (vs2_.nScoreEnemyInitial (), ofstream_);
	iofunctions::write (vs2_.nScoreEnemyUltimate (), ofstream_);
	iofunctions::write (vs2_.nScorePlayerInitial (), ofstream_);
	iofunctions::write (vs2_.nScorePlayerUltimate (), ofstream_);
	iofunctions::write (vs2_.nCashInPotBefore (), ofstream_);
	iofunctions::write (int (vs2_.pokerroundresult_ ()), ofstream_);
	iofunctions::write (vs2_.n5DiceEnemyUltimate (), ofstream_);
	iofunctions::write (vs2_.n5DicePlayerUltimate (), ofstream_);
}