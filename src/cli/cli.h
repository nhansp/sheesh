/* This file is automatically generated from the documentation. EDIT AT YOUR OWN RISK. */

#ifndef CLI_H
#define CLI_H

#include <stddef.h>
#include "tracee/tracee.h"
#include "attribute.h"

typedef struct {
	const char *name;
	char separator;
	const char *value;
} Argument;

struct Cli;
typedef int (*option_handler_t)(Tracee *tracee, const struct Cli *cli, const char *value);

typedef struct {
	const char *class;
	option_handler_t handler;
	const char *description;
	const char *detail;
	Argument arguments[5];
} Option;

#define END_OF_OPTIONS { .class = NULL,								\
			 .arguments = {{ .name = NULL, .separator = '\0', .value = NULL }},	\
			 .handler = NULL,							\
			 .description = NULL,							\
			 .detail = NULL								\
			}

typedef int (*initialization_hook_t)(Tracee *tracee, const struct Cli *cli,
				size_t argc, char *const argv[], size_t cursor);
typedef struct Cli {
	const char *name;
	const char *version;
	const char *subtitle;
	const char *synopsis;
	const char *colophon;
	const char *logo;

	initialization_hook_t pre_initialize_bindings;
	initialization_hook_t post_initialize_bindings;
	initialization_hook_t pre_initialize_cwd;
	initialization_hook_t post_initialize_cwd;
	initialization_hook_t pre_initialize_exe;
	initialization_hook_t post_initialize_exe;
	void *private;

	const Option options[];
} Cli;

extern const Cli *get_sheesh_cli(TALLOC_CTX *context);
extern const Cli * WEAK get_care_cli(TALLOC_CTX *context);

extern void print_usage(Tracee *tracee, const Cli *cli, bool detailed);
extern void print_version(const Cli *cli);
extern int parse_integer_option(const Tracee *tracee, int *variable, const char *value, const char *option);
extern const char *expand_front_variable(TALLOC_CTX *context, const char *string);

extern bool exit_failure;

#endif /* CLI_H */
