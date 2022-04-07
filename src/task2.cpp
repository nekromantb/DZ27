#include "task2.h"
#include <iostream>
#include <math.h>

enum Color
{
    RED,
    BLUE,
    GREEN,
    NONE
};

class Coordinates
{
    double x = 0;
    double y = 0;

public:

    void setCoord(double inputX, double inputY)
    {
        x += inputX;
        y += inputY;
    }

    double getCoordX()
    {
        return x;
    }

    double getCoordY()
    {
        return y;
    }

};

class Figure
{
public:
    Coordinates center;
    Color color = NONE;

    void getColor (std::string input)
    {
        if (input == "red" || input == "Red") color = RED;
        if (input == "blue" || input == "Blue") color = BLUE;
        if (input == "green" || input == "Green") color = GREEN;
        if (input == "none" || input == "None") color = NONE;
    }
};

class RectangleOut: Figure
{
    double length = 0, wight = 0;

public:

    void setRectangleOut (Coordinates inCenter, double inLength, double inWight)
    {
        center = inCenter;
        length = inLength;
        wight = inWight;
    }

    void outputRectOut()
    {
        std::cout << "Circumscribing rectangle: length: " << length << " wight: " << wight << " center: " << center.getCoordX() << " , " << center.getCoordY();
    }
};

class Rectangle: Figure
{
    double length = 0, wight = 0, square = 0;
    RectangleOut outRect;

public:

    Rectangle()
    {
        std::cout << "Enter center point of figure (x, y)" <<std::endl;
        double inX, inY;
        std::cin >> inX >> inY;
        center.setCoord(inX,inY);
        std::cout << "Enter length of rectangle "<< std::endl;
        std::cin >> length;
        std::cout << "Enter wight of rectangle " << std::endl;
        std::cin >> wight;
        std::cout << "Enter color of rectangle (red, blue, green, none)" << std::endl;
        std::string inColor;
        std::cin >> inColor;
        getColor(inColor);
        square = length * wight;
        outRect.setRectangleOut(center,length+1,wight+1);
    }


    void output()
    {
        std::cout << "Square " << square << " ";
        outRect.outputRectOut();
    }

};

class Circle: Figure
{
    double radius = 0, square = 0;
    RectangleOut outRect;

public:

    Circle()
    {
        std::cout << "Enter center point of figure (x, y)" <<std::endl;
        double inX, inY;
        std::cin >> inX >> inY;
        center.setCoord(inX,inY);
        std::cout << "Enter radius of circle "<< std::endl;
        std::cin >> radius;
        std::cout << "Enter color of circle (red, blue, green, none)" << std::endl;
        std::string inColor;
        std::cin >> inColor;
        getColor(inColor);
        square = radius *radius * 4 * atan(1);
        outRect.setRectangleOut(center,2*radius+1,2*radius+1);
    }

    void output()
    {
        std::cout << "Square " << square << " ";
        outRect.outputRectOut();
    }

};

class Square: Figure
{
    double length = 0, square = 0;
    RectangleOut outRect;

public:

    Square()
    {
        std::cout << "Enter center point of figure (x, y)" <<std::endl;
        double inX, inY;
        std::cin >> inX >> inY;
        center.setCoord(inX,inY);
        std::cout << "Enter length of square "<< std::endl;
        std::cin >> length;
        std::cout << "Enter color of square (red, blue, green, none)" << std::endl;
        std::string inColor;
        std::cin >> inColor;
        getColor(inColor);
        square = length * length;
        outRect.setRectangleOut(center,length+1,length+1);
    }

    void output()
    {
        std::cout << "Square " << square << " ";
        outRect.outputRectOut();
    }

};

class Triangle: Figure
{
    double length = 0, square = 0;
    RectangleOut outRect;

public:

    Triangle() {
        std::cout << "Enter center point of figure (x, y)" << std::endl;
        double inX, inY;
        std::cin >> inX >> inY;
        center.setCoord(inX, inY);
        std::cout << "Enter length of triangle " << std::endl;
        std::cin >> length;
        std::cout << "Enter color of triangle (red, blue, green, none)" << std::endl;
        std::string inColor;
        std::cin >> inColor;
        getColor(inColor);
        square = length * length * std::sqrt(3) / 4;
        outRect.setRectangleOut(center, length + 1, length * std::sqrt(3) * 2 / 3);
    }

    void output()
    {
        std::cout << "Square " << square << " ";
        outRect.outputRectOut();
    }

};

void task2()
{
    std::cout << "Choose figure: circle, square, triangle, rectangle" << std::endl;
    std::string input;
    std::cin >> input;
    if ( input == "circle") {
        Circle circle;
        circle.output();
    } else
    if ( input == "square") {
        Square square;
        square.output();
    } else
    if ( input == "triangle") {
        Triangle triangle;
        triangle.output();
    } else
    if ( input == "rectangle") {
        Rectangle rectangle;
        rectangle.output();
    } else std::cout << "Wrong input!"<< std::endl;
}