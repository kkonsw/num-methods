#pragma once

namespace My4mlab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TableTestU
	/// </summary>
	public ref class TableTestU : public System::Windows::Forms::Form
	{
	public:
		TableTestU(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TableTestU()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::DataGridView^  dataGridView_testU;
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
            this->dataGridView_testU = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_testU))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView_testU
            // 
            this->dataGridView_testU->BackgroundColor = System::Drawing::SystemColors::Control;
            this->dataGridView_testU->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_testU->Location = System::Drawing::Point(69, 47);
            this->dataGridView_testU->Name = L"dataGridView_testU";
            this->dataGridView_testU->RowTemplate->Height = 28;
            this->dataGridView_testU->Size = System::Drawing::Size(684, 537);
            this->dataGridView_testU->TabIndex = 0;
            // 
            // TableTestU
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(836, 634);
            this->Controls->Add(this->dataGridView_testU);
            this->Name = L"TableTestU";
            this->Text = L"Точные значения тестовой задачи";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_testU))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
	};
}
