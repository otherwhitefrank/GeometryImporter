/*	Author: Frank Dye
	Date: 10/2/1013
	Copyright: Frank Dye, 10/2/2013
	Description: This class handles the importing of an OBJ Geometry file. It is passed in an open valid ifstream handle and proceeds
				 to parse the file line by line storing each of the aspects of the Geometry file for retrieval. User is required to close
				 the ifstream handle outside the scope of the class. 
*/


#include "CGeometryImporterOBJ.h"

CGeometryImporterOBJ::CGeometryImporterOBJ()
{
	//Initially reset the object
	ResetObject();
}

CGeometryImporterOBJ::CGeometryImporterOBJ( ifstream* inputFile )
{
	//Initially reset the object
	ResetObject();

	//Set the file pointer internally
	pInputFile = inputFile;

	//Process the file
	ProcessFile();
}



CGeometryImporterOBJ::~CGeometryImporterOBJ()
{
	//Free all the buffers
	FreeAllBuffers();
}

bool CGeometryImporterOBJ::LoadFile( ifstream* inputFile )
{
	//Set the file pointer internally
	pInputFile = inputFile;

	//Process the file
	ProcessFile();
	return true;
}

list<Vector3D>* CGeometryImporterOBJ::GetVertexPosList()
{
	return pVectorPosList;
}

list<Vector3D>* CGeometryImporterOBJ::GetVertexNormalList()
{
	return pVectorNormalList;
}

list<Vector2D>* CGeometryImporterOBJ::GetVertexTextureList()
{
	return pVectorTextureList;
}

list<VectorPosNormText>* CGeometryImporterOBJ::GetVectorPosNormTextList()
{
	return pVectorPosNormTextList;
}

list<Mesh>* CGeometryImporterOBJ::GetMeshList()
{
	return pMeshList;
}

list<string>* CGeometryImporterOBJ::GetErrorList()
{
	return pErrorList;
}

void CGeometryImporterOBJ::CopyVectorPosNormTextList( list<VectorPosNormText>* destVectorPosNormTextList )
{
	for (auto it = std::begin(*pVectorPosNormTextList); it!=std::end(*pVectorPosNormTextList); ++it)
		destVectorPosNormTextList->push_back(*it);
}

void CGeometryImporterOBJ::CopyMeshList( list<Mesh>* destMeshList )
{
	for (auto it = std::begin(*pMeshList); it!=std::end(*pMeshList); ++it)
		destMeshList->push_back(*it);
}

void CGeometryImporterOBJ::CopyVertexPosList( list<Vector3D>* destVertexList )
{
	for (auto it = std::begin(*pVectorPosList); it!=std::end(*pVectorPosList); ++it)
		destVertexList->push_back(*it);

}

void CGeometryImporterOBJ::CopyVertexNormalList( list<Vector3D>* destVertexNormalList )
{
	for (auto it = std::begin(*pVectorNormalList); it!=std::end(*pVectorNormalList); ++it)
		destVertexNormalList->push_back(*it);
}

void CGeometryImporterOBJ::CopyVertexTextureList( list<Vector2D>* destVertexTextureList )
{
	for (auto it = std::begin(*pVectorTextureList); it!=std::end(*pVectorTextureList); ++it)
		destVertexTextureList->push_back(*it);
}

void CGeometryImporterOBJ::ProcessFile()
{
	string lineBuffer = "";
	int lineCount = 0;

	//ResetObject();

	//Create our list objects
	pErrorList = new list<string>;
	pMeshList = new list<Mesh>;
	pVectorNormalList  = new list<Vector3D>;
	pVectorPosList = new list<Vector3D>;
	pVectorPosNormTextList = new list<VectorPosNormText>;
	pVectorTextureList = new list<Vector2D>;

	for (lineBuffer = ""; std::getline(*pInputFile, lineBuffer) && !pInputFile->eof(); lineCount++)
	{
		//Process each line one at a time.
		smatch regexMatch;
		
		//Material Libraries
		if (regex_search(lineBuffer, regexMatch, OBJ_MTLLIB_EXP))
		{

		}
	

		//Vertex 
		else if (regex_search(lineBuffer, regexMatch, OBJ_VERTEX_EXP))
		{
			m_VertexPosCount++;
			std::cout << lineBuffer << std::endl;
		}
		
		//Vertex Texture
		else if (regex_search(lineBuffer, regexMatch, OBJ__TEXTURE_EXP))
		{
			m_VertexTextureCount++;
			string szX = regexMatch[1];
			string szY = regexMatch[2];
			Vector2D* tempVect2D = new Vector2D;
			tempVect2D->x = atof(szX.c_str());
			tempVect2D->y = atof(szY.c_str());
			std::cout << lineBuffer << std::endl;
		}

		//Vertex Normal
		else if (regex_search(lineBuffer, regexMatch, OBJ_VERTEX_NORMAL_EXP))
		{
			m_VertexNormalCount++;
			std::cout << lineBuffer << std::endl;
		}
		
		//Groups
		else if (regex_search(lineBuffer, regexMatch, OBJ_GROUP_EXP))
		{

		}

		//Object names
		else if (regex_search(lineBuffer, regexMatch, OBJ_OBJECT_EXP))
		{

		}

		//Use Material
		else if (regex_search(lineBuffer, regexMatch, OBJ_USEMTL_EXP))
		{

		}

		//Smooth Group
		else if (regex_search(lineBuffer, regexMatch, OBJ_SMOOTH_EXP))
		{

		}

		//Face Vertex-Texture Coordinate-Vector Normal
		else if (regex_search(lineBuffer, regexMatch, OBJ_FACE_VT_TC_VN_EXP))
		{
			m_FaceCount++;
			std::cout << lineBuffer << std::endl;
		}
		
		//Face Vertex Only
		else if (regex_search(lineBuffer, regexMatch, OBJ_FACE_VT_EXP))
		{
			m_FaceCount++;
			std::cout << lineBuffer << std::endl;
		}

		//Face Vertex-Texture Coordinate
		else if (regex_search(lineBuffer, regexMatch, OBJ_FACE_VT_TC_EXP))
		{
			m_FaceCount++;
			std::cout << lineBuffer << std::endl;
		}

		//Face Vertex-Vector Normal
		else if (regex_search(lineBuffer, regexMatch, OBJ_FACE_VT_VN_EXP))
		{
			m_FaceCount++;
			std::cout << lineBuffer << std::endl;
		}

		//Comment
		else if (regex_search(lineBuffer, regexMatch, OBJ_COMMENT_EXP))
		{

		}

		//Material File Definition

		//New Material
		else if (regex_search(lineBuffer, regexMatch, OBJ_NEWMTL_EXP))
		{

		}

		//Ambient Color
		else if (regex_search(lineBuffer, regexMatch, OBJ_AMBIENT_COLOR_EXP))
		{

		}
		
		//Diffuse Color
		else if (regex_search(lineBuffer, regexMatch, OBJ_DIFFUSE_COLOR_EXP))
		{

		}
		
		//Specular Color
		else if (regex_search(lineBuffer, regexMatch, OBJ_SPECULAR_COLOR_EXP))
		{

		}
		
		//Specular Coefficient
		else if (regex_search(lineBuffer, regexMatch, OBJ_SPECULAR_COEFF_COLOR_EXP))
		{

		}

		//Dissolve, same as transparency %
		else if (regex_search(lineBuffer, regexMatch, OBJ_DISSOLVE_EXP))
		{

		}

		//Transparency, also called Dissolve %
		else if (regex_search(lineBuffer, regexMatch, OBJ_TRANSPARENT_EXP))
		{

		}

		/*Illumination enumeration given as follows
		0. Color on and Ambient off
		1. Color on and Ambient on
		2. Highlight on
		3. Reflection on and Ray trace on
		4. Transparency: Glass on, Reflection: Ray trace on
		5. Reflection: Fresnel on and Ray trace on
		6. Transparency: Refraction on, Reflection: Fresnel off and Ray trace on
		7. Transparency: Refraction on, Reflection: Fresnel on and Ray trace on
		8. Reflection on and Ray trace off
		9. Transparency: Glass on, Reflection: Ray trace off
		10. Casts shadows onto invisible surfaces
		*/

		else if (regex_search(lineBuffer, regexMatch, OBJ_ILLUMINATION_EXP))
		{

		}

		//Catch all, reports lines that where not processed and line numbers
		else
		{
			string szTemp = lineCount + ": " + lineBuffer;
			pErrorList->push_back(szTemp);
		}

		
	}
}


void CGeometryImporterOBJ::ResetObject()
{
	//Reset all the counters
	m_MeshCount = 0;
	m_VertexPosCount = 0;
	m_VertexTextureCount = 0;
	m_VertexNormalCount = 0;
	m_FaceCount = 0;

	//We assume the user called FreeAllBuffers() before resetting the object if they plan on loading another file in
	//so just set points to null. User must watch memory leaks.

	pErrorList = nullptr;
	pMeshList = nullptr;
	pVectorNormalList  = nullptr;
	pVectorPosList = nullptr;
	pVectorPosNormTextList = nullptr;
	pVectorTextureList = nullptr;
}

void CGeometryImporterOBJ::FreeAllBuffers()
{
	//Wipe the geometry buffers, this is up to the user to perform to avoid memory leaks.
	if (pMeshList != nullptr)
		delete pMeshList;
	
	if (pErrorList != nullptr)
		delete pErrorList;

	if (pVectorNormalList != nullptr)
		delete pVectorNormalList;

	if (pVectorPosList != nullptr)
		delete pVectorPosList;

	if (pVectorPosNormTextList != nullptr)
		delete pVectorPosNormTextList;

	if (pVectorTextureList != nullptr)
		delete pVectorTextureList;
}
