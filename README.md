# BlitzWare-CPP-Example
>
> BlitzWare Auth C++ basic example.
>
> *Disclaimer: this is just very basic implementations of our api, modify it to your needs!*


## Install required packages:
https://vcpkg.io/en/
1.  open cmd as admin
2.  go to a directory where you want to install vcpkg
3.  `git clone https://github.com/Microsoft/vcpkg.git` (or just download the .zip file)
4.  `.\vcpkg\bootstrap-vcpkg.bat`
5.  `cd vcpkg`
6.  `vcpkg install cpr --triplet x64-windows-static`
7.  `vcpkg install cpr --triplet x86-windows-static`
8.  `vcpkg install curl --triplet x64-windows-static`
9.  `vcpkg install curl --triplet x86-windows-static`
10. `vcpkg install nlohmann-json --triplet x64-windows-static`
11. `vcpkg install nlohmann-json --triplet x86-windows-static`
12. `vcpkg install openssl --triplet x64-windows-static`
13. `vcpkg install openssl --triplet x86-windows-static`
14. `vcpkg integrate install`
15. restart your IDE (Visual Studio)
16. Project->Properties->Configuration Properties->vcpkg->"Use Vcpkg":"Yes" and "Use Static Libraries":"Yes"


