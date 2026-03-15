
import java.util.Scanner;

// Two ways to open a scanner for input
public class JavaIO {

    public static void main(String[] args) {

        // -------Method 1-----------
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");

        int number = sc.nextInt();

        System.out.println(number);
        sc.close();
        // -------End of method 1-------

        TryWithResources.TWR();

    }

    // Method 2 (Auto close)

    static class TryWithResources {

        static void TWR() {
            try (Scanner sc = new Scanner(System.in)) {
                System.out.print("Enter a number: ");
                int number = sc.nextInt();

                System.out.println(number);
            }

        }

    }

}
