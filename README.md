dontneed
========

A utility to apply POSIX_FADV_DONTNEED to a specified file.

This was primarily written to workaround a problem with MySQL on Linux Kernels before 2.6.28 where the filesyste cache would fail to honour vm.swappiness=0.  This could cause extreme swap usage with large InnoDB log files.
