SET PATH=C:\Python34;%PATH%
python.exe doc.py

"..\AStyle" --options=..\astyle.cfg --recursive *.c 
"..\AStyle" --options=..\astyle.cfg --recursive *.cpp 
"..\AStyle" --options=..\astyle.cfg --recursive *.h 

git add .
git commit -a -m"Save changes"
git pull
git push