#include "duckdb_extension.h"

#ifndef DUCKDB_EXTENSION_CANONICAL
#error "DUCKDB_EXTENSION_CANONICAL is not defined"
#endif

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#include <stdio.h> 

DUCKDB_EXTENSION_ENTRYPOINT(duckdb_connection connection, duckdb_extension_info info, struct duckdb_extension_access *access) {
	if (duckdb_query(connection, "INSTALL " STR(DUCKDB_EXTENSION_CANONICAL) " FROM community;", NULL) == DuckDBError){
		return false;
	}
	if (duckdb_query(connection, "LOAD " STR(DUCKDB_EXTENSION_CANONICAL), NULL) == DuckDBError){
		return false;
	}
	return true;
}