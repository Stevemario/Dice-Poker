#ifndef IOFUNCTIONS_H
#define IOFUNCTIONS_H
#include <fstream>
#include <string>
namespace iofunctions {
	int nReading (
		std::ifstream&
	);
	std::string sReading (
		std::ifstream&
	);
	void write (
		const int&,
		std::ofstream&
	);
	void write (
		const std::string&,
		std::ofstream&
	);
}
#endif