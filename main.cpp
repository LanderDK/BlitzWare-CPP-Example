#include "BlitzWareAuth.h"
#include "skStr.h"

/*
	BlitzWare C++ example
	Please read our docs at https://docs.blitzware.xyz/
*/

using namespace BlitzWare;

std::string apiUrl = skCrypt("https://api.blitzware.xyz/api/").decrypt();
std::string appName = skCrypt("NAME").decrypt();
std::string appSecret = skCrypt("SECRET").decrypt();
std::string appVersion = skCrypt("VERSION").decrypt();

API BlitzWareAuth(apiUrl, appName, appSecret, appVersion);

int main()
{
	std::cout << skCrypt("\n\n Connecting...");
	BlitzWareAuth.Initialize();
	std::cout << skCrypt("\n Connected!");

	std::cout << skCrypt("\n\n [1] Login\n [2] Register\n [3] Extend subscription\n [4] License key only\n\n Choose option: ");

	int option;
	std::string username;
	std::string email;
	std::string password;
	std::string twoFactorCode;
	std::string key;

	std::cin >> option;
	switch (option)
	{
	case 1:
		std::cout << skCrypt("\n\n Enter username: ");
		std::cin >> username;
		std::cout << skCrypt("\n Enter password: ");
		std::cin >> password;
		std::cout << skCrypt("\n Enter 2FA (if enabled): ");
		std::cin >> twoFactorCode;
		if (BlitzWareAuth.Login(username, password, twoFactorCode)) {
			BlitzWareAuth.Log(username, "User logged in");
			break;
		}
		else
			exit(0);
	case 2:
		std::cout << skCrypt("\n\n Enter username: ");
		std::cin >> username;
		std::cout << skCrypt("\n Enter password: ");
		std::cin >> password;
		std::cout << skCrypt("\n Enter email: ");
		std::cin >> email;
		std::cout << skCrypt("\n Enter license: ");
		std::cin >> key;
		if (BlitzWareAuth.Register(username, password, email, key)) {
			BlitzWareAuth.Log(username, "User registered");
			break;
		}
		else
			exit(0);
	case 3:
		std::cout << skCrypt("\n\n Enter username: ");
		std::cin >> username;
		std::cout << skCrypt("\n Enter password: ");
		std::cin >> password;
		std::cout << skCrypt("\n Enter license: ");
		std::cin >> key;
		if (BlitzWareAuth.Extend(username, password, key)) {
			BlitzWareAuth.Log(username, "User extended");
			break;
		}
		else
			exit(0);
	case 4:
		std::cout << skCrypt("\n Enter license: ");
		std::cin >> key;
		if (BlitzWareAuth.LoginLicenseOnly(key)) {
			BlitzWareAuth.Log(key, "User login with license");
			break;
		}
		else
			exit(0);
	default:
		std::cout << skCrypt("\n\n Invalid Selection");
		Sleep(3000);
		exit(0);

	}

	std::cout << skCrypt("\n User data:");
	std::cout << skCrypt("\n Username: ") << BlitzWareAuth.userData.username;
	std::cout << skCrypt("\n Email: ") << BlitzWareAuth.userData.email;
	std::cout << skCrypt("\n IP-address: ") << BlitzWareAuth.userData.lastIP;
	std::cout << skCrypt("\n Hardware-Id: ") << BlitzWareAuth.userData.hwid;
	std::cout << skCrypt("\n Last login: ") << BlitzWareAuth.userData.lastLogin;
	std::cout << skCrypt("\n Subscription expiry: ") << BlitzWareAuth.userData.expiry;

	std::cout << skCrypt("\n\n Closing in five seconds...");
	Sleep(5000);
	exit(0);
}