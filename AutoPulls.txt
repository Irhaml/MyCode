git init
git remote add origin https://github.com/Irhaml/MyCode
git add .
set /p count=<Counter.txt
set /a count+=1
echo %a% > Counter.txt
git commit -m "Perubahan ke "
git push origin master