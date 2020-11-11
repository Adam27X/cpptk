#include "cpptk.h"
#include <stdio.h>
#include <iostream>

int main(int, char *argv[])
{
	Tk::init(argv[0]);

	//First tutorial
	/*Tk::button(".b") -text("Hello World");
	Tk::grid(Tk::configure,".b");*/

	Tk::wm(Tk::title, ".", "Feet to meters"); //Change the title of the main window
	Tk::frame(".c") -Tk::padx(3) -Tk::pady(12); //FIXME: How to support padding("3 3 12 12")?
	Tk::grid(Tk::configure, ".c") -Tk::column(3) -Tk::row(2) -Tk::sticky("nsew");
	Tk::grid(Tk::columnconfigure, ".", 0) -Tk::weight(1);
	Tk::grid(Tk::rowconfigure, ".", 0) -Tk::weight(1);

	double feet;
	Tk::entry(".c.feet") -Tk::width(7) -Tk::textvariable(feet);
	Tk::grid(Tk::configure, ".c.feet") -Tk::column(2) -Tk::row(1) -Tk::sticky("we");

	double meters;
	Tk::label(".c.meters") -Tk::textvariable(meters);
	Tk::grid(Tk::configure, ".c.meters") -Tk::column(2) -Tk::row(2) -Tk::sticky("we");
	std::function<void()> calculate = [&] { meters = 0.3048*feet; };
	Tk::button(".c.calc") -Tk::text("Calculate") -Tk::command(calculate);
	Tk::grid(Tk::configure, ".c.calc") -Tk::column(3) -Tk::row(3) -Tk::sticky("w");

	Tk::label(".c.flbl") -Tk::text("feet");
	Tk::label(".c.islbl") -Tk::text("is equivalent to");
	Tk::label(".c.mlbl") -Tk::text("meters");
	Tk::grid(Tk::configure, ".c.flbl") -Tk::column(3) -Tk::row(1) -Tk::sticky("w");
	Tk::grid(Tk::configure, ".c.islbl") -Tk::column(1) -Tk::row(2) -Tk::sticky("e");
	Tk::grid(Tk::configure, ".c.mlbl") -Tk::column(3) -Tk::row(2) -Tk::sticky("w");

	Tk::grid(Tk::configure, Tk::winfo(Tk::children, ".c")) - Tk::padx(5) -Tk::pady(5);
	Tk::focus(".c.feet");
	Tk::bind(".", "<Return>", calculate);

     	Tk::runEventLoop();
}

