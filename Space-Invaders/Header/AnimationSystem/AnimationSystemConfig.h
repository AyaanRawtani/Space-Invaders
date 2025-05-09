#pragma once
#include <SFML/Graphics.hpp>

namespace Animation
{
	struct AnimationSystemConfig
	{
		sf::String Animation_texture_path;

		float sprite_sheet_height;
		float sprite_sheet_width;

		float tile_width;
		float tile_height;

		int number_of_animation_frames; 
		float frame_duration; 

		AnimationSystemConfig() = default; 

		
		AnimationSystemConfig(sf::String texture_path, float sprite_width, float sprite_height, float t_width, float t_height, int frames, float duration) :
			Animation_texture_path(texture_path),
			sprite_sheet_width(sprite_width),
			sprite_sheet_height(sprite_height),
			tile_width(t_width),
			tile_height(t_height),
			number_of_animation_frames(frames),
			frame_duration(duration) {}
	};
}