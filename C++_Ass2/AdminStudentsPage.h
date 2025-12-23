#pragma once
#include "AdminAddStudent.h";
#include "AdminModifyStudent.h"
#include "AdminDeleteStudent.h"


namespace CAss2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for AdminStudentsPage
	/// </summary>
	public ref class AdminStudentsPage : public System::Windows::Forms::Form
	{
		Form^ currentPopup = nullptr;

		void CloseCurrentPopup()
		{
			if (currentPopup != nullptr)
			{
				currentPopup->Close();
				currentPopup = nullptr;
			}
		}

		void LoadAllStudents()
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
					"s.code AS [Code], "
					"s.name AS [Name], "
					"s.seatnumber AS [Seat Number], "
					"s.NationalNumber AS [National ID], "

					"CASE s.year "
					"WHEN 1 THEN 'First' "
					"WHEN 2 THEN 'Second' "
					"WHEN 3 THEN 'Third' "
					"WHEN 4 THEN 'Fourth' "
					"END AS [Year], "

					"s.current_term AS [Term], "
					"d.name AS [Department] "
					"FROM Students s "
					"INNER JOIN Departments d ON s.department_id = d.id";


				SqlDataAdapter^ da = gcnew SqlDataAdapter(query, conn);
				DataTable^ dt = gcnew DataTable();

				da->Fill(dt);

				dataGridViewStudents->DataSource = dt;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Error");
			}
		}


	private:
		int AdminCode;
	public:
		AdminStudentsPage(int code)
		{
			InitializeComponent();
			AdminCode = code;
			LoadAllStudents();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminStudentsPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::DataGridView^ dataGridViewStudents;










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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminStudentsPage::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->dataGridViewStudents = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudents))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(54, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1063, 100);
			this->panel1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(301, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(599, 39);
			this->label1->TabIndex = 1;
			this->label1->Text = L"New Cairo Technological University";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(27, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(110, 84);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(1138, 33);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(71, 65);
			this->button1->TabIndex = 2;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AdminStudentsPage::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(911, 154);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(187, 60);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Refresh";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &AdminStudentsPage::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(644, 154);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(187, 60);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Delete Student";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &AdminStudentsPage::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(362, 154);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(187, 60);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Modify Student";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &AdminStudentsPage::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(81, 154);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(187, 60);
			this->button5->TabIndex = 3;
			this->button5->Text = L"Add Student";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &AdminStudentsPage::button5_Click);
			// 
			// dataGridViewStudents
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			this->dataGridViewStudents->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewStudents->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::DarkGray;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewStudents->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewStudents->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStudents->Location = System::Drawing::Point(189, 255);
			this->dataGridViewStudents->Name = L"dataGridViewStudents";
			this->dataGridViewStudents->ReadOnly = true;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			this->dataGridViewStudents->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridViewStudents->Size = System::Drawing::Size(838, 302);
			this->dataGridViewStudents->TabIndex = 4;
			// 
			// AdminStudentsPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(1242, 599);
			this->Controls->Add(this->dataGridViewStudents);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"AdminStudentsPage";
			this->Text = L"AdminStudentsPage";
			this->Load += gcnew System::EventHandler(this, &AdminStudentsPage::AdminStudentsPage_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudents))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		CloseCurrentPopup();
		CAss2::AdminAddStudent^ addStudentForm = gcnew CAss2::AdminAddStudent();
		currentPopup = addStudentForm;
		addStudentForm->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminStudentsPage::PopupClosed);
		addStudentForm->Show();
	}
private: System::Void AdminStudentsPage_Load(System::Object^ sender, System::EventArgs^ e) {
}

	// declaration of back handler
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	CloseCurrentPopup();
	AdminModifyStudent^ AMS = gcnew AdminModifyStudent();
	currentPopup = AMS;
	AMS->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminStudentsPage::PopupClosed);
	AMS->Show();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	CloseCurrentPopup();
	AdminDeleteStudent^ AMS = gcnew AdminDeleteStudent();
	currentPopup = AMS;
	AMS->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminStudentsPage::PopupClosed);
	AMS->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//here to refresh the data grid view
	LoadAllStudents();
}
private: System::Void PopupClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	currentPopup = nullptr;
}
};
}
