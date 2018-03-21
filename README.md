A library intended to interface with kissfft for my visualizer called Drop.

Windows Compilation:

1. Need Visual Studio Command Line Tools.
2. Put relevant files in "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin" or equivalent directory.
3. Open cmd as admin
4. Run "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"
5. Cd to "bin"
6. Run `cl /LD /EHsc fft_windows.c kiss_fft.c kiss_fftr.c`

"fft_windows.dll" should now be in the bin directory.  Rename it to "fft.dll".

Mac Compilation:

1. Navigate to source directory
2. Run `gcc -dynamiclib -o libfft.dylib fft_mac.c kiss_fft.c kiss_fftr.c`

"libfft.dylib" should now be in the source directory.
