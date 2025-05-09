#pragma once
#include "UIService/UIElement/ImageView.h"
#include <functional>

namespace UI
{
	namespace UIElement
	{
		enum class AnimationType
		{
			FADE_IN,
			FADE_OUT,
		};

		class AnimatedImageView : public ImageView
		{
		private :
			using CallbackFuntion = std::function<void()>;

			CallbackFuntion callback_function = nullptr;

			void updateElapsedDuration();
			void handleAnimationProgress();
			void updateAnimation();

		protected :
			const float default_animation_duration = 2.0f;

			AnimationType animation_type;
			float animation_duration;
			float elapsed_duration;
			sf::Clock clock;

			virtual void reset();
			void setAnimationDuration(float duration);
			void setAnimationType(AnimationType type);

			virtual void fadeIn();
			virtual void fadeOut();

		public :
			AnimatedImageView();
			virtual ~AnimatedImageView();

			virtual void initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position) override ;
			virtual void update() override;
			virtual void render() override;

			virtual void playAnimation(AnimationType type, float duration, CallbackFuntion animation_end_callback);

			void registerCallbackFunction(CallbackFuntion animation_end_callback);
		};
	}
}