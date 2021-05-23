import java.util.Scanner;
import java.util.StringTokenizer;

public class Customer {
	String name, dob;
	
	void read() {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the name of customer:");
		this.name = input.nextLine();
		
		System.out.println("Enter the Date of Birth [format: dd/mm/yyyy]:");
		this.dob= input.next();
		
		input.close();
	}
	
	void display() {
		StringTokenizer token = new StringTokenizer(this.dob, "/");
		System.out.print(this.name+" - ");
		
		while(token.hasMoreTokens()) {
			System.out.print(token.nextToken());
			if(token.countTokens() != 0) {
				System.out.print(", ");
			}
		}
	}
}

class Main {
	public static void main(String args[]) {
		Customer customer = new Customer();
		customer.read();
		System.out.println("\nCustomer Details\n________________\n");
		customer.display();
	}
}
