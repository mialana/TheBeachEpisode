Get-ChildItem -Recurse -Path Coastal\Source `
    -Include *.h, *.cpp, *.inl | 
    ForEach-Object { clang-format -i -style=file $_.FullName}
