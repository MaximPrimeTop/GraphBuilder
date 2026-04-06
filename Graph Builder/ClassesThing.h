#pragma once
#include <cmath>
namespace GraphLib
{
	using namespace System;
	using namespace System::Drawing;
	static double pi = 3.141592653589793;
    public ref class Vertex 
	{
	public:
		Point coord;
		int r;
		int N;
		Color colord;
		Vertex(int x, int y, int n, int r)
		{
			coord = Point(x, y);
			N = n;
			this->r = r;
		}

		void Draw(Color color, Graphics^ g)
		{
			Brush^ brush = gcnew SolidBrush(color);
			g->FillEllipse(brush, coord.X - r / 2, coord.Y - r / 2, r, r);
			brush = gcnew SolidBrush(Color::White);
			StringFormat^ format = gcnew StringFormat();
			format->Alignment = StringAlignment::Center;
			format->LineAlignment = StringAlignment::Center;
			g->DrawString(N.ToString(), gcnew Drawing::Font("Arial", r / 2), brush, coord, format);
		}

		void Clear(Color bgColor, Graphics^ g)
		{
			Brush^ brush = gcnew SolidBrush(bgColor);
			g->FillEllipse(brush, coord.X - r / 2, coord.Y - r / 2, r, r);
		}

		bool isClicked(Point pos)
		{
			if (hypot(coord.X - pos.X, coord.Y - pos.Y) <= r / 2)
				return true;
			return false;
		}

		bool isDrawable(Point pos, int radius)
		{
			if (hypot(coord.X - pos.X, coord.Y - pos.Y) <= (r + radius) / 2)
				return true;
			return false;
		}
	};
    public ref class Edge
	{
	public:
		Vertex^ vertex1;
		Vertex^ vertex2;
		int width;
		bool isOriented = false;
		Color colord;
		Edge(Vertex^ v1, Vertex^ v2, int w)
		{
			vertex1 = v1;
			vertex2 = v2;
			width = w;
		}

		bool operator==(Edge^ other)
		{
			if (isOriented)
				return vertex1 == other->vertex1 && vertex2 == other->vertex2;
			return (vertex1 == other->vertex1 && vertex2 == other->vertex2) ||
				(vertex1 == other->vertex2 && vertex2 == other->vertex1);
		}

		void Draw(Color colorV, Color colorE, Graphics^ g)
		{
			Pen^ pen = gcnew Pen(colorE, width);
			g->DrawLine(pen, vertex1->coord, vertex2->coord);
			if (isOriented)
				DrawArrow(pen, g);
		}

		void DrawArrow(Pen^ pen, Graphics^ g)
		{
			double angle = atan2(vertex2->coord.Y - vertex1->coord.Y, vertex2->coord.X - vertex1->coord.X);
			Point arrowStart = Point
			(
				vertex2->coord.X - vertex2->r / 2 * cos(angle),
				vertex2->coord.Y - vertex2->r / 2 * sin(angle)
			);
			double angle1 = angle - (pi / 6);
			double angle2 = angle + (pi / 6);

			Point arrowEnd1 = Point
			(
				arrowStart.X - vertex2->r * cos(angle1),
				arrowStart.Y - vertex2->r * sin(angle1)
			);
			Point arrowEnd2 = Point
			(
				arrowStart.X - vertex2->r * cos(angle2),
				arrowStart.Y - vertex2->r * sin(angle2)
			);
			g->DrawLine(pen, arrowStart, arrowEnd1);
			g->DrawLine(pen, arrowStart, arrowEnd2);
		}
	private:

	};
    //public ref class ConnectedComponent { ... };
    //public ref class Path { ... };
}