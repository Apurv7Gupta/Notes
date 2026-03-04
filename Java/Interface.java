// In interfaces, the fields are static and final, so you have to initialize every attribute on declaration
// Every method in an interface is already abstract, so you dont need "abstract" keyword
// Interface methods are implicitly public
public class Interface {

    interface Animal {
        int age = 18;

        public void makeSound(); // Abstract method

        public default void ConcreteMethod() {

            System.out.println("You can use 'default' to make a concrete method in an Interface");
        } // Concrete method
    }

    public static class Human implements Animal {

        public void makeSound() {
            System.out.println("Speak");
        }

    }

    public static void main(String[] args) {
        Animal Davis = new Human();
        Davis.makeSound();
        Davis.ConcreteMethod();
    }
}

// ---------- Interface vs Abstract classes ----------

// 1) You can implement as many Interfaces as you want in the child class, but you can extend only one Abstract class in a child class
// 2) You can define which method wil be abstract in an Abstract class, in an Interface, every method is abstract, unless its default

// 3) You use "Extends" to extend an Abstract class, you use "Implements" to implement an Interface

// 4) You can change fields in Abstract classes, in Interfaces, every field is static and final

// 5) Abstract classes can have concrete methods freely; interfaces only via default/static
