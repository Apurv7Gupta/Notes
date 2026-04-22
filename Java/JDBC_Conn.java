// for MySQL

import java.sql.Connection;
import java.sql.DriverManager;

public class Main {

    public static void main(String[] args) {

        String url = "jdbc:mysql://localhost:3306/testdb";
        String username = "root";
        String password = "1234";

        try {
            // Connect to database
            Connection con = DriverManager.getConnection(url, username, password);

            System.out.println("Connected Successfully!");

            // Close connection
            con.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
