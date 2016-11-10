/*
*********************************************************************************************************
*                                            EXAMPLE CODE
*
*                          (c) Copyright 2009-2011; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*
*               Please feel free to use any application code labeled as 'EXAMPLE CODE' in
*               your application products.  Example code may be used as is, in whole or in
*               part, or may be used as a reference only.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                          APPLICATION CODE
*
*                                          Microsoft Windows
*
* Filename      : app.c
* Version       : V1.00
* Programmer(s) : JJL
*                 FGK
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include <includes.h>


/*
*********************************************************************************************************
*                                             LOCAL DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            LOCAL VARIABLES
*********************************************************************************************************
*/

static  CPU_STK  AppTaskStartStk[APP_TASK_START_STK_SIZE];
OS_STK TaskStk11[APP_TASK_START_STK_SIZE];
OS_STK TaskStk12[APP_TASK_START_STK_SIZE];
OS_STK TaskStk21[APP_TASK_START_STK_SIZE];
OS_STK TaskStk22[APP_TASK_START_STK_SIZE];
OS_STK TaskStk23[APP_TASK_START_STK_SIZE];

INT32U task11Time[3];
INT32U task12Time[3];
INT32U task21Time[3];
INT32U task22Time[3];
INT32U task23Time[3];
INT32U StartTime = 10;

/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/



static  void  AppTaskStart(void  *p_arg);
void Task11(void *p_arg);
void Task12(void *p_arg);
void Task21(void *p_arg);
void Task22(void *p_arg);
void Task23(void *p_arg);
void createTaskSet1();
void createTaskSet2();

/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Argument(s) : none.
*
* Return(s)   : none.
*********************************************************************************************************
*/

int  main (void)
{
    OSInit();                                                   /* Init uC/OS-II.                                       */

	BSP_Init();                                                 /* Initialize BSP functions                             */
	CPU_Init();

	//OSTaskCreateExt((void(*)(void *))AppTaskStart,              /* Create the start task                                */
	//	(void          *)0,
	//	(OS_STK        *)&AppTaskStartStk[APP_TASK_START_STK_SIZE - 1],
	//	(INT8U)1u,
	//	(INT16U)0u,
	//	(OS_STK        *)&AppTaskStartStk[0],
	//	(INT32U)APP_TASK_START_STK_SIZE,
	//	(void          *)0,
	//	(INT16U)(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));
	
	//createTaskSet1();
	createTaskSet2();

    OSStart();                                                  /* Start multitasking (i.e. give control to uC/OS-II).  */
}


/*
*********************************************************************************************************
*                                          STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg       is the argument passed to 'AppTaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Note(s)     : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static void createTaskSet1(){


	INT32U C11 = 1, C12 = 3;
	INT32U T11 = 3, T12 = 6;

	task11Time[0] = C11;
	task11Time[1] = StartTime;
	task11Time[2] = StartTime + T11;

	task12Time[0] = C12;
	task12Time[1] = StartTime;
	task12Time[2] = StartTime + T12;

	OSTaskCreateExt((void(*)(void *))Task11,              /* Create the start task                                */
		(void          *)0,
		(OS_STK        *)&TaskStk11[APP_TASK_START_STK_SIZE - 1],
		(INT8U)1u,
		(INT16U)1u,
		(OS_STK        *)&TaskStk11[0],
		(INT32U)APP_TASK_START_STK_SIZE,
		(void          *)task11Time,
		(INT16U)(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));
	OSTaskCreateExt((void(*)(void *))Task12,              /* Create the start task                                */
		(void          *)0,
		(OS_STK        *)&TaskStk12[APP_TASK_START_STK_SIZE - 1],
		(INT8U)2u,
		(INT16U)2u,
		(OS_STK        *)&TaskStk12[0],
		(INT32U)APP_TASK_START_STK_SIZE,
		(void          *)task12Time,
		(INT16U)(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));
}

static void createTaskSet2() {


	INT32U C21 = 1, C22 = 3, C23 = 4;
	INT32U T21 = 3, T22 = 6, T23 = 9;

	task21Time[0] = C21;
	task21Time[1] = StartTime;
	task21Time[2] = StartTime + T21;

	task22Time[0] = C22;
	task22Time[1] = StartTime;
	task22Time[2] = StartTime + T22;

	task23Time[0] = C23;
	task23Time[1] = StartTime;
	task23Time[2] = StartTime + T23;

	OSTaskCreateExt((void(*)(void *))Task21,              /* Create the start task                                */
		(void          *)0,
		(OS_STK        *)&TaskStk21[APP_TASK_START_STK_SIZE - 1],
		(INT8U)1u,
		(INT16U)1u,
		(OS_STK        *)&TaskStk21[0],
		(INT32U)APP_TASK_START_STK_SIZE,
		(void          *)task21Time,
		(INT16U)(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));
	OSTaskCreateExt((void(*)(void *))Task22,              /* Create the start task                                */
		(void          *)0,
		(OS_STK        *)&TaskStk22[APP_TASK_START_STK_SIZE - 1],
		(INT8U)2u,
		(INT16U)2u,
		(OS_STK        *)&TaskStk22[0],
		(INT32U)APP_TASK_START_STK_SIZE,
		(void          *)task22Time,
		(INT16U)(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));
	OSTaskCreateExt((void(*)(void *))Task23,              /* Create the start task                                */
		(void          *)0,
		(OS_STK        *)&TaskStk23[APP_TASK_START_STK_SIZE - 1],
		(INT8U)3u,
		(INT16U)3u,
		(OS_STK        *)&TaskStk23[0],
		(INT32U)APP_TASK_START_STK_SIZE,
		(void          *)task23Time,
		(INT16U)(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));
}

static  void  AppTaskStart (void *p_arg)
{
    OS_ERR  err;


   (void)p_arg;

   
#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&err);                               /* Compute CPU capacity with no task running            */
#endif

    APP_TRACE_DBG(("uCOS-II is Running...\n\r"));

    while (DEF_ON) {                                            /* Task body, always written as an infinite loop.       */
       /* OSTimeDlyHMSM(0, 0, 1, 0);

        APP_TRACE_DBG(("Time: %d\n\r", OSTimeGet(&err)));
		printf("test\n");*/
		if (OSTimeGet() >= 150){
			OSTaskChangePrio(1,60);
			//OSTimeDly(10);
		}
    }
}
void Task11(void *p_arg){

	int toDelay;
	int T = task11Time[2] - task11Time[1];
	if (OSTimeGet()<StartTime){
		OSTimeDly(StartTime - OSTimeGet());
	}

	while (1){
		while (OSTCBCur->CompTime>0){

		}
		toDelay = task11Time[2] - OSTimeGet();
		task11Time[1] = task11Time[2];
		task11Time[2] = task11Time[1] + T;
		OSTCBCur->CompTime = task11Time[0];
		OSTCBCur->StartTime = task11Time[1];
		OSTCBCur->Deadline = task11Time[2];
		//printf("task1     cuurent:%d  deadline:%d\n", OSTimeGet(), OSTCBCur->Deadline);
		OSTimeDly(toDelay);
	}

}
void Task12(void *p_arg) {

	int toDelay;
	int T = task12Time[2] - task12Time[1];

	if (OSTimeGet()<StartTime){
		OSTimeDly(StartTime - OSTimeGet());
	}
	while (1) {
		while (OSTCBCur->CompTime>0) {

		}
		toDelay = task12Time[2] - OSTimeGet();
		task12Time[1] = task12Time[2];
		task12Time[2] = task12Time[1] + T;
		OSTCBCur->CompTime = task12Time[0];
		OSTCBCur->StartTime = task12Time[1];
		OSTCBCur->Deadline = task12Time[2];
		//printf("task2     current:%d  deadline:%d\n", OSTimeGet(), OSTCBCur->Deadline);
		OSTimeDly(toDelay);
	}

}
void Task21(void *p_arg) {

	int toDelay;
	int c = task21Time[0];
	int T = task21Time[2] - task21Time[1];

	if (OSTimeGet()<StartTime) {
		OSTimeDly(StartTime - OSTimeGet());
	}
	while (1) {
		while (OSTCBCur->CompTime>0) {

		}
		toDelay = OSTCBCur->Deadline - OSTimeGet();
		if (toDelay < 0) {
			printf("task1 ÑÓÊ±£¡\n");
			OSTCBCur->CompTime = c;
			OSTCBCur->StartTime = OSTimeGet();
			OSTCBCur->Deadline = OSTCBCur->StartTime + T;
		}
		else {
			OSTCBCur->CompTime = task21Time[0];
			OSTCBCur->StartTime = OSTCBCur->Deadline;
			OSTCBCur->Deadline = OSTCBCur->StartTime + T;
			OSTimeDly(toDelay);
		}	
		
	}

}
void Task22(void *p_arg) {

	int toDelay;
	int c = task22Time[0];
	int T = task22Time[2] - task22Time[1];

	if (OSTimeGet()<StartTime) {
		OSTimeDly(StartTime - OSTimeGet());
	}
	while (1) {
		while (OSTCBCur->CompTime>0) {

		}
		toDelay = OSTCBCur->Deadline - OSTimeGet();
		if (toDelay < 0) {
			printf("task1 ÑÓÊ±£¡\n");
			OSTCBCur->CompTime = c;
			OSTCBCur->StartTime = OSTimeGet();
			OSTCBCur->Deadline = OSTCBCur->StartTime + T;
		}
		else {
			OSTCBCur->CompTime = task22Time[0];
			OSTCBCur->StartTime = OSTCBCur->Deadline;
			OSTCBCur->Deadline = OSTCBCur->StartTime + T;
			OSTimeDly(toDelay);
		}
	}

}
void Task23(void *p_arg) {

	int toDelay;
	int c = task23Time[0];
	int T = task23Time[2] - task23Time[1];

	if (OSTimeGet()<StartTime) {
		OSTimeDly(StartTime - OSTimeGet());
	}
	while (1) {
		while (OSTCBCur->CompTime>0) {

		}
		toDelay = OSTCBCur->Deadline - OSTimeGet();
		if (toDelay < 0) {
			printf("task1 ÑÓÊ±£¡\n");
			OSTCBCur->CompTime = c;
			OSTCBCur->StartTime = OSTimeGet();
			OSTCBCur->Deadline = OSTCBCur->StartTime + T;
		}
		else {
			OSTCBCur->CompTime = task23Time[0];
			OSTCBCur->StartTime = OSTCBCur->Deadline;
			OSTCBCur->Deadline = OSTCBCur->StartTime + T;
			OSTimeDly(toDelay);
		}
	}

}
