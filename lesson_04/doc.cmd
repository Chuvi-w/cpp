"..\AStyle" --options=..\astyle.cfg --recursive *.c 
"..\AStyle" --options=..\astyle.cfg --recursive *.cpp 
"..\AStyle" --options=..\astyle.cfg --recursive *.h 

SET PATH=C:\Python34;%PATH%
python.exe doc.py