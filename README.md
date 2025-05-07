# DuckDB Extension Alias
This DuckDB extension creates an alias for an existing community extension.
It does so by setting `EXTENSION_NAME` to the alias and `EXTENSION_CANONICAL` to the name of the original community extension.

It uses only the DuckDB C API, and when the aliased extension is loaded, it installs and loads the canonical community extension under the hood.