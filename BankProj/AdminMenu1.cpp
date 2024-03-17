#include "AdminMenu1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int amain(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	BankProj::AdminMenu1 form;
	Application::Run(% form);
	return 0;
}