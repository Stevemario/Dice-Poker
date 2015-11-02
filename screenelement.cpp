#include "screenelement.h"
void draw (
	const std::vector <screenelement*>& vec_screenelement_pToDraw,
	sf::RenderWindow& rwDestination
) {
	unsigned int nAmountOfElements = vec_screenelement_pToDraw.size ();
	unsigned int nElementIndex;
	for (nElementIndex = 0; nElementIndex < nAmountOfElements; nElementIndex++) {
		vec_screenelement_pToDraw[nElementIndex]->draw (rwDestination);
	}
}
void clear (
	std::vector <screenelement*>& vec_screenelement_pToClear
) {
	unsigned int nAmountOfElements = vec_screenelement_pToClear.size ();
	unsigned int nElementIndex = 0;
	for (nElementIndex = 0; nElementIndex < nAmountOfElements; nElementIndex++) {
		delete vec_screenelement_pToClear[nElementIndex];
		vec_screenelement_pToClear[nElementIndex] = nullptr;
	}
	vec_screenelement_pToClear.clear ();
}