#ifndef __OS_H_
#define __OS_H_

#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>

typedef unsigned int OsUInt32;
typedef signed int OsInt32;

typedef unsigned short int OsUInt16;
typedef signed short int OsInt16;

typedef unsigned char OsUInt8;
typedef signed char OsInt8;

typedef char OsChar;

typedef bool BOOL;

#ifndef NULL
#define NULL ((void *)0)
#endif
#define OS_EVENT_SIZE		8
#define OS_SEM_SIZE			8
#define OS_CRITICAL_SECTION_SIZE 	8

#define OS_ERROR do {printf("OS Error: %s %s %d\n", __FILE__, __func__, __LINE__);} while(0)

typedef enum {
	OS_FAILURE = -1,
	OS_SUCCESS = 0,
	OS_INVALID_CONTROL_STRUCTURE,
}OS_RETURN_CODES;
	

typedef struct OsEvent {
	OsUInt32 event_data[OS_EVENT_SIZE / sizeof(OsUInt32)];
}OsEvent;
typedef struct {
	pthread_cond_t		m_hdl;
	pthread_mutex_t		m_mutex;
	OsUInt32		flags;
	OsUInt32		padding;
}OsEventInternals;

/*
typedef struct {
	sem_t m_hdl;
}OsSemInternals;
*/
typedef struct OsSem {
        OsUInt32 sem_data[OS_SEM_SIZE / sizeof(OsUInt32)];
}OsSem;

typedef struct {
        pthread_mutex_t         m_mutex;
}OsCriticalSectionInternals;

typedef struct {
        OsUInt32 critical_section_data[OS_CRITICAL_SECTION_SIZE / sizeof(OsUInt32)];
}OsCriticalSection;

	
#endif
