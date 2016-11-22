//#include <stdio.h>
//#include <stdlib.h>
#include "mpi.h"
#include "adios.h"
#include "adios_types.h"

int main(int argc, char **argv)
{
	char *filename="test.bp";
	int rank,size,ii,block;
	int NX=100,G,O;
	double t[NX];
	int64_t m_adios_group;
	int64_t m_adios_file;
	uint64_t adios_groupsize,adios_totalsize;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	//printf("MPI Init\n");
	//strcpy(filename,"test.bp");
	adios_init_noxml(MPI_COMM_WORLD);
	adios_allocate_buffer(ADIOS_BUFFER_ALLOC_NOW,10);
	adios_declare_group(&m_adios_group,"restart","iter",adios_flag_yes);
	//printf("%ld\n",m_adios_group);
	adios_select_method(m_adios_group,"MPI","","");
	adios_define_var(m_adios_group,"NX","",2,0,0,0);
	adios_define_var(m_adios_group,"G","",adios_integer,0,0,0);
	adios_define_var(m_adios_group,"O","",adios_integer,0,0,0);
	adios_define_var(m_adios_group,"temp","",adios_double,"NX","G","O");

	adios_open(&m_adios_file,"restart",filename,"w",MPI_COMM_WORLD);
	adios_groupsize=4+4+4+NX*8;
	adios_group_size(m_adios_file,adios_groupsize,&adios_totalsize);
	G=NX*size;
	O=NX*rank;
	for(ii=0;ii<NX;ii++)
		t[ii]=rank*NX+ii-1;
	adios_write(m_adios_file,"NX",(void *) &NX);
	adios_write(m_adios_file,"G",(void *) &G);
	adios_write(m_adios_file,"O",(void *) &O);
	adios_write(m_adios_file,"temp",t);

	adios_close(m_adios_file);
	MPI_Barrier(MPI_COMM_WORLD);
	adios_finalize(rank);
	MPI_Finalize();
	return 0;
}
