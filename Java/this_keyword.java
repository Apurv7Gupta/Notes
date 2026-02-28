// ------------------------------ "this" keyword is ------------------------------

// ⦁ a reference variable
// ⦁ refers to the current object of a class
// ⦁ used inside instance methods, constructors, or instance blocks

// ------------------------------ Rules ------------------------------

// 1. Cannot be used in static context (static methods/blocks).

// 2. Must be the first statement when calling a constructor from another
// constructor.

// 3. Can be used to differentiate between local variables and instance
// variables.

// 4. Refers to current object only.

// ------------------------------ Usages ------------------------------

// 1. When a local variable (e.g. method parameter) has the same name as an
// instance variable (shadowing), "this" distinguishes the instance variable.

// 2. this.methodName() can be used to call another method of the same class.

// 3. Using this(), a constructor can call another constructor of the same
// class.
// Rule: Must be the first statement in the constructor.

// 4. this can be passed as a parameter to another method or constructor

// 5. Can be used to return current class instance, Useful for method chaining.

public class this_keyword {

    public static void main(String[] args) {
        Student obj = new Student();
        obj.firstMethod(); // Prints both sentences, even though we only called firstMethod

        // This was a default constructor call, so this set the "name" attribute to "Unknown" because our default cons calls param cons inside itself

        obj.thirdMethod();

        // 4a.
        Student p = new Student("Rin");
        p.sendSelf();

        // 4b.
        new Y();

    }

    static class Student {
        int rollNo;
        String name;

        // 1.
        void method(int rollNo, String LastName) {
            this.name = LastName;
            this.rollNo = rollNo; // Resolve Shadowing
        }

        // 2.
        public void firstMethod() {
            System.out.println("Inside firstMethod()");
            this.secondMethod();
        }// Calling another method of the same class using this

        // 3.
        // Default constructor
        public Student() {
            this("Unknown"); // <-- Calls parameterized constructor
        }

        // Parameterized constructor
        public Student(String FirstName) {
            this.name = FirstName;
        }

        public void secondMethod() {
            System.out.println("Inside secondMethod()");
        }

        public void thirdMethod() {
            System.out.println("Name: " + name);
        }

        // 4a. (Passing "this" in a method)

        public void sendSelf() {
            receive(this); // passing current object
        }

        public void receive(Student p) {
            System.out.println("Received: " + p.name);
        }

    }

    // 4b. (Passing "this" in a constructor)
    static class X {
        X(Y b) {
            System.out.println("X got Y");
        } // defining a constructor for X that expects an object of Y
    }

    static class Y {
        Y() {
            X a = new X(this); // passing Y's object as "this"
        }
    }

}
