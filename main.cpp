#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	int hour{0}, minute{0};
	std::string faceColour{"black"}, hourHandColour{"black"}, minuteHandColour{"black"};
	
	int gnuArgCount = 0;
	while(argv[gnuArgCount+1] && argv[gnuArgCount+1][0] == '-' && argv[gnuArgCount+1][1] == '-')
	{
		std::string gnuArg{&argv[gnuArgCount+1][2]};
		if(gnuArg.starts_with("colour="))
		{
			faceColour = hourHandColour = minuteHandColour = gnuArg.substr(std::string{"colour="}.length());
		}
		else if(gnuArg.starts_with("facecolour="))
		{
			faceColour = gnuArg.substr(std::string{"facecolour="}.length());
		}
		else if(gnuArg.starts_with("handcolour="))
		{
			hourHandColour = minuteHandColour = gnuArg.substr(std::string{"handcolour="}.length());
		}
		else if(gnuArg.starts_with("hourhandcolour="))
		{
			hourHandColour = gnuArg.substr(std::string{"hourhandcolour="}.length());
		}
		else if(gnuArg.starts_with("minutehandcolour="))
		{
			minuteHandColour = gnuArg.substr(std::string{"minutehandcolour="}.length());
		}
		++gnuArgCount;
	}
	if(argc>gnuArgCount+1)
	{
		hour = std::stoi(argv[gnuArgCount + 1]);
	}
	if(argc>gnuArgCount+2)
	{
		minute = std::stoi(argv[gnuArgCount + 2]);
	}
	
	hour %= 12;
	
	// https://commons.wikimedia.org/wiki/File:Clock_12-27.svg
	// https://commons.wikimedia.org/wiki/User:Jahobr
	std::cout
		<< "<?xml version='1.0' encoding='UTF-8'?>" << std::endl
		<< "<svg xmlns:xlink='http://www.w3.org/1999/xlink' xmlns:svg='http://www.w3.org/2000/svg' xmlns='http://www.w3.org/2000/svg' width='500' height='500' viewBox='-100 -100 200 200'>" << std::endl
		<< "<defs>"
			<< "<circle cx='0' cy='87' r='2.2' fill='" << faceColour << "' id='minMarker'/>"
			<< "<line x1='0' y1='95' x2='0' y2='78' stroke-width='3.8' stroke='" << faceColour << "' id='hourMarker'/>"
		<< "</defs>" << std::endl
		<< "<g id='markerSet'>"
			<< "<use xlink:href='#hourMarker'/>"
			<< "<use xlink:href='#minMarker' transform='rotate( 6)'/>"
			<< "<use xlink:href='#minMarker' transform='rotate(12)'/>"
			<< "<use xlink:href='#minMarker' transform='rotate(18)'/>"
			<< "<use xlink:href='#minMarker' transform='rotate(24)'/>"
		<< "</g>" << std::endl;
	for(int degree=30; degree<=330; degree+=30)
	{
		std::cout << "<use xlink:href='#markerSet' transform='rotate(" << degree << ")'/>" << std::endl;
	}
	
	std::cout << "<line x1='0' y1='-62' x2='0' y2='0' stroke-width='5' stroke='" << hourHandColour << "' transform='rotate(" << (hour + static_cast<float>(minute)/60) * (360/12) << ")'/>" << std::endl;
	std::cout << "<line x1='0' y1='-95' x2='0' y2='0' stroke-width='2.8' stroke='" << minuteHandColour << "' transform='rotate(" << minute * (360/60) << ")'/>" << std::endl;
	
	std::cout << "<circle cx='0' cy='0' r='9' fill='" << faceColour << "'/>" << std::endl;
	
	std::cout << "</svg>" << std::endl;
}
