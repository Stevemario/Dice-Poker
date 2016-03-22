#ifndef SCREENELEMENT_H
#define SCREENELEMENT_H
#include "screenelement_enum.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
class screenelement {
	public: virtual screenelement_enum screenelement_enum_ (
	) const = 0;
	public: virtual bool bClicked (
		const sf::Event::MouseButtonEvent&
	) const = 0;
	public: virtual void draw (
		sf::RenderWindow&
	) const = 0;
};
typedef std::vector <screenelement*> screenelements;
void draw (
	const screenelements&,
	sf::RenderWindow&
);
void clear (
	screenelements&
);
namespace screenelement_rectangle {
	template <class screenelement_rectangle_enum>
	class screenelement_rectangle : public screenelement {
		private: sf::Text m_text;
		private: sf::RectangleShape m_rs;
		private: bool m_bIsHeldDown;
		public: screenelement_enum screenelement_enum_ (
		) const;
		private: sf::RectangleShape rs_ (
		) const;
		public: bool bClicked (
			const sf::Event::MouseButtonEvent&
		) const;
		public: virtual screenelement_rectangle_enum screenelement_rectangle_enum_ (
		) const = 0;
		public: bool bIsHeldDown (
		) const;
		public: void draw (
			sf::RenderWindow&
		) const;
		public: void set_bIsHeldDown (
			bool
		);
		protected: void create (
			float,
			float,
			const sf::Color&
		);
		public: void stretch (
			float,
			float
		);
		public: void move (
			float,
			float
		);
	};
}
namespace screenelement_label {
	template <class screenelement_label_enum>
	class screenelement_label : public screenelement {
		private: sf::Text m_text;
		private: bool m_bIsHeldDown;
		public: screenelement_enum screenelement_enum_ (
		) const;
		private: sf::Text text_ (
		) const;
		public: sf::FloatRect frBounds_text (
		) const;
		public: bool bClicked (
			const sf::Event::MouseButtonEvent&
		) const;
		public: virtual screenelement_label_enum screenelement_label_enum_ (
		) const = 0;
		public: bool bIsHeldDown (
		) const;
		public: void draw (
			sf::RenderWindow&
		) const;
		public: void set_bIsHeldDown (
			bool
		);
		protected: void create (
			const std::string&,
			const sf::Font&,
			unsigned int,
			const sf::Color&
		);
		public: void move (
			float,
			float
		);
	};
}
namespace screenelement_button {
	template <class screenelement_button_enum>
	class screenelement_button : public screenelement {
		private: sf::Text m_text;
		private: sf::RectangleShape m_rs;
		private: bool m_bIsHeldDown;
		public: screenelement_enum screenelement_enum_ (
		) const;
		private: sf::RectangleShape rs_ (
		) const;
		public: sf::FloatRect frBounds_rs (
		) const;
		public: bool bClicked (
			const sf::Event::MouseButtonEvent&
		) const;
		public: virtual screenelement_button_enum screenelement_button_enum_ (
		) const = 0;
		public: bool bIsHeldDown (
		) const;
		public: void draw (
			sf::RenderWindow&
		) const;
		public: void set_bIsHeldDown (
			bool
		);
		protected: void create (
			const std::string&,
			const sf::Font&,
			unsigned int,
			const sf::Color&,
			const sf::Color&
		);
		public: void stretch (
			float,
			float
		);
		public: void move (
			float,
			float
		);
	};
}
#include "screenelement.tpp"
#endif