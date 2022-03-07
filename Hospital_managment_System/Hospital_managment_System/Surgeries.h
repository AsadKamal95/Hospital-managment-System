#include"Pharmacy.h"
class Surgery {
private:

	int total_cost_surgery = 0;
	int surgeries = 0;
	int random_number = 0;
	node* head;
	queue Total_surgeries;
	string types[6] = { "Appendectomy","Carotid endarterectomy","Cataract surgery","Hemorrhoidectomy","Partial colectomy","Tonsillectomy" };
	int cost[6] = { 3000,15000,8000,6500,12000,5000 };
public:

	void setSurgeries(int surgery) {
		surgeries = surgery;
	}

	void setHead(node* h) {
		head = h;
	}

	void setTotalSurgeries(queue& surgery) {
		Total_surgeries = surgery;
	}

	void Surgery_perform() {

		cout << "\n\t\tOperations" << endl;
		if (5 > surgeries) {
			cout << "\nSurgery performed " << surgeries << endl;
			cout << "NAMES\t\t    OPERATIONS \t\t\t  COST\n\n";
			for (int i = 0; i < surgeries; i++) {
				//Random number to allot random operations to patients.
				random_number = 0 + rand() % (5);

				cout << left;
				cout << setw(20) << Total_surgeries.dequeue(&head) << setw(30) << types[random_number] << setw(25) << cost[random_number] << endl;
				total_cost_surgery = total_cost_surgery + cost[random_number];

			}
		}
		else {
			cout << "\nSurgery performed : " << 5 << endl;
			cout << "NAMES\t\t    OPERATIONS \t\t\t  COST\n";
			for (int i = 0; i < 5; i++) {
				//Random number to allot random operations to patients.
				random_number = 0 + rand() % (5);

				cout << left;
				cout << setw(20) << Total_surgeries.dequeue(&head) << setw(30) << types[random_number] << setw(25) << cost[random_number] << endl;
				total_cost_surgery = total_cost_surgery + cost[random_number];


			}
		}

		cout << "\n\nPending Surgeries\n";
		Total_surgeries.print(head);
	}

	int get_money() {
		return total_cost_surgery;
	}
};