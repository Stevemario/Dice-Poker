#include "gamedata.h"
std::string gamedata::sPlayerName (
) const {
	return m_sPlayerName;
}
int gamedata::nDollarsCarried (
) const {
	return m_nDollarsCarried;
}
gamedata::gamedata (
	const std::string& sPlayerName
) {
	m_sPlayerName = sPlayerName;
	m_nDollarsCarried = 100;
}
gamedata::gamedata (
	const std::string& sPlayerName,
	const int& nDollarsCarried
) {
	m_sPlayerName = sPlayerName;
	m_nDollarsCarried = nDollarsCarried;
}
gamedata::gamedata (
	std::ifstream& ifstream_
) {
	char* ch_p_ = new char;
	std::string sPlayerName;
	std::string sDollarsCarried;
	do {
		ifstream_.read (ch_p_, 1);
		if (*ch_p_ != '\0')
			sPlayerName.push_back (*ch_p_);
	} while (*ch_p_ != '\0');
	m_sPlayerName = sPlayerName;
	do {
		ifstream_.read (ch_p_, 1);
		if (*ch_p_ != '\0')
			sDollarsCarried.push_back (*ch_p_);
	} while (*ch_p_ != '\0');
	m_nDollarsCarried = std::stoi (sDollarsCarried);
	delete ch_p_;
}
void gamedata::set_sPlayerName (
	const std::string& sPlayerName
) {
	m_sPlayerName = sPlayerName;
}
void gamedata::set_nDollarsCarried (
	int nDollarsCarried
) {
	m_nDollarsCarried = nDollarsCarried;
}
void save (
	const gamedata& gamedata_,
	std::ofstream& ofstream_
) {
	char* ch_p_ = new char;
	std::string sPlayerName = gamedata_.sPlayerName ();
	int nSizeOf_sPlayerName = sPlayerName.size ();
	for (int i = 0; i < nSizeOf_sPlayerName; i++) {
		*ch_p_ = sPlayerName[i];
		ofstream_.write (ch_p_, 1);
	}
	*ch_p_ = '\0';
	ofstream_.write (ch_p_, 1);
	std::string sDollarsCarried = std::to_string (gamedata_.nDollarsCarried ());
	int nSizeOf_sDollarsCarried = sDollarsCarried.size ();
	for (int i = 0; i < nSizeOf_sDollarsCarried; i++) {
		*ch_p_ = sDollarsCarried[i];
		ofstream_.write (ch_p_, 1);
	}
	*ch_p_ = '\0';
	ofstream_.write (ch_p_, 1);
	delete ch_p_;
}
void load (
	std::ifstream& ifstream_,
	gamedata& gamedata_
) {
	char* ch_p_ = new char;
	std::string sPlayerName;
	std::string sDollarsCarried;
	do {
		ifstream_.read (ch_p_, 1);
		if (*ch_p_ != '\0')
			sPlayerName.push_back (*ch_p_);
	} while (*ch_p_ != '\0');
	gamedata_.set_sPlayerName (sPlayerName);
	do {
		ifstream_.read (ch_p_, 1);
		if (*ch_p_ != '\0')
			sDollarsCarried.push_back (*ch_p_);
	} while (*ch_p_ != '\0');
	gamedata_.set_nDollarsCarried (std::stoi (sDollarsCarried));
	delete ch_p_;
}