// #include "elements/header.hpp"
// #include "layers.hpp"

#include <cstdio>
// #include <thread>
// #include <unistd.h>
#include <sys/ioctl.h>


#include "terminal.hpp"
#include "layers.hpp"
// #include "engine/screen.hpp"

int main(int argc, char *argv[])
{
	bool nopause = false;

	for (int i = 0; i < argc; i++)  {
		if (argv[i] == static_cast<std::string>("--no-pause"))
			nopause = true;
	}

	Terminal terminal = Terminal();
	std::shared_ptr<Terminal> term = std::make_shared<Terminal>(terminal);
	std::weak_ptr term_w = term;

	uint16_t * const tX = &terminal.size.ws_col, *tY = &terminal.size.ws_row;

	Layers l;
	auto layers = std::make_shared<Layers>(l);

	u16 *cl_x     = static_cast<u16*>(calloc(1, sizeof(u16))),
		*cl_max_x = static_cast<u16*>(calloc(1, sizeof(u16)));

	*cl_x = 5, *cl_max_x = 1000;
	Clamp cl(Vec2(cl_x, tY),    Percentage( 20, 100, tX, tY),       Vec2(cl_max_x, tY)),
	      cr(Vec2(5, 2), 		Percentage(-20, 0,   tX, tY),       Vec2(1000, 1)),
		  cs(Vec2(5, 2), 		Percentage( 20, 0,   tX, tY, true), Vec2(100, 1));


	Element background(Vec2(), 							 Percentage(100, 100, tX, tY),  RGB(0, 0, 0),    RGB(255, 255, 255)),
			panel_left(Vec2(), 							 cl,                            RGB(20, 20, 20), RGB(255, 255, 255)),
		   panel_right(cr,      						 cl,							RGB(20, 20, 20), RGB(255, 255, 255)),
			    status(Vec2(), 		    				 cs,							RGB(0, 190, 80), RGB(255, 255, 255)),
		   status_text(fVec2(0.5f, 1.0f, true).ToVec2(), cs,							RGB(0, 190, 80), RGB(255, 255, 255), "Online");

	status.children.push_back(status_text);

	std::vector elements = {
		background,
		panel_right,
		panel_left,
		status
	};

	layers->Add(elements);


	std::string cmd;
	WindowSize ws(terminal.size);

	print(Ansi::Clear);
	layers->Print(term_w);

	while (true)
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal.size);

		if (terminal.size.ws_col == ws.ws_col && terminal.size.ws_row == ws.ws_row)
			continue;

		if (nopause == false)
			sleep(1);

		print(Ansi::Clear);
		layers->Print(term_w);
		std::println();
		ws = terminal.size;
	}

	return 0;
}
