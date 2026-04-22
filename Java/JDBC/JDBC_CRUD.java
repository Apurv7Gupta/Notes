import java.sql.*;

public class Main {

    static String url = "jdbc:mysql://localhost:3306/testdb";
    static String username = "root";
    static String password = "1234";

    public static void main(String[] args) {

        try {
            Connection con = DriverManager.getConnection(url, username, password);

            // =========================
            // CREATE (INSERT)
            // =========================
            String insertQuery = "INSERT INTO students(id, name) VALUES(?, ?)";

            PreparedStatement insertStmt = con.prepareStatement(insertQuery);

            insertStmt.setInt(1, 1);
            insertStmt.setString(2, "Rin");

            insertStmt.executeUpdate();

            System.out.println("Data Inserted");

            // =========================
            // READ (SELECT)
            // =========================
            String selectQuery = "SELECT * FROM students";

            Statement selectStmt = con.createStatement();

            ResultSet rs = selectStmt.executeQuery(selectQuery);

            while (rs.next()) {

                int id = rs.getInt("id");
                String name = rs.getString("name");

                System.out.println(id + " " + name);
            }

            // =========================
            // UPDATE
            // =========================
            String updateQuery = "UPDATE students SET name=? WHERE id=?";

            PreparedStatement updateStmt = con.prepareStatement(updateQuery);

            updateStmt.setString(1, "Alice");
            updateStmt.setInt(2, 1);

            updateStmt.executeUpdate();

            System.out.println("Data Updated");

            // =========================
            // DELETE
            // =========================
            String deleteQuery = "DELETE FROM students WHERE id=?";

            PreparedStatement deleteStmt = con.prepareStatement(deleteQuery);

            deleteStmt.setInt(1, 1);

            deleteStmt.executeUpdate();

            System.out.println("Data Deleted");

            // Close connection
            con.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}


// ====================== Table Used ======================
// CREATE TABLE students (
//     id INT PRIMARY KEY,
//     name VARCHAR(50)
// );
// ========================================================
