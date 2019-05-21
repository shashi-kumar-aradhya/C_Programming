semaphore mutex = 1;                 // Controls access to the reader count
semaphore db = 1;                    // Controls access to the database
int reader_count;                    // The number of reading processes accessing the data

Reader()
{
  while (TRUE) {                     // loop forever
     down(&mutex);                          // gain access to reader_count
     reader_count = reader_count + 1;       // increment the reader_count
     if (reader_count == 1)
         down(&db);                         // if this is the first process to read the database,
                                            // a down on db is executed to prevent access to the 
                                            // database by a writing process
     up(&mutex);                            // allow other processes to access reader_count
     read_db();                             // read the database
     down(&mutex);                          // gain access to reader_count
     reader_count = reader_count - 1;       // decrement reader_count
     if (reader_count == 0)
         up(&db);                           // if there are no more processes reading from the 
                                            // database, allow writing process to access the data
     up(&mutex);                            // allow other processes to access reader_countuse_data();
                                            // use the data read from the database (non-critical)
}

Writer()
{
  while (TRUE) {                     // loop forever
     create_data();                         // create data to enter into database (non-critical)
     down(&db);                             // gain access to the database
     write_db();                            // write information to the database
     up(&db);                               // release exclusive access to the database
}
