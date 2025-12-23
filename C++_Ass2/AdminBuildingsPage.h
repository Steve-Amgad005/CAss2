#pragma once

#include "AdminAddBuilding.h"
#include "AdminDeleteBuilding.h"
#include "AdminModifyBuilding.h"
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
	/// Summary for AdminBuildingsPage
	/// </summary>
	public ref class AdminBuildingsPage : public System::Windows::Forms::Form
	{
	private:
		Form^ currentPopup = nullptr;

		void CloseCurrentPopup()
		{
			if (currentPopup != nullptr)
			{
				currentPopup->Close();
				currentPopup = nullptr;
			}
		}

		void LoadBuildingsData()
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
					"b.id, b.name AS [Building], "

					"(SELECT COUNT(*) FROM Floors f "
					" WHERE f.building_id = b.id) AS [Floors], "

					"(SELECT COUNT(*) FROM LectureHalls h "
					" INNER JOIN Floors f ON h.floor_id = f.id "
					" WHERE f.building_id = b.id) AS [Halls], "

					"(SELECT COUNT(*) FROM Labs l "
					" INNER JOIN Floors f ON l.floor_id = f.id "
					" WHERE f.building_id = b.id) AS [Labs] "

					"FROM Buildings b";

				SqlDataAdapter^ da = gcnew SqlDataAdapter(query, conn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				dataGridViewBuildings->DataSource = dt;

				dataGridViewBuildings->AutoSizeColumnsMode =
					DataGridViewAutoSizeColumnsMode::Fill;
				dataGridViewBuildings->ReadOnly = true;
				dataGridViewBuildings->SelectionMode =
					DataGridViewSelectionMode::FullRowSelect;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Error");
			}
		}
	private:
		int AdminCode;

	public:
		AdminBuildingsPage(int code)
		{
			InitializeComponent();
			AdminCode = code;
			LoadBuildingsData();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminBuildingsPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridViewBuildings;
	protected:

	protected:








	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel1;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminBuildingsPage::typeid));
			this->dataGridViewBuildings = (gcnew System::Windows::Forms::DataGridView());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewBuildings))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridViewBuildings
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			this->dataGridViewBuildings->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewBuildings->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::DarkGray;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewBuildings->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewBuildings->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewBuildings->Location = System::Drawing::Point(179, 270);
			this->dataGridViewBuildings->Name = L"dataGridViewBuildings";
			this->dataGridViewBuildings->ReadOnly = true;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			this->dataGridViewBuildings->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridViewBuildings->Size = System::Drawing::Size(838, 302);
			this->dataGridViewBuildings->TabIndex = 11;
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
			this->button4->Location = System::Drawing::Point(352, 169);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(187, 60);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Modify Building";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &AdminBuildingsPage::button4_Click);
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
			this->button3->Location = System::Drawing::Point(634, 169);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(187, 60);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Delete Building";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &AdminBuildingsPage::button3_Click);
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
			this->button2->Location = System::Drawing::Point(901, 169);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(187, 60);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Refresh";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &AdminBuildingsPage::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(1128, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(71, 65);
			this->button1->TabIndex = 6;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AdminBuildingsPage::button1_Click);
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
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(71, 169);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(187, 60);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Add Building";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &AdminBuildingsPage::button5_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(44, 27);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1063, 100);
			this->panel1->TabIndex = 5;
			// 
			// AdminBuildingsPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(1242, 599);
			this->Controls->Add(this->dataGridViewBuildings);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->panel1);
			this->Name = L"AdminBuildingsPage";
			this->Text = L"AdminBuildingsPage";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewBuildings))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		CloseCurrentPopup();
		AdminAddBuilding^ addBuildingForm = gcnew AdminAddBuilding();
		currentPopup = addBuildingForm;
		addBuildingForm->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminBuildingsPage::PopupClosed);
		addBuildingForm->Show();
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	CloseCurrentPopup();
	AdminDeleteBuilding^ deleteBuildingForm = gcnew AdminDeleteBuilding();
	currentPopup = deleteBuildingForm;
	deleteBuildingForm->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminBuildingsPage::PopupClosed);
	deleteBuildingForm->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	CloseCurrentPopup();
	AdminModifyBuilding^ modifyBuildingForm = gcnew AdminModifyBuilding();
	currentPopup = modifyBuildingForm;
	modifyBuildingForm->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminBuildingsPage::PopupClosed);
	modifyBuildingForm->Show();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadBuildingsData();
}
private: System::Void PopupClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e){
		   currentPopup = nullptr;
}

};
}
