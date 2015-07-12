<<<<<<< HEAD
git add .
git commit -a -m"Save changes"
git pull
git push
=======
AStyle --options=astyle.cfg --recursive *.c 
AStyle --options=astyle.cfg --recursive *.cpp 
AStyle --options=astyle.cfg --recursive *.h 

rem Добавить все изменения
git add .
rem Сохранить их в истории с сообщением "Save changes"
git commit -a -m"Save changes"
rem Получить изменения из удалённого репозитория
git pull
rem Отправить объединённую копию
rem git push
git push --set-upstream origin master
>>>>>>> 598441b3757cbdb52d583c6c662504f14a5c615c
