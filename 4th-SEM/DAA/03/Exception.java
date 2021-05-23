import java.util.Scanner;

public class Exception {
	public static void main(String[] args) {
		int num1, num2, result;
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the first number (num1)");
		num1 = input.nextInt();
		System.out.println("Enter the first number (num2)");
		num2 = input.nextInt();
		input.close();
		
		try {
			result = num1 / num2;
			System.out.println("Result of division = "+result);
		} catch (ArithmeticException err) {
			System.out.println("Exception caught: Division by zero error!");
		}
	}
}
