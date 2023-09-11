#include "BlitzWareAuth.h"
#include "skStr.h"

/*
	BlitzWare C++ example
	Please read our docs at https://docs.blitzware.xyz/
*/

using namespace BlitzWare;

std::string apiUrl = skCrypt("https://api.blitzware.xyz/api/").decrypt();
std::string appName = skCrypt("TestAPI").decrypt();
std::string appSecret = skCrypt("e2b8129d620ad01f9b31aec1b5483d36e7aaf289d4e264d6ba12a9d9ec955ed3").decrypt();
std::string appVersion = skCrypt("1.0").decrypt();

API BlitzWareAuth(apiUrl, appName, appSecret, appVersion);

int main()
{
	std::cout << skCrypt("\n\nConnecting...");
	BlitzWareAuth.Initialize();
	std::cout << skCrypt("\nConnected!");

	std::cout << skCrypt("\n\n[1] Login\n[2] Register\n[3] Extend subscription\n[4] License key only\n\nChoose option: ");

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
		std::cout << skCrypt("\n\nEnter username: ");
		std::cin >> username;
		std::cout << skCrypt("\nEnter password: ");
		std::cin >> password;
		std::cout << skCrypt("\nEnter 2FA (if enabled): ");
		std::cin >> twoFactorCode;
		if (BlitzWareAuth.Login(username, password, twoFactorCode)) {
			BlitzWareAuth.Log(username, "User logged in");
			break;
		}
		else
			exit(0);
	case 2:
		std::cout << skCrypt("\n\nEnter username: ");
		std::cin >> username;
		std::cout << skCrypt("\nEnter password: ");
		std::cin >> password;
		std::cout << skCrypt("\nEnter email: ");
		std::cin >> email;
		std::cout << skCrypt("\nEnter license: ");
		std::cin >> key;
		if (BlitzWareAuth.Register(username, password, email, key)) {
			BlitzWareAuth.Log(username, "User registered");
			break;
		}
		else
			exit(0);
	case 3:
		std::cout << skCrypt("\n\nEnter username: ");
		std::cin >> username;
		std::cout << skCrypt("\nEnter password: ");
		std::cin >> password;
		std::cout << skCrypt("\nEnter license: ");
		std::cin >> key;
		if (BlitzWareAuth.Extend(username, password, key)) {
			BlitzWareAuth.Log(username, "User extended");
			break;
		}
		else
			exit(0);
	case 4:
		std::cout << skCrypt("\nEnter license: ");
		std::cin >> key;
		if (BlitzWareAuth.LoginLicenseOnly(key)) {
			BlitzWareAuth.Log(key, "User login with license");
			break;
		}
		else
			exit(0);
	default:
		std::cout << skCrypt("\n\nInvalid Selection");
		Sleep(3000);
		exit(0);

	}

	std::cout << skCrypt("\nUser data:");
	std::cout << skCrypt("\nUsername: ") << BlitzWareAuth.userData.username;
	std::cout << skCrypt("\nEmail: ") << BlitzWareAuth.userData.email;
	std::cout << skCrypt("\nIP-address: ") << BlitzWareAuth.userData.lastIP;
	std::cout << skCrypt("\nHardware-Id: ") << BlitzWareAuth.userData.hwid;
	std::cout << skCrypt("\nLast login: ") << BlitzWareAuth.userData.lastLogin;
	std::cout << skCrypt("\nSubscription expiry: ") << BlitzWareAuth.userData.expiry;

	std::cout << skCrypt("\n\nClosing in five seconds...");
	Sleep(5000);
	exit(0);
}