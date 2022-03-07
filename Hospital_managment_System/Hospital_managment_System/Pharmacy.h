#include"Data_Structures.h"
class patient {
private:
	int Total_patients = 0;
	int surgeries = 0;
	int medicine_patients = 0;

	int fix_1 = 0;
	int fix_2 = 0;
	int* array;
	linked_list frequency;
	linked_list list1;
	node* head_list1 = NULL;
	node* head_frequency;

	queue list;
	queue surgery;
	queue pharmacy;
	queue total_surgery;

	node* head = NULL;
	node* head_surgery = NULL;
	node* head_total_surgery = NULL;
	node* head_pharmacy = NULL;
public:
	void add_patient() {
		int limit = 0;

		string myText;
		ifstream MyReadFile("Names.txt");

		Total_patients = 12 + rand() % (14 - 12 + 1);

		fix_2 = fix_2 + Total_patients;
		while (getline(MyReadFile, myText) && (limit) < (fix_2)) {
			if (limit < fix_1) {
				limit++;
			}
			else {
				list.enqueue(&head, myText);
				limit++;
			}
		}
		fix_1 = fix_2;
		MyReadFile.close();
	}

	void diagnose() {

		surgeries = 4 + rand() % (6 - 4 + 1);

		int number = 0;
		int count = 0;

		string str;
		//PRINT PATIENTS OF 1 DAY
		list.print(head);
		//------------------------	
		//LOOP TO ADD PATIENTS TO PHARMACY OR SURGERY QUEUE
		for (int i = 0; i < Total_patients; i++) {
			str = list.dequeue(&head);
			number = 1 + rand() % (2);

			if (number == 1) {//adds patients to pharmacy
				pharmacy.enqueue(&head_pharmacy, str);
			}
			else if (number == 2 && count < surgeries) {//adds patients to surgery
				surgery.enqueue(&head_surgery, str);
				total_surgery.enqueue(&head_total_surgery, str);
				count++;
			}
			else {//adds remaining patients to pharmacy
				pharmacy.enqueue(&head_pharmacy, str);
			}
		}

		cout << "\n\nTotal patients : " << Total_patients;

		cout << "\nNo. of patients diagnosed for surgeries are : " << surgeries;

		medicine_patients = Total_patients - surgeries;
		cout << "\nNo. of patients who need medicine are : " << medicine_patients << "\n\n";

		cout << "\n\t\tSURGERY LIST\n";
		total_surgery.print(head_total_surgery);

		cout << "\n\t\tPHARMACY LIST\n";
		pharmacy.print(head_pharmacy);
	}

	void Prescription() {
		string medicine_Patient_name, b;
		string yourtext, ourtext;
		string diesease_name, medicine_name;
		int R_number;
		int q = 0;

		//Alloting random disease to patients
		for (int i = 0; i < medicine_patients; i++) {
			ifstream MyReadFile("Pharmacy.txt");
			ifstream ReadFile("Medicine.txt");
			q = 0;
			R_number = 0;

			medicine_Patient_name = pharmacy.dequeue(&head_pharmacy);
			//Random number to allot random disease, total number of diseases are 17 so we find 
			//a random number between 1 and 17.
			
			R_number = 1 + rand() % (17);

			//Reading files for medicine and disease.
			//"q" becomes zero in every alteration so that the files traverse from the begenning to the random line 
			//alloted by "R_number".
			while (getline(MyReadFile, yourtext) && q < R_number && getline(ReadFile, ourtext)) {
				diesease_name = yourtext;
				medicine_name = ourtext;
				q++;
			}
			MyReadFile.close();
			//A link list("list1") in which each node contains the patient name, patient disease and the medicine.
			list1.push(&head_list1, medicine_Patient_name, diesease_name, medicine_name);
			frequency.push(&head_frequency, diesease_name);
		}
		cout << "\t\t Patients prescriptions" << endl;
		list1.print(head_list1);
		cout << "\n\nSearching for medicine\n\n";
		list1.find_medicine(head_list1);
		//DELETING LIST
		list1.pop(&head_list1);
		pharmacy.clear(&head_pharmacy);
	}

	//Get set methods to use the queues in Surgery class.
	node* get_head() {
		return head_list1;
	}
	int get_surgeries() {
		return surgeries;
	}
	queue& get_total_surgery() {
		return total_surgery;
	}
	node* get_node() {
		return head_total_surgery;
	}
	void viral() {
		int array[19];
		int x = 0;
		int min = 0;
		int check_array = 0;
		string disease_viral;
		ifstream MyViralFile("Pharmacy.txt");
		while (getline(MyViralFile, disease_viral)) {
			array[x] = frequency.count(&head_frequency, disease_viral);
			x++;
		}


		MyViralFile.close();
		int max = 0;
		for (int i = 0; i < 18; i++)
		{
			if (array[i] > max) {
				max = array[i];
				min++;
			}
		}
		//cout << "\nGG" << max;

		for (int i = 0; i < 19; i++) {
			if (array[i] == max) {
				break;
			}
			check_array++;
		}

		check_array = check_array + 1;

		frequency.print_viral(head_frequency, check_array);


	}

};
