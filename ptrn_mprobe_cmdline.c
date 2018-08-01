/*
  File autogenerated by gengetopt version 2.22.1
  generated with the following command:
  gengetopt -S -i ptrn_mprobe_cmdline.ggo -F ptrn_mprobe_cmdline -f ptrn_mprobe_parser -a ptrn_mprobe_cmd_struct 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getopt.h"

#include "ptrn_mprobe_cmdline.h"

const char *ptrn_mprobe_cmd_struct_purpose = "";

const char *ptrn_mprobe_cmd_struct_usage = "Usage: netgauge-mprobe [OPTIONS]...";

const char *ptrn_mprobe_cmd_struct_description = "";

const char *ptrn_mprobe_cmd_struct_help[] = {
  "      --help             Print help and exit",
  "  -V, --version          Print version and exit",
  "  -x, --pattern=pattern  pattern",
  "  -t, --threads=INT      Number of Threads  (default=`1')",
  "  -n, --messages=INT     Number of Messages  (default=`10000')",
  "  -r, --reps=INT         Number or Repetitions  (default=`20')",
  "  -h, --hostname         Print hostname  (default=off)",
  "  -b, --nonblocking      Use nonblocking receive from all peers in parallel  \n                           (default=off)",
  "  -o, --option=INT       Option: 1=ANY,ANY, 2=src,ANY, 3=ANY,tag, 4=src,tag  \n                           (default=`1')",
  "  -p, --procs            use processes instead of threads!  (default=off)",
  "  -l, --latency          measure latency instead of message rate  (default=off)",
    0
};

typedef enum {ARG_NO
  , ARG_FLAG
  , ARG_STRING
  , ARG_INT
} ptrn_mprobe_parser_arg_type;

static
void clear_given (struct ptrn_mprobe_cmd_struct *args_info);
static
void clear_args (struct ptrn_mprobe_cmd_struct *args_info);

static int
ptrn_mprobe_parser_internal (int argc, char * const *argv, struct ptrn_mprobe_cmd_struct *args_info,
                        struct ptrn_mprobe_parser_params *params, const char *additional_error);

static int
ptrn_mprobe_parser_required2 (struct ptrn_mprobe_cmd_struct *args_info, const char *prog_name, const char *additional_error);
struct line_list
{
  char * string_arg;
  struct line_list * next;
};

static struct line_list *cmd_line_list = 0;
static struct line_list *cmd_line_list_tmp = 0;

static void
free_cmd_list(void)
{
  /* free the list of a previous call */
  if (cmd_line_list)
    {
      while (cmd_line_list) {
        cmd_line_list_tmp = cmd_line_list;
        cmd_line_list = cmd_line_list->next;
        free (cmd_line_list_tmp->string_arg);
        free (cmd_line_list_tmp);
      }
    }
}


static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct ptrn_mprobe_cmd_struct *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->pattern_given = 0 ;
  args_info->threads_given = 0 ;
  args_info->messages_given = 0 ;
  args_info->reps_given = 0 ;
  args_info->hostname_given = 0 ;
  args_info->nonblocking_given = 0 ;
  args_info->option_given = 0 ;
  args_info->procs_given = 0 ;
  args_info->latency_given = 0 ;
}

static
void clear_args (struct ptrn_mprobe_cmd_struct *args_info)
{
  args_info->pattern_arg = NULL;
  args_info->pattern_orig = NULL;
  args_info->threads_arg = 1;
  args_info->threads_orig = NULL;
  args_info->messages_arg = 10000;
  args_info->messages_orig = NULL;
  args_info->reps_arg = 20;
  args_info->reps_orig = NULL;
  args_info->hostname_flag = 0;
  args_info->nonblocking_flag = 0;
  args_info->option_arg = 1;
  args_info->option_orig = NULL;
  args_info->procs_flag = 0;
  args_info->latency_flag = 0;
  
}

static
void init_args_info(struct ptrn_mprobe_cmd_struct *args_info)
{


  args_info->help_help = ptrn_mprobe_cmd_struct_help[0] ;
  args_info->version_help = ptrn_mprobe_cmd_struct_help[1] ;
  args_info->pattern_help = ptrn_mprobe_cmd_struct_help[2] ;
  args_info->threads_help = ptrn_mprobe_cmd_struct_help[3] ;
  args_info->messages_help = ptrn_mprobe_cmd_struct_help[4] ;
  args_info->reps_help = ptrn_mprobe_cmd_struct_help[5] ;
  args_info->hostname_help = ptrn_mprobe_cmd_struct_help[6] ;
  args_info->nonblocking_help = ptrn_mprobe_cmd_struct_help[7] ;
  args_info->option_help = ptrn_mprobe_cmd_struct_help[8] ;
  args_info->procs_help = ptrn_mprobe_cmd_struct_help[9] ;
  args_info->latency_help = ptrn_mprobe_cmd_struct_help[10] ;
  
}

void
ptrn_mprobe_parser_print_version (void)
{
  printf ("%s %s\n", PTRN_MPROBE_PARSER_PACKAGE, PTRN_MPROBE_PARSER_VERSION);
}

static void print_help_common(void) {
  ptrn_mprobe_parser_print_version ();

  if (strlen(ptrn_mprobe_cmd_struct_purpose) > 0)
    printf("\n%s\n", ptrn_mprobe_cmd_struct_purpose);

  if (strlen(ptrn_mprobe_cmd_struct_usage) > 0)
    printf("\n%s\n", ptrn_mprobe_cmd_struct_usage);

  printf("\n");

  if (strlen(ptrn_mprobe_cmd_struct_description) > 0)
    printf("%s\n\n", ptrn_mprobe_cmd_struct_description);
}

void
ptrn_mprobe_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (ptrn_mprobe_cmd_struct_help[i])
    printf("%s\n", ptrn_mprobe_cmd_struct_help[i++]);
}

void
ptrn_mprobe_parser_init (struct ptrn_mprobe_cmd_struct *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);
}

void
ptrn_mprobe_parser_params_init(struct ptrn_mprobe_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct ptrn_mprobe_parser_params *
ptrn_mprobe_parser_params_create(void)
{
  struct ptrn_mprobe_parser_params *params = 
    (struct ptrn_mprobe_parser_params *)malloc(sizeof(struct ptrn_mprobe_parser_params));
  ptrn_mprobe_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
ptrn_mprobe_parser_release (struct ptrn_mprobe_cmd_struct *args_info)
{

  free_string_field (&(args_info->pattern_arg));
  free_string_field (&(args_info->pattern_orig));
  free_string_field (&(args_info->threads_orig));
  free_string_field (&(args_info->messages_orig));
  free_string_field (&(args_info->reps_orig));
  free_string_field (&(args_info->option_orig));
  
  

  clear_given (args_info);
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, char *values[])
{
  if (arg) {
    fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
ptrn_mprobe_parser_dump(FILE *outfile, struct ptrn_mprobe_cmd_struct *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", PTRN_MPROBE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->pattern_given)
    write_into_file(outfile, "pattern", args_info->pattern_orig, 0);
  if (args_info->threads_given)
    write_into_file(outfile, "threads", args_info->threads_orig, 0);
  if (args_info->messages_given)
    write_into_file(outfile, "messages", args_info->messages_orig, 0);
  if (args_info->reps_given)
    write_into_file(outfile, "reps", args_info->reps_orig, 0);
  if (args_info->hostname_given)
    write_into_file(outfile, "hostname", 0, 0 );
  if (args_info->nonblocking_given)
    write_into_file(outfile, "nonblocking", 0, 0 );
  if (args_info->option_given)
    write_into_file(outfile, "option", args_info->option_orig, 0);
  if (args_info->procs_given)
    write_into_file(outfile, "procs", 0, 0 );
  if (args_info->latency_given)
    write_into_file(outfile, "latency", 0, 0 );
  

  i = EXIT_SUCCESS;
  return i;
}

int
ptrn_mprobe_parser_file_save(const char *filename, struct ptrn_mprobe_cmd_struct *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", PTRN_MPROBE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = ptrn_mprobe_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
ptrn_mprobe_parser_free (struct ptrn_mprobe_cmd_struct *args_info)
{
  ptrn_mprobe_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = NULL;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
ptrn_mprobe_parser (int argc, char * const *argv, struct ptrn_mprobe_cmd_struct *args_info)
{
  return ptrn_mprobe_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
ptrn_mprobe_parser_ext (int argc, char * const *argv, struct ptrn_mprobe_cmd_struct *args_info,
                   struct ptrn_mprobe_parser_params *params)
{
  int result;
  result = ptrn_mprobe_parser_internal (argc, argv, args_info, params, NULL);

  if (result == EXIT_FAILURE)
    {
      ptrn_mprobe_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
ptrn_mprobe_parser2 (int argc, char * const *argv, struct ptrn_mprobe_cmd_struct *args_info, int override, int initialize, int check_required)
{
  int result;
  struct ptrn_mprobe_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = ptrn_mprobe_parser_internal (argc, argv, args_info, &params, NULL);

  if (result == EXIT_FAILURE)
    {
      ptrn_mprobe_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
ptrn_mprobe_parser_required (struct ptrn_mprobe_cmd_struct *args_info, const char *prog_name)
{
  int result = EXIT_SUCCESS;

  if (ptrn_mprobe_parser_required2(args_info, prog_name, NULL) > 0)
    result = EXIT_FAILURE;

  if (result == EXIT_FAILURE)
    {
      ptrn_mprobe_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
ptrn_mprobe_parser_required2 (struct ptrn_mprobe_cmd_struct *args_info, const char *prog_name, const char *additional_error)
{
  int error = 0;

  /* checks for required options */
  if (! args_info->pattern_given)
    {
      fprintf (stderr, "%s: '--pattern' ('-x') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error = 1;
    }
  
  
  /* checks for dependences among options */

  return error;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see ptrn_mprobe_parser_params.check_ambiguity
 * @param override @see ptrn_mprobe_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, char *possible_values[], const char *default_value,
               ptrn_mprobe_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  char **string_field;

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_FLAG:
    *((int *)field) = !*((int *)field);
    break;
  case ARG_INT:
    if (val) *((int *)field) = strtol (val, &stop_char, 0);
    break;
  case ARG_STRING:
    if (val) {
      string_field = (char **)field;
      if (!no_free && *string_field)
        free (*string_field); /* free previous string */
      *string_field = gengetopt_strdup (val);
    }
    break;
  default:
    break;
  };

  /* check numeric conversion */
  switch(arg_type) {
  case ARG_INT:
    if (val && !(stop_char && *stop_char == '\0')) {
      fprintf(stderr, "%s: invalid numeric value: %s\n", package_name, val);
      return 1; /* failure */
    }
    break;
  default:
    ;
  };

  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
  case ARG_FLAG:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


int
ptrn_mprobe_parser_internal (int argc, char * const *argv, struct ptrn_mprobe_cmd_struct *args_info,
                        struct ptrn_mprobe_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error = 0;
  struct ptrn_mprobe_cmd_struct local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    ptrn_mprobe_parser_init (args_info);

  ptrn_mprobe_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 0 },
        { "version",	0, NULL, 'V' },
        { "pattern",	1, NULL, 'x' },
        { "threads",	1, NULL, 't' },
        { "messages",	1, NULL, 'n' },
        { "reps",	1, NULL, 'r' },
        { "hostname",	0, NULL, 'h' },
        { "nonblocking",	0, NULL, 'b' },
        { "option",	1, NULL, 'o' },
        { "procs",	0, NULL, 'p' },
        { "latency",	0, NULL, 'l' },
        { NULL,	0, NULL, 0 }
      };

      c = getopt_long (argc, argv, "Vx:t:n:r:hbo:pl", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'V':	/* Print version and exit.  */
          ptrn_mprobe_parser_print_version ();
          ptrn_mprobe_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'x':	/* pattern.  */
        
        
          if (update_arg( (void *)&(args_info->pattern_arg), 
               &(args_info->pattern_orig), &(args_info->pattern_given),
              &(local_args_info.pattern_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "pattern", 'x',
              additional_error))
            goto failure;
        
          break;
        case 't':	/* Number of Threads.  */
        
        
          if (update_arg( (void *)&(args_info->threads_arg), 
               &(args_info->threads_orig), &(args_info->threads_given),
              &(local_args_info.threads_given), optarg, 0, "1", ARG_INT,
              check_ambiguity, override, 0, 0,
              "threads", 't',
              additional_error))
            goto failure;
        
          break;
        case 'n':	/* Number of Messages.  */
        
        
          if (update_arg( (void *)&(args_info->messages_arg), 
               &(args_info->messages_orig), &(args_info->messages_given),
              &(local_args_info.messages_given), optarg, 0, "10000", ARG_INT,
              check_ambiguity, override, 0, 0,
              "messages", 'n',
              additional_error))
            goto failure;
        
          break;
        case 'r':	/* Number or Repetitions.  */
        
        
          if (update_arg( (void *)&(args_info->reps_arg), 
               &(args_info->reps_orig), &(args_info->reps_given),
              &(local_args_info.reps_given), optarg, 0, "20", ARG_INT,
              check_ambiguity, override, 0, 0,
              "reps", 'r',
              additional_error))
            goto failure;
        
          break;
        case 'h':	/* Print hostname.  */
        
        
          if (update_arg((void *)&(args_info->hostname_flag), 0, &(args_info->hostname_given),
              &(local_args_info.hostname_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "hostname", 'h',
              additional_error))
            goto failure;
        
          break;
        case 'b':	/* Use nonblocking receive from all peers in parallel.  */
        
        
          if (update_arg((void *)&(args_info->nonblocking_flag), 0, &(args_info->nonblocking_given),
              &(local_args_info.nonblocking_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "nonblocking", 'b',
              additional_error))
            goto failure;
        
          break;
        case 'o':	/* Option: 1=ANY,ANY, 2=src,ANY, 3=ANY,tag, 4=src,tag.  */
        
        
          if (update_arg( (void *)&(args_info->option_arg), 
               &(args_info->option_orig), &(args_info->option_given),
              &(local_args_info.option_given), optarg, 0, "1", ARG_INT,
              check_ambiguity, override, 0, 0,
              "option", 'o',
              additional_error))
            goto failure;
        
          break;
        case 'p':	/* use processes instead of threads!.  */
        
        
          if (update_arg((void *)&(args_info->procs_flag), 0, &(args_info->procs_given),
              &(local_args_info.procs_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "procs", 'p',
              additional_error))
            goto failure;
        
          break;
        case 'l':	/* measure latency instead of message rate.  */
        
        
          if (update_arg((void *)&(args_info->latency_flag), 0, &(args_info->latency_given),
              &(local_args_info.latency_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "latency", 'l',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
          if (strcmp (long_options[option_index].name, "help") == 0) {
            ptrn_mprobe_parser_print_help ();
            ptrn_mprobe_parser_free (&local_args_info);
            exit (EXIT_SUCCESS);
          }

        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", PTRN_MPROBE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */



  if (check_required)
    {
      error += ptrn_mprobe_parser_required2 (args_info, argv[0], additional_error);
    }

  ptrn_mprobe_parser_release (&local_args_info);

  if ( error )
    return (EXIT_FAILURE);

  return 0;

failure:
  
  ptrn_mprobe_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}

static unsigned int
ptrn_mprobe_parser_create_argv(const char *cmdline_, char ***argv_ptr, const char *prog_name)
{
  char *cmdline, *p;
  size_t n = 0, j;
  int i;

  if (prog_name) {
    cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
    cmd_line_list_tmp->next = cmd_line_list;
    cmd_line_list = cmd_line_list_tmp;
    cmd_line_list->string_arg = gengetopt_strdup (prog_name);

    ++n;
  }

  cmdline = gengetopt_strdup(cmdline_);
  p = cmdline;

  while (p && strlen(p))
    {
      j = strcspn(p, " \t");
      ++n;
      if (j && j < strlen(p))
        {
          p[j] = '\0';

          cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
          cmd_line_list_tmp->next = cmd_line_list;
          cmd_line_list = cmd_line_list_tmp;
          cmd_line_list->string_arg = gengetopt_strdup (p);

          p += (j+1);
          p += strspn(p, " \t");
        }
      else
        {
          cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
          cmd_line_list_tmp->next = cmd_line_list;
          cmd_line_list = cmd_line_list_tmp;
          cmd_line_list->string_arg = gengetopt_strdup (p);

          break;
        }
    }

  *argv_ptr = (char **) malloc((n + 1) * sizeof(char *));
  cmd_line_list_tmp = cmd_line_list;
  for (i = (n-1); i >= 0; --i)
    {
      (*argv_ptr)[i] = cmd_line_list_tmp->string_arg;
      cmd_line_list_tmp = cmd_line_list_tmp->next;
    }

  (*argv_ptr)[n] = NULL;

  free(cmdline);
  return n;
}

int
ptrn_mprobe_parser_string(const char *cmdline, struct ptrn_mprobe_cmd_struct *args_info, const char *prog_name)
{
  return ptrn_mprobe_parser_string2(cmdline, args_info, prog_name, 0, 1, 1);
}

int
ptrn_mprobe_parser_string2(const char *cmdline, struct ptrn_mprobe_cmd_struct *args_info, const char *prog_name,
    int override, int initialize, int check_required)
{
  struct ptrn_mprobe_parser_params params;

  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  return ptrn_mprobe_parser_string_ext(cmdline, args_info, prog_name, &params);
}

int
ptrn_mprobe_parser_string_ext(const char *cmdline, struct ptrn_mprobe_cmd_struct *args_info, const char *prog_name,
    struct ptrn_mprobe_parser_params *params)
{
  char **argv_ptr = 0;
  int result;
  unsigned int argc;
  
  argc = ptrn_mprobe_parser_create_argv(cmdline, &argv_ptr, prog_name);
  
  result =
    ptrn_mprobe_parser_internal (argc, argv_ptr, args_info, params, 0);
  
  if (argv_ptr)
    {
      free (argv_ptr);
    }

  free_cmd_list();
  
  if (result == EXIT_FAILURE)
    {
      ptrn_mprobe_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}
