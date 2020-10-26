git init
git remote add origin https://github.com/Irhaml/MyCode
git add .
set /p count=<Counter.txt
set /a count+=1
echo %a% > Counter.txt
echo %a%
git commit -m "Perubahan ke %a%"
git push origin master