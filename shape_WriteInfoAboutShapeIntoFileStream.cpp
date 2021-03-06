#include "stdafx.h"
#include <fstream>
#include "shape.h"

using namespace std;

namespace shapes 
{
	float CalculateShapePerimeter(shape &shape);
	void WriteDimensionsOfShapeIntoFileStream(rectangle &rectangle, ofstream &outFileStream);
	void WriteDimensionsOfShapeIntoFileStream(circle  &circle, ofstream &outFileStream);
	void WriteDimensionsOfShapeIntoFileStream(triangle  &triangle, ofstream &outFileStream);

	void WriteInfoAboutShapeIntoFileStream(shape &outShape, ofstream &outFileStream)
	{
		void CheckOutputFile(ostream &outFileStream);
		outFileStream << "It is ";
		
		switch (outShape.key) 
		{
		case shape::key::RECTANGLE:
			outFileStream << "Rectangle";
			break;
		case shape::key::CIRCLE:
			outFileStream << "Circle";
			break; 
		case shape::key::TRIANGLE:
			outFileStream << "Triangle";
			break;
		default:
			break;
		}

		outFileStream << "; Its color is ";
		string m[7] = { "RED", "ORANGE", "YELLOW", "GREEN", "CYAN", "BLUE", "MAGNETA" };

		int i = outShape._color - 1;
		outFileStream << m[i].c_str();

		outFileStream << "; And its dimensions are: ";

		switch (outShape.key) 
		{
		case shape::key::RECTANGLE:
			WriteDimensionsOfShapeIntoFileStream(outShape.rectangle, outFileStream);
			break;
		case shape::key::CIRCLE:
			WriteDimensionsOfShapeIntoFileStream(outShape.circle, outFileStream);
			break;
		case shape::key::TRIANGLE:
			WriteDimensionsOfShapeIntoFileStream(outShape.triangle, outFileStream);
			break;
		default:
			break;
		}

		outFileStream << "; Plotnost: " <<outShape.plotn;
		outFileStream << "; Its perimeter is " << CalculateShapePerimeter(outShape);
		outFileStream << ";" << endl;
	}
}
