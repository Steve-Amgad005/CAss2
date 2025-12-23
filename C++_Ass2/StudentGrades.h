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
	/// Summary for StudentGrades
	/// </summary>
	public ref class StudentGrades : public System::Windows::Forms::Form
	{
		void LoadGrades()
		{
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";
			String^ query =
				"SELECT "
				"c.course_name AS 'Course', "
				"g.assignment1 AS 'Assignment 1', "
				"g.assignment2 AS 'Assignment 2', "
				"g.cw AS 'Course Work', "
				"g.final AS 'Final', "
				"g.total AS 'Total', "
				"g.grade AS 'Grade' "
				"FROM Students s "
				"JOIN Grades g ON g.student_id = s.id "
				"JOIN Courses c ON c.id = g.course_id "
				"WHERE s.code = @code";
			SqlConnection^ conn = gcnew SqlConnection(connStr);
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			cmd->Parameters->Add("@code", SqlDbType::Int)->Value = StdCode;

			SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
			DataTable^ dt = gcnew DataTable();

			try
			{
				da->Fill(dt);
				dataGridView1->DataSource = dt;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
	private:
		int StdCode;

		
	public:
		StudentGrades(int code)
		{
			InitializeComponent();
			StdCode = code;
			LoadGrades();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentGrades()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::DarkGray;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->GridColor = System::Drawing::Color::Purple;
			this->dataGridView1->Location = System::Drawing::Point(12, 31);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Size = System::Drawing::Size(702, 494);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &StudentGrades::dataGridView1_CellContentClick);
			// 
			// StudentGrades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(726, 546);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"StudentGrades";
			this->Text = L"StudentGrades";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
};
}
