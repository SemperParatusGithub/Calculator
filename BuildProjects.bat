set msBuildDir=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin
cd build
"%msBuildDir%\MSBuild.exe" /p:Platform=x64 /p:Configuration=Release /p:DisableFastUpToDateCheck=1 -m Calculator.sln

xcopy /e /v Calculator\res bin\Release-windows-x86_64\Calculator\res /i
