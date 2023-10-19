chcp 1251

rmdir /S /Q lesson-02

mkdir lesson-02
cd lesson-02

mkdir diary log backup

echo "Начало работы: %date% %time%" > diary\\%date%.txt
echo "%date% %time% - Дневник создан" > log\\log-%date%.txt
tree /A /F 1>>diary\\%date%.txt
echo "Конец работы: %date% %time%" >> diary\\%date%.txt

mkdir backup\\%date%
xcopy diary backup\\%date%\\diary /I /E
xcopy log backup\\%date%\\log /I /E

cd ..
