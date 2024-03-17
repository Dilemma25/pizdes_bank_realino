#include "AdminMenu2.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int cmain(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	BankProj::AdminMenu2 form;
	Application::Run(% form);
	return 0;
}