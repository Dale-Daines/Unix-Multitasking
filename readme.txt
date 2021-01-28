Assignment 2 - System Programming 1
Dale Daines - 16998416

How to compile and run:
	Connect through putty to the university's SCEM computer
	Log onto the computer
	Input the command "cc Assignment2.c -o assesrun"
	input the command "./assesrun <file1> <file2>"
		Remember to input the two arguements for the files you want to read and modify otherwise the program will not run.
	The program is now running
	

Pseudo Code
	MAIN:
		Test that two arguements are present in main
			If not present print "Please insert two arguments: ./<RUNNAME> <file1> <file2>"
			End program
		Create the first child
			Child runs averageMark()
		Create the second child
			Child runs wc(<file1>) with first arguement as a parameter
		Create the third child
			Child runs modifyFile(<file2>) with second arguement as a parameter
		Run parent() code
		
	PARENT:
		Wait for children to end
		Report exit status of each child
	
	AVERAGEMARK:
		Print "Please insert 20 marks."
		Loop 20 times:
			Take input from keyboard
			Test if keyboard is reading
				If keyboard isn't reading:
					Print "Keyboard not reading"
					Exit the child - Failure
			Test if input is non-number
				If input is non-number
					read until next line
					reduce loop by 1
			If neither test fails
				increase total by number input ( Total + number = newTotal )
		Calculate average from the 20 inputs
			Average = total / 20
		Print "Average mark is: <AVERAGE>" to output the average calculated	
		Exit the child - Success
		
	WC:
		Open file1 for reading
		Test whether file1 is open
			If not open:
				Print "Cannot open <file1>"
				exit the child
		Loop until end of file1:
			For each word increase the total by 1
		Close file1
		Print: "There are <TOTAL> words"
		Exit the child - Success
		
	MODIFYFILE:
		Open file2 for reading
		Test whether file2 is open
			If not open:
				Print "Cannot open <file2>"
				Exit the child - Failure
		Open "fTemp.txt" for writing
		Test whether fTemp.txt is open
			If not open:
				Print "Failed to create fTemp"
				Exit the child - Failure
		Input the starting phrase "this is the updated version." into the start of fTemp.txt
		Loop until end of file2:
			Input word from file2
			If word is "run"
				insert "execute" into fTemp.txt
			If word is "examine"
				insert "study" into fTemp.txt
			Otherwise
				insert <word> into fTemp.txt
		Close file2
		Close fTemp.txt
		Delete file2
			If deletion failed:
				Print "Error deleting <file2>"
				Exit the child - Failure
		Rename fTemp.txt into file2
			If rename failed:
				Print "Error renaming fTemp.txt"
				Exit the child - Failure
		Exit the child - Success
		
Test Plan
	1. Run the program as above in the "How to compile and run" section
	2. Use the arguments "count.txt" and "modify.txt"
	3. A prompt will appear asking you to input 20 marks.
	4. The program will output the word count for file1
	5. The program will output the end status of both child 2 and child 3
	6. Input the 20 marks into the console.
	7. The program will output the averageMark for these marks
	8. The program will output the end status of child 1 and finish
	
Test Run/Output
Before:
	Modify:
		I like to run code so that I can examine its effects upon other code that is also run at the same time. Children can be created by forking programs which allows the program to run different code per children. Sometimes it is a good idea to examine the code to prevent errors.
	Count:
		This text is used to count the words it contains herein. Some of these words are short and some are quite lengthy. Supercalifragilisticexpialidocious for instance.
	
	1.	
		Please insert 20 marks.
		There are 25 words.
		done waiting for 25527
		status: exit=0, sig=0, core=0
		done waiting for 25528
		status: exit=0, sig=0, core=0
		
		<Input:	25
				23
				52
				63
				4
				7
				43
				2
				356
				34
				67
				43
				244
				64
				32
				1
				2
				46
				43
				3 >
	2.
		Average mark is: 57.
		done waiting for 25669
		status: exit=0, sig=0, core=0

		<Program Ends>

After:
	Modify:
		this is the updated version. I like to execute code so that I can study its effects upon other code that is also execute at the same time. Children can be created by forking programs which allows the program to execute different code per children. Sometimes it is a good idea to study the code to prevent errors.
	Count:
		This text is used to count the words it contains herein. Some of these words are short and some are quite lengthy. Supercalifragilisticexpialidocious for instance.