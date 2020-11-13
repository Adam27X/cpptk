#include "cpptk.h"
#include <stdio.h>
#include <iostream>

int main(int, char *argv[])
{
	Tk::init(argv[0]);

	//First tutorial
	/*Tk::button(".b") -text("Hello World");
	Tk::grid(Tk::configure,".b");*/

	//Second tutorial
	/*Tk::wm(Tk::title, ".", "Feet to meters"); //Change the title of the main window
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
	Tk::bind(".", "<Return>", calculate);*/

	//Configuration options
	/*std::function<void()> button_pressed = [] {};
	Tk::button(".b") -Tk::text("Hello") -Tk::command(button_pressed);

	std::string button_text(".b" << Tk::cget(Tk::text));
	std::string command(".b" << Tk::cget(Tk::command));
	std::cout << "Button text: " << button_text << "\n";
	std::cout << "Button cmd: " << command << "\n";
	".b" << Tk::configure() -Tk::text("Goodbye");
	button_text = std::string(".b" << Tk::cget(Tk::text));
	std::cout << "Button text: " << button_text << "\n";*/

	//Binding to events
	/*Tk::label(".l") -Tk::text("Starting...");
	Tk::grid(Tk::configure, ".l");
	Tk::bind(".l", "<Enter>", [] () { ".l" << Tk::configure() -Tk::text("Moved mouse inside"); });
	Tk::bind(".l", "<Leave>", [] () { ".l" << Tk::configure() -Tk::text("Moved mouse outside"); }); 
	Tk::bind(".l", "<ButtonPress-1>", [] () { ".l" << Tk::configure() -Tk::text("Clicked left mouse button"); }); 
	Tk::bind(".l", "<3>", [] () { ".l" << Tk::configure() -Tk::text("Clicked right mouse button"); }); 
	Tk::bind(".l", "<Double-1>", [] () { ".l" << Tk::configure() -Tk::text("Double clicked left mouse button"); });
	Tk::bind(".l", "<B3-Motion>", [] (int x, int y) { std::stringstream msg; msg << "Right button drag to " << x << " " << y; ".l" << Tk::configure() -Tk::text(msg.str()); }, Tk::event_x, Tk::event_y);*/

	//Validation of entries
	/*std::string zip;
	Tk::entry(".e") -Tk::textvariable(zip) -Tk::validate(Tk::key) -Tk::validatecommand([] (const std::string &n) { return std::all_of(n.begin(),n.end(),::isdigit) && n.size() <= 5; }, Tk::valid_P);
	Tk::grid(Tk::configure, ".e") -Tk::column(0) -Tk::row(0) -Tk::sticky("we");*/

	//Advanced validation example
	/*Tk::frame(".f");
	Tk::grid(Tk::configure, ".f") -Tk::column(0) -Tk::row(0);
	Tk::label(".f.l1") -Tk::text("Name:");
	Tk::grid(Tk::configure, ".f.l1") -Tk::column(0) -Tk::row(0) -Tk::padx(5) -Tk::pady(5);
	Tk::entry(".f.e1");
	Tk::grid(Tk::configure, ".f.e1") -Tk::column(1) -Tk::row(0) -Tk::padx(5) -Tk::pady(5);
	Tk::label(".f.l") -Tk::text("Zip:");
	Tk::grid(Tk::configure, ".f.l") -Tk::column(0) -Tk::row(1) -Tk::padx(5) -Tk::pady(5);

	std::string zip;
	std::string errmsg;
	auto callback = [&errmsg] (const std::string &newval, const std::string &op)
	{
		errmsg = std::string("");
		bool valid = false;
		std::string first_zip;
		if(newval.size() >= 5)
		{
			first_zip = std::string(newval.begin(),newval.begin()+5);
		}
		else
		{
			valid = false;
		}
		if(newval.size() == 5 && std::all_of(first_zip.begin(),first_zip.end(),::isdigit))
		{
			valid = true;
		}
		std::string second_zip;
		if(newval.size() == 10)
		{
			second_zip = std::string(newval.begin()+6,newval.end());
			if(std::all_of(first_zip.begin(),first_zip.end(),::isdigit) && std::all_of(second_zip.begin(),second_zip.end(),::isdigit) && newval[5] == '-')
			{
				valid = true;
			}
		}

		if(valid)
		{
			".f.btn" << Tk::configure() -Tk::state(Tk::normal);
		}
		else
		{
			".f.btn" << Tk::configure() -Tk::state(Tk::disabled);
		}

		if(op.compare("key") == 0)
		{
			//Check if valid so far
			bool ok_so_far = false;
			if(newval.size() <= 10)
			{
				if(std::all_of(newval.begin(),newval.end(),[] (char c) { if((c >= '0' && c <= '9') || c == '-') return true; return false; }))
				{
					ok_so_far = true;
				}
			}

			if(!ok_so_far)
			{
				errmsg = "Zip should be ##### or #####-####";
			}
			return ok_so_far;
		}
		else if(op.compare("focusout") == 0)
		{
			//Send error if not valid
			if(!valid)
			{
				errmsg = "Zip should be ##### or #####-####";
			}
		}

		return valid;
	};

	Tk::entry(".f.e") -Tk::textvariable(zip) -Tk::validate(Tk::all) -Tk::validatecommand(callback, Tk::valid_P, Tk::valid_V);
	Tk::grid(Tk::configure,".f.e") -Tk::column(1) -Tk::row(1) -Tk::padx(5) -Tk::pady(5);
	Tk::button(".f.btn") -Tk::text("Process");
	Tk::grid(Tk::configure, ".f.btn") -Tk::column(2) -Tk::row(1) -Tk::padx(5) -Tk::pady(5);
	".f.btn" << Tk::configure() -Tk::state(Tk::disabled);
	Tk::label(".f.msg") -Tk::font("SmallCaptionFont") -Tk::foreground("red") -Tk::textvariable(errmsg);
	Tk::grid(Tk::configure, ".f.msg") -Tk::column(1) -Tk::row(2) -Tk::padx(5) -Tk::pady(5) -Tk::sticky("w");*/

     	Tk::runEventLoop();
}

