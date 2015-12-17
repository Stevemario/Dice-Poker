#include "iofunctions.h"
std::string iofunctions::sReading (
	std::ifstream& ifstream_
) {
	char* ch_p_ = new char;
	std::string s_;
	do {
		ifstream_.read (ch_p_, 1);
		if (*ch_p_ != '\0')
			s_.push_back (*ch_p_);
	} while (*ch_p_ != '\0');
	delete ch_p_;
	return s_;
}
int iofunctions::nReading (
	std::ifstream& ifstream_
) {
	int n_ = std::stoi (sReading (ifstream_));
	return n_;
}
void iofunctions::write (
	const std::string s_,
	std::ofstream& ofstream_
) {
	char* ch_p_ = new char;
	int nSize_s = s_.size ();
	for (int i = 0; i < nSize_s; i++) {
		*ch_p_ = s_[i];
		ofstream_.write (ch_p_, 1);
	}
	*ch_p_ = '\0';
	ofstream_.write (ch_p_, 1);
	delete ch_p_;
}