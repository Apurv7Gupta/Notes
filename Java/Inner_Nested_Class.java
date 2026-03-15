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
