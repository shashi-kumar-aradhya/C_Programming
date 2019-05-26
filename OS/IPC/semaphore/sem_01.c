







int open_semaphore_set( key_t keyval, int numsems )
{
        int     sid;

        if ( ! numsems )
                return(-1);
        
        if((sid = semget( mykey, numsems, IPC_CREAT | 0660 )) == -1)
        {
                return(-1);
        }
        
        return(sid);
}
