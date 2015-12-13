#include "screenelement.h"
void draw (
	const screenelements& ses_,
	sf::RenderWindow& rw_
) {
	unsigned int nAmountOfElements = ses_.size ();
	unsigned int nElementIndex;
	for (nElementIndex = 0; nElementIndex < nAmountOfElements; nElementIndex++) {
		ses_[nElementIndex]->draw (rw_);
	}
}
void clear (
	screenelements& ses_
) {
	unsigned int nAmountOfElements = ses_.size ();
	unsigned int nElementIndex = 0;
	for (nElementIndex = 0; nElementIndex < nAmountOfElements; nElementIndex++) {
		delete ses_[nElementIndex];
		ses_[nElementIndex] = nullptr;
	}
	ses_.clear ();
}