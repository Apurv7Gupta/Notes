public class Inner_Nested_Class {
    public class Outer {

        int x = 10;

        class Inner {
            void method() {

                class LOCAL {

                    void LOCALmethod() {

                        System.out.println("Local Class");

                    }
                }
                new LOCAL().LOCALmethod(); // calling local class's method

            }

        }

        static class StaticInner {
            void method() {
                System.out.println("Nested Static class");
            }

            void StaticMethod() {
                // Anonymous class
                Runnable r = new Runnable() {
                    @Override
                    public void run() {
                        System.out.println("Anonymous Class");
                    }

                };
                r.run(); // calling anonymous class's method

            }

        }
    }
}

// --------------Anonymous Class--------------:

// A class defined and instantiated at the same time
// with no name
// used for a one-time implementation of an interface or abstract class.

// An anonymous class must implement an existing interface or extend an existing class. Common ones:

// Runnable → has run()
// Comparator → has compare()
// Any abstract class you've defined

// --------------Local Class--------------:

// A class defined inside a method, only accessible within that method.

// --------------Inner Class--------------:

// A non-static class defined inside another class, tied to an instance of the outer class.

// --------------Static Inner Class--------------:

// A static class defined inside another class, with no access to the outer class's instance members.
