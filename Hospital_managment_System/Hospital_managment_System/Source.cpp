#include"Surgeries.h"
class Bill {
public:
	void total(Surgery& obj) {
		cout << "\nTotal Earned : "<<obj.get_money();
		cout<<endl;
	}
};

class mains {
	patient obj;
	Surgery s;
	tries P;
	linked_list L;
	Bill B;

public: 
	mains() {
		for (int i = 0; i < 30; i++) {
			
			cout << "Patients in day : " << i+1 << endl;
			obj.add_patient();
			obj.diagnose();
			obj.Prescription();
			s.setHead(obj.get_node());
			s.setSurgeries(obj.get_surgeries());
			s.setTotalSurgeries(obj.get_total_surgery());
			s.Surgery_perform();
			
			L.find_medicine(obj.get_head());	
			cout << "----------------End of day-------------------" << endl;
			
			B.total(s);
			cout << "\n\nEND OF DAY# "<<i + 1 << endl;
			cout << " . ";
			Sleep(100);
			cout << " . ";
			Sleep(100);
			cout << " . ";
			Sleep(500);

			
		}
		cout << "\n\n";
		obj.viral();
		
	}
};

int main() {
	mains obj;
	
	return 0;
}