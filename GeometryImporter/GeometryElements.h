/*	Author: Frank Dye
	Date: 10/2/1013
	Copyright: Frank Dye, 10/2/2013
	Description: This header defines basic geometry elements that are used by the GeometryImporter to parse OBJ and STL files.
				 These elements are defined using basic language types to insure easy cross-platform usage and ease of understanding.
*/

#ifndef GEOMETRY_ELEMENTS_H
#define GEOMETRY_ELEMENTS_H

#include <list>
#include <vector>
#include <string>

using namespace std;

//Base class for polymorphism, needed since we can have faces in several forms.
const int VECTOR_POS_TEXT_NORM = 1;
const int VECTOR_POS = 2;
const int VECTOR_POS_TEXT = 3;
const int VECTOR_POS_NORM = 4;
const int VECTOR_BASE = 5;



class VectorBase
{
public:
	virtual int getTypeId() {return VECTOR_BASE;};
};

class Face
{
public:

	//A face consists of n-vertices, usually triangles
	vector<VectorPosNormText> faceVectors;  //Vertices can be in form Pos/Norm/Texture, Pos, Pos/Norm, or Pos/Text
									 //This requires casting VectorBase to the appropriate type.
};

class	VectorPosNorm : VectorBase
{
public:
	virtual int getTypeId() {return VECTOR_POS_NORM;};
	float	posX;
	float	posY;
	float	posZ;
	float   normX;
	float	normY;
	float	normZ;
};

class	VectorPosText : VectorBase
{
public:
	virtual int getTypeId() {return VECTOR_POS_TEXT;};
	float	posX;
	float	posY;
	float	posZ;
	float	textU;
	float	textV;
};

class	VectorPos : VectorBase
{
public:
	virtual int getTypeId() {return VECTOR_POS;};
	float	posX;
	float	posY;
	float	posZ;
};

class	VectorPosNormText : VectorBase
{
public:
	virtual int getTypeId() {return VECTOR_POS_TEXT_NORM;};
	float	posX;
	float	posY;
	float	posZ;
	float   normX;
	float	normY;
	float	normZ;
	float	textU;
	float	textV;

};

struct	Vector3D
{
	float	x;
	float	y;
	float	z;
};

struct	Vector2D
{
	float	x;
	float	y;
};


struct	MaterialDesc
{
	string		    sMaterialRef; //Original ID for the scene
	string		    pAmbientTextureFileName;
	string          pDiffuseTextureFileName;
	string          pSpecularTextureFileName;
	string          pOpacityTextureFileName;
	string          pBumpTextureFileName;

};

struct	MaterialLibraryDesc
{
	string		sMaterialLibraryName;
};

struct	GroupName
{
	string		sGroup;
};

struct  RenderTextureRange
{
	int	min;
	int	max;
};

struct	Mesh
{
	int		startIndex;
	int		stopIndex;
	int		materialID;
	string	groupName;
};


#endif

