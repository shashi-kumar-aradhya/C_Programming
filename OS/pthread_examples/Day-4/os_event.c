#include "os.h"

OsInt32 OsEventCreate(OsEvent *event, const OsChar* name, OsUInt32 flags)
{
	BOOL manual_reset;
	OsEventInternals *event_data = (OsEventInternals *)event;
	if(0 != pthread_cond_init(&event_data->m_hdl, NULL))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	if(0 != pthread_mutex_init(&event_data->m_mutex, NULL))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	//event_data->flags = flags;
	return OS_SUCCESS;
}
OsInt32 OsEventiDelete(OsEvent *event)
{
	BOOL result;
	OsEventInternals *event_data = (OsEventInternals *)event;
	if(event_data == 0)
	{
		OS_ERROR;
		return OS_INVALID_CONTROL_STRUCTURE;
	}
	if(0 != pthread_mutex_destroy(&event_data->m_mutex))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	if(0 != pthread_cond_destroy(&event_data->m_hdl))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	//event_data->flags = flags;
	return OS_SUCCESS;
}
OsUInt32 OsEventSet(OsEvent *event)
{
	BOOL result;
	OsEventInternals *event_data = (OsEventInternals *)event;
	
	if(0 != pthread_mutex_lock(&event_data->m_mutex))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	if (0 != pthread_cond_signal(&event_data->m_hdl))
	{
		OS_ERROR;
		if(0 != pthread_mutex_unlock(&event_data->m_mutex))
			OS_ERROR;
		return OS_FAILURE;
	}
	if(0 != pthread_mutex_unlock(&event_data->m_mutex))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	return OS_SUCCESS;
}

//OsUInt32 OsEventWait(OsEvent * event, OsUInt32 min_timeout, OsUInt32 max_timeout)
OsUInt32 OsEventWait(OsEvent * event)
{
	BOOL result;
	OsEventInternals *event_data = (OsEventInternals *)event;

	if(event_data == 0)
	{
		OS_ERROR;
		return OS_INVALID_CONTROL_STRUCTURE;
	}

	if(0 != pthread_mutex_lock(&event_data->m_mutex))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	if (0 != pthread_cond_wait(&event_data->m_hdl, &event_data->m_mutex))
	{
		OS_ERROR;
		if(0 != pthread_mutex_unlock(&event_data->m_mutex))
			OS_ERROR;
		return OS_FAILURE;
	}
	if(0 != pthread_mutex_unlock(&event_data->m_mutex))
	{
		OS_ERROR;
		return OS_FAILURE;
	}

	return OS_SUCCESS;
}
