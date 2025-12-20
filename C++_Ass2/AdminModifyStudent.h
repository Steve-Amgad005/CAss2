#pragma once

namespace CAss2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for AdminModifyStudent
	/// </summary>
	public ref class AdminModifyStudent : public System::Windows::Forms::Form
	{
		int currentStudentId = -1;

		void LoadDeptsInCMB() {
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";

			SqlConnection^ conn = gcnew SqlConnection(connStr);

			try
			{
				conn->Open();

				SqlDataAdapter^ da = gcnew SqlDataAdapter(
					"SELECT id, name FROM Departments",
					conn);

				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				cmbDepartment->DataSource = dt;
				cmbDepartment->DisplayMember = "name"; // اللي هيظهر
				cmbDepartment->ValueMember = "id";     // اللي هيتخزن
				cmbDepartment->SelectedIndex = -1;     // مفيش اختيار افتراضي

				conn->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Error");
			}
		}
	public:
		AdminModifyStudent(void)
		{
			InitializeComponent();
			LoadDeptsInCMB();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminModifyStudent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cmbYear;

	private: System::Windows::Forms::ComboBox^ cmbDepartment;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtNID;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtName;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txtStudentCode;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ComboBox^ cmbFeesStatus;
	private: System::Windows::Forms::TextBox^ txtFees;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtFees = (gcnew System::Windows::Forms::TextBox());
			this->cmbFeesStatus = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtStudentCode = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbYear = (gcnew System::Windows::Forms::ComboBox());
			this->cmbDepartment = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtNID = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(119, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(270, 39);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Update Student";
			this->label2->Click += gcnew System::EventHandler(this, &AdminModifyStudent::label2_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->txtFees);
			this->panel1->Controls->Add(this->cmbFeesStatus);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->txtStudentCode);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->cmbYear);
			this->panel1->Controls->Add(this->cmbDepartment);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtNID);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->txtName);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Location = System::Drawing::Point(40, 86);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 512);
			this->panel1->TabIndex = 2;
			// 
			// txtFees
			// 
			this->txtFees->Location = System::Drawing::Point(192, 391);
			this->txtFees->Multiline = true;
			this->txtFees->Name = L"txtFees";
			this->txtFees->Size = System::Drawing::Size(214, 33);
			this->txtFees->TabIndex = 33;
			// 
			// cmbFeesStatus
			// 
			this->cmbFeesStatus->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbFeesStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbFeesStatus->FormattingEnabled = true;
			this->cmbFeesStatus->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Paid", L"Unpaid" });
			this->cmbFeesStatus->Location = System::Drawing::Point(104, 391);
			this->cmbFeesStatus->Name = L"cmbFeesStatus";
			this->cmbFeesStatus->Size = System::Drawing::Size(82, 33);
			this->cmbFeesStatus->TabIndex = 32;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Purple;
			this->button3->Location = System::Drawing::Point(226, 65);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(123, 33);
			this->button3->TabIndex = 31;
			this->button3->Text = L"Show";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdminModifyStudent::button3_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(25, 29);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(125, 24);
			this->label8->TabIndex = 29;
			this->label8->Text = L"Student Code";
			// 
			// txtStudentCode
			// 
			this->txtStudentCode->Location = System::Drawing::Point(192, 26);
			this->txtStudentCode->Multiline = true;
			this->txtStudentCode->Name = L"txtStudentCode";
			this->txtStudentCode->Size = System::Drawing::Size(214, 33);
			this->txtStudentCode->TabIndex = 30;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Purple;
			this->button1->Location = System::Drawing::Point(192, 336);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(214, 33);
			this->button1->TabIndex = 27;
			this->button1->Text = L"Choose Picture";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(25, 336);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 24);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Picture";
			// 
			// cmbYear
			// 
			this->cmbYear->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbYear->FormattingEnabled = true;
			this->cmbYear->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"First Year", L"Second Year", L"Third Year", L"Fourth Year" });
			this->cmbYear->Location = System::Drawing::Point(192, 278);
			this->cmbYear->Name = L"cmbYear";
			this->cmbYear->Size = System::Drawing::Size(214, 33);
			this->cmbYear->TabIndex = 25;
			// 
			// cmbDepartment
			// 
			this->cmbDepartment->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDepartment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbDepartment->FormattingEnabled = true;
			this->cmbDepartment->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ICT", L"Petrol", L"Mechatronics", L"Autotronics",
					L"Renewable Energy"
			});
			this->cmbDepartment->Location = System::Drawing::Point(192, 227);
			this->cmbDepartment->Name = L"cmbDepartment";
			this->cmbDepartment->Size = System::Drawing::Size(214, 33);
			this->cmbDepartment->TabIndex = 24;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(25, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 24);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Full Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(25, 176);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 24);
			this->label4->TabIndex = 16;
			this->label4->Text = L"NID";
			// 
			// txtNID
			// 
			this->txtNID->Location = System::Drawing::Point(192, 177);
			this->txtNID->Multiline = true;
			this->txtNID->Name = L"txtNID";
			this->txtNID->Size = System::Drawing::Size(214, 33);
			this->txtNID->TabIndex = 22;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(25, 231);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(107, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Department";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(192, 130);
			this->txtName->Multiline = true;
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(214, 33);
			this->txtName->TabIndex = 23;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(25, 282);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 24);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Year";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(104, 445);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Modify";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminModifyStudent::button2_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(25, 395);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 24);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Fees";
			// 
			// AdminModifyStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 621);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Name = L"AdminModifyStudent";
			this->Text = L"AdminModifyStudent";
			this->Load += gcnew System::EventHandler(this, &AdminModifyStudent::AdminModifyStudent_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void AdminModifyStudent_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(txtStudentCode->Text))
	{
		MessageBox::Show("Please enter student code", "Validation Error");
		return;
	}

	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	try
	{
		conn->Open();

		String^ query =
			"SELECT s.id, s.name, s.NationalNumber, s.year, s.department_id, "
			"       p.amount, p.status "
			"FROM Students s "
			"LEFT JOIN Payments p ON p.student_id = s.id "
			"WHERE s.code = @code";

		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		cmd->Parameters->AddWithValue("@code", Convert::ToInt32(txtStudentCode->Text));

		SqlDataReader^ dr = cmd->ExecuteReader();

		if (!dr->Read())
		{
			MessageBox::Show("Student not found", "Error");
			dr->Close();
			conn->Close();
			return;
		}

		// ==========================
		// تعبئة البيانات
		// ==========================
		currentStudentId = Convert::ToInt32(dr["id"]);
		txtName->Text = dr["name"]->ToString();
		txtNID->Text = dr["NationalNumber"]->ToString();

		// السنة
		int year = Convert::ToInt32(dr["year"]);
		if (year == 1) cmbYear->Text = "First Year";
		else if (year == 2) cmbYear->Text = "Second Year";
		else if (year == 3) cmbYear->Text = "Third Year";
		else if (year == 4) cmbYear->Text = "Fourth Year";

		// القسم
		cmbDepartment->SelectedValue = Convert::ToInt32(dr["department_id"]);

		// المصاريف
		if (dr["status"] != DBNull::Value)
		{
			cmbFeesStatus->Text = dr["status"]->ToString();
			txtFees->Text = dr["amount"]->ToString();
		}
		else
		{
			cmbFeesStatus->SelectedIndex = -1;
			txtFees->Clear();
		}

		dr->Close();
		conn->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Error");
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentStudentId == -1)
	{
		MessageBox::Show("Please search student first", "Error");
		return;
	}

	// ==========================
	// Validation
	// ==========================
	if (String::IsNullOrWhiteSpace(txtName->Text))
	{
		MessageBox::Show("Enter student name", "Validation Error");
		return;
	}

	if (String::IsNullOrWhiteSpace(txtNID->Text) || txtNID->Text->Length != 14)
	{
		MessageBox::Show("Invalid National ID", "Validation Error");
		return;
	}

	int year = 0;
	if (cmbYear->Text == "First Year") year = 1;
	else if (cmbYear->Text == "Second Year") year = 2;
	else if (cmbYear->Text == "Third Year") year = 3;
	else if (cmbYear->Text == "Fourth Year") year = 4;
	else
	{
		MessageBox::Show("Select valid year", "Validation Error");
		return;
	}

	if (cmbDepartment->SelectedIndex == -1)
	{
		MessageBox::Show("Select department", "Validation Error");
		return;
	}

	if (cmbFeesStatus->SelectedIndex == -1)
	{
		MessageBox::Show("Select fees status", "Validation Error");
		return;
	}

	int fees = 0;
	if (cmbFeesStatus->Text == "Paid")
	{
		if (!Int32::TryParse(txtFees->Text, fees) || fees > 155000)
		{
			MessageBox::Show("Invalid fees amount", "Validation Error");
			return;
		}
	}

	// ==========================
	// Update DB
	// ==========================
	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	try
	{
		conn->Open();

		// -------- Update Students
		String^ updateStudent =
			"UPDATE Students SET "
			"name = @name, "
			"NationalNumber = @nid, "
			"year = @year, "
			"department_id = @dept "
			"WHERE id = @id";

		SqlCommand^ cmdStd = gcnew SqlCommand(updateStudent, conn);
		cmdStd->Parameters->AddWithValue("@name", txtName->Text);
		cmdStd->Parameters->AddWithValue("@nid", txtNID->Text);
		cmdStd->Parameters->AddWithValue("@year", year);
		cmdStd->Parameters->AddWithValue("@dept", cmbDepartment->SelectedValue);
		cmdStd->Parameters->AddWithValue("@id", currentStudentId);
		cmdStd->ExecuteNonQuery();

		// -------- Update Payments
		String^ updateFees =
			"UPDATE Payments SET "
			"amount = @amount, "
			"status = @status "
			"WHERE student_id = @sid";

		SqlCommand^ cmdFees = gcnew SqlCommand(updateFees, conn);
		cmdFees->Parameters->AddWithValue("@sid", currentStudentId);
		cmdFees->Parameters->AddWithValue("@amount", fees);
		cmdFees->Parameters->AddWithValue("@status", cmbFeesStatus->Text);
		cmdFees->ExecuteNonQuery();

		MessageBox::Show("Student updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		conn->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Error");
	}
}
};
}
