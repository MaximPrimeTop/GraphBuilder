#pragma once
#include "ClassesThing.h"
namespace GraphBuilder {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace GraphLib;
	using Vertex = GraphLib::Vertex;
	using Edge = GraphLib::Edge;
	/// <summary>
	/// Summary for AlgorithmsForm
	/// </summary>
	public ref class AlgorithmsForm : public System::Windows::Forms::Form
	{
	public:
		AlgorithmsForm(List<Vertex^>^ vertices, List<Edge^>^ edges, bool isOriented)
		{
			InitializeComponent();
			Vertices = gcnew List<Vertex^>();
			Edges = gcnew List<Edge^>();
			for each (auto vertex in vertices)
				Vertices->Add(vertex);
			for each (auto edge in edges)
				Edges->Add(edge);
			this->isOriented = isOriented;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AlgorithmsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	ref class DoubleBufferedPanel : public Panel
	{
	public:
		DoubleBufferedPanel()
		{
			this->DoubleBuffered = true;
			this->SetStyle(ControlStyles::OptimizedDoubleBuffer, true);
			this->SetStyle(ControlStyles::AllPaintingInWmPaint, true);
			this->SetStyle(ControlStyles::UserPaint, true);
			this->UpdateStyles();
		}
	};

	private: DoubleBufferedPanel^ drawPanel;




	private: System::Windows::Forms::Timer^ animationTimer;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->drawPanel = (gcnew DoubleBufferedPanel);
			this->animationTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// drawPanel
			// 
			this->drawPanel->BackColor = System::Drawing::Color::White;
			this->drawPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->drawPanel->Location = System::Drawing::Point(0, 0);
			this->drawPanel->Name = L"drawPanel";
			this->drawPanel->Size = System::Drawing::Size(1264, 681);
			this->drawPanel->TabIndex = 0;
			this->drawPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AlgorithmsForm::drawPanel_Paint);
			this->drawPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AlgorithmsForm::drawPanel_MouseDown);
			// 
			// animationTimer
			// 
			this->animationTimer->Enabled = false;
			this->animationTimer->Interval = 16;
			this->animationTimer->Tick += gcnew System::EventHandler(this, &AlgorithmsForm::animationTimer_Tick);
			// 
			// AlgorithmsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->drawPanel);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
			this->Name = L"AlgorithmsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"woooo now this is spicy";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AlgorithmsForm::AlgorithmsForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &AlgorithmsForm::AlgorithmsForm_Load);
			this->ResumeLayout(false);

		}



		protected:
			virtual void OnPaintBackground(PaintEventArgs^ e) override
			{
				// do nothing Å® prevents background erase flicker
			}
#pragma endregion
		const int heightThing = 100;
		bool isOriented = false;
		List<Vertex^>^ Vertices = gcnew List<Vertex^>();
		List<Edge^>^ Edges = gcnew List<Edge^>();
		int N;
		Brush^ brush = gcnew SolidBrush(Color::Black);
		Brush^ Redbrush = gcnew SolidBrush(Color::Red);
		Brush^ Whitebrush = gcnew SolidBrush(Color::White);
		Brush^ Purplebrush = gcnew SolidBrush(Color::Purple);
		Brush^ Bluebrsuh = gcnew SolidBrush(Color::Blue);
		Pen^ bgPen = gcnew Pen(Color::White, 15);
		Pen^ pen = gcnew Pen(Color::Black, 10);
		Pen^ Graypen = gcnew Pen(Color::Gray, 10);
		StringFormat^ format = gcnew StringFormat();
		void AdjustCoordinates()
		{
			int vertexCount = Vertices->Count;
			for (int i = 0; i < vertexCount; i++)
			{
				Vertices[i]->coord = Point(
					Vertices[i]->coord.X,
					Vertices[i]->coord.Y + heightThing
				);
			}
		}

		void AlgorithmsForm_Load(System::Object^ sender, System::EventArgs^ e) 
		{
			format->Alignment = StringAlignment::Center;
			format->LineAlignment = StringAlignment::Center;
			AdjustCoordinates();
			currentPath = gcnew List<int>();
			finalPath = gcnew List<int>();
			drawPanel->Invalidate();
		}

		array<bool, 2>^ GetAdjacencyMatrix()
		{
			N = Vertices->Count;
			array<bool, 2>^ matrix = gcnew array<bool, 2>(N, N);
			for each (auto edge in Edges)
			{
				int i = edge->vertex1->N;
				int j = edge->vertex2->N;
				matrix[i, j] = true;
				if (!isOriented)
					matrix[j, i] = true;
			}
			return matrix;
		}

		int isEulerian(array<bool, 2>^ adjacencyMatrix, int N)
		{
			int odd = 0;
			for (int i = 0; i < N; i++)
			{
				int degree = 0;
				for (int j = 0; j < N; j++)
				{
					if (adjacencyMatrix[i, j])
						degree++;
				}
				if (degree % 2 != 0)
					odd++;
			}
			if (odd == 0)
				return 2;
			if (odd == 2)
				return 1;
			return 0;
		}

		int findOddDegreeVertex(array<bool, 2>^ adjacencyMatrix, int N)
		{
			for (int i = 0; i < N; i++)
			{
				int degree = 0;
				for (int j = 0; j < N; j++)
				{
					if (adjacencyMatrix[i, j])
						degree++;
				}
				if (degree % 2 != 0)
					return i;
			}
			return -1;
		}

		int findNextVertex(int currentVertex, array<bool, 2>^ adjacencyMatrix, int N)
		{
			for (int i = 0; i < N; i++)
			{
				if (adjacencyMatrix[currentVertex, i])
					return i;
			}
			return -1;
		}

		enum class AnimationState
		{
			NotStarted,
			MovingToCurrentPath,
			MovingToCurrentPathAndDeletingEdge,
			MovingToFinalPath,
			ReversingFinalPath,
			Rebuilding,
			Finished,
		};

		AnimationState animationState = AnimationState::NotStarted;
		bool isReversed = false;
		array<bool, 2>^ AdjacencyMatrix;
		List<int>^ currentPath;
		List<int>^ finalPath;
		List<int>^ secretFinalPath;
		bool Started = false;
		Point targetPos;
		bool Rebuilding = false;
		int isEulerianResult;
	private: System::Void drawPanel_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		if (!Started)
		{
			AdjacencyMatrix = GetAdjacencyMatrix();
			isEulerianResult = isEulerian(AdjacencyMatrix, N);
			if (isEulerianResult == 0)
			{
				animationState = AnimationState::Finished;
				drawPanel->Invalidate();
				return;
			}
			currentPath = gcnew List<int>();
			finalPath = gcnew List<int>();
			if (isEulerianResult == 1)
			{
				AnimNumPos = Vertices[findOddDegreeVertex(AdjacencyMatrix, N)]->coord;
				AnimatedNumber = findOddDegreeVertex(AdjacencyMatrix, N);
			}
			else
			{
				AnimNumPos = Vertices[0]->coord;
				AnimatedNumber = 0;
			}
			animationState = AnimationState::MovingToCurrentPath;
			animationTimer->Start();
			Started = true;
			return;
		}
		if (animationState != AnimationState::NotStarted)
			return;
		if (currentPath->Count > 0)
		{
			int currentVertex = currentPath[currentPath->Count - 1];
			int nextVertex = findNextVertex(currentVertex, AdjacencyMatrix, N);
			if (nextVertex != -1)
			{
				AdjacencyMatrix[currentVertex, nextVertex] = false;
				AdjacencyMatrix[nextVertex, currentVertex] = false;
				AnimNumPos = Vertices[nextVertex]->coord;
				AnimatedNumber = nextVertex;
				animationState = AnimationState::MovingToCurrentPath;
				targetPos = GetTargetNumberPos(true, currentPath->Count);
				Edges->Remove(findEdgeByVertices(Vertices[currentVertex], Vertices[nextVertex]));
				animationTimer->Start();
			}
			else
			{
				AnimNumPos = GetTargetNumberPos(true, currentPath->Count - 1);
				AnimatedNumber = currentVertex;
				targetPos = GetTargetNumberPos(false, finalPath->Count);
				animationState = AnimationState::MovingToFinalPath;
				animationTimer->Start();
				//finalPath->Add(currentVertex);
				currentPath->RemoveAt(currentPath->Count - 1);
			}
		}
		else if (!isReversed && isOriented)
		{
			animationState = AnimationState::ReversingFinalPath;
			for each (auto num in finalPath)
			{
				animPositions->Add(GetTargetNumberPos(false, finalPath->IndexOf(num)));
				targetPositions->Add(GetTargetNumberPos(false, finalPath->Count - finalPath->IndexOf(num) - 1));
			}
			animationTimer->Start();
		}
		else if (!Rebuilding)
		{
			Rebuilding = true;
			secretFinalPath = gcnew List<int>();
			for each (auto fjikdf in finalPath)
				secretFinalPath->Add(fjikdf);
		}
		else
		{
			edgeToRebuild = gcnew Edge(Vertices[secretFinalPath[0]], Vertices[secretFinalPath[1]], 10);
			edgeToRebuild->isOriented = true;
			edgeToRebuild->colord = Color::Blue;
			animationState = AnimationState::Rebuilding;
			animationTimer->Start();
		}
	}
	 Edge^ edgeToRebuild;
	private: System::Void drawPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		Graphics^ g = e->Graphics;
		g->DrawLine(Graypen, 0, heightThing, drawPanel->Width, heightThing);
		g->DrawLine(Graypen, 0, drawPanel->Height - heightThing, drawPanel->Width, drawPanel->Height - heightThing);
		for each (auto edge in Edges)
			edge->Draw(edge->colord, edge->colord, g);
		for each (auto vertex in Vertices)
			vertex->Draw(vertex->colord, g);
		for (int i = 0; i < currentPath->Count; i++)
			g->DrawString(currentPath[i].ToString(), gcnew Drawing::Font("Arial", Vertices[currentPath[i]]->r / 2), brush, GetTargetNumberPos(true, i), format);
		if (animationState != AnimationState::ReversingFinalPath)
			for (int i = 0; i < finalPath->Count; i++)
				g->DrawString(finalPath[i].ToString(), gcnew Drawing::Font("Arial", Vertices[finalPath[i]]->r / 2), brush, GetTargetNumberPos(false, i), format);
		if (animationState == AnimationState::MovingToCurrentPath || animationState == AnimationState::MovingToFinalPath)
		{
			g->DrawString(AnimatedNumber.ToString(), gcnew Drawing::Font("Arial", Vertices[AnimatedNumber]->r / 2), brush, AnimNumPos, format);
			if (tempR != 50)
			{
				g->FillEllipse(Redbrush, Vertices[AnimatedNumber]->coord.X - tempR / 2, Vertices[AnimatedNumber]->coord.Y - tempR / 2, tempR, tempR);
				g->DrawString(AnimatedNumber.ToString(), gcnew Drawing::Font("Arial", Vertices[AnimatedNumber]->r / 2), Whitebrush, Vertices[AnimatedNumber]->coord, format);
			}
		}
		if (animationState == AnimationState::MovingToFinalPath)
		{
			g->DrawString(AnimatedNumber.ToString(), gcnew Drawing::Font("Arial", Vertices[AnimatedNumber]->r / 2), brush, AnimNumPos, format);
			if (tempR != 50)
			{
				g->FillEllipse(Purplebrush, Vertices[AnimatedNumber]->coord.X - tempR / 2, Vertices[AnimatedNumber]->coord.Y - tempR / 2, tempR, tempR);
				g->DrawString(AnimatedNumber.ToString(), gcnew Drawing::Font("Arial", Vertices[AnimatedNumber]->r / 2), Whitebrush, Vertices[AnimatedNumber]->coord, format);
			}
		}
		if (animationState == AnimationState::Rebuilding)
		{
			if (tempR != 50)
			{
				g->FillEllipse(Bluebrsuh, Vertices[secretFinalPath[0]]->coord.X - tempR / 2, Vertices[secretFinalPath[0]]->coord.Y - tempR / 2, tempR, tempR);
				g->DrawString(secretFinalPath[0].ToString(), gcnew Drawing::Font("Arial", Vertices[secretFinalPath[0]]->r / 2), Whitebrush, Vertices[secretFinalPath[0]]->coord, format);
				g->FillEllipse(Bluebrsuh, Vertices[secretFinalPath[1]]->coord.X - tempR / 2, Vertices[secretFinalPath[1]]->coord.Y - tempR / 2, tempR, tempR);
				g->DrawString(secretFinalPath[1].ToString(), gcnew Drawing::Font("Arial", Vertices[secretFinalPath[1]]->r / 2), Whitebrush, Vertices[secretFinalPath[1]]->coord, format);
			}
		}

		if (animationState == AnimationState::ReversingFinalPath)
		{
			for (int i = 0; i < animPositions->Count; i++)
			{
				g->DrawString(finalPath[i].ToString(), gcnew Drawing::Font("Arial", Vertices[finalPath[i]]->r / 2), brush, animPositions[i], format);
			}
		}

		if (animationState == AnimationState::Finished)
		{
			if (isEulerianResult == 0)
				g->DrawString("There is no eulerian path in this graph!", gcnew Drawing::Font("Arial", 30), brush, Point(drawPanel->Width / 2, 50), format);
			else if (isEulerianResult == 1)
				g->DrawString("Found eulerian path!", gcnew Drawing::Font("Arial", 30), brush, Point(drawPanel->Width / 2, 50), format);
			else
				g->DrawString("Found eulerian circuit!", gcnew Drawing::Font("Arial", 30), brush, Point(drawPanel->Width / 2, 50), format);
		}
	}
	private: System::Void AlgorithmsForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) 
	{

	}
	int tempR = 0;
	Point edgeStartPos, edgeEndPos;
	double angle;
	int cnt = 0;
	List<Point>^ animPositions = gcnew List<Point>;
	List<Point>^ targetPositions = gcnew List<Point>;
	private: System::Void animationTimer_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		if (animationState == AnimationState::MovingToCurrentPath || animationState == AnimationState::MovingToCurrentPathAndDeletingEdge)
		{
			AnimNumPos = Point(
				AnimNumPos.X + (targetPos.X - AnimNumPos.X) * 0.1,
				AnimNumPos.Y + (targetPos.Y - AnimNumPos.Y) * 0.1
			);
			if (tempR < 50)
				tempR += 3;
			if (tempR > 50)
			{
				tempR = 50;
				Vertices[AnimatedNumber]->colord = Color::Red;
			}
			if ((Math::Abs(AnimNumPos.X - targetPos.X) < 10 && Math::Abs(AnimNumPos.Y - targetPos.Y) < 10 && tempR == 50) || cnt == 100)
			{
				AnimNumPos = targetPos;
				animationState = AnimationState::NotStarted;
				currentPath->Add(AnimatedNumber);
				animationTimer->Stop();
				tempR = 0;
				cnt = 0;
			}
		}
		if (animationState == AnimationState::MovingToFinalPath)
		{
			AnimNumPos = Point(
				AnimNumPos.X + (targetPos.X - AnimNumPos.X) * 0.1,
				AnimNumPos.Y + (targetPos.Y - AnimNumPos.Y) * 0.1
			);
			if (tempR < 50)
				tempR += 3;
			if (tempR > 50)
			{
				tempR = 50;
				Vertices[AnimatedNumber]->colord = Color::Purple;
			}
			if ((Math::Abs(AnimNumPos.X - targetPos.X) < 10 && Math::Abs(AnimNumPos.Y - targetPos.Y) < 10 && tempR == 50) || cnt == 100)
			{
				AnimNumPos = targetPos;
				animationState = AnimationState::NotStarted;
				finalPath->Add(AnimatedNumber);
				animationTimer->Stop();
				tempR = 0;
				cnt = 0;
			}
		}
		if (animationState == AnimationState::Rebuilding)
		{
			if (tempR < 50)
				tempR += 3;
			if (tempR > 50)
			{
				tempR = 50;
				Vertices[secretFinalPath[0]]->colord = Color::Blue;
				Vertices[secretFinalPath[1]]->colord = Color::Blue;
			}
			if (tempR == 50 || cnt == 100)
			{
				animationState = AnimationState::NotStarted;
				animationTimer->Stop();
				secretFinalPath->RemoveAt(0);
				tempR = 0;
				cnt = 0;
				Edges->Add(edgeToRebuild);
				if (secretFinalPath->Count == 1)
				{
					secretFinalPath->RemoveAt(0);
					animationState = AnimationState::Finished;

				}
			}
		}
		if (animationState == AnimationState::ReversingFinalPath)
		{
			for (int i = 0; i < animPositions->Count; i++)
			{
				int x = animPositions[i].X;
				if (x < targetPositions[i].X)
					x += 10;
				else
					x -= 10;
				animPositions[i] = Point(
					x,
					animPositions[i].Y
				);
			}
			if (cnt == 25)
			{
				for (int i = 0; i < animPositions->Count; i++)
				{
					animPositions[i] = targetPositions[i];
				}
				animationState = AnimationState::NotStarted;
				animationTimer->Stop();
				finalPath->Reverse();
				animPositions->Clear();
				targetPositions->Clear();
				isReversed = true;
				cnt = 0;
			}
		}
		cnt++;
		drawPanel->Invalidate();
	}

	Point AnimNumPos;
	int AnimatedNumber;
	Point targetNumberPos;
	const int spaceBetweenNumbers = 50;
	Point GetTargetNumberPos(bool toCurrent, int index)
	{
		if (toCurrent)
		{
			return Point(50 + spaceBetweenNumbers * index, heightThing / 2);
		}
		else
		{
			return Point(50 + spaceBetweenNumbers * index, drawPanel->Height - heightThing / 2);
		}
	}
	Edge^ findEdgeByVertices(Vertex^ v1, Vertex^ v2)
	{
		Edge^ edge = gcnew Edge(v1, v2, 10);
			for each (auto e in Edges)
				if (e == edge)
					return e;
		return nullptr;
	}
};
}