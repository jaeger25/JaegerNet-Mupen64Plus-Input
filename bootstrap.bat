mkdir build & cd build
mkdir x86-windows & cd x86-windows

cmake -G "Visual Studio 15 2017" ../../Src

cd ..
mkdir x64-windows & cd x64-windows

cmake -G "Visual Studio 15 2017 Win64" ../../Src

cd ../..