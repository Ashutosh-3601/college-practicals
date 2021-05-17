import java.util.Scanner;

class Staff {
	String StaffID, Name, Phone, Salary;
	Scanner input = new Scanner(System.in);
	
	void read() {
		System.out.println("Enter the Staff ID");
		StaffID = input.nextLine();
		System.out.println("Enter Staff Name");
		Name = input.nextLine();
		System.out.println("Enter the phone number");
		Phone = input.nextLine();
		System.out.println("Enter the salary amount");
		Salary = input.nextLine();
	}
	
	void display() {
		input.close();
		System.out.printf("\n%-15s","STAFFID");
		System.out.printf("\n%-15s", StaffID);
		System.out.printf("\n%-15s","NAME");
		System.out.printf("\n%-15s",Name);
		System.out.printf("\n%-15s","PHONE");
		System.out.printf("\n%-15s",Phone);
		System.out.printf("\n%-15s","SALARY");
		System.out.printf("\n%-15s",Salary);
	}
}

class Teaching extends Staff {
	String Domain, Publication;
	
	void Teaching_read() {
		super.read();
		System.out.println("Enter Domain");
		Domain = input.nextLine();
		System.out.println("Enter Publication");
		Publication = input.nextLine();
	}
	
	void display() {
		super.display();
		System.out.printf("\n%-15s","DOMAIN");
		System.out.printf("\n%-15s",Domain);
		System.out.printf("\n%-15s","PUBLICATION");
		System.out.printf("\n%-15s",Publication);
	}
}

class Technical extends Staff {
	String Skills;
	
	void Techincal_read() {
		super.read();
		System.out.println("Enter skills");
		Skills = input.nextLine();
	}
	
	void display() {
		super.display();
		System.out.printf("\n%-15s","SKILLS");
		System.out.printf("\n%-15s",Skills);
	}
}

class Contract extends Staff {
	String Period;
	
	void Contract_read() {
		super.read();
		System.out.println("Enter Period");
		Period = input.nextLine();
	}
	
	void display() {
		super.display();
		System.out.printf("\n%-15s","PERIOD");
		System.out.printf("\n%-15s",Period);
	} 
}

class StaffDetails {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the numbr of staff");
		int n = input.nextInt();
		Teaching StaffTeaching[] = new Teaching[n];
		Technical StaffTechnical[] = new Technical[n];
		Contract StaffContract[] = new Contract[n];
		
		for(int i = 0; i < n; i++) {
			System.out.println("Enter the details of teaching staff");
			StaffTeaching[i] = new Teaching();
			StaffTeaching[i].Teaching_read();
		}
		
		for(int i = 0; i < n; i++) {
			System.out.println("Enter the details of technical staff");
			StaffTechnical[i] = new Technical();
			StaffTechnical[i].Techincal_read();
		}
		
		for(int i = 0; i < n; i++) {
			System.out.println("Enter the details of teaching staff");
			StaffContract[i] = new Contract();
			StaffContract[i].Contract_read();
		}
		
		System.out.println("\nSTAFF DETAILS\n");
		
		System.out.println("\n_______________TEACHING STAFF_______________\n");
		for(int i=0 ; i<n ; i++) {
			StaffTeaching[i].display();
		}
		
		System.out.println();
		System.out.println("\n_______________TECHNICAL STAFF_______________\n");
		for(int i=0 ; i<n ; i++) {
			StaffTechnical[i].display();
		}
		System.out.println();
		System.out.println("\n_______________CONTRACT STAFF_______________\n");
		for(int i=0 ; i<n ; i++) {
			StaffContract[i].display();
		}
		input.close();
	}
}
