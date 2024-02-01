#pragma once
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>

namespace Project1 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct Process {
		int id;
		int arrivalTime;
		int burstTime;
		int startTime;
		int completionTime;
		int turnaroundTime;
		int waitingTime;
		int responseTime;
	};

	// Comparison functions for sorting processes
	bool compareArrival(Process p1, Process p2) {
		return p1.arrivalTime < p2.arrivalTime;
	}

	bool compareID(Process p1, Process p2) {
		return p1.id < p2.id;
	}


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		String^ arrive;


	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cbbAlgo;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtboxArrival;
	private: System::Windows::Forms::TextBox^ txtboxBurst;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnSubmit;

	private: System::Windows::Forms::Label^ lblInput;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ListBox^ lstboxDisplay;

	private: System::Windows::Forms::Label^ lstTitle;
	private: System::Windows::Forms::TextBox^ txtboxPriority;
	private: System::Windows::Forms::Label^ lblPriority;
	private: System::Windows::Forms::Label^ lbl5;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbbAlgo = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtboxArrival = (gcnew System::Windows::Forms::TextBox());
			this->txtboxBurst = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->lblInput = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lstboxDisplay = (gcnew System::Windows::Forms::ListBox());
			this->lstTitle = (gcnew System::Windows::Forms::Label());
			this->txtboxPriority = (gcnew System::Windows::Forms::TextBox());
			this->lblPriority = (gcnew System::Windows::Forms::Label());
			this->lbl5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(108, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Algorithm";
			// 
			// cbbAlgo
			// 
			this->cbbAlgo->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->cbbAlgo->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->cbbAlgo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbbAlgo->ForeColor = System::Drawing::SystemColors::InfoText;
			this->cbbAlgo->FormattingEnabled = true;
			this->cbbAlgo->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"FCFS (FIrst Come FIrst Serve) ", L"NPP (Non-Preemptive Priority)",
					L"SRTF (Shortest Remaining Time First)"
			});
			this->cbbAlgo->Location = System::Drawing::Point(111, 96);
			this->cbbAlgo->Name = L"cbbAlgo";
			this->cbbAlgo->Size = System::Drawing::Size(185, 21);
			this->cbbAlgo->TabIndex = 1;
			this->cbbAlgo->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cbbAlgo_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label2->Location = System::Drawing::Point(111, 139);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Arrival Time:";
			// 
			// txtboxArrival
			// 
			this->txtboxArrival->Location = System::Drawing::Point(111, 156);
			this->txtboxArrival->Name = L"txtboxArrival";
			this->txtboxArrival->Size = System::Drawing::Size(185, 20);
			this->txtboxArrival->TabIndex = 3;
			// 
			// txtboxBurst
			// 
			this->txtboxBurst->Location = System::Drawing::Point(111, 217);
			this->txtboxBurst->Name = L"txtboxBurst";
			this->txtboxBurst->Size = System::Drawing::Size(185, 20);
			this->txtboxBurst->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->Location = System::Drawing::Point(111, 200);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Burst Time:";
			// 
			// btnSubmit
			// 
			this->btnSubmit->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->ForeColor = System::Drawing::Color::White;
			this->btnSubmit->Location = System::Drawing::Point(111, 313);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(75, 23);
			this->btnSubmit->TabIndex = 6;
			this->btnSubmit->Text = L"Solve";
			this->btnSubmit->UseVisualStyleBackColor = false;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &MyForm::btnSubmit_Click);
			// 
			// lblInput
			// 
			this->lblInput->AutoSize = true;
			this->lblInput->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInput->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblInput->Location = System::Drawing::Point(105, 35);
			this->lblInput->Name = L"lblInput";
			this->lblInput->Size = System::Drawing::Size(88, 33);
			this->lblInput->TabIndex = 7;
			this->lblInput->Text = L"Input";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Cursor = System::Windows::Forms::Cursors::Default;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label4->Location = System::Drawing::Point(381, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 33);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Output";
			// 
			// lstboxDisplay
			// 
			this->lstboxDisplay->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstboxDisplay->FormattingEnabled = true;
			this->lstboxDisplay->ItemHeight = 15;
			this->lstboxDisplay->Location = System::Drawing::Point(387, 96);
			this->lstboxDisplay->Name = L"lstboxDisplay";
			this->lstboxDisplay->Size = System::Drawing::Size(827, 304);
			this->lstboxDisplay->TabIndex = 9;
			// 
			// lstTitle
			// 
			this->lstTitle->AutoSize = true;
			this->lstTitle->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstTitle->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lstTitle->Location = System::Drawing::Point(384, 78);
			this->lstTitle->Name = L"lstTitle";
			this->lstTitle->Size = System::Drawing::Size(59, 15);
			this->lstTitle->TabIndex = 10;
			this->lstTitle->Text = L"Algorithm";
			// 
			// txtboxPriority
			// 
			this->txtboxPriority->Location = System::Drawing::Point(111, 273);
			this->txtboxPriority->Name = L"txtboxPriority";
			this->txtboxPriority->Size = System::Drawing::Size(185, 20);
			this->txtboxPriority->TabIndex = 12;
			// 
			// lblPriority
			// 
			this->lblPriority->AutoSize = true;
			this->lblPriority->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPriority->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblPriority->Location = System::Drawing::Point(111, 256);
			this->lblPriority->Name = L"lblPriority";
			this->lblPriority->Size = System::Drawing::Size(45, 13);
			this->lblPriority->TabIndex = 11;
			this->lblPriority->Text = L"Priority:";
			// 
			// lbl5
			// 
			this->lbl5->AutoSize = true;
			this->lbl5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lbl5->Location = System::Drawing::Point(666, 66);
			this->lbl5->Name = L"lbl5";
			this->lbl5->Size = System::Drawing::Size(35, 13);
			this->lbl5->TabIndex = 13;
			this->lbl5->Text = L"label5";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1289, 450);
			this->Controls->Add(this->lbl5);
			this->Controls->Add(this->txtboxPriority);
			this->Controls->Add(this->lblPriority);
			this->Controls->Add(this->lstTitle);
			this->Controls->Add(this->lstboxDisplay);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lblInput);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->txtboxBurst);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtboxArrival);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cbbAlgo);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::Cornsilk;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

		String^ stdDetails = "{0,15}{1,22}{2,22}{3,25}{4, 25}{5, 25}{6, 25}";

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		lstboxDisplay->Items->Add(String::Format(stdDetails, "PID", "Arrival Time", "Burst Time", "Completion Time", "Turn Around Time", "Waiting Time", "Priority"));
	}

	private: System::Void cbbAlgo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		lstTitle->Text = cbbAlgo->Text;
		txtboxPriority->Hide();
		lblPriority->Hide();
		lstboxDisplay->Size = System::Drawing::Size(720, 304);

		this->btnSubmit->Location = System::Drawing::Point(111, 256);

		if (cbbAlgo->Text == "NPP (Non-Preemptive Priority)") {
			txtboxPriority->Show();
			lblPriority->Show();
			btnSubmit->Location = System::Drawing::Point(111, 313);
			lstboxDisplay->Size = System::Drawing::Size(827, 304);
		}
	}

	private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cbbAlgo->Text == "NPP (Non-Preemptive Priority)") {
			
		}


		if (cbbAlgo->Text == "FCFS (First Come FIrst Serve)") {
			// Declare variables to store process information and various metrics
			int numProcesses;
			vector<Process> processes;
			float avgTurnaroundTime, avgWaitingTime, avgResponseTime, cpuUtilization, throughput;
			int totalTurnaroundTime = 0, totalWaitingTime = 0, totalResponseTime = 0, totalIdleTime = 0;
			String^ tempBurstTime, ^ tempArrivalTime = "";

			// Input handling for arrival times

			tempArrivalTime = txtboxArrival->Text;
			string arrivalTimeStr = msclr::interop::marshal_as<std::string>(tempArrivalTime);
			istringstream iss(arrivalTimeStr);

			// Read arrival times and store them in the 'at' vector
			vector<int> at;
			char comma;  // Variable to store the comma
			for (int number; iss >> number || (iss.eof() && at.empty());) {
				at.push_back(number);

				// Check for a comma and consume it if not at the end of the input
				if (iss >> std::ws && iss.peek() == ',') {
					iss.ignore();
				}
			}

			// Input handling for burst times
			tempBurstTime = txtboxBurst->Text;
			std::string burstTimeStr = msclr::interop::marshal_as<std::string>(tempBurstTime);
			istringstream isss(burstTimeStr);

			// Read burst times and store them in the 'bt' vector
			vector<int> bt;
			for (int number; isss >> number || (isss.eof() && bt.empty());) {
				bt.push_back(number);

				// Check for a comma and consume it if not at the end of the input
				if (isss >> std::ws && isss.peek() == ',') {
					isss.ignore();
				}
			}

			// Validation to check if the number of bt and at is the same, if not exit
			if (at.size() != bt.size()) {
				MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			// Initialize the number of processes
			numProcesses = at.size();

			// Store the values to the struct process
			for (int i = 0; i < numProcesses; i++) {
				Process process;
				process.id = i + 1;  // Assign a unique id
				process.arrivalTime = at[i];
				process.burstTime = bt[i];
				processes.push_back(process);
			}

			// Sort processes based on arrival time
			sort(processes.begin(), processes.end(), compareArrival);

			// Calculate various metrics for each process
			for (int i = 0; i < numProcesses; i++) {
				processes[i].startTime = (i == 0) ? processes[i].arrivalTime : max(processes[i - 1].completionTime, processes[i].arrivalTime);
				processes[i].completionTime = processes[i].startTime + processes[i].burstTime;
				processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
				processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
				processes[i].responseTime = processes[i].startTime - processes[i].arrivalTime;

				// Update cumulative metrics
				totalTurnaroundTime += processes[i].turnaroundTime;
				totalWaitingTime += processes[i].waitingTime;
				totalResponseTime += processes[i].responseTime;
				totalIdleTime += (i == 0) ? processes[i].arrivalTime : (processes[i].startTime - processes[i - 1].completionTime);
			}

			// Calculate average metrics
			avgTurnaroundTime = static_cast<float>(totalTurnaroundTime) / numProcesses;
			avgWaitingTime = static_cast<float>(totalWaitingTime) / numProcesses;
			avgResponseTime = static_cast<float>(totalResponseTime) / numProcesses;
			cpuUtilization = ((processes[numProcesses - 1].completionTime - totalIdleTime) / static_cast<float>(processes[numProcesses - 1].completionTime)) * 100;
			throughput = static_cast<float>(numProcesses) / (processes[numProcesses - 1].completionTime - processes[0].arrivalTime);

			// Sort processes based on ID for output display
			sort(processes.begin(), processes.end(), compareID);

			// Display process information in tabular format
			for (const Process& p : processes) {
				lstboxDisplay->Items->Add(String::Format(stdDetails, p.id, p.arrivalTime, p.burstTime, p.completionTime, p.turnaroundTime, p.waitingTime));

			}

			/*
			// Display average metrics and other performance indicators
			cout << "Average Turnaround Time = " << avgTurnaroundTime << endl;
			cout << "Average Waiting Time = " << avgWaitingTime << endl;
			cout << "Average Response Time = " << avgResponseTime << endl;
			cout << "CPU Utilization = " << cpuUtilization << "%" << endl;
			*/

		}

	}
	};
}
