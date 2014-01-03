This document outlines the process of installing the MPICH2 MPI library on Windows.

1. Download the Windows binary [here](http://www.mcs.anl.gov/research/projects/mpich2staging/goodell/downloads/tarballs/1.4.1p1/mpich2-1.4.1p1-win-ia32.msi).
2. Open an administrator command prompt from Start > Run > cmd, right click and choose Run as administrator.
3. Execute msiexec /i mpich2-1.4.1p1-win-ia32.msi.
4. Choose the default installation opens, except choose to to install for everyone.
5. Add the MPICH2 bin directory (C:\Program Files\MPICH2\bin by default) to the PATH environment variable.
5. In the installation bin directory (C:\Program Files\MPICH2\bin by default), run the wmpiregister utility.
6. Enter your user name and password, then select "Register".
7. Set the environment variable MPI_DIR to the location of the MPICH2 directory in your installation (C:\Program Files\MPICH2 by default).
