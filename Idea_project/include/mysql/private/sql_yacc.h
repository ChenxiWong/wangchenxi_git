
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ABORT_SYM = 258,
     ACCESSIBLE_SYM = 259,
     ACTION = 260,
     ADD = 261,
     ADDDATE_SYM = 262,
     AFTER_SYM = 263,
     AGAINST = 264,
     AGGREGATE_SYM = 265,
     ALGORITHM_SYM = 266,
     ALL = 267,
     ALTER = 268,
     ALWAYS_SYM = 269,
     ANALYZE_SYM = 270,
     AND_AND_SYM = 271,
     AND_SYM = 272,
     ANY_SYM = 273,
     AS = 274,
     ASC = 275,
     ASCII_SYM = 276,
     ASENSITIVE_SYM = 277,
     AT_SYM = 278,
     AUTHORS_SYM = 279,
     AUTOEXTEND_SIZE_SYM = 280,
     AUTO_INC = 281,
     AVG_ROW_LENGTH = 282,
     AVG_SYM = 283,
     BACKUP_SYM = 284,
     BEFORE_SYM = 285,
     BEGIN_SYM = 286,
     BETWEEN_SYM = 287,
     BIGINT = 288,
     BINARY = 289,
     BINLOG_SYM = 290,
     BIN_NUM = 291,
     BIT_AND = 292,
     BIT_OR = 293,
     BIT_SYM = 294,
     BIT_XOR = 295,
     BLOB_SYM = 296,
     BLOCK_SYM = 297,
     BOOLEAN_SYM = 298,
     BOOL_SYM = 299,
     BOTH = 300,
     BTREE_SYM = 301,
     BY = 302,
     BYTE_SYM = 303,
     CACHE_SYM = 304,
     CALL_SYM = 305,
     CASCADE = 306,
     CASCADED = 307,
     CASE_SYM = 308,
     CAST_SYM = 309,
     CATALOG_NAME_SYM = 310,
     CHAIN_SYM = 311,
     CHANGE = 312,
     CHANGED = 313,
     CHARSET = 314,
     CHAR_SYM = 315,
     CHECKPOINT_SYM = 316,
     CHECKSUM_SYM = 317,
     CHECK_SYM = 318,
     CIPHER_SYM = 319,
     CLASS_ORIGIN_SYM = 320,
     CLIENT_SYM = 321,
     CLIENT_STATS_SYM = 322,
     CLOSE_SYM = 323,
     COALESCE = 324,
     CODE_SYM = 325,
     COLLATE_SYM = 326,
     COLLATION_SYM = 327,
     COLUMNS = 328,
     COLUMN_ADD_SYM = 329,
     COLUMN_CREATE_SYM = 330,
     COLUMN_DELETE_SYM = 331,
     COLUMN_EXISTS_SYM = 332,
     COLUMN_GET_SYM = 333,
     COLUMN_LIST_SYM = 334,
     COLUMN_SYM = 335,
     COLUMN_NAME_SYM = 336,
     COMMENT_SYM = 337,
     COMMITTED_SYM = 338,
     COMMIT_SYM = 339,
     COMPACT_SYM = 340,
     COMPLETION_SYM = 341,
     COMPRESSED_SYM = 342,
     CONCURRENT = 343,
     CONDITION_SYM = 344,
     CONNECTION_SYM = 345,
     CONSISTENT_SYM = 346,
     CONSTRAINT = 347,
     CONSTRAINT_CATALOG_SYM = 348,
     CONSTRAINT_NAME_SYM = 349,
     CONSTRAINT_SCHEMA_SYM = 350,
     CONTAINS_SYM = 351,
     CONTEXT_SYM = 352,
     CONTINUE_SYM = 353,
     CONTRIBUTORS_SYM = 354,
     CONVERT_SYM = 355,
     COUNT_SYM = 356,
     CPU_SYM = 357,
     CREATE = 358,
     CROSS = 359,
     CUBE_SYM = 360,
     CURDATE = 361,
     CURRENT_USER = 362,
     CURSOR_SYM = 363,
     CURSOR_NAME_SYM = 364,
     CURTIME = 365,
     DATABASE = 366,
     DATABASES = 367,
     DATAFILE_SYM = 368,
     DATA_SYM = 369,
     DATETIME = 370,
     DATE_ADD_INTERVAL = 371,
     DATE_SUB_INTERVAL = 372,
     DATE_SYM = 373,
     DAY_HOUR_SYM = 374,
     DAY_MICROSECOND_SYM = 375,
     DAY_MINUTE_SYM = 376,
     DAY_SECOND_SYM = 377,
     DAY_SYM = 378,
     DEALLOCATE_SYM = 379,
     DECIMAL_NUM = 380,
     DECIMAL_SYM = 381,
     DECLARE_SYM = 382,
     DEFAULT = 383,
     DEFINER_SYM = 384,
     DELAYED_SYM = 385,
     DELAY_KEY_WRITE_SYM = 386,
     DELETE_SYM = 387,
     DESC = 388,
     DESCRIBE = 389,
     DES_KEY_FILE = 390,
     DETERMINISTIC_SYM = 391,
     DIRECTORY_SYM = 392,
     DISABLE_SYM = 393,
     DISCARD = 394,
     DISK_SYM = 395,
     DISTINCT = 396,
     DIV_SYM = 397,
     DOUBLE_SYM = 398,
     DO_SYM = 399,
     DROP = 400,
     DUAL_SYM = 401,
     DUMPFILE = 402,
     DUPLICATE_SYM = 403,
     DYNAMIC_SYM = 404,
     EACH_SYM = 405,
     ELSE = 406,
     ELSEIF_SYM = 407,
     ENABLE_SYM = 408,
     ENCLOSED = 409,
     END = 410,
     ENDS_SYM = 411,
     END_OF_INPUT = 412,
     ENGINES_SYM = 413,
     ENGINE_SYM = 414,
     ENUM = 415,
     EQ = 416,
     EQUAL_SYM = 417,
     ERROR_SYM = 418,
     ERRORS = 419,
     ESCAPED = 420,
     ESCAPE_SYM = 421,
     EVENTS_SYM = 422,
     EVENT_SYM = 423,
     EVERY_SYM = 424,
     EXAMINED_SYM = 425,
     EXECUTE_SYM = 426,
     EXISTS = 427,
     EXIT_SYM = 428,
     EXPANSION_SYM = 429,
     EXTENDED_SYM = 430,
     EXTENT_SIZE_SYM = 431,
     EXTRACT_SYM = 432,
     FALSE_SYM = 433,
     FAST_SYM = 434,
     FAULTS_SYM = 435,
     FETCH_SYM = 436,
     FILE_SYM = 437,
     FIRST_SYM = 438,
     FIXED_SYM = 439,
     FLOAT_NUM = 440,
     FLOAT_SYM = 441,
     FLUSH_SYM = 442,
     FORCE_SYM = 443,
     FOREIGN = 444,
     FOR_SYM = 445,
     FOUND_SYM = 446,
     FROM = 447,
     FULL = 448,
     FULLTEXT_SYM = 449,
     FUNCTION_SYM = 450,
     GE = 451,
     GENERAL = 452,
     GENERATED_SYM = 453,
     GEOMETRYCOLLECTION = 454,
     GEOMETRY_SYM = 455,
     GET_FORMAT = 456,
     GLOBAL_SYM = 457,
     GRANT = 458,
     GRANTS = 459,
     GROUP_SYM = 460,
     GROUP_CONCAT_SYM = 461,
     GT_SYM = 462,
     HANDLER_SYM = 463,
     HARD_SYM = 464,
     HASH_SYM = 465,
     HAVING = 466,
     HELP_SYM = 467,
     HEX_NUM = 468,
     HEX_STRING = 469,
     HIGH_PRIORITY = 470,
     HOST_SYM = 471,
     HOSTS_SYM = 472,
     HOUR_MICROSECOND_SYM = 473,
     HOUR_MINUTE_SYM = 474,
     HOUR_SECOND_SYM = 475,
     HOUR_SYM = 476,
     IDENT = 477,
     IDENTIFIED_SYM = 478,
     IDENT_QUOTED = 479,
     IF = 480,
     IGNORE_SYM = 481,
     IGNORE_SERVER_IDS_SYM = 482,
     IMPORT = 483,
     INDEXES = 484,
     INDEX_SYM = 485,
     INDEX_STATS_SYM = 486,
     INFILE = 487,
     INITIAL_SIZE_SYM = 488,
     INNER_SYM = 489,
     INOUT_SYM = 490,
     INSENSITIVE_SYM = 491,
     INSERT = 492,
     INSERT_METHOD = 493,
     INSTALL_SYM = 494,
     INTERVAL_SYM = 495,
     INTO = 496,
     INT_SYM = 497,
     INVOKER_SYM = 498,
     IN_SYM = 499,
     IO_SYM = 500,
     IPC_SYM = 501,
     IS = 502,
     ISOLATION = 503,
     ISSUER_SYM = 504,
     ITERATE_SYM = 505,
     JOIN_SYM = 506,
     KEYS = 507,
     KEY_BLOCK_SIZE = 508,
     KEY_SYM = 509,
     KILL_SYM = 510,
     LANGUAGE_SYM = 511,
     LAST_SYM = 512,
     LAST_VALUE = 513,
     LE = 514,
     LEADING = 515,
     LEAVES = 516,
     LEAVE_SYM = 517,
     LEFT = 518,
     LESS_SYM = 519,
     LEVEL_SYM = 520,
     LEX_HOSTNAME = 521,
     LIKE = 522,
     LIMIT = 523,
     LINEAR_SYM = 524,
     LINES = 525,
     LINESTRING = 526,
     LIST_SYM = 527,
     LOAD = 528,
     LOCAL_SYM = 529,
     LOCATOR_SYM = 530,
     LOCKS_SYM = 531,
     LOCK_SYM = 532,
     LOGFILE_SYM = 533,
     LOGS_SYM = 534,
     LONGBLOB = 535,
     LONGTEXT = 536,
     LONG_NUM = 537,
     LONG_SYM = 538,
     LOOP_SYM = 539,
     LOW_PRIORITY = 540,
     LT = 541,
     MASTER_CONNECT_RETRY_SYM = 542,
     MASTER_HOST_SYM = 543,
     MASTER_LOG_FILE_SYM = 544,
     MASTER_LOG_POS_SYM = 545,
     MASTER_PASSWORD_SYM = 546,
     MASTER_PORT_SYM = 547,
     MASTER_SERVER_ID_SYM = 548,
     MASTER_SSL_CAPATH_SYM = 549,
     MASTER_SSL_CA_SYM = 550,
     MASTER_SSL_CERT_SYM = 551,
     MASTER_SSL_CIPHER_SYM = 552,
     MASTER_SSL_KEY_SYM = 553,
     MASTER_SSL_SYM = 554,
     MASTER_SSL_VERIFY_SERVER_CERT_SYM = 555,
     MASTER_SYM = 556,
     MASTER_USER_SYM = 557,
     MASTER_HEARTBEAT_PERIOD_SYM = 558,
     MATCH = 559,
     MAX_CONNECTIONS_PER_HOUR = 560,
     MAX_QUERIES_PER_HOUR = 561,
     MAX_ROWS = 562,
     MAX_SIZE_SYM = 563,
     MAX_SYM = 564,
     MAX_UPDATES_PER_HOUR = 565,
     MAX_USER_CONNECTIONS_SYM = 566,
     MAX_VALUE_SYM = 567,
     MEDIUMBLOB = 568,
     MEDIUMINT = 569,
     MEDIUMTEXT = 570,
     MEDIUM_SYM = 571,
     MEMORY_SYM = 572,
     MERGE_SYM = 573,
     MESSAGE_TEXT_SYM = 574,
     MICROSECOND_SYM = 575,
     MIGRATE_SYM = 576,
     MINUTE_MICROSECOND_SYM = 577,
     MINUTE_SECOND_SYM = 578,
     MINUTE_SYM = 579,
     MIN_ROWS = 580,
     MIN_SYM = 581,
     MODE_SYM = 582,
     MODIFIES_SYM = 583,
     MODIFY_SYM = 584,
     MOD_SYM = 585,
     MONTH_SYM = 586,
     MULTILINESTRING = 587,
     MULTIPOINT = 588,
     MULTIPOLYGON = 589,
     MUTEX_SYM = 590,
     MYSQL_SYM = 591,
     MYSQL_ERRNO_SYM = 592,
     NAMES_SYM = 593,
     NAME_SYM = 594,
     NATIONAL_SYM = 595,
     NATURAL = 596,
     NCHAR_STRING = 597,
     NCHAR_SYM = 598,
     NDBCLUSTER_SYM = 599,
     NE = 600,
     NEG = 601,
     NEW_SYM = 602,
     NEXT_SYM = 603,
     NODEGROUP_SYM = 604,
     NONE_SYM = 605,
     NOT2_SYM = 606,
     NOT_SYM = 607,
     NOW_SYM = 608,
     NO_SYM = 609,
     NO_WAIT_SYM = 610,
     NO_WRITE_TO_BINLOG = 611,
     NULL_SYM = 612,
     NUM = 613,
     NUMERIC_SYM = 614,
     NVARCHAR_SYM = 615,
     OFFSET_SYM = 616,
     OLD_PASSWORD = 617,
     ON = 618,
     ONE_SHOT_SYM = 619,
     ONE_SYM = 620,
     ONLINE_SYM = 621,
     OPEN_SYM = 622,
     OPTIMIZE = 623,
     OPTIONS_SYM = 624,
     OPTION = 625,
     OPTIONALLY = 626,
     OR2_SYM = 627,
     ORDER_SYM = 628,
     OR_OR_SYM = 629,
     OR_SYM = 630,
     OUTER = 631,
     OUTFILE = 632,
     OUT_SYM = 633,
     OWNER_SYM = 634,
     PACK_KEYS_SYM = 635,
     PAGE_SYM = 636,
     PAGE_CHECKSUM_SYM = 637,
     PARAM_MARKER = 638,
     PARSER_SYM = 639,
     PARSE_VCOL_EXPR_SYM = 640,
     PARTIAL = 641,
     PARTITIONING_SYM = 642,
     PARTITIONS_SYM = 643,
     PARTITION_SYM = 644,
     PASSWORD = 645,
     PERSISTENT_SYM = 646,
     PHASE_SYM = 647,
     PLUGINS_SYM = 648,
     PLUGIN_SYM = 649,
     POINT_SYM = 650,
     POLYGON = 651,
     PORT_SYM = 652,
     POSITION_SYM = 653,
     PRECISION = 654,
     PREPARE_SYM = 655,
     PRESERVE_SYM = 656,
     PREV_SYM = 657,
     PRIMARY_SYM = 658,
     PRIVILEGES = 659,
     PROCEDURE_SYM = 660,
     PROCESS = 661,
     PROCESSLIST_SYM = 662,
     PROFILE_SYM = 663,
     PROFILES_SYM = 664,
     PROXY_SYM = 665,
     PURGE = 666,
     QUARTER_SYM = 667,
     QUERY_SYM = 668,
     QUICK = 669,
     RANGE_SYM = 670,
     READS_SYM = 671,
     READ_ONLY_SYM = 672,
     READ_SYM = 673,
     READ_WRITE_SYM = 674,
     REAL = 675,
     REBUILD_SYM = 676,
     RECOVER_SYM = 677,
     REDOFILE_SYM = 678,
     REDO_BUFFER_SIZE_SYM = 679,
     REDUNDANT_SYM = 680,
     REFERENCES = 681,
     REGEXP = 682,
     RELAY = 683,
     RELAYLOG_SYM = 684,
     RELAY_LOG_FILE_SYM = 685,
     RELAY_LOG_POS_SYM = 686,
     RELAY_THREAD = 687,
     RELEASE_SYM = 688,
     RELOAD = 689,
     REMOVE_SYM = 690,
     RENAME = 691,
     REORGANIZE_SYM = 692,
     REPAIR = 693,
     REPEATABLE_SYM = 694,
     REPEAT_SYM = 695,
     REPLACE = 696,
     REPLICATION = 697,
     REQUIRE_SYM = 698,
     RESET_SYM = 699,
     RESIGNAL_SYM = 700,
     RESOURCES = 701,
     RESTORE_SYM = 702,
     RESTRICT = 703,
     RESUME_SYM = 704,
     RETURNS_SYM = 705,
     RETURN_SYM = 706,
     REVOKE = 707,
     RIGHT = 708,
     ROLLBACK_SYM = 709,
     ROLLUP_SYM = 710,
     ROUTINE_SYM = 711,
     ROWS_SYM = 712,
     ROW_FORMAT_SYM = 713,
     ROW_SYM = 714,
     RTREE_SYM = 715,
     SAVEPOINT_SYM = 716,
     SCHEDULE_SYM = 717,
     SCHEMA_NAME_SYM = 718,
     SECOND_MICROSECOND_SYM = 719,
     SECOND_SYM = 720,
     SECURITY_SYM = 721,
     SELECT_SYM = 722,
     SENSITIVE_SYM = 723,
     SEPARATOR_SYM = 724,
     SERIALIZABLE_SYM = 725,
     SERIAL_SYM = 726,
     SESSION_SYM = 727,
     SERVER_SYM = 728,
     SERVER_OPTIONS = 729,
     SET = 730,
     SET_VAR = 731,
     SHARE_SYM = 732,
     SHIFT_LEFT = 733,
     SHIFT_RIGHT = 734,
     SHOW = 735,
     SHUTDOWN = 736,
     SIGNAL_SYM = 737,
     SIGNED_SYM = 738,
     SIMPLE_SYM = 739,
     SLAVE = 740,
     SLOW = 741,
     SMALLINT = 742,
     SNAPSHOT_SYM = 743,
     SOCKET_SYM = 744,
     SOFT_SYM = 745,
     SONAME_SYM = 746,
     SOUNDS_SYM = 747,
     SOURCE_SYM = 748,
     SPATIAL_SYM = 749,
     SPECIFIC_SYM = 750,
     SQLEXCEPTION_SYM = 751,
     SQLSTATE_SYM = 752,
     SQLWARNING_SYM = 753,
     SQL_BIG_RESULT = 754,
     SQL_BUFFER_RESULT = 755,
     SQL_CACHE_SYM = 756,
     SQL_CALC_FOUND_ROWS = 757,
     SQL_NO_CACHE_SYM = 758,
     SQL_SMALL_RESULT = 759,
     SQL_SYM = 760,
     SQL_THREAD = 761,
     SSL_SYM = 762,
     STARTING = 763,
     STARTS_SYM = 764,
     START_SYM = 765,
     STATUS_SYM = 766,
     STDDEV_SAMP_SYM = 767,
     STD_SYM = 768,
     STOP_SYM = 769,
     STORAGE_SYM = 770,
     STRAIGHT_JOIN = 771,
     STRING_SYM = 772,
     SUBCLASS_ORIGIN_SYM = 773,
     SUBDATE_SYM = 774,
     SUBJECT_SYM = 775,
     SUBPARTITIONS_SYM = 776,
     SUBPARTITION_SYM = 777,
     SUBSTRING = 778,
     SUM_SYM = 779,
     SUPER_SYM = 780,
     SUSPEND_SYM = 781,
     SWAPS_SYM = 782,
     SWITCHES_SYM = 783,
     SYSDATE = 784,
     TABLES = 785,
     TABLESPACE = 786,
     TABLE_REF_PRIORITY = 787,
     TABLE_STATS_SYM = 788,
     TABLE_SYM = 789,
     TABLE_CHECKSUM_SYM = 790,
     TABLE_NAME_SYM = 791,
     TEMPORARY = 792,
     TEMPTABLE_SYM = 793,
     TERMINATED = 794,
     TEXT_STRING = 795,
     TEXT_SYM = 796,
     THAN_SYM = 797,
     THEN_SYM = 798,
     TIMESTAMP = 799,
     TIMESTAMP_ADD = 800,
     TIMESTAMP_DIFF = 801,
     TIME_SYM = 802,
     TINYBLOB = 803,
     TINYINT = 804,
     TINYTEXT = 805,
     TO_SYM = 806,
     TRAILING = 807,
     TRANSACTION_SYM = 808,
     TRANSACTIONAL_SYM = 809,
     TRIGGERS_SYM = 810,
     TRIGGER_SYM = 811,
     TRIM = 812,
     TRUE_SYM = 813,
     TRUNCATE_SYM = 814,
     TYPES_SYM = 815,
     TYPE_SYM = 816,
     UDF_RETURNS_SYM = 817,
     ULONGLONG_NUM = 818,
     UNCOMMITTED_SYM = 819,
     UNDEFINED_SYM = 820,
     UNDERSCORE_CHARSET = 821,
     UNDOFILE_SYM = 822,
     UNDO_BUFFER_SIZE_SYM = 823,
     UNDO_SYM = 824,
     UNICODE_SYM = 825,
     UNINSTALL_SYM = 826,
     UNION_SYM = 827,
     UNIQUE_SYM = 828,
     UNKNOWN_SYM = 829,
     UNLOCK_SYM = 830,
     UNSIGNED = 831,
     UNTIL_SYM = 832,
     UPDATE_SYM = 833,
     UPGRADE_SYM = 834,
     USAGE = 835,
     USER = 836,
     USER_STATS_SYM = 837,
     USE_FRM = 838,
     USE_SYM = 839,
     USING = 840,
     UTC_DATE_SYM = 841,
     UTC_TIMESTAMP_SYM = 842,
     UTC_TIME_SYM = 843,
     VALUES = 844,
     VALUE_SYM = 845,
     VARBINARY = 846,
     VARCHAR = 847,
     VARIABLES = 848,
     VARIANCE_SYM = 849,
     VARYING = 850,
     VAR_SAMP_SYM = 851,
     VIA_SYM = 852,
     VIEW_SYM = 853,
     VIRTUAL_SYM = 854,
     WAIT_SYM = 855,
     WARNINGS = 856,
     WEEK_SYM = 857,
     WHEN_SYM = 858,
     WHERE = 859,
     WHILE_SYM = 860,
     WITH = 861,
     WITH_CUBE_SYM = 862,
     WITH_ROLLUP_SYM = 863,
     WORK_SYM = 864,
     WRAPPER_SYM = 865,
     WRITE_SYM = 866,
     X509_SYM = 867,
     XA_SYM = 868,
     XML_SYM = 869,
     XOR = 870,
     YEAR_MONTH_SYM = 871,
     YEAR_SYM = 872,
     ZEROFILL = 873,
     IMPOSSIBLE_ACTION = 874
   };
#endif
/* Tokens.  */
#define ABORT_SYM 258
#define ACCESSIBLE_SYM 259
#define ACTION 260
#define ADD 261
#define ADDDATE_SYM 262
#define AFTER_SYM 263
#define AGAINST 264
#define AGGREGATE_SYM 265
#define ALGORITHM_SYM 266
#define ALL 267
#define ALTER 268
#define ALWAYS_SYM 269
#define ANALYZE_SYM 270
#define AND_AND_SYM 271
#define AND_SYM 272
#define ANY_SYM 273
#define AS 274
#define ASC 275
#define ASCII_SYM 276
#define ASENSITIVE_SYM 277
#define AT_SYM 278
#define AUTHORS_SYM 279
#define AUTOEXTEND_SIZE_SYM 280
#define AUTO_INC 281
#define AVG_ROW_LENGTH 282
#define AVG_SYM 283
#define BACKUP_SYM 284
#define BEFORE_SYM 285
#define BEGIN_SYM 286
#define BETWEEN_SYM 287
#define BIGINT 288
#define BINARY 289
#define BINLOG_SYM 290
#define BIN_NUM 291
#define BIT_AND 292
#define BIT_OR 293
#define BIT_SYM 294
#define BIT_XOR 295
#define BLOB_SYM 296
#define BLOCK_SYM 297
#define BOOLEAN_SYM 298
#define BOOL_SYM 299
#define BOTH 300
#define BTREE_SYM 301
#define BY 302
#define BYTE_SYM 303
#define CACHE_SYM 304
#define CALL_SYM 305
#define CASCADE 306
#define CASCADED 307
#define CASE_SYM 308
#define CAST_SYM 309
#define CATALOG_NAME_SYM 310
#define CHAIN_SYM 311
#define CHANGE 312
#define CHANGED 313
#define CHARSET 314
#define CHAR_SYM 315
#define CHECKPOINT_SYM 316
#define CHECKSUM_SYM 317
#define CHECK_SYM 318
#define CIPHER_SYM 319
#define CLASS_ORIGIN_SYM 320
#define CLIENT_SYM 321
#define CLIENT_STATS_SYM 322
#define CLOSE_SYM 323
#define COALESCE 324
#define CODE_SYM 325
#define COLLATE_SYM 326
#define COLLATION_SYM 327
#define COLUMNS 328
#define COLUMN_ADD_SYM 329
#define COLUMN_CREATE_SYM 330
#define COLUMN_DELETE_SYM 331
#define COLUMN_EXISTS_SYM 332
#define COLUMN_GET_SYM 333
#define COLUMN_LIST_SYM 334
#define COLUMN_SYM 335
#define COLUMN_NAME_SYM 336
#define COMMENT_SYM 337
#define COMMITTED_SYM 338
#define COMMIT_SYM 339
#define COMPACT_SYM 340
#define COMPLETION_SYM 341
#define COMPRESSED_SYM 342
#define CONCURRENT 343
#define CONDITION_SYM 344
#define CONNECTION_SYM 345
#define CONSISTENT_SYM 346
#define CONSTRAINT 347
#define CONSTRAINT_CATALOG_SYM 348
#define CONSTRAINT_NAME_SYM 349
#define CONSTRAINT_SCHEMA_SYM 350
#define CONTAINS_SYM 351
#define CONTEXT_SYM 352
#define CONTINUE_SYM 353
#define CONTRIBUTORS_SYM 354
#define CONVERT_SYM 355
#define COUNT_SYM 356
#define CPU_SYM 357
#define CREATE 358
#define CROSS 359
#define CUBE_SYM 360
#define CURDATE 361
#define CURRENT_USER 362
#define CURSOR_SYM 363
#define CURSOR_NAME_SYM 364
#define CURTIME 365
#define DATABASE 366
#define DATABASES 367
#define DATAFILE_SYM 368
#define DATA_SYM 369
#define DATETIME 370
#define DATE_ADD_INTERVAL 371
#define DATE_SUB_INTERVAL 372
#define DATE_SYM 373
#define DAY_HOUR_SYM 374
#define DAY_MICROSECOND_SYM 375
#define DAY_MINUTE_SYM 376
#define DAY_SECOND_SYM 377
#define DAY_SYM 378
#define DEALLOCATE_SYM 379
#define DECIMAL_NUM 380
#define DECIMAL_SYM 381
#define DECLARE_SYM 382
#define DEFAULT 383
#define DEFINER_SYM 384
#define DELAYED_SYM 385
#define DELAY_KEY_WRITE_SYM 386
#define DELETE_SYM 387
#define DESC 388
#define DESCRIBE 389
#define DES_KEY_FILE 390
#define DETERMINISTIC_SYM 391
#define DIRECTORY_SYM 392
#define DISABLE_SYM 393
#define DISCARD 394
#define DISK_SYM 395
#define DISTINCT 396
#define DIV_SYM 397
#define DOUBLE_SYM 398
#define DO_SYM 399
#define DROP 400
#define DUAL_SYM 401
#define DUMPFILE 402
#define DUPLICATE_SYM 403
#define DYNAMIC_SYM 404
#define EACH_SYM 405
#define ELSE 406
#define ELSEIF_SYM 407
#define ENABLE_SYM 408
#define ENCLOSED 409
#define END 410
#define ENDS_SYM 411
#define END_OF_INPUT 412
#define ENGINES_SYM 413
#define ENGINE_SYM 414
#define ENUM 415
#define EQ 416
#define EQUAL_SYM 417
#define ERROR_SYM 418
#define ERRORS 419
#define ESCAPED 420
#define ESCAPE_SYM 421
#define EVENTS_SYM 422
#define EVENT_SYM 423
#define EVERY_SYM 424
#define EXAMINED_SYM 425
#define EXECUTE_SYM 426
#define EXISTS 427
#define EXIT_SYM 428
#define EXPANSION_SYM 429
#define EXTENDED_SYM 430
#define EXTENT_SIZE_SYM 431
#define EXTRACT_SYM 432
#define FALSE_SYM 433
#define FAST_SYM 434
#define FAULTS_SYM 435
#define FETCH_SYM 436
#define FILE_SYM 437
#define FIRST_SYM 438
#define FIXED_SYM 439
#define FLOAT_NUM 440
#define FLOAT_SYM 441
#define FLUSH_SYM 442
#define FORCE_SYM 443
#define FOREIGN 444
#define FOR_SYM 445
#define FOUND_SYM 446
#define FROM 447
#define FULL 448
#define FULLTEXT_SYM 449
#define FUNCTION_SYM 450
#define GE 451
#define GENERAL 452
#define GENERATED_SYM 453
#define GEOMETRYCOLLECTION 454
#define GEOMETRY_SYM 455
#define GET_FORMAT 456
#define GLOBAL_SYM 457
#define GRANT 458
#define GRANTS 459
#define GROUP_SYM 460
#define GROUP_CONCAT_SYM 461
#define GT_SYM 462
#define HANDLER_SYM 463
#define HARD_SYM 464
#define HASH_SYM 465
#define HAVING 466
#define HELP_SYM 467
#define HEX_NUM 468
#define HEX_STRING 469
#define HIGH_PRIORITY 470
#define HOST_SYM 471
#define HOSTS_SYM 472
#define HOUR_MICROSECOND_SYM 473
#define HOUR_MINUTE_SYM 474
#define HOUR_SECOND_SYM 475
#define HOUR_SYM 476
#define IDENT 477
#define IDENTIFIED_SYM 478
#define IDENT_QUOTED 479
#define IF 480
#define IGNORE_SYM 481
#define IGNORE_SERVER_IDS_SYM 482
#define IMPORT 483
#define INDEXES 484
#define INDEX_SYM 485
#define INDEX_STATS_SYM 486
#define INFILE 487
#define INITIAL_SIZE_SYM 488
#define INNER_SYM 489
#define INOUT_SYM 490
#define INSENSITIVE_SYM 491
#define INSERT 492
#define INSERT_METHOD 493
#define INSTALL_SYM 494
#define INTERVAL_SYM 495
#define INTO 496
#define INT_SYM 497
#define INVOKER_SYM 498
#define IN_SYM 499
#define IO_SYM 500
#define IPC_SYM 501
#define IS 502
#define ISOLATION 503
#define ISSUER_SYM 504
#define ITERATE_SYM 505
#define JOIN_SYM 506
#define KEYS 507
#define KEY_BLOCK_SIZE 508
#define KEY_SYM 509
#define KILL_SYM 510
#define LANGUAGE_SYM 511
#define LAST_SYM 512
#define LAST_VALUE 513
#define LE 514
#define LEADING 515
#define LEAVES 516
#define LEAVE_SYM 517
#define LEFT 518
#define LESS_SYM 519
#define LEVEL_SYM 520
#define LEX_HOSTNAME 521
#define LIKE 522
#define LIMIT 523
#define LINEAR_SYM 524
#define LINES 525
#define LINESTRING 526
#define LIST_SYM 527
#define LOAD 528
#define LOCAL_SYM 529
#define LOCATOR_SYM 530
#define LOCKS_SYM 531
#define LOCK_SYM 532
#define LOGFILE_SYM 533
#define LOGS_SYM 534
#define LONGBLOB 535
#define LONGTEXT 536
#define LONG_NUM 537
#define LONG_SYM 538
#define LOOP_SYM 539
#define LOW_PRIORITY 540
#define LT 541
#define MASTER_CONNECT_RETRY_SYM 542
#define MASTER_HOST_SYM 543
#define MASTER_LOG_FILE_SYM 544
#define MASTER_LOG_POS_SYM 545
#define MASTER_PASSWORD_SYM 546
#define MASTER_PORT_SYM 547
#define MASTER_SERVER_ID_SYM 548
#define MASTER_SSL_CAPATH_SYM 549
#define MASTER_SSL_CA_SYM 550
#define MASTER_SSL_CERT_SYM 551
#define MASTER_SSL_CIPHER_SYM 552
#define MASTER_SSL_KEY_SYM 553
#define MASTER_SSL_SYM 554
#define MASTER_SSL_VERIFY_SERVER_CERT_SYM 555
#define MASTER_SYM 556
#define MASTER_USER_SYM 557
#define MASTER_HEARTBEAT_PERIOD_SYM 558
#define MATCH 559
#define MAX_CONNECTIONS_PER_HOUR 560
#define MAX_QUERIES_PER_HOUR 561
#define MAX_ROWS 562
#define MAX_SIZE_SYM 563
#define MAX_SYM 564
#define MAX_UPDATES_PER_HOUR 565
#define MAX_USER_CONNECTIONS_SYM 566
#define MAX_VALUE_SYM 567
#define MEDIUMBLOB 568
#define MEDIUMINT 569
#define MEDIUMTEXT 570
#define MEDIUM_SYM 571
#define MEMORY_SYM 572
#define MERGE_SYM 573
#define MESSAGE_TEXT_SYM 574
#define MICROSECOND_SYM 575
#define MIGRATE_SYM 576
#define MINUTE_MICROSECOND_SYM 577
#define MINUTE_SECOND_SYM 578
#define MINUTE_SYM 579
#define MIN_ROWS 580
#define MIN_SYM 581
#define MODE_SYM 582
#define MODIFIES_SYM 583
#define MODIFY_SYM 584
#define MOD_SYM 585
#define MONTH_SYM 586
#define MULTILINESTRING 587
#define MULTIPOINT 588
#define MULTIPOLYGON 589
#define MUTEX_SYM 590
#define MYSQL_SYM 591
#define MYSQL_ERRNO_SYM 592
#define NAMES_SYM 593
#define NAME_SYM 594
#define NATIONAL_SYM 595
#define NATURAL 596
#define NCHAR_STRING 597
#define NCHAR_SYM 598
#define NDBCLUSTER_SYM 599
#define NE 600
#define NEG 601
#define NEW_SYM 602
#define NEXT_SYM 603
#define NODEGROUP_SYM 604
#define NONE_SYM 605
#define NOT2_SYM 606
#define NOT_SYM 607
#define NOW_SYM 608
#define NO_SYM 609
#define NO_WAIT_SYM 610
#define NO_WRITE_TO_BINLOG 611
#define NULL_SYM 612
#define NUM 613
#define NUMERIC_SYM 614
#define NVARCHAR_SYM 615
#define OFFSET_SYM 616
#define OLD_PASSWORD 617
#define ON 618
#define ONE_SHOT_SYM 619
#define ONE_SYM 620
#define ONLINE_SYM 621
#define OPEN_SYM 622
#define OPTIMIZE 623
#define OPTIONS_SYM 624
#define OPTION 625
#define OPTIONALLY 626
#define OR2_SYM 627
#define ORDER_SYM 628
#define OR_OR_SYM 629
#define OR_SYM 630
#define OUTER 631
#define OUTFILE 632
#define OUT_SYM 633
#define OWNER_SYM 634
#define PACK_KEYS_SYM 635
#define PAGE_SYM 636
#define PAGE_CHECKSUM_SYM 637
#define PARAM_MARKER 638
#define PARSER_SYM 639
#define PARSE_VCOL_EXPR_SYM 640
#define PARTIAL 641
#define PARTITIONING_SYM 642
#define PARTITIONS_SYM 643
#define PARTITION_SYM 644
#define PASSWORD 645
#define PERSISTENT_SYM 646
#define PHASE_SYM 647
#define PLUGINS_SYM 648
#define PLUGIN_SYM 649
#define POINT_SYM 650
#define POLYGON 651
#define PORT_SYM 652
#define POSITION_SYM 653
#define PRECISION 654
#define PREPARE_SYM 655
#define PRESERVE_SYM 656
#define PREV_SYM 657
#define PRIMARY_SYM 658
#define PRIVILEGES 659
#define PROCEDURE_SYM 660
#define PROCESS 661
#define PROCESSLIST_SYM 662
#define PROFILE_SYM 663
#define PROFILES_SYM 664
#define PROXY_SYM 665
#define PURGE 666
#define QUARTER_SYM 667
#define QUERY_SYM 668
#define QUICK 669
#define RANGE_SYM 670
#define READS_SYM 671
#define READ_ONLY_SYM 672
#define READ_SYM 673
#define READ_WRITE_SYM 674
#define REAL 675
#define REBUILD_SYM 676
#define RECOVER_SYM 677
#define REDOFILE_SYM 678
#define REDO_BUFFER_SIZE_SYM 679
#define REDUNDANT_SYM 680
#define REFERENCES 681
#define REGEXP 682
#define RELAY 683
#define RELAYLOG_SYM 684
#define RELAY_LOG_FILE_SYM 685
#define RELAY_LOG_POS_SYM 686
#define RELAY_THREAD 687
#define RELEASE_SYM 688
#define RELOAD 689
#define REMOVE_SYM 690
#define RENAME 691
#define REORGANIZE_SYM 692
#define REPAIR 693
#define REPEATABLE_SYM 694
#define REPEAT_SYM 695
#define REPLACE 696
#define REPLICATION 697
#define REQUIRE_SYM 698
#define RESET_SYM 699
#define RESIGNAL_SYM 700
#define RESOURCES 701
#define RESTORE_SYM 702
#define RESTRICT 703
#define RESUME_SYM 704
#define RETURNS_SYM 705
#define RETURN_SYM 706
#define REVOKE 707
#define RIGHT 708
#define ROLLBACK_SYM 709
#define ROLLUP_SYM 710
#define ROUTINE_SYM 711
#define ROWS_SYM 712
#define ROW_FORMAT_SYM 713
#define ROW_SYM 714
#define RTREE_SYM 715
#define SAVEPOINT_SYM 716
#define SCHEDULE_SYM 717
#define SCHEMA_NAME_SYM 718
#define SECOND_MICROSECOND_SYM 719
#define SECOND_SYM 720
#define SECURITY_SYM 721
#define SELECT_SYM 722
#define SENSITIVE_SYM 723
#define SEPARATOR_SYM 724
#define SERIALIZABLE_SYM 725
#define SERIAL_SYM 726
#define SESSION_SYM 727
#define SERVER_SYM 728
#define SERVER_OPTIONS 729
#define SET 730
#define SET_VAR 731
#define SHARE_SYM 732
#define SHIFT_LEFT 733
#define SHIFT_RIGHT 734
#define SHOW 735
#define SHUTDOWN 736
#define SIGNAL_SYM 737
#define SIGNED_SYM 738
#define SIMPLE_SYM 739
#define SLAVE 740
#define SLOW 741
#define SMALLINT 742
#define SNAPSHOT_SYM 743
#define SOCKET_SYM 744
#define SOFT_SYM 745
#define SONAME_SYM 746
#define SOUNDS_SYM 747
#define SOURCE_SYM 748
#define SPATIAL_SYM 749
#define SPECIFIC_SYM 750
#define SQLEXCEPTION_SYM 751
#define SQLSTATE_SYM 752
#define SQLWARNING_SYM 753
#define SQL_BIG_RESULT 754
#define SQL_BUFFER_RESULT 755
#define SQL_CACHE_SYM 756
#define SQL_CALC_FOUND_ROWS 757
#define SQL_NO_CACHE_SYM 758
#define SQL_SMALL_RESULT 759
#define SQL_SYM 760
#define SQL_THREAD 761
#define SSL_SYM 762
#define STARTING 763
#define STARTS_SYM 764
#define START_SYM 765
#define STATUS_SYM 766
#define STDDEV_SAMP_SYM 767
#define STD_SYM 768
#define STOP_SYM 769
#define STORAGE_SYM 770
#define STRAIGHT_JOIN 771
#define STRING_SYM 772
#define SUBCLASS_ORIGIN_SYM 773
#define SUBDATE_SYM 774
#define SUBJECT_SYM 775
#define SUBPARTITIONS_SYM 776
#define SUBPARTITION_SYM 777
#define SUBSTRING 778
#define SUM_SYM 779
#define SUPER_SYM 780
#define SUSPEND_SYM 781
#define SWAPS_SYM 782
#define SWITCHES_SYM 783
#define SYSDATE 784
#define TABLES 785
#define TABLESPACE 786
#define TABLE_REF_PRIORITY 787
#define TABLE_STATS_SYM 788
#define TABLE_SYM 789
#define TABLE_CHECKSUM_SYM 790
#define TABLE_NAME_SYM 791
#define TEMPORARY 792
#define TEMPTABLE_SYM 793
#define TERMINATED 794
#define TEXT_STRING 795
#define TEXT_SYM 796
#define THAN_SYM 797
#define THEN_SYM 798
#define TIMESTAMP 799
#define TIMESTAMP_ADD 800
#define TIMESTAMP_DIFF 801
#define TIME_SYM 802
#define TINYBLOB 803
#define TINYINT 804
#define TINYTEXT 805
#define TO_SYM 806
#define TRAILING 807
#define TRANSACTION_SYM 808
#define TRANSACTIONAL_SYM 809
#define TRIGGERS_SYM 810
#define TRIGGER_SYM 811
#define TRIM 812
#define TRUE_SYM 813
#define TRUNCATE_SYM 814
#define TYPES_SYM 815
#define TYPE_SYM 816
#define UDF_RETURNS_SYM 817
#define ULONGLONG_NUM 818
#define UNCOMMITTED_SYM 819
#define UNDEFINED_SYM 820
#define UNDERSCORE_CHARSET 821
#define UNDOFILE_SYM 822
#define UNDO_BUFFER_SIZE_SYM 823
#define UNDO_SYM 824
#define UNICODE_SYM 825
#define UNINSTALL_SYM 826
#define UNION_SYM 827
#define UNIQUE_SYM 828
#define UNKNOWN_SYM 829
#define UNLOCK_SYM 830
#define UNSIGNED 831
#define UNTIL_SYM 832
#define UPDATE_SYM 833
#define UPGRADE_SYM 834
#define USAGE 835
#define USER 836
#define USER_STATS_SYM 837
#define USE_FRM 838
#define USE_SYM 839
#define USING 840
#define UTC_DATE_SYM 841
#define UTC_TIMESTAMP_SYM 842
#define UTC_TIME_SYM 843
#define VALUES 844
#define VALUE_SYM 845
#define VARBINARY 846
#define VARCHAR 847
#define VARIABLES 848
#define VARIANCE_SYM 849
#define VARYING 850
#define VAR_SAMP_SYM 851
#define VIA_SYM 852
#define VIEW_SYM 853
#define VIRTUAL_SYM 854
#define WAIT_SYM 855
#define WARNINGS 856
#define WEEK_SYM 857
#define WHEN_SYM 858
#define WHERE 859
#define WHILE_SYM 860
#define WITH 861
#define WITH_CUBE_SYM 862
#define WITH_ROLLUP_SYM 863
#define WORK_SYM 864
#define WRAPPER_SYM 865
#define WRITE_SYM 866
#define X509_SYM 867
#define XA_SYM 868
#define XML_SYM 869
#define XOR 870
#define YEAR_MONTH_SYM 871
#define YEAR_SYM 872
#define ZEROFILL 873
#define IMPOSSIBLE_ACTION 874




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 732 "/home/buildbot/git/sql/sql_yacc.yy"

  int  num;
  ulong ulong_num;
  ulonglong ulonglong_number;
  longlong longlong_number;
  LEX_STRING lex_str;
  LEX_STRING *lex_str_ptr;
  LEX_SYMBOL symbol;
  LEX_TYPE lex_type;
  Table_ident *table;
  char *simple_string;
  Item *item;
  Item_num *item_num;
  List<Item> *item_list;
  List<String> *string_list;
  String *string;
  Key_part_spec *key_part;
  TABLE_LIST *table_list;
  udf_func *udf;
  LEX_USER *lex_user;
  struct sys_var_with_base variable;
  enum enum_var_type var_type;
  Key::Keytype key_type;
  enum ha_key_alg key_alg;
  handlerton *db_type;
  enum row_type row_type;
  enum ha_rkey_function ha_rkey_mode;
  enum enum_tx_isolation tx_isolation;
  enum Cast_target cast_type;
  enum Item_udftype udf_type;
  enum ha_choice choice;
  CHARSET_INFO *charset;
  thr_lock_type lock_type;
  interval_type interval, interval_time_st;
  timestamp_type date_time_type;
  st_select_lex *select_lex;
  chooser_compare_func_creator boolfunc2creator;
  struct sp_cond_type *spcondtype;
  struct { int vars, conds, hndlrs, curs; } spblock;
  sp_name *spname;
  LEX *lex;
  sp_head *sphead;
  struct p_elem_val *p_elem_value;
  enum index_hint_type index_hint;
  enum enum_filetype filetype;
  enum Foreign_key::fk_option m_fk_option;
  enum enum_yes_no_unknown m_yes_no_unk;
  Diag_condition_item_name diag_condition_item_name;
  DYNCALL_CREATE_DEF *dyncol_def;
  List<DYNCALL_CREATE_DEF> *dyncol_def_list;
  bool is_not_empty;



/* Line 1676 of yacc.c  */
#line 1345 "/home/buildbot/git/mkdist/sql/sql_yacc.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif




