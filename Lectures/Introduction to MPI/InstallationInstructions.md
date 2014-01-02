This document outlines the process of installing the MPICH2 MPI library on Windows.

1. Download the Windows binary [here](http://www.mpich.org/static/tarballs/1.4.1p1/mpich2-1.4.1p1-win-ia32.msi).
2. Run in the installation program, choosing all of the default values.
3. If prompted, allow access for the program via the Windows firewall.
4. In the installation bin directory (C:\Program Files\MPICH2\bin by default), run the wmpiregister utility.
5. Enter your user name and password, then select "Register".
6. Set the environment variable MPI_DIR to the location of the MPICH2 directory in your installation (C:\Program Files\MPICH2 by default).
