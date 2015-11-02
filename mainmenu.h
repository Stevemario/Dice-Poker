#ifndef MAINMENU_H
#define MAINMENU_H
#include "gamedata.h"
#include "screenelement.h"
#include "gameaction.h"
#include "mainmenupage.h"
namespace menu_main {
	void work (
		int&,
		bool&,
		bool&,
		bool&,
		bool&,
		std::vector <screenelement*>&,
		const sf::Font&,
		sf::RenderWindow&,
		gameaction&,
		mainmenupage&,
		gamedata*
	);
	void prepare (
		const bool&,
		const bool&,
		std::vector <screenelement*>&,
		const sf::Font&,
		mainmenupage&,
		gamedata*
	);
	void handle (
		int&,
		bool&,
		bool&,
		bool&,
		const std::vector <screenelement*>&,
		gameaction&,
		mainmenupage&,
		gamedata*,
		const sf::Event&,
		bool&
	);
	void addButtonsPageSwitching (
		std::vector <screenelement*>&,
		const sf::Font&
	);
	void addPageSplash (
		std::vector <screenelement*>&,
		const sf::Font&
	);
	void addPageAdjust (
		std::vector <screenelement*>&,
		const sf::Font&
	);
	void addPageAccredit (
		std::vector <screenelement*>&,
		const sf::Font&
	);
	void addPageNewGame (
		const bool&,
		std::vector <screenelement*>&,
		const sf::Font&
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
		HeaderClickPlay,
		HeaderName,
	};
	typedef screenelement_label::screenelement_label <screenelement_label_enum> screenelement_label;
	class screenelement_label_title : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_title (
			const sf::Font&
		);
	};
	class screenelement_label_title_shadow : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_title_shadow (
			const sf::Font&
		);
	};
	class screenelement_label_header_welcome : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_welcome (
			const sf::Font&
		);
	};
	class screenelement_label_header_options : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_options (
			const sf::Font&
		);
	};
	class screenelement_label_header_credits : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_credits (
			const sf::Font&
		);
	};
	class screenelement_label_paragraph_credits : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_paragraph_credits (
			const sf::Font&
		);
	};
	class screenelement_label_header_new_game : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_new_game (
			const sf::Font&
		);
	};
	class screenelement_label_header_click_play : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_click_play (
			const sf::Font&
		);
	};
	class screenelement_label_header_name : public screenelement_label {
		public: screenelement_label_enum screenelement_label_enum_ (
		) const;
		public: screenelement_label_header_name (
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
	};
	typedef screenelement_button::screenelement_button <screenelement_button_enum> screenelement_button;
	class screenelement_button_exit : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_exit (
			const sf::Font&
		);
	};
	class screenelement_button_adjust : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_adjust (
			const sf::Font&
		);
	};
	class screenelement_button_accredit : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_accredit (
			const sf::Font&
		);
	};
	class screenelement_button_play : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_play (
			const sf::Font&
		);
	};
	class screenelement_button_new_game : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_new_game (
			const sf::Font&
		);
	};
	class screenelement_button_save : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_save (
			const sf::Font&
		);
	};
	class screenelement_button_load : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_load (
			const sf::Font&
		);
	};
	class screenelement_button_review : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_review (
			const sf::Font&
		);
	};
	class screenelement_button_new_quick_game : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_new_quick_game (
			const sf::Font&
		);
	};
	class screenelement_button_new_adventure : public screenelement_button {
		public: screenelement_button_enum screenelement_button_enum_ (
		) const;
		public: screenelement_button_new_adventure (
			const sf::Font&
		);
	};
	void handle (
		bool&,
		bool&,
		gameaction&,
		mainmenupage&,
		gamedata*,
		bool&,
		screenelement_button_enum
	);
}
#endif