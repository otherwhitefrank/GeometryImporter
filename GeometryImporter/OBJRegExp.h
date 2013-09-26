/*	Author: Frank Dye
	Date: 9/25/13
	Copyright: Frank Dye, 9/25/2013
	Description: Defines the RegExp constants used in the OBJ geometry file format. For more information check
	http://en.wikipedia.org/wiki/Wavefront_.obj_file it gives a pretty good overview of the file format.
*/

#ifndef OBJREGEXP_H
#define OBJREGEXP_H

#include <regex>

//Material Libraries
const std::regex OBJ_MTLLIB_EXP = std::regex("(?:mtllib)\\s*(\\S*)");   

//Vertex 
const std::regex OBJ_VERTEX_EXP = std::regex("(?:v)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)");

//Vertex Texture
const std::regex OBJ__TEXTURE_EXP = std::regex("(?:vt)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)");

//Vertex Normal
const std::regex OBJ_VERTEX_NORMAL_EXP = std::regex("(?:vn)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)");

//Groups
const std::regex OBJ_GROUP_EXP = std::regex("(?:g)\\s*(\\S*)");

//Object names
const std::regex OBJ_OBJECT_EXP = std::regex("(?:o)\\s*(\\S*)");

//Use Material
const std::regex OBJ_USEMTL_EXP = std::regex("(?:usemtl)\\s*(\\S*)");   

//Smooth Group
const std::regex OBJ_SMOOTH_EXP = std::regex("(?:s)\\s*([0-9]*)");   

//Face Vertex-Texture Coordinate-Vector Normal
const std::regex OBJ_FACE_VT_TC_VN_EXP = std::regex("(?:f)\\s*([0-9]*)/([0-9]*)/([0-9]*)\\s*([0-9]*)/([0-9]*)/([0-9]*)\\s*([0-9]*)/([0-9]*)/([0-9]*)");

//Face Vertex Only
const std::regex OBJ_FACE_VT_EXP = std::regex("(?:f)\\s*([0-9]*)\\s*([0-9]*)\\s*([0-9]*)");

//Face Vertex-Texture Coordinate
const std::regex OBJ_FACE_VT_TC_EXP = std::regex("(?:f)\\s*([0-9]*)/([0-9]*)\\s*([0-9]*)/([0-9]*)\\s*([0-9]*)/([0-9]*)");

//Face Vertex-Vector Normal
const std::regex OBJ_FACE_VT_VN_EXP = std::regex("(?:f)\\s*([0-9]*)//([0-9]*)\\s*([0-9]*)//([0-9]*)\\s*([0-9]*)//([0-9]*)");

//Comment
const std::regex OBJ_COMMENT_EXP = std::regex("(?:#).*");

//Material File Definition

//New Material
const std::regex OBJ_NEWMTL_EXP = std::regex("(?:newmtl)\\s*(\\S*)"); 

//Ambient Color
const std::regex OBJ_AMBIENT_COLOR_EXP = std::regex("(?:Ka)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)");

//Diffuse Color
const std::regex OBJ_DIFFUSE_COLOR_EXP = std::regex("(?:Kd)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)");

//Specular Color
const std::regex OBJ_SPECULAR_COLOR_EXP = std::regex("(?:Ks)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)");

//Specular Coefficient
const std::regex OBJ_SPECULAR_COEFF_COLOR_EXP = std::regex("(?:Ns)\\s*([-+]?[0-9]*\\.?[0-9]+)");

//Dissolve, same as transparency %
const std::regex OBJ_DISSOLVE_EXP = std::regex("(?:d)\\s*([-+]?[0-9]*\\.?[0-9]+)");

//Transparency, also called Dissolve %
const std::regex OBJ_TRANSPARENT_EXP = std::regex("(?:Tr)\\s*([-+]?[0-9]*\\.?[0-9]+)");

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
const std::regex OBJ_ILLUMINATION_EXP = std::regex("(?:illum)\\s*([0-9]*)");


#endif