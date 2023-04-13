#pragma once
#include "InfInt.h"
#include "RSA Class.h"
#include <string>
#include <msclr\marshal_cppstd.h>

bool shouldGenerate;
bool ready;
RSAClass test;
namespace RSA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for hARSh
	/// </summary>
	public ref class hARSh : public System::Windows::Forms::Form
	{
	public:
		hARSh(void)
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
		~hARSh()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ input;
	private: System::Windows::Forms::Button^ decrypt;

	private: System::Windows::Forms::Button^ encrypt;

	private: System::Windows::Forms::TextBox^ output;
	private: System::Windows::Forms::TextBox^ pInput;
	private: System::Windows::Forms::TextBox^ qInput;




	private: System::Windows::Forms::RadioButton^ isSupplied;

	private: System::Windows::Forms::RadioButton^ isGenerate;
	private: System::Windows::Forms::TextBox^ keyOne;
	private: System::Windows::Forms::TextBox^ keyTwo;



	private: System::Windows::Forms::TextBox^ nOutput;

	private: System::Windows::Forms::TextBox^ eOutput;
	private: System::Windows::Forms::TextBox^ dOutput;



	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ loadingImage;


	protected:





	protected:


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(hARSh::typeid));
			this->input = (gcnew System::Windows::Forms::TextBox());
			this->decrypt = (gcnew System::Windows::Forms::Button());
			this->encrypt = (gcnew System::Windows::Forms::Button());
			this->output = (gcnew System::Windows::Forms::TextBox());
			this->pInput = (gcnew System::Windows::Forms::TextBox());
			this->qInput = (gcnew System::Windows::Forms::TextBox());
			this->isSupplied = (gcnew System::Windows::Forms::RadioButton());
			this->isGenerate = (gcnew System::Windows::Forms::RadioButton());
			this->keyOne = (gcnew System::Windows::Forms::TextBox());
			this->keyTwo = (gcnew System::Windows::Forms::TextBox());
			this->nOutput = (gcnew System::Windows::Forms::TextBox());
			this->eOutput = (gcnew System::Windows::Forms::TextBox());
			this->dOutput = (gcnew System::Windows::Forms::TextBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->loadingImage = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->loadingImage))->BeginInit();
			this->SuspendLayout();
			loadingImage->Hide();
			// 
			// input
			// 
			this->input->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->input->Location = System::Drawing::Point(45, 55);
			this->input->Multiline = true;
			this->input->Name = L"input";
			this->input->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->input->Size = System::Drawing::Size(680, 68);
			this->input->TabIndex = 4;
			// 
			// decrypt
			// 
			this->decrypt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->decrypt->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->decrypt->Location = System::Drawing::Point(742, 92);
			this->decrypt->Name = L"decrypt";
			this->decrypt->Size = System::Drawing::Size(86, 31);
			this->decrypt->TabIndex = 6;
			this->decrypt->Text = L"Decrypt";
			this->decrypt->UseVisualStyleBackColor = true;
			this->decrypt->Click += gcnew System::EventHandler(this, &hARSh::decrypt_Click);
			// 
			// encrypt
			// 
			this->encrypt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->encrypt->BackColor = System::Drawing::Color::Transparent;
			this->encrypt->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->encrypt->Location = System::Drawing::Point(742, 55);
			this->encrypt->Name = L"encrypt";
			this->encrypt->Size = System::Drawing::Size(86, 31);
			this->encrypt->TabIndex = 7;
			this->encrypt->Text = L"Encrypt";
			this->encrypt->UseVisualStyleBackColor = false;
			this->encrypt->Click += gcnew System::EventHandler(this, &hARSh::encrypt_Click);
			// 
			// output
			// 
			this->output->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->output->Location = System::Drawing::Point(45, 291);
			this->output->Multiline = true;
			this->output->Name = L"output";
			this->output->ReadOnly = true;
			this->output->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->output->Size = System::Drawing::Size(783, 106);
			this->output->TabIndex = 8;
			// 
			// pInput
			// 
			this->pInput->Location = System::Drawing::Point(620, 189);
			this->pInput->Name = L"pInput";
			this->pInput->Size = System::Drawing::Size(208, 26);
			this->pInput->TabIndex = 9;
			this->pInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->pInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &hARSh::pInput_KeyPress);
			// 
			// qInput
			// 
			this->qInput->Location = System::Drawing::Point(620, 222);
			this->qInput->Name = L"qInput";
			this->qInput->Size = System::Drawing::Size(208, 26);
			this->qInput->TabIndex = 10;
			this->qInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->qInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &hARSh::qInput_KeyPress);
			// 
			// isSupplied
			// 
			this->isSupplied->AutoSize = true;
			this->isSupplied->Location = System::Drawing::Point(45, 159);
			this->isSupplied->Name = L"isSupplied";
			this->isSupplied->Size = System::Drawing::Size(100, 24);
			this->isSupplied->TabIndex = 11;
			this->isSupplied->TabStop = true;
			this->isSupplied->Text = L"Use This!";
			this->isSupplied->UseVisualStyleBackColor = true;
			this->isSupplied->CheckedChanged += gcnew System::EventHandler(this, &hARSh::isSupplied_CheckedChanged);
			// 
			// isGenerate
			// 
			this->isGenerate->AutoSize = true;
			this->isGenerate->Location = System::Drawing::Point(722, 159);
			this->isGenerate->Name = L"isGenerate";
			this->isGenerate->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->isGenerate->Size = System::Drawing::Size(106, 24);
			this->isGenerate->TabIndex = 12;
			this->isGenerate->TabStop = true;
			this->isGenerate->Text = L"!Generate";
			this->isGenerate->UseVisualStyleBackColor = true;
			this->isGenerate->CheckedChanged += gcnew System::EventHandler(this, &hARSh::isGenerate_CheckedChanged);
			// 
			// keyOne
			// 
			this->keyOne->Location = System::Drawing::Point(45, 189);
			this->keyOne->Name = L"keyOne";
			this->keyOne->Size = System::Drawing::Size(208, 26);
			this->keyOne->TabIndex = 13;
			this->keyOne->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &hARSh::keyOne_KeyPress);
			// 
			// keyTwo
			// 
			this->keyTwo->Location = System::Drawing::Point(45, 222);
			this->keyTwo->Name = L"keyTwo";
			this->keyTwo->Size = System::Drawing::Size(208, 26);
			this->keyTwo->TabIndex = 14;
			this->keyTwo->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &hARSh::keyTwo_KeyPress);
			// 
			// nOutput
			// 
			this->nOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->nOutput->Location = System::Drawing::Point(45, 411);
			this->nOutput->Name = L"nOutput";
			this->nOutput->ReadOnly = true;
			this->nOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->nOutput->Size = System::Drawing::Size(253, 26);
			this->nOutput->TabIndex = 15;
			// 
			// eOutput
			// 
			this->eOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->eOutput->Location = System::Drawing::Point(310, 411);
			this->eOutput->Name = L"eOutput";
			this->eOutput->ReadOnly = true;
			this->eOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->eOutput->Size = System::Drawing::Size(253, 26);
			this->eOutput->TabIndex = 16;
			this->eOutput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// dOutput
			// 
			this->dOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dOutput->Location = System::Drawing::Point(575, 411);
			this->dOutput->Name = L"dOutput";
			this->dOutput->ReadOnly = true;
			this->dOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dOutput->Size = System::Drawing::Size(253, 26);
			this->dOutput->TabIndex = 17;
			this->dOutput->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(356, 201);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(174, 37);
			this->label1->TabIndex = 18;
			this->label1->Text = L"< hARSh >";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(620, 189);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 20);
			this->label2->TabIndex = 19;
			this->label2->Text = L"p";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(620, 223);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(18, 20);
			this->label3->TabIndex = 20;
			this->label3->Text = L"q";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(235, 191);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(18, 20);
			this->label4->TabIndex = 21;
			this->label4->Text = L"n";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(235, 225);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 20);
			this->label5->TabIndex = 22;
			this->label5->Text = L"e";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Black;
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->Location = System::Drawing::Point(158, 441);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 20);
			this->label6->TabIndex = 23;
			this->label6->Text = L"n";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Black;
			this->label7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label7->Location = System::Drawing::Point(429, 441);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(18, 20);
			this->label7->TabIndex = 24;
			this->label7->Text = L"e";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Black;
			this->label8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label8->Location = System::Drawing::Point(697, 441);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(18, 20);
			this->label8->TabIndex = 25;
			this->label8->Text = L"d";
			// 
			// loadingImage
			// 
			this->loadingImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"loadingImage.Image")));
			this->loadingImage->Location = System::Drawing::Point(268, 85);
			this->loadingImage->Name = L"loadingImage";
			this->loadingImage->Size = System::Drawing::Size(337, 245);
			this->loadingImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->loadingImage->TabIndex = 26;
			this->loadingImage->TabStop = false;
			// 
			// hARSh
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(875, 503);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dOutput);
			this->Controls->Add(this->eOutput);
			this->Controls->Add(this->nOutput);
			this->Controls->Add(this->keyTwo);
			this->Controls->Add(this->keyOne);
			this->Controls->Add(this->isGenerate);
			this->Controls->Add(this->isSupplied);
			this->Controls->Add(this->qInput);
			this->Controls->Add(this->pInput);
			this->Controls->Add(this->output);
			this->Controls->Add(this->encrypt);
			this->Controls->Add(this->decrypt);
			this->Controls->Add(this->input);
			this->Controls->Add(this->loadingImage);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"hARSh";
			this->Text = L"hARSh";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->loadingImage))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void isGenerate_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	shouldGenerate = true;
}
private: System::Void isSupplied_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	shouldGenerate = false;
}

// Numbers Only
private: System::Void keyOne_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
		e->Handled = true;
}
private: System::Void keyTwo_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
		e->Handled = true;
}
private: System::Void pInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
		e->Handled = true;
}
private: System::Void qInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
		e->Handled = true;
}
private: System::Void encrypt_Click(System::Object^ sender, System::EventArgs^ e) {
	loadingImage->Show();
	msclr::interop::marshal_context context;
	InfInt key[2];
	do {
	if (shouldGenerate == true) {
			PrimePair pair;
			KeyPair key;
			if (pInput->Text == "" || qInput->Text == "") {
				output->Text = "Please Enter Numbers For p and q";
				break;
			}
			pair.p = msclr::interop::marshal_as<std::string>(pInput->Text);
			pair.q = msclr::interop::marshal_as<std::string>(qInput->Text);
			if (!test.isPrime(pair.p) || !test.isPrime(pair.q) || pair.p == pair.q) output->Text = "Please Enter Two Different Prime Numbers For p and q";
			else {
				key = test.generateKeys(pair);
				if (pair.p < 50 || pair.q < 50) {
					std::string message = "test";
					std::string encrypted = test.encrypt(message, key.publicKey);
					if (message.compare(test.decrypt(encrypted, key.privateKey)) != 0) {
						output->Text = "Please Choose Other Values For p and q (Values Larger than 50 Work Best)";
						break;
					}
				}
				else {
					key = test.generateKeys(pair);
				}
				nOutput->Text = gcnew String(key.publicKey[0].toString().c_str()); //convert to system::string instead of standard string
				eOutput->Text = gcnew String(key.publicKey[1].toString().c_str()); //convert to system::string instead of standard string
				dOutput->Text = gcnew String(key.privateKey[1].toString().c_str()); //convert to system::string instead of standard string
				output->Text = gcnew String(test.encrypt(msclr::interop::marshal_as<std::string>(input->Text), key.publicKey).c_str());
			}

		}
		else {
			if (keyOne->Text == "" || keyTwo->Text == "") output->Text = "Please Enter Numbers For n and e";
			else {
				InfInt key[2];
				nOutput->Text = keyOne->Text;
				eOutput->Text = keyTwo->Text;
				dOutput->Text = "N/A";
				key[0] = msclr::interop::marshal_as<std::string>(keyOne->Text);
				key[1] = msclr::interop::marshal_as<std::string>(keyTwo->Text);
				output->Text = gcnew String(test.encrypt(context.marshal_as<std::string>(input->Text), key).c_str());
			}
	}
	} while (false);
	loadingImage->Hide();
}
private: System::Void decrypt_Click(System::Object^ sender, System::EventArgs^ e) {
	loadingImage->Show();
	if (shouldGenerate) output->Text = "Key Generation Is Not Supported For Decryption";
	else {
		if (keyOne->Text == "" || keyTwo->Text == "") output->Text = "Please Enter Numbers For n and e";
		else {
			InfInt key[2];
			msclr::interop::marshal_context context;
			nOutput->Text = keyOne->Text;
			dOutput->Text = keyTwo->Text;
			eOutput->Text = "N/A";
			key[0] = context.marshal_as<std::string>(keyOne->Text);
			key[1] = context.marshal_as<std::string>(keyTwo->Text);
			output->Text = gcnew String(test.decrypt(context.marshal_as<std::string>(input->Text), key).c_str());
		}
	}
	loadingImage->Hide();
}
};
}
