#pragma once

namespace GraphBuilder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChangeRadiusForm
	/// </summary>
	public ref class ChangeRadiusForm : public System::Windows::Forms::Form
	{
	public:
		ChangeRadiusForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChangeRadiusForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Button^ buttonConfirm;
	private: System::Windows::Forms::Button^ buttonCancel;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->buttonConfirm = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->textBox1->Location = System::Drawing::Point(12, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(247, 32);
			this->textBox1->TabIndex = 0;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ChangeRadiusForm::textBoxKeyPress);
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->labelName->Location = System::Drawing::Point(8, 3);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(261, 22);
			this->labelName->TabIndex = 1;
			this->labelName->Text = L"Choose a new radius (in pixels)";
			// 
			// buttonConfirm
			// 
			this->buttonConfirm->Location = System::Drawing::Point(184, 76);
			this->buttonConfirm->Name = L"buttonConfirm";
			this->buttonConfirm->Size = System::Drawing::Size(75, 23);
			this->buttonConfirm->TabIndex = 3;
			this->buttonConfirm->Text = L"OK";
			this->buttonConfirm->UseVisualStyleBackColor = true;
			this->buttonConfirm->Click += gcnew System::EventHandler(this, &ChangeRadiusForm::buttonConfirm_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(12, 76);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 4;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// ChangeRadiusForm
			// 
			this->AcceptButton = this->buttonConfirm;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(271, 111);
			this->ControlBox = false;
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonConfirm);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->textBox1);
			this->Name = L"ChangeRadiusForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"change da radius";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			public:
				int R;
			private:

	private: System::Void buttonConfirm_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		try
		{
			R = Convert::ToInt32(textBox1->Text);
			this->DialogResult = Windows::Forms::DialogResult::OK;
			this->Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Please enter a valid integer for the radius.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void textBoxKeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
	{
		if ((e->KeyChar < '0' || e->KeyChar > '9') && e->KeyChar != 8) // Allow digits and backspace
		{
			e->Handled = true;
			return;
		}
		if (e->KeyChar == '0' && textBox1->Text->Length == 0)
		{
			e->Handled = true;
			return;
		}
	}
};
}
