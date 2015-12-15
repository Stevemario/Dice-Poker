#ifndef MAINMENU_H
#define MAINMENU_H
#include "screenelement.h"
#include "gamedata.h"
#include "gameaction.h"
#include "gamemode.h"
#include "mainmenupage.h"
namespace mainmenu {
	void prepare (
		const bool&,
		const bool&,
		const std::string&,
		const sf::Font&,
		const mainmenupage&,
		const gamedata*&,
		screenelements&
	);
	void addButtonsPageSwitching (
		const sf::Font&,
		screenelements&
	);
	void addPageSplash (
		const sf::Font&,
		screenelements&
	);
	void addPageAdjust (
		const sf::Font&,
		screenelements&
	);
	void addPageAccredit (
		const sf::Font&,
		screenelements&
	);
	void addPageNewGame (
		const bool&,
		const bool&,
		const std::string&,
		const sf::Font&,
		screenelements&
	);
	enum class screenelement_rectangle_enum {
		BgButtonsPageSwitching,
		BgScreenMajority,
	};
	typedef screenelement_rectangle::screenelement_rectangle <screenelement_rectangle_enum> screenelement_rectangle;
	class screenelement_rectangle_bg_buttons_page_switching : public screenelement_rectangle {
		public: screenelement_rectangle_enum screenelement_rectangle_enum_ (
		) const;
		public: screenelement_rectangle_bg_buttons_page_switching (
		);
	};
	class screenelement_rectangle_bg_screen_majority : public screenelement_rectangle {
		public: screenelement_rectangle_enum screenelement_rectangle_enum_ (
		) const;
		public: screenelement_rectangle_bg_screen_majority (
		);
	};
	enum class screenelement_label_enum {
		Title,
		TitleShadow,
		HeaderWelcome,
		HeaderOptions,
		HeaderCredits,
		ParagraphCredits,
		HeaderNewGame,
		HeaderNewQuickGameIfPlayClicked,
		HeaderName,
		HeaderNewAdventureIfPlayClicked,
	};
	typedef screenelement_label::screenelement_label <screenelement_label_enum> screenelement_label;
	class screenelement_label_generic : public screenelement_label {
		private: screenelement_label_enum m_screenelement_label_enum;
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_generic (
			const sf::Font&,
			const screenelement_label_enum&
		);
	};
	class screenelement_label_title_shadow : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_title_shadow (
			const sf::Font&
		);
	};
	enum class screenelement_button_enum {
		Exit,
		Adjust,
		Accredit,
		Play,
		NewGame,
		Save,
		Load,
		Review,
		NewQuickGame,
		NewAdventure,
		NewGameReturn,
		NewAdventureName,
	};
	typedef screenelement_button::screenelement_button <screenelement_button_enum> screenelement_button;
	class screenelement_button_page_switching : public screenelement_button {
		private: screenelement_button_enum m_screenelement_button_enum;
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_page_switching (
			const sf::Font&,
			const std::string&,
			const screenelement_button_enum&
		);
	};
	class screenelement_button_generic : public screenelement_button {
		private: screenelement_button_enum m_screenelement_button_enum;
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_generic (
			const sf::Font&,
			const std::string&,
			const screenelement_button_enum&
		);
	};
}
#endif