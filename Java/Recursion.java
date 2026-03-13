public class Recursion {

    public static void main(String[] args) {

        // Self
        System.out.println(Factorial(5));

        // Indirect
        First(5);

    }

    // ----------Self Recursion----------

    public static int Factorial(int n) {

        if (n == 0 || n == 1) {
            return 1;
        }

        return n * Factorial(n - 1); // Calling itself as return statement

    }

    // ----------Indirect recursion----------

    static void First(int n) {

        if (n <= 0) {
            return;
        }

        System.out.println("Second: " + n);

        Second(n - 1);
    }

    static void Second(int n) {

        if (n <= 0) {
            return;
        }

        System.out.println("First: " + n);

        First(n - 1);
    }

}

// First() → Second() → First() → Second()
