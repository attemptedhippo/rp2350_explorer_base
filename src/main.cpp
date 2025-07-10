#include <cmath>
#include <cstdint>
#include "pico/stdlib.h"
#include "drivers/st7789/st7789.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"


using namespace pimoroni;

const int width{320};
const int height{240};

// void* frame_buf = new uint8_t[width * height]{0};

ST7789 st7789(width, height, ROTATE_0, {27, 28, 30, 31, 32, 26});
// PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);
PicoGraphics_PenRGB565 graphics(st7789.width, st7789.height, nullptr); // frame_buf, 1);

int main()
{
	stdio_init_all();

	RGB565 image[width * height];

	for (int y{0}; y < height; y++)
	{
		for (int x{0}; x < width; x++)
		{
			float r = static_cast<float>(x / (width - 1.0));
			float g = static_cast<float>(y / (height - 1.0));
			image[y * width + x] = PicoGraphics::rgb_to_rgb565(
							(uint8_t)std::round(r * 255),
							(uint8_t)std::round(g * 255),
							(uint8_t)0.0);
		}
	}
	
	RGB565 clear_color{PicoGraphics::rgb_to_rgb565(0, 120, 150)};
	RGB565 ball_color{PicoGraphics::rgb_to_rgb565(0, 0, 255)};
	while (true)
	{
		graphics.set_pen(clear_color);
		graphics.clear();

		//Draw your stuff below:
		
		for (int y{0}; y < height ; y++)
		{
			for (int x{0}; x < width; x++)
			{
				graphics.set_pen(image[y * width + x]);
				graphics.set_pixel(Point(x , y));
			}
		}
		
		graphics.set_pen(ball_color);
		graphics.circle(Point(20, 20), 20);
		st7789.update(&graphics);
	}
}
