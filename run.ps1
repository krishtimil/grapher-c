Remove-Item ./build -Force -Recurse
xmake
Remove-Item ./grapher-c.exe -ErrorAction:SilentlyContinue
Move-Item ./build/windows/x64/release/grapher-c.exe ./grapher-c.exe
./grapher-c.exe