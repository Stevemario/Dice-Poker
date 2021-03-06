#ifndef DICESET_H
#define DICESET_H
#include "iofunctions.h"
#include <array>
typedef std::array <int, 2> intx2;
typedef std::array <int, 3> intx3;
typedef std::array <int, 5> intx5;
namespace iofunctions {
	void write (
		const intx5&,
		std::ofstream&
	);
}
intx5 n5Reading (
	std::ifstream&
);
class diceset {
	public: virtual int nScore (
	) const = 0;
};
bool bHasDice (
	const intx5&,
	int
);
bool bIsStraight (
	const intx5&,
	int&
);
/*
	This function initializes a diceset object and should be the only way to do 
	that.  This function determines which of the diceset derived classes' 
	constructors is appropriate for the input variable numbers.
*/
diceset* diceset_p_ (
	const intx5&
);
class diceset_invalid : public diceset {
	private: diceset_invalid (
	);

	public: int nScore (
	) const;

	friend diceset* diceset_p_ (
		const intx5&
	);
};
class diceset_fiveofakind : public diceset {
	private: int m_nDice;

	private: diceset_fiveofakind (
		int
	);

	public: int nScore (
	) const;

	friend diceset* diceset_p_ (
		const intx5&
	);
};
class diceset_fourofakind : public diceset {
	private: int m_nDiceAppearingTimes4;
	private: int m_nDiceAppearingTimes1;

	private: diceset_fourofakind (
		int,
		int
	);

	public: int nScore (
	) const;

	friend diceset* diceset_p_ (
		const intx5&
	);
};
class diceset_fullhouse : public diceset {
	private: int m_nDiceAppearingTimes3;
	private: int m_nDiceAppearingTimes2;

	private: diceset_fullhouse (
		int,
		int
	);
					 
	public: int nScore (
	) const;

	friend diceset* diceset_p_ (
		const intx5&
	);
};
class diceset_straight : public diceset {
	private: bool m_bIsHighStraight;

	private: diceset_straight (
		bool
	);
					 
	public: int nScore (
	) const;

	friend diceset* diceset_p_ (
		const intx5&
	);
};
class diceset_threeofakind : public diceset {
	private: int m_nDiceAppearingTimes3;
	//Sorted 0 to 1, largest to smallest
	private: intx2 m_n2DiceAppearingTimes1;

	private: diceset_threeofakind (
		int,
		const intx2&
	);
					 
	public: int nScore (
	) const;

	friend diceset* diceset_p_ (
		const intx5&
	);
};
class diceset_twopair : public diceset {
	//Sorted 0 to 1, largest to smallest
	private: intx2 m_n2DiceAppearingTimes2;
	private: int m_nDiceAppearingTimes1;

	private: diceset_twopair (
		const intx2&,
		int
	);
					 
	public: int nScore (
	) const;

	friend diceset* diceset_p_ (
		const intx5&
	);
};
class diceset_onepair : public diceset {
	private: int m_nDiceAppearingTimes2;
	//Sorted 0 to 2, largest to smallest
	private: intx3 m_n3DiceAppearingTimes1;

	private: diceset_onepair (
		int,
		const intx3&
	);
					 
	public: int nScore (
	) const;

	friend diceset* diceset_p_ (
		const intx5&
	);
};
class diceset_highdice : public diceset {
	private: int m_nDiceMissing;

	private: diceset_highdice (
		int
	);
					 
	public: int nScore (
	) const;

	friend diceset* diceset_p_ (
		const intx5&
	);
};
#endif