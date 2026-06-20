Get-ChildItem -Recurse -Path TheBeachEpisode\Source `
    -Include *.h, *.cpp, *.inl | 
    ForEach-Object { clang-format -i -style=file $_.FullName}
