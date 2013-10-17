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
}

bool CGeometryImporterOBJ::LoadFile( ifstream* inputFile )
{
	//Set the file pointer internally
	pInputFile = inputFile;

	//Process the file
	ProcessFile();
	return true;
}

vector<Vector3D> CGeometryImporterOBJ::GetVertexPosArray()
{
	return VectorPosArray;
}

vector<Vector3D> CGeometryImporterOBJ::GetVertexNormalArray()
{
	return VectorNormalArray;
}

vector<Vector2D> CGeometryImporterOBJ::GetVertexTextureArray()
{
	return VectorTextureArray;
}

vector<Face>	 CGeometryImporterOBJ::GetFaceArray()
{
	return FaceArray;
}

vector<Mesh> CGeometryImporterOBJ::GetMeshArray()
{
	return MeshArray;
}

vector<string> CGeometryImporterOBJ::GetErrorArray()
{
	return ErrorArray;
}

void CGeometryImporterOBJ::CopyFaceArray( vector<Face>&	 destVectorPosNormTextArray )
{
	for (auto it = std::begin(FaceArray); it!=std::end(FaceArray); ++it)
		destVectorPosNormTextArray.push_back(*it);
}

void CGeometryImporterOBJ::CopyMeshArray(vector<Mesh>& destMeshArray)
{
	for (auto it = std::begin(MeshArray); it!=std::end(MeshArray); ++it)
		destMeshArray.push_back(*it);
}

void CGeometryImporterOBJ::CopyVertexPosArray(vector<Vector3D>& destVertexArray)
{
	for (auto it = std::begin(VectorPosArray); it!=std::end(VectorPosArray); ++it)
		destVertexArray.push_back(*it);

}

void CGeometryImporterOBJ::CopyVertexNormalArray(vector<Vector3D>& destVertexNormalArray)
{
	for (auto it = std::begin(VectorNormalArray); it!=std::end(VectorNormalArray); ++it)
		destVertexNormalArray.push_back(*it);
}

void CGeometryImporterOBJ::CopyVertexTextureArray(vector<Vector2D>& destVertexTextureArray)
{
	for (auto it = std::begin(VectorTextureArray); it!=std::end(VectorTextureArray); ++it)
		destVertexTextureArray.push_back(*it);
}

float	CGeometryImporterOBJ::StringToFloat(string& inString)
{
	//Convert string object to float value using C string based conversion.
	return (float) atof(inString.c_str());
}

int		CGeometryImporterOBJ::StringToInt(string& inString)
{
	//convert string object to int value using c string based conversion
	return (int) atoi(inString.c_str());
}


void CGeometryImporterOBJ::ProcessFile()
{
	string lineBuffer = "";
	int lineCount = 0;


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
			string szX = regexMatch[1];
			string szY = regexMatch[2];
			string szZ = regexMatch[3];
			Vector3D* tempVect3D = new Vector3D;
			tempVect3D->x = StringToFloat(szX);
			tempVect3D->y = StringToFloat(szY);
			tempVect3D->z = StringToFloat(szZ);
			std::cout << lineBuffer << " Position Vector" << std::endl;

			//Add it to our vertex texture vector
			VectorPosArray.push_back(*tempVect3D);

		}
		
		//Vertex Texture
		else if (regex_search(lineBuffer, regexMatch, OBJ__TEXTURE_EXP))
		{
			m_VertexTextureCount++;
			string szX = regexMatch[1];
			string szY = regexMatch[2];
			Vector2D* tempVect2D = new Vector2D;
			tempVect2D->x = StringToFloat(szX);
			tempVect2D->y = StringToFloat(szY);
			std::cout << lineBuffer << " Texture Vector" << std::endl;

			//Add it to our vertex texture vector
			VectorTextureArray.push_back(*tempVect2D);

		}

		//Vertex Normal
		else if (regex_search(lineBuffer, regexMatch, OBJ_VERTEX_NORMAL_EXP))
		{
			m_VertexNormalCount++;

			string szX = regexMatch[1];
			string szY = regexMatch[2];
			string szZ = regexMatch[3];
			Vector3D* tempVect3D = new Vector3D;
			tempVect3D->x = StringToFloat(szX);
			tempVect3D->y = StringToFloat(szY);
			tempVect3D->z = StringToFloat(szZ);
			std::cout << lineBuffer << " Normal Vector" << std::endl;

			//Add it to our vertex texture vector
			VectorNormalArray.push_back(*tempVect3D);
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
			
			VectorPosNormText* tempVect;
			string tempString[9];
			int tempIndexes[9];
			for (int i = 0; i < 9; i++)
			{
				tempString[i] = regexMatch[i+1];
				tempIndexes[i] = StringToInt(tempString[i]);
			}

			Face tempFace;

			for (int i = 0; i < 3; i++)
			{
				tempVect = new VectorPosNormText;
				int index = i * 3;
				int posIndex = tempIndexes[index];
				int normIndex = tempIndexes[index+1];
				int textIndex = tempIndexes[index+2];
				//Position
				tempVect->posX = VectorPosArray[posIndex-1].x;
				tempVect->posY = VectorPosArray[posIndex-1].y;
				tempVect->posZ = VectorPosArray[posIndex-1].z;
				//Normal
				tempVect->normX = VectorNormalArray[normIndex-1].x;
				tempVect->normY = VectorNormalArray[normIndex-1].y;
				tempVect->normZ = VectorNormalArray[normIndex-1].z;
				//Texture
				tempVect->textU = VectorTextureArray[textIndex-1].x;
				tempVect->textV = VectorTextureArray[textIndex-1].y;

				tempFace.faceVectors.push_back( *tempVect);
			}

			FaceArray.push_back(tempFace);


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
			ErrorArray.push_back(szTemp);
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

	ErrorArray.clear();
	MeshArray.clear();
	VectorNormalArray.clear();
	VectorPosArray.clear();
	FaceArray.clear();
	VectorTextureArray.clear();
}

