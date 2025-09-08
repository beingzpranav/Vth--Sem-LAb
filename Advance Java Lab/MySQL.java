import java.sql.*;
public class MySQL {
    public static void main(String[] args) {
        String jdbcUrl = "jdbc:mysql://localhost:3306/world";
        String username = "root";
        String password = "root";

        Connection connection = null;

        try{
            //Load MySQL JDBC Driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            //Establish Connection
            connection = DriverManager.getConnection(jdbcUrl,username,password);
            if (connection != null){
                System.out.println("Successfully Connected to MySQL Databasse");
            }
        }catch(ClassNotFoundException e) {
            System.out.println("MySQL JDBC Driver not Found");
            e.printStackTrace();
        }catch (SQLException e){
            System.out.println("Connection Failed");
            e.printStackTrace();
        }finally {
            try {
                if(connection !=null){
                    connection.close();
                    System.out.println("Connection Closed");
                }
            }catch (SQLException e){
                e.printStackTrace();
            }
        }

    }
}


/* Compile using the command
   javac -cp ".;mysql-connector-j-9.0.0.jar" MySQL.java
   Run using the command
   java -cp ".;mysql-connector-j-9.0.0.jar" MySQL
*/