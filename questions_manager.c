
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

/*  General Includes  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*  Current Version */
const char VERSION[4] = {'1', '.', '1', '\0'};

/*  Defines  */
#define false  0
#define true   1

#define DETAIL     10
#define NOT_DETAIL 11
#define INIT       12

#define LINE_SIZE 1024

/*
 * Print Forensics GC logo with header of not.
 */
int print_logo(unsigned int mode, int questions_number)
{
	char op;

	if(mode == DETAIL || mode == INIT)
	{
		system("clear");
		printf("\n");
	}

	printf("______________________________________________________________\n");
	printf("   _____                        _              ____    ____      \n");
	printf("  |  ___|__  _ __ ___ _ __  ___(_) ___ ___    / ___|  / ___|     \n");
	printf("  | |_ / _ \\| '__/ _ \\ '_ \\/ __| |/ __/ __|  | |  _  | |      \n");
	printf("  |  _| (_) | | |  __/ | | \\__ \\ | (__\\__ \\  | |_| | | |___  \n");
	printf("  |_|  \\___/|_|  \\___|_| |_|___/_|\\___|___/   \\____|  \\____|\n");
	printf("______________________________________________________________\n");
	printf("                                                              \n");
	printf("                  4Linux Forensics Questions                  \n");
	printf("         (c) 2018 GUSTAVO CELANI ALL RIGHTS RESERVED          \n");
	printf("______________________________________________________________\n\n");

	if(mode == DETAIL || mode == INIT)
	{
		printf(" Version:         %s\n", VERSION);
		printf(" Creation Date:   08/05/2018\n");
		printf(" Creation Time:   18:54:28\n");
		printf(" Developer:       Gustavo Celani\n");
		printf(" Type:            C Program\n");
		printf(" Compiler:        gcc\n");
		printf(" Format:          .c\n");
		printf(" Category:        Forensics Certification Questions\n");
		printf(" Procedure:       Study\n");
		printf(" Questions:       questions_db.txt\n");
		printf("______________________________________________________________\n\n");

		if(mode == INIT)
		{
			printf(" [ %d ] Questions was Interpreted\n\n", questions_number);
			do
			{
				printf(" Start Questions now [y/n]? ");
				scanf(" %c", &op);
			} while(op != 'y' && op != 'Y' && op != 'n' && op != 'N');

			if(op == 'y' || op == 'Y')
				return true;
			else
				return false;
		}
	}

	return true;
}

/*
 * Formats a line Read removing '\n'
 * Unfomatted Line: some question\n
 * Formatted  Line: some question
 */
void format_line(char *line_buffer)
{
	unsigned int i = 0;

	for(i=0; i<strlen(line_buffer); i++)
		if(line_buffer[i] == '\n')
		{
			line_buffer[i] = '\0';
			return;
		}
}

/*
 * If diff_t is greater than 60sec, it will format it
 */
void format_time(int diff_t, char *aux_t)
{
	int min, sec;

	if(diff_t < 60)
		snprintf(aux_t, sizeof(aux_t), "%dsec", diff_t);
	else
	{
		min = (int) (diff_t / 60);
		sec = (int) (diff_t - (min * 60));
		snprintf(aux_t, 16, "%dmin %dsec", min, sec);
	}
	return;
}

/*
 * Main
 */
void main(void)
{
	unsigned int score = 0;
	unsigned int questions = 0;
	unsigned int line = 0;
	unsigned int questions_number = 0;
	unsigned int ret = 0;
	FILE *questions_file;
	char line_buffer[LINE_SIZE];
	char op;
	float percent;
	time_t start_t, end_t;
	double diff_t;
	char aux_t[16];

	questions_file = fopen("questions_db.txt", "r");
	if(!questions_file)
	{
		printf("\n Fail to Open [ questions_db.txt ]\n");
		print_logo(NOT_DETAIL, 0);
		return;
	}

	while(true)
	{
		fgets(line_buffer, sizeof(line_buffer), (FILE *)questions_file);
		format_line(line_buffer);
		questions_number++;

		if(strcmp(line_buffer, "QUESTIONS_END") == 0)
			break;

		bzero(line_buffer, LINE_SIZE);
	}

	bzero(line_buffer, LINE_SIZE);
	questions_number = (questions_number-1) / 7;

	ret = print_logo(INIT, questions_number);
	if(!ret)
	{
		print_logo(NOT_DETAIL, 0);
		return;
	}

	fclose(questions_file);
	questions_file = fopen("questions_db.txt", "r");

	time(&start_t);

	for(questions = 0; questions < questions_number; questions++)
	{
		system("clear");
		print_logo(NOT_DETAIL, 0);

		for(line = 0; line < 5; line++)
		{
			fgets(line_buffer, sizeof(line_buffer), (FILE *)questions_file);
			format_line(line_buffer);

			if(line == 0)
				printf(" %d) %s\n", (questions+1), line_buffer);
			else
				printf(" %s\n", line_buffer);

			bzero(line_buffer, LINE_SIZE);
		}

		do
		{
			printf(" Option: ");
			scanf(" %c", &op);
		} while(op != 'a' && op != 'b' && op != 'c' && op != 'd');

		fgets(line_buffer, sizeof(line_buffer), (FILE *)questions_file);
		format_line(line_buffer);

		if(op == line_buffer[0])
		{
			score++;
			printf("\n Correct Answer!\n");
		}
		else
		{
			printf("\n Wrong Answer...\n");
			printf(" The correct answer was [ %c ]\n", line_buffer[0]);
		}
		getchar();
		getchar();

		fgets(line_buffer, sizeof(line_buffer), (FILE *)questions_file);
		bzero(line_buffer, LINE_SIZE);
	}

	time(&end_t);
	diff_t = difftime(end_t, start_t);
	format_time(diff_t, aux_t);

	percent = (score*100) / questions_number;

	print_logo(DETAIL, questions_number);
	printf("       Score: %d/%d (%.2f%%)     Total Time: %s\n",
			score,
			questions_number,
			percent,
			aux_t);
	print_logo(NOT_DETAIL, questions_number);


	return;
}
