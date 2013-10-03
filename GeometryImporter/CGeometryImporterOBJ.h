/*	Author: Frank Dye
	Date: 10/2/1013
	Copyright: Frank Dye, 10/2/2013
	Description: This class handles the importing of an OBJ Geometry file. It is passed in an open valid ifstream handle and proceeds
				 to parse the file line by line storing each of the aspects of the Geometry file for retrieval. User is required to close
				 the ifstream handle outside the scope of the class. 
*/

#ifndef CGEOMETRY_IMPORTER_OBJ_H
#define CGEOMETRY_IMPORTER_OBJ_H

#include <fstream>
#include <iostream>
#include <list>
#include "GeometryElements.h"
#include "OBJRegExp.h"

using namespace std;

class	CGeometryImporterOBJ
{
public:
	//Constructors
	CGeometryImporterOBJ();
	CGeometryImporterOBJ(ifstream* inputFile);

	//Deconstructors
	~CGeometryImporterOBJ();

	bool     LoadFile(ifstream* inputFile); //Load a new file

	//Functions to request counts from file
	int 	GetVertexCount()			{return m_VertexPosCount;};
	int 	GetTextureVertexCount()	    {return m_VertexTextureCount};
	int 	GetNormalVertexCount()	    {return m_VertexNormalCount;};
	int 	GetFaceCount()				{return m_FaceCount;};
	int		GetMeshCount()				{m_MeshCount;};

	int		GetErrorCount()				{pErrorList->size();};

	//Functions to request pointers the internal geometry lists, the user is required to maintain this pointer and reset
	//the library appropriately. If this is not done appropriately then it may result in a memory leak.

	list<Vector3D>*					GetVertexPosList(); 
	list<Vector3D>*					GetVertexNormalList();
	list<Vector2D>*					GetVertexTextureList();
	list<VectorPosNormText>*		GetVectorPosNormTextList();
	list<Mesh>*						GetMeshList();

	list<string>*					GetErrorList();


	//Functions to physically copy out elements.
	void	CopyVectorPosNormTextList(list<VectorPosNormText>* destVectorList);
	void	CopyMeshList(list<Mesh>* destMeshList);

	void	CopyVertexPosList(list<Vector3D>* destVertexList);  //All perform physical memcpy
	void	CopyVertexNormalList(list<Vector3D>* destVertexNormalList);
	void	CopyVertexTextureList(list<Vector2D>* destVertexTextureList);

private:
	void	ProcessFile();		   //Assumes m_inputFile is set, fills internal arrays
	void	ResetObject();		   //Resets all member functions to default values

	//Internal counts of stores information
	int		m_VertexPosCount;			//Number of vertices in file
	int		m_VertexTextureCount;		//Number of texture vertices in file
	int		m_VertexNormalCount;		//Number of vertex normals in file

	int		m_FaceCount;				//Number of faces in file
	int		m_MeshCount;				//Number of meshes in file

	//Pointers to element arrays
	list<Vector3D>*					pVectorPosList;				//Pointer to list of vertices
	list<Vector3D>*					pVectorNormalList;			//Pointer to list of vertex normals
	list<Vector2D>*					pVectorTextureList;			//Pointer to list of texture vertices
	list<VectorPosNormText>*		pVectorPosNormTextList;		//Pointer to a list of Pos/Norm/Text Vectors
	list<Mesh>*						pMeshList;					//Pointer to a list of meshes

	list<string>*					pErrorList;					//Pointer to a list of strings that contains description of any problems encountered
																//Format is of form <File Name:LineNumber>:<Error Found>

	//File handle
	ifstream*	m_InputFile;		//Pointer to an externally opened and verified input file, user is required to maintain it
};

#endif
