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
	/// Summary for NewsPage
	/// </summary>
	public ref class NewsPage : public System::Windows::Forms::Form
	{
		void ShowNewsPopup(String^ title, String^ content)
		{
			Form^ popup = gcnew Form();
			popup->Text = title;
			popup->Size = System::Drawing::Size(600, 400);
			popup->StartPosition = FormStartPosition::CenterParent;
			popup->BackColor = Color::White;

			// ===== RichTextBox =====
			RichTextBox^ rtb = gcnew RichTextBox();
			rtb->Dock = DockStyle::Fill;
			rtb->ReadOnly = true;
			rtb->Text = content;
			rtb->Font = gcnew Drawing::Font("Segoe UI", 12);
			rtb->BackColor = Color::White;

			// ===== Close Button =====
			Button^ btnClose = gcnew Button();
			btnClose->Text = "Close";
			btnClose->Dock = DockStyle::Bottom;
			btnClose->Height = 40;

			btnClose->Click += gcnew EventHandler(this, &NewsPage::ClosePopup);

			btnClose->Tag = popup;

			popup->Controls->Add(rtb);
			popup->Controls->Add(btnClose);

			popup->ShowDialog();
		}


		void LoadNews()
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
					"id, "
					"title AS [Title], "
					"content AS [Content] "
					"FROM News "
					"ORDER BY id DESC";

				SqlDataAdapter^ da = gcnew SqlDataAdapter(query, conn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				dataGridViewNews->DataSource = dt;

				dataGridViewNews->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				dataGridViewNews->AutoGenerateColumns = true;
				dataGridViewNews->DataSource = dt;

				for each (DataGridViewColumn ^ col in dataGridViewNews->Columns)
				{
					col->SortMode = DataGridViewColumnSortMode::NotSortable;
				}

				dataGridViewNews->Columns["id"]->Visible = false;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}

	public:
		NewsPage(void)
		{
			InitializeComponent();
			LoadNews();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewsPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridViewNews;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;

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
			this->dataGridViewNews = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewNews))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewNews
			// 
			this->dataGridViewNews->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewNews->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->dataGridViewNews->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewNews->Location = System::Drawing::Point(12, 97);
			this->dataGridViewNews->MultiSelect = false;
			this->dataGridViewNews->Name = L"dataGridViewNews";
			this->dataGridViewNews->ReadOnly = true;
			this->dataGridViewNews->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewNews->Size = System::Drawing::Size(587, 408);
			this->dataGridViewNews->TabIndex = 0;
			this->dataGridViewNews->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &NewsPage::dataGridViewNews_CellContentClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(217, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(186, 33);
			this->label1->TabIndex = 1;
			this->label1->Text = L"NCTU News";
			// 
			// NewsPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(611, 517);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridViewNews);
			this->Name = L"NewsPage";
			this->Text = L"NewsPage";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewNews))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridViewNews_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (dataGridViewNews->SelectedRows->Count == 0)
			return;

		String^ title =
			dataGridViewNews->SelectedRows[0]->Cells["Title"]->Value->ToString();

		String^ content =
			dataGridViewNews->SelectedRows[0]->Cells["Content"]->Value->ToString();

		ShowNewsPopup(title, content);
	}

	private: System::Void dataGridViewNews_DoubleClick(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (dataGridViewNews->SelectedRows->Count == 0)
				   return;

			   String^ title =
				   dataGridViewNews->SelectedRows[0]->Cells["Title"]->Value->ToString();

			   String^ content =
				   dataGridViewNews->SelectedRows[0]->Cells["Content"]->Value->ToString();

			   ShowNewsPopup(title, content);
	}
	private: System::Void ClosePopup(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ btn = safe_cast<Button^>(sender);
		Form^ popup = safe_cast<Form^>(btn->Tag);
		popup->Close();
	}

	private: System::Void dataGridViewNews_CellDoubleClick(System::Object^ sender,System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		if (e->RowIndex < 0) return;

		String^ title =
			dataGridViewNews->Rows[e->RowIndex]->Cells["title"]->Value->ToString();

		String^ content =
			dataGridViewNews->Rows[e->RowIndex]->Cells["content"]->Value->ToString();

		ShowNewsPopup(title, content);
	}



};
}
