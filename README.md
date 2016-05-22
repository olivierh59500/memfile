memfile is a C header for opening files in memory by mimicking the functionaliy of fopen and fscanf. memfile is not compatible with standard C FILE pointers, but works pretty much the same way. Here's a quick example:

    MEM_FILE fp;
    OpenFileInMemory( &fp, some_memory );
    char buffer[ 256 ];
    fscanf( &fp, "%s", buffer );

Just include memfile.h and you're good to go. I've created an example to demonstrate usage in main.c. As extra goodies I've included the incbin script I used to generate the poem symbol from main.c (incbin.pl stolen from Richard Mitton).
