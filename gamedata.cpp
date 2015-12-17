#include "gamedata.h"
#include "iofunctions.h"
std::string gamedata::sPlayerName (
) const {
	return m_sPlayerName;
}
int gamedata::nDollarsCarried (
) const {
	return m_nDollarsCarried;
}
void gamedata::save (
	std::ofstream& ofstream_
) const {
	iofunctions::write (m_sPlayerName, ofstream_);
	iofunctions::write (std::to_string (m_nDollarsCarried), ofstream_);
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
	m_sPlayerName = iofunctions::sReading (ifstream_);
	m_nDollarsCarried = iofunctions::nReading (ifstream_);
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