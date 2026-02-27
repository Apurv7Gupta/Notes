//// Constructor = Special Method that is automatically invoked at time of obj creation
/// Constructor should have the same name as the class
// has no return type

public class Constructor {
    public static void main(String[] ParameterName) {
        // Default Cons calling
        MyClass obj = new MyClass();
        System.out.println(obj.name);

        // Param Cons calling
        MyClass obj2 = new MyClass(99, "John");
        System.out.println("Name: " + obj2.name + " Age: " + obj2.age + " ");

        // Copy Cons calling (copying obj2's values)
        MyClass obj3 = new MyClass(obj2);
        System.out.println(obj3.name + " " + obj3.age);
    }

    static class MyClass

    {
        public String name;
        public int age;

        MyClass() {
        } // DEFAULT constructor
          // (Java will automatically give this even if we didn't write it)

        MyClass(int x, String Lastname) {
            this.name = Lastname;
            this.age = x;
        } // PARAMETERIZED constructor
          // Java doesnt support default values in parameters
          // You can use default constructor to fill default values

        MyClass(MyClass OrgObj) {
            this.name = OrgObj.name; // copied name
            this.age = OrgObj.age; // copied age
        } // COPY constructor
          // In java, you don't get a default copy constructor
    }
}

// FEW NOTES -

/*
 * Here, we used public attributes , but in the real world, we use private
 * with setters and getters in OOP
 */

// Constructor Overloading:

// The Phenomenon of having multiple constructors with same name but different types is known as Constructor Overloading
// Which is an example of POLYMORPHISM
// This is already shown in the above code
