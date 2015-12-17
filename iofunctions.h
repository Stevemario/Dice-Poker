#ifndef IOFUNCTIONS_H
#define IOFUNCTIONS_H
#include <fstream>
#include <string>
namespace iofunctions {
	std::string sReading (
		std::ifstream&
	);
	int nReading (
		std::ifstream&
	);
	void write (
		const std::string,
		std::ofstream&
	);
}
#endif