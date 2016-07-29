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
void write (
	const gamedata& gamedata_,
	std::ofstream& ofstream_
) {
	iofunctions::write (gamedata_.sPlayerName (), ofstream_);
	iofunctions::write (gamedata_.nDollarsCarried (), ofstream_);
}