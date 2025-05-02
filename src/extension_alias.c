#include "duckdb_extension.h"

#ifndef DUCKDB_EXTENSION_WRAPPER_NAME
#error "DUCKDB_EXTENSION_WRAPPER_NAME is not defined"
#endif

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#include <stdio.h> 

DUCKDB_EXTENSION_ENTRYPOINT(duckdb_connection connection, duckdb_extension_info info, struct duckdb_extension_access *access) {
	printf("Query: INSTALL %s FROM community;\n", STR(DUCKDB_EXTENSION_WRAPPER_NAME));
	if (duckdb_query(connection, "INSTALL " STR(DUCKDB_EXTENSION_WRAPPER_NAME) " FROM community;", NULL) == DuckDBError){
		return false;
	}
	if (duckdb_query(connection, "LOAD " STR(DUCKDB_EXTENSION_WRAPPER_NAME), NULL) == DuckDBError){
		return false;
	}
	return true;
}