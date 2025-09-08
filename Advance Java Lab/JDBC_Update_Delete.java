/*Objective: To write a Java Program using JDBC that
    1. Connect Java with MySQL Database
    2. Creates Table dynamically if it does not exist
    3. Takes user input and perform database operations like Insert, Update, Delete and Display using Prepared Statement */

     // Experiment 3 Part 2

 import java.sql.*;
 import java.util.Scanner;
 public class JDBC_Update_Delete {
    public static void main(String[] args) {
        String jdbcUrl = "jdbc:mysql://localhost:3306/world"; /* For Exceptions: jdbc:mysql://localhost:3306/world?useSSL=false&serverTimezone=UTC */
        String username = "root";   
        String password = "root";
        try{
            //Load MySQL JDBC Driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            //Establish Connection
            Connection connection = DriverManager.getConnection(jdbcUrl,username,password);
            if (connection != null){
                System.out.println("Successfully Connected to MySQL Databasse");
            }
            //Create Table if not exists
            String TableQuery= "CREATE TABLE IF NOT EXISTS SectionF (" +"id INT PRIMARY KEY," +"name VARCHAR(50)," +"age INT)";

            Statement createStmt = connection.createStatement();
            createStmt.execute(TableQuery);
            System.err.println("Table 'SectionF' is created");

            //Taking user input
            Scanner scanner = new Scanner(System.in);
            System.out.println("\n Enter Records: ");
            
            
            System.out.print("Enter ID: ");
            int id = scanner.nextInt();
            scanner.nextLine();  // Consume newline left-over
            System.out.print("Enter Name: ");
            String name = scanner.next();
            System.out.println("Enter Age: ");
            int age = scanner.nextInt();

            //Insert Record
            String insertQuery = "INSERT INTO SectionF (id, name, age) VALUES (?, ?, ?)";
            PreparedStatement psmt=connection.prepareStatement(insertQuery);
            psmt.setInt(1,id);
            psmt.setString(2,name);
            psmt.setInt(3,age);

            int rowsInserted = psmt.executeUpdate();
            if (rowsInserted > 0) {
                System.out.println("A new record was inserted successfully!");
            }

            //Update Record
            String updateQuery = "UPDATE SectionF SET name = ?, age = ? WHERE id = ?";
            PreparedStatement Psmt = connection.prepareStatement(updateQuery);
            Psmt.setString(1, "UpdatedName");
            Psmt.setInt(2, age+1);
            Psmt.setInt(3, id);
            int rowsUpdated = Psmt.executeUpdate();
            if (rowsUpdated > 0) {
                System.out.println("Record updated successfully!");
            }

            //Delete Record
            System.out.println("Enter ID to delete: ");
            int deleteId = scanner.nextInt();
            String deleteQuery = "DELETE FROM SectionF WHERE id = ?";
            PreparedStatement deleteStmt = connection.prepareStatement(deleteQuery);
            deleteStmt.setInt(1, deleteId);
            int rowsDeleted = deleteStmt.executeUpdate();
            if (rowsDeleted > 0) {
                System.out.println("Record deleted successfully!");
            }

            //Display Records
            String selectQuery = "SELECT * FROM SectionF";
            Statement Stmt = connection.createStatement();
            ResultSet resultSet = Stmt.executeQuery(selectQuery);
            System.out.println("\n Records in the Table:");
            while (resultSet.next()) {
               System.out.println(resultSet.getInt("id") + " " + resultSet.getString("name") + " " + resultSet.getInt("age"));
            }
            //Close resources
            resultSet.close();
            psmt.close();
            Stmt.close();
            connection.close();

        }catch(ClassNotFoundException e) {
            System.out.println("MySQL JDBC Driver not Found");
            e.printStackTrace();
        }catch(SQLException e) {
            System.out.println("SQL Exception Occurred");
            e.printStackTrace();
        }
    }
 }