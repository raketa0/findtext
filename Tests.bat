echo Running tests...

REM ���� 1: ����� ������������� ������
SET MyProgram="%~1"
echo MyProgram
echo %MyProgram%
%MyProgram% "input.txt" "I'm writing"
if %errorlevel% equ 0 (
    echo Test 1 passed
) else (
    echo Test 1 failed
)

REM ���� 2: ����� ��������������� ������
%MyProgram% "input.txt" "������"
if %errorlevel% equ 1 (
    echo Test 2 passed
) else (
    echo Test 2 failed
)

REM ���� 3: ����� � ������ ��������
%MyProgram% "input.txt" "����"
if %errorlevel% equ 1 (
    echo Test 3 passed
) else (
    echo Test 3 failed
)

REM ���� 4: ������ �������� �����
%MyProgram% "�����.txt" "������"
if %errorlevel% equ 1 (
    echo Test 4 passed
) else (
    echo Test 4 failed
)

REM ���� 5: ������ ����� �� ������� �����
%MyProgram% "������� ������.txt" "���"
if %errorlevel% equ 1 (
    echo Test 5 passed
) else (
    echo Test 5 failed
)

echo All tests completed.