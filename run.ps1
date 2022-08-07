Remove-Item ./build -Force -Recurse -ErrorAction:SilentlyContinue
$grapher = Get-Process grapher-c -ErrorAction:SilentlyContinue
if($grapher){
    $grapher | Stop-Process -Force
}
xmake
if($LASTEXITCODE -ne 0){
    return
}
Remove-Item ./grapher-c.exe -ErrorAction:SilentlyContinue
Move-Item ./build/windows/x64/release/grapher-c.exe ./grapher-c.exe
./grapher-c.exe