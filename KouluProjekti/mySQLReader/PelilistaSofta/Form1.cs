using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
using Database;

namespace mySQLReader
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // Create instance of the Database class
        private Database.Database db = new Database.Database();

        string selectedDatabase;
        string selectedTable;

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selectedItem = listBox1.SelectedItem.ToString();

            selectedDatabase = selectedItem;

            UpdateListBox2();
        }

        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selectedItem2 = listBox2.SelectedItem.ToString();

            selectedTable = selectedItem2;
        }

        private void UpdateListBox2()
        {
            listBox2.Items.Clear();

            string connectionString = BuildConnectionString().ToString();
            
            DataTable dt = db.ExecuteQuery(connectionString, $"SHOW TABLES FROM `{selectedDatabase}`", selectedDatabase);

            foreach (DataRow row in dt.Rows)
            {
                string tableName = row[0].ToString();

                string formattedTableName = $"`{tableName}`";

                listBox2.Items.Add(formattedTableName);
            }
        }

        public MySqlConnectionStringBuilder BuildConnectionString()
        {
            MySqlConnectionStringBuilder conn_string = new MySqlConnectionStringBuilder();

            conn_string.Server = textBox9.Text;
            conn_string.Port = uint.Parse(textBox10.Text);
            conn_string.UserID = textBox11.Text;
            conn_string.Password = textBox12.Text;
            conn_string.Database = selectedDatabase;

            return conn_string;
        }

        private void button1_Click(object sender, EventArgs e)
        {

            if (listBox2.SelectedItem == null)
            {
                MessageBox.Show("no table selected");
                return;
            }
            else
            {
                string selectedTable = listBox2.SelectedItem.ToString();
            }

            //Connection
            string connectionString = BuildConnectionString().ToString();

            DataTable dt = db.ExecuteQuery(connectionString, "SELECT * FROM " + selectedTable, selectedDatabase);

            dataGridView1.DataSource = dt;

            listBox3.Items.Clear();

            foreach (DataColumn column in dt.Columns) //Loop and add the names to listbox
            {
                listBox3.Items.Add(column.ColumnName);
            }
        }

        private void button16_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            string connectionString = BuildConnectionString().ToString();

            DataTable dt = db.ExecuteQuery(connectionString, "SHOW DATABASES" ,selectedDatabase);

            foreach (DataRow row in dt.Rows) //Loop and add the names to listbox
            {
                string databaseName = row[0].ToString();

                listBox1.Items.Add(databaseName);
            }
        }
        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton4.Checked)
            {
                textBox2.Visible = true; 
            }
            else 
            {
                textBox2.Visible = false; 
            }
        }
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                textBox2.Visible = false;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string selectedColumn = null;
            if (listBox3.SelectedItem != null) //get the selected table/column
            {
                selectedColumn = listBox3.SelectedItem.ToString();
            }
            else //nothing is selected
            {
                MessageBox.Show("no column selected");
                return;
            }

            string searchText = textBox1.Text; //user input 1
            string searchText2 = textBox2.Text; //user input 2

            string connectionString = BuildConnectionString().ToString();

            RadioButton selectedRadioButton = null;
            if (radioButton1.Checked)
            {
                selectedRadioButton = radioButton1;
            }
            else if (radioButton2.Checked)
            {
                selectedRadioButton = radioButton2;
            }
            else if (radioButton3.Checked)
            {
                selectedRadioButton = radioButton3;
            }
            else if (radioButton4.Checked)
            {
                selectedRadioButton = radioButton4;
            }
            else if (radioButton5.Checked)
            {
                selectedRadioButton = radioButton5;
            }
            else if (radioButton6.Checked)
            {
                selectedRadioButton = radioButton6;
            }


            string query = "";
            if (selectedRadioButton == radioButton1)
            {
                query = $"SELECT * FROM {selectedTable} WHERE {selectedColumn} = '{searchText}'";
            }
            else if (selectedRadioButton == radioButton2)
            {
                query = $"SELECT * FROM {selectedTable} WHERE {selectedColumn} NOT LIKE '%{searchText}%'";
            }
            else if (selectedRadioButton == radioButton3)
            {
                query = $"SELECT * FROM {selectedTable} WHERE {selectedColumn} LIKE '%{searchText}%'";
            }
            else if (selectedRadioButton == radioButton4)
            {
                query = $"SELECT * FROM {selectedTable} WHERE {selectedColumn} BETWEEN '{searchText}' AND '{searchText2}'";
            }
            else if (selectedRadioButton == radioButton5)
            {
                query = $"SELECT MIN({selectedColumn}) FROM {selectedTable}";
            }
            else if (selectedRadioButton == radioButton6)
            {
                query = $"SELECT MAX({selectedColumn}) FROM {selectedTable}";
            }

            label16.Text = query;

            DataTable dt = db.ExecuteQuery(connectionString, query, selectedDatabase);

            dataGridView1.DataSource = dt;
        }
    }
}

