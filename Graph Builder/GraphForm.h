#pragma once
#include <windows.h>
#include <cmath>
#using <System.Core.dll>
#include "ChangeRadiusForm.h"
#include "RandomGraphGeneratorForm.h"
#include "StatsForm.h"
namespace GraphBuilder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using System::Collections::Generic::Stack;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	public ref class GraphForm : public System::Windows::Forms::Form
	{
	public:
		GraphForm(void)
		{
			InitializeComponent();
		}

	protected:
		~GraphForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelDraw;


	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
























	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;







	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ customizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomColorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ colorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ changeRadiusToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ optionsToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ generateGraphToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ orientedGraphsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ changeWidthToolStripMenuItem;
































	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GraphForm::typeid));
			this->panelDraw = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->customizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeRadiusToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeWidthToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generateGraphToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->orientedGraphsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelDraw->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelDraw
			// 
			this->panelDraw->Controls->Add(this->menuStrip1);
			this->panelDraw->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelDraw->Location = System::Drawing::Point(0, 0);
			this->panelDraw->Name = L"panelDraw";
			this->panelDraw->Size = System::Drawing::Size(1264, 681);
			this->panelDraw->TabIndex = 0;
			this->panelDraw->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphForm::panelDraw_MouseDown);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->toolsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1264, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newToolStripMenuItem,
					this->openToolStripMenuItem, this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"newToolStripMenuItem.Image")));
			this->newToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->newToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->newToolStripMenuItem->Text = L"&New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripMenuItem.Image")));
			this->openToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->openToolStripMenuItem->Text = L"&Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveToolStripMenuItem.Image")));
			this->saveToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->saveToolStripMenuItem->Text = L"&Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::saveToolStripMenuItem_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->customizeToolStripMenuItem,
					this->optionsToolStripMenuItem1
			});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->toolsToolStripMenuItem->Text = L"&Tools";
			// 
			// customizeToolStripMenuItem
			// 
			this->customizeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->randomColorToolStripMenuItem,
					this->colorToolStripMenuItem, this->changeRadiusToolStripMenuItem, this->changeWidthToolStripMenuItem
			});
			this->customizeToolStripMenuItem->Name = L"customizeToolStripMenuItem";
			this->customizeToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->customizeToolStripMenuItem->Text = L"&Customize";
			// 
			// randomColorToolStripMenuItem
			// 
			this->randomColorToolStripMenuItem->Checked = true;
			this->randomColorToolStripMenuItem->CheckOnClick = true;
			this->randomColorToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->randomColorToolStripMenuItem->Name = L"randomColorToolStripMenuItem";
			this->randomColorToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->randomColorToolStripMenuItem->Text = L"Random color";
			this->randomColorToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::randomColor_Click);
			// 
			// colorToolStripMenuItem
			// 
			this->colorToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"colorToolStripMenuItem.Image")));
			this->colorToolStripMenuItem->Name = L"colorToolStripMenuItem";
			this->colorToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->colorToolStripMenuItem->Text = L"Choose Color";
			this->colorToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::changeColor_Click);
			// 
			// changeRadiusToolStripMenuItem
			// 
			this->changeRadiusToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"changeRadiusToolStripMenuItem.Image")));
			this->changeRadiusToolStripMenuItem->Name = L"changeRadiusToolStripMenuItem";
			this->changeRadiusToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->changeRadiusToolStripMenuItem->Text = L"Change radius";
			this->changeRadiusToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::changeRadius_Click);
			// 
			// changeWidthToolStripMenuItem
			// 
			this->changeWidthToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"changeWidthToolStripMenuItem.Image")));
			this->changeWidthToolStripMenuItem->Name = L"changeWidthToolStripMenuItem";
			this->changeWidthToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->changeWidthToolStripMenuItem->Text = L"Change width";
			this->changeWidthToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::changeWidthToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem1
			// 
			this->optionsToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->generateGraphToolStripMenuItem,
					this->orientedGraphsToolStripMenuItem
			});
			this->optionsToolStripMenuItem1->Name = L"optionsToolStripMenuItem1";
			this->optionsToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->optionsToolStripMenuItem1->Text = L"&Options";
			// 
			// generateGraphToolStripMenuItem
			// 
			this->generateGraphToolStripMenuItem->Name = L"generateGraphToolStripMenuItem";
			this->generateGraphToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->generateGraphToolStripMenuItem->Text = L"Generate Graph";
			this->generateGraphToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::generateGraph_Click);
			// 
			// orientedGraphsToolStripMenuItem
			// 
			this->orientedGraphsToolStripMenuItem->CheckOnClick = true;
			this->orientedGraphsToolStripMenuItem->Name = L"orientedGraphsToolStripMenuItem";
			this->orientedGraphsToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->orientedGraphsToolStripMenuItem->Text = L"Oriented Graphs";
			this->orientedGraphsToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::orientedGraphsToolStripMenuItem_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"txt";
			this->saveFileDialog1->FileName = L"graphs";
			this->saveFileDialog1->Filter = L"Text files|*.txt|All files|*.*";
			this->saveFileDialog1->Title = L"SAVE";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"txt";
			this->openFileDialog1->FileName = L"graphs";
			this->openFileDialog1->Filter = L"Text files|*.txt|All files|*.*";
			this->openFileDialog1->Title = L"LOAD";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &GraphForm::timer1_Tick_1);
			// 
			// GraphForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->panelDraw);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"GraphForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Graph Builder";
			this->Load += gcnew System::EventHandler(this, &GraphForm::GraphForm_Load);
			this->panelDraw->ResumeLayout(false);
			this->panelDraw->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		static Graphics^ g;
		static int R = 50;
		static int Width = 10;
		static bool randomColor = true;
		static Color bgColor;
		static Color currentColor = Color::Black;
		static Random^ rnd = gcnew Random();
		static StatsForm^ stats;
		static bool isOriented = false;
		static double pi = 3.141592653589793;
		enum class DrawingState
		{
			Vertex,
			EdgeStart,
			Deleting,
		};

		static DrawingState drawingState = DrawingState::Vertex;

		#pragma region Classes
	public:
			ref class Vertex
			{
			public:
				Point coord;
				int r;
				int N;
				Vertex(int x, int y) : Vertex(Point(x, y))
				{
				}
				Vertex(Point pos)
				{
					coord = pos;
					r = R;
					int count = 0;
					for each (auto graph in Graphs)
						count += graph->Vertices->Count;
					count += tempGraph->Vertices->Count;
					N = count + 1;
				}

				Vertex(Point pos, int r)
				{
					coord = pos;
					this->r = r;
					int count = 0;
					for each (auto graph in Graphs)
						count += graph->Vertices->Count;
					count += tempGraph->Vertices->Count;
					N = count + 1;
				}

				Vertex(int x, int y, int n, int r)
				{
					coord = Point(x, y);
					N = n;
					this->r = r;
				}

				void Draw(Color color)
				{
					Brush^ brush = gcnew SolidBrush(color);
					g->FillEllipse(brush, coord.X - r / 2, coord.Y - r / 2, r, r);
					brush = gcnew SolidBrush(Color::White);
					StringFormat^ format = gcnew StringFormat();
					format->Alignment = StringAlignment::Center;
					format->LineAlignment = StringAlignment::Center;
					g->DrawString(N.ToString(), gcnew Drawing::Font("Arial", r / 2), brush, coord, format);
				}

				void Clear()
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

			ref class Edge
			{
			public:
				Vertex^ vertex1;
				Vertex^ vertex2;
				int width;
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

				void Draw(Color colorV, Color colorE)
				{
					Pen^ pen = gcnew Pen(colorE, width);
					g->DrawLine(pen, vertex1->coord, vertex2->coord);
					pen = gcnew Pen(Color::Black, 2);
				}

				void DrawArrow(Pen^ pen)
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

			ref class Graph
			{
			public:
				List<Vertex^>^ Vertices = gcnew List<Vertex^>();
				List<Edge^>^ Edges = gcnew List<Edge^>();
				Color color;
				Graph()
				{
					if (randomColor)
						color = RandomColor();
					else
						color = currentColor;
				}

				Graph(Color c)
				{
					color = c;
				}

				void DrawGraph()
				{
					for each (auto edge in Edges)
						edge->Draw(color, color);
					for each (auto vertex in Vertices)
						vertex->Draw(color);
					if (isOriented)
						for each (auto edge in Edges)
							edge->DrawArrow(gcnew Pen(color, edge->width));
				}
				Edge^ findEdge(Edge^ edge)
				{
					for each (auto e in Edges)
						if (e == edge)
							return e;
					return nullptr;
				}
				void DeleteVertex(Vertex^ vertex)
				{
					if (findGraphByVertex(vertex) != this)
						return;
					for (int i = Edges->Count - 1; i >= 0 ; i--)
					{
						if (Edges[i]->vertex1 == vertex || Edges[i]->vertex2 == vertex)
							Edges->RemoveAt(i);
					}
					Vertices->Remove(vertex);
					RenumberVertices(vertex->N);
					if (Vertices->Count == 0)
						Graphs->Remove(this);
					RebuildGraphs();
				}

				void DeleteEdge(Edge^ edge)
				{
					if (findGraphByEdge(edge) != this)
						return;
					edge = findEdge(edge);
					Pen^ pen = gcnew Pen(bgColor);
					Edges->Remove(edge);
					RebuildGraphs();
				}
			};
		#pragma endregion
	private:
		static List<Graph^>^ Graphs = gcnew List<Graph^>();
		void GraphForm_Load(System::Object^ sender, System::EventArgs^ e)
		{
			g = panelDraw->CreateGraphics();
			bgColor = panelDraw->BackColor;
			stats = gcnew StatsForm();
			stats->Location = Point(this->Right, this->Top + 31);
			stats->Show();
		}

		protected:
			virtual void OnMove(EventArgs^ e) override
			{
				Form::OnMove(e);

				if (stats != nullptr && !stats->IsDisposed)
				{
					stats->BringToFront();
					stats->Location = Point(this->Right, this->Top + 31);
				}
			}

		static void DrawGraphs()
		{
			g->Clear(bgColor);
			for each (auto graph in Graphs)
			{
				graph->DrawGraph();
			}
		}

		Vertex^ checkVertices(Point pos)
		{
			for each (auto graph in Graphs)
				for each (auto vertex in graph->Vertices)
					if (vertex->isClicked(pos))
						return vertex;
			return nullptr;
		}

		bool checkDrawableVertices(Point pos, int r)
		{
			for each (auto graph in Graphs)
				for each (auto vertex in graph->Vertices)
					if (vertex->isDrawable(pos, r))
						return true;
			return false;
		}

		bool checkIfYouCanMoveVertex(Point pos, Vertex^ v)
		{
			for each(auto graph in Graphs)
				for each(auto vertex in graph->Vertices)
				{
					if (vertex == v)
						continue;
					if (vertex->isDrawable(pos, v->r))
						return true;
				}
			return false;
		}

		bool doesEdgeExist(Vertex^ v1, Vertex^ v2)
		{
			Edge^ edge = gcnew Edge(v1, v2, Width);
			for each (auto graph in Graphs)
				for each (auto e in graph->Edges)
					if (e == edge)
						return true;
			return false;
		}
		// I HAVE NO IDEA HOW THIS SHIT WORKS I STOLE IT
		//
		//
		// IT WORKS THO
		static void RebuildGraphs()
		{
			List<Vertex^>^ allVertices = gcnew List<Vertex^>();
			List<Edge^>^ allEdges = gcnew List<Edge^>();

			Dictionary<Vertex^, Graph^>^ originalGraph = gcnew Dictionary<Vertex^, Graph^>();
			Dictionary<Graph^, int>^ componentCount = gcnew Dictionary<Graph^, int>();

			for each (auto g in Graphs)
			{
				componentCount[g] = 0;

				for each (auto v in g->Vertices)
				{
					allVertices->Add(v);
					originalGraph[v] = g;
				}

				for each (auto e in g->Edges)
					allEdges->Add(e);
			}

			Dictionary<Vertex^, List<Vertex^>^>^ adj = gcnew Dictionary<Vertex^, List<Vertex^>^>();
			for each (auto v in allVertices)
				adj[v] = gcnew List<Vertex^>();

			for each (auto e in allEdges)
			{
				adj[e->vertex1]->Add(e->vertex2);
				adj[e->vertex2]->Add(e->vertex1);
			}

			Graphs->Clear();
			HashSet<Vertex^>^ visited = gcnew HashSet<Vertex^>();

			for each (auto start in allVertices)
			{
				if (visited->Contains(start))
					continue;

				Graph^ oldGraph = originalGraph[start];
				componentCount[oldGraph]++;

				Color color;

				if (componentCount[oldGraph] == 1)
					color = oldGraph->color;
				else
					color = RandomColor();

				Graph^ newGraph = gcnew Graph(color);

				Stack<Vertex^>^ stack = gcnew Stack<Vertex^>();
				stack->Push(start);
				visited->Add(start);

				while (stack->Count > 0)
				{
					Vertex^ v = stack->Pop();
					newGraph->Vertices->Add(v);

					for each (auto neighbor in adj[v])
					{
						if (!visited->Contains(neighbor))
						{
							visited->Add(neighbor);
							stack->Push(neighbor);
						}
					}
				}
				for each (auto e in allEdges)
					if (newGraph->Vertices->Contains(e->vertex1) && newGraph->Vertices->Contains(e->vertex2))
						newGraph->Edges->Add(e);
				Graphs->Add(newGraph);
			}
		}

		static void RenumberVertices(int DeletedVertexIndex)
		{
			for each (auto graph in Graphs)
				for each (auto vertex in graph->Vertices)
					if (vertex->N > DeletedVertexIndex)
						vertex->N--;
		}

		static Color RandomColor()
		{
			return Color::FromArgb(rnd->Next(256), rnd->Next(256), rnd->Next(256));
		}

		static Graph^ findGraphByVertex(Vertex^ vertex)
		{
			for each (auto graph in Graphs)
				if (graph->Vertices->Contains(vertex))
					return graph;
			return nullptr;
		}

		static Graph^ findGraphByEdge(Edge^ edge)
		{
			for each (auto graph in Graphs)
				for each (auto e in graph->Edges)
					if (e == edge)
						return graph;
			return nullptr;
		}

		void MergeGraphs(Graph^ graph1, Graph^ graph2)
		{
			if (graph1 == graph2)
				return;
			for each (auto vertex in graph2->Vertices)
				graph1->Vertices->Add(vertex);
			for each (auto edge in graph2->Edges)
				graph1->Edges->Add(edge);
			Graphs->Remove(graph2);
			graph1->DrawGraph();
		}

		Vertex^ prevVertex;
		Graph^ prevGraph;	
		void panelDraw_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			auto pos = e->Location;
			Vertex^ vertex = checkVertices(pos);
			if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				if (drawingState == DrawingState::Deleting)
				{
					return;
				}
				else if (drawingState == DrawingState::Vertex)
				{
					if (vertex == nullptr)
					{
						if (checkDrawableVertices(pos, R))
							return;
						Graph^ graph = gcnew Graph();
						vertex = gcnew Vertex(pos);
						graph->Vertices->Add(vertex);
						Graphs->Add(graph);
						DrawGraphs();
					}
					else
					{
						prevVertex = vertex;
						vertex->Draw(Color::Red);
						drawingState = DrawingState::EdgeStart;
					}
				}
				else if (drawingState == DrawingState::EdgeStart)
				{
					if (vertex == nullptr)
					{
						if (checkIfYouCanMoveVertex(pos, prevVertex))
							return;
						prevVertex->coord = pos;
						DrawGraphs();
						drawingState = DrawingState::Vertex;
						return;
					}
					if (vertex == prevVertex || doesEdgeExist(prevVertex, vertex))
					{
						drawingState = DrawingState::Vertex;
						DrawGraphs();
						return;
					}

					Edge^ edge = gcnew Edge(prevVertex, vertex, Width);
					Graph^ graph = findGraphByVertex(edge->vertex1);
					Graph^ graph2 = findGraphByVertex(edge->vertex2);
					MergeGraphs(graph, graph2);
					graph->Edges->Add(edge);
					drawingState = DrawingState::Vertex;
					DrawGraphs();
					return;
				}
			}
			else if (e->Button == System::Windows::Forms::MouseButtons::Right)
			{
				if (vertex == nullptr || drawingState == DrawingState::EdgeStart)
					return;
				else if (drawingState == DrawingState::Vertex)
				{
					prevVertex = vertex;
					prevGraph = findGraphByVertex(vertex);
					vertex->Draw(Color::Red);
					drawingState = DrawingState::Deleting;
				}
				else if (drawingState == DrawingState::Deleting)
				{
					if (vertex == prevVertex)
					{
						prevGraph->DeleteVertex(vertex);
						drawingState = DrawingState::Vertex;
						DrawGraphs();
						return;
					}
					Graph^ graph = findGraphByVertex(vertex);
					if (graph == prevGraph && doesEdgeExist(prevVertex, vertex))
					{
						graph->DeleteEdge(gcnew Edge(prevVertex, vertex, Width));
						DrawGraphs();
					}
					else
						return;
					drawingState = DrawingState::Vertex;
				}
			}
		}

		#pragma region IO
		void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				StreamWriter^ writer = gcnew StreamWriter(saveFileDialog1->FileName);
				writer->WriteLine(Graphs->Count);
				for (int i = 0; i < Graphs->Count; i++)
				{
					writer->WriteLine(Graphs[i]->color.ToArgb());
					writer->WriteLine(Graphs[i]->Vertices->Count);
					for (int j = 0; j < Graphs[i]->Vertices->Count; j++)
					{
						writer->WriteLine(Graphs[i]->Vertices[j]->coord.X + " " + Graphs[i]->Vertices[j]->coord.Y);
						writer->WriteLine(Graphs[i]->Vertices[j]->r);
						writer->WriteLine(Graphs[i]->Vertices[j]->N);
					}
					writer->WriteLine(Graphs[i]->Edges->Count);
					for(int j = 0; j < Graphs[i]->Edges->Count; j++)
					{
						int v1Index = Graphs[i]->Vertices->IndexOf(Graphs[i]->Edges[j]->vertex1);
						int v2Index = Graphs[i]->Vertices->IndexOf(Graphs[i]->Edges[j]->vertex2);
						writer->WriteLine(v1Index + " " + v2Index);
						writer->WriteLine(Graphs[i]->Edges[j]->width);
					}
				}
				writer->Close();
			}
		}

		void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName);
				int graphCount = Convert::ToInt32(reader->ReadLine());
				Graphs->Clear();
				for (int i = 0; i < graphCount; i++)
				{
					Graph^ graph = gcnew Graph();
					graph->color = Color::FromArgb(Convert::ToInt32(reader->ReadLine()));
					int vertexCount = Convert::ToInt32(reader->ReadLine());
					for (int j = 0; j < vertexCount; j++)
					{
						array<String^>^ coords = reader->ReadLine()->Split(' ');
						int x = Convert::ToInt32(coords[0]);
						int y = Convert::ToInt32(coords[1]);
						int r = Convert::ToInt32(reader->ReadLine());
						int n = Convert::ToInt32(reader->ReadLine());
						graph->Vertices->Add(gcnew Vertex(x, y, n, r));
					}
					int edgeCount = Convert::ToInt32(reader->ReadLine());
					for (int j = 0; j < edgeCount; j++)
					{
						array<String^>^ indices = reader->ReadLine()->Split(' ');
						int v1Index = Convert::ToInt32(indices[0]);
						int v2Index = Convert::ToInt32(indices[1]);
						int width = Convert::ToInt32(reader->ReadLine());
						graph->Edges->Add(gcnew Edge(graph->Vertices[v1Index], graph->Vertices[v2Index], width));
					}
					Graphs->Add(graph);
				}
				reader->Close();
				DrawGraphs();
			}
		}
		#pragma endregion

		void changeColor_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (colorDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				randomColor = false;
				randomColorToolStripMenuItem->Checked = false;
				currentColor = colorDialog1->Color;
			}
		}

		void randomColor_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			randomColor = !randomColor;
		}

		void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) 
		{
			bool changed = false;
			List<Label^>^ labels = stats->Labels;
			for (int i = 0; i < Graphs->Count; i++)
			{
				if (i >= stats->Labels->Count)
				{
					Label^ label = gcnew Label();
					label->AutoSize = true;
					label->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 15);
					label->Location = Point(10, 10 + 20 * i);
					labels->Add(label);
					changed = true;
				}
				if (labels[i]->Text != "Graph " + (i + 1) + ": " + Graphs[i]->Vertices->Count + " vertices, " + Graphs[i]->Edges->Count + " edges")
				{
					changed = true;
					labels[i]->Text = "Graph " + (i + 1) + ": " + Graphs[i]->Vertices->Count + " vertices, " + Graphs[i]->Edges->Count + " edges";
				}
				labels[i]->BackColor = Graphs[i]->color;
			}
			if (labels->Count > Graphs->Count)
			{
				labels->RemoveRange(Graphs->Count, labels->Count - Graphs->Count);
				changed = true;
			}
			if (changed)
				stats->SetLabels(labels);
		}
		void changeRadius_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			ChangeRadiusForm^ form = gcnew ChangeRadiusForm();
			if (form->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				R = form->R;
				DrawGraphs();
			}
		}
		void generateGraph_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			RandomGraphGeneratorForm^ form = gcnew RandomGraphGeneratorForm();
			if (form->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				GenerateGraph(form->VertexN, form->EdgeN);
			}
		}
		static Graph^tempGraph = gcnew Graph();
		void GenerateGraph(int vertexN, int edgeN)
		{
			tempGraph = gcnew Graph();
			for (int i = 0; i < vertexN; i++)
			{
				int x, y;
				bool valid;
				int attempts = 0;
				do
				{
					x = rnd->Next(R, panelDraw->Width - R);
					y = rnd->Next(R, panelDraw->Height - R);

					valid = true;

					for each (auto v in tempGraph->Vertices)
					{
						double dist = hypot(v->coord.X - x, v->coord.Y - y);
						if (dist < R * 1.5)
						{
							valid = false;
							break;
						}
					}

					if (valid)
					{
						for each (auto g in Graphs)
						{
							for each (auto v in g->Vertices)
							{
								double dist = hypot(v->coord.X - x, v->coord.Y - y);
								if (dist < R * 1.5)
								{
									valid = false;
									break;
								}
							}
							if (!valid) break;
						}
					}
					attempts++;
					if (attempts > 1000)
						break;
				} while (!valid);
				tempGraph->Vertices->Add(gcnew Vertex(x, y));
			}
			for (int i = 0; i < edgeN; i++)
			{
				Vertex^ v1, ^v2;
				do
				{
					v1 = tempGraph->Vertices[rnd->Next(vertexN)];
					v2 = tempGraph->Vertices[rnd->Next(vertexN)];
				} while (v1 == v2 || doesEdgeExist(v1, v2));
				tempGraph->Edges->Add(gcnew Edge(v1, v2, Width));
			}
			Graphs->Add(tempGraph);
			RebuildGraphs();
			DrawGraphs();
		}

private: System::Void orientedGraphsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	isOriented = !isOriented;
	DrawGraphs();
}
private: System::Void changeWidthToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	ChangeRadiusForm^ form = gcnew ChangeRadiusForm();
	form->labelName->Text = "Choose a new width for edges";
	form->Text = "change da width yo";
	if (form->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		Width = form->R;
		DrawGraphs();
	}
}
private: System::Void newToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Graphs->Clear();
	DrawGraphs();	
}
};
}
