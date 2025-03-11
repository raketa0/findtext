echo Running tests...

REM Тест 1: Поиск существующего текста
SET MyProgram="%~1"
echo MyProgram
echo %MyProgram%
%MyProgram% "input.txt" "I'm writing"
if %errorlevel% equ 0 (
    echo Test 1 passed
) else (
    echo Test 1 failed
)

REM Тест 2: Поиск несуществующего текста
%MyProgram% "input.txt" "онегин"
if %errorlevel% equ 1 (
    echo Test 2 passed
) else (
    echo Test 2 failed
)

REM Тест 3: Поиск с учетом регистра
%MyProgram% "input.txt" "меня"
if %errorlevel% equ 1 (
    echo Test 3 passed
) else (
    echo Test 3 failed
)

REM Тест 4: Ошибка открытия файла
%MyProgram% "Евген.txt" "онегин"
if %errorlevel% equ 1 (
    echo Test 4 passed
) else (
    echo Test 4 failed
)

REM Тест 5: Запуск файла на русском языке
%MyProgram% "Евгений Онегин.txt" "Что"
if %errorlevel% equ 1 (
    echo Test 5 passed
) else (
    echo Test 5 failed
)

echo All tests completed.