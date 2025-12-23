#pragma once

#include "AdminPage.h"

namespace CAss2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;


	/// <summary>
	/// Summary for AdminShowMarks
	/// </summary>
	public ref class AdminShowMarks : public System::Windows::Forms::Form
	{
		void LoadYears()
		{
			cmbYear->Items->Clear();
			cmbYear->Items->Add("All");
			cmbYear->Items->Add("First");
			cmbYear->Items->Add("Second");
			cmbYear->Items->Add("Third");
			cmbYear->Items->Add("Fourth");
			cmbYear->SelectedIndex = 0;
		}

		void LoadDepartments()
		{
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";

			SqlConnection^ conn = gcnew SqlConnection(connStr);

			try
			{
				String^ query = "SELECT id, name FROM Departments";
				SqlDataAdapter^ da = gcnew SqlDataAdapter(query, conn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				cmbDepartment->DataSource = dt;
				cmbDepartment->DisplayMember = "name";
				cmbDepartment->ValueMember = "id";

				cmbDepartment->SelectedIndex = -1;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}

		void LoadAllStudentsMarks()
		{
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";

			SqlConnection^ conn = gcnew SqlConnection(connStr);

			try
			{
				String^ query =
					"SELECT "
					"s.code AS [Student Code], "
					"s.name AS [Student Name], "
					"d.name AS [Department], "

					"CASE s.year "
					" WHEN 1 THEN 'First' "
					" WHEN 2 THEN 'Second' "
					" WHEN 3 THEN 'Third' "
					" WHEN 4 THEN 'Fourth' "
					" ELSE 'Unknown' "
					"END AS [Year], "

					"c.course_name AS [Course], "
					"g.assignment1 AS [Assignment 1], "
					"g.assignment2 AS [Assignment 2], "
					"g.cw AS [CW], "
					"g.final AS [Final], "
					"g.total AS [Total] "

					"FROM Grades g "
					"INNER JOIN Students s ON g.student_id = s.id "
					"INNER JOIN Courses c ON g.course_id = c.id "
					"INNER JOIN Departments d ON s.department_id = d.id "

					"ORDER BY d.name, s.year, s.code, c.course_name";

				SqlDataAdapter^ da = gcnew SqlDataAdapter(query, conn);
				DataTable^ dt = gcnew DataTable();

				da->Fill(dt);
				dataGridViewMarks->DataSource = dt;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Error");
			}
		}
	private:
		int AdminCode;
	public:
		AdminShowMarks(int code)
		{
			InitializeComponent();
			AdminCode = code;
			LoadAllStudentsMarks();
			LoadDepartments();
			LoadYears();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminShowMarks()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridViewMarks;
	protected:











	private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::ComboBox^ cmbDepartment;
private: System::Windows::Forms::ComboBox^ cmbYear;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminShowMarks::typeid));
			this->dataGridViewMarks = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbDepartment = (gcnew System::Windows::Forms::ComboBox());
			this->cmbYear = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMarks))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewMarks
			// 
			this->dataGridViewMarks->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			this->dataGridViewMarks->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewMarks->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::DarkGray;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewMarks->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewMarks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMarks->Location = System::Drawing::Point(95, 235);
			this->dataGridViewMarks->Name = L"dataGridViewMarks";
			this->dataGridViewMarks->ReadOnly = true;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			this->dataGridViewMarks->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridViewMarks->Size = System::Drawing::Size(837, 292);
			this->dataGridViewMarks->TabIndex = 11;
			this->dataGridViewMarks->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AdminShowMarks::dataGridView1_CellContentClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(323, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(373, 39);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Show Students Marks";
			// 
			// cmbDepartment
			// 
			this->cmbDepartment->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDepartment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbDepartment->FormattingEnabled = true;
			this->cmbDepartment->Location = System::Drawing::Point(226, 147);
			this->cmbDepartment->Name = L"cmbDepartment";
			this->cmbDepartment->Size = System::Drawing::Size(148, 33);
			this->cmbDepartment->TabIndex = 15;
			this->cmbDepartment->SelectedIndexChanged += gcnew System::EventHandler(this, &AdminShowMarks::comboBox1_SelectedIndexChanged);
			// 
			// cmbYear
			// 
			this->cmbYear->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbYear->FormattingEnabled = true;
			this->cmbYear->Location = System::Drawing::Point(678, 147);
			this->cmbYear->Name = L"cmbYear";
			this->cmbYear->Size = System::Drawing::Size(148, 33);
			this->cmbYear->TabIndex = 16;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Purple;
			this->button1->Location = System::Drawing::Point(441, 139);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(177, 41);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Show";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminShowMarks::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(909, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(59, 56);
			this->button2->TabIndex = 18;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &AdminShowMarks::button2_Click);
			// 
			// AdminShowMarks
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(1002, 539);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->cmbYear);
			this->Controls->Add(this->cmbDepartment);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridViewMarks);
			this->Name = L"AdminShowMarks";
			this->Text = L"AdminShowMarks";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMarks))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	String^ query =
		"SELECT "
		"s.code AS [Student Code], "
		"s.name AS [Student Name], "
		"d.name AS [Department], "
		"CASE s.year "
		" WHEN 1 THEN 'First' "
		" WHEN 2 THEN 'Second' "
		" WHEN 3 THEN 'Third' "
		" WHEN 4 THEN 'Fourth' "
		"END AS [Year], "
		"c.course_name AS [Course], "
		"g.assignment1 AS [Assignment 1], "
		"g.assignment2 AS [Assignment 2], "
		"g.cw AS [CW], "
		"g.final AS [Final], "
		"g.total AS [Total] "
		"FROM Grades g "
		"INNER JOIN Students s ON g.student_id = s.id "
		"INNER JOIN Courses c ON g.course_id = c.id "
		"INNER JOIN Departments d ON s.department_id = d.id "
		"WHERE 1 = 1 ";

	// فلترة السنة
	if (cmbYear->SelectedItem != nullptr && cmbYear->Text != "All")
	{
		query += " AND s.year = @year ";
	}

	// فلترة القسم
	if (cmbDepartment->SelectedValue != nullptr)
	{
		query += " AND d.id = @deptId ";
	}

	query += " ORDER BY d.name, s.year, s.code";

	SqlCommand^ cmd = gcnew SqlCommand(query, conn);

	// باراميتر السنة
	if (cmbYear->Text == "First") cmd->Parameters->AddWithValue("@year", 1);
	if (cmbYear->Text == "Second") cmd->Parameters->AddWithValue("@year", 2);
	if (cmbYear->Text == "Third") cmd->Parameters->AddWithValue("@year", 3);
	if (cmbYear->Text == "Fourth") cmd->Parameters->AddWithValue("@year", 4);

	// باراميتر القسم
	if (cmbDepartment->SelectedValue != nullptr)
	{
		cmd->Parameters->AddWithValue("@deptId", cmbDepartment->SelectedValue);
	}

	SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
	DataTable^ dt = gcnew DataTable();
	da->Fill(dt);

	dataGridViewMarks->DataSource = dt;
}
};
}
