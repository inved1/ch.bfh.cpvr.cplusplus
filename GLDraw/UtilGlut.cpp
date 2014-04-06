/*/////////////////////////////////////////////////////////////////////////////
module:  implementation of GLUT utility class
purpose: implements general utilities for OpenGL/GLUT/OS support

written: U.Kuenzler
version: 1.03
version: 1.02 - added Tk GUI support for Mac
version: 1.01
history: 1.00 - initial version of OpenGL drawing application
/////////////////////////////////////////////////////////////////////////////*/




// system includes ////////////////////////////////////////////////////////////
#ifdef WIN32
#include <windows.h>
#pragma warning(disable : 4996)  // disable MS VC2005 "deprecated" warnings
#endif // WIN32

#if defined(__APPLE__) && defined(__MACH__)
    #include <GLUT/glut.h>
    #include <fstream>
#else
	#include <GL/glut.h>
#endif
#include <iostream>

#include "UtilGlut.h"
using namespace std;




bool CUtilGlut::getFilePath(string& filepath, 
	const string& filter, const string& initial, bool open)
///////////////////////////////////////////////////////////////////////////////
{
	bool result = false;

#ifdef __APPLE__
    std::string initial_;
        initial.length() == 0 ? initial_ += "~" : initial_ = initial;
    
    // the script's content (filter not yet implemented)
    std::string tk;
    if ( true == open ) 
    {
        // 'puts $var' is the return value printed to stdout and grabbed by the pipe
        tk += "package require Tk ;\
               wm iconify . ;\
               set filename [ tk_getOpenFile -parent . -initialdir " + initial_ + " ] ;\
               puts $filename ;\
               exit";
    }
    else
    {
        tk += "package require Tk ;\
               wm iconify . ;\
               set filename [ tk_getSaveFile -parent . -initialdir " + initial_ + " ] ;\
               puts $filename ;\
               exit";
    }
    
    // write the script to file
    std::ofstream scriptFile;
    scriptFile.open("mac.tcl", std::ios::out);
    scriptFile << tk;
    scriptFile.close();
    
    // get current location...
    const char * pwd = "echo $PWD";
    FILE* pwd_pipe = popen(pwd, "r");
    if (!pwd_pipe) return result;
    char pwd_buffer[512];
    std::string wd = "";
    while(!feof(pwd_pipe)) {
        if(fgets(pwd_buffer, 512, pwd_pipe) != NULL)
            wd += pwd_buffer;
    }
    pclose(pwd_pipe);
    
    // ...and create callable path
    wd.erase(wd.length() - 1, 1);
    std::string path = wd + "/mac.tcl";
    std::string scriptCall = "tclsh " + path;
    
    // execute script and get its result
    FILE* script_pipe = popen(scriptCall.c_str(), "r");
    if (!script_pipe) return result;
    char script_buffer[512];
    while(!feof(script_pipe)) {
        if(fgets(script_buffer, 512, script_pipe) != NULL)
            filepath += script_buffer;
    }
    pclose(script_pipe);
    
    // delete script file
    std::string rm_cmd = "rm " + path;
    system(rm_cmd.c_str());
    
    // get rid of the last newline char
    int pos = filepath.rfind("\n");
    filepath.erase(pos);
    
    result = true;
    return result;  
#endif // __APPLE__
    
#ifdef WIN32
#ifdef _UNICODE
	// WIN32 requires wchar_t type strings, so you need to convert all std::strings
	// (see VS2005 project settings for character set --> can be _UNICODE or _MBCS)
	// std::cout << "DEBUG: UtilGlut::getFilePath() (_UNICODE Version)" << std::endl;
	wstring wstr_initial = wstring(initial.begin(), initial.end());
	wstring wstr_filter = wstring(filter.begin(), filter.end());

	// replace custom filter string separator L'\n' with L'\0' required by the OFN structure
	for (unsigned int i=0; i<wstr_filter.size(); i++)
	{
		if (wstr_filter[i] == L'\n') wstr_filter[i] = L'\0';
	}

	// initialize Win32 OPENFILENAME structure file open common dialog box
	OPENFILENAME ofn;					// windows common dialog struct
	wchar_t pathbuffer[260];			// buffer for file path (needs to be of wide char type)
	ZeroMemory(&ofn, sizeof(ofn));		// clear memory
	ofn.lStructSize = sizeof(ofn);		// determine size of common dialog struct
	ofn.hwndOwner = NULL;				// handle of parent window
	ofn.lpstrFile = pathbuffer;			// buffer for file path
	ofn.nMaxFile = sizeof(pathbuffer);	// determine size of file path buffer
	ofn.lpstrFile[0] = L'\0';			// init with '\0' (wchar_t) so it is not used for initialization
	ofn.nFilterIndex = 1;				// index of the currently selected file filter control
	ofn.lpstrFileTitle = NULL;			// buffer that receives the file name and extension (without path)
	ofn.nMaxFileTitle = 0;				// size of the buffer pointed to by lpstrFileTitle
	ofn.lpstrDefExt = L"DAT";			// buffer containing default extension if non is user supplied

	// a set of bit flags, which can be used to initialize the dialog box
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

	// buffer containing pairs of null-terminated filter strings (terminated by two NULL characters)
	ofn.lpstrFilter = wstr_filter.c_str();

	// NULL terminated string that can specify the initial directory
	ofn.lpstrInitialDir = wstr_initial.c_str();

	// display the Open dialog box and get file path or return false otherwise
	if (open)
	{
		if ( GetOpenFileName(&ofn) )
		{
			// get open file path system call successful, set result
			result = true;

			// convert from wchar_t to wstring and string type (may not work for arbitrary UNICODE)
			wstring wstr_path(pathbuffer);
			filepath = string(wstr_path.begin(), wstr_path.end());

			// std::wcout << L"DEBUG: file path = '" << pathbuffer << L"' (wchar_t)" << std::endl;
			// std::cout << "DEBUG: file path = '" << filepath << "' (char)" << std::endl;
		}
	}
	else // save
	{
		if ( GetSaveFileName(&ofn) )
		{
			// get save file path system call successful, set result
			result = true;

			// convert from wchar_t to wstring and string type (may not work for arbitrary UNICODE)
			wstring wstr_path(pathbuffer);
			filepath = string(wstr_path.begin(), wstr_path.end());

			// std::wcout << L"DEBUG: file path = '" << pathbuffer << L"' (wchar_t)" << std::endl;
			// std::cout << "DEBUG: file path = '" << filepath << "' (char)" << std::endl;
		}
	}

#else // NOT _UNICODE
	// VS2005 can be configured for non _UNICODE version (i.e. _MBCS characters)
	// std::cout << "DEBUG: UtilGlut::getFilePath() (_MBCS Version)" << std::endl;

	// replace custom filter string separator '\n' with '\0' required by the OFN structure
	string str_filter = filter;
	for (unsigned int i=0; i<filter.size(); i++)
	{
		if (str_filter[i] == '\n') str_filter[i] = '\0';
	}

	// initialize Win32 OPENFILENAME structure file open common dialog box
	OPENFILENAME ofn;					// windows common dialog struct
	char pathbuffer[260];				// buffer for file path (needs to be of wide char type)
	ZeroMemory(&ofn, sizeof(ofn));		// clear memory
	ofn.lStructSize = sizeof(ofn);		// determine size of common dialog struct
	ofn.hwndOwner = NULL;				// handle of parent window
	ofn.lpstrFile = pathbuffer;			// buffer for file path
	ofn.nMaxFile = sizeof(pathbuffer);	// determine size of file path buffer
	ofn.lpstrFile[0] = '\0';			// init with '\0' (wchar_t) so it is not used for initialization
	ofn.nFilterIndex = 1;				// index of the currently selected file filter control
	ofn.lpstrFileTitle = NULL;			// buffer that receives the file name and extension (without path)
	ofn.nMaxFileTitle = 0;				// size of the buffer pointed to by lpstrFileTitle
	ofn.lpstrDefExt = "DAT";			// buffer containing default extension if non is user supplied

	// a set of bit flags, which can be used to initialize the dialog box
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

	// buffer containing pairs of null-terminated filter strings (terminated by two NULL characters)
	ofn.lpstrFilter = str_filter.c_str();

	// NULL terminated string that can specify the initial directory
	ofn.lpstrInitialDir = initial.c_str();

	// display the Open dialog box and get file path or return false otherwise
	if (open)
	{
		if ( GetOpenFileName(&ofn) )
		{
			// get open file path system call successful, set result
			result = true;

			// convert from wchar_t to wstring and string type (may not work for arbitrary unicode)
			filepath = string(pathbuffer);

			// std::cout << "DEBUG: file path = '" << filepath << "' (char)" << std::endl;
		}
	}
	else // save
	{
		if ( GetSaveFileName(&ofn) )
		{
			// get save file path system call successful, set result
			result = true;

			// convert from wchar_t to wstring and string type (may not work for arbitrary unicode)
			filepath = string(pathbuffer);

			// std::cout << "DEBUG: file path = '" << filepath << "' (char)" << std::endl;
		}
	}
#endif // NOT _UNICODE
#else // NOT WIN32
	// use hard coded filename in current directory
	result = true;
	filepath = "testfile01.drw";
#endif // WIN32

	return result;
}
// UtilGlut::getFilePath() ////////////////////////////////////////////////////




void CUtilGlut::showErrorCode(void)
///////////////////////////////////////////////////////////////////////////////
{
	GLenum errCode;
	const GLubyte *errString;

	if ((errCode = glGetError()) != GL_NO_ERROR)
	{
		errString = gluErrorString(errCode);
		std::cout << "OpenGL Error Code: " << errCode << " (" << errString << ")" << std::endl;
	}
}
// end: UtilGlut::showErrorCode() /////////////////////////////////////////////




void CUtilGlut::showFPS(const string& title)
///////////////////////////////////////////////////////////////////////////////
{
	// replace current GLUT window title with FPS string ("append" can 
	// not be implemented, because there is no GLUT function to get the 
	// current window title.)

	// calculate frames per second (FPS)
	static int frame = 0;
	static int time = 0;
	static int timebase = 0;
	static char str[128];

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000)
	{
		sprintf(str,"%s ( FPS: %4.2f )", title.c_str(), frame*1000.0/(time-timebase));
		glutSetWindowTitle(str);
		timebase = time;
		frame = 0;
	}
}
// end: UtilGlut::showFPS() ///////////////////////////////////////////////////


void CUtilGlut::showMessageBox( const string& msg, const string& title)
///////////////////////////////////////////////////////////////////////////////
{
#ifdef __APPLE__
    // the script's content (icon hard coded)
    std::string tk;
        tk += "package require Tk ;\
               wm iconify . ;\
               tk_messageBox -message \"" + msg + "\" -title \"" + title + "\" -icon warning -parent . ;\
               exit";
    
    // write the script to file
    std::ofstream scriptFile;
    scriptFile.open("mac.tcl", std::ios::out);
    scriptFile << tk;
    scriptFile.close();
    
    // get current location...
    const char * pwd = "echo $PWD";
    FILE* pwd_pipe = popen(pwd, "r");
    if (!pwd_pipe) 
    {
        std::cout << "ERROR: creating message pipe";
    }
    char pwd_buffer[512];
    std::string wd = "";
    while(!feof(pwd_pipe)) {
        if(fgets(pwd_buffer, 512, pwd_pipe) != NULL)
            wd += pwd_buffer;
    }
    pclose(pwd_pipe);
    
    // ...and create callable path
    wd.erase(wd.length() - 1, 1);
    std::string path = wd + "/mac.tcl";
    std::string scriptCall = "tclsh " + path;
    
    // execute script
    FILE* script_pipe = popen(scriptCall.c_str(), "r");
    if (!script_pipe)
    {
        std::cout << "ERROR: creating message pipe";
    }
    pclose(script_pipe);
    
    // delete script file
    std::string rm_cmd = "rm " + path;
    system(rm_cmd.c_str()); 
// end __APPLE__
#elif WIN32
	//MessageBox(0, msg.c_str(), title.c_str(), MB_OK);
// end WIN32
#else
	// do simple std console output
	cout << title.c_str() << ": " << msg.c_str() << endl;
#endif
}
// end: UtilGlut::showMessageBox() ////////////////////////////////////////////