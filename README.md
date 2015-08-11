# Assignment-1---Warboats-1
Local Change Log ------------------------------------------------------------------------------------------------------

8/10/2015 - First pushable verion of the project. Issues regaurding the project needing to work when moved to a
different directory needed to be worked out.
- Project no longer uses directories for files that extend from the C drive. For example "C:\...\...\"
 This was unreliable in that moving the project's location meant changing every directory. Directories now use the
 command for moving a level toward the parent directory. For example, The executable C:\Users\Tardis\Folder1\a.exe
 must be accesed from a this directory C:\Users\Tardis\Folder2. This was initially implemeted by using this
 directory to access the executable C:\Users\Tardis\Folder1\a.exe. The improved version ..\Folder2\a.exe.

 
Makefiles all work seperately from each other so they cna be used independantly from each other to create an executable 
for only on driver.

----Batch Files----
Clean.bat - Deletes all obj files, Executables.

CompleteTest.bat - Compiles all source code creating obj files for every driver, compiles obj into executables, 
runs executables and redirects output to the designated text file, output is diff'd with the Master Output,
the result is then appended to "DiffResult.txt".

An empty "DiffResult.txt" is not an Error/Bug, it indicates a successful diff, no differences were found.

