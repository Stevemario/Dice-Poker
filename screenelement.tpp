namespace screenelement_rectangle {
	template <class screenelement_rectangle_enum>
	screenelement_enum screenelement_rectangle <screenelement_rectangle_enum>::screenelement_enum_ (
	) const {
		return screenelement_enum::Rectangle;
	}
	template <class screenelement_rectangle_enum>
	sf::RectangleShape screenelement_rectangle <screenelement_rectangle_enum>::rs_ (
	) const {
		return m_rs;
	}
	template <class screenelement_rectangle_enum>
	bool screenelement_rectangle <screenelement_rectangle_enum>::bClicked (
		const sf::Event::MouseButtonEvent& mbe_
	) const {
		bool bClicked = false;
		float fClickX = float (mbe_.x);
		float fClickY = float (mbe_.y);
		if (m_rs.getRotation () == 0.f) {
			if (m_rs.getGlobalBounds ().contains (fClickX, fClickY))
				bClicked = true;
		} else {
			//Don't know how to check
		}
		return bClicked;
	}
	template <class screenelement_rectangle_enum>
	bool screenelement_rectangle <screenelement_rectangle_enum>::bIsHeldDown (
	) const {
		return m_bIsHeldDown;
	}
	template <class screenelement_rectangle_enum>
	void screenelement_rectangle <screenelement_rectangle_enum>::draw (
		sf::RenderWindow& rwDestination
	) const {
		rwDestination.draw (m_rs);
		rwDestination.draw (m_text);
	}
	template <class screenelement_rectangle_enum>
	void screenelement_rectangle <screenelement_rectangle_enum>::set_bIsHeldDown (
		bool bToSet
	) {
		m_bIsHeldDown = bToSet;
	}
	template <class screenelement_rectangle_enum>
	void screenelement_rectangle <screenelement_rectangle_enum>::create (
		float fWidth,
		float fHeight,
		const sf::Color& clrBackground
	) {
		m_rs.setSize (sf::Vector2f (fWidth, fHeight));
		m_rs.setFillColor (clrBackground);
	}
	template <class screenelement_rectangle_enum>
	void screenelement_rectangle <screenelement_rectangle_enum>::stretch (
		float fSizeX,
		float fSizeY
	) {
		sf::Vector2f v2f_ = m_rs.getSize ();
		bool bWillStretchX = false;
		bool bWillStretchY = false;
		if (v2f_.x < fSizeX)
			bWillStretchX = true;
		if (v2f_.y < fSizeY)
			bWillStretchY = true;
		if (bWillStretchX) {
			if (bWillStretchY) {
				m_rs.setSize (sf::Vector2f (fSizeX, fSizeY));
				m_text.move (
					.5f * (fSizeX - v2f_.x),
					.5f * (fSizeY - v2f_.y)
				);
			} else {
				m_rs.setSize (sf::Vector2f (fSizeX, v2f_.y));
				m_text.move (
					.5f * (fSizeX - v2f_.x),
					0
				);
			}
		} else {
			if (bWillStretchY) {
				m_rs.setSize (sf::Vector2f (v2f_.x, fSizeY));
				m_text.move (
					0,
					.5f * (fSizeY - v2f_.y)
				);
			}
		}
	}
	template <class screenelement_rectangle_enum>
	void screenelement_rectangle <screenelement_rectangle_enum>::move (
		float fOffsetX,
		float fOffsetY
	) {
		m_text.move (fOffsetX, fOffsetY);
		m_rs.move (fOffsetX, fOffsetY);
	}
}
namespace screenelement_label {
	template <class screenelement_label_enum>
	screenelement_enum screenelement_label <screenelement_label_enum>::screenelement_enum_ (
	) const {
		return screenelement_enum::Label;
	}
	template <class screenelement_label_enum>
	sf::Text screenelement_label <screenelement_label_enum>::text_ (
	) const {
		return m_text;
	}
	template <class screenelement_label_enum>
	sf::FloatRect screenelement_label <screenelement_label_enum>::frBounds_text (
	) const {
		return m_text.getGlobalBounds ();
	}
	template <class screenelement_label_enum>
	bool screenelement_label <screenelement_label_enum>::bClicked (
		const sf::Event::MouseButtonEvent& mbe_
	) const {
		bool bClicked = false;
		float fClickX = float (mbe_.x);
		float fClickY = float (mbe_.y);
		if (m_text.getRotation () == 0.f) {
			if (m_text.getGlobalBounds ().contains (fClickX, fClickY))
				bClicked = true;
		} else {
			//Don't know how to check
		}
		return bClicked;
	}
	template <class screenelement_label_enum>
	bool screenelement_label <screenelement_label_enum>::bIsHeldDown (
	) const {
		return m_bIsHeldDown;
	}
	template <class screenelement_label_enum>
	void screenelement_label <screenelement_label_enum>::draw (
		sf::RenderWindow& rwDestination
	) const {
		rwDestination.draw (m_text);
	}
	template <class screenelement_label_enum>
	void screenelement_label <screenelement_label_enum>::set_bIsHeldDown (
		bool bToSet
	) {
		m_bIsHeldDown = bToSet;
	}
	template <class screenelement_label_enum>
	void screenelement_label <screenelement_label_enum>::create (
		const std::string& sLabel,
		const sf::Font& font_,
		unsigned int nCharacterSize,
		const sf::Color& clrText
	) {
		sf::FloatRect frTextBounds;
		m_text.setString (sLabel);
		m_text.setFont (font_);
		m_text.setCharacterSize (nCharacterSize);
		m_text.setColor (clrText);
		frTextBounds = m_text.getLocalBounds ();
		m_text.move (-1.f * frTextBounds.left, -1.f * frTextBounds.top);
	}
	template <class screenelement_label_enum>
	void screenelement_label <screenelement_label_enum>::move (
		float fOffsetX,
		float fOffsetY
	) {
		m_text.move (fOffsetX, fOffsetY);
	}
}
namespace screenelement_button {
	template <class screenelement_button_enum>
	screenelement_enum screenelement_button <screenelement_button_enum>::screenelement_enum_ (
	) const {
		return screenelement_enum::Button;
	}
	template <class screenelement_button_enum>
	sf::RectangleShape screenelement_button <screenelement_button_enum>::rs_ (
	) const {
		return m_rs;
	}
	template <class screenelement_button_enum>
	sf::FloatRect screenelement_button <screenelement_button_enum>::frBounds_rs (
	) const {
		return m_rs.getGlobalBounds ();
	}
	template <class screenelement_button_enum>
	bool screenelement_button <screenelement_button_enum>::bClicked (
		const sf::Event::MouseButtonEvent& mbe_
	) const {
		bool bClicked = false;
		float fClickX = float (mbe_.x);
		float fClickY = float (mbe_.y);
		if (m_rs.getRotation () == 0.f) {
			if (m_rs.getGlobalBounds ().contains (fClickX, fClickY))
				bClicked = true;
		} else {
			//Don't know how to check
		}
		return bClicked;
	}
	template <class screenelement_button_enum>
	bool screenelement_button <screenelement_button_enum>::bIsHeldDown (
	) const {
		return m_bIsHeldDown;
	}
	template <class screenelement_button_enum>
	void screenelement_button <screenelement_button_enum>::draw (
		sf::RenderWindow& rwDestination
	) const {
		rwDestination.draw (m_rs);
		rwDestination.draw (m_text);
	}
	template <class screenelement_button_enum>
	void screenelement_button <screenelement_button_enum>::set_bIsHeldDown (
		bool bToSet
	) {
		m_bIsHeldDown = bToSet;
	}
	template <class screenelement_button_enum>
	void screenelement_button <screenelement_button_enum>::create (
		const std::string& sLabel,
		const sf::Font& font_,
		unsigned int nCharacterSize,
		const sf::Color& clrText,
		const sf::Color& clrBackground
	) {
		sf::FloatRect frTextBounds;
		float fTextSizeX;
		float fTextSizeY;
		m_text.setString (sLabel);
		m_text.setFont (font_);
		m_text.setCharacterSize (nCharacterSize);
		m_text.setColor (clrText);
		frTextBounds = m_text.getLocalBounds ();
		fTextSizeX = frTextBounds.width;
		fTextSizeY = frTextBounds.height;
		m_text.move (-1.f * frTextBounds.left, -1.f * frTextBounds.top);
		m_text.move (.5f * fTextSizeY, .5f * fTextSizeY);
		m_rs.setSize (sf::Vector2f (fTextSizeX + fTextSizeY, 2.f * fTextSizeY));
		m_rs.setFillColor (clrBackground);
	}
	template <class screenelement_button_enum>
	void screenelement_button <screenelement_button_enum>::stretch (
		float fSizeX,
		float fSizeY
	) {
		sf::Vector2f v2f_ = m_rs.getSize ();
		bool bWillStretchX = false;
		bool bWillStretchY = false;
		if (v2f_.x < fSizeX)
			bWillStretchX = true;
		if (v2f_.y < fSizeY)
			bWillStretchY = true;
		if (bWillStretchX) {
			if (bWillStretchY) {
				m_rs.setSize (sf::Vector2f (fSizeX, fSizeY));
				m_text.move (
					.5f * (fSizeX - v2f_.x),
					.5f * (fSizeY - v2f_.y)
				);
			} else {
				m_rs.setSize (sf::Vector2f (fSizeX, v2f_.y));
				m_text.move (
					.5f * (fSizeX - v2f_.x),
					0
				);
			}
		} else {
			if (bWillStretchY) {
				m_rs.setSize (sf::Vector2f (v2f_.x, fSizeY));
				m_text.move (
					0,
					.5f * (fSizeY - v2f_.y)
				);
			}
		}
	}
	template <class screenelement_button_enum>
	void screenelement_button <screenelement_button_enum>::move (
		float fOffsetX,
		float fOffsetY
	) {
		m_text.move (fOffsetX, fOffsetY);
		m_rs.move (fOffsetX, fOffsetY);
	}
}