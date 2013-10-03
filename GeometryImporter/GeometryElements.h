/*	Author: Frank Dye
	Date: 10/2/1013
	Copyright: Frank Dye, 10/2/2013
	Description: This header defines basic geometry elements that are used by the GeometryImporter to parse OBJ and STL files.
				 These elements are defined using basic language types to insure easy cross-platform usage and ease of understanding.
*/

#ifndef GEOMETRY_ELEMENTS_H
#define GEOMETRY_ELEMENTS_H

#include <string>

using namespace std;

struct	VectorPosNormText
{
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

