#pragma once
#include <windows.h>
#include <cmath>
#using <System.Core.dll>
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
	private: System::Windows::Forms::ToolStripMenuItem^ optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ colorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomColorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ refreshToolStripMenuItem;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;































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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->refreshToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->panelDraw->Controls->Add(this->label3);
			this->panelDraw->Controls->Add(this->label2);
			this->panelDraw->Controls->Add(this->label1);
			this->panelDraw->Controls->Add(this->menuStrip1);
			this->panelDraw->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelDraw->Location = System::Drawing::Point(0, 0);
			this->panelDraw->Name = L"panelDraw";
			this->panelDraw->Size = System::Drawing::Size(1264, 681);
			this->panelDraw->TabIndex = 0;
			this->panelDraw->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphForm::panelDraw_MouseDown);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1104, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->optionsToolStripMenuItem, this->refreshToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1264, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripMenuItem.Image")));
			this->openToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->openToolStripMenuItem->Text = L"&Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveToolStripMenuItem.Image")));
			this->saveToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->saveToolStripMenuItem->Text = L"&Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::saveToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->randomColorToolStripMenuItem,
					this->colorToolStripMenuItem
			});
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// randomColorToolStripMenuItem
			// 
			this->randomColorToolStripMenuItem->Checked = true;
			this->randomColorToolStripMenuItem->CheckOnClick = true;
			this->randomColorToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->randomColorToolStripMenuItem->Name = L"randomColorToolStripMenuItem";
			this->randomColorToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->randomColorToolStripMenuItem->Text = L"Random color";
			this->randomColorToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::randomColorToolStripMenuItem_Click);
			// 
			// colorToolStripMenuItem
			// 
			this->colorToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"colorToolStripMenuItem.Image")));
			this->colorToolStripMenuItem->Name = L"colorToolStripMenuItem";
			this->colorToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->colorToolStripMenuItem->Text = L"Choose Color";
			this->colorToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::colorToolStripMenuItem_Click);
			// 
			// refreshToolStripMenuItem
			// 
			this->refreshToolStripMenuItem->Name = L"refreshToolStripMenuItem";
			this->refreshToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->refreshToolStripMenuItem->Text = L"Refresh";
			this->refreshToolStripMenuItem->Click += gcnew System::EventHandler(this, &GraphForm::refreshToolStripMenuItem_Click);
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
			this->Text = L"GraphForm";
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
		static bool randomColor = true;
		static Color bgColor;
		static Color currentColor = Color::Black;
		static Random^ rnd = gcnew Random();
		enum class DrawingState
		{
			Vertex,
			EdgeStart,
			Deleting,
		};

		static DrawingState drawingState = DrawingState::Vertex;

		ref class Vertex
		{
		public:
			Point coord;
			int r;
			Vertex(int x, int y)
			{
				coord.X = x;
				coord.Y = y;
				r = R;
			}
			Vertex(Point pos)
			{
				coord.X = pos.X;
				coord.Y = pos.Y;
				r = R;
			}
			void Draw(Color color)
			{
				Brush^ brush = gcnew SolidBrush(color);
				g->FillEllipse(brush, coord.X - r / 2, coord.Y - r / 2, r, r);
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

			bool isDrawable(Point pos)
			{
				if (hypot(coord.X - pos.X, coord.Y - pos.Y) <= r)
					return true;
				return false;
			}
		};

		ref class Edge
		{
		public:
			Vertex^ vertex1;
			Vertex^ vertex2;
			Edge(Vertex^ v1, Vertex^ v2)
			{
				vertex1 = v1;
				vertex2 = v2;
			}

			bool operator==(Edge^ other)
			{
				return (vertex1 == other->vertex1 && vertex2 == other->vertex2) || (vertex1 == other->vertex2 && vertex2 == other->vertex1);
			}

			void Draw(Color colorV, Color colorE)
			{
				Pen^ pen = gcnew Pen(colorE);
				vertex1->Draw(colorV);
				vertex2->Draw(colorV);
				g->DrawLine(pen, vertex1->coord, vertex2->coord);
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
				if (Vertices->Count == 0)
				{
					Graphs->Remove(this);
				}
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

		static List<Graph^>^ Graphs = gcnew List<Graph^>();
		void GraphForm_Load(System::Object^ sender, System::EventArgs^ e)
		{
			g = panelDraw->CreateGraphics();
			bgColor = panelDraw->BackColor;
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

		bool checkDrawableVertices(Point pos)
		{
			for each (auto graph in Graphs)
				for each (auto vertex in graph->Vertices)
					if (vertex->isDrawable(pos))
						return true;
			return false;
		}

		bool doesEdgeExist(Vertex^ v1, Vertex^ v2)
		{
			Edge^ edge = gcnew Edge(v1, v2);
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

			for each (auto g in Graphs)
			{
				for each (auto v in g->Vertices)
					allVertices->Add(v);

				for each (auto e in g->Edges)
					allEdges->Add(e);
			}

			Graphs->Clear();

			HashSet<Vertex^>^ visited = gcnew HashSet<Vertex^>();

			for each (auto start in allVertices)
			{
				if (visited->Contains(start))
					continue;

				Graph^ newGraph = gcnew Graph();
				Stack<Vertex^>^ stack = gcnew Stack<Vertex^>();

				stack->Push(start);
				visited->Add(start);

				while (stack->Count > 0)
				{
					Vertex^ v = stack->Pop();
					newGraph->Vertices->Add(v);

					for each (auto e in allEdges)
					{
						Vertex^ neighbor = nullptr;

						if (e->vertex1 == v)
							neighbor = e->vertex2;
						else if (e->vertex2 == v)
							neighbor = e->vertex1;

						if (neighbor != nullptr)
						{
							if (!newGraph->Edges->Contains(e))
								newGraph->Edges->Add(e);

							if (!visited->Contains(neighbor))
							{
								visited->Add(neighbor);
								stack->Push(neighbor);
							}
						}
					}
				}

				Graphs->Add(newGraph);
			}
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
						if (checkDrawableVertices(pos))
							return;
						Graph^ graph = gcnew Graph();
						vertex = gcnew Vertex(pos);
						graph->Vertices->Add(vertex);
						vertex->Draw(graph->color);
						Graphs->Add(graph);
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
						return;
					if (vertex == prevVertex || doesEdgeExist(prevVertex, vertex))
					{
						prevVertex->Draw(findGraphByVertex(prevVertex)->color);
						drawingState = DrawingState::Vertex;
					}
					Edge^ edge = gcnew Edge(prevVertex, vertex);
					Graph^ graph = findGraphByVertex(edge->vertex1);
					Graph^ graph2 = findGraphByVertex(edge->vertex2);
					MergeGraphs(graph, graph2);
					graph->Edges->Add(edge);
					edge->Draw(graph->color, graph->color);
					drawingState = DrawingState::Vertex;
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
						graph->DeleteEdge(gcnew Edge(prevVertex, vertex));
						DrawGraphs();
					}
					else
						return;
					drawingState = DrawingState::Vertex;
				}
			}
		}

	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
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
					writer->WriteLine(Graphs[i]->Vertices[j]->coord.X + " " + Graphs[i]->Vertices[j]->coord.Y);
				writer->WriteLine(Graphs[i]->Edges->Count);
				for(int j = 0; j < Graphs[i]->Edges->Count; j++)
				{
					int v1Index = Graphs[i]->Vertices->IndexOf(Graphs[i]->Edges[j]->vertex1);
					int v2Index = Graphs[i]->Vertices->IndexOf(Graphs[i]->Edges[j]->vertex2);
					writer->WriteLine(v1Index + " " + v2Index);
				}
			}
			writer->Close();
		}
	}

	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
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
					graph->Vertices->Add(gcnew Vertex(x, y));
				}
				int edgeCount = Convert::ToInt32(reader->ReadLine());
				for (int j = 0; j < edgeCount; j++)
				{
					array<String^>^ indices = reader->ReadLine()->Split(' ');
					int v1Index = Convert::ToInt32(indices[0]);
					int v2Index = Convert::ToInt32(indices[1]);
					graph->Edges->Add(gcnew Edge(graph->Vertices[v1Index], graph->Vertices[v2Index]));
				}
				Graphs->Add(graph);
			}
			reader->Close();
			DrawGraphs();
		}
	}
	private: System::Void colorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (colorDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			randomColor = false;
			randomColorToolStripMenuItem->Checked = false;
			currentColor = colorDialog1->Color;
		}
	}
	private: System::Void randomColorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		randomColor = !randomColor;
	}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void refreshToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	DrawGraphs();
}
private: System::Void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) 
{
	label1->Text = "Graphs: " + Graphs->Count;
	label2->Text = "";
	for each (auto graph in Graphs)
		label2->Text += "Vertices: " + graph->Vertices->Count + " Edges: " + graph->Edges->Count + " | ";
}
};
}
