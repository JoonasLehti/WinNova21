using MySql.Data.MySqlClient;
using System;
using System.Data;

namespace Database
{
    public class Database
    {
        public DataTable ExecuteQuery(string connectionString, string commandText, string selectedDatabase)
        {
            // Create a connection object using the connection string
            using (MySqlConnection con = new MySqlConnection(connectionString))
            {
                // Open the connection
                con.Open();

                // Create a command object using the command text
                using (MySqlCommand cmd = con.CreateCommand())
                {
                    cmd.CommandType = CommandType.Text;
                    cmd.CommandText = commandText;

                    // Execute the command and get the result
                    using (MySqlDataAdapter da = new MySqlDataAdapter(cmd))
                    {
                        // Set the value of the parameter
                        cmd.Parameters.AddWithValue("@DatabaseName", selectedDatabase);

                        // Create a data table object and fill it with the data
                        DataTable dt = new DataTable();
                        da.Fill(dt);

                        // Return the data table
                        return dt;
                    }
                }
            }
        }
    }
}
