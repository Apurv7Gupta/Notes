public class StaticInJava {

    class Class1 {

        int field1;
        String field2;

        public static void StaticMethod() {

        } // ❌ illegal in non-static class, except constants (static final).

    }

    static class StaticClass {
        public void method() {
        }

        public static void StaticMethod() {
            System.out.println("Static method in a static nested class");
        }
    }

    public static void main(String[] args) {

        // Class1 obj = new Class1(); // Wrong

        StaticInJava outerObj = new StaticInJava(); // outer instance

        Class1 obj = outerObj.new Class1(); // inner class instance

        StaticClass.StaticMethod(); // Static methods can be called without creating an object

        StaticClass obj2 = new StaticClass();

        obj2.method(); // non static methods need an object
    }
}
