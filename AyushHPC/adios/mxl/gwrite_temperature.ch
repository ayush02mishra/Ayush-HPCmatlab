adios_groupsize = sizeof(long) \
                + sizeof(double) * (NX);
adios_group_size (adios_handle, adios_groupsize, &adios_totalsize);
adios_write (adios_handle, "NX", &NX);
adios_write (adios_handle, "/temperature", t);
