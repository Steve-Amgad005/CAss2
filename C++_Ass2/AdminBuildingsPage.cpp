#include "AdminBuildingsPage.h"
#include "AdminPage.h"
using namespace System;
using namespace System::Windows::Forms;

namespace CAss2 {
System::Void AdminBuildingsPage::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	AdminPage^ admin = gcnew AdminPage(AdminCode);
	AdminBuildingsPage::CloseCurrentPopup();
	admin->Show();
	this->Close();
}
}
