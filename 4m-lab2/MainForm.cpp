#include "MainForm.h"
#include "TableTestU.h"
#include "ErrorsTest.h"
#include "ErrorsMain.h"
#include "TableMainVS2.h"

using namespace My4mlab2;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    My4mlab2::MainForm form;
    Application::Run(%form);
}

System::Void My4mlab2::MainForm::button_testU_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    My4mlab2::TableTestU form_testU;
    form_testU.ShowDialog();
}

System::Void My4mlab2::MainForm::button_testErrors_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    My4mlab2::ErrorsTest form_testErrors;
    form_testErrors.ShowDialog();
}

System::Void My4mlab2::MainForm::button_mainVS2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    My4mlab2::TableMainVS2 form_mainVS2;
    form_mainVS2.ShowDialog();
}

System::Void My4mlab2::MainForm::button_mainErrors_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    My4mlab2::ErrorsMain form_mainErrors;
    form_mainErrors.ShowDialog();
}
