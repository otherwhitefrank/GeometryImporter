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
#include <string>
#include <vector>
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
	int 	GetTextureVertexCount()	    {return m_VertexTextureCount;};
	int 	GetNormalVertexCount()	    {return m_VertexNormalCount;};
	int 	GetFaceCount()				{return m_FaceCount;};
	int		GetMeshCount()				{return m_MeshCount;};

	int		GetErrorCount()				{return ErrorArray.size();};

	//Functions to request pointers the internal geometry vectors, the user is required to maintain this pointer and reset
	//the library appropriately. If this is not done appropriately then it may result in a memory leak.

	vector<Vector3D>					GetVertexPosArray(); 
	vector<Vector3D>					GetVertexNormalArray();
	vector<Vector2D>					GetVertexTextureArray();
	vector<Face>					GetFaceArray();
	vector<Mesh>						GetMeshArray();

	vector<string>						GetErrorArray();


	//Functions to physically copy out elements.
	void	CopyFaceArray( vector<Face>&	 destVectorPosNormTextvector );
	void	CopyMeshArray(vector<Mesh>& destMeshvector);

	void	CopyVertexPosArray(vector<Vector3D>& destVertexvector);  //All perform physical memcpy
	void	CopyVertexNormalArray(vector<Vector3D>& destVertexNormalvector);
	void	CopyVertexTextureArray(vector<Vector2D>& destVertexTexturevector);
	

private:
	void	ProcessFile();		   //Assumes m_inputFile is set, fills internal arrays
	void	ResetObject();		   //Resets all member functions to default values
	float	StringToFloat(string& inString);
	int		StringToInt(string& inString);

	//Internal counts of stores information
	int		m_VertexPosCount;			//Number of vertices in file
	int		m_VertexTextureCount;		//Number of texture vertices in file
	int		m_VertexNormalCount;		//Number of vertex normals in file

	int		m_FaceCount;				//Number of faces in file
	int		m_MeshCount;				//Number of meshes in file

	//Pointers to element arrays
	vector<Vector3D>					VectorPosArray;				//Position Array
	vector<Vector3D>					VectorNormalArray;			//Normal Array
	vector<Vector2D>					VectorTextureArray;			//Texture Array
	vector<Face>						FaceArray;					//Triangle Array
	vector<Mesh>						MeshArray;					//Mesh array

	vector<string>						ErrorArray;					//vector of strings that contains description of any problems encountered
																	//Format is of form <File Name:LineNumber>:<Error Found>

	//File handle
	ifstream*	pInputFile;		//Pointer to an externally opened and verified input file, user is required to maintain it
};

#endif
