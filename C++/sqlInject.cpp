/********************************************
 * Names: 
 *
 *
 *
 *
 *
 *********************************************/

#include <iostream>
#include <string>

using namespace std;

// Test case examples with username and password
/*  TEST CASE 1:  Username: joshm
                  Password: password1
    TEST CASE 2:  Username: riom
                  Password: pass2
    TEST CASE 3:  Username: michealf
                  Password: Maryhadalittlelambwhosefleecewaswhiteassnow
    TEST CASE 4:  Username: jasonj
                  Password: 234Uj88
    TEST CASE 5:  Username: robbyb
                  Password: Bro_Halfrich_rules
 */

/*******************************************
 * QUERY GENERATOR for username and password
 * *****************************************/
string qGenerator(string username, string password)
{
  return "SELECT authenticate FROM users WHERE name='" + username + "' AND password='" + password + "';";
}

/********************************************
*Strong mitigation
**********************************************/
string strongMitigation(string username, string password)
{
	for (int i = 0; i < username.length(); i++) // check username validation
  {
		if (!isalnum(username[i]) && username[i] != '_')
    {
			return "Invalid Input"; 
		}
	}
  
	for (int i = 0; i < password.length(); i++) // check password validation
  {
		if (!isalnum(password[i]) && password[i] != '_')
    {
			return "Invalid Input";
		}
	}
	return qGenerator(username, password);
}

/**************************************
 * Strong Mitigation Display
 * ***********************************/
void strongMitigationDisplay() 
{
  string username[] = {"robby2b", "josh_m", "jasonj", "ri0m' --"}; // usernames to test strong mitigation
  string password[] = {"nada' OR 'x' = 'x", "mayberryj' UNION SELECT authenticate FROM users", "jenkinsj'; DROP TABLE users", "2we_love4_stuff"}; // passwords to test weak mitigation
  string attackType[] = {"Tautology Attack", "Union Query Attack", "Additional Statement Attack", "Comment Attack"};
  cout << "*************************************************************" << endl;
  cout << "Strong Mitigation Example: " << endl;
  for (int i = 0; i < 4; i++)
  {
    cout << endl << attackType[i] << " Example" << endl;
    cout << "Insert username: " << username[i] << endl;
    cout << "Insert Password: " << password[i] << endl;
    string query = strongMitigation(username[i], password[i]);
    cout << "Query generated: " << query << endl << endl;
  }
}

/********************************************
*Weak Mitigation - Tautology
*********************************************/
string weakTautologyMitigation(string username, string password)
{
	size_t uFound = username.find("="); // check validation for username
  if (uFound != string::npos) 
  {
    return "Invalid Input";
  }

  size_t pFound = password.find("="); // check validation for password
  if (pFound != string::npos)
  {
    return "Invalid Input";
  }
	return qGenerator(username, password);
}

/********************************************
* Weak Mitigation - Union
*********************************************/
string weakUnionMitigation(string username, string password)
{
  size_t uFound = username.find("UNION "); // check validation for username
  if (uFound != string::npos) 
  {
    return "Invalid Input";
  }

  size_t pFound = password.find("UNION "); // check validation for password
  if (pFound != string::npos)
  {
    return "Invalid Input";
  }

	return qGenerator(username, password);
}

/********************************************
* Weak Mitigation - Additional
*********************************************/
string weakAdditionalMitigation(string username, string password)
{
	size_t uFound = username.find(";"); // check validation for username
  if (uFound != string::npos) 
  {
    return "Invalid Input";
  }

  size_t pFound = password.find(";"); // check validation for password
  if (pFound != string::npos)
  {
    return "Invalid Input";
  }

	return qGenerator(username, password);
}

/********************************************
*Weak Mitigation - Comment
*********************************************/
string weakCommentMitigation(string username, string password)
{
	size_t uFound = username.find("--"); // check validation for username
  if (uFound != string::npos) 
  {
    return "Invalid Input"; 
  }

  size_t pFound = password.find("--"); // check validation for password
  if (pFound != string::npos)
  {
    return "Invalid Input";
  }

	return qGenerator(username, password);
}

/**************************************
 * Weak Mitigation Display
 * ***********************************/
void weakMitigationDisplay() 
{
  string username[] = {"robby2b", "josh_m", "jasonj", "ri0m' --"}; // usernames to test weak mitigation
  string password[] = {"nada' OR 'x' = 'x", "mayberryj' UNION SELECT authenticate FROM users", "jenkinsj'; DROP TABLE users", "2we_love4_stuff"}; // passwords to test weak mitigation
  string attackType[] = {"Tautology Attack", "Union Query Attack", "Additional Statement Attack", "Comment Attack"};
    cout << "**************************************************************" << endl;
  cout << "Weak Tautology Mitigation Example: " << endl;
  for (int i = 0; i < 4; i++) //tautology
  {
    cout << endl << attackType[i] << endl;
    cout << "Insert username: " << username[i] << endl;
    cout << "Insert Password: " << password[i] << endl;
    string query = weakTautologyMitigation(username[i], password[i]);
    cout << "Query generated: " << query << endl << endl;
  }
  
  cout << "**************************************************************" << endl;
  cout << "Weak Union Mitigation Example: " << endl;
  for (int i = 0; i < 4; i++) //union attack
  {
    cout << endl << attackType[i] << endl;
    cout << "Insert username: " << username[i] << endl;
    cout << "Insert Password: " << password[i] << endl;
    string query = weakUnionMitigation(username[i], password[i]);
    cout << "Query generated: " << query << endl << endl;
  }
  
  cout << "**************************************************************" << endl;
  cout << "Weak Additional Mitigation Example: " << endl;
  for (int i = 0; i < 4; i++) //additional
  {
    cout << endl << attackType[i] << endl;
    cout << "Insert username: " << username[i] << endl;
    cout << "Insert Password: " << password[i] << endl;
    string query = weakAdditionalMitigation(username[i], password[i]);
    cout << "Query generated: " << query << endl << endl;
  }
  
  cout << "**************************************************************" << endl;
  cout << "Weak Comment Mitigation Example: " << endl;
  for (int i = 0; i < 4; i++) //comment
  {
    cout << endl << attackType[i] << endl;
    cout << "Insert username: " << username[i] << endl;
    cout << "Insert Password: " << password[i] << endl;
    string query = weakCommentMitigation(username[i], password[i]);
    cout << "Query generated: " << query << endl << endl;
  }
}

/***************************
* Test Cases for valid input
****************************/
void validInput()
{
  string username[] = {"josh2m", "rio_m", "michealf", "jasonj", "robby2b"};  // usernames to test
  string password[] = {"password_1", "pass2" ,"Maryhadalittlelambwhosefleecewaswhiteassnow", "234Uj88", "Bro_Halfrich_rules"}; // passwords to test

  for (int i = 0; i < 5; i++) // runs amount of test for each vulnerability
  {
    string loggedIn = qGenerator(username[i], password[i]);  // finds information in query generator
    cout << "Test Case Valid Input #" << (i+1) << ":" << endl;
    cout << "Insert username: " << username[i] << endl;
    cout << "Insert password: " << password[i] << endl;
    cout << "Query generated: " << loggedIn    << endl << endl;
  }
}

/****************************************
* Test Cases for vulnerability: Tautology
*****************************************/
void tautologyAttack()
{
  string username = "joshm"; // username from test cases
  string attack = "nada' OR 'x' = 'x"; // possible attack

  string loggedIn = qGenerator(username, attack); // finds information in query generator
  cout << "**************************************************************" << endl;
  cout << "Test Case Tautology Attack:"   << endl;
  cout << "Insert username: " << username << endl;
  cout << "Insert password: " << attack   << endl;
  cout << "Query generated: " << loggedIn << endl << endl;
}

/******************************************
* Test Cases for vulnerability: Union Query
*******************************************/
void unionAttack()
{
  string username = "joshm";                                         // username from test cases
  string attack = "mayberryj' UNION SELECT authenticate FROM users"; // possible attack

  string loggedIn = qGenerator(username, attack); // finds information in query generator
  cout << "**************************************************************" << endl;
  cout << "Test Case Union Query Attack:" << endl;
  cout << "Insert username: " << username << endl;
  cout << "Insert password: " << attack   << endl;
  cout << "Query generated: " << loggedIn << endl << endl;
}

/**********************************************************
* Test Cases for vulnerability: Additional Statement Attack
***********************************************************/
void additionalAttack()
{
  string username[] = {"joshm", "jenkinsj"}; // usernames from test cases
  string attack[] = {"mayberryj'; INSERT INTO users (name, password) VALUES 'mayberryj', 'myPassword",
                     "jenkinsj'; DROP TABLE users"}; // possible attacks
 
  for (int i = 0; i < 2; i++) // loops through username and password for testing
  {
    string loggedIn = qGenerator(username[i], attack[i]);  // finds information in query generator
    cout << "**************************************************************" << endl;
    cout << "Test Case Additional Statement Attack #" << (i+1) << ":" << endl;
    cout << "Insert username: "  << username[i] << endl;
    cout << "Insert password: "  << attack[i]   << endl;
    cout << "Query generated: "  << loggedIn    << endl << endl;
  }
}

/**********************************************
* Test Cases for vulnerability: Comment Attack
***********************************************/
void commentAttack()
{
  string attack = "riom'; --"; // possible attacks
  string password = "mourar"; // passwords from test cases

    string loggedIn = qGenerator(attack, password); // finds information in query generator
    cout << "**************************************************************" << endl;
    cout << "Test Case Comment Attack:" << endl;
    cout << "Insert username: "  << attack        << endl;
    cout << "Insert password: "  << password      << endl;
    cout << "Query generated: "  << loggedIn      << endl << endl;
}

/**************************************************
 * MAIN
 * ************************************************/
int main(int argc, char const *argv[])
{
    validInput();       // call to demonstrate the vulnerability of our query generator
    tautologyAttack();  // call to demonstrate the tautology attack
    unionAttack();      // call to demonstrate the union query attack
    additionalAttack(); // call to demonstrate the additional statement attack
    commentAttack();    // call to demonstrate the comment attack
    weakMitigationDisplay(); // call to display weak mitigation
    strongMitigationDisplay(); // call to display strong mitigation
    return 0;
}