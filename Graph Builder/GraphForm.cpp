#include "GraphForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace GraphBuilder;

[STAThread]
int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew GraphForm);
	return 0;
}