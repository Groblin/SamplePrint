#pragma once


namespace PrintingSample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			_pageSetting = gcnew Printing::PageSettings();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: 
	private: System::Windows::Forms::Button^  btnPrintPreview;
	private: System::Drawing::Printing::PrintDocument^  printDoc;
	private: System::Windows::Forms::PrintPreviewControl^  printPreviewControl1;
	private: System::Windows::Forms::PrintPreviewDialog^  ppDlg;
	private: System::Windows::Forms::Button^  btnPageSetup;
	private: System::Windows::Forms::Button^  btnPrint;
	private: System::Windows::Forms::PageSetupDialog^  psDlg;
	private: System::Windows::Forms::PrintDialog^  prDlg;

	Printing::PageSettings^ _pageSetting;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->btnPrintPreview = (gcnew System::Windows::Forms::Button());
			this->printDoc = (gcnew System::Drawing::Printing::PrintDocument());
			this->printPreviewControl1 = (gcnew System::Windows::Forms::PrintPreviewControl());
			this->ppDlg = (gcnew System::Windows::Forms::PrintPreviewDialog());
			this->btnPageSetup = (gcnew System::Windows::Forms::Button());
			this->btnPrint = (gcnew System::Windows::Forms::Button());
			this->psDlg = (gcnew System::Windows::Forms::PageSetupDialog());
			this->prDlg = (gcnew System::Windows::Forms::PrintDialog());
			this->SuspendLayout();
			// 
			// btnPrintPreview
			// 
			this->btnPrintPreview->Location = System::Drawing::Point(12, 12);
			this->btnPrintPreview->Name = L"btnPrintPreview";
			this->btnPrintPreview->Size = System::Drawing::Size(139, 23);
			this->btnPrintPreview->TabIndex = 0;
			this->btnPrintPreview->Text = L"Print Preview";
			this->btnPrintPreview->UseVisualStyleBackColor = true;
			this->btnPrintPreview->Click += gcnew System::EventHandler(this, &Form1::btnPrintPreview_Click);
			// 
			// printDoc
			// 
			this->printDoc->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &Form1::printDoc_PrintPage);
			// 
			// printPreviewControl1
			// 
			this->printPreviewControl1->AutoZoom = false;
			this->printPreviewControl1->Document = this->printDoc;
			this->printPreviewControl1->Location = System::Drawing::Point(157, 12);
			this->printPreviewControl1->Name = L"printPreviewControl1";
			this->printPreviewControl1->Size = System::Drawing::Size(337, 401);
			this->printPreviewControl1->TabIndex = 1;
			this->printPreviewControl1->Zoom = 0.3609090909090909;
			// 
			// ppDlg
			// 
			this->ppDlg->AutoScrollMargin = System::Drawing::Size(0, 0);
			this->ppDlg->AutoScrollMinSize = System::Drawing::Size(0, 0);
			this->ppDlg->ClientSize = System::Drawing::Size(400, 300);
			this->ppDlg->Document = this->printDoc;
			this->ppDlg->Enabled = true;
			this->ppDlg->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"ppDlg.Icon")));
			this->ppDlg->Name = L"ppDlg";
			this->ppDlg->Visible = false;
			// 
			// btnPageSetup
			// 
			this->btnPageSetup->Location = System::Drawing::Point(12, 41);
			this->btnPageSetup->Name = L"btnPageSetup";
			this->btnPageSetup->Size = System::Drawing::Size(139, 23);
			this->btnPageSetup->TabIndex = 2;
			this->btnPageSetup->Text = L"Page Setup";
			this->btnPageSetup->UseVisualStyleBackColor = true;
			this->btnPageSetup->Click += gcnew System::EventHandler(this, &Form1::btnPageSetup_Click);
			// 
			// btnPrint
			// 
			this->btnPrint->Location = System::Drawing::Point(12, 70);
			this->btnPrint->Name = L"btnPrint";
			this->btnPrint->Size = System::Drawing::Size(139, 23);
			this->btnPrint->TabIndex = 3;
			this->btnPrint->Text = L"Print";
			this->btnPrint->UseVisualStyleBackColor = true;
			this->btnPrint->Click += gcnew System::EventHandler(this, &Form1::btnPrint_Click);
			// 
			// psDlg
			// 
			this->psDlg->Document = this->printDoc;
			// 
			// prDlg
			// 
			this->prDlg->Document = this->printDoc;
			this->prDlg->UseEXDialog = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(506, 425);
			this->Controls->Add(this->btnPrint);
			this->Controls->Add(this->btnPageSetup);
			this->Controls->Add(this->printPreviewControl1);
			this->Controls->Add(this->btnPrintPreview);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void printDoc_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) 
			 {
				 String^ printString = "Голова НБУ Сергій Арбузов не погодився з МВФ і президентом Віктором Януковичем, адже у регулятора повідомили, що золотовалютні резерви можуть вирости до кінця року, якщо 'збережуться позитивні економічні тенденції'.";

				 System::Drawing::Font^ printFont = gcnew System::Drawing::Font(gcnew FontFamily("Arial"), 16, FontStyle::Regular, GraphicsUnit::Pixel);
				 System::Drawing::StringFormat^ strFormat = gcnew System::Drawing::StringFormat();

				 Rectangle rectDraw = Rectangle(e->MarginBounds.Left, e->MarginBounds.Top, e->MarginBounds.Width, e->MarginBounds.Height);

				 SizeF sizeMeasure = SizeF(e->MarginBounds.Width, e->MarginBounds.Height);

				 strFormat->Trimming = StringTrimming::Character;
				 strFormat->Alignment = StringAlignment::Near;
				 strFormat->LineAlignment = StringAlignment::Near;


				 SizeF sizePrint = e->Graphics->MeasureString(printString, printFont, sizeMeasure, strFormat);
				 Rectangle rectPrint = Rectangle(e->MarginBounds.Left, e->MarginBounds.Top, sizePrint.Width, sizePrint.Height + printFont->GetHeight(e->Graphics));

				 e->Graphics->DrawRectangle(gcnew Pen(Color::LightBlue), rectDraw);
				 e->Graphics->DrawRectangle(gcnew Pen(Color::Blue), rectPrint);

				 e->Graphics->DrawString(printString, printFont, Brushes::Black, rectPrint, strFormat);

				 Image^ newImage = Image::FromFile("c:\\logo.png");


				 e->Graphics->DrawImage(newImage, e->MarginBounds.Left + (e->MarginBounds.Width - newImage->Width)/2, e->MarginBounds.Top+rectPrint.Height+5);

			 }
	private: System::Void btnPrintPreview_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 ppDlg->ShowDialog();
			 }
	private: System::Void btnPageSetup_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(psDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 _pageSetting = psDlg->PageSettings;
				 }
			 }
	private: System::Void btnPrint_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 prDlg->ShowDialog();
			 }
};
}

