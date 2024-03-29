#include <unistd.h>

static void clar_print_init(int test_count, int suite_count, const char *suite_names)
{
        int PATH_LEN = 1024;
        char dirname [PATH_LEN];
        getcwd(dirname, PATH_LEN);

	(void)test_count;
	printf("Loaded %d suites: %s\n", (int)suite_count, suite_names);
        printf("Started in %s\n", dirname);
}

static void clar_print_shutdown(int test_count, int suite_count, int error_count)
{
	(void)test_count;
	(void)suite_count;
	(void)error_count;

	printf("\n\n");
	clar_report_errors();
}

static void clar_print_error(int num, const struct clar_error *error)
{
	printf("  %d) Failure:\n", num);

	printf("%s::%s [%s:%d]\n",
		error->suite,
		error->test,
		error->file,
		error->line_number);

	printf("  %s\n", error->error_msg);

	if (error->description != NULL)
		printf("  %s\n", error->description);

	printf("\n");
	fflush(stdout);
}

static void clar_print_ontest(const char *test_name, int test_number, enum cl_test_status status)
{
	(void)test_name;
	(void)test_number;

	switch(status) {
	case CL_TEST_OK: printf("."); break;
	case CL_TEST_FAILURE: printf("F"); break;
	case CL_TEST_SKIP: printf("S"); break;
	}

	fflush(stdout);
}

static void clar_print_onsuite(const char *suite_name, int suite_index)
{
	if (_clar.report_suite_names)
		printf("\n%s", suite_name);

	(void)suite_index;
}

static void clar_print_onabort(const char *msg, ...)
{
	va_list argp;
	va_start(argp, msg);
	vfprintf(stderr, msg, argp);
	va_end(argp);
}
