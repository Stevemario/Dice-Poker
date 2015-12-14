#ifndef GAMEDATA_H
#define GAMEDATA_H
#include <fstream>
#include <string>
class gamedata {
	private: std::string m_sPlayerName;
	private: int m_nDollarsCarried;
	public: std::string sPlayerName (
	) const;
	public: int nDollarsCarried (
	) const;
	public: gamedata (
		const std::string&
	);
	public: gamedata (
		const std::string&,
		const int&
	);
	public: gamedata (
		std::ifstream&
	);
	public: void set_sPlayerName (
		const std::string&
	);
	public: void set_nDollarsCarried (
		int
	);
};
void save (
	const gamedata&,
	std::ofstream&
);
void load (
	std::ifstream&,
	gamedata&
);
#endif