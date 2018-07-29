# Forensics COmputing Cerfitication Questions Manager

Practice your knowledge about forensics computing. Here are some questions in portuguese about forensics computing that were made by 4Linux Forensics Computing Course.

```
/****************************************************************
 *  _____                        _              ____    ____
 * |  ___|__  _ __ ___ _ __  ___(_) ___ ___    / ___|  / ___|
 * | |_ / _ \| '__/ _ \ '_ \/ __| |/ __/ __|  | |  _  | |
 * |  _| (_) | | |  __/ | | \__ \ | (__\__ \  | |_| | | |___
 * |_|  \___/|_|  \___|_| |_|___/_|\___|___/   \____|  \____|
 *
 * File: questions_manager.c
 * Description: 4Linux - Forensic Questions
 *
 * Creation Date: 08/05/2018
 * Creation Time: 18:54:28
 *
 * Version: 1.1
 * Compiler: gcc
 *
 * Author: Gustavo Celani
 * Organization: Forensics GC
 *
 ***************************************************************/
```

## Running Forensics Computing Certification Questions Manager

To run the Question Manager, follow this steps bellow:

* Clone this repository:

	```
	$ git clone https://github.com/gustavocelani/forensics_computing_questions_manager.git
	```

* Compile questions_manager.c

	```
	$ gcc questions_manager.c -o questions_manager.o
	```

* Run questions_manager.o

	```
	$ ./questions_manager.o
	```

## Incrementing Questions Database

You can also increment questions_db.txt to your own questions your from another place.

To do that without any compatibility problem, you have to respect this rules bellow:

* Questions must to have 4 alternatives;
* Alternatives always must be [ a | b | c | d ];
* You must to respect the question formatation.

## Question Formatation

```
Line 1:  Whats your name ?    //Question Text
Line 2:  a. Ash               //First  Alternative
Line 3:  b. Brock             //Second Alternative
Line 4:  c. Mist              //Thirdy Alternative
Line 5:  d. Oak               //Fourth Alternative
Line 6:  a                    //Question's Answer
Line 7:                       //Empty Line
```

