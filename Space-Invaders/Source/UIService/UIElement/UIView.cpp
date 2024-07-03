#include "../../Header/UIService/UIElement/UIView.h"
#include "Global/ServiceLocator.h"
#include "Graphic/GraphicService.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;
		using namespace Graphic;

		UIView::UIView() = default;

		UIView::~UIView() = default;

		void UIView::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			ui_state = UIState::VISIBLE;
		}

		void UIView::update()
		{
		}

		void UIView::render()
		{
		}

		void UIView::show()
		{
			ui_state = UIState::VISIBLE;
		}

		void UIView::hide()
		{
			ui_state = UIState::HIDDEN;
		}


	}
}