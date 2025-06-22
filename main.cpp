#include "pico/stdlib.h"
#include "drivers/st7789/st7789.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include <cstdint>

using namespace pimoroni;

ST7789 st7789(320, 240, ROTATE_0, {27, 28, 30, 31, 32, 26});
PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);

struct G_Block {
	Point top_left		= {0, 0};
	Point bottom_right	= {0, 0};
};

struct G_Ball {
	Point center	= {0, 0};
	uint32_t rad	= {0};
};

int main()
{
	stdio_init_all();
	
	G_Ball ball = {Point{320/2, 240/2}, 5};
	Point  ball_vel = {10, 10};

	while(true)
	{
		//Update your logic below:
		if((ball.center.x - ball.rad + ball_vel.x  <= 0) or (ball.center.x + ball.rad + ball_vel.x >= 320))
		{
			ball_vel.x = -ball_vel.x;
		}
		if((ball.center.y - ball.rad + ball_vel.y  <= 0) or (ball.center.y + ball.rad + ball_vel.y >= 240))
		{
			ball_vel.y = -ball_vel.y;
		}

		ball.center += ball_vel;

		graphics.set_pen(30, 30, 90);
		graphics.clear();
		graphics.set_pen(110, 120, 130);
		graphics.text("HELLO EXPLORER!", Point(20, 200), 200);

		//Draw your stuff below:
		graphics.set_pen(255, 0, 0);
		graphics.circle(ball.center, ball.rad);

		st7789.update(&graphics);
	}
}
