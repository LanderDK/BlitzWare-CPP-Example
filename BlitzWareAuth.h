#ifndef BLITZWAREAUTH_H
#define BLITZWAREAUTH_H

#include <Windows.h>
#include <iostream>

namespace BlitzWare {
    class Security {
    public:
        static std::string CalculateResponseHash(const std::string& data);
        static std::string CalculateFileHash(const char* filename);
    };

    class Utilities {
    public:
        static std::string RemoveQuotesFromString(const std::string& s);
        static std::string HWID();
        static std::string IP();
    };

    class API {
    public:
        const std::string apiUrl;
        const std::string appName;
        const std::string appSecret;
        const std::string appVersion;
        bool initialized;

        class ApplicationData {
        public:
            inline static std::string id;
            inline static std::string name;
            inline static bool status;
            inline static bool hwidCheck;
            inline static bool developerMode;
            inline static bool integrityCheck;
            inline static bool freeMode;
            inline static bool twoFactorAuth;
            inline static std::string programHash;
            inline static std::string version;
            inline static std::string downloadLink;
        };
        ApplicationData appData;

        class UserData {
        public:
            inline static std::string id;
            inline static std::string username;
            inline static std::string email;
            inline static std::string hwid;
            inline static std::string expiry;
            inline static std::string lastLogin;
            inline static std::string lastIP;
            inline static std::string authToken;
        };
        UserData userData;

        API(const std::string& apiUrl, const std::string& appName, const std::string& appSecret, const std::string& appVersion);

        void Initialize();
        bool Register(const std::string& username, const std::string& password, const std::string& email, const std::string& license);
        bool Login(const std::string& username, const std::string& password, const std::string& twoFactorCode);
        bool LoginLicenseOnly(const std::string& license);
        bool Extend(const std::string& username, const std::string& password, const std::string& license);
        void Log(const std::string& username, const std::string& action);
    };
}

#endif // BLITZWAREAUTH_H
