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
	CGeometryImporterOBJ();

	//Set the file pointer internally
	m_InputFile = inputFile;

	//Process the file
	ProcessFile();
}



CGeometryImporterOBJ::~CGeometryImporterOBJ()
{

}

bool CGeometryImporterOBJ::LoadFile( ifstream* inputFile )
{
	//Set the file pointer internally
	m_InputFile = inputFile;

	//Process the file
	ProcessFile();
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

}

void CGeometryImporterOBJ::ResetObject()
{

}
