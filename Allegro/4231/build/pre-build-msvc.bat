@ECHO OFF
COPY /B ..\tools\plugins\*.inc ..\obj\msvc\plugins.h

ECHO // Generated by pre-build-msvc.bat > ..\include\allegro\platform\alplatf.h
ECHO #define ALLEGRO_MSVC >> ..\include\allegro\platform\alplatf.h

pause