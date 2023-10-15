using MySql.Data.MySqlClient;
using System.Data;

namespace TestProject1
{
    [TestFixture]
    public class SimpleTests
    {
        [Test] //testi testi
        public void Test_SimpleAssertion()
        {
            int actual = 5;
            int expected = 5;

            Assert.That(actual, Is.EqualTo(expected));
        }
    }
    [TestFixture]
    public class DatabaseTests
    {
        [Test]
        public void Test_DatabaseConnection()
        {
            string testConnectionString = "Server=192.168.50.45;Port=3307;User ID=remote;Password=Password1;Database=Game_List;";

            using (MySqlConnection con = new MySqlConnection(testConnectionString))
            {
                try
                {
                    con.Open();
                    Assert.AreEqual(ConnectionState.Open, con.State);
                }
                catch (Exception ex)
                {
                    Assert.Fail($"Database connection failed with the following error: {ex.Message}");
                }
            }
        }
    }
}
