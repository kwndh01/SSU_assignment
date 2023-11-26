cmake_minimum_required(VERSION 3.24)
project(SSU_assignment C)

set(CMAKE_C_STANDARD 11)

add_executable(SSU_assignment
        ProgrammingLanguages/Assignment1/calendar.c
        OperatingSystem/Assignment1/newps.c
        OperatingSystem/Assignment2/assignment2.c
        OperatingSystem/Assignment2/sys_print_reverse.c
        OperatingSystem/Assignment2/sys_print_reverse2.c
        AlgorithmRE/Assignment3/20212211_3.c
        InformationSecurity/Assignment1/VigenereCipher.c
        InformationSecurity/Assignment2/S-AES_Encryption.c
        InformationSecurity/Assignment2/S-AES_Decryption.c
        ProgrammingLanguages/Assignment2/interpreter.c
        ProgrammingLanguages/Assignment5/primeNumber.c
)
