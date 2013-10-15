/*	Author: Frank Dye
	Date: 9/25/13
	Copyright: Frank Dye, 9/25/2013
	Description: A simple RegExp tester to help with setting up the correct RegExp constants
*/

#include <iostream>
#include <fstream>
#include <regex>
#include <tchar.h>

#include "OBJRegExp.h"
#include "GeometryElements.h"
#include "CGeometryImporterOBJ.h"
#include <direct.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char        szTempFileName[1024];
	string a;

	//Open the File
	_getcwd(szTempFileName, 1024);
	strcat_s(szTempFileName, "\\Obj\\");
	strcat_s(szTempFileName, "gsg9.obj");

	ifstream inFile(szTempFileName);

	CGeometryImporterOBJ geoImporter(&inFile);

	cout << "File details: \n";
	cout << "Vertex Count: " << geoImporter.GetVertexCount() << "\n";
	cout << "Normal Count: " << geoImporter.GetNormalVertexCount() << "\n";
	cout << "Vertex Texture Count: " << geoImporter.GetTextureVertexCount() << "\n";
	cout << "Face Count: " << geoImporter.GetFaceCount() << "\n";
	cout << "Error Count: " << geoImporter.GetErrorCount() << "\n";


	//Just here to keep the console window open. Hookey but works.
	std::cin >> a;

	return 0;
}



