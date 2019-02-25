#include "os.h"

OsInt32 OsCriticalSectionCreate(OsCriticalSection *cs, const OsChar* name)
{
	BOOL manual_reset;
	OsCriticalSectionInternals *cs_data = (OsCriticalSectionInternals *)cs;
	if(0 != pthread_mutex_init(&cs_data->m_mutex, NULL))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	//cs_data->flags = flags;
	return OS_SUCCESS;
}
/*
OsInt32 OsCriticalSectioniDelete(OsCriticalSection *cs)
{
	BOOL result;
	OsCriticalSectionInternals *cs_data = (OsCriticalSectionInternals *)cs;
	if(cs_data == 0)
	{
		OS_ERROR;
		return OS_INVALID_CONTROL_STRUCTURE;
	}
	if(0 != pthread_mutex_destroy(&cs_data->m_mutex, NULL))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	return OS_SUCCESS;
}
*/
OsUInt32 OsCriticalSectionEnter(OsCriticalSection *cs)
{
	BOOL result;
	OsCriticalSectionInternals *cs_data = (OsCriticalSectionInternals *)cs;
	
	if(0 != pthread_mutex_lock(&cs_data->m_mutex))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	return OS_SUCCESS;
}
OsUInt32 OsCriticalSectionLeave(OsCriticalSection *cs)
{
	OsCriticalSectionInternals *cs_data = (OsCriticalSectionInternals *)cs;
	if(0 != pthread_mutex_unlock(&cs_data->m_mutex))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	return OS_SUCCESS;
}


