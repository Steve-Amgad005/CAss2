#pragma once

#include "StudentGrades.h"
#include "StudentAcademicCourses.h"

namespace CAss2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Data::SqlClient;

	


	/// <summary>
	/// Summary for StudetMainPage
	/// </summary>
	public ref class StudetMainPage : public System::Windows::Forms::Form
	{
		void LoadStudentData()
		{
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
					"SELECT s.name, s.code, s.NationalNumber, s.year, "
					"d.name AS DepartmentName, s.ProfileImage "
					"FROM Students s "
					"INNER JOIN Departments d ON s.department_id = d.id "
					"WHERE s.code = @code";

				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@code", StdCode);

				SqlDataReader^ reader = cmd->ExecuteReader();

				if (reader->Read())
				{
					// =========================
					// Text data
					// =========================
					LableStdName->Text = reader["name"]->ToString();
					LableStdCode->Text = reader["code"]->ToString();
					LableStdNID->Text = reader["NationalNumber"]->ToString();
					LableStdDept->Text = reader["DepartmentName"]->ToString();

					int year = Convert::ToInt32(reader["year"]);
					switch (year)
					{
					case 1: LableStdYear->Text = "First Year"; break;
					case 2: LableStdYear->Text = "Second Year"; break;
					case 3: LableStdYear->Text = "Third Year"; break;
					case 4: LableStdYear->Text = "Fourth Year"; break;
					default: LableStdYear->Text = "Unknown"; break;
					}

					// =========================
					// Image handling
					// =========================
					pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;

					if (reader["ProfileImage"] != DBNull::Value)
					{
						array<Byte>^ imgBytes = (array<Byte>^)reader["ProfileImage"];
						System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(imgBytes);

						// Free old image (important)
						if (pictureBox2->Image != nullptr)
						{
							delete pictureBox2->Image;
							pictureBox2->Image = nullptr;
						}

						pictureBox2->Image = Image::FromStream(ms);
					}
					else
					{
						// Default image
						pictureBox2->Image = Image::FromFile("default.png");
						pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
					}
				}

				reader->Close();
				conn->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}


	private:
		int StdCode;
	public:
		StudetMainPage(int code)
		{
			InitializeComponent();
			StdCode=code;
			this->Load += gcnew System::EventHandler(this, &StudetMainPage::StudetMainPage_Load);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudetMainPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ LableStdName;


	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ LableStdNID;

	private: System::Windows::Forms::Label^ LableStdCode;
	private: System::Windows::Forms::Label^ LableStdYear;


	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ LableStdDept;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button8;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StudetMainPage::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->LableStdDept = (gcnew System::Windows::Forms::Label());
			this->LableStdNID = (gcnew System::Windows::Forms::Label());
			this->LableStdCode = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->LableStdName = (gcnew System::Windows::Forms::Label());
			this->LableStdYear = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(22, 21);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1122, 100);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(262, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(599, 39);
			this->label1->TabIndex = 2;
			this->label1->Text = L"New Cairo Technological University";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(21, 19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(69, 63);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->LableStdDept);
			this->panel2->Controls->Add(this->LableStdNID);
			this->panel2->Controls->Add(this->LableStdCode);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->LableStdName);
			this->panel2->Controls->Add(this->LableStdYear);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Location = System::Drawing::Point(22, 142);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1122, 157);
			this->panel2->TabIndex = 2;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &StudetMainPage::panel2_Paint);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(729, 104);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(91, 16);
			this->label12->TabIndex = 13;
			this->label12->Text = L"Department:";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(698, 4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(10, 153);
			this->panel3->TabIndex = 9;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(159, 104);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 16);
			this->label7->TabIndex = 8;
			this->label7->Text = L"NID:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(729, 72);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(117, 16);
			this->label11->TabIndex = 12;
			this->label11->Text = L"Academic Year:";
			this->label11->Click += gcnew System::EventHandler(this, &StudetMainPage::label11_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(159, 72);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(104, 16);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Student Code:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(159, 40);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Name:";
			this->label5->Click += gcnew System::EventHandler(this, &StudetMainPage::label5_Click);
			// 
			// LableStdDept
			// 
			this->LableStdDept->AutoSize = true;
			this->LableStdDept->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LableStdDept->ForeColor = System::Drawing::Color::White;
			this->LableStdDept->Location = System::Drawing::Point(822, 104);
			this->LableStdDept->Name = L"LableStdDept";
			this->LableStdDept->Size = System::Drawing::Size(41, 16);
			this->LableStdDept->TabIndex = 11;
			this->LableStdDept->Text = L":القسم";
			// 
			// LableStdNID
			// 
			this->LableStdNID->AutoSize = true;
			this->LableStdNID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LableStdNID->ForeColor = System::Drawing::Color::White;
			this->LableStdNID->Location = System::Drawing::Point(202, 104);
			this->LableStdNID->Name = L"LableStdNID";
			this->LableStdNID->Size = System::Drawing::Size(82, 16);
			this->LableStdNID->TabIndex = 5;
			this->LableStdNID->Text = L":الرقم القومي";
			// 
			// LableStdCode
			// 
			this->LableStdCode->AutoSize = true;
			this->LableStdCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LableStdCode->ForeColor = System::Drawing::Color::White;
			this->LableStdCode->Location = System::Drawing::Point(269, 72);
			this->LableStdCode->Name = L"LableStdCode";
			this->LableStdCode->Size = System::Drawing::Size(73, 16);
			this->LableStdCode->TabIndex = 4;
			this->LableStdCode->Text = L":كود الطالب";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(852, 72);
			this->label9->Name = L"label9";
			this->label9->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label9->Size = System::Drawing::Size(76, 16);
			this->label9->TabIndex = 10;
			this->label9->Text = L"2025-2026";
			// 
			// LableStdName
			// 
			this->LableStdName->AutoSize = true;
			this->LableStdName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LableStdName->ForeColor = System::Drawing::Color::White;
			this->LableStdName->Location = System::Drawing::Point(217, 40);
			this->LableStdName->Name = L"LableStdName";
			this->LableStdName->Size = System::Drawing::Size(39, 16);
			this->LableStdName->TabIndex = 3;
			this->LableStdName->Text = L":الأسم";
			this->LableStdName->Click += gcnew System::EventHandler(this, &StudetMainPage::label2_Click);
			// 
			// LableStdYear
			// 
			this->LableStdYear->AutoSize = true;
			this->LableStdYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LableStdYear->ForeColor = System::Drawing::Color::White;
			this->LableStdYear->Location = System::Drawing::Point(729, 40);
			this->LableStdYear->Name = L"LableStdYear";
			this->LableStdYear->Size = System::Drawing::Size(97, 16);
			this->LableStdYear->TabIndex = 7;
			this->LableStdYear->Text = L"Second Year";
			this->LableStdYear->Click += gcnew System::EventHandler(this, &StudetMainPage::label8_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(21, 28);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(121, 102);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(64, 331);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(289, 69);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Seat Number";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &StudetMainPage::button2_Click);
			// 
			// button1
			// 
			this->button1->AccessibleName = L"back";
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(1176, 52);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(41, 39);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &StudetMainPage::button1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(441, 331);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(289, 69);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Current year\'s result";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &StudetMainPage::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(803, 331);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(289, 69);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Student\'s academic courses";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &StudetMainPage::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(803, 428);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(289, 69);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Student fees";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &StudetMainPage::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Location = System::Drawing::Point(441, 428);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(289, 69);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Student Portal";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &StudetMainPage::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::White;
			this->button7->Location = System::Drawing::Point(64, 428);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(289, 69);
			this->button7->TabIndex = 6;
			this->button7->Text = L"University website";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &StudetMainPage::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::White;
			this->button8->Location = System::Drawing::Point(441, 518);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(289, 69);
			this->button8->TabIndex = 9;
			this->button8->Text = L"Student Schedule";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &StudetMainPage::button8_Click);
			// 
			// StudetMainPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(1242, 599);
			this->ControlBox = false;
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"StudetMainPage";
			this->Text = L"StudetMainPage";
			this->Load += gcnew System::EventHandler(this, &StudetMainPage::StudetMainPage_Load_1);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connStr =
			"Server=localhost\\SQLEXPRESS;"
			"Database=MyDB;"
			"Trusted_Connection=True;"
			"TrustServerCertificate=True;";

		SqlConnection^ conn = gcnew SqlConnection(connStr);

		try {
			conn->Open();

			String^ query =
				"SELECT seatnumber "
				"FROM Students "
				"WHERE code = @code";

			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@code", StdCode);

			Object^ result = cmd->ExecuteScalar();

			if (result != nullptr) {
				MessageBox::Show(
					"Your seat number is: " + result,
					"Student Seat Number",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information
				);
			}
			else {
				MessageBox::Show(
					"Your seat number is: " + result,
					"Student Seat Number",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
			}

			conn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		StudentGrades^ gradesForm = gcnew StudentGrades(StdCode);
		gradesForm->Show();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	ProcessStartInfo^ psi = gcnew ProcessStartInfo();
	psi->FileName = "https://nctu.edu.eg/";
	psi->UseShellExecute = true;
	Process::Start(psi);
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	ProcessStartInfo^ psi = gcnew ProcessStartInfo();
	psi->FileName = "http://193.227.0.21/Nctu/Registration/ED_Login.aspx";
	psi->UseShellExecute = true;
	Process::Start(psi);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	StudentAcademicCourses^ coursesForm = gcnew StudentAcademicCourses(StdCode);
	coursesForm->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	String^ query =
		"SELECT s.name, s.code, s.seatnumber, "
		"ISNULL(p.amount, 0) AS amount, "
		"ISNULL(p.status, 'Not Paid') AS status "
		"FROM Students s "
		"LEFT JOIN Payments p ON p.student_id = s.id "
		"WHERE s.code = @code";

	SqlCommand^ cmd = gcnew SqlCommand(query, conn);

	// ✅ تأكد إن StdCode int
	cmd->Parameters->Add("@code", SqlDbType::Int)->Value = StdCode;

	try
	{
		conn->Open();
		SqlDataReader^ dr = cmd->ExecuteReader();

		if (dr->Read())
		{
			String^ message =
				"Student Fees Status\n\n"
				"Name: " + dr["name"]->ToString() + "\n"
				"Code: " + dr["code"]->ToString() + "\n"
				"Seat Number: " + dr["seatnumber"]->ToString() + "\n\n"
				"Status: " + dr["status"]->ToString() + "\n"
				"Amount Paid: " + dr["amount"]->ToString() + " EGP";

			MessageBox::Show(
				message,
				"Student Fees",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
		}
		else
		{
			MessageBox::Show("Student not found");
		}

		dr->Close();
		conn->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}
}

private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	ProcessStartInfo^ psi = gcnew ProcessStartInfo();
	psi->FileName = "https://drive.google.com/drive/folders/1K6CMYRDOvsRMaM32yJVu8EelwJBnJeNv?usp=sharing";
	psi->UseShellExecute = true;
	Process::Start(psi);
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void StudetMainPage_Load(System::Object^ sender, System::EventArgs^ e) {
	LoadStudentData();
}
private: System::Void StudetMainPage_Load_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
