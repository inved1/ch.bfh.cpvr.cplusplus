/*/////////////////////////////////////////////////////////////////////////////
module:  declaration of GLUT utility class
purpose: implements general utilities for OpenGL/GLUT/OS support

written: U.Kuenzler
version: 1.01
/////////////////////////////////////////////////////////////////////////////*/



// system includes ////////////////////////////////////////////////////////////
#include <string>



class CUtilGlut
///////////////////////////////////////////////////////////////////////////////
{
public:
	static bool getFilePath(std::string& filepath,
		const std::string& filter = "All Files (*.*)\n*.*\n\0",
		const std::string& startdir = "" , bool open = true);

	static void showFPS(const std::string& title = "");
	static void showErrorCode(void);
	static void showMessageBox(
		const std::string& msg,
		const std::string& title = "Error Message");
};
// class CUtilGlut ////////////////////////////////////////////////////////////