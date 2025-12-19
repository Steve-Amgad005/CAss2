#include "AdminDepartmentPage.h"
#include "AdminPage.h"

using namespace System;
using namespace System::Windows::Forms;

namespace CAss2 {
	System::Void AdminDepartmentPage::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CAss2::AdminPage^ admin = gcnew CAss2::AdminPage(AdminCode);
		admin->Show();
		this->Hide();
	}
}

