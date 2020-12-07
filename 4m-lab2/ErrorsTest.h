#pragma once

namespace My4mlab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ErrorsTest
	/// </summary>
	public ref class ErrorsTest : public System::Windows::Forms::Form
	{
	public:
		ErrorsTest(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

        ErrorsTest(double **test_err, int n, int m)
        {
            InitializeComponent();

            // строим таблицу
            cli::array< DataGridViewTextBoxColumn^ >^ arr;
            arr = gcnew cli::array< DataGridViewTextBoxColumn^ >(n + 1);

            for (int i = 0; i < n + 1; i++)
            {
                arr[i] = gcnew DataGridViewTextBoxColumn();
            }

            dataGridView_testErrors->Columns->AddRange(arr);

            for (int j = m; j >= 0; j--)
            {
                dataGridView_testErrors->Rows->Add();
                for (int i = 0; i < n + 1; i++)
                {
                    dataGridView_testErrors->Rows[m - j]->Cells[i]->Value = System::Convert::ToString(test_err[i][j]);
                }
            }

            dataGridView_testErrors->ClearSelection();
        }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ErrorsTest()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::DataGridView^  dataGridView_testErrors;
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
            this->dataGridView_testErrors = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_testErrors))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView_testErrors
            // 
            this->dataGridView_testErrors->BackgroundColor = System::Drawing::SystemColors::Control;
            this->dataGridView_testErrors->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_testErrors->Location = System::Drawing::Point(103, 57);
            this->dataGridView_testErrors->Name = L"dataGridView_testErrors";
            this->dataGridView_testErrors->RowTemplate->Height = 28;
            this->dataGridView_testErrors->Size = System::Drawing::Size(613, 485);
            this->dataGridView_testErrors->TabIndex = 0;
            // 
            // ErrorsTest
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(807, 606);
            this->Controls->Add(this->dataGridView_testErrors);
            this->Name = L"ErrorsTest";
            this->Text = L"Таблица погрешностей тестовой задачи";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_testErrors))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
	};
}
