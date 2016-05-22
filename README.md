memfile is a portable C++ header for opening files from memory (as opposed to from disk) by mimicking the functionaliy of fopen and fscanf. memfile is not compatible with standard C FILE pointers, but works pretty much the same way. Here's a quick example:

    MEM_FILE fp;
    OpenFileInMemory( &fp, some_memory );
    char buffer[ 256 ];
    mscanf( &fp, "%s", buffer );

Just include memfile.h and you're good to go.

I've created an example to demonstrate usage in main.cpp. As extra goodies I've also included the incbin script I used to generate the poem symbol from main.cpp (incbin.pl stolen from Richard Mitton).

Note: Function overloadng is used to implement mscanf. For C support overloading can be implemented with some C macros.
