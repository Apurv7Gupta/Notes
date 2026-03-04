// Abstraction = hiding implementation details and exposing only essential behavior.

// An abstract class is only made for inheritance, it has no object, it only tells how the inherited class should be (it only exists to be a blueprint for other classes)

// The abstract class defines WHAT its children can do, but does not define HOW every child does it.

// Abstract classes are used to define a structure for defining classes that will be closely related

// It enforces a consistent structure across all implementations
public class Abstraction {

    public static abstract class Animal {

        // ---------Fields---------

        public int age;

        // ---------Methods---------
        public abstract void ImplementME(); // This is an abstract method, you HAVE TO implement abstract methods

        public void ConcreteMethod() {
            System.out.println("Concrete methods can be made in abstract classes");
        }

        public void makeSound() {
            System.out.println("Generic animal sound");
        }

    }

    public static class Cat extends Animal {
        public void ImplementME() {
            System.out.println("If I hadn't implemented this, I would have gotten a compile time error");
        }
    }

    public static class Seagull extends Animal {
        public void ImplementME() {
            age = 99;
            System.out.println("I am " + age + " years old");
        }

        @Override
        public void makeSound() {
            System.out.println("GAG");
        } // Overriding makeSound
    }

    public static void main(String[] parameters) {

        Animal Gurt = new Cat();

        // Using concrete method from abstract class
        Gurt.ConcreteMethod();

        Animal Frank = new Seagull();

        Frank.ImplementME();

        // Using overriden method
        Frank.makeSound();
    }

}

// At compile time → both classes are typed as Animal.
// At runtime → Java dispatches to the actual object (Cat or Seagull).

// ---------- Interface vs Abstract classes ----------

// 1) You can implement as many Interfaces as you want in the child class, but you can extend only one Abstract class in a child class
// 2) You can define which method wil be abstract in an Abstract class, in an Interface, every method is abstract, unless its default

// 3) You use "Extends" to extend an Abstract class, you use "Implements" to implement an Interface

// 4) You can change fields in Abstract classes, in Interfaces, every field is static and final

// 5) Abstract classes can have concrete methods freely; interfaces only via default/static
