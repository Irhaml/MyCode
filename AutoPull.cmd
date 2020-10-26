git init
git remote add origin https://github.com/Irhaml/MyCode
git add .
set /p count=<Counter.txt
set /a count+=1
echo %count% > Counter.txt
echo %count%
git commit -m "Irham -> perubahan ke %count%"
git push origin master