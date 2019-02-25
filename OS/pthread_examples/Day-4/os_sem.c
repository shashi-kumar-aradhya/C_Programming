#include "os.h"

OsInt32 OsSemCreate(OsSem *sem, const OsChar* name, OsUInt32 init_value, OsUInt32 flags)
{
	BOOL manual_reset;
	OsSemInternals *sem_data = (OsSemInternals *)sem;
	if(0 != sem_init(&sem_data->m_hdl, 0, init_value))
	{
		UTA_ERROR;
		return UTA_FAILURE;
	}
	return UTA_SUCCESS;
}

OsInt32 OsSemiDelete(OsSem *sem)
{
	BOOL result;
	OsSemInternals *sem_data = (OsSemInternals *)sem;
	if(sem_data == 0)
	{
		UTA_ERROR;
		return UTA_OS_INVALID_STRUCTURE;
	}
	if(0 != sem_destroy(&sem_data->m_hdl))
	{
		UTA_ERROR;
		return UTA_FAILURE;
	}
	return UTA_SUCCESS;
}

OsUInt32 OsSemSet(OsSem *sem)
{
	BOOL result;
	OsSemInternals *sem_data = (OsSemInternals *)sem;
	
	if(0 != pthread_mutex_lock(&sem_data->m_mutex))
	{
		UTA_ERROR;
		return UTA_FAILURE;
	}
	if (0 != pthread_cond_signal(&sem_data->m_hdl))
	{
		UTA_ERROR;
		if(0 != pthread_mutex_unlock(&sem_data->m_mutex))
			UTA_ERROR;
		return UTA_FAILURE;
	}
	if(0 != pthread_mutex_unlock(&sem_data->m_mutex))
	{
		UTA_ERROR;
		return UTA_FAILURE;
	}
	return UTA_SUCCESS;
}

OsUInt32 OsSemObtain(OsSem * sem, OsUInt32 min_timeout, OsUInt32 max_timeout)
{
	BOOL result;
	OsSemInternals *sem_data = (OsSemInternals *)sem;

	if(sem_data == 0)
	{
		UTA_ERROR;
		return UTA_OS_INVALID_STRUCTURE;
	}

	if (0 != sem_wait(&sem_data->m_hdl))
	{
		UTA_ERROR;
		return UTA_FAILURE;
	}

	return UTA_SUCCESS;
}

OsUInt32 OsSemRelease(OsSem * sem)
{
        BOOL result;
        OsSemInternals *sem_data = (OsSemInternals *)sem;

        if(sem_data == 0)
        {   
                UTA_ERROR;
                return UTA_OS_INVALID_STRUCTURE;
        }   

        if (0 != sem_post(&sem_data->m_hdl))
        {   
                UTA_ERROR;
                return UTA_FAILURE;
        }   

        return UTA_SUCCESS;
}

