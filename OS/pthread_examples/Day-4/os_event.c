#include "os.h"

UtaInt32 OsEventCreate(OsEvent *event, const UtaChar* name, UtaUInt32 flags)
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
	event_data->flags = flags;
	return OS_SUCCESS;
}

UtaInt32 OsEventiDelete(OsEvent *event)
{
	BOOL result;
	OsEventInternals *event_data = (OsEventInternals *)event;
	if(event_data == 0)
	{
		OS_ERROR;
		return OS_OS_INVALID_STRUCTURE;
	}
	if(0 != pthread_mutex_destroy(&event_data->m_mutex, NULL))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	if(0 != pthread_cond_destroy(&event_data->m_hdl, NULL))
	{
		OS_ERROR;
		return OS_FAILURE;
	}
	event_data->flags = flags;
	return OS_SUCCESS;
}

UtaUInt32 OsEventSet(OsEvent *event)
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

UtaUInt32 OsEventWait(OsEvent * event, UtaUInt32 min_timeout, UtaUInt32 max_timeout)
{
	BOOL result;
	OsEventInternals *event_data = (OsEventInternals *)event;

	if(event_data == 0)
	{
		OS_ERROR;
		return OS_OS_INVALID_STRUCTURE;
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
