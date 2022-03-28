Compress-Archive -Force -Path "cpp\*.*" -DestinationPath ".\cpp.zip"
Compress-Archive -Force -Path "csharp\*.*", "csharp\Properties" -DestinationPath ".\csharp.zip"
Compress-Archive -Force -Path "vbnet\*.*", "vbnet\My Project" -DestinationPath ".\vbnet.zip"
