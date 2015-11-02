#include "diceset.h"
int intx2::n (
	int nIndex
) const {
	int n;
	switch (nIndex) {
		default:
		case 0: n = n0; break;
		case 1: n = n1; break;
	}
	return n;
}
void intx2::set_n (
	int nIndex,
	int nValue
) {
	switch (nIndex) {
		default:
		case 0: n0 = nValue; break;
		case 1: n1 = nValue; break;
	}
}
int intx3::n (
	int nIndex
) const {
	int n;
	switch (nIndex) {
		default:
		case 0: n = n0; break;
		case 1: n = n1; break;
		case 2: n = n2; break;
	}
	return n;
}
void intx3::set_n (
	int nIndex,
	int nValue
) {
	switch (nIndex) {
		default:
		case 0: n0 = nValue; break;
		case 1: n1 = nValue; break;
		case 2: n2 = nValue; break;
	}
}
int intx5::n (
	int nIndex
) const {
	int n;
	switch (nIndex) {
		default:
		case 0: n = n0; break;
		case 1: n = n1; break;
		case 2: n = n2; break;
		case 3: n = n3; break;
		case 4: n = n4; break;
	}
	return n;
}
void intx5::set_n (
	int nIndex,
	int nValue
) {
	switch (nIndex) {
		default:
		case 0: n0 = nValue; break;
		case 1: n1 = nValue; break;
		case 2: n2 = nValue; break;
		case 3: n3 = nValue; break;
		case 4: n4 = nValue; break;
	}
}
bool bHasDice (
	const intx5& n5Dice,
	int nDiceValue
) {
	bool bHasDice = false;
	for (int i = 0; i < 5 && bHasDice != true; i++) {
		if (n5Dice.n (i) == nDiceValue)
				bHasDice = true;
	}
	return bHasDice;
}
bool bIsStraight (
	const intx5& n5Dice,
	int& nDiceMissing
) {
	bool bDiceMakeStraight = false;
	if (bHasDice (n5Dice, 6)) {
		bool bFoundDiceMissing = false;
		for (int i = 1; i <= 4 && bFoundDiceMissing != true; i++) {
			if (bHasDice (n5Dice, i) != true) {
				nDiceMissing = i;
				bFoundDiceMissing = true;
			}
		}
		if (bFoundDiceMissing != true) {
			nDiceMissing = 5;
		}
		if (nDiceMissing == 1)
			bDiceMakeStraight = true;
	} else {
		nDiceMissing = 6;
		bDiceMakeStraight = true;
	}
	return bDiceMakeStraight;
}
diceset* diceset_p_ (
	const intx5& n5Dice
) {
	diceset* diceset_p_;
	int nDiceValid = 0;
	for (int i = 0; i < 5; i++) {
		if (1 <= n5Dice.n (i))
			if (n5Dice.n (i) <= 6)
				nDiceValid++;
	}
	if (nDiceValid != 5) {
		diceset_p_ = new diceset_invalid ();
	} else {
		int cSame = 0;
		for (int i = 0; i < 5; i++) {
			if (n5Dice.n (0) == n5Dice.n (i))
				cSame++;
		}
		switch (cSame) {
			case 5: {
				diceset_p_ = new diceset_fiveofakind (n5Dice.n (0));
				break;
			}
			case 4: {
				int nDiceAppearingTimes4 = n5Dice.n (0);
				int nDiceAppearingTimes1;
				bool bFoundDice = false;
				for (int i = 1; i < 5 && bFoundDice != true; i++) {
					if (n5Dice.n (0) != n5Dice.n (i)) {
						nDiceAppearingTimes1 = n5Dice.n (i);
						bFoundDice = true;
					}
				}
				diceset_p_ = new diceset_fourofakind (nDiceAppearingTimes4, nDiceAppearingTimes1);
				break;
			}
			case 3: {
				intx2 n2DiceNotConforming;
				bool bSet_nDiceNotConforming[2] = {false, false};
				bool bFoundDice = false;
				for (int i = 1; i < 5 && bFoundDice != true; i++) {
					if (n5Dice.n (0) != n5Dice.n (i)) {
						if (bSet_nDiceNotConforming[0] != true) {
							n2DiceNotConforming.set_n(0, n5Dice.n (i));
							bSet_nDiceNotConforming[0] = true;
						} else {
							n2DiceNotConforming.set_n(1, n5Dice.n (i));
							bSet_nDiceNotConforming[1] = true;
							bFoundDice = true;
						}
					}
				}
				if (n2DiceNotConforming.n (0) == n2DiceNotConforming.n (1))
					diceset_p_ = new diceset_fullhouse (n5Dice.n (0), n2DiceNotConforming.n (0));
				else
					diceset_p_ = new diceset_threeofakind (n5Dice.n (0), n2DiceNotConforming);
				break;
			}
			case 2: {
				cSame = 0;
				for (int i = 0; i < 5; i++) {
					if (n5Dice.n (1) == n5Dice.n (i))
						cSame++;
				}
				switch (cSame) {
					case 3: {
						diceset_p_ = new diceset_fullhouse (n5Dice.n (1), n5Dice.n (0));
						break;
					}
					case 2: {
						if (n5Dice.n (0) == n5Dice.n (1)) {
							cSame = 0;
							for (int i = 0; i < 5; i++) {
								if (n5Dice.n (2) == n5Dice.n (i))
									cSame++;
							}
							switch (cSame) {
								case 3: {
									diceset_p_ = new diceset_fullhouse (n5Dice.n (2), n5Dice.n (0));
									break;
								}
								case 2: {
									intx2 n2DiceAppearingTimes2;
									n2DiceAppearingTimes2.set_n (0, n5Dice.n (0));
									n2DiceAppearingTimes2.set_n (1, n5Dice.n (2));
									int nDiceNotConforming;
									if (n5Dice.n (2) == n5Dice.n (3))
										nDiceNotConforming = n5Dice.n (4);
									else
										nDiceNotConforming = n5Dice.n (3);
									diceset_p_ = new diceset_twopair (n2DiceAppearingTimes2, nDiceNotConforming);
									break;
								}
								case 1: {
									if (n5Dice.n (3) == n5Dice.n (4)) {
										intx2 n2DiceAppearingTimes2;
										n2DiceAppearingTimes2.set_n (0, n5Dice.n (0));
										n2DiceAppearingTimes2.set_n (1, n5Dice.n (3));
										diceset_p_ = new diceset_twopair (n2DiceAppearingTimes2, n5Dice.n (2));
									} else {
										intx3 n3DiceAppearingTimes1;
										n3DiceAppearingTimes1.set_n (0, n5Dice.n (2));
										n3DiceAppearingTimes1.set_n (1, n5Dice.n (3));
										n3DiceAppearingTimes1.set_n (2, n5Dice.n (4));
										diceset_p_ = new diceset_onepair (n5Dice.n (0), n3DiceAppearingTimes1);
									}
									break;
								}
							}
						} else {
							intx2 n2DiceAppearingTimes2;
							n2DiceAppearingTimes2.set_n (0, n5Dice.n (0));
							n2DiceAppearingTimes2.set_n (1, n5Dice.n (1));
							int nDiceAppearingTimes1;
							for(int i = 2; i < 5; i++) {
								if(n5Dice.n (0) != n5Dice.n (i))
									if(n5Dice.n (1) != n5Dice.n (i))
										nDiceAppearingTimes1 = n5Dice.n (i);
							}
							diceset_p_ = new diceset_twopair (n2DiceAppearingTimes2, nDiceAppearingTimes1);
						}
						break;
					}
					case 1: {
						cSame = 0;
						for (int i = 0; i < 5; i++) {
							if (n5Dice.n (2) == n5Dice.n (i))
								cSame++;
						}
						switch(cSame) {
							case 2: {
								if (n5Dice.n (0) == n5Dice.n (2)) {
									if (n5Dice.n (3) == n5Dice.n (4)) {
										intx2 n2DiceAppearingTimes2;
										n2DiceAppearingTimes2.set_n (0, n5Dice.n (0));
										n2DiceAppearingTimes2.set_n (1, n5Dice.n (3));
										int nDiceAppearingTimes1 = n5Dice.n (1);
										diceset_p_ = new diceset_twopair (n2DiceAppearingTimes2, nDiceAppearingTimes1);
									} else {
										int nDiceAppearingTimes2 = n5Dice.n (0);
										intx3 n3DiceAppearingTimes1;
										n3DiceAppearingTimes1.set_n (0, n5Dice.n (1));
										n3DiceAppearingTimes1.set_n (1, n5Dice.n (3));
										n3DiceAppearingTimes1.set_n (2, n5Dice.n (4));
										diceset_p_ = new diceset_onepair (nDiceAppearingTimes2, n3DiceAppearingTimes1);
									}
								} else {
									intx2 n2DiceAppearingTimes2;
									n2DiceAppearingTimes2.set_n (0, n5Dice.n (0));
									n2DiceAppearingTimes2.set_n (1, n5Dice.n (2));
									int nDiceAppearingTimes1 = n5Dice.n (1);
									diceset_p_ = new diceset_twopair (n2DiceAppearingTimes2, nDiceAppearingTimes1);
								}
								break;
							}
							case 1: {
								int nDiceAppearingTimes2 = n5Dice.n (0);
								intx3 n3DiceAppearingTimes1;
								n3DiceAppearingTimes1.set_n (0, n5Dice.n (1));
								n3DiceAppearingTimes1.set_n (1, n5Dice.n (2));
								if (n5Dice.n (0) == n5Dice.n (3))
									n3DiceAppearingTimes1.set_n (2, n5Dice.n (4));
								else
									n3DiceAppearingTimes1.set_n (2, n5Dice.n (3));
								diceset_p_ = new diceset_onepair (nDiceAppearingTimes2, n3DiceAppearingTimes1);
								break;
							}
						}
						break;
					}
				}
				break;
			}
			case 1: {
				cSame = 0;
				for (int i = 0; i < 5; i++) {
					if (n5Dice.n (1) == n5Dice.n (i))
						cSame++;
				}
				switch (cSame) {
					case 4: {
						diceset_p_ = new diceset_fourofakind (n5Dice.n (1), n5Dice.n (0));
						break;
					}
					case 3: {
						intx2 n2DiceAppearingTimes1;
						n2DiceAppearingTimes1.set_n (0, n5Dice.n (0));
						bool bFoundDice = false;
						for (int i = 2; i < 5 && bFoundDice != true; i++) {
							if (n5Dice.n (1) != n5Dice.n (i)) {
								n2DiceAppearingTimes1.set_n (1, n5Dice.n (i));
								bFoundDice = true;
							}
						}
						diceset_p_ = new diceset_threeofakind (n5Dice.n (1), n2DiceAppearingTimes1);
						break;
					}
					case 2: {
						cSame = 0;
						for (int i = 0; i < 5; i++) {
							if (n5Dice.n (2) == n5Dice.n (i))
								cSame++;
						}
						switch (cSame) {
							case 2: {
								if (n5Dice.n (1) == n5Dice.n (2)) {
									if (n5Dice.n (3) == n5Dice.n (4)) {
										intx2 n2DiceAppearingTimes2;
										int nDiceAppearingTimes1 = n5Dice.n (0);
										n2DiceAppearingTimes2.set_n (0, n5Dice.n (1));
										n2DiceAppearingTimes2.set_n (1, n5Dice.n (3));
										diceset_p_ = new diceset_twopair (n2DiceAppearingTimes2, nDiceAppearingTimes1);
									} else {
										intx3 n3DiceAppearingTimes1;
										int nDiceAppearingTimes2 = n5Dice.n (1);
										n3DiceAppearingTimes1.set_n (0, n5Dice.n (0));
										n3DiceAppearingTimes1.set_n (1, n5Dice.n (3));
										n3DiceAppearingTimes1.set_n (2, n5Dice.n (4));
										diceset_p_ = new diceset_onepair (nDiceAppearingTimes2, n3DiceAppearingTimes1);
									}
								} else {
									intx2 n2DiceAppearingTimes2;
									int nDiceAppearingTimes1 = n5Dice.n (0);
									n2DiceAppearingTimes2.set_n (0, n5Dice.n (1));
									n2DiceAppearingTimes2.set_n (1, n5Dice.n (2));
									diceset_p_ = new diceset_twopair (n2DiceAppearingTimes2, nDiceAppearingTimes1);
								}
								break;
							}
							case 1: {
								int nDiceAppearingTimes2 = n5Dice.n (1);
								intx3 n3DiceAppearingTimes1;
								n3DiceAppearingTimes1.set_n (0, n5Dice.n (0));
								n3DiceAppearingTimes1.set_n (1, n5Dice.n (2));
								if (n5Dice.n (1) == n5Dice.n (3)) {
									n3DiceAppearingTimes1.set_n (2, n5Dice.n (4));
								} else {
									n3DiceAppearingTimes1.set_n (2, n5Dice.n (3));
								}
								diceset_p_ = new diceset_onepair (nDiceAppearingTimes2, n3DiceAppearingTimes1);
								break;
							}
						}
						break;
					}
					case 1: {
						cSame = 0;
						for (int i = 0; i < 5; i++) {
							if (n5Dice.n (2) == n5Dice.n (i))
								cSame++;
						}
						switch (cSame) {
							case 3: {
								intx2 n2DiceAppearingTimes1;
								n2DiceAppearingTimes1.set_n (0, n5Dice.n (0));
								n2DiceAppearingTimes1.set_n (1, n5Dice.n (1));
								diceset_p_ = new diceset_threeofakind (n5Dice.n (2), n2DiceAppearingTimes1);
								break;
							}
							case 2: {
								intx3 n3DiceAppearingTimes1;
								n3DiceAppearingTimes1.set_n (0, n5Dice.n (0));
								n3DiceAppearingTimes1.set_n (1, n5Dice.n (1));
								if (n5Dice.n (2) == n5Dice.n (3))
									n3DiceAppearingTimes1.set_n (2, n5Dice.n (4));
								else
									n3DiceAppearingTimes1.set_n (2, n5Dice.n (3));
								diceset_p_ = new diceset_onepair (n5Dice.n (2), n3DiceAppearingTimes1);
								break;
							}
							case 1: {
								if (n5Dice.n (3) == n5Dice.n (4)) {
									intx3 n3DiceAppearingTimes1;
									n3DiceAppearingTimes1.set_n (0, n5Dice.n (0));
									n3DiceAppearingTimes1.set_n (1, n5Dice.n (1));
									n3DiceAppearingTimes1.set_n (2, n5Dice.n (2));
									diceset_p_ = new diceset_onepair (n5Dice.n (3), n3DiceAppearingTimes1);
								} else {
									bool bSetIsStraight;
									int nDiceMissing;
									bSetIsStraight = bIsStraight (n5Dice, nDiceMissing);
									if (bSetIsStraight) {
										if (nDiceMissing == 6)
											diceset_p_ = new diceset_straight (true);
										else
											diceset_p_ = new diceset_straight (false);
									} else {
										diceset_p_ = new diceset_highdice (nDiceMissing);
									}
								}
								break;
							}
						}
						break;
					}
				}
				break;
			}
		}
	}
	return diceset_p_;
}
diceset_invalid::diceset_invalid (
) {
}
int diceset_invalid::nScore (
) const {
	int nScore = -1;
	return nScore;
}
diceset_fiveofakind::diceset_fiveofakind (
	int nDice
) {
	m_nDice = nDice;
}
int diceset_fiveofakind::nScore (
) const {
	int nScore = -1 + 6;
	int nSetsBeatOfSameClass = 0;
	nSetsBeatOfSameClass += m_nDice - 1;
	nScore -= nSetsBeatOfSameClass;
	return nScore;
}
diceset_fourofakind::diceset_fourofakind (
	int nDiceAppearingTimes4,
	int nDiceAppearingTimes1
) {
	m_nDiceAppearingTimes4 = nDiceAppearingTimes4;
	m_nDiceAppearingTimes1 = nDiceAppearingTimes1;
}
int diceset_fourofakind::nScore (
) const {
	int nScore = -1 + 6 + 30;
	int nSetsBeatOfSameClass = 0;
	nSetsBeatOfSameClass += 5 * (m_nDiceAppearingTimes4 - 1);
	if (m_nDiceAppearingTimes1 <= m_nDiceAppearingTimes4)
		nSetsBeatOfSameClass += (m_nDiceAppearingTimes1 - 1);
		//minus 1 because it does not beat iteself
	else
		nSetsBeatOfSameClass += (m_nDiceAppearingTimes1 - 2);
		//minus 2 because it does not beat itself and
		//it does not beat a set of the same class when 
		//m_nDiceAppearingTimes1 equals m_nDiceAppearingTimes4.
	nScore -= nSetsBeatOfSameClass;
	return nScore;
}
diceset_fullhouse::diceset_fullhouse (
	int nDiceAppearingTimes3,
	int nDiceAppearingTimes2
) {
	m_nDiceAppearingTimes3 = nDiceAppearingTimes3;
	m_nDiceAppearingTimes2 = nDiceAppearingTimes2;
}
int diceset_fullhouse::nScore (
) const {
	int nScore = -1 + 6 + 30 + 30;
	int nSetsBeatOfSameClass = 0;
	nSetsBeatOfSameClass += 5 * (m_nDiceAppearingTimes3 - 1);
	if (m_nDiceAppearingTimes2 <= m_nDiceAppearingTimes3)
		nSetsBeatOfSameClass += (m_nDiceAppearingTimes2 - 1);
		//minus 1 because it does not beat iteself
	else
		nSetsBeatOfSameClass += (m_nDiceAppearingTimes2 - 2);
		//minus 2 because it does not beat itself and
		//it does not beat a set of the same class when 
		//m_nDiceAppearingTimes2 equals m_nDiceAppearingTimes3.
	nScore -= nSetsBeatOfSameClass;
	return nScore;
}
diceset_straight::diceset_straight (
	bool bIsHighStraight
) {
	m_bIsHighStraight = bIsHighStraight;
}
int diceset_straight::nScore (
) const {
	int nScore = -1 + 6 + 30 + 30 + 2;
	int nSetsBeatOfSameClass = 0;
	if (m_bIsHighStraight)
		nSetsBeatOfSameClass += 1;
	nScore -= nSetsBeatOfSameClass;
	return nScore;
}
diceset_threeofakind::diceset_threeofakind (
	int nDiceAppearingTimes3,
	const intx2& n2DiceAppearingTimes1
) {
	m_nDiceAppearingTimes3 = nDiceAppearingTimes3;
	if (n2DiceAppearingTimes1.n (0) < n2DiceAppearingTimes1.n (1)) {
		m_n2DiceAppearingTimes1.set_n (0, n2DiceAppearingTimes1.n (1));
		m_n2DiceAppearingTimes1.set_n (1, n2DiceAppearingTimes1.n (0));
	} else {
		m_n2DiceAppearingTimes1.set_n (0, n2DiceAppearingTimes1.n (0));
		m_n2DiceAppearingTimes1.set_n (1, n2DiceAppearingTimes1.n (1));
	}
}
int diceset_threeofakind::nScore (
) const {
	int nScore = -1 + 6 + 30 + 30 + 2 + 60;
	int nSetsBeatOfSameClass = 0;
	int nDice0 = m_nDiceAppearingTimes3;
	int nDice1;
	int nDice2;
	int nDice1End = m_n2DiceAppearingTimes1.n (0);
	int nDice2End;
	nSetsBeatOfSameClass += 10 * (m_nDiceAppearingTimes3 - 1);
	for (nDice1 = 2; nDice1 <= nDice1End; nDice1++) {
		if (nDice1 < m_n2DiceAppearingTimes1.n (0))
			nDice2End = nDice1 - 1;
		else
			nDice2End = m_n2DiceAppearingTimes1.n (1) - 1;
		for (nDice2 = 1; nDice2 <= nDice2End; nDice2++) {
			if (nDice1 != nDice0)
				if (nDice2 != nDice0)
					nSetsBeatOfSameClass++;
		}
	}
	nScore -= nSetsBeatOfSameClass;
	return nScore;
}
diceset_twopair::diceset_twopair (
	const intx2& n2DiceAppearingTimes2,
	int nDiceAppearingTimes1
) {
	if (n2DiceAppearingTimes2.n (0) < n2DiceAppearingTimes2.n (1)) {
		m_n2DiceAppearingTimes2.set_n (0, n2DiceAppearingTimes2.n (1));
		m_n2DiceAppearingTimes2.set_n (1, n2DiceAppearingTimes2.n (0));
	} else {
		m_n2DiceAppearingTimes2.set_n (0, n2DiceAppearingTimes2.n (0));
		m_n2DiceAppearingTimes2.set_n (1, n2DiceAppearingTimes2.n (1));
	}
	m_nDiceAppearingTimes1 = nDiceAppearingTimes1;
}
int diceset_twopair::nScore (
) const {
	int nScore = -1 + 6 + 30 + 30 + 2 + 60 + 60;
	int nSetsBeatOfSameClass = 0;
	int nDice0;
	int nDice1;
	int nDice2;
	int nDice0End = m_n2DiceAppearingTimes2.n (0);
	int nDice1End;
	int nDice2End = 6;
	for (nDice0 = 2; nDice0 <= nDice0End; nDice0++) {
		if (nDice0 == nDice0End)
			nDice1End = m_n2DiceAppearingTimes2.n (1);
		else
			nDice1End = nDice0 - 1;
		for (nDice1 = 1; nDice1 <= nDice1End; nDice1++) {
			if (nDice0 == nDice0End)
				if (nDice1 == nDice1End)
					nDice2End = m_nDiceAppearingTimes1 - 1;
			for (nDice2 = 1; nDice2 <= nDice2End; nDice2++) {
				if (nDice2 != nDice0)
					if (nDice2 != nDice1)
						nSetsBeatOfSameClass++;
			}
		}
	}
	nScore -= nSetsBeatOfSameClass;
	return nScore;
}
diceset_onepair::diceset_onepair (
	int nDiceAppearingTimes2,
	const intx3& n3DiceAppearingTimes1
) {
	m_nDiceAppearingTimes2 = nDiceAppearingTimes2;
	if (n3DiceAppearingTimes1.n (0) < n3DiceAppearingTimes1.n (1)) {
		if (n3DiceAppearingTimes1.n (0) < n3DiceAppearingTimes1.n (2)) {
			if (n3DiceAppearingTimes1.n (1) < n3DiceAppearingTimes1.n (2)) {
				m_n3DiceAppearingTimes1.set_n (0, n3DiceAppearingTimes1.n (2));
				m_n3DiceAppearingTimes1.set_n (1, n3DiceAppearingTimes1.n (1));
				m_n3DiceAppearingTimes1.set_n (2, n3DiceAppearingTimes1.n (0));
			} else {
				m_n3DiceAppearingTimes1.set_n (0, n3DiceAppearingTimes1.n (1));
				m_n3DiceAppearingTimes1.set_n (1, n3DiceAppearingTimes1.n (2));
				m_n3DiceAppearingTimes1.set_n (2, n3DiceAppearingTimes1.n (0));
			}
		} else {
			m_n3DiceAppearingTimes1.set_n (0, n3DiceAppearingTimes1.n (1));
			m_n3DiceAppearingTimes1.set_n (1, n3DiceAppearingTimes1.n (0));
			m_n3DiceAppearingTimes1.set_n (2, n3DiceAppearingTimes1.n (2));
		}
	} else {
		if (n3DiceAppearingTimes1.n (0) < n3DiceAppearingTimes1.n (2)) {
			m_n3DiceAppearingTimes1.set_n (0, n3DiceAppearingTimes1.n (2));
			m_n3DiceAppearingTimes1.set_n (1, n3DiceAppearingTimes1.n (0));
			m_n3DiceAppearingTimes1.set_n (2, n3DiceAppearingTimes1.n (1));
		} else {
			if (n3DiceAppearingTimes1.n (1) < n3DiceAppearingTimes1.n (2)) {
				m_n3DiceAppearingTimes1.set_n (0, n3DiceAppearingTimes1.n (0));
				m_n3DiceAppearingTimes1.set_n (1, n3DiceAppearingTimes1.n (2));
				m_n3DiceAppearingTimes1.set_n (2, n3DiceAppearingTimes1.n (1));
			} else {
				m_n3DiceAppearingTimes1.set_n (0, n3DiceAppearingTimes1.n (0));
				m_n3DiceAppearingTimes1.set_n (1, n3DiceAppearingTimes1.n (1));
				m_n3DiceAppearingTimes1.set_n (2, n3DiceAppearingTimes1.n (2));
			}
		}
	}
}
int diceset_onepair::nScore (
) const {
	int nScore = -1 + 6 + 30 + 30 + 2 + 60 + 60 + 60;
	int nSetsBeatOfSameClass = 0;
	int nDice0;
	int nDice1;
	int nDice2;
	int nDice3;
	int nDice0End = m_nDiceAppearingTimes2;
	int nDice1End;
	int nDice2End;
	int nDice3End;
	for (nDice0 = 1; nDice0 <= nDice0End; nDice0++) {
		if (nDice0 == nDice0End)
			nDice1End = m_n3DiceAppearingTimes1.n (0);
		else
			nDice1End = 6;
		for (nDice1 = 3; nDice1 <= nDice1End; nDice1++) {
			if (nDice0 != nDice1) {
				if (
					nDice0 == nDice0End &&
					nDice1 == nDice1End
				)
					nDice2End = m_n3DiceAppearingTimes1.n (1);
				else
					nDice2End = nDice1 - 1;
				for (nDice2 = 1; nDice2 <= nDice2End; nDice2++) {
					if (nDice0 != nDice2) {
						if (
							nDice0 == nDice0End &&
							nDice1 == nDice1End &&
							nDice2 == nDice2End
						)
							nDice3End = m_n3DiceAppearingTimes1.n (2) - 1;
						else
							nDice3End = nDice2 - 1;
						for (nDice3 = 1; nDice3 <= nDice3End; nDice3++) {
							if (nDice0 != nDice3)
								nSetsBeatOfSameClass++;
						}
					}
				}
			}
		}
	}
	nScore -= nSetsBeatOfSameClass;
	return nScore;
}
diceset_highdice::diceset_highdice (
	int nDiceMissing
) {
	m_nDiceMissing = nDiceMissing;
}
int diceset_highdice::nScore (
) const {
	int nScore = -1 + 6 + 30 + 30 + 2 + 60 + 60 + 60 + 4;
	int nSetsBeatOfSameClass = 0;
	nSetsBeatOfSameClass += 5 - m_nDiceMissing;
	nScore -= nSetsBeatOfSameClass;
	return nScore;
}