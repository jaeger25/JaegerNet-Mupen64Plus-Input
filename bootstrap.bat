mkdir build & cd build
mkdir x86-windows & cd x86-windows

cmake -G "Visual Studio 15 2017" "-DCMAKE_TOOLCHAIN_FILE=../../Dependencies/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_INSTALL_PREFIX=../../installed" "-DCMAKE_PREFIX_PATH=../../Dependencies/installed/x86-windows/share" ../../Src

cd ..
mkdir x64-windows & cd x64-windows

cmake -G "Visual Studio 15 2017 Win64" "-DCMAKE_TOOLCHAIN_FILE=../../Dependencies/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_INSTALL_PREFIX=../../installed" "-DCMAKE_PREFIX_PATH=../../Dependencies/installed/x64-windows/share" ../../Src

cd ../..