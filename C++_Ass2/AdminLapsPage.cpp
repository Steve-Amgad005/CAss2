#include "AdminLapsPage.h"
#include "AdminPage.h"
using namespace System;
using namespace System::Windows::Forms;

namespace CAss2 {
 System::Void AdminLapsPage::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	 AdminPage^ admin = gcnew AdminPage();
	 admin->Show();
	 this->Close();
}
}
