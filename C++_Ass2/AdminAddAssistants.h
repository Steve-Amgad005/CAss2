#pragma once

namespace CAss2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Collections::Generic;




	/// <summary>
	/// Summary for AdminAddAssistants
	/// </summary>
	public ref class AdminAddAssistants : public System::Windows::Forms::Form
	{
		void LoadDepartments()
		{
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";

			SqlConnection^ conn = gcnew SqlConnection(connStr);
			SqlDataAdapter^ da = gcnew SqlDataAdapter("SELECT id, name FROM Departments", conn);

			DataTable^ dt = gcnew DataTable();
			da->Fill(dt);

			checkedListBoxDepartments->DataSource = dt;
			checkedListBoxDepartments->DisplayMember = "name";
			checkedListBoxDepartments->ValueMember = "id";
		}
	public:
		AdminAddAssistants(void)
		{
			InitializeComponent();
			LoadDepartments();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminAddAssistants()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtNID;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::CheckedListBox^ checkedListBoxCourses;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::CheckedListBox^ checkedListBoxDepartments;


	private: System::Windows::Forms::CheckedListBox^ checkedListBoxProfessors;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;

	protected:












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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtNID = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkedListBoxProfessors = (gcnew System::Windows::Forms::CheckedListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->checkedListBoxCourses = (gcnew System::Windows::Forms::CheckedListBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkedListBoxDepartments = (gcnew System::Windows::Forms::CheckedListBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(21, 35);
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
			this->label4->Location = System::Drawing::Point(21, 78);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 24);
			this->label4->TabIndex = 16;
			this->label4->Text = L"NID";
			// 
			// txtNID
			// 
			this->txtNID->Location = System::Drawing::Point(188, 79);
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
			this->label5->Location = System::Drawing::Point(21, 146);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(107, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Department";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(188, 32);
			this->txtName->Multiline = true;
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(214, 33);
			this->txtName->TabIndex = 23;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(102, 464);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminAddAssistants::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(147, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(243, 39);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Add Assistant";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->checkedListBoxProfessors);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->checkedListBoxCourses);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->checkedListBoxDepartments);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtNID);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->txtName);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(52, 132);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 550);
			this->panel1->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Purple;
			this->button1->Location = System::Drawing::Point(217, 324);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 33);
			this->button1->TabIndex = 38;
			this->button1->Text = L"Show Professors";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminAddAssistants::button1_Click);
			// 
			// checkedListBoxProfessors
			// 
			this->checkedListBoxProfessors->FormattingEnabled = true;
			this->checkedListBoxProfessors->Location = System::Drawing::Point(188, 374);
			this->checkedListBoxProfessors->Name = L"checkedListBoxProfessors";
			this->checkedListBoxProfessors->Size = System::Drawing::Size(214, 49);
			this->checkedListBoxProfessors->TabIndex = 36;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(21, 383);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(65, 24);
			this->label7->TabIndex = 37;
			this->label7->Text = L"Doctor";
			// 
			// checkedListBoxCourses
			// 
			this->checkedListBoxCourses->FormattingEnabled = true;
			this->checkedListBoxCourses->Location = System::Drawing::Point(188, 256);
			this->checkedListBoxCourses->Name = L"checkedListBoxCourses";
			this->checkedListBoxCourses->Size = System::Drawing::Size(214, 49);
			this->checkedListBoxCourses->TabIndex = 34;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(21, 265);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 24);
			this->label6->TabIndex = 35;
			this->label6->Text = L"Courses";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Purple;
			this->button3->Location = System::Drawing::Point(217, 205);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(148, 33);
			this->button3->TabIndex = 33;
			this->button3->Text = L"Show Courses";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdminAddAssistants::button3_Click);
			// 
			// checkedListBoxDepartments
			// 
			this->checkedListBoxDepartments->FormattingEnabled = true;
			this->checkedListBoxDepartments->Location = System::Drawing::Point(188, 136);
			this->checkedListBoxDepartments->Name = L"checkedListBoxDepartments";
			this->checkedListBoxDepartments->Size = System::Drawing::Size(214, 49);
			this->checkedListBoxDepartments->TabIndex = 6;
			// 
			// AdminAddAssistants
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 705);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Name = L"AdminAddAssistants";
			this->Text = L"AdminAddAssistants";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkedListBoxDepartments->CheckedItems->Count == 0)
		{
			MessageBox::Show("Select at least one department");
			return;
		}

		List<String^>^ deptIds = gcnew List<String^>();

		for each (Object ^ obj in checkedListBoxDepartments->CheckedItems)
		{
			DataRowView^ item = safe_cast<DataRowView^>(obj);
			deptIds->Add(item["id"]->ToString());
		}

		array<String^>^ arr = deptIds->ToArray();
		String^ inClause = String::Join(",", arr);

		String^ connStr =
			"Server=localhost\\SQLEXPRESS;"
			"Database=MyDB;"
			"Trusted_Connection=True;"
			"TrustServerCertificate=True;";

		SqlConnection^ conn = gcnew SqlConnection(connStr);

		String^ query =
			"SELECT DISTINCT c.id, c.course_name "
			"FROM Courses c "
			"INNER JOIN CourseDepartments cd ON c.id = cd.course_id "
			"WHERE cd.department_id IN (" + inClause + ")";

		SqlDataAdapter^ da = gcnew SqlDataAdapter(query, conn);
		DataTable^ dt = gcnew DataTable();
		da->Fill(dt);

		checkedListBoxCourses->DataSource = dt;
		checkedListBoxCourses->DisplayMember = "course_name";
		checkedListBoxCourses->ValueMember = "id";
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (checkedListBoxCourses->CheckedItems->Count == 0)
	{
		MessageBox::Show("Select at least one course");
		return;
	}

	List<String^>^ courseIds = gcnew List<String^>();

	for each (Object ^ obj in checkedListBoxCourses->CheckedItems)
	{
		DataRowView^ item = safe_cast<DataRowView^>(obj);
		courseIds->Add(item["id"]->ToString());
	}

	array<String^>^ arr = courseIds->ToArray();
	String^ inClause = String::Join(",", arr);

	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	String^ query =
		"SELECT DISTINCT p.id, p.name "
		"FROM Professors p "
		"INNER JOIN ProfessorCourses pc ON p.id = pc.professor_id "
		"WHERE pc.course_id IN (" + inClause + ")";

	SqlDataAdapter^ da = gcnew SqlDataAdapter(query, conn);
	DataTable^ dt = gcnew DataTable();
	da->Fill(dt);

	checkedListBoxProfessors->DataSource = dt;
	checkedListBoxProfessors->DisplayMember = "name";
	checkedListBoxProfessors->ValueMember = "id";
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// ================= Validation =================
	if (String::IsNullOrWhiteSpace(txtName->Text))
	{
		MessageBox::Show("Enter assistant name");
		return;
	}

	if (String::IsNullOrWhiteSpace(txtNID->Text) || txtNID->Text->Length != 14)
	{
		MessageBox::Show("Enter valid National ID (14 digits)");
		return;
	}

	if (checkedListBoxCourses->CheckedItems->Count == 0 ||
		checkedListBoxProfessors->CheckedItems->Count == 0)
	{
		MessageBox::Show("Select at least one course and professor");
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

		// ================= Generate Code =================
		SqlCommand^ cmdCode = gcnew SqlCommand(
			"SELECT ISNULL(MAX(code),7000)+1 FROM Assistants", conn);

		int code = Convert::ToInt32(cmdCode->ExecuteScalar());

		// ================= Insert Assistant =================
		SqlCommand^ cmdInsert = gcnew SqlCommand(
			"INSERT INTO Assistants (code, NationalNumber, name) "
			"OUTPUT INSERTED.id VALUES (@code,@nid,@name)", conn);

		cmdInsert->Parameters->AddWithValue("@code", code);
		cmdInsert->Parameters->AddWithValue("@nid", txtNID->Text);
		cmdInsert->Parameters->AddWithValue("@name", txtName->Text);

		int assistantId = Convert::ToInt32(cmdInsert->ExecuteScalar());

		// ================= Insert Assignments =================
		for each (Object ^ co in checkedListBoxCourses->CheckedItems)
		{
			DataRowView^ c = safe_cast<DataRowView^>(co);

			for each (Object ^ pr in checkedListBoxProfessors->CheckedItems)
			{
				DataRowView^ p = safe_cast<DataRowView^>(pr);

				SqlCommand^ cmdAssign = gcnew SqlCommand(
					"INSERT INTO AssistantAssignments "
					"(assistant_id, course_id, professor_id) "
					"VALUES (@aid,@cid,@pid)", conn);

				cmdAssign->Parameters->AddWithValue("@aid", assistantId);
				cmdAssign->Parameters->AddWithValue("@cid", c["id"]);
				cmdAssign->Parameters->AddWithValue("@pid", p["id"]);

				cmdAssign->ExecuteNonQuery();
			}
		}

		MessageBox::Show("Assistant added successfully", "Success");
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Error");
	}
	finally
	{
		conn->Close();
	}
}
};
}
