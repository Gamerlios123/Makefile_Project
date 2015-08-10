make -f Makefiles\clean.gnu clean
make -f Makefiles\make_driverfinal.gnu clean
make -f Makefiles\make_driversample_Test0.gnu clean
make -f Makefiles\make_driversample_Test1.gnu clean
make -f Makefiles\make_driversample_Test2.gnu clean
make -f Makefiles\make_driverbig_10x10_min_output.gnu clean
make -f Makefiles\make_driverbig_10x10_med_output.gnu clean
make -f Makefiles\make_driverbig_10x10_max_output.gnu clean
make -f Makefiles\make_driverbig_30x30_min_output.gnu clean
make -f Makefiles\make_driverbig_30x30_med_output.gnu clean
make -f Makefiles\make_driverbig_30x30_max_output.gnu clean
make -f Makefiles\make_driverbig_8x12_min_output.gnu clean
make -f Makefiles\make_driverbig_8x12_med_output.gnu clean
make -f Makefiles\make_driverbig_8x12_max_output.gnu clean

make -f Makefiles\make_driverfinal.gnu
make -f Makefiles\make_driversample_Test0.gnu
make -f Makefiles\make_driversample_Test1.gnu
make -f Makefiles\make_driversample_Test2.gnu
make -f Makefiles\make_driverbig_10x10_min_output.gnu
make -f Makefiles\make_driverbig_10x10_med_output.gnu
make -f Makefiles\make_driverbig_10x10_max_output.gnu
make -f Makefiles\make_driverbig_30x30_min_output.gnu
make -f Makefiles\make_driverbig_30x30_med_output.gnu
make -f Makefiles\make_driverbig_30x30_max_output.gnu
make -f Makefiles\make_driverbig_8x12_min_output.gnu
make -f Makefiles\make_driverbig_8x12_med_output.gnu
make -f Makefiles\make_driverbig_8x12_max_output.gnu

.\Executables\driverbig_30x30_min_output.exe > Output\driverbig_30x30_min_output_MyOutput.txt
.\Executables\driverbig_30x30_med_output.exe > Output\driverbig_30x30_med_output_MyOutput.txt
.\Executables\driverbig_30x30_max_output.exe > Output\driverbig_30x30_max_output_MyOutput.txt
.\Executables\driverbig_10x10_min_output.exe > Output\driverbig_10x10_min_output_MyOutput.txt
.\Executables\driverbig_10x10_med_output.exe > Output\driverbig_10x10_med_output_MyOutput.txt
.\Executables\driverbig_10x10_max_output.exe > Output\driverbig_10x10_max_output_MyOutput.txt
.\Executables\driverbig_8x12_min_output.exe > Output\driverbig_8x12_min_output_MyOutput.txt
.\Executables\driverbig_8x12_med_output.exe > Output\driverbig_8x12_med_output_MyOutput.txt
.\Executables\driverbig_8x12_max_output.exe > Output\driverbig_8x12_max_output_MyOutput.txt
.\Executables\driversample_Test0.exe > Output\driversample_Test0_MyOutput.txt
.\Executables\driversample_Test1.exe > Output\driversample_Test1_MyOutput.txt
.\Executables\driversample_Test2.exe > Output\driversample_Test2_MyOutput.txt
.\Executables\driverfinal.exe > Output\driverfinal_MyOutput.txt

diff Output/driverbig_30x30_min_output_MyOutput.txt Master_Output/driverbig_30x30_min_output_Master.txt > DiffResult.txt 
diff Output/driverbig_30x30_med_output_MyOutput.txt Master_Output/driverbig_30x30_med_output_Master.txt >> DiffResult.txt
diff Output/driverbig_30x30_max_output_MyOutput.txt Master_Output/driverbig_30x30_max_output_Master.txt >> DiffResult.txt
diff Output/driverbig_10x10_min_output_MyOutput.txt Master_Output/driverbig_10x10_min_output_Master.txt >> DiffResult.txt
diff Output/driverbig_10x10_med_output_MyOutput.txt Master_Output/driverbig_10x10_med_output_Master.txt >> DiffResult.txt
diff Output/driverbig_10x10_max_output_MyOutput.txt Master_Output/driverbig_10x10_max_output_Master.txt >> DiffResult.txt
diff Output/driverbig_8x12_min_output_MyOutput.txt Master_Output/driverbig_8x12_min_output_Master.txt   >> DiffResult.txt
diff Output/driverbig_8x12_med_output_MyOutput.txt Master_Output/driverbig_8x12_med_output_Master.txt   >> DiffResult.txt
diff Output/driverbig_8x12_max_output_MyOutput.txt Master_Output/driverbig_8x12_max_output_Master.txt   >> DiffResult.txt
diff Output/driversample_Test0_MyOutput.txt Master_Output/driversample_Test0_Master.txt                 >> DiffResult.txt
diff Output/driversample_Test1_MyOutput.txt Master_Output/driversample_Test1_Master.txt                 >> DiffResult.txt
diff Output/driversample_Test2_MyOutput.txt Master_Output/driversample_Test2_Master.txt                 >> DiffResult.txt

"C:\Program Files (x86)\Notepad++\Notepad++.exe" DiffResult.txt"