#pragma once
#include <windows.h>
#include <cmath>

namespace GraphBuilder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;

	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panelDraw = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelDraw->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelDraw
			// 
			this->panelDraw->Controls->Add(this->label1);
			this->panelDraw->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelDraw->Location = System::Drawing::Point(0, 0);
			this->panelDraw->Name = L"panelDraw";
			this->panelDraw->Size = System::Drawing::Size(1264, 681);
			this->panelDraw->TabIndex = 0;
			this->panelDraw->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphForm::panelDraw_MouseDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(436, 213);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// timer1
			// 
			this->timer1->Interval = 25;
			this->timer1->Tick += gcnew System::EventHandler(this, &GraphForm::timer1_Tick);
			// 
			// GraphForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->panelDraw);
			this->Name = L"GraphForm";
			this->Text = L"GraphForm";
			this->Load += gcnew System::EventHandler(this, &GraphForm::GraphForm_Load);
			this->panelDraw->ResumeLayout(false);
			this->panelDraw->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		static Graphics^ g;
		static int R = 30;
		static Color bgColor;

		enum class DrawingState
		{
			Vertex,
			EdgeStart,
		};

		static DrawingState drawingState = DrawingState::Vertex;

		ref class Vertex
		{
		public:
			Point coord;
			int r;
			List<Vertex^>^ ConnectedVertices = gcnew List<Vertex^>();
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
			void Draw(Color colorV, Color colorE)
			{
				Pen^ pen = gcnew Pen(colorE);
				vertex1->Draw(colorV);
				vertex2->Draw(colorV);
				g->DrawLine(pen, vertex1->coord, vertex2->coord);
			}
		private:

		};

		List<Vertex^>^ Vertices = gcnew List<Vertex^>();
		int Nv = 0;
		List<Edge^>^ Edges = gcnew List<Edge^>();
		int Ne = 0;

		void GraphForm_Load(System::Object^ sender, System::EventArgs^ e)
		{
			g = panelDraw->CreateGraphics();
			bgColor = panelDraw->BackColor;
		}

		Vertex^ checkVertices(Point pos)
		{
			for each (auto v in Vertices)
				if (v->isClicked(pos))
					return v;
			return nullptr;
		}

		void panelDraw_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			auto mousePos = Cursor->Position;
			auto relativePos = panelDraw->PointToClient(mousePos);
			Vertex^ vertex = checkVertices(relativePos);
			if (vertex == nullptr)
			{
				vertex = gcnew Vertex(relativePos);
				Vertices->Add(vertex);
				vertex->Draw(Color::Black);
				Nv++;
			}
			else if (drawingState == DrawingState::Vertex)
			{
				Edge^ newEdge = gcnew Edge(vertex, nullptr);
				Edges->Add(newEdge);
				Ne++;
				vertex->Draw(Color::Red);
				drawingState = DrawingState::EdgeStart;

			}
			else
			{
				auto edge = Edges[Ne - 1];
				edge->vertex2 = vertex;
				edge->vertex2->ConnectedVertices->Add(vertex);
				edge->vertex1->ConnectedVertices->Add(edge->vertex2);
				edge->Draw(Color::Black, Color::Black);
				drawingState = DrawingState::Vertex;
			}
		}

		Vertex^ prevVertex = gcnew Vertex(0, 0);
		void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			prevVertex->Clear();
			auto mousePos = Cursor->Position;
			auto relativePos = panelDraw->PointToClient(mousePos);
			Vertex^ shadowVertex = gcnew Vertex(relativePos);
			prevVertex = shadowVertex;
			label1->Text = relativePos.X.ToString() + " " + relativePos.Y.ToString();
			shadowVertex->Draw(Color::FromArgb(100, Color::Black));
		}
	};
}
