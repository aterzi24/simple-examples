import java.util.*;

class Person {
	int age;
	String name;
	Gender gender;

	enum Gender {
		MALE,
		FEMALE,
		NotDefined
	}

	Person () {
		age = -1;
		name = "Murtaza";
		gender = Gender.NotDefined;
	}
}

class Employee extends Person {
	String company;
	int numOfEmployer;

	Employee() {
		company = "Aselsan";
		age = 5;
		gender = Gender.MALE;
	}
}

public class InheritanceExmp {

	public static void main(String[] args) {
		Employee emp = new Employee();
    	
    	System.out.println(emp.gender);
   }
}
