public class Recursion {

    public static int Factorial(int n) {

        if (n == 0 || n == 1) {
            return 1;
        }

        return n * Factorial(n - 1); // Calling itself as return statement

    }

    public static void main(String[] args) {

        System.out.println(Factorial(5));

    }

}
